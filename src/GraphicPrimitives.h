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
#include <iostream>
#include <vector>
#include <string.h>

#include "libGraphicInclude.h"
#include "TextureManager.h"


class GraphicPrimitives {
    
public:
    
    /**
     * Dessine un rectangle en (x,y) de largeur width et hauteu height et de couleur r,g,b,a
     *
     */
    
    static void drawFillRect2D(float x,float y,float width,float height,float r,float g, float b,float a = 1.0f);
    
    /**
     * Dessine un rectangle avec juste ses arrete en (x,y) de largeur width et hauteu height et de couleur r,g,b,a
     *
     */
    static void drawOutlinedRect2D(float x,float y,float width,float height,float r,float g, float b,float a = 1.0f);
    
    /**
     * Dessine une ligne du point (x1,y1) au point (x2,y2) de couleur r,g,b,a
     *
     */
    static void drawLine2D(float x1,float y1,float x2,float y2,float r,float g, float b,float a = 1.0f);
    
    /**
     * Dessine un triangle qui relit les point 1 2 et 3, de couleur r,g,b,a
     *
     */
    static void drawFillTriangle2D(float x1,float y1,float x2,float y2,float x3,float y3,float r,float g, float b,float a = 1.0f);
    
    /**
     * Dessine un polygone (le dernier sommet rejoindra le premier)
     */
    static void drawOutlinedPolygone2D(std::vector<float> &x,std::vector<float> &y,float r,float g, float b,float a = 1.0f);
    
    /**
     * Dessine un polygone (le dernier sommet rejoindra le premier)
     */
    static void drawFillPolygone2D(std::vector<float> &x,std::vector<float> &y,float r,float g, float b,float a = 1.0f);
    
    /**
     * Ecrit le texte a l'ecran
     */
    static void drawText2D(char * str,float x,float y,float r,float g, float b,float a = 1.0f);
    
    /**
     * Affiche un rectangle contenant le sprite
     */
    static void drawSpritedRect2D(float x,float y,float width,float height,float * textCoord,GLuint texture);
    static void drawSpritedRect2D(float x,float y,float width,float height,int tx,int ty,TextureManager* texture);
    
};

