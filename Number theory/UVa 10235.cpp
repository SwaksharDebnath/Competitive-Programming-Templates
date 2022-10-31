#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool isprime[1000001];
void sieve()
{
    memset(isprime,true,sizeof isprime);
    isprime[1] = false;
    for(ll i=2;i*i<=1000001;++i)
    {
        if(isprime[i])
        {
            for(ll j=i*i;j<=1000001;j+=i)
                isprime[j] = false;
        }
    }
}
int main()
{
    sieve();
    ll n,nv=0,p,q;

    while(scanf("%lld",&n)!=EOF)
    {
        nv=0;
        p = n;
        while(p!=0)
        {
            nv= (nv*10) + (p%10);
            p = p/10;
        }
        if(!isprime[n])
            cout<<n<<" is not prime."<<endl;
        else if(isprime[n]==true && isprime[nv]==true && n!=nv)
            cout<<n<<" is emirp."<<endl;
        else
            cout<<n<<" is prime."<<endl;

    }

}
