#include "../headers/apple.h"

void placeNewApple()
{
        char const appleChar = 'a';
        int UI_min_x = -1; // -1 is magic initializer
        int UI_min_y = -1;
        calcUImins(&UI_min_x, &UI_min_y);
        srand(time(0));
        int xPosMax = UI_min_x + playSpaceWidth;
        int xPosMin = UI_min_x;
        int xPos = (rand() % (xPosMax-xPosMin))+xPosMin+1;

        int yPosMax = UI_min_y +playSpaceHeight;
        int yPosMin = UI_min_y;
        int yPos = (rand() % (yPosMax - yPosMin))+yPosMin+1;
        mvaddch(yPos, xPos, appleChar);
}
