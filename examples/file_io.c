#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    char buffer[256];
    fd = open("/dev/suidev", O_RDONLY);
    read(fd, buffer, 256);
    printf("%s\n", buffer);
    close(fd);
    return 0;
}