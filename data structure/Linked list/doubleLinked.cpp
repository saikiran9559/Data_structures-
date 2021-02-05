#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node* leftLink;
	int data;
	struct node* rightLink;
};

int len;
struct node *root = NULL ;

int length(){
	int count=1;
	struct node* temp;
	temp = root;
	if(temp == NULL){
		return 0;
	}
	else{
		
		while(temp->rightLink != NULL){
			count++;
			temp = temp->rightLink;
		}
		return count;
	}
		
}

int append(){
	
	struct node* temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->rightLink = NULL;
	printf("enter the data: ");
	scanf("%d",&temp->data);
	
	if(root == NULL){
		
		temp->leftLink=NULL;
		root = temp;
	}
	else{
		struct node *p;
		p = root;
		while(p->rightLink != NULL){
			p = p->rightLink;
		}
		p->rightLink = temp;
		temp->leftLink = p;
	}
	
}

int display(){
	struct node *temp;
	temp = root;
	if(temp == NULL){
		printf("list is empty\n");
	}
	else{
		do{
			printf("%d<->",temp->data);
			temp = temp->rightLink;
		}while(temp != NULL);	
	}
}

int add_at_begin(){
	
	struct node *temp, *p;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("enter the data : ");
	scanf("%d",&temp->data);
	temp->leftLink = NULL;
	temp->rightLink = NULL;
	
	if(root == NULL){
		root = temp;
	}
	else{
		temp->rightLink = root;
		root->leftLink = temp;
		root = temp;
	}
	
}

int add_at_after(){
	
	struct node* temp, *p, *p2;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->leftLink = NULL;
	temp->rightLink = NULL;
	printf("enter the location: ");
	int loc;
	scanf("%d",&loc);
	printf("enter the data: ");
	scanf("%d",&temp->data);
	
	if(root == NULL){
		root = temp;
	}
	else if(loc > length()){
		printf("location out of index");
	}
	else{
		
		p = root;
		int i;
		for(int i = 1; i < loc; i++){
			p = p->rightLink;
		}
		p2 = p->rightLink;
		temp->leftLink = p;
		temp->rightLink = p2;
		p->rightLink = temp;
		p2->leftLink = temp;
	}
	
}


int delete_node(){
	struct  node* temp, *leftnode, *rightnode;
	temp = root;
	printf("enter the location:");
	int loc;
	scanf("%d",&loc);
	int i;
	if(root == NULL){
		printf("no elemets to delete");
	}
	else if(loc > length()){
		printf("invalid loaction");
	}
	else if(length() == 1 and loc == 1){
		root =NULL;
	}
	else if(loc == 1){
		root = temp->rightLink;
		root->leftLink = NULL;
		temp->rightLink = NULL;
	}
	else{
		for(i = 1; i < loc; i++){
			temp = temp->rightLink;
		}
		
		leftnode = temp->leftLink;
		rightnode = temp->rightLink;
		leftnode->rightLink = rightnode;
		temp->leftLink = NULL;
		rightnode->leftLink = leftnode;
		temp->rightLink = NULL;	
	}
	
}

int swap_two_nodes(int loc1 ,int loc2){
	
	
	
	struct node *temp1, *temp2, *p;
	p = root;
	int lent = length();
	if(loc1 <= lent and loc2 <= lent and loc1 != loc2){
		for(int i = 1; i <= length(); i++){
			if(loc1 == i or loc2 == i){
				if(loc1 == i){
					temp1 = p;
				}
				else{
					temp2 = p;
				}
			}	
		p = p->rightLink;
		
		}	
	}
	else{
		printf("Invalid swapping");
	}
	
	
	int a;
	a = temp1->data;
	temp1->data = temp2->data;
	temp2->data = a;
	
	
	
}

int reverse_list(){
	
	struct node *temp1, *temp2;
	int lent = length();
	if(lent >= 2){
		for(int i = 1; i <= (lent/2); i++){
			swap_two_nodes(i,lent-i+1);
		}
	}
	
}



int main(){
	printf("double linked list operations\n\n");;
	
	while(1){
        printf("\nMENU : \n");
        printf("1.append\n");
        printf("2.add_at_begin\n");
        printf("3.add_at_after\n");
        printf("4.delete_node\n");
        printf("5.display\n");
        printf("6.length\n");
        printf("7.reverse_list\n");
        printf("8.swap_two_nodes\n");
        printf("9.sort_elements\n");
        printf("10.delete value\n");
        printf("11.exit\n\n");
        printf("ENTER YOUR CHOICE : ");
        int choice;
        scanf("%d",&choice);
        printf("\n");
        switch(choice)
        {
        case 1:
            append();
            break;
        case 2:
            add_at_begin();
            break;
        case 3:
            add_at_after();
            break;
        case 4:
            delete_node();
            break;
        case 5:
            display();
            break;
        case 6:
            len = length();
            printf("\n LENGTH OF LIST IS : %d\n",len);
            break;
        case 7:
            reverse_list();
            break;
        case 8:
        	printf("enter the first location:");
			int loc1,loc2;
			scanf("%d",&loc1);
			printf("enter the second location:");
			scanf("%d",&loc2);
            swap_two_nodes(loc1,loc2);
            break;
        case 9:
            //sort_elements();
            break;
        case 10:
            //delete_value();
            break;
        case 11:
            exit(1);
        default:
            printf("\ninvalid choice");
        }
    }
	
}
