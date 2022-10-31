#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz 100005
ll n,m,tree[sz*4],arr[sz],ans[sz];
void init(ll node,ll b,ll e)
{
    if(b == e){
        tree[node] = 1;
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
        tree[node] = 0;
        return;
    }
    ll left = node * 2;
    ll right=node * 2 + 1;
    ll mid = (b+e)/2;
    update(left,b,mid,id);
    update(right,mid+1,e,id);
    tree[node] = tree[left]+tree[right];
}
ll  query(ll node,ll b,ll e,ll i,ll j,ll val)
{
    if(b>j || e<i)return 0;
    if(val == 1 && b == e )
        return b;
    ll left = node * 2;
    ll right=node * 2 + 1;
    ll mid = (b+e)/2;
    ll v1=0,v2=0;
    if(tree[right] < val)
        v1 = query(left,b,mid,i,j,val-tree[right]);
    else
        v2 = query(right,mid+1,e,i,j,val);
    return max(v1,v2);

}
int main()
{
    cin>>n;
    for(ll i=1;i<=n;++i)cin>>arr[i];
    init(1,1,n);
    for(ll i=n;i>=1;--i)
    {
        ll aa;
        if(i == n)
        {
            aa = query(1,1,n,1,n,arr[i]+1);
            update(1,1,n,aa);
            ans[i] = aa;
        }
        else
        {
            if(arr[i]<arr[i+1])
                aa = query(1,1,n,ans[i+1]+1,n,arr[i]+1);
            else
                aa = query(1,1,n,1,ans[i+1]-1,arr[i]+1);
            update(1,1,n,aa);
            ans[i] = aa;
        }
    }
    for(ll i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    cout<<endl;
    //cout<<tree[1]<<endl;

}
