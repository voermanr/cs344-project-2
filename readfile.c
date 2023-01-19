#include "unistd.h"
#include "fcntl.h"
#include "stdio.h"

int main(int argc, char *argv[]) {
    if (argc == 2) {
        char *filename = argv[1];

        int fd = open(filename, O_RDONLY);
        if (fd < 0) {
            perror("Error: Unable to open file\n");
            return 1;
        }

        char data[2048];

        int write_size = read(fd, data, 2048);

        write(1, data, write_size);
        close(fd);

        return 0;
    }
    else return 1;
}