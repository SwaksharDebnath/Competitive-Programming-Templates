#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n;
    cin>>n;
    ll b,rem=0;
    string a;
    for(ll i=1;i<=n;++i)
    {
        cin>>a>>b;
        rem = 0;
        for(ll j=0;j<a.length();++j)
        {
            if(a[j] == '-')
                continue;
            rem = rem*10 + a[j]-'0';
            rem %= b;
        }
        if(rem == 0)
            cout<<"Case "<<i<<": divisible"<<endl;
        else
            cout<<"Case "<<i<<": not divisible"<<endl;

    }
}
