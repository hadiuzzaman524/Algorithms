#include <iostream>

using namespace std;


class Student
{
public:
    string name;
    int volume;
};


int main()
{
   // freopen("input.txt","r",stdin);
    int n,t,x=0;
    cin>>t;
    int big,index=0,index2=0,total_volume;

    string name;
    while(t--)
    {
        cin>>n;
        Student obj[n];


        int a,b,c;
        for(int i=0; i<n; i++)
        {
            cin>>name;
            cin>>a>>b>>c;
            obj[i].name=name;
            obj[i].volume=a*b*c;

        }

        big=0;
        total_volume=0;

        for(int i=0; i<n; i++)
        {
            if(big<obj[i].volume)
            {
                big=obj[i].volume;
                index=i;
            }
            total_volume+=obj[i].volume;



        }

        int small=obj[0].volume;
        index2=0;

        for(int i=1; i<n; i++)
        {
            if(small > obj[i].volume)
            {
                small=obj[i].volume;
                index2=i;
            }
        }


        int avg=(total_volume/n);


          cout<< "Case "<<++x<<": ";
          if(avg==big)
          {
              cout<< "no thief"<<endl;
          }
          else
          {
              cout<< obj[index].name<< " took chocolate from "<<obj[index2].name<<endl;
          }

}
    return 0;
}

