#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool isprime[1000000];
vector<ll>primes;
void sieve()
{
    memset(isprime,true, sizeof isprime);
    for(ll i=2;i*i<=1000000;++i)
    {
        if(isprime[i] == true)
        {
            for(ll j=i*i;j<=1000000;j+=i)
                isprime[j] = false;
        }
    }
    for(ll i=2;i<=1000000;++i)
        if(isprime[i] == true)
            primes.push_back(i);
}
int main()
{
    ll x,y,mn=10000000,mx=0,ii,jj,flag=0,r;
    sieve();
    vector<ll>v;
    while(scanf("%lld %lld",&x,&y) != EOF)
    {
        mn=10000000;mx=0;

        for(ll i=x;i<=y;++i)
        {
            flag = 0;
            for(ll j=0;primes[j]*primes[j]<=i;++j)
            {
                if(i % primes[j] == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0 && i != 1)
                v.push_back(i);

        }
        if(v.size()<=1)
            cout<<"There are no adjacent primes."<<endl;
        else
        {
            for(ll i=0;i<v.size()-1;++i)
            {
                if(v[i+1]-v[i]<mn){
                    mn = v[i+1]-v[i];
                    ii  = i;
                }
                if(v[i+1]-v[i]>mx){
                    mx = v[i+1]-v[i];
                    jj  = i;
                }
            }
            cout<<v[ii]<<","<<v[ii+1]<<" are closest, "<<v[jj]<<","<<v[jj+1]<<" are most distant."<<endl;

        }
        v.clear();
    }
}
