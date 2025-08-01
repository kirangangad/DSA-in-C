
//Binary Search Tree
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
      int info;
      struct node *left,*right;
}NODE;


NODE *createBST(NODE *root)
{
	NODE *newnode,*temp;      
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
                       }//if 
                       else
                       {
                           if(temp->right==NULL)
                          {
                            temp->right=newnode;
                             break;
                           }
                           else
                                temp=temp->right;               
                         }//else
                 }//while
             }//else
       } //for
        return root;
}
void inorder(NODE *root)
{
       NODE *temp;       
	temp=root;
       if(temp!=NULL)
       {
              inorder(temp->left);
              printf("%d\t",temp->info);
		inorder(temp->right);
        } 
}
void preorder(NODE *root)
{
       NODE *temp;       
	temp=root;
       if(temp!=NULL)
       {
	      printf("%d\t",temp->info);              
 	      preorder(temp->left);
             preorder(temp->right);
        } 
}
void postorder(NODE *root)
{
       NODE *temp;       
	temp=root;
       if(temp!=NULL)
       {
              postorder(temp->left);
              postorder(temp->right);
		printf("%d\t",temp->info);
        } 
}


int main()
{
    NODE *root=NULL;
    root=createBST(root);
    printf("Inorder Traversal\n");
    inorder(root);    
    printf("\nPreorder Traversal\n");
    preorder(root);
    printf("\nPostorder Traversal\n");
    postorder(root);
     return 0;
}




