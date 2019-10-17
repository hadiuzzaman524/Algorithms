#include <iostream>
#include <algorithm>
using namespace std;

class A
{
public:
    int roll;
    int marks;
    string name;


};
bool comp(A a,A b)
{
    if(a.marks !=b.marks)
    {
        return a.marks > b.marks;
    }

}
int main()
{
    A obj[4];
    int r,m;
    string name;
    for(int i=0; i<4; i++)
    {
        cin>>r>>m;
        cin>>name;

        obj[i].name=name;
        obj[i].roll=r;
        obj[i].marks=m;
    }

    sort(obj,obj+4,comp);

    for(int i=0; i<4; i++)
    {
        cout<<obj[i].roll<< " "<<obj[i].marks<< " "<< obj[i].name<<endl;
    }
    return 0;
}
/*

3 99
Atik
1 43
gondhoraj
5 87
abir
5 85
riaj




*/


