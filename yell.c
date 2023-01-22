#include "fcntl.h"
#include "unistd.h"
#include "stdio.h"

#define BUFSIZE 2048

int main (int argc, char *argv[]) {

    int input_fd, output_fd = 1, n;
    char buf[BUFSIZE];

    if (argc == 1) {
        // no file specified, use stdin
        input_fd = 0;
        while ((n = read(input_fd, buf, BUFSIZE)) > 0) {
            write(output_fd, buf, n);
        }
    } else {
        for (int i = 1; i < argc; i++) {
            if ((input_fd = open(argv[i], O_RDONLY)) < 0) {
                perror("open");
                return 1;
            }
            while ((n = read(input_fd, buf, BUFSIZE)) > 0) {
                write(output_fd, buf, n);
            }
            close(input_fd);
        }
    }

    if (n < 0) {
        perror("read");
        return 1;
    }

    return 0;
}