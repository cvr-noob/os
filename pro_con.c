#include<stdio.h>
#include<unistd.h>

#define SIZE 5

int buffer[SIZE];
int count = 0;
int empty = SIZE, full = 0, mutex = 1;

void wait(int *s){
    while(*s<=0);
    (*s)--;
}

void signal1(int *s){
    (*s)++;
}

void producer(){
    int item = 0;
    if(empty>0 && mutex==1){
        printf("Enter item to insert into buffer: ");
        scanf("%d",&item);
        wait(&empty);
        wait(&mutex);
        buffer[count++] = item;
        printf("Produced: %d\n",item);
        signal1(&mutex);
        signal1(&full);
    }
    else{
        printf("Buffer is full\n");
    }
}

void consumer(){
    int item=0;
    if(full>0 && mutex==1){
        wait(&full);
        wait(&mutex);
        item = buffer[--count];
        printf("recieved %d\n", item);
        signal1(&mutex);
        signal1(&empty);
    }
    else{
        printf("buffer is empty\n");
    }
}

void main(){
    int ch;
    printf("Menu\n1)Producer\n2)Consumer\n3)Exit\n");
    do{
        scanf("%d",&ch);
        switch(ch){
            case 1: producer();
                    break;
            case 2: consumer();
            case 3: break;
            default: printf("Invalid input");
        }
    }while(ch!=3);
}
