#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 100
vector<ll>v;
ll tree[4*MAX];
void init(ll nod,ll b,ll e)
{
    if(b == e)
    {
        tree[nod] = v[b];
        return;
    }
    ll left = nod * 2;
    ll right  = nod * 2 + 1;
    ll mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[nod] = tree[left]+tree[right];
}
int queri(ll nod,ll b,ll e,ll i,ll j)
{
    if(j<b || i>e)
        return 0;
    else if(b>=i && e<=j)
        return tree[nod];

    ll left = nod * 2;
    ll right = nod * 2 + 1;
    ll mid = (b+e)/2;

    ll p = queri(left,b,mid,i,j);
    ll q = queri(right,mid+1,e,i,j);
    return p+q;
}
void update(ll nod,ll b,ll e,ll i)
{
    if(b == i && e == i){
        tree[nod] = v[i]*10;
        return;
    }
    else if(i < b || i > e)
        return;
    ll left = nod * 2;
    ll right = nod * 2 + 1;
    ll mid = (b+e)/2;

    update(left,b,mid,i);
    update(right,mid+1,e,i);

    tree[nod] = tree[left]+tree[right];
}
int main()
{
    ll n,x,a,b;
    cin>>n;
    v.push_back(0);
    for(ll i=1;i<=n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    init(1,1,n);
    for(ll i=1;i<=4*n;++i)
        cout<<tree[i]<<" ";

    cout<<endl;
    for(ll i=0;i<3;++i)
    {

        cin>>a>>b;
        ll r = queri(1,1,n,a,b);
        cout<<r<<endl;
        cin>>x;
        update(1,1,n,x);
        for(ll i=1;i<=2*n;++i)
            cout<<tree[i]<<" ";
        cout<<endl;
    }

}
