#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>v;
ll n,m;

bool calc(ll s)
{
    ll s1=0,c=1;
    for(ll i=0; i<n; )
    {
        if(s1+v[i]<=s)
        {
            s1+=v[i];
            ++i;
        }
        else
        {
            if(v[i]>s)
                return 0;
            ++c;
            //cout<<s1<<endl;
            s1 = 0;
        }

    }
        //cout<<c<<"bb "<<s<<endl;
        if(c<=m)
            return 1;
        return 0;
}
int main()
{
    ll t,x,s=0,mx=0;
    cin>>t;
    queue<ll>q;
    for(ll i=1; i<=t; ++i)
    {
        cin>>n>>m;
        n++;
        m++;
        mx=0;
        s=0;
        for(ll i=0; i<n; ++i)
        {
            cin>>x;
            s+=x;
            mx=max(x,mx);
            v.push_back(x);
        }
        if(n == m)
        {
            printf("Case %lld: %lld\n",i,mx);
            //cout<<mx<<endl;
            for(ll i=0; i<n; ++i)
                cout<<v[i]<<endl;
        }
        else
        {

            ll hi = s,lo=0,md;
            while(lo<hi)
            {
                md = (hi+lo)/2;
                //cout<<hi<<" "<<lo<<" "<<md<<endl;
                if(calc(md))
                    hi = md;
                else
                    lo = md +1;
                //cout<<hi<<" "<<lo<<" "<<md<<endl;
                //cout<<"--------------"<<endl;
            }
            printf("Case %lld: %lld\n",i,hi);
            ll s2=0,c=0;
            //cout<<hi<<endl;
            for(ll i=0; i<n; )
            {
                if(c == n-m)
                {
                    if(s2!=0){
                        q.push(s2);
                        s2=0;
                    }
                    q.push(v[i]);
                    ++i;
                }
                else if(s2+v[i]<=hi){

                    if(v[i] == s && s2 == 0)
                        q.push(v[i]);
                    else{
                        if(s2!=0)
                            ++c;
                        s2+=v[i];
                    }
                    ++i;
                }
                else
                {
                    q.push(s2);
                    s2 = 0;
                }
            }
            if(s2!=0)
                q.push(s2);
            while(!q.empty()){
                cout<<q.front()<<endl;
                q.pop();
            }
        }
        v.clear();
    }
}

