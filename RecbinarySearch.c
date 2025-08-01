  //binary search
#include<stdio.h>  
int search(int a[], int top,int bottom,int key)
{          
        int mid;
         if(top<=bottom)
         {
		mid=(top+bottom)/2;
              if(a[mid]==key)
			return mid;
		else
              	if(key < a[mid])
				return search(a,top,mid-1,key);
			else
				return search(a,mid+1,bottom,key);
                     
	 }
	return -1;
}
int main()
{
	int a[20],i,n,key,ans;
	printf("\nEnter number of elements");
	scanf("%d",&n);
	printf("\nEnter sorted array elements");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter key to search");
	scanf("%d",&key);
	ans=search(a,0,n-1,key);  //function call
	if(ans==-1)
		printf("\nelement does not exist");
	else
		printf("\nElement is present at %d position",ans);

	return 0;
}//main

       

   














      
              




  
