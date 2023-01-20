#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
}*Head,*ptr,*new,*p,*temp;
void create(){
    new=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter:");
    scanf("%d",&new->data);
    new->next=NULL;
    ptr->next=new;
    ptr=new;
}
int display(){
    ptr=Head;
    while(ptr!=NULL){
        printf("\t %d",ptr->data);
        ptr=ptr->next;
    }
}
int x,i=0;
int search(){
    if(ptr==NULL)
    return 0;
    else if(ptr->data==x){
        printf("\n%d is in %d position of LL",ptr->data,i+1);
    }
    else{
        i++;
        ptr=ptr->next;
        return search(ptr);
    }

}
struct node*prevn,*curr,*nextn;
int rev(){
     prevn=0;
     curr=nextn=Head;
     while(nextn!=0){
           nextn=nextn->next;
           curr->next=prevn;
           prevn=curr;
           curr=nextn;
     }
     Head=prevn;
}
void removedup()
{
    ptr=Head;
    while(ptr!=NULL)
    {   p=ptr;
        while(p->next!=NULL)
        {
            if(ptr->data==p->next->data)
            {
                p->next=p->next->next;
            }
            else
            {
                p=p->next;
            }
        }
        ptr=ptr->next;    
    }
}
int count(){
    if(ptr->next!=NULL){
        i++;
        ptr=ptr->next;
        return count(ptr,i);

    }
    else{
        printf("%d no. of nodes",i);
    }
}
struct node*cur2,*prev2,*next2;
int swap(){
    int p1,p2;
    printf("give positions :");
    scanf("%d %d",&p1,&p2);
    int cnt=0;
    ptr=Head;
    while(ptr!=NULL){
        
        cnt++;
        if(cnt==p1-1){
            curr=ptr->next;
            prevn=ptr;
            nextn=(ptr->next)->next;

        }
        if((cnt)==p2-1){
            cur2=ptr->next;
            prev2=ptr;
            next2=(ptr->next)->next;
        }
        ptr=ptr->next;
    }
    ptr=Head;
    cnt=0;
    while(ptr!=NULL){
        
        cnt++;
        if((cnt)==p1-1){
            cur2->next=nextn;
            ptr->next=cur2;
            

        }
        if((cnt)==p2-1){
            curr->next=next2;
            ptr->next=curr;
            
        }
        ptr=ptr->next;
    }
    



}
void skipdel(){
    int m,n;
    printf("\ngive values of m and n:");
    scanf("%d %d",&m,&n);
    ptr=Head;
    int cnt;
    while(ptr){
          for(cnt=1;cnt<m&&ptr!=NULL;cnt++)
          ptr=ptr->next;
          
          if(ptr==NULL)
          return;

          p=ptr->next;
          for(cnt=1;cnt<=n&&p!=NULL;cnt++){
            temp=p;
            p=p->next;
            free(temp);
          }
          ptr->next=p;
          ptr=p;
    }

}


int main(){
    int c;
    new=(struct node*)malloc(sizeof(struct node));
    Head=NULL;
    printf("Enter;");
    scanf("%d",&new->data);
    new->next=NULL;
    Head=new;
    ptr=Head;
    printf("\n press1 to add:");
    scanf("%d",&c);
    while(c==1){
        create(new,ptr,Head);
        printf("\n press1 to add:");
        scanf("%d",&c);

    }
    display();
    /*rev(Head);
    printf("\n");
    display(Head);
    printf("\nsearch:");
    scanf("%d",&x);
    ptr=Head;
    search(ptr,x);
    removedup(Head);
    display(Head);*/
    //ptr=Head;
    //int i=0;
    //count(ptr,i);
  //  swap();
   // display();
   //merge()
   //delrec()
 //  skipdel();
  // display();


}