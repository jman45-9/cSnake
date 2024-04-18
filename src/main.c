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

        refresh();
        getch();


        // Normal Control Loop
        while (1) {
                erase();
                makeBorder();
                printSnake(playerSnake);
                switch (getch())
                {
                case DOWN:
                        if (playerSnake->yVel == -1)
                                break;
                        playerSnake->xVel = 0;
                        playerSnake->yVel = 1;
                        break;
                case UP:
                        if (playerSnake->yVel == 1)
                                break;
                        playerSnake->xVel = 0;
                        playerSnake->yVel = -1;
                        break;
                case LEFT:
                        if (playerSnake->xVel == 1)
                                break;
                        playerSnake->xVel = -1;
                        playerSnake->yVel = 0;
                        break;
                case RIGHT:
                        if (playerSnake->xVel == -1)
                                break;
                        playerSnake->xVel= 1;
                        playerSnake->yVel = 0;
                        break;

                case QUIT:
                        goto exit_success;
                        
                }

                moveSnake(playerSnake);
                if (checkEdgeCollision(playerSnake))
                        goto game_over;

                refresh();

                int delayTime = 100; //in milliseconds
                struct timespec ts;
                ts.tv_sec = delayTime / 1000;
                ts.tv_nsec = (delayTime % 1000) * 1000000;
                nanosleep(&ts, NULL);
        }
game_over:
        printKillScreen();
        refresh();
        while(1) {
                if (getch() != -1)
                        break;
        }


exit_success:
        delSnake(playerSnake);
        endwin();
        return 0;
}
