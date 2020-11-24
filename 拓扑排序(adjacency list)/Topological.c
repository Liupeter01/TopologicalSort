#include"Topological.h"

void InitTopologicalArray(ALGraph G, int** indegree)			//��������ĳ�ʼ������
{
		  *indegree = (int*)malloc(sizeof(int) * G.vexnum);//������������Ŀռ�
		  assert(*indegree != NULL);
		  memset(*indegree, 0, sizeof(int) * G.vexnum);

		  for (int i = 0; i < G.vexnum; ++i)				//����ÿ����������
		  {
					(*indegree)[i] = CalculateEnVertex(G, G.Vetics[i].data);
		  }
}

void DestroyTopologicalArray(int* indegree)		  //����������ڴ����ٴ���
{
		  free(indegree);
}

BOOL TopologicalSort(ALGraph G)			  //��������ִ�еı������
{
		  LinkStack stack;	 
		  InitLinkStack(&stack);		 //ջ�ĳ�ʼ��
		  int* indegree = NULL;			
		  InitTopologicalArray(G, &indegree);	  //�洢ÿһ��������������
		  int counter = 0;				//������
		  for (int i = 0; i < G.vexnum; ++i)
		  {
					if (indegree[i] == 0)			  //Ѱ�����Ϊ0�Ķ���
					{
							  Push_Stack(&stack, G.Vetics[i].data);	  //��ջ
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
							  if (!(--indegree[pos]))			//��ǰ�������Ϊ0
							  {
										Push_Stack(&stack, G.Vetics[pos].data);	  //��ջ
							  }
					}
		  }
		  printf("END\n");
		  DestroyTopologicalArray(indegree);
		  return ((counter == G.vexnum) ? TRUE : FALSE);
}