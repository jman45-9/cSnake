#include "../headers/snake.h"

struct snake *createNewSnake()
{
        struct snake *newSnake = malloc(sizeof(struct snake));
        newSnake->bodyArray = malloc(sizeof(struct point));
        struct point start = {20,20};
        *(newSnake->bodyArray) = start;
        newSnake->bodyLen++;

        for(int iii = 0; iii < SNAKE_START_LEN - 1; iii++) {
                addSegment(newSnake);
        }
        return newSnake;
}

void addSegment(struct snake *playerSnake)
{
        struct point *storedBody = playerSnake->bodyArray;
        storedBody = realloc(storedBody, sizeof(struct point) * playerSnake->bodyLen+1);
        struct point newPoint = *(storedBody+playerSnake->bodyLen-1);
        newPoint.x--;
        *(storedBody+playerSnake->bodyLen) = newPoint;
        playerSnake->bodyLen++;
        playerSnake->bodyArray = storedBody;
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

