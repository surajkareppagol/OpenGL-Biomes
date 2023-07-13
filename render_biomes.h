/**************************************/
/* render_biomes.h */
/**************************************/

#ifndef _RENDER_BIOMES_H_
#define _RENDER_BIOMES_H_

/**************************************/
/* Utility */
/**************************************/

GLfloat *setPlacementVertices(float vertex1, float vertex2, float vertex3);

/**************************************/
/* PLAINS */
/**************************************/

void renderPlains(float posX, float posY, float playerColor[3], int day);

/**************************************/
/* MAZE */
/**************************************/

void renderMaze(float posX, float posY);

/**************************************/
/* DESERT */
/**************************************/

void renderDesert(float posX, float posY, float playerColor[3], int day);

#endif

/**************************************/
/* EOF */
/**************************************/