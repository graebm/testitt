#include <stdio.h>
#include "mylib.h"

int main(int argc, const char **argv)
{
    (void)argc;
    (void)argv;
    mylib_init();

    mylib_do_work("adsf");

    mylib_deinit();
    printf("DONE\n");
    return 0;
}
