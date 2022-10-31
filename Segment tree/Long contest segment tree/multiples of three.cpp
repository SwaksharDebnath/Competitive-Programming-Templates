#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 100007
struct info{
    ll zero=0,one=0,two=0,prop=0;
}tree[4*MAX],temp;
ll s1=0,s2=0;
void magic(struct info *p)
{
    ll temp1=0;
    temp1 = p->one;
    p->one = p->zero;
    p->zero = p->two;
    p->two = temp1;
}
void init(ll node,ll b,ll e)
{
    if(b == e){
        tree[node].zero = 1;
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);

    tree[node].zero = e-b+1;
}
void update(ll node,ll b,ll e,ll i,ll j)
{
    if(b>=i && e<=j)
    {
        magic(&tree[node]);
        tree[node].prop = (tree[node].prop+1)%3;
        return;
    }
    else if(b>j || e<i)
        return;
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;
    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);

    temp.zero = (tree[left].zero + tree[right].zero);
    temp.one = (tree[left].one + tree[right].one);
    temp.two = (tree[left].two + tree[right].two);
    ll cont = tree[node].prop;

    for(ll i=0;i<cont;++i) magic(&temp);

    tree[node].zero = temp.zero;
    tree[node].one = temp.one;
    tree[node].two = temp.two;
}
ll query(ll node,ll b,ll e,ll i,ll j,ll carry)
{
    if(i>e || j<b)
        return 0;
    else if(b>=i && e<=j)
    {
        ll cnt = carry % 3;
        temp.zero = tree[node].zero;
        temp.one = tree[node].one;
        temp.two = tree[node].two;
        for(ll i=0;i<cnt;++i) magic(&temp);
        return temp.zero;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    ll p = query(left,b,mid,i,j,tree[node].prop+carry);
    ll q = query(right,mid+1,e,i,j,tree[node].prop+carry);

    return p+q;
}
int main()
{
    ll t,m,n,c,x,y;
    scanf("%lld",&t);
    for(ll i=1;i<=t;++i)
    {
        s1=0;s2=0;
        scanf("%lld %lld",&n,&m);
        init(1,1,n);
        printf("Case %lld:\n",i);
        while(m--)
        {
            scanf("%lld %lld %lld",&c,&x,&y);
            x++;y++;
            if(c == 0)
                update(1,1,n,x,y);
            else
            {
                s1 = query(1,1,n,x,y,0);

                cout<<s1<<endl;
            }
        }
        memset(tree,0,sizeof(tree));
    }
}
