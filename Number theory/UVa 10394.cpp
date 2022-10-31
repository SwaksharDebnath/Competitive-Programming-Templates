#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool isprime[20000005];
ll v[20000005];
void sieve()
{
    memset(isprime,true,sizeof isprime);
    for(ll i=2;i*i<20000005;++i)
    {
        if(isprime[i])
        {
            for(ll j= i*i;j<=20000005;j+=i)
                isprime[j] = false;
        }
    }
    ll j=1;
    for(ll i = 3;i<=20000000;i+=2)
    {
        if(isprime[i] == true && isprime[i+2] == true)
        {
            v[j++] = i;
        }
    }
}
int main()
{
    sieve();
    ll n,x;
    while(scanf("%lld",&x)!=EOF)
    {
        cout<<"("<<v[x]<<", "<<v[x]+2<<")"<<endl;
    }
}
