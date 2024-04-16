#include "../headers/snake.h"

struct snake *createNewSnake()
{
        struct snake *newSnake = malloc(sizeof(struct snake));
        newSnake->bodyArray = malloc(sizeof(struct point));
        struct point test = {20,20};
        *(newSnake->bodyArray) = test;
        return newSnake;
}

void printSnake(struct snake *playerSnake)
{
}

void delSnake(struct snake *playerSnake)
{
        free(playerSnake->bodyArray);
        free(playerSnake);
}

