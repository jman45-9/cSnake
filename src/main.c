#include "main.h"

int main(int argc, char **argv)
{
        if (argc > 1 && !strcmp(*(argv+1), "--version"))
        {
                printf("Version: %d.%d.%d\n", cSnake_VERSION_MAJOR, cSnake_VERSION_MINOR, cSnake_VERSION_MINOR);
                return 0;
        }
        return 0;
}
