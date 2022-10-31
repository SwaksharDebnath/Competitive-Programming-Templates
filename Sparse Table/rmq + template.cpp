///Range Minimum Query
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz 1001
ll n,q;
ll arr[sz],lg[sz],st[sz][11];///st[max size of n][lg2 n]
void calc_max_pow2()
{
    lg[1]=0;
    for(ll i=2;i<=n;++i)
        lg[i] = lg[i/2]+1;
}
void build()
{
    for(ll i=0;i<n;++i)
        st[i][0] = arr[i];
    ll k = log2(n);
    for(ll j=1;j<=k;++j)
        for(ll i=0;i+(1 << j) <= n;++i)
            st[i][j] = min(st[i][j-1],st[i+(1 << (j-1))][j-1]);
}
ll queri(ll l,ll r)
{
    ll j = lg[r-l+1];
    ll minimum = min(st[l][j],st[r-(1 << j)+1][j]);
    return minimum;
}
int main()
{
    cin>>n>>q;
    for(ll i=0;i<n;++i)cin>>arr[i];

    calc_max_pow2();
    build();
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        cout<<queri(l-1,r-1)<<endl;
    }

}
/*n query
ai......an
li ri
.
.
lq rq*/


