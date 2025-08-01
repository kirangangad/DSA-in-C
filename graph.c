#include<stdio.h>
void createmat(int m[10][10], int n)
{
    int i,j;
    for(j=0;j<n;j++)
    {
        m[i][j]=0;
        if(i !=j)
        {
            printf("\nIs their edge between %d and %d(1/0)",i+1,j+1);
            scanf("%d",&m[i][j]);
        
            }
    }
}
void dispmat(int m[10][10],int n)
{
    int i,j;
    printf("\nAdjacency matrix is.......\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\t%d",m[i][j]);
        }
        printf("\n");
}

}
void countdegree(int m[10][10],int n)
{
     int i,j;
     int rowsum,colsum;
     printf("\n vertex\t Indegree\t outdegree \t totoal degree\n ");
     for(i=0;i<n;i++)
     {
        rowsum=0;
        colsum=0;

        for(j=0;j<n;j++)
        {
            rowsum=rowsum+m[i][j];
            colsum=colsum+m[j][i];
        }
        printf("\nv%d\t\t&d\t%d\t%d\n",i+1,colsum,rowsum,rowsum+colsum);
     }
}
int main()
{
     int m[10][10],n;
     printf("Enter number of vertices ") ;
     scanf("%d",&n);
     createmat (m,n);
     countdegree(m,n);
     return 0;

}