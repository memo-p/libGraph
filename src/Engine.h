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
#include "ControlEngineBase.h"
#include "GameEngineBase.h"
#include "GraphicEngineBase.h"
#include "libGraphicInclude.h"
#include "GraphicPrimitives.h"

//singleton
class Engine {
public:
    
    Engine(int argc, char * argv[],int width = 800,int height = 600,char * title = "TP");
    
    //these methods are in the header file because you have to see that the previous Engines are deleted...
    void setControlEngine(ControlEngineBase* crtE){
        delete crtE_;
        crtE_ = crtE;
    }
    void setGameEngine(GameEngineBase* gmE){
        delete gmE_;
        gmE_ = gmE;
    }
    void setGraphicEngine(GraphicEngineBase* grE){
        delete grE_;
        grE_ = grE;
    }
    
    void start();
    
    static ControlEngineBase * crtE_;
    static GameEngineBase * gmE_;
    static GraphicEngineBase * grE_;
    
private:
    void controlBoot();
    void graphicBoot();
    void gameBoot();
    
};