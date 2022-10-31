#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll bigmod(ll a,ll b,ll m)
{
    if(b == 0)
        return 1;
    ll x = bigmod(a,b/2,m);

    x = ((x%m)*(x%m))%m;
    if(b%2 == 1)
        x = ((x%m)*(a%m))%m;

    return x;
}
int leaddig(ll a,ll b)
{
    double d = b*log10(a);
    return (int)(pow(10,d-(ll)(d))*100);

}
int main()
{
    ll x,a,b;
    cin>>x;
    for(ll i=1;i<=x;++i)
    {
        cin>>a>>b;
        printf("Case %lld: %d %03lld\n",i,leaddig(a,b),bigmod(a,b,1000));

    }
}
