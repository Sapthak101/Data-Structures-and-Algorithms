#include<iostream>
using namespace std;

int main()
{
    int a , b, count=0;

    cin>>a>>b;

    while(1)
    {
        a=3*a;
        b=2*b;
        count++;

        if (a>b)
            break;
    }

    cout<<count<<endl;

    return 0;
}