#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    
    /* Declare variables */
    int fd;
    char buffer[256];

    /* Open file descriptor to device file */
    fd = open("/dev/suidev", O_RDONLY);
    
    /* Copy 256 bytes into buffer */
    read(fd, buffer, 256);

    /* Print buffer */
    printf("%s\n", buffer);
    
    close(fd);
    return 0;
}