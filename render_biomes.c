/**************************************/
/* render_biomes.c */
/**************************************/

#include <GL/glut.h>

#include "opengl_constants.h"
#include "objects.h"

GLfloat placementVertices[3];

/**************************************/
/* Utility Functions */
/**************************************/

GLfloat *setPlacementVertices(float vertex1, float vertex2, float vertex3)
{

  placementVertices[0] = vertex1;
  placementVertices[1] = vertex2;
  placementVertices[2] = vertex3;

  return placementVertices;
}

/**************************************/
/* PLAINS */
/**************************************/

void renderPlains(float posX, float posY, float playerColor[3], int day)
{
  if (day)
  {
    glClearColor(SKY_COLOR);
    glClear(GL_COLOR_BUFFER_BIT);

    createSun();
  }
  else if (!day)
  {
    glClearColor(NIGHT_COLOR);
    glClear(GL_COLOR_BUFFER_BIT);

    createStars(8);
    createMoon();
  }

  /**************************************/
  /* Ground */
  /**************************************/

  glBegin(GL_POLYGON);
  glColor3f(BROWN);
  glVertex2f(-1.0f, -1.0f); // TL
  glVertex2f(-1.0f, -0.4f); // TR
  glVertex2f(1.0f, -0.4f);  // BR
  glVertex2f(1.0f, -1.0f);  // BL
  glEnd();

  /**************************************/
  /* Grass */
  /**************************************/

  glBegin(GL_POLYGON);
  glColor3f(GREEN);
  glVertex2f(-1.0f, -0.6f); // TL
  glVertex2f(-1.0f, -0.4f); // TR
  glVertex2f(1.0f, -0.4f);  // BR
  glVertex2f(1.0f, -0.6f);  // BL
  glEnd();

  /**************************************/
  /* Objects */
  /**************************************/

  createSky(setPlacementVertices(-0.8f, 0.6f, 0.0f), 1);
  createSky(setPlacementVertices(-0.4f, 0.4f, 0.0f), 2);
  createSky(setPlacementVertices(-0.4f, 0.4f, 0.0f), 2);
  createSky(setPlacementVertices(0.6f, 0.7f, 0.0f), 3);

  /**************************************/
  /* Player */
  /**************************************/

  glTranslatef(posX, posY, 0.0f);
  glBegin(GL_POLYGON);
  glColor3f(playerColor[0], playerColor[1], playerColor[2]);

  glVertex2f(-0.1f, -0.1f); // TL
  glVertex2f(0.1f, -0.1f);  // TR
  glVertex2f(0.1f, 0.1f);   // BR
  glVertex2f(-0.1f, 0.1f);  // BL

  glEnd();
}

/**************************************/
/* MAZE */
/**************************************/

void renderMaze(float posX, float posY)
{
  /**************************************/
  /* Quadrants */
  /**************************************/

  // First quadrant
  glBegin(GL_POLYGON);
  glColor3f(GREEN);
  glVertex2f(-1.0f, 1.0f); // TL
  glVertex2f(-0.1f, 1.0f); // TR
  glVertex2f(-0.1f, 0.1f); // BR
  glVertex2f(-1.0f, 0.1f); // BL
  glEnd();

  // Second quadrant
  glBegin(GL_POLYGON);
  glColor3f(GREEN);
  glVertex2f(0.1f, 1.0f); // TL
  glVertex2f(1.0f, 1.0f); // TR
  glVertex2f(1.0f, 0.1f); // BR
  glVertex2f(0.1f, 0.1f); // BL
  glEnd();

  // Third quadrant
  glBegin(GL_POLYGON);
  glColor3f(GREEN);
  glVertex2f(-1.0f, -0.1f); // TL
  glVertex2f(-0.1f, -0.1f); // TR
  glVertex2f(-0.1f, -1.0f); // BR
  glVertex2f(-1.0f, -1.0f); // BL
  glEnd();

  // Fourth quadrant
  glBegin(GL_POLYGON);
  glColor3f(GREEN);
  glVertex2f(0.1f, -0.1f); // TL
  glVertex2f(1.0f, -0.1f); // TR
  glVertex2f(1.0f, -1.0f); // BR
  glVertex2f(0.1f, -1.0f); // BL
  glEnd();

  /**************************************/
  /* Player */
  /**************************************/

  glTranslatef(posX, posY, 0.0f);
  glBegin(GL_POLYGON);
  glColor3f(GOLD);

  glVertex2f(-0.1f, -0.1f);
  glVertex2f(0.1f, -0.1f);
  glVertex2f(0.1f, 0.1f);
  glVertex2f(-0.1f, 0.1f);

  glEnd();
}

/**************************************/
/* DESERT */
/**************************************/

void renderDesert(float posX, float posY, float playerColor[3], int day)
{
  if (day)
  {
    glClearColor(SKY_COLOR);
    glClear(GL_COLOR_BUFFER_BIT);

    createSun();
  }
  else if (!day)
  {
    glClearColor(NIGHT_COLOR);
    glClear(GL_COLOR_BUFFER_BIT);

    createStars(8);
    createMoon();
  }

  /**************************************/
  /* Ground */
  /**************************************/

  glBegin(GL_POLYGON);
  glColor3f(SAND_COLOR_YELLOW);
  glVertex2f(-1.0f, -1.0f); // TL
  glVertex2f(-1.0f, -0.4f); // TR
  glVertex2f(1.0f, -0.4f);  // BR
  glVertex2f(1.0f, -1.0f);  // BL
  glEnd();

  /**************************************/
  /* Upper Layer */
  /**************************************/

  glBegin(GL_POLYGON);
  glColor3f(SAND_COLOR_ORANGE);
  glVertex2f(-1.0f, -0.6f); // TL
  glVertex2f(-1.0f, -0.4f); // TR
  glVertex2f(1.0f, -0.4f);  // BR
  glVertex2f(1.0f, -0.6f);  // BL
  glEnd();

  /**************************************/
  /* Objects */
  /**************************************/

  createCactus(1);
  createCactus(2);
  createCactus(3);

  createSky(setPlacementVertices(-0.8f, 0.6f, 0.0f), 1);
  createSky(setPlacementVertices(-0.4f, 0.4f, 0.0f), 2);
  createSky(setPlacementVertices(-0.4f, 0.4f, 0.0f), 2);
  createSky(setPlacementVertices(0.6f, 0.7f, 0.0f), 3);

  /**************************************/
  /* Player */
  /**************************************/

  glTranslatef(posX, posY, 0.0f);
  glBegin(GL_POLYGON);
  glColor3f(playerColor[0], playerColor[1], playerColor[2]);

  glVertex2f(-0.05f, -0.05f); // TL
  glVertex2f(0.05f, -0.05f);  // TR
  glVertex2f(0.05f, 0.05f);   // BR
  glVertex2f(-0.05f, 0.05f);  // BL

  glEnd();
}

/**************************************/
/* EOF */
/**************************************/