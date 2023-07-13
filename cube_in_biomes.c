/**************************************/
/* cube_in_biomes.c */
/**************************************/

#include <stdio.h>
#include <stdbool.h>
#include <GL/glut.h>
#include <math.h>

#include "opengl_constants.h"
#include "render_biomes.h"

/**************************************/
/* Global Variables */
/**************************************/

GLint windowWidth = 640;
GLint windowHeight = 480;

GLint windowPosX = 50;
GLint windowPosY = 50;

GLfloat cubeOriginalPosX = 0.0f;
GLfloat cubeOriginalPosY = 0.0f;

GLfloat cubePosX = 0.0f;
GLfloat cubePosY = 0.0f;

GLfloat cubeSpeedX = 0.04f;
GLfloat cubeSpeedY = 0.04f;

bool fullScreenMode = true;

GLint biome = 1;

GLfloat playerColor[3];

GLint day = 1;

/**************************************/
/* Utility Functions */
/**************************************/

void setPlayerColor(float color1, float color2, float color3)
{
  playerColor[0] = color1;
  playerColor[1] = color2;
  playerColor[2] = color3;
}

void initGL()
{
  if (biome == 1)
  {
    cubeOriginalPosX = -0.85f;
    cubeOriginalPosY = -0.4f;

    cubePosX = -0.85f;
    cubePosY = -0.4f;

    setPlayerColor(0.8f, 0.498039f, 0.196078f);

    glClearColor(SKY_COLOR);
  }
  else if (biome == 2)
  {
    cubeOriginalPosX = -0.85f;
    cubeOriginalPosY = -0.4f;

    cubePosX = -0.85f;
    cubePosY = -0.4f;

    setPlayerColor(0.1f, 0.67f, 0.71f);

    glClearColor(BLACK);
  }
  else if (biome == 3)
  {
    cubeOriginalPosX = -0.85f;
    cubeOriginalPosY = -0.4f;

    cubePosX = -0.85f;
    cubePosY = -0.4f;
    glClearColor(SKY_COLOR);
  }
}

void up()
{
  cubePosY += cubeSpeedY;
  glutPostRedisplay();
}

void down()
{
  cubePosY -= cubeSpeedY;
  if (cubePosY < cubeOriginalPosY)
    cubePosY = cubeOriginalPosY;
  glutPostRedisplay();
}

void jumpSettleDown()
{
  cubePosY -= cubeSpeedY * 4;
  glutPostRedisplay();
}

void forward()
{
  cubePosX += cubeSpeedX;
  glutPostRedisplay();
}

void backward()
{
  cubePosX -= cubeSpeedX;
  glutPostRedisplay();
}

float randomValueGenerator()
{
  return (double)rand() / (double)RAND_MAX;
}

/**************************************/
/* DISPLAY */
/**************************************/

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  if (biome == 1)
    renderPlains(cubePosX, cubePosY, playerColor, day);
  else if (biome == 2)
    renderMaze(cubePosX, cubePosY);
  else if (biome == 3)
    renderDesert(cubePosX, cubePosY, playerColor, day);

  glutSwapBuffers();
}

/**************************************/
/* KEYBOARD HANDLING */
/**************************************/

void keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 27:
    exit(0);
    break;
  case 32:
    (day == 1) ? (day = 0) : (day = 1);
    glutPostRedisplay();
    break;
  }
}

/**************************************/
/* KEYBOARD SPECIAL KEY HANDLING */
/**************************************/

void specialKeys(int key, int x, int y)
{
  switch (key)
  {
  case GLUT_KEY_RIGHT:
    forward();
    break;
  case GLUT_KEY_LEFT:
    backward();
    break;
  case GLUT_KEY_UP:
    up();
    break;
  case GLUT_KEY_DOWN:
    down();
    break;
  }
}

/**************************************/
/* MOUSE HANDLING */
/**************************************/

void mouse(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
    setPlayerColor(randomValueGenerator(), randomValueGenerator(), randomValueGenerator());
    glutPostRedisplay();
  }
}

/**************************************/
/* RESHAPE */
/**************************************/

void reshape(GLsizei width, GLsizei height)
{
  if (height == 0)
    height = 1;
  GLfloat aspect = (GLfloat)width / (GLfloat)height;

  glViewport(0, 0, width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (width >= height)
  {
    gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
  }
  else
  {
    gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
  }
}

/**************************************/
/* MAIN */
/**************************************/

int main(int argc, char **argv)
{
  printf("Welcome To OpenGL Biomes,\n");
  printf("1.Plains, 2.Maze, 3.Desert,\n\n");
  printf("Choose The Biome: ");
  scanf("%d", &biome);

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE);
  glutInitWindowSize(windowWidth, windowHeight);
  glutInitWindowPosition(windowPosX, windowPosY);
  glutCreateWindow("Cube With Game Controls");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutSpecialFunc(specialKeys);
  glutKeyboardFunc(keyboard);
  glutFullScreen();
  glutMouseFunc(mouse);
  initGL();
  glutMainLoop();

  return 0;
}

/**************************************/
/* EOF */
/**************************************/