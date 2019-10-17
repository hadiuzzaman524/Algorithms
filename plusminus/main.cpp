#include <iostream>
#include <vector>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    int t;
    long long n,m,jaman=0;
    cin>>t;
    while(t--)
    {

        cin>>n>>m;
        cout<<"Case "<<++jaman<< ": "<< (m*n)/2<<endl;
    }
    return 0;
}
