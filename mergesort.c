//merge sort
#include<stdio.h>
void merge(int a[],int low,int mid, int high)
{                                            
	 int b[20],i,j,k;                
        i=low;     //left half         
        j=mid+1;   //right half        
	 k=0;                           
        while(i<=mid && j<=high)        
	{
		if(a[i] <= a[j])
                     {
      			    b[k]=a[i];
                         k++;
                         i++;
                     }
                else
         		b[k++]=a[j++];
	}
	while(i<=mid)
		b[k++]=a[i++];
	while(j<=high)
		b[k++]=a[j++];
        for(i=low,k=0;i<=high;i++,k++)    //copy array b to a
		a[i]=b[k];
}//merge
void merge_sort(int a[],int low,int high)
{
     int mid;                         
     if(low<high)                     
     {
           mid=(low+high)/2;
           merge_sort(a,low,mid);   //left partition
	    merge_sort(a,mid+1,high);  //right partition
           merge(a,low,mid,high);
     }                                    	
}
int main()
{
	int a[20],i,n;
	printf("\nEnter number of elements");
	scanf("%d",&n);
	printf("\nEnter array elements");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	merge_sort(a,0,n-1);
	printf("\nsorted array is....\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	return 0;
}//main


