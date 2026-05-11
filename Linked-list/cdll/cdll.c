#include"cdll.h"
Node* head=0;
int main(void){
    int op;
    while(1){ 
        printf("1)Add begin 2)Add end 3)Add middle 4)print 5)Search node 6)count node 7)reverse print 8)Read file 9)Save file 10)Delete node 11)Delete all 12)Delete duplicate node 13)Sort node 14)Reverse rec 15)Reverse link 0)Exit\n");
        scanf("%d",&op);
        switch(op){
            case 1:add_begin();break;
            case 2:add_end();break;
            case 3:add_middle();break;
            case 4:print();break;
            case 5:search_node();break;
            case 6:printf("count: %d\n",count_node());break;
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
            default:printf("Wrong Option\n");
        }
    }
    return 0;
}
void reverse_link(){
    if(head==0){
        printf("No node\n");
        return;
    }
    Node*p=head,*temp,*last=head->prev;
    do{
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=temp;
    }while(p!=head);
    head=last;
    printf("Link reversed successfully\n");
}
void reverse_rec(Node*p){
    if(head==0){
        printf("No node\n");
        return;
    }
    if(p->next!=head){
        reverse_rec(p->next);
        printf("%d ",p->data);
    }
    else{
        printf("%d ",p->data);
    }
    if(p==head)
        printf("\n");
}
void sort_node(){
    if(head==0){
        printf("No node to sort\n");
        return;
    }
    Node*p=head;
    while(p->next!=head){
        Node*q=p->next;
        while(q!=head){
            if(p->data > q->data){
                int temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
            q=q->next;
        }
        p=p->next;
    }
    printf("Sorted successfully\n");
}
void delete_all(){
    if(head==0){
        printf("No node\n");
        return;
    }
    Node *del,*temp=head->next;
    while(temp!=head){
        del=temp;
        temp=temp->next;
        free(del);
    }
    free(head);
    head=0;
    printf("All nodes deleted\n");
}
void delete_duplicate(){
    if(head==0){
        printf("No node\n");
        return;
    }
    Node*p=head,*del;int cp=0,cq=0;
    while(p->next!=head){
        cp++;
        Node *q=p->next;
        cq=cp;
        while(q!=head){
            cq++;
            if(p->data==q->data){
                del=q;
                q->next->prev=q->prev;
                q->prev->next=q->next;
                printf("%d duplicate found at %dth position,Deleted\n",p->data,cq);
                q=q->next;
                free(del);
            }
            else{
                q=q->next;
            }
        }
        p=p->next;
    }
}
void delete_node(){
    if(head==0){
        printf("No node\n");
        return;
    }
    int data,f=0;
    printf("Enter data to delete:");
    scanf("%d",&data);
    Node*del;int c=-1;
    while(head->data==data){
        c++;
        f=1;
        Node*last=head->prev;
        del=head;
        if(head!=head->next){
            head=head->next;
            last->next=head;
            head->prev=last;
        }
        else{
            head=0;
            free(del);
            printf("%d found at %dth position,Deleted\n",data,c);
            return;
        }
        free(del);
        printf("%d found at %dth position,Deleted\n",data,c);
    }
    Node*p=head,*temp;
    do{
        c++;
        if(p->data == data){
            f=1;
            del=p;
            p->prev->next=p->next;
            p->next->prev=p->prev;
            printf("%d found at %dth position,Deleted\n",data,c);
            temp=p->next;
            free(del);
            p=temp;
        }
        else
            p=p->next;
    }while(p!=head);
    if(f==0)
       printf("Data not present\n");
}
void reverse_print(){
    if(head==0){
        printf("No node\n");
        return;
    }
    Node*p=head->prev;
    do{
        printf("%d ",p->data);
        p=p->prev;
    }while(p!=head->prev);
    printf("\n");
}
int count_node(){
    if(head==0)
        return 0;
    int c=0;
    Node*p=head;
    do{
        c++;
        p=p->next;
    }while(p!=head);
    return c;
}
void read_file(){
    FILE *fp=fopen("cdll.txt","r");
    if(fp==0){
        printf("File not available\n");
        return;
    }
    int data;
    while(fscanf(fp,"%d",&data)!=EOF){
        Node*p=(Node*)malloc(sizeof(Node));
        if(p==0){
            printf("Memory allocation failed\n");
            fclose(fp);
            return;
        }
        p->data=data;
        if(head==0){
            p->next=p;
            p->prev=p;
            head=p;
        }
        else{
            Node *last=head;
            while(last->next!=head)
                last=last->next;
            last->next=p;
            p->prev=last;
            p->next=head;
            head->prev=p;
        }
    }
    printf("File read successfully\n");
    fclose(fp);
}
void save_file(){
    if(head==0)
        return;
    Node*p=head;
    FILE *fp=fopen("cdll.txt","w");
    if(fp==0){
        printf("Saving operation failed\n");
        return;
    }
    do{
        fprintf(fp,"%d ",p->data);
        p=p->next;
    }while(p!=head);
    printf("Saved successfully\n");
    fclose(fp);
}
void search_node(){
    if(head==0){
        printf("No node\n");
        return;
    }
    int data,c=0;
    printf("Enter the data:");
    scanf("%d",&data);
    Node*p=head;
    do{
        if(p->data==data){
            printf("%d found at %dth position\n",data,c);
        }
        c++;
        p=p->next;
    }while(p!=head);
}
void add_middle(){
    Node*p=(Node*)malloc(sizeof(Node));
    if(p==0){
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data:");
    scanf("%d",&p->data);
    if(head==0){
        head=p;
        p->next=p;
        p->prev=p;
    }
    else if(head->data > p->data){
        Node*last;
        last=head->prev;
        head->prev=p;
        p->next=head;
        last->next=p;
        p->prev=last;
        head=p;
    }
    else{
        Node*mid=head;
        while((mid->next!=head)&& (mid->next->data < p->data))
            mid=mid->next;
        if(mid->next==head)
            head->prev=p;
        p->next=mid->next;
        p->prev=mid;
        mid->next->prev=p;
        mid->next=p;
        
    }
}
void add_end(){
    Node* p=(Node*)malloc(sizeof(Node));
    if(p==0){
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data:");
    scanf("%d",&p->data);
    if(head==0){
        head=p;
        p->next=p;
        p->prev=p;
    }
    else{
        Node * last=head->prev;
        last->next=p;
        p->prev=last;
        p->next=head;
        head->prev=p;
    }
}
void print(){
    if(head==0){
        printf("No node\n");
        return;
    }
    Node * ptr=head;
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
    printf("\n");
}
void add_begin(){
    Node* p=(Node*)malloc(sizeof(Node));
    if(p==0){
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the data:");
    scanf("%d",&p->data);

    if(head==0){
        head=p;
        p->next=p;
        p->prev=p;
    }
    else{
        Node*last=head->prev;
        p->next=head;
        p->prev=last;
        head->prev=p;
        last->next=p;
        head=p;
    }

}
