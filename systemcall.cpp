#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
using namespace std;

int main() {

    int fd = open("demo.txt", O_CREAT | O_WRONLY, 0644);          // open file
    write(fd, "Hi System Calls\n", 16);                            // write
    close(fd);                                                    // close

    fd = open("demo.txt", O_RDONLY);                              // open again for read
    char buf[50];
    int n = read(fd, buf, sizeof(buf));                           // read
    buf[n] = '\0';
    close(fd);

    int pid = fork();                                             // create process
    if(pid == 0) {
        write(1, buf, n);                                         // child prints file content
    } else {
        wait(NULL);                                               // parent waits
        write(1, "\nDone\n", 6);                                  // parent message
    }

    return 0;
}
