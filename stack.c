#include<stdio.h>
#define n 5
int stack[n];
int top=-1;
void push(){
    int x;
    printf("Enter data :");
    scanf("%d",&x);
    if(top==n-1){
        printf("Overflow");
        
    }
    else{
        top++;
        stack[top]=x;
    }
}
void pop(){
    int item;
    if(top==-1){
        printf("Underflow");
    }
    else{
        item=stack[top];
        top--;

    }
    printf("%d is poped",item);
}
void peek(){
    if(top==-1){
        printf("Empty");

    }
    else{
        printf("%d",stack[top]);
    }
}
void display(){
    printf("\n display");
    for(int i=top;i>=0;i--){
        printf("\t%d",stack[i]);
    }
}
int main(){
    int c;
    printf("PRESS 0.exit 1.push 2.pop  3.peek 4.display : ");
    scanf("%d",&c);
    while(c!=0){
    if(c==1){
    push();
    
    }

    else if(c==2)
    {pop();
    
    }

    else if(c==3)
    {peek();
    
    }
    else if(c==4)
    {display();
    
    }
    else{
        printf("invalid");

    }
    printf("PRESS 0.exit 1.push 2.pop  3.peek 4.display : ");
    scanf("%d",&c);
    }
    
}