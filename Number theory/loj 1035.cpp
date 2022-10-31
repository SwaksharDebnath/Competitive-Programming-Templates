#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool isprime[110];
ll primes[110];
ll num[101];
map<ll,ll>mp;
void sieve()
{
    memset(isprime,true,sizeof isprime);
    for(ll i=2;i*i<=101;++i)
    {
        if(isprime[i])
        {
            for(ll j=i*i;j<=101;j+=i)
                isprime[j] = false;
        }
    }
    ll j=0;
    for(ll i=2;i<=101;++i)
        if(isprime[i])
            primes[j++]=i;

}
void factor(ll n)
{
    ll cnt=0,c=0;
    ll r = sqrt(n);
    for(ll i=1;i<=101;++i)
        num[i] = i;

    for(ll i=0;primes[i]<=n;++i)
    {
        cnt = 0;c==0;
        for(ll j=2;j<=n;++j)
        {
            if(num[j] % primes[i] == 0)
            {
                while(num[j] % primes[i] == 0)
                {
                    num[j] /= primes[i];
                    ++cnt; c=1;
                }
            }
        }
        if(c == 1)
            mp[primes[i]] = cnt;

    }
}
int main()
{
    sieve();
    ll n,x;;
    cin>>n;
    map<ll,ll> :: iterator it;
    for(ll i=1;i<=n;++i)
    {
        cin>>x;
        cout<<"Case "<<i<<": "<<x<<" = ";
        factor(x);
        for(it = mp.begin();it!=mp.end();++it)
        {
            if(it == mp.begin())
                cout<<it->first<<" ("<<it->second<<")";
            else
                cout<<" * "<<it->first<<" ("<<it->second<<")";
        }
        cout<<endl;
        mp.clear();
    }
}
