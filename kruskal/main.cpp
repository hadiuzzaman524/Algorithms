#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int>vc;

class Node
{
public:
    int rankk,parent;
};

class Edge
{
public:
    int source,dest,weight;
};

bool comp(Edge obj1,Edge obj2)
{
    if(obj1.weight !=obj2.weight)

        return obj1.weight < obj2.weight;
}

void makeset(Node obj[],int x)
{
    obj[x].parent=x;
    obj[x].rankk=0;

    return ;
}
int findset(Node obj[],int x)
{
    if(obj[x].parent !=x)

        obj[x].parent=findset(obj,obj[x].parent);

        return obj[x].parent;


}
void setunion(Node obj[],int x,int y)
{
    if(obj[x].rankk > obj[y].rankk)
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

int kruskal(Node obj[],Edge ed[],int n,int e)
{
    int mincost=0;

    for(int i=0; i<n; i++)
    {
        makeset(obj,i);
    }
    sort(ed,ed+e,comp);

    for(int i=0; i<e; i++)
    {
        int x=ed[i].source;
        int y=ed[i].dest;


        int parent_x=findset(obj,x);

        int parent_y=findset(obj,y);

        if(parent_x !=parent_y)
        {
            setunion(obj, parent_x,parent_y);
            mincost+=ed[i].weight;
            vc.push_back(i);

        }
    }
    return mincost;

}
int main()
{
    int n,e;
    cin>>n>>e;

    Node obj[n];
    Edge edj[e];

    for(int i=0; i<e; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;


        edj[i].source=u;
        edj[i].dest=v;
        edj[i].weight=w;



    }

    int z=kruskal(obj,edj,n,e);


    cout<< "selected item are: "<<endl<<endl;
    for(int i=0; i<vc.size(); i++)
    {
       int x=vc[i];

       cout<< edj[x].source<< " "<< edj[x].dest<< " : "<< edj[x].weight<< endl;
    }
    cout<<endl;
    cout<<"total cost: "<<  z<<endl;


    return 0;
}
