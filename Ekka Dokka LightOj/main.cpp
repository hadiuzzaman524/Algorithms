#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int testcase;
    cin>>testcase;

    long long w;
    long long odd;
    long long even;
    int m=0;
    while(testcase--)
    {

     cin>>w;
     cout<< "Case "<<++m<< ": ";
     if(w%2!=0)
     {
         cout<< "Impossible"<<endl;
         continue;
     }
     odd=w/2;
     even=2;

     while(odd%2==0)
     {
         odd/=2;
         even*=2;
     }
     cout<< odd<< " "<< even<<endl;

    }

    return 0;
}

