#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 10
int pos = -1;
int stack[size];

void push(int a);
int pop();
void display();

int main(){
    printf("1. Push\n2. Pop\n3. Display stack\n4. Exit\nEnter choice: ");
    int choice;
    int a;
    scanf("%d", &choice);
    while(choice != 4){
        switch(choice){
            case 1: 
                printf("Enter integer to be pushed: ");
                scanf("%d", &a);
                push(a);
                break;
            case 2: 
                a = pop();
                printf("Integer poppped = %d\n", a);
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid input");
                break;
        }
        printf("Enter choice: ");
        scanf("%d", &choice);
    }
    
}

void push(int a){
    if (pos == 9){
        printf("Stack Overflow condition");
        return;
    }
    stack[++pos] = a;
}

int pop(){
    if (pos == -1){
        printf("Stack Underflow condition");
        return (int) NULL;
    }
    return stack[pos--];
}

void display(){
    for(int i = 0; i < size; i++){
        printf("%d ", stack[i]);
    }
    printf("\n");
}
