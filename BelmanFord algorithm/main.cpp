#include <iostream>
#define inf 99999
#include <vector>
#include <utility>
using namespace std;

class Node
{
public:
    int key,parent,number;
    bool mst;

    vector<int,pair<int,int> >adj;
    bool operator<(const Node &obj)
    {
        return key>obj.key;
    }
};
void Relax(Node node[],int u,int v,int w)
{
  //if(node[v].key > node[u].key + node[v].key)
}
int main()
{
    int n,e;
    cout<< "how many vertex and edges? ";
    cin>>n>>e;

    Node node[n];
    for(int i=0; i<n; i++)
    {
        node[i].key=inf;
        node[i].number=i;
        node[i].mst=false;
        node[i].parent=-1;
    }

    for(int i=0;i<e; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        node[u].adj.push_back(make_pair(v,w));
        node[v].adj.push_back(make_pair(u,w));
    }

    int s=0;
    node[s].key=0;
    priority_queue pq;
    pq.push(node[s]);


    return 0;
}
