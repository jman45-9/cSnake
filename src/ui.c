#include "../headers/ui.h"

void makeBorder()
{
        int UI_min_x = -1; // -1 is magic initilizer
        int UI_min_y = -1;
        calcUImins(&UI_min_x, &UI_min_y);
        char borderChar = '+';
        for (int iii = 0; iii <= playSpaceWidth; iii++) {
                mvaddch(UI_min_y, iii+UI_min_x, borderChar);
                mvaddch(playSpaceHeight+UI_min_y, iii+UI_min_x, borderChar);
        }
        for (int iii = 1; iii <= playSpaceHeight-1; iii++) {
                mvaddch(iii+UI_min_y, UI_min_x, borderChar);
                mvaddch(iii+UI_min_y, playSpaceWidth+UI_min_x, borderChar);
        }
}

void printKillScreen()
{
        int UI_min_x = -1; // -1 is magic init
        int UI_min_y = -1;
        calcUImins(&UI_min_x, &UI_min_y);
        char killMsg[] = "GAME OVER!";
        int killMsgLen = 10;
        int msgPosX = ((playSpaceWidth - killMsgLen)/2) + UI_min_x;
        int msgPosY = ((playSpaceHeight - 1)/2) + UI_min_y;

        makeBorder();
        mvprintw(msgPosY, msgPosX, "%s", killMsg);

        
}

void calcUImins(int *x, int *y)
{
        getmaxyx(stdscr, *y, *x);
        *y = (*y - playSpaceHeight)/2;
        *x = (*x - playSpaceWidth)/2;
}


