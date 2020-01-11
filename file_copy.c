#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define SIZE 1024

int main(int args, char *argv[])
{
    char buf[SIZE];
    int fd, f;
    fd = open("../a.txt", O_RDONLY);

    if (fd < 0) {
        perror("../a.txt");

        exit(1);
    }

    f = open("../b.txt", O_CREAT | O_WRONLY, S_IRWXU);

    while (read(fd, buf, 1) > 0)
        write(f, buf, 1);
    
    close(fd);
    close(f);

    return 0;
}