#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz 100005
struct item{
    ll seg,prf,suf,sum;
};
item tree[4*sz];
ll n,m,arr[sz];
void init(ll node,ll b,ll e)
{
    if(b == e){
        if(arr[b]>0)
            tree[node] = {arr[b],arr[b],arr[b],arr[b]};
        else
            tree[node] = {0,0,0,arr[b]};
        return;
    }
    ll left = node*2;
    ll right = node*2+1;
    ll mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].seg = max(tree[left].seg,max(tree[right].seg,tree[left].suf+tree[right].prf));
    tree[node].prf = max(tree[left].prf,tree[left].sum+tree[right].prf);
    tree[node].suf = max(tree[right].suf,tree[right].sum+tree[left].suf);
    tree[node].sum = tree[left].sum+tree[right].sum;

}
void update(ll node,ll b,ll e,ll i,ll val)
{
    if(b>i || e<i)
        return;
    else if(b == i && e == i)
    {
        if(val>0)
            tree[node] = {val,val,val,val};
        else
            tree[node] = {0,0,0,val};
        return;
    }
    ll left = node * 2;
    ll right = node * 2 +1;
    ll mid = (b+e)/2;
    update(left,b,mid,i,val);
    update(right,mid+1,e,i,val);
    tree[node].seg = max(tree[left].seg,max(tree[right].seg,tree[left].suf+tree[right].prf));
    tree[node].prf = max(tree[left].prf,tree[left].sum+tree[right].prf);
    tree[node].suf = max(tree[right].suf,tree[right].sum+tree[left].suf);
    tree[node].sum = tree[left].sum+tree[right].sum;
}
int main()
{
    cin>>n>>m;
    for(ll i=1;i<=n;++i)cin>>arr[i];
    init(1,1,n);
    cout<<tree[1].seg<<endl;
    while(m--)
    {
        ll i,v;
        cin>>i>>v;
        update(1,1,n,i+1,v);
        cout<<tree[1].seg<<endl;
    }

}
