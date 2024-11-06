 #include<stdio.h>
int main(int argc, char* argv[])
{

	int a[10],i,m,c=0,l,u,mid;
    	printf("\n\nEnter the number to be searched  :  ");
    	scanf("%d",&m);
	for(i=0;i<argc;i++)
	{
		a[i]=atoi(argv[i]);
	}
       	l=0,u=i-1;
    	while(l<=u)
	{
        	mid=(l+u)/2;
        	if(m==a[mid])
		{
             		c=1;
             		break;
         	}
         	else if(m<a[mid])
	 	{
         		u=mid-1;
         	}
         	else
	 	{
             		l=mid+1;
	 	}
    	}
    	if(c==0)
        	printf("\n\nThe number is not found.");
    	else
         	printf("\n\nThe number is found.");

	return 0;
}
