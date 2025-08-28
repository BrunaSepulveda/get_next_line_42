#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int   fd = 0;
    char *line;

    if (argc == 2) {
        fd = open(argv[1], O_RDONLY);
        if (fd < 0) { perror("open"); return 1; }
    }
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    printf("\n");
    if (argc == 2) close(fd);
    return 0;
}
