/*Code for Program to create processes using fork() and check orphan state in C Programming*/

# include <stdio.h>
int main()
{    
    int pid;
    pid=getpid();
    
    printf("Current Process ID is : %d\n\n",pid);

    printf("[ Forking Child Process ... ] \n\n");    
    pid=fork(); /* This will Create Child Process and
               Returns Child's PID */
    if(pid != 0)
    {
        /* Process Creation Failed ... */
        printf("After Forking, Process Control is now with parent Process ...\n\n");
        printf("Parent Process is going for completing and exiting\n\n");
        exit(-1);
    }
    else 
    {
        	/* Child Process */
		printf("Now in Child Process is Executing ...\n\n");
	        printf("Now Child Process is going for Sleeping ...\n\n");
        	sleep(5);

        	/* 	           Orphan Child's Parent ID is 1                */

	        printf("\nNow Child Process wakes up ...\n\n");
	        printf("\n\nOrphan Child's Parent ID : %d\n\n",getppid());
		exit(0);
     }
	
    return 0;
}


