#include "../headers/ui.h"

void makeBorder()
{
        char borderChar = '+';
        for (int iii = 0; iii <= playSpaceWidth; iii++) {
                mvaddch(0, iii, borderChar);
                mvaddch(playSpaceHeight, iii, borderChar);
        }
        for (int iii = 1; iii <= playSpaceHeight-1; iii++) {
                mvaddch(iii, 0, borderChar);
                mvaddch(iii, playSpaceWidth, borderChar);
        }
}

void printKillScreen()
{
        char killMsg[] = "GAME OVER!";
        int killMsgLen = 10;
        int msgPosX = (playSpaceWidth - killMsgLen)/2;
        int msgPosY = (playSpaceHeight - 1)/2;

        makeBorder();
        mvprintw(msgPosY, msgPosX, "%s", killMsg);

        
}

void calcUImins(int *x, int *y)
{
        getmaxyx(stdscr, *y, *x);
        *y = (*y - playSpaceHeight)/2;
        *x = (*x - playSpaceWidth)/2;
}


