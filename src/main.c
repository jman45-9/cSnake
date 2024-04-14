#include "../headers/main.h"

int main(int argc, char **argv)
{
        if (argc > 1 && !strcmp(*(argv+1), "--version"))
        {
                printf("Version: %d.%d.%d\n", cSnake_VERSION_MAJOR, cSnake_VERSION_MINOR, cSnake_VERSION_MINOR);
                return 0;
        }

        char testch = '*';

        initscr();

        //screen config
        if(nodelay(stdscr, TRUE) == ERR) {
                printf("FATAL ERR. NO DELAY INIT FAILED. EXITING...");
                endwin();
                return 1;
        }
        noecho();

        // Normal Control Loop
        while (1) {
                addch(testch);
                if (getch() == 'q')
                        break;
                refresh();
        }
        endwin();
        return 0;
}
