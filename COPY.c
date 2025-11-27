#include <fcntl.h>      // for open
#include <unistd.h>     // for read, write, close
#include <stdio.h>

int main() {
    int source, dest;
    char buffer[1024];
    ssize_t bytes;

    // open source file in read-only mode
    source = open("input.txt", O_RDONLY);
    if (source < 0) {
        perror("Error opening source file");
        return 1;
    }

    // open destination file, create if not exists
    dest = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest < 0) {
        perror("Error opening destination file");
        return 1;
    }

    // read from source and write to destination
    while ((bytes = read(source, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, bytes);
    }

    // close files
    close(source);
    close(dest);

    printf("File copied successfully.\n");
    return 0;
}
