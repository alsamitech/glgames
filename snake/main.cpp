#include <GL/gl.h>
#include <GL/glut.h>
#include "game.h"

void display_callback();
void reshape_callback(int, int);

void init() {
  glClearColor(0.0, 0.0, 0.0. 1.0);
}

int main(int argc, char **argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowSize(500, 500);
  glueCreateWindow("Snake");
  glutDisplayFunc(display_callback);
  glutReshapeFunc(reshape_callback);
  init();
  glutMainLoop();
  return 0;
}

void display_callback() {
  glutSwapBuffers();
}

void reshape_callback(int w, int h){
  glViewPort(0,0,(GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();glOrtho(0,0,40.0,0.0,40.0,-1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
}