#include <iostream>
#include <string>
using namespace std;
int len1,len2;
int table[22][22];

void maketable(string s1,string s2)
{
    int i,j;
    for(i=0; i<=len1; i++)
        table[i][0]=i;

    for(i=0; i<=len2; i++)
        table[0][i]=i;

    for(i=1; i<=len1; i++)
    {
        for(j=1; j<=len2; j++)
        {
            if(s1[i-1]==s2[j-1])
                table[i][j]=table[i-1][j-1];
            else
                table[i][j]=min(table[i-1][j-1],min(table[i-1][j],table[i][j-1]))+1;
        }
    }
}



void print(string s1,string s2)
{
    int i=len1,j=len2;
    while(i || j)
    {
        if(s1[i-1]==s2[j-1])
        {
            i--;
            j--;
            continue;
        }
        if(j>0 && (table[i][j]==table[i][j-1]+1))
        {
            cout<<"I"<<s2[j-1];
            if(i<=8)
                cout<<"0";
            cout<<i+1;
            j--;
        }
        else if(i>0 && j>0 && (table[i][j]==table[i-1][j-1]+1))
        {
            cout<<"C"<<s2[j-1];
            if(i<=9)
                cout<<"0";
            cout<<i;
            i--;
            j--;
        }

        else if(i>0)
        {
            cout<<"D"<<s1[i-1];
            if(i<=9)
                cout<<"0";
            cout<<i;
            i--;
        }
    }
    cout<<"E"<<endl;
}

int main()
{
    string x,y;
    while(cin>>x)
    {
        if(x[0]=='#')
            break;
        cin>>y;
        len1=x.length();
        len2=y.length();

        maketable(x,y);
        print(x,y);

    }



    return 0;
}
