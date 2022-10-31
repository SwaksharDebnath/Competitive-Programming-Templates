#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll phi(ll n)
{
    ll res = n;
    for(ll i=2;i*i<=n;++i)
    {
        if(n % i == 0)
        {
            while(n%i == 0)
                n = n/i;
            res = res - (res/i);
        }
    }
    if(n>1)
        res = res - (res/n);
    return res;
}
int main()
{
    ll n,x;
    while(1)
    {
        cin>>n;
        if(n == 0)
            return 0;
        if(n == 1){
            cout<<0<<endl;
            continue;
        }
        x = phi(n);
        cout<<x<<endl;
    }

}
