#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int>v[],bool visited[],int s)
{
    if(visited[s]==false)
      {



        visited[s]=true;


        for(int i=0; i<v[s].size(); i++)
        {
            int m=v[s][i];

            if(visited[m]==false)
            {
                dfs(v,visited,m);
            }
        }
      }

    cout<<s<< " ";

}

int main()
{
    int n,e;
    cout<< "how many vertex: ";
    cin>>n;
    cout<< "how many edge: ";
    cin>>e;

    vector<int>node[n];

    for(int i=0; i<e; i++)
    {
        int a,b;
        cin>>a>>b;
        node[a].push_back(b);
        //node[b].push_back(a);

    }
    bool visited[n]= {false};

    // int c=0;
    for(int i=0; i<n; i++)
    {
        if(visited[i]==false)
        {
            dfs(node,visited,i);
            //c++;
        }
    }
//cout<< "the number of connected component : "<<c<<endl;
    return 0;

}
/*

0 1
0 3
3 2
1 2
4 1
4 5

*/
