#pragma once
#include"MGraph.h"
#include"DirectedEdge.h"				//�����
#include"LinkStack.h"

void InitTopologicalArray(MGraph G, int** indegree);			//��������ĳ�ʼ������
void DestroyTopologicalArray(int* indegree);		  //����������ڴ����ٴ���
BOOL TopologicalSort(MGraph G);				  //��������ִ�еı������