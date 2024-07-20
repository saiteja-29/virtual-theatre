#include <bits/stdc++.h>
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include "chair.h"
#include "chairarm.h"
#include "stair.h"
#include "imageio.h"
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000
GLuint texture;
using namespace std;
bool lightOn[3] = {false,true,true};
int val=0;
// angle of rotation for the camera direction
float angle = 0.0, yAngle = 0.0;
// actual vector representing the camera's direction
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
// XZ position of the camera
float x = -15.0f, z = 20.0f, y = 5.0f;
float roll = 0.0f;

// for mouse movements
float halfWidth = (float)(WINDOW_WIDTH / 2.0);
float halfHeight = (float)(WINDOW_HEIGHT / 2.0);
float mouseX = 0.0f, mouseY = 0.0f;
double rotate_x = 0, rotate_y = 0, zoom = 1;

unsigned char *image;
int width, height, bpp;

int texImageWidth;
int texImageHeight;
void Stair ::drawStair()
{

	glColor3f(0.5569, 0.3725, 0.1137);

	glBegin(GL_QUADS);
	// stair seat
	// Front
	//
	glVertex3f(-17.0f, +0.0f, 0.0f);
	glVertex3f(-17.0f, -1.0f, 0.0f);
	glVertex3f(+20.0f, -1.0f, 0.0f);
	glVertex3f(+20.0f, +0.0f, 0.0f);

	glColor3f(0.3647f, 0.2627f, 0.1059f);


	// Right
	//
	glVertex3f(+20.0f, -1.0f, +0.0f);
	glVertex3f(+20.0f, +0.0f, +0.0f);
	glVertex3f(+20.0f, +0.0f, -1.0f);
	glVertex3f(+20.0f, -1.0f, -1.0f);

	// Back
	//;
	glVertex3f(-17.0f, +0.0f, -1.0f);
	glVertex3f(-17.0f, -1.0f, -1.0f);
	glVertex3f(+20.0f, -1.0f, -1.0f);
	glVertex3f(+20.0f, +0.0f, -1.0f);

	// Left
	// ;
	glVertex3f(-17.0f, -1.0f, +0.0f);
	glVertex3f(-17.0f, -1.0f, -1.0f);
	glVertex3f(-17.0f, +0.0f, -1.0f);
	glVertex3f(-17.0f, +0.0f, +0.0f);

	// top
	//

	glVertex3f(+20.0f, -1.0f, -1.0f);
	glVertex3f(-17.0f, -1.0f, -1.0f);
	glVertex3f(-17.0f, -1.0f, +0.0f);
	glVertex3f(+20.0f, -1.0f, +0.0f);

	// bottom
	// ;

	glVertex3f(+20.0f, 0.0f, -1.0f);
	glVertex3f(-17.0f, 0.0f, -1.0f);
	glVertex3f(-17.0f, 0.0f, +0.0f);
	glVertex3f(+20.0f, 0.0f, +0.0f);
	glEnd();

	// front strip
	glColor3f(0.4f, 0.2f, 0.0f);
	glLineWidth(10.0f);
	glBegin(GL_LINES);
	glVertex3f(-17.0f, +0.0f, 0.0f);
	glVertex3f(+20.0f, +0.0f, 0.0f);
	glEnd();

	// top strip
	glColor3f(0.4f, 0.2f, 0.0f);
	glLineWidth(30.0f);
	glBegin(GL_LINES);
	glVertex3f(-17.0f, -1.0f, -1.0f);
	glVertex3f(+20.0f, -1.0f, -1.0f);
	glEnd();
}
// Function to draw char
void Chair ::drawChair(int k)
{

	glColor3f(0.6314f, 0.0275f, 0.0275f);
if(k==8) glColor3f(0.0431f, 0.2667f, 0.4627f);


	glBegin(GL_QUADS);
	// chair seat
	// Front
	//
	glVertex3f(-2.0f, -2.0f, 2.0f);
	glVertex3f(2.0f, -2.0f, 2.0f);
	glVertex3f(2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, 2.0f);

	// Right
	//
	glVertex3f(2.0f, -2.0f, -2.0f);
	glVertex3f(2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, 2.0f);
	glVertex3f(2.0f, -2.0f, 2.0f);

	// Back
	//;
	glVertex3f(-2.0f, -2.0f, -2.0f);
	glVertex3f(-2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, -2.0f, -2.0f);

	// Left
	// ;
	glVertex3f(-2.0f, -2.0f, -2.0f);
	glVertex3f(-2.0f, -2.0f, 2.0f);
	glVertex3f(-2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, -2.0f);

	// top
	//

	glVertex3f(2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, -2.0f);

	// bottom
	// ;

	glVertex3f(2.0f, -2.0f, 2.0f);
	glVertex3f(-2.0f, -2.0f, 2.0f);
	glVertex3f(-2.0f, -2.0f, -2.0f);
	glVertex3f(2.0f, -2.0f, -2.0f);

	// chair back
	// front
	// chair upper part
	glColor3f(0.8706f, 0.0863f, 0.0863f);
if(k==8) glColor3f(0.0196f, 0.1647f, 0.2980f);


	glVertex3f(-1.8f, 0.2f, -1.8f);
	glVertex3f(1.8f, 0.2f, -1.8f);
	glVertex3f(1.8f, 3.5f, -1.8f);
	glVertex3f(-1.8f, 3.5f, -1.8f);

	glVertex3f(-1.8f, 0.2f, -0.6f);
	glVertex3f(1.8f, 0.2f, -0.6f);
	glVertex3f(1.8f, 3.5f, -0.6f);
	glVertex3f(-1.8f, 3.5f, -0.6f);

	// chair upper side
	glVertex3f(-1.8f, 0.2f, -1.80f);
	glVertex3f(-1.8f, 0.2f, -0.6f);
	glVertex3f(-1.8f, 3.5f, -0.6f);
	glVertex3f(-1.8f, 3.5f, -1.8f);

	glVertex3f(1.8f, 0.2f, -1.80f);
	glVertex3f(1.8f, 0.2f, -0.6f);
	glVertex3f(1.8f, 3.5f, -0.6f);
	glVertex3f(1.8f, 3.5f, -1.8f);

	// chiar upper top
	glVertex3f(-1.8f, 3.5f, -1.80f);
	glVertex3f(-1.8f, 3.5f, -0.6f);
	glVertex3f(1.8f, 3.5f, -0.6f);
	glVertex3f(1.8f, 3.5f, -1.8f);

	glVertex3f(-1.8f, 0.2f, -1.80f);
	glVertex3f(-1.8f, 0.2f, -0.6f);
	glVertex3f(1.8f, 0.2f, -0.6f);
	glVertex3f(1.8f, 0.2f, -1.8f);

	glEnd();
}
// Function to draw chararms

