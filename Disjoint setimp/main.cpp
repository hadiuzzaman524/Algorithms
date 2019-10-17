#include <iostream>
#include <iomanip>

using namespace std;


class Node
{
public:
    int rankk;
    int parent;
};


void makeset(Node obj[],int i)
{
    obj[i].parent=i;
    obj[i].rankk=0;
    return ;
}


int findset(Node obj[],int x)
{
    if(obj[x].parent !=x)

        obj[x].parent=findset(obj,obj[x].parent);

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


void setunion(Node obj[],int x,int y)
{
    int parent_x=findset(obj,x);
    int parent_y=findset(obj,y);

    if(parent_x !=parent_y)
    {
        link(obj,parent_x,parent_y);
    }
}


int main()
{ freopen("input.txt","r",stdin);
    int n,e;
   // cout<< "how many node and edges? ";
    cin>>n>>e;

    Node obj[n];
    for(int i=0; i<n; i++)
    {
        makeset(obj,i);
    }
    for(int i=0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        setunion(obj,u,v);
    }

    for(int i=0; i<n; i++)
    {
        cout<< "vertex : "<< i<<endl;

        cout<< "Parent : "<< obj[i].parent<<endl;
        cout<< "Rank :   "<< obj[i].rankk<<endl;
        cout<<endl;
    }

    return 0;
}

