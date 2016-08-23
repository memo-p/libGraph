/*
 * Copyright (C) 2016 Guillaume Perez
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; If not, see <http://www.gnu.org/licenses/>.
*/

#include "TextureManager.h"


void TextureManager::loadBMP(const char * imagepath){
    unsigned int imageSize;  
    // RGBA 
    unsigned char * pixels;

    FILE * file = fopen(imagepath,"rb");
    if (!file) {
    	printf("Image could not be opened %s\n",imagepath); 
    	textID = ERRORTEXTURE;
    	return ;}
    if ( fread(header, 1, 54, file)!=54 ){
        printf("Not a correct BMP file %s\n",imagepath);
    	textID = ERRORTEXTURE;
        return ;
    }
    if ( header[0]!='B' || header[1]!='M' ){
        printf("Not a correct BMP file %s\n",imagepath);
    	textID = ERRORTEXTURE;
        return ;
    }

    unsigned int dataS = *(int*)&(header[0x0A]);
    imageSize  = *(int*)&(header[0x22]);
    width      = *(int*)&(header[0x12]);
    height     = *(int*)&(header[0x16]);

    

    int nbPixels = width * height;
    imageSize  = nbPixels*4;

    // Create a buffer
    pixels = new unsigned char [imageSize];

    if (dataS > 54)
    {
    	std::cout << "dataS=" << dataS << "\n";
    	fread(pixels,sizeof(char),dataS-54,file);
    }

    // Read the pixels from the file
    // fread(pixels,sizeof(char),imageSize,file);
    for (int i = 0; i < nbPixels; ++i)
    {
    	fread(&pixels[(i*4)+3],sizeof(char),1,file);
    	fread(&pixels[(i*4)+2],sizeof(char),1,file);
    	fread(&pixels[(i*4)+1],sizeof(char),1,file);
    	fread(&pixels[(i*4)],sizeof(char),1,file);
    }

    fclose(file);

    // Creation of an OpenGL texture
    glGenTextures(1, &textID);

    glBindTexture(GL_TEXTURE_2D, textID);

    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

}

float * TextureManager::getCoord(int i, int j){
        float  *retour = new float[4];
        retour[0] = i  *  s1;
        retour[1] = retour[0] + s1;
        retour[2] = j  *  s2 ;
        retour[3] = retour[2] +  s2;
        return retour;
    }

TextureManager::TextureManager(const char * imagepath, int nbHorizontal,int nbVerticale):
		s1(1.0f/nbHorizontal),
		s2(1.0f/nbVerticale)
		
	{
		loadBMP(imagepath);
		pxW = 1.0f/width;
		pxH = 1.0f/height;
	}