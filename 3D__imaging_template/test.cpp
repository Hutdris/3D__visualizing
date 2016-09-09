// 3D__imaging_template.cpp : Defines the entry point for the console application.
//

/*basic include*/
#include "stdafx.h"



using namespace cv;
using namespace std;


#define	PI 3.14159265358979323846f


float g_fViewDistance = 9.;
int g_Width = 1200;
int g_Height = 1200;

float g_nearPlane = 1.;
float g_farPlane = 100.;

string action = "";
float xStart = 0.;
float yStart = 0.;
float zoom = 65.;

float xRotate = 0.;
float yRotate = 0.;
float zRotate = 0.;

float xTrans = 0.;
float yTrans = 0.;

/* Global variables */
char title[] = "3D Shapes";
 

/* Initialize OpenGL Graphics */
void initGL() 
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glEnable(GL_NORMALIZE);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClearDepth(1.0f);                   // Set background depth to farthest
	glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
	glShadeModel(GL_SMOOTH);   // Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

void sceneModel()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//X axis
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(-10.0, 0.0, 0.0);
	glVertex3f(1, 0.0, 0.0);

	glEnd();
	glFlush();


	//Y axis
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, -10.0, 0.0);
	glVertex3f(0.0, 10.0, 0.0);

	glEnd();
	glFlush();

	//Z axis
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, -10.0);
	glVertex3f(0.0, 0.0, 10.0);

	glEnd();
	glFlush();

	/*
	glColor3f(0.0f, 10.0f, 0.0f);    // Color Blue
	glBegin(GL_QUADS);        // Draw The Cube Using quads
	glVertex3f(2.0f, 1.0f, -1.60f);    // Top Right Of The Quad (Top)
	glVertex3f(-1.0f, 1.10f, -14.0f);    // Top Left Of The Quad (Top)
	glVertex3f(-1.1f, 1.0f, 1.1f);    // Bottom Left Of The Quad (Top)
	glVertex3f(1.2f, 2.0f, 1.0f);    // Bottom Right Of The Quad (Top)
	
	glEnd();
	glFlush();
	*/

	glRotatef(90., 0., 0., 1.);
	glutSolidTeapot(1.);

	glEnd();
	glFlush();
}

void DrawCube()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glRotatef(0.5, 0, 0.5, 1);
	glTranslatef(1, 1, 0);
	glColor3f(0, 0, 1);
	
	glBegin(GL_QUADS);        // Draw The Cube Using quads
	glColor3f(0.0f, 1.0f, 0.0f);    // Color Blue
	glVertex3f(1.0f, 1.0f, -1.0f);    // Top Right Of The Quad (Top)
	glVertex3f(-1.0f, 1.0f, -1.0f);    // Top Left Of The Quad (Top)
	glVertex3f(-1.0f, 1.0f, 1.0f);    // Bottom Left Of The Quad (Top)
	glVertex3f(1.0f, 1.0f, 1.0f);    // Bottom Right Of The Quad (Top)

	glColor3f(1.0f, 0.5f, 0.0f);    // Color Orange
	glVertex3f(1.0f, -1.0f, 1.0f);    // Top Right Of The Quad (Bottom)
	glVertex3f(-1.0f, -1.0f, 1.0f);    // Top Left Of The Quad (Bottom)
	glVertex3f(-1.0f, -1.0f, -1.0f);    // Bottom Left Of The Quad (Bottom)
	glVertex3f(1.0f, -1.0f, -1.0f);    // Bottom Right Of The Quad (Bottom)
	glColor3f(1.0f, 0.0f, 0.0f);    // Color Red    
	glVertex3f(1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Front)
	glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Front)
	glVertex3f(-1.0f, -1.0f, 1.0f);    // Bottom Left Of The Quad (Front)
	glVertex3f(1.0f, -1.0f, 1.0f);    // Bottom Right Of The Quad (Front)
	glColor3f(1.0f, 1.0f, 0.0f);    // Color Yellow
	glVertex3f(1.0f, -1.0f, -1.0f);    // Top Right Of The Quad (Back)
	glVertex3f(-1.0f, -1.0f, -1.0f);    // Top Left Of The Quad (Back)
	glVertex3f(-1.0f, 1.0f, -1.0f);    // Bottom Left Of The Quad (Back)
	glVertex3f(1.0f, 1.0f, -1.0f);    // Bottom Right Of The Quad (Back)
	glColor3f(0.0f, 0.0f, 1.0f);    // Color Blue
	glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Left)
	glVertex3f(-1.0f, 1.0f, -1.0f);    // Top Left Of The Quad (Left)
	glVertex3f(-1.0f, -1.0f, -1.0f);    // Bottom Left Of The Quad (Left)
	glVertex3f(-1.0f, -1.0f, 1.0f);    // Bottom Right Of The Quad (Left)
	glColor3f(1.0f, 0.0f, 1.0f);    // Color Violet
	glVertex3f(1.0f, 1.0f, -1.0f);    // Top Right Of The Quad (Right)
	glVertex3f(1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Right)
	glVertex3f(1.0f, -1.0f, 1.0f);    // Bottom Left Of The Quad (Right)
	glVertex3f(1.0f, -1.0f, -1.0f);    // Bottom Right Of The Quad (Right)
	
	
	
	glPopMatrix();


	glEnd();            // End Drawing The Cube
	glFlush();
}

