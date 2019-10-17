#include <iostream>

using namespace std;
class Node
{
public:
    int parent;
};

void makeset(Node obj[],int i)
{
    obj[i].parent=i;
    return;
}
int findset(Node obj[],int x)
{
    if(obj[x].parent!=x)

       return findset(obj,obj[x].parent);

}

void SetUnion(Node obj[],int x,int y)
{
    int u=findset(obj,x);
    int v=findset(obj,y);

    if(u!=v)
    {
        obj[v].parent=u;

    }
}
int main()
{
    freopen("input.txt","r",stdin);
    int n,e;
    //  cout<< "how many node and edges of the graph? ";
    cin>>n>>e;

    Node obj[n];
    for(int i=0; i<n ; i++)
    {
        makeset(obj,i);
    }
    for(int i=0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        SetUnion(obj,u,v);
    }

    for(int i=0;i<n; i++)
    {
        cout<< "vartex: "<<i<< " Parent: "<<obj[i].parent<<endl;

    }



    return 0;
}
