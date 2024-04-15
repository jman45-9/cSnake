#include "../headers/main.h"

int main(int argc, char **argv)
{
        if (argc > 1 && !strcmp(*(argv+1), "--version"))
        {
                printf("Version: %d.%d.%d\n", cSnake_VERSION_MAJOR, cSnake_VERSION_MINOR, cSnake_VERSION_MINOR);
                return 0;
        }

        initscr();

        //screen config
        if(nodelay(stdscr, FALSE) == ERR) {
                printf("FATAL ERR. NO DELAY INIT FAILED. EXITING...");
                endwin();
                return 1;
        }
        noecho();
        keypad(stdscr, TRUE);

        // Normal Control Loop
        while (1) {
                switch (getch())
                {
                //down arrow pressed
                case 258:
                //up arrow pressed
                case 259:
                //left arrow pressed
                case 260:
                //right arrow pressed
                case 261:
                        break;

                case 'q':
                        goto exit_success;
                        
                }

                refresh();
        }
exit_success:
        endwin();
        return 0;
}
