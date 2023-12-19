#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cnt=0;
char name[20];
	int num;
	int age;
	int score;

typedef struct Node
{
	char name[20];
	int num;
	int age;
	int score;
	struct Node* next;
}Node,*Linklist;

Linklist crHeadNode()
{
	Linklist headNode=(Linklist)malloc(sizeof(Node));
	headNode->next=NULL;
	return headNode;
}

Linklist crNewNode(char name[],int num,int age,int score)//����һ����ѧ�����
{
	Linklist P=(Linklist)malloc(sizeof(Node));
	strcpy(P->name,name);
	P->num=num;
	P->age=age;
	P->score=score;
	return P;
}

void addStuTail(Linklist headNode,Linklist P,char name[],int num,int age,int score)//��β������һ��ѧ����Ϣ
{
	P=crNewNode(name,num,age,score);
	while(headNode->next){
		headNode=headNode->next;
	}
	P->next=NULL;
	headNode->next=P;
	cnt++;
}

Linklist seekNode(Linklist headNode,int x)//Ѱ��ǰһѧ�����
{
	while(--x){
		headNode=headNode->next;
	}
	if(!headNode){
		return NULL;
	}
	return headNode;
}

void deleteNode(Linklist headNode,int x)//ɾ��ĳѧ����Ϣ
{
	headNode=seekNode(headNode,x);
	if(!headNode||!headNode->next){
		return ;
	}
	Linklist P=headNode->next;
	headNode->next=headNode->next->next;
	free(P);
	cnt--;
}

void modifyNode(Linklist headNode,int x)
{
	int score;
	headNode=seekNode(headNode,x);
	if(!headNode){
		return;
	}
	headNode=headNode->next;
	if(!headNode)
	{
		return;
	}
	printf("��������Ҫ�޸ĵ�ֵ��");
	scanf("%d",&score);
	headNode->score=score;
}

void searchNode(Linklist headNode,int x)//����Ų���
{
	headNode=seekNode(headNode,x);
	if(!headNode){
		printf("�Ҳ�����ѧ����Ϣ��\n");
		return;
	}
	headNode=headNode->next;
	if(!headNode){
		printf("�Ҳ�����ѧ����Ϣ��\n");
		return;
	}
	printf("������%s\nѧ�ţ�%d\n���䣺%d\n�ɼ���%d\n",headNode->name,headNode->num,headNode->age,headNode->score);
}

void ListReverse(Linklist headNode)//��������   ����˼�룺��ͷ�ڵ����������������������ͷ�ڵ�󣬽������β嵽ͷ�ڵ����һ�ڵ�֮��
{
	Linklist p,s;
	p=headNode->next;
	headNode->next=NULL;
	while(p)
	{
		s=p;
		p=p->next;
		//ͷ��
		s->next=headNode->next;
		headNode->next=s;
	}
	printf("����\tѧ��\t����\t�ɼ�\n");
	headNode=headNode->next;
	while(headNode){
		printf("%-8s%-8d%-8d%-8d\n",headNode->name,headNode->num,headNode->age,headNode->score);
		printf("\n");
		headNode=headNode->next;
	}
}


void printfList(Linklist headNode)//��ӡ
{
	printf("����\tѧ��\t����\t�ɼ�\n");
	headNode=headNode->next;
	while(headNode){
		printf("%-8s%-8d%-8d%-8d\n",headNode->name,headNode->num,headNode->age,headNode->score);
		printf("\n");
		headNode=headNode->next;
	}
}

void saveList(Linklist headNode)//����
{
	FILE* fp=fopen("../data/member.txt","w");
	if(fp==NULL){
		printf("���ļ�ʧ��\n");
		return ;
	}
	headNode=headNode->next;
    while(headNode){
    	fprintf(fp,"%s\t%d\t%d\t%d\n",headNode->name,headNode->num,headNode->age,headNode->score);
    	headNode=headNode->next;
	}
	fclose(fp);
	fp=NULL;
	printf("����ɹ�!\n\n");
}

void readList(Linklist headNode)
{
	FILE* fp=fopen("../data/member.txt","r");
    if(fp==NULL){
		printf("���ļ�ʧ��\n");
		return ;
	}
	while(1){
		Linklist P=(Linklist)malloc(sizeof(Node));
	    P->next=NULL;
		if(fscanf(fp,"%s %d %d %d",P->name,&P->num,&P->age,&P->score)!=EOF){
			printf("%-8s%-8d%-8d%-8d\n",P->name,P->num,P->age,P->score);
		    printf("\n");
			headNode->next=P;
			headNode=headNode->next;
		}else{
			return;
		}
	}
	
	fclose(fp);
	fp=NULL;
}

void menu()//�˵�
{
	printf("1��������ѧ����Ϣ\n");
	printf("2����ɾ��ѧ����Ϣ\n");
	printf("3��������ѧ����Ϣ\n");
	printf("4�����޸�ѧ���ɼ�\n");
	printf("5��������ѧ����Ϣ\n");
	printf("6������ӡѧ����Ϣ\n");
	printf("7������ȡ�ļ���Ϣ\n");
	printf("8�������������Ϣ\n");
}

int choice()
{
	int choice;
	printf("������Ҫ���еĲ�����ţ�\n");
	scanf("%d",&choice);
	return choice;
}

void work(Linklist headNode)
{
	
	menu();
	int a=choice();
	switch(a){
		case 1:{
			char name[20];
			int num,age,score;
			int n,i;
			printf("����ѧ��������");
			scanf("%d",&n);
			for(i=0;i<n;i++){
			    printf("������������ѧ�š����䡢�ɼ���\n");
			    scanf("%s %d %d %d",&name,&num,&age,&score);
		    	Linklist P;
			    addStuTail(headNode,P,name,num,age,score);
	    	}
			printf("����ɹ�!\n");
			break;
		}
		case 2:	{
			printf("��������Ҫɾ����ѧ����ţ�\n");
			int x;
			scanf("%d",&x);
			deleteNode(headNode,x);
			printf("ɾ���ɹ�!\n");
			break;
		}
		case 3:{
			printf("��������Ҫ���ҵ�ѧ��ѧ�ţ�\n");
			int x;
			scanf("%d",&x);
			searchNode(headNode,x);
			break;
		}
		case 4:{
			printf("��������Ҫ������Ϣ�޸ĵ�ѧ����ţ�\n");
			int x;
			scanf("%d",&x);
			modifyNode(headNode,x);
			printf("�޸ĳɹ�!\n");
			break;
		}
		case 5:{
			saveList(headNode);
			break;
		}
		case 6:{
			printfList(headNode);
			break;
		}
		case 7:{
			readList(headNode);
			break;
		}
		case 8:{
			ListReverse(headNode);
			break;
		}
		default:
		    printf("�������\n"); break;
	}

}


int main()
{
	Linklist headNode=crHeadNode();
	while(1){
	    work(headNode);
   }
	return 0;
}



