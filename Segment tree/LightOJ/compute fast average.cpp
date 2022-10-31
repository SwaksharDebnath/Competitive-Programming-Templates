#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz 100007
struct node{
    ll sum,prop,el;
}tree[4*sz];
ll n,m;
void init(ll node,ll b,ll e)
{
    if(b == e){
        tree[node].el = 1;
        tree[node].prop = -1;
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);

    tree[node].el = tree[left].el+tree[right].el;
    tree[node].prop = -1;
}
void update(ll node,ll b,ll e,ll i,ll j,ll x)
{
    if(i>e || j<b)
        return;
    else if(b>=i && e<=j)
    {
        tree[node].sum = ((e-b+1)*x);
        tree[node].prop = -1;
        if(tree[node].el != 1){
            tree[node*2].prop = x;
            tree[node*2].sum = x*tree[node*2].el;
            tree[node*2+1].prop = x;
            tree[node*2+1].sum = x*tree[node*2+1].el;
        }
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;
    if(tree[node].prop!=-1)
    {
        tree[left].prop = tree[node].prop;
        tree[right].prop = tree[node].prop;
        tree[left].sum = tree[node].prop*tree[left].el;
        tree[right].sum = tree[node].prop*tree[right].el;
        tree[node].prop=-1;
    }

    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);

    tree[node].sum = tree[left].sum+tree[right].sum;
}
ll query(ll node,ll b,ll e,ll i,ll j)
{
    if(i>e || j<b)
        return 0;
    else if(b>=i && e<=j)
    {

        if(b!=e && tree[node].prop!=-1)
        {
            ll x = tree[node].prop;
            tree[node*2].prop = x;
            tree[node*2].sum = x*tree[node*2].el;
            tree[node*2+1].prop = x;
            tree[node*2+1].sum = x*tree[node*2+1].el;
            tree[node].prop = -1;
        }
        return tree[node].sum;
    }

    ll left = node * 2;
    ll right  = node * 2+1;
    ll mid = (b+e)/2;

    if(tree[node].prop!=-1)
    {
        tree[left].prop = tree[node].prop;
        tree[right].prop = tree[node].prop;
        tree[left].sum = tree[node].prop*tree[left].el;
        tree[right].sum = tree[node].prop*tree[right].el;
        tree[node].prop = -1;
    }

    ll p = query(left,b,mid,i,j);
    ll q = query(right,mid+1,e,i,j);

    return p+q;
}
int main()
{
    ll test,tc=1;
    cin>>test;
    while(test--)
    {
        cin>>n>>m;
        init(1,1,n);
        printf("Case %lld:\n",tc++);
        while(m--)
        {
            ll v,x,y,z;
            cin>>v>>x>>y;
            if(v == 1)
            {
                cin>>z;
                update(1,1,n,x+1,y+1,z);
            }
            else{
                ll v = query(1,1,n,x+1,y+1);
                ll d = y-x+1;
                if(v%d == 0){
                    cout<<v/d<<endl;
                }
                else{
                    ll x = __gcd(v,d);
                    cout<<(v/x)<<"/"<<(d/x)<<endl;
                }
            }
        }
        memset(tree,0,sizeof(tree));

    }
}
