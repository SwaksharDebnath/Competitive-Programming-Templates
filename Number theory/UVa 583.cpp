#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool isprime[100000];
ll primes[100000];
vector<ll>v;
void sieve()
{
    memset(isprime,true,sizeof isprime);
    ll tot=0;
    for(ll i=2;i*i<100000;++i)
    {
        if(isprime[i])
        {
            for(ll j=i*i;j<=100000;j+=i)
                isprime[j] = false;
        }
    }
    for(ll i=2;i<100000;++i)
    {
        if(isprime[i])
            primes[tot++] = i;
    }
}
void prfa(ll n)
{
    ll r=sqrt(n);
    for(ll i=0;primes[i]<=r;++i)
    {
        if(n % primes[i] == 0)
        {
            while(n % primes[i] == 0)
            {
                v.push_back(primes[i]);
                n = n/primes[i];
            }
        }
    }
    if(n>1)
        v.push_back(n);
}
int main()
{
    sieve();
    ll x;
    while(1)
    {
        cin>>x;
        if(x == 0)
            return 0;
        cout<<x<<" = ";
        if(x < 0)
            cout<<-1<<" x ";
        x = abs(x);
        prfa(x);
        for(ll i=0;i<v.size();++i)
        {
            if(i== v.size()-1)
                cout<<v[i]<<endl;
            else
                cout<<v[i]<<" x ";
        }
        v.clear();
    }
}
