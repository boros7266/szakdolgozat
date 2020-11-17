#include <stdio.h>
#include "model.h"
#include "timer.h"
#include "texture.h"
#include "bounding_box.h"
#include "texture_box.h"
#include "draw.h"
#include "write_obj.h"
#include "triangulation.h"
#include "craw_order.h"

#include <SOIL/SOIL.h>
#include <GL/glut.h>

double rotateX;
double rotateY;

Model model;


void initialize_texture()
{
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);
	
    char texture_filename[] = "OBJ/cube/cube.png";

    int width;
    int height;

    unsigned char* image = SOIL_load_image(texture_filename, &width, &height, 0, SOIL_LOAD_RGB);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE,
            (Pixel*)image);

	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);

	glEnable(GL_TEXTURE_2D);
}

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
        0.0, 0.0, -6,
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
    Triangle triangle;

    load_model("OBJ/cube/cube.obj", &model, &regular);
    print_model_info(&model);
    calc_bounding_box(&model,&bounding_box);
    calc_texture_box(&model,&texture_box);
    print_bounding_box(&bounding_box);
    print_texture_box(&texture_box);
    write_to_file("obj_output.obj", &model); 
    write_to_file_triangular("triangular_output.obj",&triangle, &model);
    write_to_file_craw_order("craw_order_output.obj",&triangle, &model);
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
	
