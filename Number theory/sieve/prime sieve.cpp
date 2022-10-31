#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
vector<ll>primes;
//int v[1000];
int prime_or_not[1000];
void sieve ()
{
    //memset(prime_or_not,true,sizeof(prime_or_not));

    for(ll i=3;i<=1000;i++){
        if(i%2==1)prime_or_not[i]=true;
        else prime_or_not[i]=false;}


    ll val = sqrt(n)+1;
    prime_or_not[1]=false;
    prime_or_not[2]=true;

    for(ll i=3;i<=val;i+=2)
        if(prime_or_not[i] == true)
            for(ll j=i*i;j<=n;j+=i*2)
                prime_or_not[j] = false;
    //ll total=0;
    primes.push_back(2);
    for(ll i=3;i<=n;i+=2)
        if(prime_or_not[i] == true)
            primes.push_back(i);
}
int main()
{
    n;
    cin>>n;
    sieve();
    for(ll i=0;i<primes.size();++i)
        cout<<primes[i]<<" ";
}
