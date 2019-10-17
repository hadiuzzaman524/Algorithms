#include <iostream>
#define M 8
#define N 6
using namespace std;
int findsquare(int mat[M][N])
{
    int table[M+1][N+1];

    for(int i=0; i<=M; i++)
    {
        table[M][0]=0;
    }
    for(int j=0; j<=N; j++)
    {
        table[0][N]=0;
    }

    int maximum=0;


    for(int i=1; i<=M; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(mat[i-1][j-1]==0)
            {
                table[i][j]=0;
            }
            else
            {
                table[i][j]=min(table[i-1][j],min(table[i-1][j-1],table[i][j-1]))+1;
            }
            maximum=max(maximum,table[i][j]);

        }



    }
    return maximum;
}

int main()
{
    int mat[M][N] =
    {
        { 0, 0, 1, 0, 1, 1 },
        { 0, 1, 1, 1, 0, 0 },
        { 0, 0, 1, 1, 1, 1 },
        { 1, 1, 0, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1 },
        { 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1 }
    };

    int z=findsquare(mat);
    cout<< z<<endl;
    return 0;
}
