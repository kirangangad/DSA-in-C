
//Binary Search Tree
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
      int info;
      struct node *left,*right;
}NODE;
NODE *root,*temp,*newnode;

NODE *createBST(NODE *root)
{
      int n,i;
       printf("Enter no of nodes");
       scanf("%d",&n);
       for(i=0;i<n;i++)
       {
             newnode=(NODE *)malloc(sizeof(NODE));
             printf("Enter data");
	     scanf("%d",&newnode->info);
             newnode->left=newnode->right=NULL;
             if(root==NULL)
		       root=newnode;
             else
             {
                  temp=root;
              while(1)
               {
                 if(newnode->info < temp->info)
                   {
                        if(temp->left==NULL)
                          {
                            temp->left=newnode;
                             break;
                           }
                           else
                                temp=temp->left;
                   }
               else
                    if(temp->right==NULL)
                          {
                            temp->right=newnode;
                             break;
                           }
                    else
                             temp=temp->right;               
}                 }//while
             }//else
       } //for
        return root;
}//create
void inorder(NODE *root)
{
       temp=root;
       if(temp!=NULL)
       {
              inorder(temp->left);
              printf("%d\t",temp->info);
		inorder(temp->right);
        } 
}
int main()

{
    root=NULL;
    root=createBST(root);
    inorder(root);    
     return 0;
}




