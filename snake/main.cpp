#include <GL/gl.h>
#include <GL/glut.h>
#include "game.h"

#define COLUMNS 40
#define ROWS 40
#define FPS 10

extern short sDirection;
bool gameOver = false;

void timer_callback();
void display_callback();
void reshape_callback(int, int);
void keyboard_callback(int,int,int);

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
  glutTimerFunc(0,timer_callback,0);
  glutSpecialFUnc(keyboard_callback);
  init();
  glutMainLoop();
  return 0;
}

void display_callback() {
  glClear(GL_COLOR_BUFFER_BIT);
  drawGrid();
  drawSnake();
  glutSwapBuffers();
  if(gameOver){
    //MessageBox(NULL, "Your Score : ", "GAME OVER",0);    use this for windows

    exit(0);
  }
}

void reshape_callback(int w, int h){
  glViewPort(0,0,(GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();glOrtho(0,0,COLUMNS,0.0,ROWS,-1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
}

void timer_callback(int) {
  glutPostRedisplay();
  glutTimerFunc(1000/FPS, timer_callback,0);
}

void keyboard_callback(int key, int, int) {
  switch(key){
    case GLUT_KEY_UP:
    if(sDirection!=DOWN)
      sDirection=UP;
    break;
  case GLUT_KEY_DOWN:
    if(sDirection!=UP)
      sDirection=DOWN;
    break;
  case GLUT_KEY_RIGHT:
    if (sDirection!=LEFT)
      sDirection=RIGHT;
      break;
  case GLUT_KEY_LEFT:
    if(sDirection!=RIGHT)
      sDirection=LEFT;
    break;
  }
}