#include<iostream>
using namespace std;

int main()
{
    string s2;
    long long int n ,count=0, count2=0, n2, i;

    cin>>n;

    s2=to_string(n);

    n2=n;
    while(n2!=0)
    {   
        n2=n2/10;
        count++;
    }

    for (i=0; i<count; i++)
    {
        if (s2[i]=='4'||s2[i]=='7')
            count2++;
    } 

    if (count2==7 || count2==4)
        cout<<"YES";
    else
        cout<<"NO";  

    return 0;
}