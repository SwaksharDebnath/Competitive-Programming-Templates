#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 10000001
vector<ll>spf(MAX,0);
void smlprmfctr()
{
    spf[1] = 1;
    for(ll i=2;i<=MAX;++i)
    {
        if(spf[i] == 0)
        {
            spf[i] = i;
            for(ll j=i*i;j<=MAX;j+=i)
                if(spf[j] == 0)
                    spf[j] = i;
        }
    }
}
ll aps(ll n)
{
    ll r=0;
    for(ll i=1;i<=n;++i)
    {
        if(i == 1)
           r=0;
        else
        {
            r = r+spf[i];
        }
    }
    /*if(n == 1 || n == 0)
        return 0;
    return aps(n-1)+spf[n];*/
    return r;
}
int main()
{
    ll t,n,res;
    smlprmfctr();
    cin>>t;
    for(ll i=1;i<=t;++i)
    {
        cin>>n;
        res = aps(n);
        cout<<res<<endl;
    }
}
