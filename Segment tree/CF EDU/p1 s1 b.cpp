#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100005

ll n,m;
ll tree[4*MAX],arr[MAX];
void init(ll node,ll b,ll e)
{
    if(b == e){
        tree[node] = arr[b];
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node] = min(tree[left],tree[right]);
}
void update(ll node,ll b,ll e,ll id,ll val)
{
    if(b>id || e<id)return;
    if(b == id && e == id){
        tree[node] = val;
        return;
    }
    ll left = node * 2;
    ll right=node * 2 + 1;
    ll mid = (b+e)/2;
    update(left,b,mid,id,val);
    update(right,mid+1,e,id,val);
    tree[node] = min(tree[left],tree[right]);
}
ll query(ll node,ll b,ll e,ll i,ll j)
{
    if(b>=i && e<=j)return tree[node];
    if(b>j || e<i)return 1e12+3;
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;
    ll v1 = query(left,b,mid,i,j);
    ll v2 = query(right,mid+1,e,i,j);
    return min(v1,v2);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;++i)cin>>arr[i];
    init(1,1,n);
    while(m--)
    {
        ll d,x,y;
        cin>>d>>x>>y;
        if(d == 1)update(1,1,n,x+1,y);
        else{
            ll val = query(1,1,n,x+1,y);
            cout<<val<<endl;
        }
    }
}
