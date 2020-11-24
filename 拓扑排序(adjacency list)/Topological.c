#include"Topological.h"

void InitTopologicalArray(ALGraph G, int** indegree)			//拓扑排序的初始化代码
{
		  *indegree = (int*)malloc(sizeof(int) * G.vexnum);//分配拓扑排序的空间
		  assert(*indegree != NULL);
		  memset(*indegree, 0, sizeof(int) * G.vexnum);

		  for (int i = 0; i < G.vexnum; ++i)				//计算每个顶点的入度
		  {
					(*indegree)[i] = CalculateEnVertex(G, G.Vetics[i].data);
		  }
}

void DestroyTopologicalArray(int* indegree)		  //拓扑排序的内存销毁代码
{
		  free(indegree);
}

BOOL TopologicalSort(ALGraph G)			  //拓扑排序执行的本体代码
{
		  LinkStack stack;	 
		  InitLinkStack(&stack);		 //栈的初始化
		  int* indegree = NULL;			
		  InitTopologicalArray(G, &indegree);	  //存储每一个顶点的入度数量
		  int counter = 0;				//计数器
		  for (int i = 0; i < G.vexnum; ++i)
		  {
					if (indegree[i] == 0)			  //寻找入度为0的顶点
					{
							  Push_Stack(&stack, G.Vetics[i].data);	  //入栈
					}
		  }
		  while (!isEmpty(stack))
		  {
					VertexType temp;
					Pop_Stack(&stack, &temp);
					printf("%c--->", temp);
					counter++;
					for (int pos = FindFirstNeighbor(G, temp); pos != -1; pos = FindNextNeighbor(G, temp, G.Vetics[pos].data))
					{
							  if (!(--indegree[pos]))			//当前顶点入边为0
							  {
										Push_Stack(&stack, G.Vetics[pos].data);	  //入栈
							  }
					}
		  }
		  printf("END\n");
		  DestroyTopologicalArray(indegree);
		  return ((counter == G.vexnum) ? TRUE : FALSE);
}