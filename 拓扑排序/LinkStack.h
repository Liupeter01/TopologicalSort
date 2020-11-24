#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>

#define ElemType char

typedef struct StackNode
{
		  ElemType data;						  //数据域
		  struct StackNode* next;		//指针域
}StackNode,*LinkStack;

void InitLinkStack(LinkStack* lstack);	//初始化链式栈
void DestroyLinkStack(LinkStack* lstack);	//摧毁链式栈
BOOL isEmpty(LinkStack lstack);		// 判空操作
int length(LinkStack lstack);	//求栈的大小
ElemType GetTop(LinkStack lstack);//获得栈顶元素

/*出栈入栈操作*/
void Push_Stack(LinkStack*lstack,ElemType data);	//入栈
void Pop_Stack(LinkStack* lstack, ElemType *x);	//出栈