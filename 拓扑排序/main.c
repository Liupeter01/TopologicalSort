#include"MGraph.h"
#include"DirectedEdge.h"                   //����ͼ
#include"UnDirectedEdge.h"              //����ͼ
#include"Topological.h"                      //��������

typedef struct Pair
{
          VertexType Vex1;        //����
          VertexType Vex2;        //����
         // int distance;                 //����
}Pair;

int main()
{
          MGraph Graph;
          InitGraph(&Graph);         //��ʼ��

          /*�����б��������*/
          VertexType arr[] = { "ABCDEF" };
          CreateBatchVertex(&Graph, arr, NORMALGRAPH);      //�����б��������

          Pair pair[] = {
                    {'A','B' },
                     {'A','D' },
                      {'A','C' },
                       {'C','B' },
                        {'C','E' },
                         {'D','E' },
                          {'F','D' },
                           {'F','E' }
          };                  //����Ա�

          for (int i = 0; i < sizeof(pair) / sizeof(Pair); ++i)
          {
                    InsertDirectEdge(&Graph, pair[i].Vex1, pair[i].Vex2);
          }

          DisplayGraph(Graph);          //ͼ�����

          TopologicalSort(Graph);       //��������

          DestroyGraph(&Graph);         //ͼ������
          return 0;
}