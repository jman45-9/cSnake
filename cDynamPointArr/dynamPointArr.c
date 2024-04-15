#include "dynamPointArr.h"

struct dynamPntArr *create_dynamPntArr()
{
        struct dynamPntArr *newArr = malloc(sizeof(struct dynamPntArr));
        newArr->array = NULL;
        newArr->len = 0;
        return newArr;
}

void pushPoint(struct point pointData, struct dynamPntArr *dynamArray)
{
        dynamArray->array = realloc(dynamArray->array,sizeof(sizeof(struct point) * (dynamArray->len + 1)));
        struct point *storedArray = dynamArray->array;
        *(storedArray+dynamArray->len) = pointData;
        dynamArray->len += 1;
}

struct point popPoint(struct dynamPntArr *dynamArray)
{
        struct point *array = dynamArray->array;
        dynamArray->len -= 1;
        struct point value = *(array+dynamArray->len);
        dynamArray->array = realloc(dynamArray->array, sizeof(struct point) * dynamArray->len);
        return value;
}

struct point pnt_readIndex(int index, struct dynamPntArr *dynamArray)
{
        struct point *array = dynamArray->array;
        return *(array+index);
}

void pnt_changeIndex(int index, struct point newPoint, struct dynamPntArr *dynamArray)
{
        struct point *array = dynamArray->array;
        *(array+index) = newPoint;
        dynamArray->array = array;
}

void pnt_delDynamArray(struct dynamPntArr *dynamArray)
{
        if (dynamArray->array != NULL)
                free(dynamArray->array);
        free(dynamArray);
}

