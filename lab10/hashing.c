#include <stdio.h>

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define size 10

int table[size];

void push(int data);
int pop(int data);
void search(int data);
void display();

int main(){
    for(int i = 0; i < size; i++) table[i] = -1;
    int choice;
    printf("1. Insert\n2. Search\n3. Delete\n4. Exit\nChoice: ");
    scanf("%d", &choice);
    int a;
    while(choice != 4){
        switch(choice){
            case 1:
                printf("Enter integer to be pushed: ");
                scanf("%d", &a);
                push(a);
                break;
            case 2:
                printf("Enter integer to be popped: ");
                scanf("%d", &a);
                int res = pop(a);
                if (res == 0) printf("Integer popped\n");
                else printf("Integer not found\n");
                break;
            case 3:
                display();
                break;
            default:
                printf("Idk");
                break;
        }
        printf("Enter choice: ");
        scanf("%d", &choice);
    }
}

void push(int data){
    int hash = data%size;
    while (table[hash] != -1 && hash <= (hash+size-1)) hash = (hash+1)%size;
    if (table[hash] == -1) table[hash] = data;
    else printf("Table is full");
}

int pop(int data){
    int hash = data%size;
     for(int i = 0; (table[hash] != data) || (i < size); i++, hash = (hash+1)%size);
     if (table[hash] == data) {
        table[hash] = -1; return 0;
     }
     return -1;
}

void display(){
    printf("Table: ");
    for(int i = 0; i < size; i++)
        printf("%d ", table[i]);
    printf("\n");
}
