#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node * next;
};
struct node * temp=NULL;
struct node * temp2=NULL;
struct node * start=NULL;

struct node * insert_beg(struct node * start){
	struct node * newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	int x;
	printf("Basa kac eklemek istiyorsun ?\n");
	scanf("%d", &x);
	newnode->val=x;
	if (start==NULL){
	    newnode->next=newnode;
	}
	else{
	    temp=start;
	    while(temp->next!=start){
	        temp=temp->next;
	    }
	    temp->next=newnode;
	    newnode->next=start;
	}
	start=newnode;
	return start;
}

struct node * insert_end(struct node * start){
	int x;
	printf("Sona kac eklemek istiyorsun ?\n");
	scanf("%d", &x);
	struct node * newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->val=x;
	if (start==NULL){
	    newnode->next=newnode;
	    start = newnode;
	}
	else{
	    temp=start;
	    while(temp->next!=start){
	        temp=temp->next;
	    }
	    temp->next=newnode;
	    newnode->next=start;
	}
	return start;
}
struct node * del_beg(struct node * start){
    if(start==NULL) printf("Silinecek eleman yok.\n");
    else{
        if(start->next==start){
            free(start);
            start=NULL;
        }
        else{
            temp=start;
            while(temp->next!=start){
                temp=temp->next;
            }
            temp2=start->next;
            temp->next=temp2;
            free(start);
            start=temp2;
        }
        return start;
    }
    
}

struct node * del_node(struct node * start){
	int num;
	printf("Hangi sayiyi silmek istiyorsun ? \n");
	scanf("%d",&num);
	if (start==NULL)printf("Liste bos");
	else if(start->val==num){
		start=del_beg(start);
	}
	else{
		temp=start;
		while(temp->val!=num){
			temp2=temp;
			temp=temp->next;
		}
		temp2->next=temp->next;
		if(temp==start) start=temp->next;
		free(temp);
	}
	return start;
	
}

struct node * del_end(struct node * start){
	if(start==NULL) printf("Silinecek eleman yok.\n");
	else if(start->next==start){
		free(start);
		start=NULL;
	}
	else{
		temp=start;
		while(temp->next!=start){
			temp2=temp;
			temp=temp->next;
		}
		temp2->next=start;
		free(temp);
	}
	return start;
}


void display(struct node * start){
	
	if (start==NULL) printf("Liste bos.\n");
	else if(start->next==start){
		printf("%d \n", temp->val);
	}
	else{
		temp=start;
		while(temp->next!=start){
			printf("%d ", temp->val);
			temp=temp->next;
		}
		printf("%d\n", temp->val);
	}
	
}

int main() {
	start=insert_beg(start);
	start=insert_beg(start);
	start=insert_end(start);
	start=del_end(start);
	display(start);
	



}
