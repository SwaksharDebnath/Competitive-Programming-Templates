#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 100000
ll arr[MAX];
struct info{
    ll sum=0,prop=0;
}tree[MAX*4];

void init(ll node,ll b,ll e)
{
    if(b == e){
        tree[node].sum += arr[b];
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);

    tree[node].sum = tree[left].sum+tree[right].sum;
}

void update(ll node,ll b,ll e,ll i,ll j,ll x)
{
    if(i>e || j<b)
        return;
    else if(b>=i && e<=j)
    {
        tree[node].sum += ((e-b+1)*x);
        tree[node].prop += x;
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);

    tree[node].sum = tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}
ll query(ll node,ll b,ll e,ll i,ll j,ll carry)
{
    if(i>e || j<b)
        return 0;
    else if(b>=i && e<=j)
        return tree[node].sum + carry *(e-b+1);

    ll left = node * 2;
    ll right  = node * 2+1;
    ll mid = (b+e)/2;

    ll p = query(left,b,mid,i,j,carry+tree[node].prop);
    ll q = query(right,mid+1,e,i,j,carry+tree[node].prop);

    return p+q;
}
int main()
{
    ll x,n,m,a,b;
    char ch;
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=n;++i) scanf("%lld",&arr[i]);
    init(1,1,n);
    for(ll i=1;i<=2*n;++i)
        printf("%lld ",tree[i].sum);
    printf("\n");
    scanf("%lld %lld %lld",&a,&b,&x);
    update(1,1,n,a,b,x);
        for(ll i=1;i<=2*n;++i)
        printf("%lld ",tree[i].sum);
    printf("\n");    scanf("%lld %lld",&a,&b);
    ll r = query(1,1,n,a,b,0);
    cout<<r<<endl;
     /*while(m--)
     {
         cin>>ch;
         if(ch == 'u'){
            scanf("%lld %lld %lld ",&a,&b,&x);

         }
         else{
            scanf("%lld %lld",&a,&b);

         }
     }*/

}
