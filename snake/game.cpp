//#include <GL/gl.h>
//#include <GL/glut.h>
#include <time.h>


#include "game.h"

int gridX, gridY;
short sDirection = RIGHT;
extern bool gameOver;
int posX=2,posY=20;

void initGrid(int x, int y){gridX=x;gridY=y;}

void drawGrid(){
  for(int x=0;x<gridX;x++) {
    for(int y=0;y<gridY;y++) {
      unit(x,y);
    }
  }
}

void unit(int x, int y) {
  if (x == 0 || y == 0 || x == gridX-1 || y == gridY-1) {
    glLineWidth(3.0);
    glColor3f(1.0,0.0,0.0);
  } else{glLineWidth(1.0);glColor3f(1.0,1.0,1.0);}

  glColor3f(1.0,1.0,1.0,1.0);

  glBegin(GL_LINE_LOOP);
    glVertex2f(x,y);
    glVertex2f(x+1,y);
    glVertex2f(x+1,y+1);
    glVertex2f(x,y+1);
  
  glEnd();
}

void drawFood() {

}

void drawSnake() {
  if(sDirection==UP)
    posY++;
  else if(sDirection==DOWN)
    posY--;
  else if(sDirection==RIGHT)
    posX++;
  else if(sDirection==LEFT)
    posX--;
  glColor3f(0.0,1.0,0.0);
  glRectd(posX, posY,posX+1, posY+1);
  if(posX==0 || posX == gridX-1 || posY == 0 || posY==gridY-1) {
    gameOver=true;
  }
}
void random(int &x, int &y) {
  int _max = gridX-2;
  int _min = 1;
  srand(time(NULL));
  rand();
}