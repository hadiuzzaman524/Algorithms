#include <iostream>
#define M 5
#define N 5
using namespace std;

int table[M][N];

int findminimum_cost(int cost[M][N])
{


    table[0][0]=cost[0][0];

    for(int i=1; i<M; i++)
    {
        table[i][0]=cost[i][0]+table[i-1][0];
    }


    for(int j=1; j<N; j++)
    {
        table[0][j]=cost[0][j]+table[0][j-1];
    }

    for(int i=1; i<M; i++)
    {
        for(int j=1; j<N; j++)
        {
            table[i][j]=min(table[i-1][j],table[i][j-1])+cost[i][j];
        }
    }

    return table[M-1][N-1];

}
void print_path(int cost[M][N])
{
    int i=M-1;
    int j=N-1;

    while(i>=0&&j>=0)
    {


        if(table[i][j]==table[i-1][j]+cost[i][j])
        {
            cout<<cost[i][j]<< " ";
            i--;
        }


        else if(table[i][j]==table[i][j-1]+cost[i][j])
        {
            cout<< cost[i][j]<< " ";
            j--;
        }


        else
        {
            cout<< cost[i][j]<< " ";
            i--;
            j--;
        }


    }


}

int main()
{

    int cost[M][N] =
    {
        { 4, 7, 8, 6, 4 },
        { 6, 7, 3, 9, 2 },
        { 3, 8, 1, 2, 4 },
        { 7, 1, 7, 3, 7 },
        { 2, 9, 8, 9, 3 }
    };

    int c=findminimum_cost(cost);
    cout<< "Minimum cost is: "<<c<<endl;
    cout<< "Selected values are: "<<endl;
    print_path(cost);
    cout<<endl;

    return 0;
}
