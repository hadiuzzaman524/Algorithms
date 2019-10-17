#include <iostream>
#include <string>
#include <string.h>
#define endl "\n"
using namespace std;

int length1,length2;
int table[100][100];

void editdistance(string x,string y)
{
    length1=x.length();
    length2=y.length();


    for(int i=0; i<=length1; i++)
    {
        table[i][0]=i;
    }

    for(int j=0; j<=length2; j++)
    {
        table[0][j]=j;

    }

    for(int i=1; i<=length1; i++)
    {
        for(int j=1; j<=length2; j++)
        {
            if(x[i-1]==y[j-1])
            {
                table[i][j]=table[i-1][j-1];
            }
            else
            {
                table[i][j]=min(min(table[i-1][j],table[i][j-1]),table[i-1][j-1])+1;

            }
        }
    }


}


void print(string x,string y)
{

    int i=length1;
    int j=length2;
    int k=0;
    cout<<table[i][j]<<endl;
    while(i||j)
    {
        if(x[i-1]==y[j-1])
        {
            i--;
            j--;
            continue;
        }
        cout<<++k<< " ";

        if(j>0 && table[i][j-1]+1==table[i][j])
        {

            cout<< "Insert "<<i+1<< ","<<y[j-1];

            x.insert(i,1,y[j-1]);
            j--;
        }
        else if(i>0&&j>0&& table[i-1][j-1]+1==table[i][j])
        {

            cout<< "Replace "<<i<< "," <<y[j-1];
            x[i-1]=y[j-1];
            i--;
            j--;
        }
        else if(i>0&&table[i-1][j]+1==table[i][j])
        {
            cout<< "Delete "<<i;
            x.erase(i-1,1);
            i--;
        }
        putchar('\n');
    }
}

int main()
{
    string x,y;
    bool flag=false;
    char str[100];
    while(gets(str))
    {
        x=str;
        getline(cin,y);

        editdistance(x,y);
        if(flag)
            putchar('\n');
        flag=true;
        print(x,y);



    }
    return 0;
}
