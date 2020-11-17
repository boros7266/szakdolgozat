#include <stdio.h>
#include "model.h"
#include "timer.h"
#include "texture.h"
#include "bounding_box.h"
#include "texture_box.h"
#include "draw.h"
#include "write_obj.h"
#include "triangulation.h"
#include "vertex_order.h"

#include <SOIL/SOIL.h>
#include <GL/glut.h>

double rotateX;
double rotateY;

Model model;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();

    glRotatef(-rotateY, 1.0, 0, 0);
    glRotatef(rotateX, 0, 1.0, 0);

    draw_model(&model);

	glPopMatrix();

	glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height)
{
	glViewport (0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, (GLdouble)width / (GLdouble)height, 0.01, 10000.0);
}

void mouseHandler(int button, int state, int x, int y)
{
}

void motionHandler(int x, int y)
{
    rotateX = x;
    rotateY = y;

    glutPostRedisplay();
}

void idle()
{
}

void initialize()
{
    glShadeModel(GL_SMOOTH);

    glEnable(GL_NORMALIZE);
    glEnable(GL_AUTO_NORMAL);

    glClearColor(0.0, 0.0, 0.0, 0.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(
        0.0, 0.0, -50,
        0.0, 0.0, 0.0,
        0.0, 1.0, 0.0
    );

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glClearDepth(1.0);

    initialize_texture();
}

int main(int argc, char* argv[])
{
    start_timer();
    rotateX = 0.0;
    rotateY = 0.0;
    Regular regular;
    BoundingBox bounding_box;
    TextureBox texture_box;

    load_model("OBJ/skull/12140_Skull_v3_L2.obj", &model, &regular);
    print_model_info(&model);
    calc_bounding_box(&model,&bounding_box);
    calc_texture_box(&model,&texture_box);
    write_to_file("obj_output.obj", &model);
    write_to_file_triangular("triangular_output.obj", &model);
    write_to_file_craw_order("changed_vertex_order_output.obj", &model);
    glutInit(&argc, argv);

	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	int window = glutCreateWindow("GLUT Window");
	glutSetWindow(window);

    initialize();  
 
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouseHandler);
    glutMotionFunc(motionHandler);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
} 
	
