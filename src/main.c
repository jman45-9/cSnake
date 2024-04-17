#include "../headers/main.h"

enum usrKeys {
        DOWN = 258,
        UP = 259,
        LEFT = 260,
        RIGHT = 261,
        QUIT = 'q'
};


int main(int argc, char **argv)
{

        if (argc > 1 && !strcmp(*(argv+1), "--version"))
        {
                printf("Version: %d.%d.%d\n", cSnake_VERSION_MAJOR, cSnake_VERSION_MINOR, cSnake_VERSION_MINOR);
                return 0;
        }


        //ncurses config
        initscr();
        if(nodelay(stdscr, TRUE) == ERR) {
                printf("FATAL ERR. NO DELAY INIT FAILED. EXITING...");
                endwin();
                return 1;
        }
        noecho();
        keypad(stdscr, TRUE);
        curs_set(0);
        
        struct snake *playerSnake = createNewSnake();


        // Normal Control Loop
        while (1) {
                erase();
                makeBorder();
                printSnake(playerSnake);
                switch (getch())
                {
                case DOWN:
                case UP:
                case LEFT:
                case RIGHT:
                        break;

                case QUIT:
                        goto exit_success;
                        
                }

                moveSnake(playerSnake);

                refresh();

                int delayTime = 100; //in milliseconds
                struct timespec ts;
                ts.tv_sec = delayTime / 1000;
                ts.tv_nsec = (delayTime % 1000) * 1000000;
                nanosleep(&ts, NULL);
        }
exit_success:
        delSnake(playerSnake);
        endwin();
        return 0;
}
