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

#pragma once
#include "libGraphicInclude.h"
#include <cstdio>
#include <iostream>
#define ERRORTEXTURE 999999u

//Le fichier bmp doit être un fichier 32 bit ABGR (alpha blue green red)!

class TextureManager
{
	const float s1;
	const float s2;
	unsigned char header[54];
    unsigned int width, height;
	float pxW,pxH;
public:
	GLuint textID;

	TextureManager(const char * imagepath, int nbHorizontal,int nbVerticale);

	/* data */
    float * getCoord(int i, int j);
private:
	void loadBMP(const char * imagepath);
};