/*
 * MAHJONG GAME
 * Autors: Mattia Casagrande - Gabriele Spina
 */

#include "shader.h"
#include "Mahjong.h"
#include "readBMP.h"
#include "texturing.h"
#include "data.h"

// Globals.
static float Xangle =  5.82, Yangle = 0.00, Zangle = 0.0;           // Angles to rotate the cards.
static float Xtraslate = -5.6, Ytraslate = 3.5 , Ztraslate = 0.0;   // Values to translate the cards.

// global variables keeping the state of the mouse
int mouseX=0, mouseY=0;

// Matrices
static mat4 modelViewMat = GLM_MAT4_IDENTITY_INIT;
static mat4 projMat = GLM_MAT4_IDENTITY_INIT;
static mat3 normalMat = GLM_MAT3_IDENTITY_INIT;

// Distance between the elements.
GLfloat gap;

static unsigned int
programId,
vertexShaderId,
fragmentShaderId,
modelViewMatLoc,
normalMatLoc,
projMatLoc,
objectLoc,
textureLoc,
buffer[3],
vao[2],
width,
height;

/* Definizione mahjong */

Campo campo;
Elemento sel1,sel2;
int nCards;

/*-------------------------*/

// Initialization routine.
void setup(void)
{
    GLenum glErr;
    
    gap = 0.05;

    glClearColor(0.5, 0.5, 0.5, 0.0);
    glEnable(GL_DEPTH_TEST);

    // Create shader program executable.
    vertexShaderId = setShader("vertex", "vertexShader.glsl");
    fragmentShaderId = setShader("fragment", "fragmentShader.glsl");
    programId = glCreateProgram();
    glAttachShader(programId, vertexShaderId);
    glAttachShader(programId, fragmentShaderId);
    glLinkProgram(programId);
    glUseProgram(programId);

    // Create VAOs and VBOs...
    glGenVertexArrays(2, vao);
    glGenBuffers(4, buffer);

    // ...and associate data with vertex shader.
    // Place  in VAO '1' the data of the card
    glBindVertexArray(vao[1]);
    glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cardVertices), cardVertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elementIndices), elementIndices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(cardVertices[0]), 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 
                        sizeof(cardVertices[0]), (void*)sizeof(cardVertices[0].coords));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(cardVertices[0]),
                          (void*)(sizeof(cardVertices[0].coords)+sizeof(cardVertices[0].normal)));
    glEnableVertexAttribArray(2);

    // Place in VAO '0' the data of the square for the backgroud texture
    glBindVertexArray(vao[0]);
    glBindBuffer(GL_ARRAY_BUFFER, buffer[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(backgroundSquareVertices), backgroundSquareVertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer[3]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(backgroundIndices), backgroundIndices, GL_STATIC_DRAW);
    glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(backgroundSquareVertices[0]), 0);
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 
                        sizeof(backgroundSquareVertices[0]), (void*)sizeof(backgroundSquareVertices[0].coords));
    glEnableVertexAttribArray(4);
    glVertexAttribPointer(5, 2, GL_FLOAT, GL_FALSE, sizeof(backgroundSquareVertices[0]),
                          (void*)(sizeof(backgroundSquareVertices[0].coords)+sizeof(backgroundSquareVertices[0].normal)));
    glEnableVertexAttribArray(5);


    // Obtain modelview matrix, projection matrix, normal matrix and object uniform locations.
    modelViewMatLoc = glGetUniformLocation(programId, "modelViewMat");
    projMatLoc = glGetUniformLocation(programId, "projMat");
    normalMatLoc = glGetUniformLocation(programId, "normalMat");
    objectLoc = glGetUniformLocation(programId, "object");
    textureLoc = glGetUniformLocation(programId, "textures");

    // Obtain light property uniform locations and set values.
    glUniform4fv(glGetUniformLocation(programId, "light0.ambCols"), 1, &light0.ambCols[0]);
    glUniform4fv(glGetUniformLocation(programId, "light0.difCols"), 1, &light0.difCols[0]);
    glUniform4fv(glGetUniformLocation(programId, "light0.specCols"), 1, &light0.specCols[0]);
    glUniform4fv(glGetUniformLocation(programId, "light0.coords"), 1, &light0.coords[0]);

    // Obtain global ambient uniform location and set value.
    glUniform4fv(glGetUniformLocation(programId, "globAmb"), 1, &globAmb[0]);
    
    // Obtain material property uniform locations and set values.
    glUniform4fv(glGetUniformLocation(programId, "material.ambRefl"), 1, &matChiaro.ambRefl[0]);
    glUniform4fv(glGetUniformLocation(programId, "material.difRefl"), 1, &matChiaro.difRefl[0]);
    glUniform4fv(glGetUniformLocation(programId, "material.specRefl"), 1, &matChiaro.specRefl[0]);
    glUniform4fv(glGetUniformLocation(programId, "material.emitCols"), 1, &matChiaro.emitCols[0]);
    glUniform1f(glGetUniformLocation(programId, "material.shininess"), matChiaro.shininess);
    
    // Function to load all the needed textures 
    loadTexture(programId);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);    

    // Initialize the game field
    nCards = setUp(&campo);
    sel1.selezionato=-10;sel2.selezionato=-10;
    
    if ((glErr = glGetError()) != 0)
    {
        printf("Errore = %d \n %s\n", glErr, gluErrorString(glErr));
        exit(-1);
    }
}

