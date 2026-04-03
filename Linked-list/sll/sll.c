#include<stdio.h>
#include"sll.h"
int main(){
    Node *head=0;int op,c;
    while(1){
        printf("1.add begin\n2.add end\n3.add middle\n4.print node\n5.count node\n6.save file\n7.read file\n8.reverse print\n9.print rec\n10.reverse rec\n11.delete all\n12.delete node\n13.search node\n14.sort data\n15.reverse links\n16.exit\n");
        scanf("%d",&op);
        switch(op){
            case 1:add_begin(&head);break;
            case 2:add_end(&head);break;
            case 3:add_mid(&head);break;
            case 4:print_node(head);break;
            case 5:c=count_node(head);
                   printf("Node count=%d\n",c);
                   break;
            case 6:save_file(head);break;
            case 7:read_file(&head);break;
            case 8:rev_print(head);break;
            case 9:print_rec(head);break;
            case 10:reverse_rec(head);break;
            case 11:delete_all(&head);break;
            case 12:delete_node(&head);break;
            case 13:search_node(head);break;
            case 14:sort_data(head);break;
            case 15:reverse_link(&head);break;
            case 16:exit(0);
            default:printf("Wrong Option\n");
        }
    }
}
void sort_data(Node *ptr){
    if(ptr==0){
        printf("No node to sort\n");
        return;
    }
    int c=count_node(ptr);
    Node*p1=ptr,*p2;
    for(int i=0;i<c-1;i++){
        p2=p1->next;
        for(int j=0;j<c-1-i;j++){
            if(p1->rollno>p2->rollno){
                Node t;
                t.rollno=p1->rollno;
                strcpy(t.name,p1->name);
                t.marks=p1->marks;

                p1->rollno=p2->rollno;
                strcpy(p1->name,p2->name);
                p1->marks=p2->marks;


                p2->rollno=t.rollno;
                strcpy(p2->name,t.name);
                p2->marks=t.marks;
            }
            p2=p2->next;
        }
        p1=p1->next;
    }
    printf("Sorted successfully\n");
}
void reverse_link(Node**ptr){
    if(*ptr==0){
        printf("No node\n");
        return;
    }
    Node *p=*ptr,*q=0,*r=0;
    while(p){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    *ptr=q;
    printf("node link reversed successfully\n");
}
void search_node(Node *ptr){
    if(ptr==0){
        printf("No node present\n");
        return;
    }
    int rollno;
    printf("Enter rollno to search:");
    scanf("%d",&rollno);
    int f=0;
    while(ptr){
        if(ptr->rollno==rollno){
            f=1;
            printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
        }
        ptr=ptr->next;
    }
    if(f==0)
        printf("No rollno found\n");
}
void delete_node(Node **ptr){
    if(*ptr==0){
        printf("No node present\n");
        return;
    }
    int rollno;
    printf("Enter rollno to delete:");
    scanf("%d",&rollno);
    Node*del=*ptr,*t=0;
    while(del){
        if(del->rollno==rollno){
            if(del==*ptr)
                *ptr=del->next;
            else
                t->next=del->next;
            free(del);
            printf("rollno:%d info deleted\n",rollno);
            return;
        }
        t=del;
        del=del->next;
    }
    printf("Node not present\n");
}
void delete_all(Node **ptr){
    if(*ptr==0){
        printf("No node to delete\n");
        return;
    }
    Node *del=*ptr;
    int c=1;
    while(del){
        *ptr=del->next;
        free(del);
        del=*ptr;
        printf("%d node deleted\n",c++);
    }
    printf("All nodes deleted\n");
}
void reverse_rec(Node*ptr){
    if(ptr!=0){
        if(ptr->next!=0)
            reverse_rec(ptr->next);
        printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
    }
    else
        printf("No node\n");
}
void print_rec(Node*ptr){
    if(ptr!=0){
        printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
        if(ptr->next!=0)
            print_rec(ptr->next);
    }
    else
        printf("No node\n");
}
void rev_print(Node*ptr){
    if(ptr==0){
        printf("No node\n");
        return;
    }
    int c=count_node(ptr);
    Node*temp;
    for(int i=0;i<c;i++){
        temp=ptr;
        for(int j=0;j<c-1-i;j++){
            temp=temp->next;
        }
        printf("%d %s %f\n",temp->rollno,temp->name,temp->marks);
    }
}
void read_file(Node **ptr){
    FILE *fp=fopen("students.txt","r");
    if(fp==0){
        printf("file not available\n");
        return;
    }
    Node*last,*new;
    while(1){
        new=malloc(sizeof(Node));
        if(fscanf(fp,"%d%s%f",&new->rollno,new->name,&new->marks)==EOF){
            free(new);
            break;
        }
        new->next=0;
        if(*ptr==0){
            *ptr=new;
        }
        else{
            last=*ptr;
            while(last->next)
                last=last->next;
            last->next=new;
        }
    }
    fclose(fp);
}
void save_file(Node *ptr){
    if(ptr==0){
        printf("No node\n");
        return;
    }
    FILE *fp=fopen("students.txt","w");
    while(ptr){
        fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
        ptr=ptr->next;
    }
    fclose(fp);
}
int count_node(Node *ptr){
    int c=0;
    while(ptr){
        c++;
        ptr=ptr->next;
    }
    return c;
}
void add_mid(Node**ptr){

    Node*new=malloc(sizeof(Node));
    printf("Enter node info (rollno,name,marks):");
    scanf("%d%s%f",&new->rollno,new->name,&new->marks);
    if(*ptr==0||(*ptr)->rollno > new->rollno){
        new->next=*ptr;
        *ptr=new;
    }
    else{
        Node*temp=*ptr;
        while(temp->next&&temp->next->rollno < new->rollno)
            temp=temp->next;
        new->next=temp->next;
        temp->next=new;
    }
}
void add_end(Node**ptr){

    Node*new=malloc(sizeof(Node));
    printf("Enter node info (rollno,name,marks):");
    scanf("%d%s%f",&new->rollno,new->name,&new->marks);
    new->next=0;
    if(*ptr==0)
        *ptr=new;
    else{
        Node*last=*ptr;
        while(last->next)
            last=last->next;
        last->next=new;
    }
}
void add_begin(Node **ptr){
    Node*new=malloc(sizeof(Node));
    printf("Enter node info (rollno,name,marks):");
    scanf("%d%s%f",&new->rollno,new->name,&new->marks);
    new->next=*ptr;
    *ptr=new;
}
void print_node(Node*ptr){
    if(ptr==0){
        printf("NO NODE\n");
        return;
    }
    while(ptr){
        printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
        ptr=ptr->next;
    }
}
