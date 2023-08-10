// standard includes
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <cglm/cglm.h>
#include <cglm/types-struct.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct Vertex
{
    float coords[4];
    float normal[3];
    float texCoords[2];
} Vertex;

typedef struct Material
{
   vec4 ambRefl;
   vec4 difRefl;
   vec4 specRefl;
   vec4 emitCols;
   GLfloat shininess;
} Material;

typedef struct Light
{
   vec4 ambCols;
   vec4 difCols;
   vec4 specCols;
   vec4 coords;
} Light;

// Define components and position of the light font
static const Light light0 =
{
    (vec4){0.0, 0.0, 0.0, 1.0},
    (vec4){1.0, 1.0, 1.0, 1.0},
    (vec4){1.0, 1.0, 1.0, 1.0},
    (vec4){20.0, 25.0, 8.0, 1.0}
};

static const vec4 globAmb = (vec4){0.1, 0.1, 0.1, 1.0};

// Define 3 different materials to simulate the color change when picking a "right/wrong" card
static const Material matVerde =
{
    (vec4){(float)0.135, (float)0.2225, (float)0.1575, 1.0},
    (vec4){(float)0.54, (float)0.89, (float)0.63, 1.0},
    (vec4){(float)0.316228, (float)0.316228, (float)0.316228, 1.0},
    (vec4){(float)0.0, (float)1.0, (float)0.0, 1.0},
    0.6f
};

static const Material matChiaro =
{
    (vec4){(float)0.19125, (float)0.0735, (float)0.0225	, 1.0},
    (vec4){(float)0.7038, (float)0.27048, (float)0.0828, 1.0},
    (vec4){(float)0.256777, (float)0.137622, (float)0.086014, 1.0},
    (vec4){(float)1.0, (float)1.0, (float)1.0, 1.0},
    0.1f
};

static const Material matRosso =
{
    (vec4){(float)0.5,(float)0, (float)0, 1.0},
    (vec4){(float)0.5,(float)0, (float)0, 1.0},
    (vec4){(float)0.7,(float)0.7, (float)0.6, 1.0},
    (vec4){(float)1.0,(float)0.0, (float)0.0, 1.0},
    0.6f
};

// Data of a card
static Vertex cardVertices[6*4] =
{
    { { 0.0, 0.0, 0.0, 1.0   },   {1.0, 1.0, 1.0},  {0.52, 0.75} }, //v0
    { { 1.0, 0.0, 0.0, 1.0   },   {1.0, 1.0, 1.0},  {0.8, 0.75} }, //v1
    { { 0.0, 1.618, 0.0, 1.0  },   {1.0, 1.0, 1.0},  {0.52, 0.35} }, //v3
    { { 1.0, 1.618, 0.0, 1.0  },   {1.0, 1.0, 1.0},  {0.8, 0.35} }, //v2

    { { 0.0, 0.0, 0.0, 1.0  },  {1.0, 1.0, 1.0},  {0.9, 0.35} }, //v1
    { { 0.0, 1.618, 0.0, 1.0   },  {1.0, 1.0, 1.0},  {0.9, 0.35} }, //v4
    { { 0.0, 0.0, -0.35, 1.0 },  {1.0, 1.0, 1.0},  {0.9, 0.35} }, //v2
    { { 0.0, 1.618, -0.35, 1.0  },  {1.0, 1.0, 1.0},  {0.9, 0.35} },  //v5

    { { 0.0, 0.0, -0.35, 1.0  },  {1.0, 1.0, 1.0},  {0.9, 0.35} }, //v7
    { { 1.0, 0.0, -0.35, 1.0  },  {1.0, 1.0, 1.0},  {0.9, 0.35} }, //v4
    { { 0.0, 1.618, -0.35, 1.0 },  {1.0, 1.0, 1.0},  {0.9, 0.35} }, //v6
    { { 1.0, 1.618, -0.35, 1.0 },  {1.0, 1.0, 1.0},  {0.9, 0.35} },  //v5
    
    { { 1.0, 0.0, 0.0, 1.0  },  {1.0, 1.0, 1.0},  {0.9, 0.35} }, //v0
    { { 1.0, 1.618, 0.0, 1.0   },  {1.0, 1.0, 1.0},  {0.9, 0.35} }, //v7
    { { 1.0, 0.0, -0.35, 1.0 },  {1.0, 1.0, 1.0},  {0.9, 0.35} }, //v3
    { { 1.0, 1.618, -0.35, 1.0 },  {1.0, 1.0, 1.0},  {0.9, 0.35} }, //v3
        
    { { 0.0, 1.618, 0.0, 1.0  },  {1.0, 1.0, 1.0},  {0.9, 0.35} }, //v3
    { { 1.0, 1.618, 0.0, 1.0  },  {1.0, 1.0, 1.0},  {0.9, 0.35} }, //v2
    { { 0.0, 1.618, -0.35, 1.0  },  {1.0, 1.0, 1.0},  {0.9, 0.35} }, //v6
    { { 1.0, 1.618, -0.35, 1.0  },  {1.0, 1.0, 1.0},  {0.9, 0.35} }, //v5

    { { 0.0, 0.0, 0.0, 1.0   },  {1.0, 1.0, 1.0},  {0.9, 0.35} }, //v0
    { { 1.0, 0.0, 0.0, 1.0   },  {1.0, 1.0, 1.0},  {0.9, 0.35} }, //v1
    { { 0.0, 0.0, -0.35, 1.0  },  {1.0, 1.0, 1.0},  {0.9, 0.35} }, //v7
    { { 1.0, 0.0, -0.35, 1.0  },  {1.0, 1.0, 1.0},  {0.9, 0.35} }, //v4
};

// Index array for the card
GLubyte elementIndices[6*4] =
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};

// Data of the square in background
static Vertex backgroundSquareVertices[4]={
    {{-8.0, -8.0, -8.0, 1.0}, {1.0, 1.0, 1.0}, {0.0, 0.0}},
    {{8.0,  -8.0,  -8.0 , 1.0}, {1.0, 1.0, 1.0}, {1.0, 0.0}},
    {{-8.0, 8.0,  0.0 , 1.0}, {1.0, 1.0, 1.0}, {0.0, 1.0}},
    {{8.0,  8.0,  0.0  , 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0}},
};

// Index array for the square
GLubyte backgroundIndices[4] =
    {0, 1, 2, 3};
    
