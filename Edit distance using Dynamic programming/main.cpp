#include <iostream>

using namespace std;

int edit_distance(string x,string y,int m,int n)
{
    int table[m+1][n+1]= {0};

    for(int i=0; i<=m; i++)
    {
        table[i][0]=i;
    }

    for(int i=0; i<=n; i++)
    {
        table[0][i]=i;
    }

    int cost;

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(x[i-1]==y[j-1])
                cost=0;
            else
                cost =1;

            table[i][j]=min(min(table[i-1][j]+1,table[i][j-1]+1),table[i-1][j-1]+cost);
        }
    }


    int i = n, j = m;
    while (i || j)
    {
        if (x[i - 1] == y[j - 1])
        {
            i--, j--;
            continue;
        }
        if (j > 0 && table[i][j] == table[i][j - 1] + 1)     // insert
        {
            printf("I%c", y[j - 1]);
            if (i + 1 < 10)
                putchar('0');
            printf("%d", i + 1);
            x.insert(i, 1, y[j - 1]);
            j--;
        }
        else if ((i > 0 && j > 0) && table[i][j] == table[i - 1][j - 1] + 1)    // replace
        {
            printf("C%c", y[j - 1]);
            if (i < 10)
                putchar('0');
            printf("%d", i);
            x[i - 1] = y[j - 1];
            i--, j--;
        }
        else if (i > 0)   // f[i][j] == f[i - 1][j] + 1  ==> delete
        {
            printf("D%c", x[i - 1]);
            if (i < 10)
                putchar('0');
            printf("%d", i);
            x.erase(i - 1, 1);
            i--;
        }
        //   cout << x << endl;
    }
    puts("E");

    /*
         int i=0;
        int j=0;

        while(i<m||j<n)
        {
            if(x[i]==y[j])
            {
                i++;
                j++;
                continue;
            }

            if(j<n&&table[i][j-1]+1==table[i][j])
            {
                cout<< " I"<< y[j-1]<<i;
                x.insert(i,1,y[j-1]);
                j++;
            }


            else if(i<m&&table[i-1][j]+1==table[i][j])
            {
                cout<< " D"<< x[i-1]<<i;
                x.erase(i-1,1);
                i++;

            }


            else if(i<m&&j<n&&table[i][j]==table[i-1][j-1]+1)
            {
                cout<< " C"<< y[j-1]<<j;
                x[i-1]=y[j-1];
                i++;
                j++;
            }


        }*/

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<< table[i][j]<< " ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<< x<<endl;
    cout<< y<<endl;
    return table[m][n];
}



int main()
{
    string x="abcde";
    string y="bcgfe";

    int n=x.length();
    int m=y.length();


    int z=edit_distance(x,y,n,m);

    cout<< "Total operation is: "<< z <<endl;

    return 0;
}
