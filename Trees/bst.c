#include"bst.h"
BST* parent=0;

int main(){
    int op,num;BST *root=0,*ptr;
    while(1){
        printf("1.Insert 2.preorder 3.inorder 4.postorder 5.Search 6.Delete 7.Exit\n");
        scanf("%d",&op);
        switch(op){
            case 1:printf("Enter a num to add:");
                   scanf("%d",&num);
                   insertNode(&root,num);break;
            case 2:preorder(root);printf("\n");break;
            case 3:inorder(root);printf("\n");break;
            case 4:postorder(root);printf("\n");break;
            case 5:printf("Enter num for search:");
                   scanf("%d",&num);
                   ptr=searchNode(root,num);
                   if(ptr)
                       printf("Found\n");
                   else
                       printf("Not found\n");
                   break;
            case 6:printf("Enter num for delete:");
                   scanf("%d",&num);
                   deleteNode(&root,num);break;
            case 7:exit(0);
            default:printf("Unknown option\n");
        }
    }
    return 0;
}
void deleteNode(BST **ptr,int n){
    if(*ptr==0){
        printf("No node\n");
        return;
    }
    parent=0;
    BST *del=searchNode(*ptr,n);
    if(del){
        //deleting root node
        if(parent==NULL){
            if(del->left==0 && del->right==0 ){//root has no child
                *ptr=0;
                free(del);
                return;
            }
            else if(del->left!=0 && del->right==0){//root has one child(left)
                *ptr=del->left;
                free(del);
                return;

            }
            else if(del->left==0 && del->right!=0){//root has one child(right)
                *ptr=del->right;
                free(del);
                return;
            }
            else if(del->left && del->right){
                BST* min;
                min=del->right;
                parent=del;
                while(min->left){
                    parent=min;
                    min=min->left;
                }
                del->num=min->num;
                del=min;
                if(del->left==0 && del->right==0){
                    if(parent->left==del)
                        parent->left=0;
                    else if(parent->right==del)
                        parent->right=0;
                    free(del);
                    return;
                }
                //deleting a node having one chile(right)
                else if(del->left==0 && del->right!=0){
                    if(parent->left==del)
                        parent->left=del->right;
                    else if(parent->right==del)
                        parent->right=del->right;
                    free(del);
                    return;
                }
                //deleting a node having one chile(left)
                else if(del->left!=0 && del->right==0){
                    if(parent->left==del)
                        parent->left=del->left;
                    else if(parent->right==del)
                        parent->right=del->left;
                    free(del);
                    return;
                }
            }
        }
        //Deleting leaf node
        if(del->left==0 && del->right==0){
            if(parent->left==del)
                parent->left=0;
            else if(parent->right==del)
                parent->right=0;
            free(del);
            return;
        }
        //deleting a node having one chile(left)
        else if(del->left!=0 && del->right==0){
            if(parent->left==del)
                parent->left=del->left;
            else if(parent->right==del)
                parent->right=del->left;
            free(del);
            return;
        }
        //deleting a node having one chile(right)
        else if(del->left==0 && del->right!=0){
            if(parent->left==del)
                parent->left=del->right;
            else if(parent->right==del)
                parent->right=del->right;
            free(del);
            return;
        }
        //Deleting node having two childs
        else if(del->left && del->right){
            BST* min;
            min=del->right;
            parent=del;
            while(min->left){
                parent=min;
                min=min->left;
            }
            del->num=min->num;
            del=min;
            //Node having no child
            if(del->left==0 && del->right==0){
                if(parent->left==del)
                    parent->left=0;
                else if(parent->right==del)
                    parent->right=0;
                free(del);
                return;
            }
            //deleting a node having one chile(right)
            else if(del->left==0 && del->right!=0){
                if(parent->left==del)
                    parent->left=del->right;
                else if(parent->right==del)
                    parent->right=del->right;
                free(del);
                return;
            }
        }
    }
    else
        printf("Num not present\n");
}
BST* searchNode(BST *ptr,int n){
    if(ptr){
        if(n==ptr->num){
            return ptr;
        }
        else if(n < ptr->num){
            parent=ptr;
            return searchNode(ptr->left,n);
        }
        else if(n > ptr->num){
            parent=ptr;
            return searchNode(ptr->right,n);
        }
    }
    else 
        return 0;
}
void insertNode(BST **ptr,int n){
    if(*ptr==0){
        *ptr=calloc(1,sizeof(BST));
        (*ptr)->num=n;
    }
    else if(n < (*ptr)->num){
        insertNode(&((*ptr)->left),n);
    }
    else if(n > (*ptr)->num){
        insertNode(&((*ptr)->right),n);
    }
}
void preorder(BST *ptr){
    if(ptr){
        printf("%d ",ptr->num);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
void inorder(BST *ptr){
    if(ptr){
        inorder(ptr->left);
        printf("%d ",ptr->num);
        inorder(ptr->right);
    }
}
void postorder(BST *ptr){
    if(ptr){
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ",ptr->num);
    }
}
