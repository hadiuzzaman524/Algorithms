#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


string s1,s2;
int len1,len2,table[22][22];


void buildTable()
{
    int i,j;
    for(i=0; i<=len1; i++)
        table[i][0]=i;
    for(j=0; j<=len2; j++)
        table[0][j]=j;

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

    for(int i=0;i<=len1; i++)
    {
        for(int j=0; j<=len2; j++)
        {
            cout<< table[i][j]<< " ";
        }
        cout<<endl;
    }
}


void result()
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
    //freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    while(cin>>s1)
    {
        if(s1[0]=='#')
            break;
        cin>>s2;
        len1=s1.size();
        len2=s2.size();
        buildTable();
       // result();
    }
    return 0;
}
