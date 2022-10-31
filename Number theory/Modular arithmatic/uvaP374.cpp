#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll bigmod(ll a,ll b,ll c)
{
    if(b == 0)
        return 1;
    ll x = bigmod(a,b/2,c);
    x = ((x%c)*(x%c))%c;
    if(b%2 == 1)
        x = ((x%c)*(a%c))%c;
    return x;
}
int main()
{
    ll a,b,c;
    while(cin>>a>>b>>c)
    {
        //cout<<endl;
        cout<<bigmod(a,b,c)<<endl;
        //cout<<endl;
    }
}
