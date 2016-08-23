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



#include "GraphicPrimitives.h"


//Pour les carre
//
//0,1--1,1
//|     |
//|     |
//0,0--1,0
//
//2--3
//|  |
//0--1



void GraphicPrimitives::drawFillRect2D(float x,float y,float width,float height,float r,float g, float b,float a ){
    glPushMatrix();
    glPushAttrib(GL_CURRENT_BIT);
    
    glColor4f (r,g,b,a);
    glBegin (GL_TRIANGLES);
    
    
    glVertex3f (x,y,0);
    glVertex3f (x + width,y,0);
    glVertex3f (x,y + height,0);
    
    glVertex3f (x+width,y+height,0);
    glVertex3f (x + width,y,0);
    glVertex3f (x,y + height,0);
    
    glEnd();
    glPopAttrib(); // This sets the colour back to its original value
}

void GraphicPrimitives::drawOutlinedRect2D(float x,float y,float width,float height,float r,float g, float b,float a){
    glPushMatrix();
    glPushAttrib(GL_CURRENT_BIT);
    
    glColor4f (r,g,b,a);
    glBegin (GL_LINES);
    //haut
    glVertex3f (x,y + height,0);
    glVertex3f (x + width,y + height,0);
    //bas
    glVertex3f (x,y,0);
    glVertex3f (x + width,y,0);
    //droite
    glVertex3f (x + width,y,0);
    glVertex3f (x + width,y + height,0);
    //gauche
    glVertex3f (x,y,0);
    glVertex3f (x,y + height,0);
    
    glEnd();
    glPopAttrib(); // This sets the colour back to its original value
}


void GraphicPrimitives::drawLine2D(float x1,float y1,float x2,float y2,float r,float g, float b,float a){
    glPushMatrix();
    glPushAttrib(GL_CURRENT_BIT);
    
    glColor4f (r,g,b,a);
    glBegin (GL_LINES);
    
    glVertex3f (x1,y1,0);
    glVertex3f (x2,y2,0);
    
    glEnd();
    glPopAttrib(); // This sets the colour back to its original value
    
}


void GraphicPrimitives::drawFillTriangle2D(float x1,float y1,float x2,float y2,float x3,float y3,float r,float g, float b,float a ){
    glPushMatrix();
    glPushAttrib(GL_CURRENT_BIT);
    
    glColor4f (r,g,b,a);
    glBegin (GL_TRIANGLES);
    
    
    glVertex3f (x1,y1,0);
    glVertex3f (x2,y2,0);
    glVertex3f (x3,y3,0);
    
    
    glEnd();
    glPopAttrib(); // This sets the colour back to its original value
}

void GraphicPrimitives::drawOutlinedPolygone2D(std::vector<float>& x,std::vector<float>& y,float r,float g, float b,float a ){
    
    glPushMatrix();
    glPushAttrib(GL_CURRENT_BIT);
    
    glColor4f (r,g,b,a);
    glBegin (GL_LINES);
    
    for (int i=0; i < x.size()-1; i++) {
        glVertex3f (x[i],y[i],0);
        glVertex3f (x[i+1],y[i+1],0);
    }
    glVertex3f (x[0],y[0],0);
    glVertex3f (x[x.size()-1],y[x.size()-1],0);
    
    glEnd();
    glPopAttrib(); // This sets the colour back to its original value
    
    
}

void GraphicPrimitives::drawFillPolygone2D(std::vector<float>& x,std::vector<float>& y,float r,float g, float b,float a ){
    
    glPushMatrix();
    glPushAttrib(GL_CURRENT_BIT);
    
    glColor4f (r,g,b,a);
    glBegin (GL_TRIANGLES);
    
    
    for (int i=0; i < x.size()-2; i++) {
        glVertex3f (x[i],y[i],0);
        glVertex3f (x[i+1],y[i+1],0);
        glVertex3f (x[i+2],y[i+2],0);
    }
    glVertex3f (x[0],y[0],0);
    glVertex3f (x[x.size()-2],y[x.size()-2],0);
    glVertex3f (x[x.size()-1],y[x.size()-1],0);
    
    glVertex3f (x[0],y[0],0);
    glVertex3f (x[1],y[1],0);
    glVertex3f (x[x.size()-1],y[x.size()-1],0);
    
    
    
    for (int i=0; i < x.size()-1; i++) {
        glVertex3f (x[i],y[i],0);
        glVertex3f (x[i+1],y[i+1],0);
    }
    glVertex3f (x[0],y[0],0);
    glVertex3f (x[x.size()-1],y[x.size()-1],0);
    
    glEnd();
    glPopAttrib(); // This sets the colour back to its original value
    
}


void GraphicPrimitives::drawText2D(char * str,float x,float y,float r,float g, float b,float a){
    glPushMatrix();
    glPushAttrib(GL_CURRENT_BIT);
    //on doit definir la couleur avant la fonction RasterPos sinon elle ne sera pas prise en compte ...
    glColor4f(r,g,b,a);
    glRasterPos2f( x,y) ;
    // Draw your text
    for (unsigned int i=0;i<strlen(str);i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*(str+i));
    }
    glPopAttrib(); // This sets the colour back to its original value
    glPopMatrix();
}
    
void GraphicPrimitives::drawSpritedRect2D(float x,float y,float width,float height,int tx,int ty,TextureManager* texture){
    drawSpritedRect2D(x,y,width,height,texture->getCoord(tx,ty),texture->textID);
}
void GraphicPrimitives::drawSpritedRect2D(float x,float y,float width,float height,float * textCoord,GLuint texture){
    glPushMatrix();
    glPushAttrib(GL_CURRENT_BIT);
    glBindTexture(GL_TEXTURE_2D, texture);
    
    glBegin (GL_TRIANGLES);
    
    glTexCoord2f(textCoord[0],textCoord[2]);
    glVertex3f (x,y,0);
    glTexCoord2f(textCoord[1],textCoord[2]);
    glVertex3f (x + width,y,0);
    glTexCoord2f(textCoord[0],textCoord[3]);
    glVertex3f (x,y + height,0);
    
    glTexCoord2f(textCoord[1],textCoord[3]);
    glVertex3f (x+width,y+height,0);
    glTexCoord2f(textCoord[1],textCoord[2]);
    glVertex3f (x + width,y,0);
    glTexCoord2f(textCoord[0],textCoord[3]);
    glVertex3f (x,y + height,0);
    
    glEnd();
    
    glPopAttrib(); // This sets the colour back to its original value
}





