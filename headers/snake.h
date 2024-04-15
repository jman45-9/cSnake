#ifndef CSNAKE_SNAKESTRUCT_HEADER_H
#define CSNAKE_SNAKESTRUCT_HEADER_H

#include "../cDynamPointArr/dynamPointArr.h"

struct snake {
        struct dynamPointArr *body;
        struct point head;
};

#endif /* CSNAKE_SNAKESTRUCT_HEADER_H */
