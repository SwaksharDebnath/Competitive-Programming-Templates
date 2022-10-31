#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool isprime[1000005];
ll primes[1000005];
void sieve()
{
    memset(isprime,true,sizeof isprime);
    ll j=0;
    isprime[1] = false;
    for(ll i=2;i*i<=1000005;++i)
    {
        if(isprime[i])
        {
            for(ll j=i*i;j<=1000005;j+=i)
            {
                isprime[j] = false;
            }
        }
    }
    for(ll i=2;i<=1000005;++i)
    {
        if(isprime[i])
            primes[j++] = i;
    }
}
ll ndivs(ll n)
{
    ll r=sqrt(n),cnt,divs=1;
    for(ll i=0;i<=1000005 && primes[i]<=r;++i)
    {

        if(n < primes[i])break;

        if(n % primes[i] == 0)
        {
            cnt = 0;
            while(n % primes[i] == 0)
            {
                n = n/primes[i];
                ++cnt;
            }
            divs *= (cnt+1);
        }
        //cout<<"bal"<<i<<endl;
    }
    if(n > 1)
        divs *= 2;
    return (divs - 1);
    /*if(n>1)
        divs *= 2;*/
}
int main()
{
    sieve();
    ll n,x;
    cin>>n;
    for(ll i=1;i<=n;++i)
    {
        cin>>x;
        cout<<"Case "<<i<<": "<<ndivs(x)<<endl;

    }

}
