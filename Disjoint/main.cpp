#include <iostream>
#include <vector>
using namespace std;
vector<int>v[9];
class Node
{
public:
    int parent,rankk;
};

void makeset(Node obj[],int x)
{
    obj[x].parent=x;
    obj[x].rankk=0;
    return ;
}

int findset(Node obj[],int x)
{
    if(obj[x].parent!=x)
        obj[x].parent= findset(obj,obj[x].parent);

    return obj[x].parent;
}

void link(Node obj[],int x,int y)
{
    if(obj[x].rankk>obj[y].rankk)
    {
        obj[y].parent=x;
        v[x].push_back(y);
    }
    else
    {
        obj[x].parent=y;
        v[y].push_back(x);

        if(obj[x].parent==obj[y].parent)
            obj[y].rankk++;
    }
}
void SetUnion(Node obj[],int x,int y)
{
    int u=findset(obj,x);
    int v=findset(obj,y);

    if(u !=v)
        link(obj,u,v);
    else
    {
        cout<< "the graph has a cycle"<<endl;
        return ;
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

    for(int i=0; i<n; i++)
    {
        cout<< "vartex: "<< i<< endl;
        cout<< "parent: "<< obj[i].parent<< endl;
        //cout<< "rank : "<< obj[i].rankk<<endl;
        cout<<endl;
    }
    int c=0;

    for(int i=0; i<n; i++)
    {


        cout<<endl;
        if(v[i].size()>0)
        {
            c++;
            cout<< i<< " :";
        }

        for(int j=0; j<v[i].size(); j++)
        {
            cout<<v[i][j]<< " ";

        }
    }
    cout<<endl<< "Total connected component in this graph is: "<<c<<endl;

    return 0;
}
