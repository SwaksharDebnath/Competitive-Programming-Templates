#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,spf[1007];
bool prime_or_not[1007];
vector<ll>prime_fators;

void sieve ()
{
    memset(prime_or_not,true,sizeof(prime_or_not));
    ll val = sqrt(n)+1;
    prime_or_not[1]=false;

    for(ll i=1;i<=n;++i)spf[i]=i;

    for(ll i=2;i<=val;++i)
        if(prime_or_not[i] == true)
            for(ll j=i*i;j<=n;j+=i){
                prime_or_not[j] = false;
                if(spf[j] == j)spf[j]=i;
            }

    //ll total=0;
    /*for(ll i=2;i<=n;i++)///storing primes
        if(prime_or_not[i] == true)
            v.push_back(i);*/
}

void prime_factorization(ll n)
{
    while(n!=1)
    {
        prime_fators.push_back(spf[n]);
        n = n/spf[n];
    }
}
int main()
{
    cin>>n;m=n;

    sieve();
    prime_factorization(m);

    for(ll i=0;i<prime_fators.size();++i)
        cout<<prime_fators[i]<<" ";
}
