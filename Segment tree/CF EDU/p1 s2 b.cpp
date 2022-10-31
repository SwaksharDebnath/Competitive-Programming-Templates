#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz 100005
ll tree[4*sz],arr[sz],n,m;
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
    tree[node] = tree[left]+tree[right];
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
ll query(ll node,ll b,ll e,ll val)
{
    if(tree[node] == 1 && b == e)
        return b;
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;
    if(tree[left] < val)
        return query(right,mid+1,e,val - tree[left]);
    else
        return query(left,b,mid,val);

}
int main()
{
    cin>>n>>m;
    for(ll i=1;i<=n;++i)cin>>arr[i];
    init(1,1,n);
    while(m--)
    {
        ll c,o;
        cin>>c>>o;
        if(c == 1)
            update(1,1,n,o+1);
        else
        {
            ll ans = query(1,1,n,o+1);
            cout<<ans-1<<endl;

        }
    }

}
