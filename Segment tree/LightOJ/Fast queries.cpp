#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz 100005
struct rng{
    ll l,r,id;
};
ll n,m;
ll arr[sz],last[sz],tree[4*sz];
rng okk[50005];
bool cmp(rng lhs,rng rhs){
    return lhs.r < rhs.r;
}
bool cmp2(rng lhs,rng rhs){
    return lhs.id < rhs.id;
}
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
    if(b>=i && e<=j)return tree[node];
    if(b>j || e<i)return 0;
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;
    ll v1 = query(left,b,mid,i,j);
    ll v2 = query(right,mid+1,e,i,j);
    return v1+v2;
}
void clr()
{
    memset(tree,0,sizeof(tree));
    memset(arr,0,sizeof(arr));
    memset(okk,0,sizeof(okk));
    memset(last,-1,sizeof(last));
}
int main()
{
    ll test,cs=1;
    cin>>test;
    while(test--)
    {
        clr();
        cin>>n>>m;
        for(ll i=1;i<=n;++i)cin>>arr[i];
        for(ll i=1;i<=m;++i){
            ll x,y;
            cin>>x>>y;
            okk[i].l = x;
            okk[i].r = y;
            okk[i].id = i;
        }
        sort(okk+1,okk+m+1,cmp);
        ll cnt=1;
        for(ll i=1;i<=n;){
            if(last[arr[i]] == -1){
                last[arr[i]] = i;
                update(1,1,n,i);
            }else{
                update(1,1,n,last[arr[i]]);
                last[arr[i]] = i;
                update(1,1,n,i);
            }
            if(okk[cnt].r == i){
                ll ans = query(1,1,n,okk[cnt].l,okk[cnt].r);
                okk[cnt].l = ans;
                cnt++;
            }else{
                ++i;
            }
        }
        sort(okk+1,okk+m+1,cmp2);
        printf("Case %lld:\n",cs++);
        for(ll i=1;i<=m;++i)
            cout<<okk[i].l<<endl;

    }
}
