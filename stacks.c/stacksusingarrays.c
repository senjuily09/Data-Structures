#include<stdio.h>
#include<stdlib.h>
int main(){
    int top=-1,stock[max];
    int arr=[];
    void push(){
        int element;
        if(top=max-1){
            printf("Stack is full\n");
        }
        else{
            printf("eneter the element\n");
            scanf("%d",&element);
            stack[++top]=element;
            printf("insertion sucessfull\n");

        }
    }
    void pop(){
        int element2;
        if(top==-1){
            printf("stack is empty\n ");
    }
    else{
        printf("the element %d is at the qposition %d is deleted\n");
        stack[top],top;
        top=top-1;
    }
    }
    void display(){
        int i;
        if(top===-1){
            printf("stack elements are \n");
            for(i=top;i>0;i--){
                printf("%d\n",stack[i]);
            }
        }
    }
    return0;
}