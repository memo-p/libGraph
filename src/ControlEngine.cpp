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


#include "ControlEngine.h"

void ControlEngine::KeyboardCallback(unsigned char key,int x, int y){
    switch (key) {
        case 'p':
            exit(0);
            break;
//        case <#constant#>:
//            <#statements#>
//            break;
            
        default:
            break;
    }
}

void ControlEngine::KeyboardReleaseCallback(unsigned char key,int x, int y){
    
}
void ControlEngine::specialCallback(int key,int x, int y){
    
}

void ControlEngine::MouseCallback(int button, int state, int x, int y){
    
}

void ControlEngine::MotionCallback(int x, int y){
    
}

void ControlEngine::PassiveMotionCallback(int x, int y){
    
}

void ControlEngine::MouseEntry(int state){
    
}


void ControlEngine::JoystickCallback(unsigned int state,
                      int x, int y, int z){
    
}
