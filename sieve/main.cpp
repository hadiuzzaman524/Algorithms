#include <iostream>

using namespace std;

void sieve(bool marked[],int n)
{
    for(int i=2; i*i<=n; i++)
    {
        if(marked[i]==false)
        {
            for(int j=i*i; j<=n; j+=i)
            {
                marked[j]=true;
            }
        }
    }
}

int main()
{
    bool marked[100]={false};
    sieve(marked,100);

    for(int i=2; i<100; i++)
    {
        if(marked[i]==false)
            cout<< i<<" ";
    }
    return 0;
}
