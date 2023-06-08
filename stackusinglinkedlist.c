#include<stdio.h>
#include<stdlib.h>
struct stack{
    int data;
    struct stack *next;
}*new,*ptr,*p;
struct stack*top=NULL;

void push(int x){
    
    new=(struct stack*)malloc(sizeof(struct stack));
    new->data=x;
    if(top==NULL){
    	new->next=NULL;
    	top=new;
	}
	else{
		new->next=top;
		top=new;
	}

}
void pop(){
    ptr=top;
     if(top==NULL){
	printf("\nUnderflow!\n");
	}
	else
	{
	top=top->next;
    printf("%d poped",ptr->data);
	free(ptr);
} }
void display(){
    ptr=top;
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}

}
void peek(){
   printf("%d is frst ",top->data);
}
int main(){
    int a;
    push(1);
    push(2);
    push(3);
    push(4);
    display();
    peek();
    pop();
    pop();
    pop();
    pop();
    pop();

}
