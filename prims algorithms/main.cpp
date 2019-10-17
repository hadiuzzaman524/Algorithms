#include <iostream>
#define inf 9999
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int number,parent,key;
    vector <pair<int,int> >adj;
    bool mst;

    bool operator<(const Node &obj)const
    {
        return key > obj.key;
    }
};

int main()
{
    int vertex,edges;
    cout<< "how many vertex and edges? ";
    cin>>vertex>>edges;

    Node node[vertex];

    for(int i=0; i<vertex; i++)
    {
        node[i].key=inf;
        node[i].number=i;
        node[i].parent=-1;
        node[i].mst=false;
    }
    for(int i=0; i<edges; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        node[u].adj.push_back(make_pair(v,w));
        node[v].adj.push_back(make_pair(u,w));
    }

    int r;
    cin>>r;

    node[r].key=0;

    priority_queue <Node> pq;

    pq.push(node[r]);

    cout<< "Selected edges are: "<<endl;
    int mstweight=0;
    while(!pq.empty())
    {
        int u=pq.top().number;
        pq.pop();

        if(node[u].mst==false)
        {
            node[u].mst=true;

            mstweight+=node[u].key;

            if(node[u].parent !=-1)
            {
                cout<< node[u].parent<< " "<< node[u].number<<endl;
            }

            for(int i=0; i<node[u].adj.size(); i++)
            {
                int v,w;
                v=node[u].adj[i].first;
                w=node[u].adj[i].second;


                if((node[v].mst==false)&& w<node[v].key)
                {
                    node[v].key=w;//dijkstra
                    node[v].parent=node[u].number;
                    pq.push(node[v]);
                }
            }
        }

    }
    cout<< "minimum cost: "<< mstweight<< endl;

    return 0;
}
/*
9 13
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/
