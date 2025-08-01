//improved bubble sort
#include<stdio.h>
#include<stdlib.h>
void bubble_sort(int a[],int n)
{
	int pass,i,temp,swapcount,count=0;
	for(pass=1;pass<n;pass++)
	{
              count=0;		
		swapcount=0;		
		for(i=0;i<n-pass;i++)
		{
                     count++;
			if(a[i] > a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
				swapcount=1;
			}
            	}
              printf("\ncomparison :  %d  pass: %d", count,pass);
           if(swapcount==0)    //array is already sorted
			break;
	}
}
int main()
{
	int a[20],i,n;
	printf("\nEnter number of elements");
	scanf("%d",&n);
	//printf("\nEnter array elements");
	for(i=0;i<n;i++)
		//a[i]=rand()%100; //to generate numbers
		scanf("%d",&a[i]);
      printf("\nunsorted array is....\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	bubble_sort(a,n);
	printf("\nsorted array is....\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	return 0;
}//main


/*
4  pass 1
2   2    pass 2
5   4    2   pass 3
1   1    1    1    
    5    4    2    
         5    4    
              5   
   3    2     1
   no of comparisons
*/ 

			
  



				



















