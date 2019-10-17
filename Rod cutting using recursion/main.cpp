#include <iostream>

using namespace std;

int rodCut(int price[],int len)
{
    if(len==0)
        return 0;

    int mincost=0;

    for(int i=1; i<=len; i++)
    {
        int cost=price[i-1]+rodCut(price,len-i);

        if(cost>mincost)
            mincost=cost;
    }
    return mincost;
}

int main()
{


    int length[] = { 1, 2, 3, 4, 5, 6, 7, 8 };	// dummy
    int price [] = { 1, 5, 8, 9, 10, 17, 17, 20 };

    // rod length
    int n = 4;

    cout << "Profit is " << rodCut(price, n);

    return 0;
}