// Function to draw the cards in right place
void draw_card(int x, int y, int z){
    // Place card in the view port
    glm_translate(modelViewMat, (vec3){ Xtraslate, Ytraslate, Ztraslate});

    // Translate to put cards in grid 
    glm_translate(modelViewMat,(vec3){ (x - 1) * 1 + x * gap,
                -(y - 1) * 1.618 + y * gap, (z-1) * -0.45 + z * gap});
    
    glUniformMatrix4fv(modelViewMatLoc, 1, GL_FALSE, (GLfloat *)(modelViewMat));
    
    int valore = campo.livello[z].riga[y].colonna[x];

    // Load texture
    glUniform1ui(textureLoc, valore );
    
    // Checking selected card
    if(valore != 0) // If exist
    {   
        // Set material to base value
        glUniform4fv(glGetUniformLocation(programId, "material.ambRefl"), 1, &matChiaro.ambRefl[0]);
        glUniform4fv(glGetUniformLocation(programId, "material.difRefl"), 1, &matChiaro.difRefl[0]);
        glUniform4fv(glGetUniformLocation(programId, "material.specRefl"), 1, &matChiaro.specRefl[0]);
        glUniform4fv(glGetUniformLocation(programId, "material.emitCols"), 1, &matChiaro.emitCols[0]);
        glUniform1f(glGetUniformLocation(programId, "material.shininess"), matChiaro.shininess);   
        
        if(sel1.selezionato > 0 )
        {
            if( x == sel1.Colonna && y == sel1.Riga && z == sel1.Livello )
            {
                // Checking card value to define if i can select it or not 
                int v = getMateriale(campo,  x,  y,  z);
                if(v > 0)   // If i can select then i draw card in green
                {
                    glUniform4fv(glGetUniformLocation(programId, "material.ambRefl"), 1, &matVerde.ambRefl[0]);
                    glUniform4fv(glGetUniformLocation(programId, "material.difRefl"), 1, &matVerde.difRefl[0]);
                    glUniform4fv(glGetUniformLocation(programId, "material.specRefl"), 1, &matVerde.specRefl[0]);
                    glUniform4fv(glGetUniformLocation(programId, "material.emitCols"), 1, &matVerde.emitCols[0]);
                    glUniform1f(glGetUniformLocation(programId, "material.shininess"), matVerde.shininess);
                }
                else    // Else i draw card in red
                {
                    glUniform4fv(glGetUniformLocation(programId, "material.ambRefl"), 1, &matRosso.ambRefl[0]);
                    glUniform4fv(glGetUniformLocation(programId, "material.difRefl"), 1, &matRosso.difRefl[0]);
                    glUniform4fv(glGetUniformLocation(programId, "material.specRefl"), 1, &matRosso.specRefl[0]);
                    glUniform4fv(glGetUniformLocation(programId, "material.emitCols"), 1, &matRosso.emitCols[0]);
                    glUniform1f(glGetUniformLocation(programId, "material.shininess"), matRosso.shininess);
                }
            }
        }
        // Here we draw the card
        for(int i = 0 ; i < 6 ; ++i)
            glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_BYTE, (GLvoid *)(i*4*sizeof(GLubyte)));
    }
    // Reset material properties
    glUniform4fv(glGetUniformLocation(programId, "material.ambRefl"), 1, &matChiaro.ambRefl[0]);
    glUniform4fv(glGetUniformLocation(programId, "material.difRefl"), 1, &matChiaro.difRefl[0]);
    glUniform4fv(glGetUniformLocation(programId, "material.specRefl"), 1, &matChiaro.specRefl[0]);
    glUniform4fv(glGetUniformLocation(programId, "material.emitCols"), 1, &matChiaro.emitCols[0]);
    glUniform1f(glGetUniformLocation(programId, "material.shininess"), matChiaro.shininess);   
        
    
    // Reset modelView matrix
    glm_mat4_identity(modelViewMat);
    glm_rotate(modelViewMat, Zangle, (vec3){0.0, 0.0, 1.0});
    glm_rotate(modelViewMat, Yangle, (vec3){0.0, 1.0, 0.0});
    glm_rotate(modelViewMat, Xangle, (vec3){1.0, 0.0, 0.0});
    glUniformMatrix4fv(modelViewMatLoc, 1, GL_FALSE, (GLfloat *)(modelViewMat));
}

