#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define size 5

void push(int a);
int pop();
void display();

int fpos = -1, rpos = -1;
int queue[size];

int main(){
    int choice;
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ");
    scanf("%d", &choice);
    int a;
    while(choice != 4){
        switch(choice){
            case 1:
                printf("Enter integer to be pushed: ");
                scanf("%d", &a);
                push(a);
                // printf("fpos = %d; rpos = %d\n", fpos%size, rpos%size);
                break;
            case 2:
                a = pop();
                printf("Popped integer = %d\n", a);
                // printf("fpos = %d; rpos = %d\n", fpos%size, rpos%size);
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

void push(int a){
    if (fpos == -1 && rpos == -1){
        queue[++rpos] = a;
        fpos++;
        return;
    }
    else if ((rpos+1)%size == (fpos%size)){
        printf("Queue overflow condition\n");
        return;
    }
    else{
        rpos++;
        queue[(rpos%size)] = a;
        return;
    }
}

int pop(){
    if (fpos == -1){
        printf("Queue Underflow condition\n");
    }
    int n = queue[fpos%size];
    queue[fpos%size] = (int) NULL;
    fpos++;
    return n;
}

void display(){
    printf("Queue: ");
    for(int i = 0; i < size; i++)
        printf("%d ", queue[i]);
    printf("\n");
}
