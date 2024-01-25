#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node *next;
} node;

node *head = NULL;
node *head1 = NULL;
int count = 0;

void insert(int data, int position);
void delete(int position);
void display();
void sort();
void reverse();
void concat(node** head1, node** head2);

int main(){
     /*int data, choice, pos;
     printf("1. Insert\n2. Delete\n3. Exit\nChoice: ");
     scanf("%d", &choice);
     while(choice != 3){
         if (choice == 1){
             printf("Enter data and position: ");
             scanf("%d%d", &data, &pos);
             insert(data, pos);
             printf("Count: %d\n", count);
         } else if (choice == 2){
             printf("Enter position: ");
             scanf("%d", &pos);
             delete(pos);
             printf("Count: %d\n", count);
         }
         display();
         printf("Enter choice: ");
         scanf("%d", &choice);
     }*/
    insert(2, 0);
    insert(1, 1);
    insert(4, 2);
    insert(3, 3);
    insert(5, 4);
    printf("Original Linked List: \n");
    display();
    sort();
    printf("Sorted Linked List: \n");
    display();
    reverse();
    printf("Reversed Linked List: \n");
    display();
    head1 = head;
    head = NULL;
    insert(3, 0);
    insert(4, 1);
    insert(1, 2);
    display();
    concat(&head1, &head);
    head = head1;
    printf("Concatenating with the above linked list gives: \n");
    display();

    return 0;
}

void insert(int data, int position){
    if (position == 0){
        node* new_node = (node*)malloc(sizeof(node));
        new_node->data = data;
        new_node->next = head;
        head = new_node;
        count++;
        return;

    } else if (position == count){
        node* new_node = malloc(sizeof(node));
        new_node->data = data;
        new_node->next = NULL;
        node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
        count++;
        return;

    } else if (position > count || position < 0){
        printf("Unable to insert at given position\n");
        return;
    } else {
        node* temp = head;
        for(int i = 0; i < position-1; i++)
            temp = temp->next;
        node* new_node = malloc(sizeof(node));
        new_node->data = data;
        new_node->next = temp->next;
        temp->next = new_node;
        count++;
        return;
    }
}

void delete(int position){
    if (position == 0){
        node* temp = head;
        head = head->next;
        free(temp);
        count--;
        return;
    } else if (position == count-1){
        node* temp = head;
        for(int i = 1; i < count-1; i++)
            temp = temp->next;
        node* temp1 = temp->next;
        temp->next = NULL;
        free(temp1);
        count--;
        return;
    } else if (position > count || position < 0){
        printf("Unable to delete at given position\n");
        return;
    } else {
        node* temp = head;
        for(int i = 0; i < position-1; i++)
            temp = temp->next;
        node* temp1 = temp->next;
        temp->next = temp1->next;
        free(temp1);
        count--;
        return;
    }
}

void sort(){
    int i, j, min_index;
    node *i_node=head, *j_node=head, *min_node=NULL;
    for(int i = 0; i < count-1; i++, i_node=i_node->next){
        min_index = i;
        min_node = i_node;
        j_node = i_node->next;
        for(int j = i+1; j < count; j++, j_node=j_node->next){
            if (j_node->data < i_node->data){
                min_index = j;
                min_node = j_node;
            }
        }
        if (min_index != i){
            int temp = i_node->data;
            i_node->data = min_node->data;
            min_node->data = temp;
        }
    }
}

void reverse(){
    node *prev = NULL, *next=NULL;
    while(head != NULL){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head = prev;
}

void concat(node **head1, node **head2){
    node *temp1 = *head1;
    while (temp1->next != NULL){
        temp1 = temp1->next;
    }
    temp1->next = *head2;
}

void display(){
    node* temp = head;
    //printf("Linked List: ");
    while (temp->next != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
    printf("\n");
}
