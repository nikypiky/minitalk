#include "include/minitalk.h"

void sigusr1(int sig)
{
    (void)sig; // Parameter is unused in this handler
    printf("0\n");
}

void sigusr2(int sig)
{
    (void)sig; // Parameter is unused in this handler
    printf("1\n");
}

int main(void)
{
    write_PID(); // Assuming this writes the process ID to a file

    signal(SIGUSR1, sigusr1); // Register handlers BEFORE the loop
    signal(SIGUSR2, sigusr2);

    while (1)
    {
        pause(); // Wait for signals
    }

    return 0; // good practice to return 0 in main
}
