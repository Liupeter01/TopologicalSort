#pragma once
#include"ALGraph.h"
#include"DirectEdge.h"		  //����ͼ
#include"LinkStack.h"

void InitTopologicalArray(ALGraph G, int** indegree);			//��������ĳ�ʼ������
void DestroyTopologicalArray(int* indegree);		  //����������ڴ����ٴ���
BOOL TopologicalSort(ALGraph G);				  //��������ִ�еı������