#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};
struct node *root = NULL ;
int len;

void append(){
	struct node* temp ;
	temp = (struct node*)malloc(sizeof(struct node)) ;
	printf("enter the node data: ") ;
	scanf("%d",&temp->data);
	temp->link = NULL;
	
	if(root == NULL){
		root = temp ;
	}
	else{
		struct node* p ;
		p = root ;
		while(p->link!= NULL){
			p = p->link;
		}
		p->link = temp;
	}
}

int length(){
	int count = 0;
	struct node* t;
	t = root;
	while(t!=NULL){
		t =	t->link;
		count++;
	}
	return count;
}

void display(){
	struct node* temp;
	temp = root;
	if(temp == NULL){
		printf("List is empty\n\n");
	}
	else{
		while(temp!=NULL){
			printf("%d -> ",temp->data);
			temp = temp->link;
		}
		printf("\n\n");
	}
}

void addAtBegin(){
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("enter the data = ");
	scanf("%d",&temp->data);
	if(root == NULL){
		
		root = temp;
		temp->link = NULL;
	
	}
	else{
		temp->link = root;
		root = temp;	
	}
}

void Delete(){
	printf("enter the location : ");
	int loc;
	scanf("%d",&loc);
	if(loc>length()){
		printf("invalid location\n\n");
	}
	else if(loc==1){
		root=root->link;
	}
	else{
		struct node* temp, *leftNode;
		temp = root;
		for(int i=1;i<loc;i++){
			leftNode = temp;
			temp = temp->link;
		}
		leftNode->link = temp->link;
		
	}
}

int addAtAfter(){
	
	printf("enter the loactaion :");
	int loc;
	scanf("%d",&loc);
	
	struct node *add, *temp, *leftNode;
	add = (struct node*)malloc(sizeof(struct node));
	printf("enter the data:");
	scanf("%d",&add->data);
	add->link = NULL;
	
	temp = root;
	for(int i=0; i<loc; i++){
		leftNode = temp;
		temp = temp->link;
	}
	leftNode->link = add;
	add->link = temp;
}

int main(){
	
	while(1){
		
		printf("1.append\n2.AddAtBegin\n3.AddAtAfter\n4.Length\n5.Display\n6.Delete\n7.Quit\n");
		printf("enter the choice: ");
		int ch;
		scanf("%d",&ch);
		switch(ch){
			case 1:
				append();
				break;
			case 2:
				addAtBegin();
				break;
			case 3:
				addAtAfter();
				break;
			case 4:
				len = length();
				printf("%d\n\n",len);
				break;
			case 5:
				display();
				break;
			case 6:
				Delete();
				break;
			case 7:
				exit(1);
				break;
			default:
				printf("invalid choice.. \n\n");
		}
		
	}
	
}







