#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool isprime[1000001];
ll primes[100000];
ll factors[1000001];
ll cnt=0;
void sieve()
{
    memset(isprime,true,sizeof isprime);
    ll tot=0;
    for(ll i=2;i*i<1000001;++i)
    {
        if(isprime[i])
        {
            for(ll j=i*i;j<=1000001;j+=i)
                isprime[j] = false;
        }
    }
    for(ll i=2;i<=1000001;++i)
        if(isprime[i])
            primes[tot++]=i;
}
void prfa(ll n)
{
    ll r = sqrt(n);
    for(ll i=0;primes[i]<=r;++i)
    {
        if(n % primes[i] == 0)
        {
            while(n % primes[i] == 0)
            {
                ++cnt;
                n = n/primes[i];
            }
        }
    }
    if(n>1)
        ++cnt;
}
void factor()
{
    factors[0]=factors[1]=0;
    for(ll i=2;i<=1000000;++i)
    {
        prfa(i);
        factors[i] = factors[i-1]+cnt;
        cnt = 0;
    }
}
int main()
{
    sieve();
    factor();
    ll x;
    while(scanf("%lld",&x)!=EOF)
    {

        cout<<factors[x]<<endl;

        //cout<<cnt<<endl;
    }
}
