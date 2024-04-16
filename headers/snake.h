#ifndef CSNAKE_SNAKESTRUCT_HEADER_H
#define CSNAKE_SNAKESTRUCT_HEADER_H

#include <stdlib.h>
#include <ncurses.h>


#define SNAKE_START_LEN 4

struct snake {
        struct dynamPntArr *body;
};

struct snake *createNewSnake();
void printSnake(struct snake *playerSnake);
void delSnake(struct snake *playerSnake);

#endif /* CSNAKE_SNAKESTRUCT_HEADER_H */
