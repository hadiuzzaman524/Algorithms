#include <iostream>
#include <vector>
#include <queue>
#define inf 99999
using namespace std;

class Node
{
public:
    int parent,number,key;
    bool mst;
    vector< pair<int,int> >adj;

    bool operator<(const Node &ob)const
    {
        return key>ob.key;
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
        node[i].parent=-1;
        node[i].number=i;
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
    cout<< "Enter the starting node: ";
    cin>>r;

    node[r].key=0;

    priority_queue <Node> pq;
    pq.push(node[r]);

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
                cout<< node[u].parent<< " "<< node[u].number<< endl;
            }

            for(int i=0; i<node[u].adj.size(); i++)
            {
                int v,w;
                v=node[u].adj[i].first;
                w=node[u].adj[i].second;

                if((node[v].mst==false)&&(w<node[v].key))
                {
                    node[v].key=w;
                    node[v].parent=node[u].number;
                    pq.push(node[v]);
                }
            }
        }
    }

    cout<< "Minimum cost is: "<< mstweight<<endl;

    return 0;
}
