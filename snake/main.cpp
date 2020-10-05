#include <GL/gl.h>
#include <GL/glut.h>
#include "game.h"

#define COLUMNS 40
#define ROWS 40

void display_callback();
void reshape_callback(int, int);

void init() {
  glClearColor(0.0, 0.0, 0.0. 1.0);
  initgrid(COLUMNS, ROWS);
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
  glClear(GL_COLOR_BUFFER_BIT);
  drawGrid();
  glutSwapBuffers();
}

void reshape_callback(int w, int h){
  glViewPort(0,0,(GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();glOrtho(0,0,COLUMNS,0.0,ROWS,-1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
}