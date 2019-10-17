#include <iostream>

using namespace std;

int main()
{
   // freopen("input.txt","r",stdin);
    int n,m,c;
    cin>>c;
    while(c--)
    {
        cin>>n>>m;

        int revers1=0;
        while (n != 0)
        {
            revers1 = revers1 * 10;
            revers1 = revers1 + n%10;
            n = n/10;
        }
        int revers2=0;

        while (m != 0)
        {
            revers2 = revers2 * 10;
            revers2 = revers2 + m%10;
            m = m/10;
        }

        int revers3=0;
        int p=revers1+revers2;

        while ( p!= 0)
        {
            revers3 = revers3 * 10;
            revers3 = revers3 + p%10;
            p = p/10;
        }

        cout<< revers3<<endl;
    }
    return 0;
}
