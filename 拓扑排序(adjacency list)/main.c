#include"ALGraph.h"
#include"DirectEdge.h"       //有向图
#include"UnDirectEdge.h"    //无向图
#include"Topological.h"       //拓扑排序

typedef struct Pair
{
          VertexType Vex1;        //顶点
          VertexType Vex2;        //顶点
         // int distance;                 //距离
}Pair;

int main()
{
          ALGraph Graph;
          InitGraph(&Graph);         //初始化

          VertexType arr[] = { "ABCDEF" };
          CreateBatchVertex(&Graph, arr);      //顶点列表批量添加

          Pair pair[] = {
                    {'A','B' },
                     {'A','D' },
                      {'A','C' },
                       {'C','B' },
                        {'C','E' },
                         {'D','E' },
                          {'F','D' },
                           {'F','E' }
          };                  //边配对表

          for (int i = 0; i < sizeof(pair) / sizeof(Pair); ++i)
          {
                    InsertDirectEdge(&Graph, pair[i].Vex1, pair[i].Vex2);
          }

          DisplayGraph(Graph);

          TopologicalSort(Graph);       //拓扑排序

          DestroyGraph(&Graph);         //图的销毁
          return 0;
}