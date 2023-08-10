#version 430 core

// Material's properties
in vec4 frontAmbDiffExport, frontSpecExport, backAmbDiffExport, backSpecExport;
// texture coordinates
in vec2 texCoordsExport;

// samplers for the textures
uniform sampler2D background;
uniform sampler2D bamboo_1;
uniform sampler2D bamboo_2;
uniform sampler2D bamboo_3;
uniform sampler2D bamboo_4;
uniform sampler2D bamboo_5;
uniform sampler2D bamboo_6;
uniform sampler2D bamboo_7;
uniform sampler2D bamboo_8;
uniform sampler2D bamboo_9;
uniform sampler2D circle_1;
uniform sampler2D circle_2;
uniform sampler2D circle_3;
uniform sampler2D circle_4;
uniform sampler2D circle_5;
uniform sampler2D dragon_green;
uniform sampler2D dragon_red;
uniform sampler2D dragon_white;
uniform sampler2D flower_1;
uniform sampler2D flower_2;
uniform sampler2D flower_3;
uniform sampler2D flower_4;
uniform sampler2D season_autumn;
uniform sampler2D season_spring;
uniform sampler2D season_summer;
uniform sampler2D season_winter;
uniform sampler2D wan_1;
uniform sampler2D wan_2;
uniform sampler2D wan_3;
uniform sampler2D wan_4;
uniform sampler2D wan_5;
uniform sampler2D win;

uniform uint textures;
uniform uint object;

out vec4 colorsOut;

vec4 texColor;

void main(void)
{
    if(object == 0){
        if(textures == 0)        texColor = texture(bamboo_1, texCoordsExport);
        else if (textures == 1)  texColor = texture(bamboo_2, texCoordsExport);
        else if (textures == 2)  texColor = texture(bamboo_3, texCoordsExport);
        else if (textures == 3)  texColor = texture(bamboo_4, texCoordsExport);
        else if (textures == 4)  texColor = texture(bamboo_5, texCoordsExport);
        else if (textures == 5)  texColor = texture(bamboo_6, texCoordsExport);
        else if (textures == 6)  texColor = texture(bamboo_7, texCoordsExport);
        else if (textures == 7)  texColor = texture(bamboo_8, texCoordsExport);
        else if (textures == 8)  texColor = texture(bamboo_9, texCoordsExport);
        else if (textures == 9)  texColor = texture(circle_1, texCoordsExport);
        else if (textures == 10) texColor = texture(circle_2, texCoordsExport);
        else if (textures == 11) texColor = texture(circle_3, texCoordsExport);
        else if (textures == 12) texColor = texture(circle_4, texCoordsExport);
        else if (textures == 13) texColor = texture(circle_5, texCoordsExport);
        else if (textures == 14) texColor = texture(dragon_green, texCoordsExport);
        else if (textures == 15) texColor = texture(dragon_red, texCoordsExport);
        else if (textures == 16) texColor = texture(dragon_white, texCoordsExport);
        else if (textures == 17) texColor = texture(flower_1, texCoordsExport);
        else if (textures == 18) texColor = texture(flower_2, texCoordsExport);
        else if (textures == 19) texColor = texture(flower_3, texCoordsExport);
        else if (textures == 20) texColor = texture(flower_4, texCoordsExport);
        else if (textures == 21) texColor = texture(season_autumn, texCoordsExport);
        else if (textures == 22) texColor = texture(season_spring, texCoordsExport);
        else if (textures == 23) texColor = texture(season_summer, texCoordsExport);
        else if (textures == 24) texColor = texture(season_winter, texCoordsExport);
        else if (textures == 25) texColor = texture(wan_1, texCoordsExport);
        else if (textures == 26) texColor = texture(wan_2, texCoordsExport);
        else if (textures == 27) texColor = texture(wan_3, texCoordsExport);
        else if (textures == 28) texColor = texture(wan_4, texCoordsExport);
        else if (textures == 29) texColor = texture(wan_5, texCoordsExport);
    }
    if(object == 1){
        if(textures == 0)
            texColor = texture(background, texCoordsExport);
        else if(textures == 1)
            texColor = texture(win, texCoordsExport);
    }
    // set color of the fragment
    colorsOut = gl_FrontFacing? (frontAmbDiffExport * texColor + frontSpecExport) :
                               (backAmbDiffExport * texColor + backSpecExport);
}
