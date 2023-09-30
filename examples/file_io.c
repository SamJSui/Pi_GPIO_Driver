#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    
    /* Declare variables */
    int fd;
    char on_state;

    /* Open file descriptor to device file */
    fd = open("/dev/sui_gpio", O_WRONLY);
    
    /* Copy on value into buffer */
    on_state = '1';
    write(fd, &on_state, sizeof(on_state));
    
    close(fd);
    return 0;
}