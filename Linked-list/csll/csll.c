/*csll.c*/
//Circular Single Linked List

#include"csll.h"
int main(){
    Node *head=0;int op,c=0;
    while(1){
        printf("1)Add begin 2)Add end 3)Print 4)Add middle 5)Count node 6)Save file 7)Read file 8)Reverse print 9)Print rec 10)Reverse rec 11)Delete all 12)Delete node 13)Search node 14)Sort data 15)Reverse links 0)Exit\n");
        scanf("%d",&op);
        switch(op){
            case 1:add_begin(&head);break;
            case 2:add_end(&head);break;
            case 3:print_node(head);break;
            case 4:add_middle(&head);break;
            case 5:c=count_node(head);printf("Node count:%d\n",c);break;
            case 6:save_file(head);break;
            case 7:read_file(&head);break;
            case 8:reverse_print(head);break;
            case 9:print_rec(head);break;
            case 10:reverse_rec(head);break;
            case 11:delete_all(&head);break;
            case 12:delete_node(&head);break;
            case 13:search_node(head);break;
            case 14:sort_data(head);break;
            case 15:reverse_links(&head);break;
            case 0:exit(0);
            default:printf("Unknown option\n");
        }
    }
}
void reverse_links(Node **ptr){
    if(*ptr==0||(*ptr)->next==*ptr)
        return;

    Node *p=*ptr,*q=0,*r=0;
    do{
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }while(p!=*ptr);
    (*ptr)->next=q;
    *ptr=q;
}
void sort_data(Node *ptr){
    if(ptr==0)
        return;
    int c=count_node(ptr);
    Node *p=ptr,*q;
    for(int i=0;i<c-1;i++){
        q=p->next;
        for(int j=0;j<c-1-i;j++){
            if(p->rollno > q->rollno){
                Node t;
                t.rollno=p->rollno;
                strcpy(t.name,p->name);

                p->rollno=q->rollno;
                strcpy(p->name,q->name);

                q->rollno=t.rollno;
                strcpy(q->name,t.name);
            }
            q=q->next;
        }
        p=p->next;
    }
}
void search_node(Node *ptr){
    if(ptr==0){
        printf("No node\n");
        return;
    }
    int rollno,flag=0;
    printf("Enter rollno to search:");
    scanf("%d",&rollno);
    Node *q=ptr;
    do{
        if(q->rollno==rollno){
            flag=1;
            printf("%d %s\n",q->rollno,q->name);
        }
        q=q->next;
    }while(q!=ptr);
    if(!flag)
        printf("No node present with rollno %d\n",rollno);
}
void delete_node(Node **ptr){
    if(*ptr==0){
        printf("No node\n");
        return;
    }
    int rollno;
    printf("Enter rollno to delete:");
    scanf("%d",&rollno);
    Node *del=*ptr,*prev=*ptr,*last=*ptr;
    while(last->next!=*ptr)
        last=last->next;
    do{
        if(del->rollno==rollno){
            if(del==*ptr){
                if(del->next==del)
                    *ptr=0;
                else{
                    *ptr=del->next;
                    last->next=*ptr;
                }
            }
            else{
                prev->next=del->next;
            }
            free(del);
            return;
        }
        prev=del;
        del=del->next;
    }while(del!=*ptr);
    printf("No node present with rollno:%d\n",rollno);
}
void delete_all(Node **ptr){
    if(*ptr==0){
        printf("No node to delete\n");
        return;
    }
    Node *del=*ptr,*last=*ptr;
    while(last->next!=*ptr)
        last=last->next;
    do{
        *ptr=del->next;
        last->next=*ptr;
        free(del);
        del=*ptr;
    }while(del!=*ptr);
    *ptr=0;
}
void reverse_rec(Node *ptr){
    if(ptr==0){
        printf("No node\n");
        return;
    }
    static Node*q=0;Node *p=0;
    if(ptr!=q){
        if(q==0)
            q=ptr;
        p=q;
        q=q->next;
        reverse_rec(ptr);
        printf("%d %s\n",p->rollno,p->name);
    }
    else
        q=0;
}
void print_rec(Node *ptr){
    if(ptr==0){
        printf("No node\n");
        return;
    }
    static Node*q=0;
    if(ptr!=q){
        if(q==0)
            q=ptr;
        printf("%d %s\n",q->rollno,q->name);
        q=q->next;
        print_rec(ptr);
    }
    else
        q=0;
}
void reverse_print(Node * ptr){
    if(ptr==0){
        printf("No node\n");
        return;
    }
    int c=count_node(ptr);
    Node *q=ptr;
    for(int i=0;i<c;i++){
        q=ptr;
        for(int j=0;j<c-1-i;j++){
            q=q->next;
        }
        printf("%d %s\n",q->rollno,q->name);
    }
}
void read_file(Node **ptr){
    FILE *fp=fopen("Node.txt","r");
    if(fp==0){
        printf("File not available\n");
        return;
    }
    Node *new;
    while(1){
        new=malloc(sizeof(Node));
        if(fscanf(fp,"%d %s",&new->rollno,new->name)==EOF){
            free(new);
            break;
        }
        if(*ptr==0){
            *ptr=new;
            new->next=new;
        }
        else{
            Node*last=*ptr;
            while(last->next!=*ptr)
                last=last->next;
            last->next=new;
            new->next=*ptr;
        }
    }
    fclose(fp);
}
void save_file(Node *ptr){
    if(ptr==0){
        printf("No node\n");
        return;
    }
    FILE *fp=fopen("Node.txt","w");
    Node *q=ptr;
    do{
        fprintf(fp,"%d %s\n",q->rollno,q->name);
        q=q->next;
    }while(q!=ptr);
    fclose(fp);
}
int count_node(Node *ptr){
    int c=0;
    if(ptr==0)
        return 0;
    Node *q=ptr;
    do{
        c++;
        ptr=ptr->next;
    }while(ptr!=q);

    return c;
}
void add_middle(Node **ptr){
    Node*new=malloc(sizeof(Node));
    printf("Enter the rollno and name:");
    scanf("%d%s",&new->rollno,new->name);
    if(*ptr==0){
        *ptr=new;
        new->next=new;
    }
    else{ 
        Node *last=*ptr;
        while(last->next!=*ptr)
            last=last->next;
        if((*ptr)->rollno > new->rollno){
            new->next=*ptr;
            *ptr=new;
            last->next=new;
        }
        else{
        Node *node=*ptr;
        while(node->next!=*ptr && node->next->rollno < new->rollno)
            node=node->next;
        new->next=node->next;
        node->next=new;
        }
    }
}
void add_begin(Node **ptr){
    Node*new=malloc(sizeof(Node));
    printf("Enter the rollno and name:");
    scanf("%d%s",&new->rollno,new->name);
    if(*ptr==0){
        *ptr=new;
        new->next=new;
    }
    else{
        Node*last=*ptr;
        while(last->next!=*ptr)
            last=last->next;
        new->next=*ptr;
        *ptr=new;
        last->next=new;
    }

}
void add_end(Node **ptr){
    Node*new=malloc(sizeof(Node));
    printf("Enter the rollno and name:");
    scanf("%d%s",&new->rollno,new->name);
    if(*ptr==0){
      *ptr=new;
      new->next=new;
    }
    else{
        Node*last=*ptr;
        while(last->next!=*ptr)
            last=last->next;
        new->next=*ptr;
        last->next=new;
    }
}
void print_node(Node* ptr){
    if(ptr==0){
        printf("No node\n");
        return;
    }
    Node *q=ptr;
    do{
        printf("%d %s\n",ptr->rollno,ptr->name);
        ptr=ptr->next;
    }while(ptr!=q);
}

