#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz 100005
ll n,tree[sz*8];
void update(ll node,ll b,ll e,ll id)
{
    if(b>id || e<id)return;
    if(b == id && e == id){
        tree[node] ^= 1;
        return;
    }
    ll left = node * 2;
    ll right=node * 2 + 1;
    ll mid = (b+e)/2;
    update(left,b,mid,id);
    update(right,mid+1,e,id);
    tree[node] = tree[left]+tree[right];
}
ll query(ll node,ll b,ll e,ll i,ll j)
{
    if(b>j || e<i) return 0;
    else if(b >= i && e<=j)
    {
        //cout<<tree[node]<<" "<<b<<" "<<e<<" "<<node<<endl;;
        return tree[node];
    }

    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;
    ll v1 = query(left,b,mid,i,j);
    ll v2 = query(right,mid+1,e,i,j);
    return v1+v2;

}
int main()
{
    memset(tree,0,sizeof(tree));
    cin>>n;
    vector<pair<pair<ll,ll>,ll > >vp(n+1,{{0,0},0});
    ll ans[n+1];
    for(ll i=1;i<=2*n;++i)
    {
        ll x;
        cin>>x;
        if(vp[x].first.first == 0){
            vp[x].first.first = i;
            vp[x].second = x;

        }
        else
            vp[x].first.second = i;
    }
    sort(vp.begin()+1,vp.end());

        //cout<<vp[i].first.first<<" "<<vp[i].first.second<<" "<<vp[i].second<<endl;
    for(ll i=1;i<=n;++i)
    {
        ll x = vp[i].first.second;
        update(1,1,2*n,x);
    }
    for(ll i=1;i<=n;++i)
    {
        ll x = vp[i].first.second;
        //cout<<"-------"<<endl;
        //cout<<x<<" ";
        update(1,1,2*n,x);
        ll v = query(1,1,2*n,x+1,2*n);
        //for(ll i=1;i<=32;++i)
        //cout<<tree[i]<<" ";
        ll y = vp[i].second;
        ll c = n - (v+i-1+1);
        //cout<<y<<" = "<<i-1<<" "<<x<<" "<<v<<" "<<c<<endl;
        ans[y] = c;
    }
    for(ll i=1;i<=n;++i)
        cout<<ans[i]<<" ";
        cout<<endl;
}
