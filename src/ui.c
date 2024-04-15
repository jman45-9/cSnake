#include "../headers/ui.h"

void makeBorder()
{
        char borderChar = '+';
        for (int iii = 0; iii <= 80; iii++) {
                mvaddch(0, iii, borderChar);
                mvaddch(24, iii, borderChar);
        }
        for (int iii = 1; iii <= 23; iii++) {
                mvaddch(iii, 0, borderChar);
                mvaddch(iii, 80, borderChar);
        }
}

