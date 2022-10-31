#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 100003
ll arr[MAX];
struct info{
    ll mx=0,md=0;
}tree[4*MAX],temp,t3;
void init(ll node,ll b,ll e)
{
    if(b == e)
    {
        tree[node].mx = arr[b];
        tree[node].md = 0;
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);

    tree[node].mx = max(tree[left].mx,tree[right].mx);
    tree[node].md = max(min(tree[left].mx,tree[right].mx),max(tree[left].md,tree[right].md));
}
void update(ll node,ll b,ll e,ll i,ll x)
{
    if(b==i && e==i)
    {
        arr[b] = x;
        tree[node].mx = arr[b];
        tree[node].md = 0;
        return;
    }
    else if(i<b || i>e)
        return;
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    update(left,b,mid,i,x);
    update(right,mid+1,e,i,x);

    tree[node].mx = max(tree[left].mx,tree[right].mx);
    tree[node].md = max(min(tree[left].mx,tree[right].mx),max(tree[left].md,tree[right].md));

}
info query(ll node,ll b,ll e,ll i,ll j)
{
    if(b>=i && e<=j)
    {
        return tree[node];
    }
    else if(b>j || e<i)
        return t3;
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    info p1 = query(left,b,mid,i,j);
    info p2 = query(right,mid+1,e,i,j);
    temp.mx = max(p1.mx,p2.mx);
    temp.md = max(min(p1.mx,p2.mx),max(p1.md,p2.md));
    return temp;
}
int main()
{
    ll n,q;
    scanf("%lld",&n);
    for(ll i=1;i<=n;++i) scanf("%lld",&arr[i]);
    init(1,1,n);
    scanf("%lld",&q);
    char ch;
    ll b,e;
    info t1;
    for(ll i=0;i<q;++i)
    {
        getchar();
        scanf("%c%lld %lld",&ch,&b,&e);
        //cout<<q<<endl;
        if(ch == 'Q')
        {
            t1 = query(1,1,n,b,e);
            printf("%lld\n",t1.mx+t1.md);
        }
        else if(ch == 'U')
            update(1,1,n,b,e);
    }
    /*for(ll i=1;i<2*n;++i)
        cout<<tree[i].mx<<" "<<tree[i].md<<endl;
    cout<<"-------------------"<<endl;
    ll i , x;
    cin>>i>>x;
    update(1,1,n,i,x);
    for(ll i=1;i<2*n;++i)
        cout<<tree[i].mx<<" "<<tree[i].md<<endl;
    info t1;
    cin>>i>>x;
    t1 = query(1,1,n,i,x);
    cout<<t1.mx+t1.md<<endl;*/


}
