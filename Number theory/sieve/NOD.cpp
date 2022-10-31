#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,j;
ll primes[1000];
bool prime_or_not[1000];
void sieve ()
{
    memset(prime_or_not,true,sizeof(prime_or_not));
    ll val = sqrt(n)+1;
    prime_or_not[1]=false;

    for(ll i=2;i<=val;++i)
        if(prime_or_not[i] == true)
            for(ll j=i*i;j<=n;j+=i)
                prime_or_not[j] = false;

    //ll total=0;
    j=0;
    for(ll i=2;i<=n;i++)
        if(prime_or_not[i] == true)
            primes[j++]=i;
}
ll NOD(ll m)
{
    ll val = sqrt(m)+1;
    ll sum=1;

    for(ll i=0;primes[i]<val;++i)
    {
        if(m%primes[i] == 0)
        {
            ll cnt=0;
            while(m%primes[i] == 0)
            {
                m /= primes[i];
                cnt++;
            }
            sum *= (cnt+1);
        }
    }
    if(m>1)sum*=2;

    return sum;
}
int main()
{
    n;
    cin>>n;
    sieve();
    ll num = NOD(n);
    for(ll i=0;i<j;++i)
        cout<<primes[i]<<" ";

    cout<<endl<<"Number of divisiors   :"<<num<<endl;


    return 0;
}
