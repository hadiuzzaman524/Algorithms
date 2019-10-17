#include <iostream>
#include <queue>
using namespace std;

int main()
{
   // freopen("input.txt","r",stdin);
    deque<int>q;
    vector<string>v;

    int n,m,x,b,f=0,t;
    cin>>t;

    while(t--)
    {
        string s="";
        cin>>n>>m;
        for(int i=0; i<m; i++)
        {

            cin>>s;
            if(s=="pushLeft")
            {
                cin>>x;


                if(q.size()!=n)
                {
                    q.push_front(x);
                    v.push_back("Pushed in left: "+to_string(x));

                }
                else
                {
                    v.push_back("The queue is full");
                }

            }
            else if(s=="pushRight")
            {
                cin>>x;
                if(q.size()!=n)
                {
                    q.push_back(x);
                    v.push_back("Pushed in right: "+to_string(x));

                }
                else
                {
                    v.push_back("The queue is full");
                }

            }
            else if(s=="popLeft")
            {

                if(q.size() !=0)
                {
                    b=q.front();
                    q.pop_front();
                    v.push_back("Popped from left: "+to_string(b));
                }
                else
                {
                    v.push_back("The queue is empty");
                }


            }
            else if(s=="popRight")
            {

                if(q.size()!=0)
                {
                    b=q.back();
                    q.pop_back();
                    v.push_back("Popped from right: "+to_string(b));
                }
                else
                {
                    v.push_back("The queue is empty");
                }


            }

        }
        cout<< "Case "<<++f<<":"<<endl;
        for(int i=0; i<v.size(); i++)
        {
            cout<< v[i]<<endl;
        }

        v.clear();
        q.clear();

    }

    return 0;
}
/*
1
3 8
pushLeft 1
pushLeft 2
pushRight -1
pushRight 1
popLeft
popRight
popLeft
popRight

*/
