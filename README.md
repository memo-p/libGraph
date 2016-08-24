# libGraph

# Description

The libGraph library provides a collection of functions for a C++ student project. The goals is to provide an easy schema to fastly implement game engine and graphics. Using easy high level methods. 


# Prerequisites

For the linux users, you will need free-glut.

	 - sudo apt-get install freeglut3-dev

Into the include directory, remove the directory GL.

# Uses

You will use inheritance from ControlEngine, GameEngine and GraphicEngine to override the graphic, control and game callbacks.

## ControlEngine
This class provides 8 methods to override for the interactions.

    - virtual void KeyboardCallback(unsigned char key,int x, int y);
Which we will "override" to handle keyboard pression.

    - virtual void KeyboardReleaseCallback(unsigned char key,int x, int y);
Which we will "override" to handle keyboard release.

    - virtual void specialCallback(int key,int x, int y);
Which we will "override" to handle special keyboard pression.

    - virtual void MouseCallback(int button, int state, int x, int y);
Which we will "override" to handle mousse button.

    - virtual void MotionCallback(int x, int y);
Which we will "override" to handle the active mouse motion.

    - virtual void PassiveMotionCallback(int x, int y);
Which we will "override" to handle the passive mouse motion.

    - virtual void MouseEntry(int state);
Which we will "override" to handle the mouse entry.

    - virtual void JoystickCallback(unsigned int buttonMask, int x, int y, int z);
Which we will "override" to handle a controller.

If you need some informations about this methods and their arguments, go on the official documentation glut, libGraph is based on:
	- https://www.opengl.org/resources/libraries/glut/spec3/node45.html


# GameEngine

This class provides only one method, but a fundamental one. The IDLE callback:
    - virtual void idle();

This idle methods is called every time their is nothing to do. This method has to be overrided.

# GraphicEngine
This class provides 2 methods:
	- virtual void Draw();
Which has to be "override" and which contains all the GraphicPrimitives call.

    - virtual void reshape(int width, int height);
Which has to be "override" and which is call each time the windows is resized.

# GraphicPrimitives
This class provides all the drawing methods:
	- static void drawFillRect2D(float x,float y,float width,float height,float r,float g, float b,float a = 1.0f);
Draw a filled rectangle in (x,y) with width and height and with color r,g,b,a.

	- static void drawOutlinedRect2D(float x,float y,float width,float height,float r,float g, float b,float a = 1.0f);
Draw a outlined rectangle in (x,y) with width and height and with color r,g,b,a.

	- static void drawLine2D(float x1,float y1,float x2,float y2,float r,float g, float b,float a = 1.0f);
Draw a line from the point (x1,y1) to the point (x2,y2) and with color r,g,b,a

	- static void drawFillTriangle2D(float x1,float y1,float x2,float y2,float x3,float y3,float r,float g, float b,float a = 1.0f);
Draw a triangle with this 3 points and with color r,g,b,a

	- static void drawOutlinedPolygone2D(std::vector<float> &x,std::vector<float> &y,float r,float g, float b,float a = 1.0f);
Draw a outlined polygone.

	- static void drawFillPolygone2D(std::vector<float> &x,std::vector<float> &y,float r,float g, float b,float a = 1.0f);
Draw a filled polygone.

	- static void drawText2D(char * str,float x,float y,float r,float g, float b,float a = 1.0f);
write text on the screen.

# Simple example

Check my other repository useLibGraph, their is an example of application which is based on 3 classes. 
## MyControlEngine
which will override:

	-virtual void MouseCallback(int button, int state, int x, int y);
Which adds butterflies on click.

## MyGameEngine
which will override:

	- virtual void idle();

which only make butterflies move.

## MyGraphicEngine
which will override:

	- virtual void Draw();
which will draw the butterflies

# Project using this library

	- https://github.com/lukesmolo/STD

	- https://github.com/lukesmolo/MDACS









