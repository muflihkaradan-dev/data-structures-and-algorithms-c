#include"dll.h"
Node * head=0;
int main(void){
    int op,c;
    while(1){
        printf("1)Add begin 2)Add end 3)Add middle 4)print 5)Search node 6)count node 7)reverse print 8)Read file 9)Save file 10)Delete node 11)Delete all 12)Delete duplicate node 13)Sort node 14)Reverse rec 15)Reverse link 0)Exit\n");
        scanf("%d",&op);
        switch(op){
            case 1:add_begin();break;
            case 2:add_end();break;
            case 3:add_middle();break;
            case 4:print();break;
            case 5:search_node();break;
            case 6:c=count_node();printf("Nodes=%d\n",c);break;
            case 7:reverse_print();break;
            case 8:read_file();break;
            case 9:save_file();break;
            case 10:delete_node();break;
            case 11:delete_all();break;
            case 12:delete_duplicate();break;
            case 13:sort_node();break;
            case 14:reverse_rec(head);break;
            case 15:reverse_link();break;
            case 0:exit(0);
            default:printf("Unknown option\n");
        }
    }
    return 0;
}
void reverse_link(){
    if(head==0)
        return;
    Node*p=head,*temp,*q=0;
    while(p){
        q=p->next;

        temp=p->next;
        p->next=p->prev;
        p->prev=temp;

        if(q==0)
            head=p;
        p=q;
    }
}
void reverse_rec(Node*p){
    if(p){
        if(p->next)
            reverse_rec(p->next);
        printf("%d ",p->data);
        if(p->prev==0)
            printf("\n");
    }
    else
        printf("No node\n");
}
void sort_node(){
    // Address-wise sorting by rearranging node links
    // instead of swapping node data
    if(head==0){
        printf("No node\n");
        return;
    }
    Node*p=head,*temp;
    printf("Address wise sorting(Changing links based on value)\n");
    while(p->next){
        Node* q=p->next;
        while(q){
            if(p->data > q->data){
                if(p->next!=q){
                    temp=p->next;
                    p->next=q->next;
                    q->next=temp;

                    if(p->next)
                        p->next->prev=p;
                    q->next->prev=q;
                }
                else{
                    p->next=q->next;
                    q->next=p;
                    
                    if(p->next)
                        p->next->prev=p;
                }
                if(q->prev!=p){
                    temp=q->prev;
                    q->prev=p->prev;
                    p->prev=temp;

                    p->prev->next=p;
                    if(q->prev)
                        q->prev->next=q;
                }
                else{ 
                    q->prev=p->prev;
                    p->prev=q;
                    if(q->prev)
                        q->prev->next=q;
                }
                if(head==p)
                    head=q;

                //restoring pointer for next iteration
                temp=p;
                p=q;
                q=temp;
            }   
            q=q->next;
        }
        p=p->next;
    }
}
void delete_duplicate(){
    if(head==0){
        printf("No node\n");
    }
    Node*p=head,*temp;int c;
    while(p){
        Node*q=p->next;
        c=1;
        while(q){
            if(p->data == q->data){
                Node*del=q;
                del->prev->next=del->next;
                if(del->next)
                    del->next->prev=del->prev;
                temp=del->next;
                free(del);
                q=temp;
                printf("%d:%dth duplicate deleted\n",p->data,c++);
            }
            else
                q=q->next;
        }
        p=p->next;
    }
}
void delete_all(){
    if(head==0){
        printf("No node\n");
        return;
    }
    int c=0;
    Node*del=head,*temp;
    while(del){
        head=del->next;
        if(del->next)
            del->next->prev=0;
        temp=del->next;
        free(del);
        del=temp;
        printf("Node %d deleted\n",++c);
    }
}
void delete_node(){
    Node*del=head,*temp;
    if(del==0){
        printf("No node present to delete\n");
        return;
    }
    int data,f=0;
    printf("Enter data to delete\n");
    scanf("%d",&data);
    while(del){
        if(del->data==data){
            f=1;
            if(del==head){
                head=del->next;
                if(del->next)
                    del->next->prev=0;
            }
            else {
                if(del->next)
                    del->next->prev=del->prev;
                del->prev->next=del->next;
            }
            printf("%d deleted\n",del->data);
            temp=del->next;
            free(del);
            del=temp;
        }
        else
            del=del->next;
    }
    if(f==0){
        printf("Data not present\n");
    }
}
int count_node(){
    Node*p=head;
    if(p==0){
        return 0;
    }
    int c=0;
    while(p){
        c++;
        p=p->next;
    }
    return c;
}
void search_node(){
    Node*p=head;
    if(p==0){
        printf("No node\n");
        return;
    }
    int data;int f=1;
    printf("Enter the data:");
    scanf("%d",&data);
    while(p){
        if(p->data == data){
            printf("Found\n");
            f=0;
        }
        p=p->next;
    }
    if(f)
        printf("No node present with data\n");
}
void save_file(){
    Node*p=head;
    if(p==0){
        printf("No node\n");
        return;
    }
    FILE *fp=fopen("Node.txt","w");
    if(fp==NULL){
        printf("Unable to open file\n");
        return;
    }
    while(p){
        fprintf(fp,"%d\n",p->data);
        p=p->next;
    }
    fclose(fp);
}
void read_file(){
    FILE *fp=fopen("Node.txt","r");
    if(fp==0){
        printf("File not available\n");
         return;
    }

    Node*new,*prev,*last=head;
    if(head!=0){
        while(last->next)
            last=last->next;
    }
    prev=last;
    while(1){
        new=calloc(1,sizeof(Node));
        if(new==NULL){
            printf("Memory allocation failed\n");
            fclose(fp);
            return;
        }
        if(fscanf(fp,"%d",&new->data)==EOF){
            free(new);
            break;
        }
        if(head==0){
            head=new;
            prev=new;
        }
        else{
            prev->next=new;
            new->prev=prev;
            prev=new;
        }
    }
    fclose(fp); 
}
void add_middle(){
    Node *new;
    new=calloc(1,sizeof(Node));//by default all field(prev,data,next)=0
    if(new==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data:");
    scanf("%d",&new->data);
    if(head==0 || head->data > new->data){
        new->next=head;
        if(head!=0)
            head->prev=new;
        head=new;
        return;
    }
    Node* ptr=head;
    while(ptr->next && ptr->next->data < new->data)
        ptr=ptr->next;
    new->next=ptr->next;
    if(ptr->next!=0)
        ptr->next->prev=new;
    new->prev=ptr;
    ptr->next=new;
}
void add_end(){
    Node *new;
    new=calloc(1,sizeof(Node));//by default all field(prev,data,next)=0
    if(new==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data:");
    scanf("%d",&new->data);
    if(head==0){
        head=new;
        return;
    }
    Node*last=head;
    while(last->next)
        last=last->next;
    new->prev=last;
    last->next=new;
}
void reverse_print(){
    Node*p=head;
    if(p==0){
        printf("No node\n");
        return;
    }
    Node *last=p;
    while(last->next)
        last=last->next;

    while(last){
        printf("%d ",last->data);
        last=last->prev;
    }
    printf("\n");
}
void print(){
    Node *p=head;
    if(p==0){
        printf("No node\n");
        return;
    }
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void add_begin(){
    Node *new;
    new=calloc(1,sizeof(Node));//by default all field(prev,data,next)=0
    if(new==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data:");
    scanf("%d",&new->data);
    if(head==0){
        head=new;
        //new->next=0;//calloc will do this
        //new->prev=0;//calloc will do this
        return;
    }
    new->next=head;
    head->prev=new;
    head=new;
    //new->prev=0;//calloc will do this
}




















