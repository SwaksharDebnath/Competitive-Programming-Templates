#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 200005
struct vrtx{
    ll r1c1,r1c2,r2c1,r2c2;
}tree[4*MAX],arr[MAX];
ll r,n,m;
void init(ll node,ll b,ll e)
{
    if(b == e){
        tree[node].r1c1 = (arr[b].r1c1)%r;
        tree[node].r1c2 = (arr[b].r1c2)%r;
        tree[node].r2c1 = (arr[b].r2c1)%r;
        tree[node].r2c2 = (arr[b].r2c2)%r;

        //cout<<tree[node].r1c1<<" "<<tree[node].r1c2<<endl;
        //cout<<tree[node].r2c1<<" "<<tree[node].r2c2<<endl<<endl;
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].r1c1 = ((tree[left].r1c1*tree[right].r1c1)%r+(tree[left].r1c2*tree[right].r2c1)%r)%r;
    tree[node].r1c2 = ((tree[left].r1c1*tree[right].r1c2)%r+(tree[left].r1c2*tree[right].r2c2)%r)%r;
    tree[node].r2c1 = ((tree[left].r2c1*tree[right].r1c1)%r+(tree[left].r2c2*tree[right].r2c1)%r)%r;
    tree[node].r2c2 = ((tree[left].r2c1*tree[right].r1c2)%r+(tree[left].r2c2*tree[right].r2c2)%r)%r;
}
vrtx query(ll node,ll b,ll e,ll i,ll j)
{
    if(b>=i && e<=j)return tree[node];
    if(b>j || e<i)return {1,0,0,1};
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;
    vrtx v1 = query(left,b,mid,i,j);
    vrtx v2 = query(right,mid+1,e,i,j);
    vrtx v;
    v.r1c1 = ((v1.r1c1*v2.r1c1)%r+(v1.r1c2*v2.r2c1)%r)%r;
    v.r1c2 = ((v1.r1c1*v2.r1c2)%r+(v1.r1c2*v2.r2c2)%r)%r;
    v.r2c1 = ((v1.r2c1*v2.r1c1)%r+(v1.r2c2*v2.r2c1)%r)%r;
    v.r2c2 = ((v1.r2c1*v2.r1c2)%r+(v1.r2c2*v2.r2c2)%r)%r;
    return v;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    scanf("%lld %lld %lld",&r,&n,&m);
    for(ll i=1;i<=n;++i){
        scanf("%lld %lld %lld %lld",&arr[i].r1c1,&arr[i].r1c2,&arr[i].r2c1,&arr[i].r2c2);
    }
    //cout<<"----------------------------"<<endl;
    init(1,1,n);
    while(m--)
    {
        ll x,y;
        scanf("%lld %lld",&x,&y);
        vrtx ans = query(1,1,n,x,y);
        printf("%lld %lld\n%lld %lld\n\n",ans.r1c1,ans.r1c2,ans.r2c1,ans.r2c2);
    }
}
