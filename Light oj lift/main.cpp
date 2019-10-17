#include <iostream>

using namespace std;

int main()
{ freopen("input.txt","r",stdin);

    int testcase;
    cin>>testcase;
    int c=0;
    while(testcase--)
    {
        int sum=0;
        int lp,mp;
        cin>>mp>>lp;



            int dif=abs(lp-mp);
            if(dif==0)
            {
                sum=3+5+3+(mp*4)+3+5;
            }
            else
            {
                sum=(dif*4)+3+5+3+(mp*4)+3+5;
            }
        cout<<"Case "<<++c<<": "<< sum<<endl;
    }

//24 12

    return 0;
}
