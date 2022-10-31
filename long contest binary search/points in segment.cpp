#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,x,y,c,q1,q2,z;
    scanf("%lld",&n);
    vector<ll>v;
    vector<ll>::iterator it1,it2;
    for(ll i=1; i<=n; ++i)
    {
        scanf("%lld %lld",&x,&y);
        while(x--)
        {
            scanf("%lld",&c);
            v.push_back(c);
        }
        printf("Case %d:\n",i);
        while(y--)
        {
            scanf("%lld %lld",&q1,&q2);
            it1 = lower_bound(v.begin(),v.end(),q1);
            if(it1 == v.end())
            {
                printf("0\n");
                continue;
            }
            else
            {
                it2 = upper_bound(v.begin(),v.end(),q2);
                z = it2-it1;
                printf("%lld\n",z);
            }
        }
        v.clear();

    }
}
