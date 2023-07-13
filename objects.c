/**************************************/
/* objects.c */
/**************************************/

#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

#include "opengl_constants.h"

float generateRandomPosition()
{
  int sign = (rand() % (1 - (-1) + 1) + (-1));
  float value = ((double)rand() / (double)RAND_MAX);

  if (sign < 0)
    value *= -1;

  return value;
}

/**************************************/
/* Cactus */
/**************************************/

void createCactus(int type)
{
  if (type == 1)
  {
    /**************************************/
    /* Cactus One */
    /**************************************/

    glTranslatef(0.0f, -0.5f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(GREEN);

    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.4f);
    glVertex2f(0.2f, 0.4f);

    glColor3f(CACTUS_GREEN);
    glVertex2f(0.2f, 0.0f);

    glEnd();
  }
  else if (type == 2)
  {
    /**************************************/
    /* Cactus Two */
    /**************************************/

    glTranslatef(-0.6f, -0.5f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(GREEN);

    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.2f);
    glVertex2f(0.1f, 0.2f);

    glColor3f(CACTUS_GREEN);
    glVertex2f(0.1f, 0.0f);

    glEnd();
  }
  else if (type == 3)
  {
    /**************************************/
    /* Cactus Three */
    /**************************************/

    glTranslatef(0.8f, -0.5f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(GREEN);

    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.15f);
    glVertex2f(0.05f, 0.15f);

    glColor3f(CACTUS_GREEN);
    glVertex2f(0.05f, 0.0f);

    glEnd();
  }

  glLoadIdentity();
}

/**************************************/
/* Sun */
/**************************************/

void createSun()
{
  glTranslatef(0.4f, 0.6f, 0.0f);
  glBegin(GL_TRIANGLE_FAN);
  glColor3f(SUN_COLOR_ORANGE);
  glVertex2f(0.0f, 0.0f);
  int numSegments = 100;
  GLfloat angle;
  for (int i = 0; i <= numSegments; i++)
  {
    glColor3f(SUN_COLOR_YELLOW);
    angle = i * 2.0f * PI / numSegments;
    glVertex2f(cos(angle) * RADIUS, sin(angle) * RADIUS);
  }
  glEnd();
  glLoadIdentity();
}

/**************************************/
/* Moon */
/**************************************/

void createMoon()
{
  glTranslatef(0.4f, 0.6f, 0.0f);
  glBegin(GL_TRIANGLE_FAN);
  glColor3f(WHITE_3F);
  glVertex2f(0.0f, 0.0f);
  int numSegments = 100;
  GLfloat angle;
  for (int i = 0; i <= numSegments; i++)
  {
    angle = i * 2.0f * PI / numSegments;
    glVertex2f(cos(angle) * RADIUS, sin(angle) * RADIUS);
  }
  glEnd();
  glLoadIdentity();
}

/**************************************/
/* Sky */
/**************************************/

void createSky(float placementVertices[3], int type)
{
  glTranslatef(placementVertices[0], placementVertices[1], placementVertices[2]);
  if (type == 1)
  {
    glBegin(GL_POLYGON);
    glColor3f(CLOUD_COLOR);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.05f);
    glVertex2f(0.1f, 0.05f);
    glVertex2f(0.1f, 0.0f);
    glEnd();
  }
  else if (type == 2)
  {
    glBegin(GL_POLYGON);
    glColor3f(CLOUD_COLOR);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.1f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(0.2f, 0.0f);
    glEnd();
  }
  else if (type == 3)
  {
    glBegin(GL_POLYGON);
    glColor3f(CLOUD_COLOR);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.2f);
    glVertex2f(0.4f, 0.2f);
    glVertex2f(0.4f, 0.0f);
    glEnd();
  }

  glLoadIdentity();
}

/**************************************/
/* Stars */
/**************************************/

void createStars(int total)
{
  if (total > 10)
    total = 10;

  for (int i = 0; i < total / 2; i++)
  {
    glPointSize(4);
    glBegin(GL_POINTS);

    glColor3f(WHITE_3F);

    glVertex2f(generateRandomPosition(), generateRandomPosition());
    glVertex2f(generateRandomPosition(), generateRandomPosition());
    glVertex2f(generateRandomPosition(), generateRandomPosition());
    glVertex2f(generateRandomPosition(), generateRandomPosition());

    glEnd();
  }
}

/**************************************/
/* EOF */
/**************************************/