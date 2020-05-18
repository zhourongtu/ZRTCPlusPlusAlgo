#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/*
原理：利用后缀表达式。
利用括号的匹配性，左右递归建树。
*/
typedef enum {
	MY_OPERATOR,
	MY_OPERAND
}DataTag;

typedef struct node {
	DataTag Tag;
	union {
		int my_operand;
		char my_operator;
	}data;
	struct node *Left, *Right;
}TreeNode, *NodePtr;

NodePtr BuildTree(char str[], int start, int end);
NodePtr CreateNode(DataTag T, void* data);
void PostTraverse(TreeNode *T);
int GetValueFromTree(NodePtr T);
NodePtr CreateNode(DataTag T, void* data) 
{
	NodePtr temp;
	temp = (NodePtr)malloc(sizeof(struct node));
	temp->Tag = T;
	temp->Left = NULL; temp->Right = NULL;
	if (temp->Tag == MY_OPERAND) {
		temp->data.my_operand = *(int*)(data);
	}
	else {
		temp->data.my_operator = *(char*)(data);
	}
	return temp;
}

int main()
{
	char str[1000];
	scanf("%s", str);
	int num = strlen(str);
	NodePtr T = BuildTree(str, 0, num - 1);
	PostTraverse(T);
	int a = GetValueFromTree(T);
	printf("\n%d", a);
}

void PostTraverse(TreeNode *T)
{
	if (T == NULL)return;
	else {
		PostTraverse(T->Left);
		PostTraverse(T->Right);
		if (T->Tag == MY_OPERAND) {
			printf("%d", T->data.my_operand);
		}
		else {
			printf("%c", T->data.my_operator);
		}
	}
}

NodePtr BuildTree(char str[], int start, int end)
{
	char temp[1000];
	if (start > end) {
		return NULL;
	}
	int isNumber = 0;
	for (int i = start; i <= end; i++) {
		if (isdigit(str[i])) {
			isNumber++; break;
		}
	}
	if (isNumber == (end - start + 1)) {//全都是数字
		int number = 0;
		for (int i = start; i <= end; i++) {
			number += (str[i] - '0')*(start - i + 1);
		}
		NodePtr temp = CreateNode(MY_OPERAND, (void*)(&number));
		return temp;
	}
	int flag = 0;
	int root1 = 0, root2 = 0;
	for (int i = start; i <= end; i++) {//判断根出现的位置
		char c = str[i];
		switch (c)
		{
		case '(': flag++; break;
		case ')': flag--; break;
		case '+':
		case '-': if (!flag)root1 = i; break;
		case '*':
		case '/': if (!flag)root2 = i; break;
		default: break;
		}
	}
	if (root1 == 0 && root2 == 0) {//解决(a+b)的情况
		return BuildTree(str, start + 1, end - 1);
	}
	else if (root1) {//采用root1建立括号
		NodePtr temp = CreateNode(MY_OPERATOR, (void*)(str + root1));
		temp->Left = BuildTree(str, start, root1 - 1);
		temp->Right = BuildTree(str, root1 + 1, end);
	}
	else if (root2) {
		NodePtr temp = CreateNode(MY_OPERATOR, (void*)(str + root2));
		temp->Left = BuildTree(str, start, root2 - 1);
		temp->Right = BuildTree(str, root2 + 1, end);
	}
}

int GetValueFromTree(NodePtr T)
{
	if(T->Tag == MY_OPERAND){
		return T->data.my_operand;
	}else{//操作符
		int left = GetValueFromTree(T->Left);
		int right = GetValueFromTree(T->Right);
		int result=0;
		switch(T->data.my_operator){
			case '+': result = left+right; break;
			case '-': result = left-right; break;
			case '*': result = left*right; break;
			case '/': result = left/right; break;
		}
		return result;
	}
}