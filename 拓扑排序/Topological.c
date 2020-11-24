#include"Topological.h"

void InitTopologicalArray(MGraph G, int** indegree)			//��������ĳ�ʼ������
{
		  *indegree = (int*)malloc(sizeof(int) * G.vexnum);	//��ʼ���������
		  assert(*indegree != NULL);
		  memset(*indegree, 0, sizeof(int) * G.vexnum);
		  for (int i = 0; i < G.vexnum; ++i)
		  {
					(*indegree)[i] = CalculateEnVertex(G, G.Vex[i]);  //������㺯��
		  }
}

void DestroyTopologicalArray(int* indegree)		  //����������ڴ����ٴ���
{
		  free(indegree);
}

BOOL TopologicalSort(MGraph G)				  //��������ִ�еı������
{
		  LinkStack stack;
		  InitLinkStack(&stack);		//��ʼ��ջ

		  int* indegree = NULL;			//�������
		  InitTopologicalArray(G, &indegree);
		  int counter = 0;	  //������
		  for (int i = 0; i < G.vexnum; ++i)
		  {
					if (indegree[i] == 0)		    //Ѱ�����Ϊ0�Ķ���
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
							  if (!(--indegree[pos]))		//��ǰ�������Ϊ0
							  {
										Push_Stack(&stack, G.Vex[pos]);
							  }
					}
		  }
		  printf("END\n");
		  DestroyTopologicalArray(indegree);
		  return((counter == G.vexnum) ? TRUE : FALSE);
}