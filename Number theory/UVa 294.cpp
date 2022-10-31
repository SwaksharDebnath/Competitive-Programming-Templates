#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define SIZE 1000000001
#define SIZEm 100000001
/*bool isprime[SIZE];
ll primes[SIZEm];
void sieve()
{
    memset(isprime,true,sizeof isprime);
    ll total=0;
    for(ll i=2;i*i<=SIZE;++i)
    {
        if(isprime[i])
        {
            for(ll j = i*i;j<=SIZE;j+=i)
                isprime[j] = false;
        }
    }
    for(ll i=2;i<=SIZE;++i)
        if(isprime[i])
            primes[++total] = i;
}
ll divs(ll n)
{
    ll r = sqrt(n),c=0,sum=1;
    for(ll i=0;primes[i]<=r;++i)
    {
        if(n % primes[i] == 0)
        {
            c =0 ;
            while(n%primes[i]==0)
            {
                n /= primes[i];
                ++c;
            }
            sum *= (c+1);
        }
    }
    if(n>1)
        sum *= 2;
    return sum;
}*/
int main()
{
    ll n,x,y,mx=0,c,div,r;
    cin>>n;
    while(n--)
    {
        cin>>x>>y;
        mx=0;div=0;
        for(ll i=x;i<=y;++i)
        {
            div=0;
            r = sqrt(i);
            for(ll j=1;j<=r;++j)
            {
                if(i%j == 0)
                    ++div;
            }
            if(r*r == i)
                div = (div*2)-1;
            else
                div *= 2;
            if(div>mx){
                c=i;
                mx = div;
            }
        }
        cout<<"Between "<<x<<" and "<<y<<", "<<c<<" has a maximum of "<<mx<<" divisors."<<endl;

    }

}
