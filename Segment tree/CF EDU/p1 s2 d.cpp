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
    tree[node] = max(tree[left],tree[right]);
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
    tree[node] = max(tree[left],tree[right]);
}
ll query(ll node,ll b,ll e,ll i,ll val)
{
    if(e<i || tree[node]<val)
        return -1;
    if(b == e)
        return b;
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;
    ll v1=0,v2=-1;
    v1 = query(left,b,mid,i,val);
    if(v1 == -1)
        v2 = query(right,mid+1,e,i,val);
    return v1+v2+1;

}
int main()
{
    cin>>n>>m;
    for(ll i=1;i<=n;++i)cin>>arr[i];
    init(1,1,n);
    while(m--)
    {
        ll c;
        cin>>c;
        if(c == 1)
        {
            ll i,v;
            cin>>i>>v;
            update(1,1,n,i+1,v);
        }
        else
        {
            ll o,l;
            cin>>o>>l;

            ll ans = query(1,1,n,l+1,o);
            if(ans == -1)ans=0;
            cout<<ans-1<<endl;



        }
    }

}

