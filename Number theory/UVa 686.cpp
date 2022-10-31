#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool isprime[1000001];
void sieve()
{
    memset(isprime,true,sizeof isprime);
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
    int x,c=0,cont=0;
    sieve();
    while(1)
    {
        cin>>x;
        if(x == 0)
            return 0;
        c=0;cont=0;
        for(ll i=2;i<=x/2;++i)
        {
            if(isprime[i]== true && isprime[x-i]== true)
            {
                if(i+(x-i) == x)
                {
                    ++cont;
                }
            }
        }
        cout<<cont<<endl;

    }
}

