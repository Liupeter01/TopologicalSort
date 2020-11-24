#pragma once
#include"ALGraph.h"
#include"DirectEdge.h"		  //有向图
#include"LinkStack.h"

void InitTopologicalArray(ALGraph G, int** indegree);			//拓扑排序的初始化代码
void DestroyTopologicalArray(int* indegree);		  //拓扑排序的内存销毁代码
BOOL TopologicalSort(ALGraph G);				  //拓扑排序执行的本体代码