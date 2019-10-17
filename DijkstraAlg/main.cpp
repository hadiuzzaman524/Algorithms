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

    int r=0;

    node[r].key=0;

    priority_queue <Node> pq;

    pq.push(node[r]);

    cout<< "The cost of the source "<< r<< " to Destination is: "<<endl;

    while(!pq.empty())
    {
        node ob=pq.top();

        int u=ob.number;

        pq.pop();

        if(node[u].mst==false)
        {
            node[u].mst=true;

            if(node[u].parent !=-1)
            {
                cout<<node[u].number<<" ---> "<< node[u].key<<endl;
            }

            for( int i=0; i<node[u].adj.size(); i++)
            {
                int v,w;
                v=node[u].adj[i].first;
                w=node[u].adj[i].second;


                if((node[v].mst==false)&& node[u].key+w < node[v].key)
                {

                    node[v].key=node[u].key+w;

                    node[v].parent=node[u].number;
                    pq.push(node[v]);
                }
            }
        }

    }

    return 0;
}
/*
9 14
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


6 9
0 1 4
0 2 1
1 2 3
1 3 3
1 4 7
2 4 2
3 4 5
3 5 2
4 5 6

*/