// Drawing routine.
void display(void)
{
    mat3 TMP;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Window title
    char title[100];
    snprintf(title, sizeof(title), "MAHJONG - CARTE RIMANENTI: %d", nCards);
    glutSetWindowTitle(title);

    // Set orthographic perspective
    glm_ortho(-8, 8, -8, 8, -8, 8, projMat);
    glUniformMatrix4fv(projMatLoc, 1, GL_FALSE, (GLfloat *) projMat);
    
    // Apply base rotation 
    glm_mat4_identity(modelViewMat);
    glm_rotate(modelViewMat, Zangle, (vec3){0.0, 0.0, 1.0});
    glm_rotate(modelViewMat, Yangle, (vec3){0.0, 1.0, 0.0});
    glm_rotate(modelViewMat, Xangle, (vec3){1.0, 0.0, 0.0});
    glUniformMatrix4fv(modelViewMatLoc, 1, GL_FALSE, (GLfloat *)(modelViewMat));
    
    // Calcolate the invert and then the traspose for the normals
    glm_mat4_pick3(modelViewMat, TMP);
    glm_mat3_inv(TMP, normalMat);
    glm_mat3_transpose(normalMat);
    glUniformMatrix3fv(normalMatLoc, 1, GL_FALSE, (GLfloat *)normalMat);

    // Translate to place the background square in place
    glm_translate(modelViewMat, (vec3){0.0, 2.0, 0.0 });
    glUniformMatrix4fv(modelViewMatLoc, 1, GL_FALSE, (GLfloat *)(modelViewMat));
    
    // Draw the background
    glUniform1ui(objectLoc, 1);
    glBindVertexArray(vao[0]);
    
    // Here i check if you win to load a different background texture
    if(nCards == 0) 
        glUniform1ui(textureLoc, 1);
    else
        glUniform1ui(textureLoc, 0);

    for(int i = 0 ; i < 1 ; ++i)
        glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_BYTE, (GLvoid *)(i*4*sizeof(GLubyte)));

    // Reset modelView matrix before drawing the cards
    glm_mat4_identity(modelViewMat);
    glm_rotate(modelViewMat, Zangle, (vec3){0.0, 0.0, 1.0});
    glm_rotate(modelViewMat, Yangle, (vec3){0.0, 1.0, 0.0});
    glm_rotate(modelViewMat, Xangle, (vec3){1.0, 0.0, 0.0});
    glUniformMatrix4fv(modelViewMatLoc, 1, GL_FALSE, (GLfloat *)(modelViewMat));

    // Draw the cards
    glUniform1ui(objectLoc, 0);
    glBindVertexArray(vao[1]);

    for(int colonna=0;colonna<MaxColonna;colonna++)
        for(int riga=0;riga<MaxRiga;riga++)
            for(int livello=0;livello<MaxLivelli;livello++)
                draw_card(colonna, riga, livello);
    
    glutSwapBuffers();
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
    glViewport(0, 0, w, h);
    width = w;
    height = h;
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{   
    switch(key)
    {
        case 'R':
            nCards = setUp(&campo);
            glutPostRedisplay();
            break;
        default:
            break;
    }
}

// Mouse input processing routine
void clikMouse(int button, int stato, int x, int y){
    switch(button){
        case GLUT_LEFT_BUTTON :
            // If mouse left button is clicked i check wich element is selected 
            if(stato == GLUT_UP){
                mouseX = x-87;
                mouseY = y-125;

                int c = mouseX / 66;//lunghezza
                int r = mouseY / 94;// Altezza
                int removed;

                if( sel1.selezionato < 0 ){   
                    sel1 = selezionare(campo, r , c );
                }else if(sel2.selezionato < 0){
                    sel2 = selezionare(campo, r, c );
                    removed = RimuoviElementi(&campo, sel1, sel2 );
                    if(removed == 1)
                        nCards-=2;
                    sel1.selezionato=-10;sel2.selezionato=-10;
                }
            }
            glutPostRedisplay();
            break;

        default:
        break;
    }
}

// Main routine.
int main(int argc, char **argv)
{
    GLenum glErr;

    printf("Interaction: \n");
    printf("Click on a card to select it\n");
    printf("Press R to re-shuffle the game field. \n");

    glutInit(&argc, argv);
    glutInitContextVersion(4, 3);
    glutInitContextProfile(GLUT_CORE_PROFILE);
    glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(1000, 1200);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("MAHJONG");
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);
    glutMouseFunc(clikMouse);
    glewInit();

    // ... it does not hurt to check that everything went OK
    if ((glErr = glGetError()) != 0)
    {
        printf("Errore = %d \n", glErr);
        exit(-1);
    }

    setup();
    glutMainLoop();

    return 0;
}
