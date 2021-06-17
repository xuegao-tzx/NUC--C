#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define OVERFLOW -1

typedef int Status;
typedef char TElemType;
typedef struct BiTNode
{
TElemType data;
struct BiTNode *lchild;
struct BiTNode *rchild;
}BiTNode;
typedef BiTNode *BiTree;

Status Create(BiTree &T)/*����������*/
{
	char ch;
	ch=getchar();
	if(ch=='*') T=NULL;
	else 
	{
		if (!(T=(BiTNode *)malloc(sizeof(BiTNode))))exit(OVERFLOW);
		T->data=ch; 
		Create(T->lchild); 
		Create(T->rchild); 
	}
	return OK;
} 
void Display(TElemType& e){printf("%c\t",e);}
void PreOrder(BiTree T, void(*visit)(TElemType& e))/*�������*/
{
	if (T==NULL) return;
	visit(T->data);
	PreOrder(T->lchild,visit);
	PreOrder(T->rchild,visit);
}
void InOrder(BiTree T, void(*visit)(TElemType& e))/*�������*/
{ 
	if (T==NULL) return;
	InOrder(T->lchild,visit);
	visit(T->data);
	InOrder(T->rchild,visit);
}
int k=0,top=-1;
void push(BiTNode** a,BiTNode* elem){a[++top]=elem;}/*ǰ����������ʹ�õĽ�ջ����*/
void pop( )/*��ջ����*/
{
    if(top==-1)return;
    top--;
}
void displayElem(BiTNode* elem){printf("%c       ",elem->data);}/*ģ��������Ԫ�صĺ����������㱾�����ֵ*/
BiTNode* getTop(BiTNode**a){return a[top];}/*�õ�ջ��Ԫ��*/
void InOrderf(BiTree Tree)/*��������ǵݹ��㷨*/
{
    BiTNode* a[20];
    BiTNode * p;
    push(a,Tree);
    while (top!=-1) 
	{
        while((p=getTop(a))&&p){push(a,p->lchild);}
        pop();
        if (top!=-1) 
		{
            p=getTop(a);
            pop();
            displayElem(p);
            push(a,p->rchild);
        }
    }
}
void PostOrder(BiTree T, void(*visit)(TElemType& e))/*�������*/
{
	if(T==NULL)return;
	PostOrder(T->lchild,visit);
	PostOrder(T->rchild,visit);
	visit(T->data);
}
int BiTreeHeight(BiTree T)/*���õݹ���������ĸ߶�*/
{
	int LH,RH;
	if(!T)return 0;
	else
	{
		LH=BiTreeHeight(T->lchild);
		RH=BiTreeHeight(T->rchild);
		if(LH>RH)return(LH+1);
		else return(RH+1);
	}
} 
int leaves(BiTree T)/*��Ҷ�ӽ����Ŀ*/
{
	if(!T)return 0;
    else
	{
		if (T->lchild==NULL&&T->rchild==NULL) k++;
		else 
		{
	   		if(T->lchild)leaves(T->lchild);
	   		if(T->rchild)leaves(T->rchild);
		}
	}	   	   
	return(k);
}

int main()
{
	BiTree R;
	printf("��������������������㣬(*Ϊ��)������������\n");
	Create(R);
	printf("\n��������ݹ��㷨�����\n");
	PreOrder(R,Display);
	printf("\n��������ݹ��㷨�����\n");
	InOrder(R,Display);
	printf("\n��������ǵݹ��㷨�����\n");
	InOrderf(R);
	printf("\n��������ݹ��㷨�����\n");
	PostOrder(R,Display);
	printf("\n�������ĸ߶ȣ�%d\n",BiTreeHeight(R));
	printf("\n���������ĸ�����%d\n",leaves(R));
	return 0;
}
