#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void prime_factorization(ll n)
{
    vector<ll>v;
    while(n!=1)
    {
        if(n%2 == 0)
        {
            v.push_back(2);
            n = n/2;
        }
        else
        {
            ll c=0;
            for(ll i=3;i*i<=n;i+=2)
            {
                if(n%i == 0){
                    v.push_back(i);
                    n = n/i;
                    c=1;
                    break;
                }
            }
            if(c==0){
                v.push_back(n);
                n /= n;
            }
        }
    }
    for(ll i=0;i<v.size();++i)
        cout<<v[i]<<" ";
}
int main()
{
    ll n;
    cin>>n;
    prime_factorization(n);
}
