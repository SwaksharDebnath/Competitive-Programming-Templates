#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
vector<ll>primes;
bool prime_or_not[1007];
void sieve()
{
    memset(prime_or_not,true,sizeof(prime_or_not));
    ll val = sqrt(n)+1;
    prime_or_not[1]=false;

    for(ll i=2;i<=val;++i)
        if(prime_or_not[i] == true)
            for(ll j=i*i;j<=n;j+=i)
                prime_or_not[j]= false;


    for(ll i=1;i<=n;++i)
        if(prime_or_not[i])
            primes.push_back(i);
}
ll SOD(ll m)
{
    ll val = sqrt(m)+1;
    ll sum=1,s=0,p=1;
    for(ll i=0;primes[i]<=val;++i)
    {
        if(m%primes[i] == 0)
        {
            p=1;
            while(m%primes[i] == 0)
            {
                m/=primes[i];
                p*=primes[i];
            }
            p*=primes[i];
            ll s = (p-1)/(primes[i]-1);
            sum *= s;
        }
    }
    if(m>1)
    {
        p = m*m;
        s = (p-1)/(m-1);
        sum*=s;
    }
    return sum;
}
int main()
{
    cin>>n;
    sieve();
    ll val = SOD(n);
    for(ll i=0;i<primes.size();++i)
        cout<<primes[i]<<" ";

    cout<<endl<<"Sum of divisiors   :"<<val<<endl;
    return 0;
}
