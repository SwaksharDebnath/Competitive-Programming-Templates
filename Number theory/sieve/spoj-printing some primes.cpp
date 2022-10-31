#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void sieve(ll n)
{
    vector<bool>is_prime(n+1,true);
    vector<ll>v;
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i*i<=n;++i)
    {
        if(is_prime[i])
        {
            for(ll j=i*i;j<=n;j+=i)
                is_prime[j]=false;
        }
    }

    v.push_back(2);
    for(ll i=3;i<=n;i+=2)
        if(is_prime[i])
            v.push_back(i);

    //cout<<is_prime.size()<<" "<<v[v.size()-1];
   for(ll i=0;i<v.size();i+=100)
        cout<<v[i]<<endl;
}
int main()
{
    ll n=100000000;
    sieve(n);
}
