#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int>result;

class Node
{
public:
    int rankk,parent;
};


class Edge
{
public:
    int weight,source,dest;
};


bool comp(Edge obj1,Edge obj2)
{
    if(obj1.weight !=obj2.weight)
        return obj1.weight<obj2.weight;
}

void makeset(Node obj[],int i)
{
    obj[i].parent=i;
    obj[i].rankk=0;
}


int findset(Node obj[],int x)
{
    if(obj[x].parent !=x)

        obj[x].parent=findset(obj, obj[x].parent);
    return obj[x].parent;


}


void setunion(Node obj[],int x,int y)
{
    if(obj[x].rankk>obj[y].rankk)
    {
        obj[y].parent=x;
    }
    else
    {
        obj[x].parent=y;
        if(obj[x].rankk==obj[y].rankk)
            obj[y].rankk++;
    }
}
int kruskal(Node v[],Edge e[],int no,int ed)
{
    int mstw=0;
    for(int i=0; i<no; i++)
    {
        makeset(v,i);
    }
    sort(e,e+ed,comp);

    for(int i=0; i<ed; i++)
    {
        int x=e[i].source;
        int y=e[i].dest;

        int parent_x=findset(v,x);
        int parent_y=findset(v,y);

        if(parent_x !=parent_y)
        {
            setunion(v,parent_x,parent_y);
            result.push_back(i);
            mstw+=e[i].weight;
        }
    }

    return mstw;
}


int main()
{ freopen("input.txt","r",stdin);
    int vertex,edges;
   // cout<< "how many vertex and edges? ";
    cin>>vertex>>edges;

    Node obj[vertex];

    Edge edj[edges];

    for(int i=0; i<edges; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        edj[i].source=u;
        edj[i].dest=v;
        edj[i].weight=w;

    }
    int z=kruskal(obj,edj,vertex,edges);

    cout<< "minimum cost is: "<<z<<endl;

    cout<< "selected edges are: "<<endl;

    for(int i=0; i<result.size(); i++)
    {
        int x=result[i];

        cout<< edj[x].source<< " - "<< edj[x].dest<< " : "<< edj[x].weight<<endl;
    }


    return 0;
}
