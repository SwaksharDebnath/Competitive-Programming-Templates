#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 1000005
map<ll,ll>mp;ll tree[4*MAX];
void update(ll node,ll b,ll e,ll i,ll j)
{
    if(b>=i && e<=j){tree[node]++;return;}
    else if(b>j || e<i) return;

    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);

}
ll query(ll node,ll b,ll e,ll i)
{
    if(b == i && e == i) return tree[node];
    else if(b>i || e<i) return 0;

    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;
    ll p,q;
    if(mid >= i)
        p = query(left,b,mid,i);
    else
        p = query(right,mid+1,e,i);

    return (tree[node]+p);
}
int main()
{
    ll t,n,m,x,y;
    scanf("%lld",&t);
    vector<pair<ll,ll> >vp;
    map<ll,ll> :: iterator it;
    vector<ll>v;
    for(ll j=1;j<=t;++j)
    {
        scanf("%lld %lld",&n,&m);
        ll cnt=1;
        memset(tree,0,sizeof(tree));
        for(ll i=0;i<n;++i)
        {
            scanf("%lld%lld",&x,&y);
            vp.push_back({x,y});
            if(mp.count(x)==0){mp.insert({x,0});cnt++;}
            if(mp.count(y)==0){mp.insert({y,0});cnt++;}
        }
        for(ll i=0;i<m;++i)
        {
            scanf("%lld",&x);
            v.push_back(x);
            if(mp.count(x)==0){mp.insert({x,0});cnt++;}
        }
        cnt=0;
        for(it = mp.begin();it != mp.end();++it){
            cnt++;
            it->second = cnt;
        }

        for(ll i=0;i<n;++i)
        {
            x = vp[i].first; y = vp[i].second;
            update(1,1,cnt,mp[x],mp[y]);
        }
        printf("Case %lld:\n",j);
        for(ll i=0;i<m;++i)
        {
            x = v[i];
            ll ans = query(1,1,cnt,mp[x]);
            printf("%lld\n",ans);
        }
        v.clear();vp.clear();mp.clear();
    }
}
