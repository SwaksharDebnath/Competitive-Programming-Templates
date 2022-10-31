#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 100003
ll v[MAX];
ll tree[4*MAX]={0};
void init(ll node,ll b,ll e)
{
    if(b == e){
        tree[node] = v[b];
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node] = min(tree[left],tree[right]);
}
int queri(ll node,ll b,ll e,ll i,ll j)
{
    if(i>e || j<b)
        return -1;
    else if(b>=i && e<=j)
        return tree[node];
    ll left = node * 2;
    ll right = node * 2 +1;
    ll mid = (b+e)/2;
    ll p = queri(left,b,mid,i,j);
    ll q = queri(right,mid+1,e,i,j);
    if(p ==-1 || q ==-1)
        return max(p,q);
    return min(p,q);
}
int main()
{
    ll t,n,m,x,a,b;
    scanf("%lld",&t);
    for(ll i=1;i<=t;++i)
    {
        scanf("%lld%lld",&n,&m);
        v[0]=-1;
        for(ll j=1;j<=n;++j)
        {
            scanf("%lld",&v[j]);
        }
        init(1,1,n);
        //for(ll i=1;i<2*n;++i)
            //cout<<tree[i]<<endl;
        printf("Case %lld:\n",i);
        while(m--){
            scanf("%lld%lld",&a,&b);
            x = queri(1,1,n,a,b);
            printf("%lld\n",x);

        }
        v[MAX]={0};tree[4*MAX]={0};

    }
}
