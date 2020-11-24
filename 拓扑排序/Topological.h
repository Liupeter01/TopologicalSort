#pragma once
#include"MGraph.h"
#include"DirectedEdge.h"				//有向边
#include"LinkStack.h"

void InitTopologicalArray(MGraph G, int** indegree);			//拓扑排序的初始化代码
void DestroyTopologicalArray(int* indegree);		  //拓扑排序的内存销毁代码
BOOL TopologicalSort(MGraph G);				  //拓扑排序执行的本体代码