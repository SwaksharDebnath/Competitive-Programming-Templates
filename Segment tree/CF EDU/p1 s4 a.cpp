#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100005
struct vrtx{
    ll a,b;
}tree[4*MAX];
struct nd{
    ll a,b,c,d;
};
ll n,m;
ll arr[MAX],q[MAX];
void init(ll node,ll b,ll e)
{
    if(b == e){
        tree[node].a = arr[b];
        tree[node].b = 0;
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    if(((abs(b-mid)+1)&1) == 0){
        tree[node].a = tree[left].a+tree[right].a;
        tree[node].b = tree[left].b+tree[right].b;
    }else{
        tree[node].a = tree[left].a+tree[right].b;
        tree[node].b = tree[left].b+tree[right].a;
    }
}
void update(ll node,ll b,ll e,ll id,ll val)
{
    if(b>id || e<id)return;
    if(b == id && e == id){
        tree[node].a = val;
        return;
    }
    ll left = node * 2;
    ll right=node * 2 + 1;
    ll mid = (b+e)/2;
    update(left,b,mid,id,val);
    update(right,mid+1,e,id,val);
    if(((abs(b-mid)+1)&1) == 0){
        tree[node].a = tree[left].a+tree[right].a;
        tree[node].b = tree[left].b+tree[right].b;
    }else{
        tree[node].a = tree[left].a+tree[right].b;
        tree[node].b = tree[left].b+tree[right].a;
    }
}
nd query(ll node,ll b,ll e,ll i,ll j)
{
    if(b>=i && e<=j){
        //cout<<b<<" "<<e<<" "<<tree[node].a<<" "<<tree[node].b<<endl;
        return {b,e,tree[node].a,tree[node].b};
    }
    if(b>j || e<i)return {-1,-1,-1,-1};
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;
    nd v = {-1,-1,-1,-1};
    nd v1 = query(left,b,mid,i,j);
    nd v2 = query(right,mid+1,e,i,j);
    if(v1.a != -1)
    {
        if(v2.a != -1){
            nd t1;
            t1.a=v1.a;t1.b=v2.b;
            if(((abs(v1.b-v1.a)+1) & 1) == 0){
                t1.c = v1.c+v2.c;
                t1.d = v1.d+v2.d;
            }else{
                t1.c = v1.c+v2.d;
                t1.d = v1.d+v2.c;
            }
            return t1;
        }else{
            return v1;
        }
    }else{
        return v2;
    }

}
int main()
{
    cin>>n;
    for(ll i=1;i<=n;++i)cin>>arr[i];
    init(1,1,n);
    cin>>m;
    while(m--)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        if(x == 0)update(1,1,n,y,z);
        else{
            nd ans = query(1,1,n,y,z);
            cout<<ans.c-ans.d<<endl;

        }
    }
    //cout<<ans.a<<" "<<ans.b<<" "<<ans.c<<" "<<ans.d<<endl;

}
