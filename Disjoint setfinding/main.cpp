#include <iostream>
#define endl "\n"
using namespace std;
class Node
{
public:
    int parent,rankk;

};

void makeset(Node obj[],int x)
{
    obj[x].parent=x;
    obj[x].rankk=0;

}


int findset(Node obj[],int x)
{
    if(obj[x].parent!=x)
        obj[x].parent=findset(obj, obj[x].parent);
    return obj[x].parent;
}


void link(Node obj[],int x,int y)
{
    if(obj[x].rankk>obj[y].rankk)
    {
        obj[y].parent=x;

    }
    else
    {
        obj[x].parent=y;
        if(obj[x].parent==obj[y].parent)
        {
            obj[y].rankk++;
        }


    }

}


void union_op(Node obj[],int x,int y)
{
    int u=findset(obj,x);
    int v=findset(obj,y);

    if(u!=v)
    {
        link(obj,u,v);
    }
}

int main()
{

    freopen("input.txt","r",stdin);
    int n,e;
    // cout<< "how many node and edge? ";
    cin>>n>>e;

    Node obj[n];

    for(int i=0; i<n; i++)
    {
        makeset(obj,i);
    }

    for(int i=0; i<e; i++)
    {
        int u,v;
        // cout<< "enter Edge "<< i+1<< " :";
        cin>>u>>v;

        union_op(obj,u,v);

    }

    for(int i=0; i<n; i++)
    {

        cout<< "vartex: "<<i<<endl;
        cout<<"Parent: "<<obj[i].parent<< endl;
        cout<< "Rank: "<< obj[i].rankk<< endl;

        cout<<endl;
    }

    return 0;
}
