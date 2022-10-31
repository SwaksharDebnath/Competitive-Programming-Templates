#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 150007
ll tree[4*MAX],n;
void init(ll node,ll b,ll e)
{
    if(b == e)
    {
        if(b <= n) tree[node] = 1;
        else tree[node] = 0;
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);

    tree[node] = tree[left]+tree[right];
}
void update(ll node,ll b,ll e,ll i)
{
    if(b == i && e == i)
    {
        ll c = tree[node]^1;
        tree[node] = c;
        return;
    }
    else if(b>i || e<i)
        return;
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    update(left,b,mid,i);
    update(right,mid+1,e,i);

    tree[node] = tree[left]+tree[right];
}
ll query(ll node,ll b,ll e,ll i,ll j)
{
    if(b>j || e<i)
        return 0;
    else if(b>=i && e<=j)
        return tree[node];
    ll left = node*2;
    ll right = node*2+1;
    ll mid = (b+e)/2;
    ll p=query(left,b,mid,i,j);
    ll q=query(right,mid+1,e,i,j);
    return p+q;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t,m,x,sz,sz1,l,h,mid,ans;
    char ch;
    cin>>t;
    vector<ll>v;
    for(ll i=1;i<=t;++i)
    {
    v.push_back(-1);
        cin>>n>>m;
        sz = n;
        sz1 = n;
        for(ll j=0;j<n;++j)
        {
            cin>>x;
            v.push_back(x);
        }
        init(1,1,MAX);
        cout<<"Case "<<i<<":"<<endl;
        for(ll j=0;j<m;++j)
        {
            cin>>ch>>x;
            if(ch == 'c')
            {
                if(x>sz1)
                    cout<<"none"<<endl;
                else
                {
                    l=1;h=sz;
                    while(l<h)
                    {
                        mid = (l+h)/2;
                        ans = query(1,1,MAX,1,mid);
                        if(x<=ans)
                            h = mid;
                        else
                            l = mid+1;
                    }
                    sz1--;
                    cout<<v[h]<<endl;
                    update(1,1,MAX,h);

                }
            }
            else{
                sz++;
                sz1++;
                v.push_back(x);
                update(1,1,MAX,sz);
            }
        }
        v.clear();
        memset(tree,0,sizeof(tree));
    }
}
