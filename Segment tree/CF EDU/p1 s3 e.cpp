#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100005

ll n,m;
ll tree[4*MAX],arr[MAX],q[MAX];
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
void update(ll node,ll b,ll e,ll id,ll val)
{
    if(b>id || e<id)return;
    if(b == id && e == id){
        tree[node] += val;
        return;
    }
    ll left = node * 2;
    ll right=node * 2 + 1;
    ll mid = (b+e)/2;
    update(left,b,mid,id,val);
    update(right,mid+1,e,id,val);
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
int main()
{
    cin>>n>>m;

    /*for(ll i=1;i<=n;++i)
    {
        cin>>arr[i];
        q[i] = q[i-1]+i;
    }
    init(1,1,n);*/
    while(m--)
    {
        ll x;
        cin>>x;
        if(x == 1)
        {
            ll l,r,v;
            cin>>l>>r>>v;
            update(1,1,n,l+1,v);
            update(1,1,n,r+1,-v);
        }
        else{
            ll id;
            cin>>id;
            ll v = query(1,1,n,1,id+1);
            cout<<v<<endl;
        }
    }
}
