#include <iostream>
#define inf 9999
using namespace std;

int path[50][50];
int dist[50][50];

void print(int i,int j)
{
    if(path[i][j]==-1)
    {
        cout<< "NO path available."<<endl;
        return ;
    }
    if(path[i][j]==i)
    {
        cout<< i<< " ";
    }
    else if(path[i][j] !=i)
    {
        print(i,path[i][j]);

        cout<< j << " ";

    }
    return ;
    /*
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if(i!=j)
                printf("\n %d --- %d : %d",i,j,dist[i][j]);
    }
    */
}


int main()
{
    int n,e;
    cout<< "how many vertex and edges? ";
    cin>>n>>e;

    //int dist[n][n];

    //initialize...
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j)
            {
                dist[i][j]=0;
                path[i][j]=j;
            }
            else
            {
                dist[i][j]=inf;
                path[i][j]=-1;
            }
        }
    }


    for(int i=0; i<e; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=w;
        path[u][v]=u;
    }

    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    path[i][j]=k;
                }
            }
        }
    }

    cout<< "Distance matrix "<<endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<< dist[i][j]<< " ";
        }
        cout<<endl;
    }
    cout<<endl;

    cout<< "Path matrix is: "<<endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<< path[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    cout<< "The path is: "<<endl;
   // print(n);

   print(0,3);

    return 0;
}

