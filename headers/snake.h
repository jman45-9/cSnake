#ifndef CSNAKE_SNAKESTRUCT_HEADER_H
#define CSNAKE_SNAKESTRUCT_HEADER_H

#include <stdlib.h>
#include <ncurses.h>

#include "../consts.h"

#define SNAKE_START_LEN 4

struct point {
        int x;
        int y;
};

struct snake {
        struct point *bodyArray;
        int bodyLen;
        int xVel;
        int yVel;
};

struct snake *createNewSnake();
void addSegment(struct snake *playerSnake);
void moveSnake(struct snake *playerSnake);
int checkEdgeCollision(struct snake *playerSnake);
void printSnake(struct snake *playerSnake);
void delSnake(struct snake *playerSnake);

#endif /* CSNAKE_SNAKESTRUCT_HEADER_H */