void ChairArm ::drawChairArm()
{
  glColor3f(0.251f, 0.043f, 0.043f);

    glBegin(GL_QUADS);
    // chair arm
    // Front
    //
    glVertex3f(-0.4f, -2.0f, 2.0f);
    glVertex3f(0.4f, -2.0f, 2.0f);
    glVertex3f(0.4f, 1.3f, 2.0f);
    glVertex3f(-0.4f, 1.3f, 2.0f);

    // Right

    glVertex3f(0.4f, -2.0f, -2.0f);
    glVertex3f(0.4f, 1.3f, -2.0f);
    glVertex3f(0.4f, 1.3f, 2.0f);
    glVertex3f(0.4f, -2.0f, 2.0f);

    // Back

    glVertex3f(-0.4f, -2.0f, -0.2f);
    glVertex3f(0.4f, -2.0f, -0.2f);
    glVertex3f(0.4f, 1.4f, -0.2f);
    glVertex3f(-0.4f, 1.3f, -0.2f);

    // Left

    glVertex3f(-0.4f, -2.0f, -2.0f);
    glVertex3f(-0.4f, -2.0f, 2.0f);
    glVertex3f(-0.4f, 1.3f, 2.0f);
    glVertex3f(-0.4f, 1.3f, -2.0f);

    // top

    glVertex3f(0.4f, 1.3f, 2.0f);
    glVertex3f(-0.4f, 1.3f, 2.0f);
    glVertex3f(-0.4f, 1.3f, -2.0f);
    glVertex3f(0.4f, 1.3f, -2.0f);

    // bottom

    glVertex3f(0.4f, -2.0f, 2.0f);
    glVertex3f(-0.4f, -2.0f, 2.0f);
    glVertex3f(-0.4f, -2.0f, -2.0f);
    glVertex3f(0.4f, -2.0f, -2.0f);

    glEnd();
}



void drawSign(double p, double q, double r, int s);
void drawGrills(int rot);

