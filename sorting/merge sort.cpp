#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void marge(vector<ll> &v,ll start,ll mid,ll nd)
{
    ll p = start,q = mid + 1;
    ll arr[nd - start + 1],k=0;
    for(ll i = start;i <= nd; ++i)
    {
        if(p > mid)
            arr[k++] = v[q++];
        else if(q > nd)
            arr[k++] = v[p++];
        else if(v[p] < v[q])
            arr[k++] = v[p++];
        else
            arr[k++] = v[q++];
    }
    for(ll i = 0;i < k;++i)
        v[start++] = arr[i];
}
void mergesort(vector<ll> &v,ll start,ll nd)
{
    if(start < nd)
    {
        ll mid = (start + nd)/2;

        mergesort(v,start,mid);
        mergesort(v,mid+1,nd);
        marge(v,start,mid,nd);
    }
}
int main()
{
    ll n,x;
    cin>>n;
    vector<ll>v;
    for(ll i=0;i<n;++i){
        cin>>x;
        v.push_back(x);
    }

    mergesort(v,0,n-1);
    for(ll i = 0;i < n;++i)
        cout<<v[i]<<" ";
}
