#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,x,y,s,s1,k=0;
    cin>>n;
    while(n--)
    {
        cin>>x>>y;
        s = ((x-1)/3)*2;
        if((x-1)%3 == 2)
            s++;
        s1 = (y/3)*2;
        if(y%3 == 2)
            s1++;


        cout<<"Case "<<++k<<": "<<s1 - s<<endl;
    }
}
