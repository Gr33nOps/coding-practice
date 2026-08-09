/*
// System Call
#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();
    if (pid == 0) {
        printf("I am the child process\n");
    }
    else if (pid > 0) {
        printf("I am the parent process\n");
    }
    else {
        printf("Fork failed\n");
    }
    return 0;
}
*/

// Fork Call System Call
/*#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t p;
    printf("Before fork\n");

    p = fork();

    if (p == 0) {
        // Child process code
        printf("Child Process: I am child having id %d\n", getpid());
        printf("Child Process: My parent's id is %d\n", getppid());
    }
    else {
        // Parent process code
        printf("Parent Process: My child's id is %d\n", p);
        printf("Parent Process: I am parent having id %d\n", getpid());
    }

    printf("Outside\n");
    return 0;
}
*/

// The wait system call
/*#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t p, q;
    printf("Before Fork\n");

    p = fork();  // First fork
    if (p == 0) {
        printf("First Child Process I am Child having id %d\n", getpid());
        printf("First Child Process My Parent's id is %d\n", getppid());
    }
    else {
        q = fork();  // Second fork (only parent executes this)
        if (q == 0) {
            printf("Second Child Process I am Child having id %d\n", getpid());
            printf("Second Child Process My Parent's id is %d\n", getppid());
        }
        else {
            wait(NULL);  // Wait for first child to finish
            printf("Parent Process My First Child's id is %d\n", p);
            printf("Parent Process My Second Child's id is %d\n", q);
            printf("Parent Process I am a Parent having id %d\n", getpid());
        }
    }

    printf("Outside\n");
    return 0;
}
*/
// Orpghan process
/*
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t p;

    p = fork();

    if (p == 0) {
        // Child process
        sleep(5);  // Child sleeps and in the mean time parent terminates
        printf("Child Process: I am child having id %d\n", getpid());
        printf("Child Process: My parent's id is %d\n", getppid());
    }
    else {
        // Parent process
        printf("Parent Process: My child's id is %d\n", p);
        printf("Parent Process: I am parent having id %d\n", getpid());
    }

    return 0;
}
*/

// Zombie process
/*
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t p, q;

    p = fork();

    if (p == 0) {
        // Child process
        printf("Child Process: I am Child having id %d\n", getpid());
        printf("Child Process: My Parent's id is %d\n", getppid());
    }
    else {
        // Parent process
        sleep(3);  // Parent sleeps. Run the ps command during this time
        printf("Parent Process: My Child's id is %d\n", p);
        printf("Parent Process: I am a Parent having id %d\n", getpid());
    }

    return 0;
}
*/

/*
* Zombie process prevention
#include <unistd.h>
int execl(const char* path, const char* arg0, ..., NULL);

#include <stdlib.h>
int system(const char* command);
**/