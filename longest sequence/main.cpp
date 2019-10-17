#include <iostream>
#include <algorithm>
#include <unordered_map>
#define N 5
using namespace std;

string findlength(int mat[N][N],int i,int j)
{

    if(i<0&&j<0&&i>=N&&j>=N)
        return "";
    string path;
    string key;
    unordered_map<string,string>mp;

    key=to_string(i)+"|"+to_string(j);

    if(mp.find(key)==mp.end())
    {
        if(i>0&&mat[i-1][j]+1==mat[i][j])
            path=findlength(mat,i-1,j);

        if(j>0&&mat[i][j-1]+1==mat[i][j])
            path=findlength(mat,i,j-1);

        if(i+1<N&&mat[i+1][j]+1==mat[i][j])
            path=findlength(mat,i+1,j);

        if(j+1<N&&mat[i][j+1]+1==mat[i][j])
            path=findlength(mat,i,j+1);

        mp[key]=to_string(mat[i][j])+" - "+path;
    }

return mp[key];
}

int main()
{
    int mat[N][N] =
    {
        { 10, 13, 14, 21, 23 },
        { 11,  9, 22,  2,  3 },
        { 12,  8,  1,  5,  4 },
        { 15, 24,  7,  6, 20 },
        { 16, 17, 18, 19, 25 }
    };


    int rs=0;
    string result="";
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            string s=findlength(mat,i,j);

            int x=count(s.begin(),s.end(),'-');

            if(x>rs)
            {
                rs=x;
                result=s;
            }
        }
    }
    reverse(result.begin(),result.end());
    cout<< result.substr(3,result.length());

    return 0;
}
