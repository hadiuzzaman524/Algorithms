#include <iostream>
#define inf 99999
#define na -1
#include <vector>
using namespace std;

void print(vector< vector<int> >path, int i,int j)
{
    if(path[i][j]==-1)
    {
        cout<< "no path"<<endl;
        return;
    }

    if(path[i][j]==i)
        cout<< i<< " ";

    if(path[i][j]!=i)
    {
        print(path,i,path[i][j]);

        cout<< j<<" ";
    }

}


int main()
{
    int v, e;
    cout << "how many vertex and edges? ";
    cin >> v >> e;

    //int dis[v][v];
    // int path[v][v];
    vector< vector<int> >dis(v,vector<int>(v));
    vector< vector<int> >path(v,vector<int>(v));


    for(int i=0; i<v; i++)
        for(int j=0; j<v; j++)
            dis[i][j]=inf;


    for(int i=0; i<v; i++)
        for(int j=0; j<v; j++)
            path[i][j]=na;

    for(int i=0; i<v; i++)
        path[i][i]=i;

    for(int i=0; i<v; i++)
    {
        dis[i][i]=0;
    }

    cout<< "Path matrix: "<<endl<<endl;

    //get input...
    for(int i=0; i<e; i++)
    {
        int m,n,w;
        cin>>m>>n>>w;

        dis[m][n]=w;

        path[m][n] = m;
    }


    for(int k=0; k<v; k++)
    {
        for(int i=0; i<v; i++)
        {
            for(int j=0; j<v; j++)
            {
                if(dis[i][j] > dis[i][k]+dis[k][j])
                {
                    dis[i][j]=dis[i][k]+dis[k][j];

                    path[i][j]=k;//path[k][j];

                }
            }
        }
    }

    cout<< "Distance matrix: "<<endl<<endl;
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            cout<< dis[i][j]<< " ";
        }
        cout<<endl;

    }
    cout<<endl;

    cout<< "Path matrix: "<<endl<<endl;

    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            cout<< path[i][j]<< " ";
        }
        cout<<endl;

    }

    int x=0,y=3;
    cout<< "path from : "<< x<< " To "<< y<< " is: "<<endl;

    print(path,x,y);

    return 0;
}

/*
4 6
0 1 3
0 2 6
0 3 15
1 2 -2
2 3 2
3 0 1


*/
