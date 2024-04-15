#ifndef DYNAMIC_POINT_ARRAY_HEADER_C
#define DYNAMIC_POINT_ARRAY_HEADER_C

#include <stdio.h>
#include <stdlib.h>

struct point {
        int x;
        int y;
};

struct dynamPntArr {
        struct point *array;
        int len;
};

struct dynamPntArr *create_dynamPntArr();
void pushPoint(struct point pointData, struct dynamPntArr *dynamArray);
struct point popPoint(struct dynamPntArr *dynamArray);
struct point pnt_readIndex(int index, struct dynamPntArr *dynamArray);
void pnt_changeIndex(int index, struct point newPoint, struct dynamPntArr *dynamArray);
void pnt_delDynamArray(struct dynamPntArr *dynamArray);


#endif /* DYNAMIC_POINT_ARRAY_HEADER_C */
