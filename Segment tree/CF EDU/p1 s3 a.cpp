#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz 100005
ll tree[4*sz],n,m;
void update(ll node,ll b,ll e,ll i)
{
    if(e<i || b>i)return;
    if(b == i && e == i){
        tree[node] = 1;
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;
    update(left,b,mid,i);
    update(right,mid+1,e,i);
    tree[node] = tree[left]+tree[right];
}
ll query(ll node,ll b,ll e,ll i,ll j)
{
    if(e<i || b>j)return 0;
    if(b >= i && e <= j)
        return tree[node];
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;
    ll v1 = query(left,b,mid,i,j);
    ll v2 = query(right,mid+1,e,i,j);
    return v1+v2;
}
int main()
{
    cin>>n;
    for(ll i=1;i<=n;++i)
    {
        ll x;
        cin>>x;
        update(1,1,n,x);
        ll v = query(1,1,n,x+1,n);
        cout<<v<<" ";
    }
    cout<<endl;

}
