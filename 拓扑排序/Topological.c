#include"Topological.h"

void InitTopologicalArray(MGraph G, int** indegree)			//拓扑排序的初始化代码
{
		  *indegree = (int*)malloc(sizeof(int) * G.vexnum);	//初始化入度数组
		  assert(*indegree != NULL);
		  memset(*indegree, 0, sizeof(int) * G.vexnum);
		  for (int i = 0; i < G.vexnum; ++i)
		  {
					(*indegree)[i] = CalculateEnVertex(G, G.Vex[i]);  //入读计算函数
		  }
}

void DestroyTopologicalArray(int* indegree)		  //拓扑排序的内存销毁代码
{
		  free(indegree);
}

BOOL TopologicalSort(MGraph G)				  //拓扑排序执行的本体代码
{
		  LinkStack stack;
		  InitLinkStack(&stack);		//初始化栈

		  int* indegree = NULL;			//入度数组
		  InitTopologicalArray(G, &indegree);
		  int counter = 0;	  //计数器
		  for (int i = 0; i < G.vexnum; ++i)
		  {
					if (indegree[i] == 0)		    //寻找入度为0的顶点
					{
							  Push_Stack(&stack, G.Vex[i]);
					}
		  }
		  while (!isEmpty(stack))
		  {
					VertexType temp;
					Pop_Stack(&stack, &temp);
					printf("%c", temp);
					++counter;
					for (int pos = FindFirstNeighbor(G, temp); pos != -1; pos = FindNextNeighbor(G, temp, G.Vex[pos]))
					{
							  if (!(--indegree[pos]))		//当前顶点入边为0
							  {
										Push_Stack(&stack, G.Vex[pos]);
							  }
					}
		  }
		  printf("END\n");
		  DestroyTopologicalArray(indegree);
		  return((counter == G.vexnum) ? TRUE : FALSE);
}