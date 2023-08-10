#include "readBMP.h"
#include "texturing.h"

// Function to load all textures 
void loadTexture(unsigned int programId){
        static BitMapFile *image[32]; // Local storage for bmp image data.

        static unsigned int 
        texture[32],bamboo_1, bamboo_2, bamboo_3, bamboo_4, bamboo_5, bamboo_6, bamboo_7, bamboo_8, bamboo_9,
        circle_1, circle_2, circle_3, circle_4, circle_5, dragon_green, dragon_red, dragon_white, flower_1, flower_2, flower_3, flower_4, 
        season_autumn, season_spring, season_summer, season_winter, wan_1, wan_2, wan_3, wan_4, wan_5, win, background;

        // Load the images.
        image[0]  = readBMP("../img/bamboo_1.bmp");
        image[1]  = readBMP("../img/bamboo_2.bmp");
        image[2]  = readBMP("../img/bamboo_3.bmp");
        image[3]  = readBMP("../img/bamboo_4.bmp");
        image[4]  = readBMP("../img/bamboo_5.bmp");
        image[5]  = readBMP("../img/bamboo_6.bmp");
        image[6]  = readBMP("../img/bamboo_7.bmp");
        image[7]  = readBMP("../img/bamboo_8.bmp");
        image[8]  = readBMP("../img/bamboo_9.bmp");
        image[9]  = readBMP("../img/circle_1.bmp");
        image[10] = readBMP("../img/circle_2.bmp");
        image[11] = readBMP("../img/circle_3.bmp");
        image[12] = readBMP("../img/circle_4.bmp");
        image[13] = readBMP("../img/circle_5.bmp");
        image[14] = readBMP("../img/dragon_green.bmp");
        image[15] = readBMP("../img/dragon_red.bmp");
        image[16] = readBMP("../img/dragon_white.bmp");
        image[17] = readBMP("../img/flower_1.bmp");
        image[18] = readBMP("../img/flower_2.bmp");
        image[19] = readBMP("../img/flower_3.bmp");
        image[20] = readBMP("../img/flower_4.bmp");
        image[21] = readBMP("../img/season_autumn.bmp");
        image[22] = readBMP("../img/season_spring.bmp");
        image[23] = readBMP("../img/season_summer.bmp");
        image[24] = readBMP("../img/season_winter.bmp");
        image[25] = readBMP("../img/wan_1.bmp");
        image[26] = readBMP("../img/wan_2.bmp");
        image[27] = readBMP("../img/wan_3.bmp");
        image[28] = readBMP("../img/wan_4.bmp");
        image[29] = readBMP("../img/wan_5.bmp");
        image[30] = readBMP("../img/sfondo1.bmp");
        image[31] = readBMP("../img/sfondo0.bmp");

        // Create texture ids.
        glGenTextures(32, texture);

        // Background texture base
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture[31]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[31]->sizeX, image[31]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[31]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        background = glGetUniformLocation(programId, "background");
        glUniform1i(background, 0);

        // Background texture in case of win
        glActiveTexture(GL_TEXTURE30);
        glBindTexture(GL_TEXTURE_2D, texture[30]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[30]->sizeX, image[30]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[30]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        win = glGetUniformLocation(programId, "win");
        glUniform1i(win, 30);

        // A texture for every kind of different card
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture[1]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[1]->sizeX, image[1]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[1]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        bamboo_2 = glGetUniformLocation(programId, "bamboo_2");
        glUniform1i(bamboo_2, 1);

        glActiveTexture(GL_TEXTURE2);
        glBindTexture(GL_TEXTURE_2D, texture[2]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[2]->sizeX, image[2]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[2]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        bamboo_3 = glGetUniformLocation(programId, "bamboo_3");
        glUniform1i(bamboo_3, 2);

        glActiveTexture(GL_TEXTURE3);
        glBindTexture(GL_TEXTURE_2D, texture[3]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[3]->sizeX, image[3]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[3]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        bamboo_4 = glGetUniformLocation(programId, "bamboo_4");
        glUniform1i(bamboo_4, 3);
        
        glActiveTexture(GL_TEXTURE4);
        glBindTexture(GL_TEXTURE_2D, texture[4]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[4]->sizeX, image[4]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[4]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        bamboo_5 = glGetUniformLocation(programId, "bamboo_5");
        glUniform1i(bamboo_5, 4);
        
        glActiveTexture(GL_TEXTURE5);
        glBindTexture(GL_TEXTURE_2D, texture[5]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[5]->sizeX, image[5]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[5]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        bamboo_6 = glGetUniformLocation(programId, "bamboo_6");
        glUniform1i(bamboo_6, 5);

        glActiveTexture(GL_TEXTURE6);
        glBindTexture(GL_TEXTURE_2D, texture[6]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[6]->sizeX, image[6]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[6]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        bamboo_7 = glGetUniformLocation(programId, "bamboo_7");
        glUniform1i(bamboo_7, 6);

        glActiveTexture(GL_TEXTURE7);
        glBindTexture(GL_TEXTURE_2D, texture[7]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[7]->sizeX, image[7]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[7]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        bamboo_8 = glGetUniformLocation(programId, "bamboo_8");
        glUniform1i(bamboo_8, 7);

        glActiveTexture(GL_TEXTURE8);
        glBindTexture(GL_TEXTURE_2D, texture[8]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[8]->sizeX, image[8]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[8]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        bamboo_9 = glGetUniformLocation(programId, "bamboo_9");
        glUniform1i(bamboo_9, 8);
        
        glActiveTexture(GL_TEXTURE9);
        glBindTexture(GL_TEXTURE_2D, texture[9]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[9]->sizeX, image[9]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[9]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        circle_1 = glGetUniformLocation(programId, "circle_1");
        glUniform1i(circle_1, 9);
        
        glActiveTexture(GL_TEXTURE10);
        glBindTexture(GL_TEXTURE_2D, texture[10]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[10]->sizeX, image[10]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[10]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        circle_2 = glGetUniformLocation(programId, "circle_2");
        glUniform1i(circle_2, 10);

        glActiveTexture(GL_TEXTURE11);
        glBindTexture(GL_TEXTURE_2D, texture[11]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[11]->sizeX, image[11]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[11]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        circle_3 = glGetUniformLocation(programId, "circle_3");
        glUniform1i(circle_3, 11);
        
        glActiveTexture(GL_TEXTURE12);
        glBindTexture(GL_TEXTURE_2D, texture[12]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[12]->sizeX, image[12]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[12]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        circle_4 = glGetUniformLocation(programId, "circle_4");
        glUniform1i(circle_4, 12);

        glActiveTexture(GL_TEXTURE13);
        glBindTexture(GL_TEXTURE_2D, texture[13]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[13]->sizeX, image[13]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[13]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        circle_5 = glGetUniformLocation(programId, "circle_5");
        glUniform1i(circle_5, 13);

        glActiveTexture(GL_TEXTURE14);
        glBindTexture(GL_TEXTURE_2D, texture[14]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[14]->sizeX, image[14]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[14]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        dragon_green = glGetUniformLocation(programId, "dragon_green");
        glUniform1i(dragon_green, 14);
        
        glActiveTexture(GL_TEXTURE15);
        glBindTexture(GL_TEXTURE_2D, texture[15]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[15]->sizeX, image[15]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[15]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        dragon_red = glGetUniformLocation(programId, "dragon_red");
        glUniform1i(dragon_red, 15);

        glActiveTexture(GL_TEXTURE16);
        glBindTexture(GL_TEXTURE_2D, texture[16]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[16]->sizeX, image[16]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[16]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        dragon_white = glGetUniformLocation(programId, "dragon_white");
        glUniform1i(dragon_white, 16);
        
        glActiveTexture(GL_TEXTURE17);
        glBindTexture(GL_TEXTURE_2D, texture[17]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[17]->sizeX, image[17]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[17]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        flower_1 = glGetUniformLocation(programId, "flower_1");
        glUniform1i(flower_1, 17);

        glActiveTexture(GL_TEXTURE18);
        glBindTexture(GL_TEXTURE_2D, texture[18]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[18]->sizeX, image[18]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[18]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        flower_2 = glGetUniformLocation(programId, "flower_2");
        glUniform1i(flower_2, 18);

        glActiveTexture(GL_TEXTURE19);
        glBindTexture(GL_TEXTURE_2D, texture[19]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[19]->sizeX, image[19]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[19]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        flower_3 = glGetUniformLocation(programId, "flower_3");
        glUniform1i(flower_3, 19);

        glActiveTexture(GL_TEXTURE20);
        glBindTexture(GL_TEXTURE_2D, texture[20]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[20]->sizeX, image[20]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[20]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        flower_4 = glGetUniformLocation(programId, "flower_4");
        glUniform1i(flower_4, 20);
        
        glActiveTexture(GL_TEXTURE21);
        glBindTexture(GL_TEXTURE_2D, texture[21]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[21]->sizeX, image[21]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[21]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        season_autumn = glGetUniformLocation(programId, "season_autumn");
        glUniform1i(season_autumn, 21);

        glActiveTexture(GL_TEXTURE22);
        glBindTexture(GL_TEXTURE_2D, texture[22]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[22]->sizeX, image[22]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[22]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        season_spring = glGetUniformLocation(programId, "season_spring");
        glUniform1i(season_spring, 22);
        
        glActiveTexture(GL_TEXTURE23);
        glBindTexture(GL_TEXTURE_2D, texture[23]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[23]->sizeX, image[23]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[23]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        season_summer = glGetUniformLocation(programId, "season_summer");
        glUniform1i(season_summer, 23);
        
        glActiveTexture(GL_TEXTURE24);
        glBindTexture(GL_TEXTURE_2D, texture[24]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[24]->sizeX, image[24]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[24]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        season_winter = glGetUniformLocation(programId, "season_winter");
        glUniform1i(season_winter, 24);
        
        glActiveTexture(GL_TEXTURE25);
        glBindTexture(GL_TEXTURE_2D, texture[25]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[25]->sizeX, image[25]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[25]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        wan_1 = glGetUniformLocation(programId, "wan_1");
        glUniform1i(wan_1, 25);

        glActiveTexture(GL_TEXTURE26);
        glBindTexture(GL_TEXTURE_2D, texture[26]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[26]->sizeX, image[26]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[26]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        wan_2 = glGetUniformLocation(programId, "wan_2");
        glUniform1i(wan_2, 26);
        
        glActiveTexture(GL_TEXTURE27);
        glBindTexture(GL_TEXTURE_2D, texture[27]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[27]->sizeX, image[27]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[27]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        wan_3 = glGetUniformLocation(programId, "wan_3");
        glUniform1i(wan_3, 27);

        glActiveTexture(GL_TEXTURE28);
        glBindTexture(GL_TEXTURE_2D, texture[28]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[28]->sizeX, image[28]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[28]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        wan_4 = glGetUniformLocation(programId, "wan_4");
        glUniform1i(wan_4, 28);
        
        glActiveTexture(GL_TEXTURE29);
        glBindTexture(GL_TEXTURE_2D, texture[29]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[29]->sizeX, image[29]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[29]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        wan_5 = glGetUniformLocation(programId, "wan_5");
        glUniform1i(wan_5, 29);

        glActiveTexture(GL_TEXTURE31);
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[0]->sizeX, image[0]->sizeY, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image[0]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        bamboo_1 = glGetUniformLocation(programId, "bamboo_1");
        glUniform1i(bamboo_1, 31);
}