void downWall(void)
{
	// Draw floor
	glColor3f(0.33f, 0.33f, 0.33f);
	glBegin(GL_QUADS);
	glVertex3f(-20.0f, 00.0f, -20.0f);
	glVertex3f(-20.0f, 00.0f, +20.0f);
	glVertex3f(+20.0f, 00.0f, +20.0f);
	glVertex3f(+20.0f, 00.0f, -20.0f);
	glEnd();
}
// Function to draw ceiling
void topWall(void)
{
	// ceiling
	glColor3f(0.1f, 0.1f, 0.1f);
	glBegin(GL_QUADS);
	glVertex3f(-20.0f, 30.0f, -20.0f);
	glVertex3f(+20.0f, 30.0f, -20.0f);
	glVertex3f(+20.0f, 30.0f, +20.0f);
	glVertex3f(-20.0f, 30.0f, +20.0f);
	glEnd();
}
// Function to draw screen wall
void backWall(void)
{
	// screen wall
	glColor3f(0.15f, 0.15f, 0.15f);
	glBegin(GL_QUADS);
	glVertex3f(-20.0f, 00.0f, -20.0f);
	glVertex3f(-20.0f, 30.0f, -20.0f);
	glVertex3f(+20.0f, 30.0f, -20.0f);
	glVertex3f(+20.0f, 00.0f, -20.0f);
	glEnd();
}
// wall with entry side
void leftWall(void)
{
	// left wall
	glColor3f(0.263, 0.243, 0.165);
	glBegin(GL_QUADS);
	glVertex3f(-20.0f, 00.0f, -20.0f);
	glVertex3f(-20.0f, 30.0f, -20.0f);
	glVertex3f(-20.0f, 30.0f, +20.0f);
	glVertex3f(-20.0f, 00.0f, +20.0f);
	glEnd();
	for(int i=0;i<40;i+=8){
		for(int j=0;j<30;j+=4){
			glColor3f(0.416, 0.482, 0.451);
			glBegin(GL_QUADS);
			glVertex3f(-20.0f + 0.001f, 0.0f+j+2, -20.0f+i);
			glVertex3f(-20.0f + 0.001f, 0.0f+j+2, -20.0f+i+5 );
			glVertex3f(-20.0f + 0.001f, 0.0f+j, -20.0f+i+5);
			glVertex3f(-20.0f + 0.001f, 0.0f+j, -20.0f+i);
			glEnd();
		}
	}
	for(int i=8;i<41;i+=8){
		for(int j=2;j<30;j+=4){
			glColor3f(0.286, 0.322, 0.306);
			glBegin(GL_QUADS);
			glVertex3f(-20.0f + 0.001f, 0.0f+j+2, -20.0f+i);
			glVertex3f(-20.0f + 0.001f, 0.0f+j+2, -20.0f+i-3 );
			glVertex3f(-20.0f + 0.001f, 0.0f+j, -20.0f+i-3);
			glVertex3f(-20.0f + 0.001f, 0.0f+j, -20.0f+i);
			glEnd();
		}
	}

}
// wall with entrance
void frontWall(void)
{
	// wall with entrance
	glColor3f(0.263, 0.243, 0.165);
	glBegin(GL_QUADS);
	glVertex3f(-15.0f, 00.0f, 20.0f);
	glVertex3f(-15.0f, 30.0f, 20.0f);
	glVertex3f(+20.0f, 30.0f, 20.0f);
	glVertex3f(+20.0f, 00.0f, 20.0f);
	glEnd();

glColor3f(0.216, 0.208, 0.180);
	glBegin(GL_QUADS);
	glVertex3f(-18.0f, 30.0f, 20.0f);
	glVertex3f(-18.0f, 04.0f, 20.0f);
	glVertex3f(-15.0f, 04.0f, 20.0f);
	glVertex3f(-15.0f, 30.0f, 20.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-18.0f, 00.0f, 20.0f);
	glVertex3f(-18.0f, 30.0f, 20.0f);
	glVertex3f(-20.0f, 30.0f, 20.0f);
	glVertex3f(-20.0f, 00.0f, 20.0f);
	glEnd();

	// door frame
	glColor3f(0.4f, 0.2f, 0.0f);
	glLineWidth(30.0f);
	glBegin(GL_LINES);
	glVertex3f(-18.0f, 4.0f, 20.01f);
	glVertex3f(-15.0f, 4.0f, 20.01f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-18.0f, 4.0f, 20.01f);
	glVertex3f(-18.0f, 0.0f, 20.01f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-15.0f, 0.0f, 20.01f);
	glVertex3f(-15.0f, 4.0f, 20.01f);
	glEnd();

	// entrance wall stripes
	for(int i=0;i<32;i+=8){
		for(int j=0;j<30;j+=4){
			glColor3f(0.416, 0.482, 0.451);
			glBegin(GL_QUADS);
			glVertex3f(-15.0f +i, 0.0f+j+2, 20.0f- 0.005f);
			glVertex3f(-15.0f +i+5 , 0.0f+j+2, 20.0f-0.005f );
			glVertex3f(-15.0f +i+5, 0.0f+j, 20.0f-0.005f);
			glVertex3f(-15.0f +i, 0.0f+j, 20.0f-0.005f);
			glEnd();
		}
	}
	for(int i=8;i<33;i+=8){
		for(int j=2;j<30;j+=4){
			glColor3f(0.286, 0.322, 0.306);
			glBegin(GL_QUADS);
			glVertex3f(-15.0f + i, 0.0f+j+2, +20.0f-0.005f);
			glVertex3f(-15.0f + i-3, 0.0f+j+2, 20.0f-0.005f );
			glVertex3f(-15.0f + i-3, 0.0f+j, 20.0f-0.005f);
			glVertex3f(-15.0f + i, 0.0f+j, 20.0f-0.005f);
			glEnd();
		}
	}
	glColor3f(0.216, 0.208, 0.180);
	glBegin(GL_QUADS);
	glVertex3f(20.0f, 30.0f, 20.0f-0.006f);
	glVertex3f(20.0f, 0.0f, 20.0f-0.006f);
	glVertex3f(17.0f, 0.0f, +20.0f-0.006f);
	glVertex3f(17.0f, 30.0f, +20.0f-0.006f);
	glEnd();
}
	// wall with exit
