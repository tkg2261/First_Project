#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};
void push(struct node** head_ref,int new_data){

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data=new_data;
    new_node->next=NULL;

    if(*head_ref==NULL){
    *head_ref=new_node;
    }
    else{
        struct node* current;
        current=*head_ref;
        while(current->next!= NULL){
            current=current->next;
        }
        current->next=new_node;
    }
}
void printlist(struct node* head)
{
    struct node* current=head;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
}

void  swap(struct node** head_ref ,int x , int y)
{
    struct node *current = *head_ref , *previous = NULL , *node_x = NULL ,*node_y = NULL, *prev_x = NULL, *prev_y =NULL;

    while(current!=NULL && (node_x == NULL || node_y == NULL)){

        if(node_x ==  NULL && current -> data == x)
        {
            node_x = current;
            prev_x = previous;
        }
        else if(node_y == NULL && current->data == y)
        {
            node_y = current;
            prev_y = previous;
        }

        previous = current;
        current = current->next;

    }

    if(node_x == NULL && node_y == NULL)
        printf("Both x and y not found\n");

    else if(node_x == NULL)
        printf("x not found\n");

    else if(node_y == NULL)
        printf("y not found\n");

    else {

        struct node* temp;

        if(prev_x == NULL){
//            temp = (*head_ref)->next;
            prev_y->next = *head_ref;
//            (*head_ref)->next = node_y->next;
            node_y->next = temp;
            *head_ref = node_y;
        }

        else if(prev_y == NULL){
            temp = (*head_ref)->next;
            prev_x->next = *head_ref;
            (*head_ref)->next = node_x->next;
            node_x->next = temp;
            *head_ref = node_x;
        }

        else
        {
            temp = node_y->next;
            prev_x->next = node_y;
            prev_y->next = node_x;
            node_y->next = node_x->next;
            node_x->next = temp;
        }
    }




}

void rev (struct node** head_ref){

    struct node *current = *head_ref, *previous = NULL,*temp = NULL;

    while(current != NULL)
    {
        temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }
    *head_ref = previous ;
}

void rev_r (struct node** head_ref){

    if(*head_ref == NULL || (*head_ref)->next == NULL)
        return;

    struct node *temp = (*head_ref)->next;
    rev_r (&temp);
    temp->next = *head_ref;
    (*head_ref)->next = NULL;
    *head_ref = temp;
}

struct node* sortedMerge(struct node* head1 ,struct node* head2){

    struct node* head = NULL;
    struct node* current = NULL;

    while (head1 && head2){

        if(head1->data <= head2->data){
            if(head == NULL)
            {
                head = head1;
                head1 = head1->next;
                head->next = NULL;
                current = head;
            }
            else{
                current->next = head1;
                head1 = head1->next;
                current = current->next;
                current->next = NULL;
            }
        }

        else{

            if(head == NULL)
            {
                head = head2;
                head2 = head2->next;
                head->next = NULL;
                current = head;
            }
            else{
                current->next = head2;
                head2 = head2->next;
                current = current->next;
                current->next = NULL;
            }


        }

    }
    if(head){
            if(head1){
                current -> next = head1;
            }
            else if(head2){
                current -> next = head2;
            }
    }
    else{
            if(head1){
                head = head1;
            }
            else if(head2){
                head = head2;
            }

    }

    return head;
};


struct node* sortedMergeRev(struct node* head1,struct node* head2){


    if(!head1){
        return head2;
    }
    else if(!head2){
        return head1;
    }
    else {
        struct node* head = NULL;
        if(head1->data <= head2->data){
            head = head1;
            head->next = sortedMergeRev(head1->next,head2);
        }
        else{
            head = head2;
            head->next = sortedMergeRev(head1,head2->next);
        }
    return head;
    }


};

int main()
{
    printf("Hello world!\n");
    struct node* head1=NULL;
    struct node* head2=NULL;
    struct node* head=NULL;
    push(&head1,1);
    push(&head2,2);
    push(&head1,3);
    push(&head2,4);
    push(&head1,5);
    push(&head2,6);
    push(&head1,7);
//    printlist(head2);
 //   struct node** head_ref = @head;

    head = sortedMergeRev(head1,head2);
//    swap(&head,3,4);
    printlist(head);

//    push(&head, 34);
//	push(&head, 36);
//	push(&head, 38);
//	push(&head, 39);
//	push(&head, 41);
//	push(&head, 42);
//
//	printf("\n Linked list before calling swapNodes() ");
//	printlist(head);
//
//    rev_r(&head);
//
//	printf("\n Linked list after calling swapNodes() ");
//
//    printlist(head);
    return 0;
}
