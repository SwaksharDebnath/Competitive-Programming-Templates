#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>v;
ll cc(ll n)
{
    ll sum=0,c=1;
    for(ll i=0;i<v.size();++i)
    {
        if(sum+v[i]<=n)
            sum+=v[i];
        else{
            sum = v[i];
            c++;
        }
        //cout<<sum<<" ";
    }
    //cout<<endl<<n<<" "<<c<<endl;
    //system("PAUSE");
    return c;
}
int main()
{
    ll t,n,m,x,mx,sum,hi,lo,mid,r;
    cin>>t;
    for(ll j =1;j<=t;++j)
    {
        cin>>n>>m;
        mx = 0;
        sum = 0;
        for(ll i=0;i<n;++i)
        {
            cin>>x;
            v.push_back(x);
            mx = max(mx,x);
            sum += x;
        }
        if(m>=n)
            printf("Case %lld: %lld\n",j,mx);
        else
        {
            hi = sum;
            lo = mx;
            while(lo<hi)
            {
                mid = (hi+lo)/2;
                r =  cc(mid);

                if(r <= m)
                    hi = mid;
                else
                    lo = mid+1;
            }
            printf("Case %lld: %lld\n",j,lo);
        }
        v.clear();
    }
}
