/*Code for Program to create processes using fork() and check orphan state in C Programming*/

# include <stdio.h>
int main()
{    
    int pid;

    pid=getpid();
    
    printf("\n\nCurrent Process ID is : %d\n\n",pid);

    printf("[ Forking Child Process ... ] \n\n");    
    pid=fork(); /* This will Create Child Process and
               Returns Child's PID */
    if(pid != 0)
    {
        /* Process Creation Failed ... */
        printf("After Forking, Process Control is now with parent Process ...\n\n");
	 
        printf("Now the Parent Process Running ... \n");
	printf("Now parent Process is going for Sleeping ..\n\n");	
	sleep(10);
	printf("\n\nNow parent Process Wakes up ..\n\n");	
        printf("\n\nNow the Parent Process is in Zombie State ...\n\n");
        while(1)
        {
            /* 
                Infinite Loop that Keeps the
                   Process Running
            */

        }
        printf("Parent Process is going for completing and exiting\n\n");
        exit(-1);
    }
    else 
    {
        	/* Child Process */
		printf("Now in Child Process is Executing ...\n\n");
	        printf("\n\nThe Child's Parent ID : %d\n\n",getppid());
		 printf("Child Process Completed and Exiting...\n\n");
		exit(0);
     }
	
    return 0;
}


