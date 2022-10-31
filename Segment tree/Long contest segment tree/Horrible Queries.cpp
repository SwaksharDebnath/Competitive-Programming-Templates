#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 100006
struct info{
    ll sum = 0;
    ll prop = 0;
}tree[4*MAX];
void update(ll node,ll b,ll e,ll i,ll j,ll x)
{
    if(b>=i && e<=j)
    {
        tree[node].sum += (e-b+1)*x;
        tree[node].prop += x;
        return;
    }
    else if(b>j || e<i)
        return;
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node].sum = tree[left].sum + tree[right].sum + (e-b+1)*tree[node].prop;
}
ll query(ll node,ll b,ll e,ll i,ll j,ll carry)
{
    if(b>=i && e<=j)
    {
        return tree[node].sum +(e-b+1)*carry;
    }
    else if(b>j || e<i)
        return 0;
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    ll p = query(left,b,mid,i,j,carry+tree[node].prop);
    ll q = query(right,mid+1,e,i,j,carry+tree[node].prop);

    return p+q;
}
int main()
{
    ll t,n,m,c,x,y,v,val;
    scanf("%lld",&t);
    for(ll i=1;i<=t;++i)
    {
        scanf("%lld %lld",&n,&m);
        printf("Case %lld:\n",i);
        while(m--)
        {
            scanf("%lld",&c);
            if(c == 0)
            {
                scanf("%lld %lld %lld",&x,&y,&v);
                x++;y++;
                update(1,1,n,x,y,v);
            }
            else
            {
                scanf("%lld %lld",&x,&y);
                x++;y++;
                val = query(1,1,n,x,y,0);
                printf("%lld\n",val);
            }
        }
        memset(tree,0,sizeof (tree));
    }
}
