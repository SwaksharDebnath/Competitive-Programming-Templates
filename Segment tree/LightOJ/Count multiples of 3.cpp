#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz 100007
struct info{
    ll z,o,t,th,prop;
}tree[4*sz];
ll n,q;
void init(ll node,ll b,ll e)
{
    if(b == e){
        tree[node].z = 1;
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);

    tree[node].z = tree[left].z+tree[right].z;
}
void update(ll node,ll b,ll e,ll i,ll j)
{
    if(b>j || e<i)return;
    else if(b>=i && e<=j){
        ll t1 = tree[node].o;
        tree[node].o = tree[node].z+tree[node].th;
        ll t2 = tree[node].t;
        tree[node].t = t1;
        tree[node].th = t2;
        tree[node].z = 0;
        tree[node].prop += 1;
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);

    tree[node].z = tree[left].z+tree[right].z;
    tree[node].o = tree[left].o+tree[right].o;
    tree[node].t = tree[left].t+tree[right].t;
    tree[node].th = tree[left].th+tree[right].th;
    if(tree[node].prop != 0)
    {
        if(tree[node].prop % 3 == 0)
            tree[node].th += tree[node].z;
        else if(tree[node].prop % 3 == 1)
        {
            ll t1 = tree[node].o;
            tree[node].o = tree[node].z+tree[node].th;
            ll t2 = tree[node].t;
            tree[node].t = t1;
            tree[node].th = t2;
            tree[node].z = 0;
        }
        else if(tree[node].prop % 3 == 2)
        {
            ll t1 = tree[node].t;
            tree[node].t = tree[node].z+tree[node].th;
            ll t2 = tree[node].o;
            tree[node].o = t1;
            tree[node].th = t2;
            tree[node].z = 0;
        }
    }
}
ll query(ll node,ll b,ll e,ll i,ll j,ll carry)
{
    if(b>j || e<i)return 0;
    else if(b>=i && e<=j)
    {
        if(carry !=0 )
        {
            ll ans=0;
            if(carry%3 == 0)
                ans = tree[node].z+tree[node].th;
            else if(carry % 3 == 1)
                ans = tree[node].t;
            else if(carry % 3 == 2)
                ans = tree[node].o;
            return ans;
        }
        else
            return tree[node].th+tree[node].z;
    }

    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    ll p = query(left,b,mid,i,j,carry+tree[node].prop);
    ll q = query(right,mid+1,e,i,j,carry+tree[node].prop);

    return p+q;

}
void clr()
{
    memset(tree,0,sizeof(tree));
}
int main()
{
    ll test,tc=1;
    cin>>test;
    while(test--)
    {

        clr();
        cin>>n>>q;
        init(1,1,n);
        printf("Case %lld:\n",tc++);
        while(q--)
        {
            ll x,y,z;
            cin>>x>>y>>z;
            if(x == 0)
                update(1,1,n,y+1,z+1);
            else{
                ll ans = query(1,1,n,y+1,z+1,0);
                cout<<ans<<endl;
            }

        }

    }





}