void rightWall(void)
{


	glColor3f(0.263, 0.243, 0.165);
	glBegin(GL_QUADS);
	glVertex3f(20.0f, 00.0f, -12.0f);
	glVertex3f(20.0f, 30.0f, -12.0f);
	glVertex3f(20.0f, 30.0f, +20.0f);
	glVertex3f(20.0f, 00.0f, +20.0f);
	glEnd();
	// right wall stripes
	for(int i=0;i<40;i+=8){
		for(int j=0;j<30;j+=4){
			glColor3f(0.416, 0.482, 0.451);
			glBegin(GL_QUADS);
			glVertex3f(+20.0f - 0.002f, 0.0f+j+2, -12.0f+i);
			glVertex3f(+20.0f - 0.002f, 0.0f+j+2, -12.0f+i+5 );
			glVertex3f(+20.0f - 0.002f, 0.0f+j, -12.0f+i+5);
			glVertex3f(+20.0f -0.002f, 0.0f+j, -12.0f+i);
			glEnd();
		}
	}
	for(int i=8;i<41;i+=8){
		for(int j=2;j<30;j+=4){
			glColor3f(0.286, 0.322, 0.306);
			glBegin(GL_QUADS);
			glVertex3f(+20.0f -0.002f, 0.0f+j+2, -12.0f+i);
			glVertex3f(+20.0f - 0.002f, 0.0f+j+2, -12.0f+i-3 );
			glVertex3f(+20.0f - 0.002f, 0.0f+j, -12.0f+i-3);
			glVertex3f(+20.0f - 0.002f, 0.0f+j, -12.0f+i);
			glEnd();
		}
	}

	glBegin(GL_QUADS);
	glVertex3f(20.0f, 04.0f, -12.0f);
	glVertex3f(20.0f, 30.0f, -12.0f);
	glVertex3f(20.0f, 30.0f, -18.0f);
	glVertex3f(20.0f, 04.0f, -18.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(20.0f, 00.0f, -18.0f);
	glVertex3f(20.0f, 30.0f, -18.0f);
	glVertex3f(20.0f, 30.0f, -20.0f);
	glVertex3f(20.0f, 00.0f, -20.0f);
	glEnd();

	// exit door
	glColor3f(0.58f, 0.29f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(20.0f, 0.0f, -12.0f);
	glVertex3f(20.0f, 4.0f, -12.0f);
	glVertex3f(20.0f, 4.0f, -18.0f);
	glVertex3f(20.0f, 0.0f, -18.0f);
	glEnd();

	glColor3f(0.4f, 0.2f, 0.0f);
	glLineWidth(30.0f);
	glBegin(GL_LINES);
	glVertex3f(20.0f, 4.0f, -12.0f);
	glVertex3f(20.0f, 4.0f, -18.0f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(20.0f, 4.0f, -18.0f);
	glVertex3f(20.0f, 0.0f, -18.0f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(20.0f, 0.0f, -15.0f);
	glVertex3f(20.0f, 4.0f, -15.0f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(20.0f, 0.0f, -12.0f);
	glVertex3f(20.0f, 4.0f, -12.0f);
	glEnd();

	// handle left
	glColor3f(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex3f(19.9f, 1.9f, -14.6f);
	glVertex3f(19.9f, 1.9f, -14.5f);
	glVertex3f(19.9f, 2.1f, -14.5f);
	glVertex3f(19.9f, 2.1f, -14.6f);
	glEnd();

	// handle right
	glBegin(GL_QUADS);
	glVertex3f(19.9f, 1.9f, -15.4f);
	glVertex3f(19.9f, 1.9f, -15.5f);
	glVertex3f(19.9f, 2.1f, -15.5f);
	glVertex3f(19.9f, 2.1f, -15.4f);
	glEnd();


}
// DRAW projector room
void projectorRoom(void)
{

	// door
	glColor3f(0.58f, 0.29f, 0.0f);

	glBegin(GL_QUADS);
	glVertex3f(-13.0f, 12.0f, 19.99f);
	glVertex3f(-13.0f, 18.0f, 19.99f);
	glVertex3f(-10.0f, 18.0f, 19.99f);
	glVertex3f(-10.0f, 12.0f, 19.99f);
	glEnd();

	glColor3f(0.4f, 0.2f, 0.0f);
	glLineWidth(30.0f);
	glBegin(GL_LINES);
	glVertex3f(-13.0f, 18.0f, 19.99f);
	glVertex3f(-10.0f, 18.0f, 19.99f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-13.0f, 18.0f, 19.99f);
	glVertex3f(-13.0f, 12.0f, 19.99f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-10.0f, 12.0f, 19.99f);
	glVertex3f(-10.0f, 18.0f, 19.99f);
	glEnd();

	glColor3f(0, 0, 0);
	// handle left
	glBegin(GL_QUADS);
	glVertex3f(-11.2f, 15.9f, 19.9f);
	glVertex3f(-11.3f, 15.9f, 19.9f);
	glVertex3f(-11.3f, 16.1f, 19.9f);
	glVertex3f(-11.2f, 16.1f, 19.9f);
	glEnd();

	// handle right
	glBegin(GL_QUADS);
	glVertex3f(-12.2f, 15.9f, 19.9f);
	glVertex3f(-12.1f, 15.9f, 19.9f);
	glVertex3f(-12.1f, 16.1f, 19.9f);
	glVertex3f(-12.2f, 16.1f, 19.9f);
	glEnd();

	// Draw floor
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(-16.0f, 12.0f, 20.0f);
	glVertex3f(-16.0f, 12.0f, 26.0f);
	glVertex3f(-10.0f, 12.0f, 26.0f);
	glVertex3f(-10.0f, 12.0f, 20.0f);
	glEnd();

	// cieling
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(-16.0f, 18.0f, 20.0f);
	glVertex3f(-16.0f, 18.0f, 26.0f);
	glVertex3f(-10.0f, 18.0f, 26.0f);
	glVertex3f(-10.0f, 18.0f, 20.0f);
	glEnd();

	// wall
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(-16.0f, 12.0f, 26.0f);
	glVertex3f(-16.0f, 18.0f, 26.0f);
	glVertex3f(-10.0f, 18.0f, 26.0f);
	glVertex3f(-10.0f, 12.0f, 26.0f);
	glEnd();

	// wall
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(-16.0f, 12.0f, 20.0f);
	glVertex3f(-16.0f, 18.0f, 20.0f);
	glVertex3f(-16.0f, 18.0f, 26.0f);
	glVertex3f(-16.0f, 12.0f, 26.0f);
	glEnd();

	// wall
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 12.0f, 20.0f);
	glVertex3f(-10.0f, 18.0f, 20.0f);
	glVertex3f(-10.0f, 18.0f, 26.0f);
	glVertex3f(-10.0f, 12.0f, 26.0f);
	glEnd();
}

void leftStairSupport(void)
{
	// stair wall support left

	glColor3f(0.3f, 0.03f, 0.03f);
	glBegin(GL_POLYGON);
	glVertex3f(-14.0f, 00.0f, -08.0f);
	glVertex3f(-14.0f, 02.0f, -08.0f);
	glVertex3f(-14.0f, 15.0f, +17.0f);
	glVertex3f(-14.0f, 15.0f, +20.0f);
	glVertex3f(-14.0f, 00.0f, +20.0f);
	glVertex3f(-14.0f, 00.0f, -08.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-13.4f, 00.0f, -08.0f);
	glVertex3f(-13.4f, 02.0f, -08.0f);
	glVertex3f(-13.4f, 15.0f, +17.0f);
	glVertex3f(-13.4f, 15.0f, +20.0f);
	glVertex3f(-13.4f, 00.0f, +20.0f);
	glVertex3f(-13.4f, 00.0f, -08.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-13.4f, 02.0f, -08.0f);
	glVertex3f(-13.4f, 00.0f, -08.0f);
	glVertex3f(-14.0f, 00.0f, -08.0f);
	glVertex3f(-14.0f, 02.0f, -08.0f);
	glVertex3f(-14.0f, 15.0f, +17.0f);
	glVertex3f(-14.0f, 15.0f, +20.0f);
	glVertex3f(-13.4f, 15.0f, +20.0f);
	glVertex3f(-13.4f, 15.0f, +17.0f);
	glEnd();
}

void rightStairSupport(void)
{
	// stair wall support right
	glColor3f(0.3f, 0.03f, 0.03f);
	glBegin(GL_POLYGON);
	glVertex3f(+13.2f, 00.0f, -08.0f);
	glVertex3f(+13.2f, 02.0f, -08.0f);
	glVertex3f(+13.2f, 15.0f, +17.0f);
	glVertex3f(+13.2f, 15.0f, +20.0f);
	glVertex3f(+13.2f, 00.0f, +20.0f);
	glVertex3f(+13.2f, 00.0f, -08.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(+12.6f, 00.0f, -08.0f);
	glVertex3f(+12.6f, 02.0f, -08.0f);
	glVertex3f(+12.6f, 15.0f, +17.0f);
	glVertex3f(+12.6f, 15.0f, +20.0f);
	glVertex3f(+12.6f, 00.0f, +20.0f);
	glVertex3f(+12.6f, 00.0f, -08.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(+12.6f, 02.0f, -08.0f);
	glVertex3f(+12.6f, 00.0f, -08.0f);
	glVertex3f(+13.2f, 00.0f, -08.0f);
	glVertex3f(+13.2f, 02.0f, -08.0f);
	glVertex3f(+13.2f, 15.0f, +17.0f);
	glVertex3f(+13.2f, 15.0f, +20.0f);
	glVertex3f(+12.6f, 15.0f, +20.0f);
	glVertex3f(+12.6f, 15.0f, +17.0f);
	glEnd();
}

void floorPattern(void)
{
	// Floor pattern
	glColor3f(0.149f, 0.149f, 0.149f);
	glLineWidth(3.0f);
	for (int i = 0; i < 40; i += 2)
	{
		glBegin(GL_LINES);
		glVertex3f(-20.0f + i, 0.001f, -20.01f);
		glVertex3f(-20.0f + i, 0.001f, +20.01f);
		glEnd();
	}
	for (int i = 0; i < 40; i += 2)
	{
		glBegin(GL_LINES);
		glVertex3f(-20.0f, 0.001f, -20.01f + i);
		glVertex3f(+20.0f, 0.001f, -20.01f + i);
		glEnd();
	}
}

void screen(void) {
    // Draw Screen
    if(!lightOn[0]){
			glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-17.0f, 10.0f, -19.99f);
    glTexCoord2f(0.0, 1.0); glVertex3f(-17.0f, 25.5f, -19.99f);
    glTexCoord2f(1.0, 1.0); glVertex3f(17.0f, 25.5f, -19.99f);
    glTexCoord2f(1.0, 0.0); glVertex3f(17.0f, 10.0f, -19.99f);
    glEnd();


    glDisable(GL_TEXTURE_2D);
	}
	else{
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
		glVertex3f(-17.0f, 10.0f, -19.99f);
		glVertex3f(-17.0f, 25.5f, -19.99f);
		glVertex3f(17.0f, 25.5f, -19.99f);
		glVertex3f(17.0f, 10.0f, -19.99f);
		glEnd();

		glColor3f(0.0f, 0.0f, 0.0f);
		glLineWidth(10.0f);
		glBegin(GL_LINES);
		glVertex3f(-17.0f, 10.0f, -19.99f);
		glVertex3f(-17.0f, 25.6f, -19.99f);
		glEnd();

		glBegin(GL_LINES);
		glVertex3f(-17.0f, 25.5f, -19.99f);
		glVertex3f(17.0f, 25.5f, -19.99f);
		glEnd();

		glBegin(GL_LINES);
		glVertex3f(17.0f, 25.6f, -19.99f);
		glVertex3f(17.0f, 10.0f, -19.99f);
		glEnd();

		glBegin(GL_LINES);
		glVertex3f(17.0f, 10.0f, -19.99f);
		glVertex3f(-17.0f, 10.0f, -19.99f);
		glEnd();
	}
}
void drawChairs(void)
{
	// Draw chairs and arms
	Chair chair[4][4];
	ChairArm chairArm[4][4];
	// sofa sofa[6][4];
	Stair stair[4];
	for (int j = -5; j <= 8; j++)
	{
	for (int i = -19; i <= 29; i += 2)
	{

			if(j==8){
				glPushMatrix();
				glTranslatef(i * 0.6, j * 1.0 + 4.8f, j * 2.0 + 2.2f);
				glScalef(0.25f, 0.25f, 0.25f);
				glRotatef(180.0, 0.0, 1.0, 0.0);
				glTranslatef(0, 2.0f, 0);
				if(j!=-5 && j!=7 && j!=-1)	chair[i][j].drawChair(8);
					glTranslatef(2.45f, 0.0f, 0.0f);
					if(j!=-5 && j!=7 && j!=-1) chairArm[i][j].drawChairArm();
					if ((i == -7||i==15|| i ==29) && j!=-5 && j!=7 && j!=-1)
					{
						glTranslatef(-4.9f, 0.0f, 0.0f);
						chairArm[i][j].drawChairArm();
					}

				glTranslatef(0.0f, -2.0f, 6.0f);
				glScalef(1.0f, 4.0f, 77.0f - j * 8.0);
				// if (j == -4)
				// {
				// 	glScalef(1.0f, 0.75f, 1.0f);
				// }
			if(i>-15 && i<29 && j!=-5)	stair[j].drawStair();
				glPopMatrix();

			}

			else	{glPushMatrix();
				glTranslatef(i * 0.6, j * 1.0 + 4.8f, j * 2.0 + 2.2f);
				glScalef(0.25f, 0.25f, 0.25f);
				glRotatef(180.0, 0.0, 1.0, 0.0);
				glTranslatef(0, 2.0f, 0);
			if(j!=-5 && j!=7 && j!=-1)	chair[i][j].drawChair(0);
				glTranslatef(2.45f, 0.0f, 0.0f);
				if(j!=-5 && j!=7 && j!=-1) chairArm[i][j].drawChairArm();
				if ((i == -7||i==15|| i ==29) && j!=-5 && j!=7 && j!=-1)
				{
					glTranslatef(-4.9f, 0.0f, 0.0f);
					chairArm[i][j].drawChairArm();
				}
				glTranslatef(0.0f, -2.0f, 6.0f);
				glScalef(1.0f, 4.0f, 77.0f - j * 8.0);
				// if (j == -4)
				// {
				// 	glScalef(1.0f, 0.75f, 1.0f);
				// }
			if(i>-15 && i<29 && j!=-5)	stair[j].drawStair();
				glPopMatrix();
				if (i == -7){
					i = -3;}
				if(i==15){
					i=19;}}

		}
	}
}
// Function to initialize OpenGL settings
void loadTexture(const char* filename) {
		int width, height;
		unsigned char* image = loadImageRGBA(const_cast<char*>(filename), &width, &height);

		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

		free(image);
}

void init() {
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_DEPTH_TEST); // Enable depth testing for proper rendering
		glEnable(GL_LIGHTING);   // Enable lighting
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHT0+1);
		// glEnable(GL_LIGHT1);
			// Enable light source 0
		glEnable(GL_COLOR_MATERIAL);
		glClearColor(0.0, 0.0, 0.0, 1.0);
	 loadTexture("img.png");
}

// to call/render the functions
void renderScene(void)
{

	// Clear Color and Depth Buffers

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//------------------------------------------------------------------------//

GLfloat light_position[3][4] = {
		 {0.0f, 29.0f, 10.0f, 0.0f}, // Position of light source 0: (1,1,1)
		 {0.0f,29.0f,-10.0f, 0.0f}, // Position of light source 1: (-1,-1,-1)
		 {5.0f,15.0f,15.0f,0.0f}
 };

 GLfloat light_color[3][4] = {
		 {2.0f, 2.0f, 2.0f, 1.0f}, // Color of light source 0: White
		 {0.5f, 0.5f, 0.5f, 1.0f}, // Color of light source 1: White
		 {0.5f, 0.5f, 0.5f, 1.0f}
 };
// if(val%3==) {light_color[0][0]={0.5f};
// light_color[0][1]={0.5f};light_color[0][2]={0.5f};light_color[0][3]={1.0f};}
 // Iterate through each light source
 for (int i = 0; i < 3; ++i) {
		 // If the light switch is on, enable the light source
		 if (lightOn[i]) {
				 glEnable(GL_LIGHT0 + i);
		 } else {
				 glDisable(GL_LIGHT0 + i);
		 }


		 // Set the light position and color
		 glLightfv(GL_LIGHT0 + i, GL_POSITION, light_position[i]);
		 glLightfv(GL_LIGHT0 + i, GL_DIFFUSE, light_color[i]);
	 }
//------------------------------------------------------------------------//
	// Reset transformations
	glLoadIdentity();

	// Set the camera
	gluLookAt(x, y, z, x + lx, y + ly, z + lz, roll + 0.0f, 2.5f, 0.0f);

	// Draw the down wall
	downWall();

	// Draw the top wall
	topWall();

	// Draw the back wall
	backWall();

	// Draw the left wall
	leftWall();

	// Draw the front wall
	frontWall();

	// Draw the right wall

	rightWall();

	// Draw the left stair support wall
	leftStairSupport();

	// Draw the right stair support wall

	// rightStairSupport();

	// Draw thee projector room
	projectorRoom();

	// Draw the screen
	screen();

	// Draw the chairs and stairs
	drawChairs();

	// Draw the floor pattern
	floorPattern();
	drawSign(0, -6, 1.5, 0);
	drawSign(2, -6, 0.1, 1);
	drawSign(7, 7, 0, 2);

	// AC grills
	drawGrills(0);
	drawGrills(1);
	drawGrills(2);

	// light_function_0(0.0,24.0,0.0);
	// light_function_1(-18.0,24.0,-18.0);
	// light_function_2(-18.0,24.0,-18.0);
	glutSwapBuffers();
}

// keys to operate the 3d model
void processNormalKeys(unsigned char key, int xx, int yy)
{
	float fraction = 1.0f;
	if (key == 'w')
	{
		float x1=x+(lx*fraction);
		if(x1<20.0 && x1>-20.0){
			x=x1;
		}
		float z1=z+(lz*fraction);
		if(z1<20.0 && z1>-20.0){
			if(x<-14.0)z=z1;
			else{
				if(z>-10.0){
					 if(y>(0.7*z1)+7.0){z=z1;}
				}
				else{z=z1;}
			}
		}

	}
	else if (key == 'a')
	{
		float x1,z1;
		x1=x + sin(angle - M_PI / 2.0) * fraction;
		z1=z + -cos(angle - M_PI / 2.0) * fraction;
		if(x1>-20.0 && x1<20.0) x=x1;
		if(z1<20.0 && z1>-20.0){
			if(x<-14.0)z=z1;
			else{
				if(z>-10.0){
					 if(y>(0.7*z1)+7.0){z=z1;}
				}
				else{z=z1;}
			}
		}
	}
	else if (key == 's')
	{
		float x1=x-(lx*fraction);
		if(x1>-20.0 && x1<20.0) x=x1;
		float z1=z-(lz*fraction);
		if(z1<20.0 && z1>-20.0){
			if(x<-14.0)z=z1;
			else{
				if(z>-10.0){
					 if(y>(0.7*z1)+7.0){z=z1;}
				}
				else{z=z1;}
			}
		}
	}
	else if (key == 'd')
	{
		float x1,z1;
		x1=x + sin(M_PI / 2.0 + angle) * fraction;
		z1=z += -cos(M_PI / 2.0 + angle) * fraction;
		if(x1>-20.0 && x1<20.0) x=x1;
		if(z1<20.0 && z1>-20.0){
			if(x<-14.0)z=z1;
			else{
				if(z>-10.0){
					 if(y>(0.7*z1)+7.0){z=z1;}
				}
				else{z=z1;}
			}
		}
	}
	else if (key == 'x')
	{
		roll += 0.5f;
	}
	else if (key == 'z')
	{
		roll -= 0.5f;
	}
	else if (key == 'm')
	{
		float y1=y+(ly * fraction);
		// y += ly * fraction;
		if(y1<30.0&& y1>0.0){
			y=y1;
		}
	}
	else if (key == 'n')
	{
		float y1=y-(ly * fraction);
		// y += ly * fraction;
		if(y1>0.0 &&y1<30.0){
			y=y1;
		}

	}
	else if(key=='1'){
		lightOn[0] =!lightOn[0];
	}
	else if(key=='2'){
		val!=val;
	}


}

// Handles the events triggered when the mouse is moved in the window area.
// Handles yaw and pitch of the camera.
// @param xx : x coordinate of mouse position
// @param yy : y coordinate of mouse position
void processMouseMovement(int xx, int yy)
{

	mouseX = (float)(halfWidth - xx) / halfWidth;
	mouseY = (float)(halfHeight - yy) / halfHeight;
	angle -= (0.01f * mouseX);
	lx = sin(angle);
	lz = -cos(angle);

	if (abs(yAngle) < (M_PI / 2))
	{
		yAngle += (0.01f * mouseY);
	}
	ly = sin(yAngle);
}

// Adjusts the viewport sie when the window size is changed and sets the projection.
// @param w : new width of window
// @param h : new height of window
void changeSize(int w, int h)
{

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);
	halfWidth = (float)(w / 2.0);
	halfHeight = (float)(h / 2.0);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void animate()
{
	/* refresh screen */
	glutPostRedisplay();
}

void grill()
{
	// Set the color to light gray
	glColor3f(0.8f, 0.8f, 0.8f);

	// Draw the square vent using GL_TRIANGLE_STRIP
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-0.4f, 0.4f, 0.0f);	// Top-left vertex
	glVertex3f(0.4f, 0.4f, 0.0f);	// Top-right vertex
	glVertex3f(-0.4f, -0.4f, 0.0f); // Bottom-left vertex
	glVertex3f(0.4f, -0.4f, 0.0f);	// Bottom-right vertex
	glEnd();

	// Set the color to black for the grills
	glColor3f(0.0f, 0.0f, 0.0f);

	// Draw the horizontal grill lines using GL_LINES
	glLineWidth(4.0f); // Set the line width to 1
	glBegin(GL_LINES);
	glVertex3f(-0.4f, 0.3f, 0.0f);	// Top line 1 left point
	glVertex3f(0.4f, 0.3f, 0.0f);	// Top line 1 right point
	glVertex3f(-0.4f, 0.1f, 0.0f);	// Top line 2 left point
	glVertex3f(0.4f, 0.1f, 0.0f);	// Top line 2 right point
	glVertex3f(-0.4f, -0.1f, 0.0f); // Bottom line 1 left point
	glVertex3f(0.4f, -0.1f, 0.0f);	// Bottom line 1 right point
	glVertex3f(-0.4f, -0.3f, 0.0f); // Bottom line 2 left point
	glVertex3f(0.4f, -0.3f, 0.0f);	// Bottom line 2 right point
	glEnd();

	// Draw the vertical grill lines using GL_LINES
	glBegin(GL_LINES);
	glVertex3f(-0.2f, 0.4f, 0.0f);	// Top line left point
	glVertex3f(-0.2f, -0.4f, 0.0f); // Bottom line left point
	glVertex3f(0.2f, 0.4f, 0.0f);	// Top line right point
	glVertex3f(0.2f, -0.4f, 0.0f);	// Bottom line right point
	glEnd();
}

void drawGrills(int rot)
{
	if (rot == 1)
	{
		glRotatef(-90.0, 0.0, 1.0, 0.0);
		glTranslatef(0, 0, -0.05);
	}
	else if (rot == 2)
	{
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glTranslatef(0, 0, -0.05);
	}
	glTranslatef(-19.6, 20, 19.95);
	for (int i = 0; i < 99; i++)
	{
		glPushMatrix();
		glTranslatef(i * 0.4, 0, 0);
		grill();
		glPopMatrix();
	}

	glTranslatef(19.6, -20, -19.95);
	if (rot == 1)
	{
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glTranslatef(0, 0, 0.05);
	}
	else if (rot == 2)
	{
		glRotatef(-90.0, 0.0, 1.0, 0.0);
		glTranslatef(0, 0, 0.05);
	}
}

void sign(int s)
{

	glColor3f(1.0f, 1.0f, 1.0f); // Set the color to white
	glBegin(GL_QUADS);
	glVertex3f(-17.75f, 29.0f, -20.0f); // Top-left vertex
	glVertex3f(-15.25f, 29.0f, -20.0f); // Top-right vertex
	glVertex3f(-15.25f, 26.0f, -20.0f); // Bottom-right vertex
	glVertex3f(-17.75f, 26.0f, -20.0f); // Bottom-left vertex
	glEnd();
	glColor3f(0.0f, 1.0f, 0.0f); // Set the color to white

	// Draw the rectangle
	glBegin(GL_QUADS);
	glVertex3f(-17.5f, 28.5f, -19.90f); // Top-left vertex
	glVertex3f(-15.5f, 28.5f, -19.90f); // Top-right vertex
	glVertex3f(-15.5f, 26.5f, -19.90f); // Bottom-right vertex
	glVertex3f(-17.5f, 26.5f, -19.90f); // Bottom-left vertex
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);

	// Draw the text
	glRasterPos3f(-17.5f, 27.5f, -19.90f); // Set the position of the text
	if (s == 0)
		glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)"EXIT");
	else if (s == 1)
		glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)"ENTRY");
	else
		glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)"PROJECTOR");
}

void drawSign(double p, double q, double r, int s)
{
	// draw sign
	glPushMatrix();
	glTranslatef(p, q, r);
	glScalef(1.0f, 0.5f, 1.0);
	if (s == 0)
	{
		glRotatef(-90.0, 0.0, 1.0, 0.0);
		glTranslatef(0, 0, 0.2);
	}
	else
	{
		glRotatef(-180.0, 0.0, 1.0, 0.0);
		glTranslatef(34.9, -4, 0.2);
	}
	sign(s);
	glPopMatrix();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Theatre");
	init();
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(animate);
	glutKeyboardFunc(processNormalKeys);
	glutPassiveMotionFunc(processMouseMovement);
		glShadeModel(GL_SMOOTH);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_NORMALIZE);
		glEnable(GL_LIGHTING);
		glEnable(GL_BLEND);
	// enter GLUT event processing cycle
	glutMainLoop();
}
