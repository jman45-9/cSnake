#include "../headers/snake.h"

struct snake *createNewSnake()
{
        struct point startVel = {1, 0};
        struct snake *newSnake = malloc(sizeof(struct snake));
        newSnake->bodyArray = malloc(sizeof(struct point));
        newSnake->bodyVel = malloc(sizeof(struct point));
        newSnake->bodyLen = 0;
        struct point start = {20,20};
        *(newSnake->bodyArray) = start;
        *(newSnake->bodyVel) = startVel;
        newSnake->bodyLen++;


        for(int iii = 0; iii < SNAKE_START_LEN - 1; iii++) {
                addSegment(newSnake);
                *(newSnake->bodyVel + (iii+1)) = startVel;
        }
        return newSnake;
}

void addSegment(struct snake *playerSnake)
{
        struct point *storedBody = playerSnake->bodyArray;
        struct point *bodyVel = playerSnake->bodyVel;
        storedBody = realloc(storedBody, sizeof(struct point) * playerSnake->bodyLen+1);
        bodyVel = realloc(bodyVel, sizeof(struct point) * playerSnake->bodyLen+1);
        struct point newPoint = *(storedBody+playerSnake->bodyLen-1);
        newPoint.x--;
        *(storedBody+playerSnake->bodyLen) = newPoint;

        struct point newVel = {0,0};
        *(bodyVel+playerSnake->bodyLen) = newVel;

        playerSnake->bodyLen++;
        playerSnake->bodyArray = storedBody;
        playerSnake->bodyVel = bodyVel;
}

void moveSnake(struct snake *playerSnake)
{
        for(int iii = 1; iii < playerSnake->bodyLen; iii++) {
                *(playerSnake->bodyArray + (playerSnake->bodyLen-iii)) = *(playerSnake->bodyArray + (playerSnake->bodyLen-iii-1));
        }


}


void printSnake(struct snake *playerSnake)
{
        const char snakeBodyChar = '*';
        struct point curPoint;
        for (int iii = 0; iii < playerSnake->bodyLen; iii++) {
                curPoint = *(playerSnake->bodyArray + iii);
                mvaddch(curPoint.y, curPoint.x, snakeBodyChar);
        }
}

void delSnake(struct snake *playerSnake)
{
        free(playerSnake->bodyArray);
        free(playerSnake);
}


