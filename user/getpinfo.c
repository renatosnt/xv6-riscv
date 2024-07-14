#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/pstat.h"


int main(int argc, char *argv[])
{
    printf("Calling getpinfo...\n");
    settickets(29);

    if (argc != 2)
    {
        fprintf(2, "USAGE: %s <num_rows>\n", argv[0]);
        exit(-1);
    }

    int numRows = atoi(argv[1]);
    int childPIDs[3];


    for (int i = 0; i < 3; i++)
    {
        int pid = fork();
        if (pid < 0) 
        {
            fprintf(2, "Error: fork failed\n");
            exit(-1);
        }
        else if (pid == 0) 
        {
            settickets(10 * (i + 1));
            int b = 0;
            for (int j = 0; j < 9999999990; j++)
            {
                b = 40 * 40 + j;
            }
            printf("%d\n", b);
            exit(0);
        }
        else 
        {
            childPIDs[i] = pid;
        }
    }
    printf("PID\tTICKETS\tTICKS\n");

    for (int row = 0; row < numRows; row++)
    {
        struct pstat ps;
        int result = getpinfo(&ps);
        if (result < 0)
        {
            fprintf(2, "Error: getpinfo failed\n");
            exit(1);
        }
        printf("\n");
        for (int i = 0; i < NPROC; i++)
        {
            if (ps.inuse[i])
            {
                if (ps.tickets[i] % 10 == 0)
                {
                    printf("%d\t%d\t%d\n", ps.pid[i], ps.tickets[i], ps.ticks[i]);
                }
            }
        }

        sleep(100); 
    }

    for (int i = 0; i < 3; i++)
    {
        kill(childPIDs[i]);
    }

    printf("Returning from getpinfo test with status 0!\n");
    exit(0);
}
