#include <stdio.h>
#include<stdlib.h>

struct node { 
 	int value;
	struct node *next;
} node;

struct spisochek{		
	struct node* first;	
} spisochek;

int isEmpty(struct spisochek* struc)
{
	return struc->first==NULL;
}

struct node* find(struct spisochek* struc,int value)
{
	struct node *tmp=struc->first;
	while(tmp->value!=value){
		if(tmp->next!=NULL)
			tmp=tmp->next;
		else
			return 0;
	}
	return tmp;
}

void init(struct spisochek* struc,int value)
{
	struct node* tmp;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->value=value;
	tmp->next=NULL;
	struc->first = tmp;
}

int push_back(struct spisochek* struc, int x)
{
	if(isEmpty(struc)==1)
		init (struc,x);
	else
	{
		struct node* tmp = (struct node*)malloc(sizeof(struct node));
		tmp->value=x;
		tmp->next=NULL;
		struct node* temp = struc->first;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=tmp;
	}
	return 0;
}

int push_front(struct spisochek* struc,int x) 
{
	if(isEmpty(struc)==1)
		init (struc,x);
	else
	{
		struct node *tmp = (struct node*)malloc(sizeof(struct node));
		tmp->value=x;
		tmp->next=struc->first;
		struc->first=tmp;
	}
	return 0;
}

int clear(struct spisochek* struc)
{
	if(isEmpty(struc)==1)
	{
		struct node *tmp=struc->first;
		struct node *temp=NULL;
		while(tmp!=NULL)
		{
			temp=tmp->next;
			free(tmp);
			tmp=temp;
		}
		struc->first=NULL;
	}
}

void _remove(struct spisochek* struc, struct node *tmp){
	if(tmp!=NULL){
		if (tmp==struc->first)
			struc->first=tmp->next;
		else
		{
			struct node *temp = (struct node*)malloc(sizeof(struct node));
			temp=struc->first;
			while(temp->next!=tmp)
				temp=temp->next;
			temp->next = tmp->next;
		}
		free(tmp);
	}
}

int removeFirst(struct spisochek* struc, int x)
{
	struct node* element = find(struc,x);
	if (element!=NULL){
		_remove(struc,element);
		return 0;
	}
	return -1;
}

int insertAfter	(struct spisochek* struc,int num, int value)
{
	struct node *temp = malloc(sizeof(node));
	temp->value=value;

	struct node* tmp = struc->first;
	struct node* prev_tmp = struc->first;
	
	for (int i = 1;i<num+1;i++)
	{
		prev_tmp=tmp;
		tmp=tmp->next;
		if(tmp==NULL) 
			return -1;
	}
	prev_tmp->next=temp;
	temp->next=tmp;
	return 0;   
}

void print(struct spisochek* struc)
{
	struct node* tmp=struc->first;
	while(tmp->next!=NULL)
	{
		printf("%d ", tmp->value);
		tmp=tmp->next;
	}
	printf("%d\n", tmp->value);
}

int main()
{
	int n,a;
    struct spisochek* spisochek=(struct spisochek*)malloc(sizeof(struct spisochek));	
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a);
		push_back(spisochek,a);
	}
	print(spisochek);
	
	int k[3];
        scanf("%d%d%d",&k[0],&k[1],&k[2]);
	for(int i=0;i<3;i++){
		if(find(spisochek,k[i])!=NULL)
			printf("1 ");
		else
			printf("0 ");
	}
	printf("\n");

	int m;
	scanf("%d",&m);
	push_back(spisochek,m);
	print(spisochek);

	int t;
	scanf("%d",&t);
	push_front(spisochek,t);
	print(spisochek);

	int j,x;
	scanf("%d%d",&j,&x);
	insertAfter(spisochek,j,x);
	print(spisochek);

	int z;
	scanf("%d",&z);
	removeFirst(spisochek,z);
	print(spisochek);

	clear(spisochek);
	return 0;
}
