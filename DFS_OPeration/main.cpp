#include <iostream>
#include <vector>
using namespace std;

int cycle=0;

void dfs(vector<int>v[],bool visited[],int s,int parent[])
{
    if(visited[s]==false)
    {

        visited[s]=true;


        for(int i=0; i<v[s].size(); i++)
        {
            int m=v[s][i];

            if(visited[m]==false)
            {
                parent[m]=s;
                dfs(v,visited,m,parent);
            }
            else
            {
                if(s!=parent[m])
                {
                    cycle++;
                }
            }
        }
    }

    cout<<s<< " ";

}

int main()
{
    int n,e;

    cin>>n;
    cin>>e;

    vector<int>node[n];

    for(int i=0; i<e; i++)
    {
        int a,b;
        cin>>a>>b;
        node[a].push_back(b);


    }
    bool visited[n]= {false};
    int parent[n];

    int c=0;
    for(int i=0; i<n; i++)
    {
        if(visited[i]==false)
        {
             c++;
            dfs(node,visited,i,parent);
            cout<<endl;

        }
    }

    cout<<endl;
    cout<< "the number of connected component : "<<c<<endl;

    if(cycle>0)
    {
        cout<< "The graph has cycle"<<endl;
    }
    else
    {
        cout<< "The graph has no cycle"<<endl;
    }

    return 0;

}

/*

6 6
0 1
0 3
3 2
1 2
4 1
4 5

*/
