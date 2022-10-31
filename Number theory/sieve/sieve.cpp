#include<bits/stdc++.h>
using namespace std;
#define ll long long
void sieve(int n)
{
    vector<bool>is_prime(n+1,true);
    is_prime[0]=is_prime[1]=false;

    for(ll i=2; i*i<=n ;++i)
        if(is_prime[i])//can be optimized by stop checking all even numbers except 2
            for(ll j=i*i; j<=n ;j+=i)
                is_prime[j]=false;

    for(ll i=2;i<=n;++i)
        if(is_prime[i])
            cout<<i<<" ";
}
int main()
{
    ll n;
    cout<<"(prime numbers from 0 to n)enter n :";
    cin>>n;
    sieve(n);
}
