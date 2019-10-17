#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;



int main()
{
   // freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);

    unsigned long long fact[21];
    fact[0]=1;

    for(int i=1; i<21; i++)
    {
        fact[i]=fact[i-1]*i;
    }
    int tes,jaman=0;
    cin>>tes;
    while(tes--)
    {
        stack<int>q;
        unsigned long long n;
        cin>>n;

        for(int i=20; i>=0; i--)
        {
            if(fact[i]<=n)
            {
                n=n-fact[i];
                q.push(i);
            }
        }

        //

        cout<<"Case "<<++jaman<<": ";
        if(n == 0)
        {
            string s="";
            //printf("Case %d: ", ++jaman);


            while(!q.empty())
            {
                s+=to_string(q.top())+"!+";
                q.pop();

            }
            while(!q.empty())
            {
                q.pop();
            }
            cout<< s.substr(0,s.length()-1)<<endl;


        }

        else
        {
            cout<<"impossible\n";
        }
    }

    return 0;
}
