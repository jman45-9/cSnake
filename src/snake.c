#include "../headers/snake.h"

struct snake *createNewSnake()
{
        struct snake *newSnake = malloc(sizeof(struct snake));
        newSnake->bodyArray = malloc(sizeof(struct point));

        newSnake->xVel = 1;
        newSnake->yVel = 0;
        newSnake->bodyLen = 0;

        int UI_min_x = -1; // -1 is magic init
        int UI_min_y = -1;
        calcUImins(&UI_min_x, &UI_min_y);
        struct point start = {(playSpaceWidth/2 + UI_min_x),(playSpaceHeight/2 + UI_min_y)};
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

void moveSnake(struct snake *playerSnake)
{
        for(int iii = 1; iii < playerSnake->bodyLen; iii++) {
                *(playerSnake->bodyArray + (playerSnake->bodyLen-iii)) = *(playerSnake->bodyArray + (playerSnake->bodyLen-iii-1));
        }

        (*(playerSnake->bodyArray)).x += playerSnake->xVel;
        (*(playerSnake->bodyArray)).y += playerSnake->yVel;
}

int checkEdgeCollision(struct snake *playerSnake)
{
        int UI_min_x = -1; // -1 is magic init
        int UI_min_y = -1;
        calcUImins(&UI_min_x, &UI_min_y);
        struct point headPoint = *(playerSnake->bodyArray);
        if (headPoint.x == UI_min_x || headPoint.x == playSpaceWidth + UI_min_x)
                return 1;
        if (headPoint.y == UI_min_y || headPoint.y == playSpaceHeight + UI_min_y)
                return 1;
        return 0;
}

int checkSelfCollision(struct snake *playerSnake)
{
        struct point headPoint = *(playerSnake->bodyArray);

        for (int iii = 1; iii < playerSnake->bodyLen; iii++) {
                if (headPoint.y == (*(playerSnake->bodyArray + iii)).y)
                        if (headPoint.x == (*(playerSnake->bodyArray + iii)).x)
                                        return 1;
        }
        return 0;

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