void polarView()
{
	glTranslatef(yTrans / 10., 0.0, 0.0);
	glTranslatef(0.0, -xTrans / 10., 0.0);
	glRotatef(-zRotate, 0.0, 0.0, 1.0);
	glRotatef(-xRotate, 1.0, 0.0, 0.0);
	glRotatef(-yRotate, .0, 1.0, 0.0);
}

void resetView()
{
	zoom = 65.;
	xRotate = 0.;
	yRotate = 0.;
	zRotate = 0.;
	xTrans = 0.;
	yTrans = 0.;
	glutPostRedisplay();
}


void mouseButton(int button, int state, int x, int y) 
{

	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON)
	{
		if (glutGetModifiers() == GLUT_ACTIVE_SHIFT)
		{
			action = "MOVE_EYE_2";
		}
		else
		{
			action = "MOVE_EYE";
		}

	}
	else if (button == GLUT_MIDDLE_BUTTON)
	{
		action = "ZOOM";
	}
	else if (button == GLUT_RIGHT_BUTTON)
	{
		action = "TRANS";
	}

	xStart = x;
	yStart = y;
}

void mouseMotion(int x, int y)
{
	if (action == "MOVE_EYE")
	{
		xRotate += x - xStart;
		yRotate -= y - yStart;
	}
	else if (action == "MOVE_EYE_2")
	{
		zRotate += y - yStart;
	}
	else if (action == "TRANS")
	{
		xTrans += x - xStart;
		yTrans += y - yStart;
	}
	else if (action == "ZOOM")
	{
		zoom -= y - yStart;
		if (zoom > 150.)
		{
			zoom = 150.;

		}
		else if (zoom < 1.1)
		{
			zoom = 1.1;
		}
	}
	else { cout << "unknown action"; }
	xStart = x;
	yStart = y;
	glutPostRedisplay();
}

/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void display() 
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers

	glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	

	glLoadIdentity();
	gluLookAt(0, 0, -g_fViewDistance, 0, 0, 0, -.1, 0, 0);   //- .1, 0, 0


//Set perspective(also zoom)
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(zoom, float(g_Width) / float(g_Height), g_nearPlane, g_farPlane);
	glMatrixMode(GL_MODELVIEW);
	
	DrawCube();
	polarView();
	sceneModel();
	

	glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}
 
/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */


void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
   
   DrawCube();
   sceneModel();
}
 



/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // Enable double buffered mode
   glutInitWindowSize(g_Width, g_Height);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow("sample");          // Create window with the given title
   
   
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutMouseFunc(mouseButton);
   glutMotionFunc(mouseMotion);

   initGL();
   DrawCube();// Our own OpenGL initialization
   sceneModel();
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}