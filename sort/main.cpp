#include <bits/stdc++.h>
using namespace std;


class Node
{
public:
    int roll;
    int marks;
    string name;
};

bool comp(Node obj1,Node obj2)
{
    if(obj1.marks !=obj2.marks)
    {
        return obj1.marks > obj2.marks;
    }
    if(obj1.roll!=obj2.roll)
    {
        return obj1.roll<obj2.roll;
    }
}
int main()
{

    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    Node obj[n];
    int r,m;
    string nam;
    for(int i=0; i<n; i++)
    {
        cin>>r;
        cin>>nam;
        cin>>m;
        obj[i].roll=r;
        obj[i].marks=m;
        obj[i].name=nam;
    }
    sort(obj,obj+n,comp);

cout<<"Roll | Name       | Marks"<<endl;
    //cout<<setw(3)<<"Roll |"<<" Name "<<setw(11)<<" | Marks"<<endl;
    cout<<"-------------------------"<<endl;
    for(int i=0; i<n; i++)
    {
        //1 | kabul      | 100
        cout<<right<<setw(4)<<obj[i].roll<<" | ";
       // int len=obj[i].name.length();
        cout<<left<<setw(11)<<obj[i].name<<"| ";
        cout<<obj[i].marks<<setw(4)<<endl;
    }
    return 0;
}

/*
3
20
abul
0
7
babul
0
1
kabul
100

*/
