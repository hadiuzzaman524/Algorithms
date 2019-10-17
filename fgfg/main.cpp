#include <bits/stdc++.h>
#define inf 9999
using namespace std;
class Node
{
public:

    int parent,number,key;

    vector< pair<int,int> >adj;

    bool inMST;

    bool operator<(const Node &obj)const
    {
        return key > obj.key;
    }


};

int main()
{
    int vertex,edges;
    cout<< "how many vertex and edges? ";
    cin>>vertex>> edges;
    Node node[vertex];
    for(int i=0; i<vertex; i++)
    {
        node[i].key=inf;
        node[i].parent=-1;
        node[i].number=i;
        node[i].inMST=false;
    }



    for(int i=0; i<edges; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        node[u].adj.push_back(make_pair(v,w));
        node[v].adj.push_back(make_pair(u,w));
    }

    int r;
    cout<< "Enter the starting vertex: ";
    cin>>r;

    node[r].key=0;

    priority_queue<Node> pq;

    pq.push(node[r]);

    cout<< "Selected edges are: ";
    int mstweight=0;

    while(!pq.empty())
    {
        int u=pq.top().number;
        pq.pop();

        if(node[u].inMST==false)
        {
            node[u].inMST=true;

            mstweight+=node[u].key;

            if(node[u].parent!=-1)
            {
                cout<< node[u].parent<< "-"<< node[u].number<< endl;
            }

            for(int i=0; i< node[u].adj.size(); i++)
            {
                int v,w;
                v=node[u].adj[i].first;
                w=node[u].adj[i].second;

                if((node[v].inMST==false)&& (w<node[v].key))
                {
                    node[v].key=w;
                    node[v].parent=node[u].number;
                    pq.push(node[v]);
                }
            }



        }
    }
    cout<< mstweight<< endl;

    return 0;
}
