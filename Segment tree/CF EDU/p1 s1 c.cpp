#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100005

ll n,m,arr[MAX];
vector<pair<ll,ll> >tree(4*MAX,{0,0});

void init(ll node,ll b,ll e)
{
    if(b == e){
        tree[node].first = arr[b];
        tree[node].second = 1;
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].first = min(tree[left].first,tree[right].first);
    if(tree[node].first == tree[left].first)tree[node].second += tree[left].second;
    if(tree[node].first == tree[right].first)tree[node].second += tree[right].second;
}
void update(ll node,ll b,ll e,ll id,ll val)
{
    if(b>id || e<id)return;
    if(b == id && e == id){
        tree[node].first = val;
        tree[node].second = 1;
        return;
    }
    ll left = node * 2;
    ll right=node * 2 + 1;
    ll mid = (b+e)/2;
    update(left,b,mid,id,val);
    update(right,mid+1,e,id,val);
    tree[node].first = min(tree[left].first,tree[right].first);
    tree[node].second = 0;
    if(tree[node].first == tree[left].first)tree[node].second += tree[left].second;
    if(tree[node].first == tree[right].first)tree[node].second += tree[right].second;
}
pair<ll,ll> query(ll node,ll b,ll e,ll i,ll j)
{
    if(b>=i && e<=j)return tree[node];
    if(b>j || e<i)return {1e12+3,0};
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;
    auto v1 = query(left,b,mid,i,j);
    auto v2 = query(right,mid+1,e,i,j);
    pair<ll,ll>res={0,0};
    res.first = min(v1.first,v2.first);
    if(res.first == v1.first)res.second += v1.second;
    if(res.first == v2.first)res.second += v2.second;
    return res;
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
            auto val = query(1,1,n,x+1,y);
            cout<<val.first<<" "<<val.second<<endl;
        }
    }
}

