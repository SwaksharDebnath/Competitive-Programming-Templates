#include<bits/stdc++.h>
using namespace std;
#define ll long long int
double lg[1000005];
int main()
{
    ll n,x,y,val;
    lg[0]=0;
    for(ll i=1;i<=1000000;++i)
    {
        lg[i] = lg[i-1]+log(i);
    }
    cin>>n;
    for(ll i=1;i<=n;++i)
    {
        cin>>x>>y;
        val = (lg[x]/log(y))+1;
        cout<<"Case "<<i<<": "<<val<<endl;
    }
}
