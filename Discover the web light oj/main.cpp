#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
  //  freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);


    int testcase;
    cin>>testcase;

    string com;

    stack<string>forwardd;
    stack<string>backword;


    int i=0;

    while(testcase--)
    {
        //cin>>com;

        while(!forwardd.empty())
        {
            forwardd.pop();
        }


        while(!backword.empty())
        {
            backword.pop();
        }

        string url="http://www.lightoj.com/";
        cout<< "Case "<<++i<<":"<<endl;

        while(cin>>com)
        {

            if(com=="FORWARD")
            {
                if(forwardd.empty())
                {
                    cout<< "Ignored"<<endl;
                }
                else
                {

                    backword.push(url);
                    url=forwardd.top();
                    forwardd.pop();
                    cout<<url<<endl;

                }


            }


            else if(com=="BACK")
            {
                if(backword.empty())
                {
                    cout<< "Ignored"<<endl;
                }
                else
                {

                    forwardd.push(url);
                    url=backword.top();
                    backword.pop();
                    cout<<url<<endl;

                }

            }

            else if(com=="VISIT")
            {
                backword.push(url);
                cin>>url;
                cout<< url<<endl;

                while(! forwardd.empty())
                {
                    forwardd.pop();
                }

            }


            else if(com=="QUIT")
            {
                break;
            }
        }

    }

    return 0;
}

