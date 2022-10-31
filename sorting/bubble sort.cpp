#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n;
    cout<<"n:";
    cin>>n;
    vector<ll>v(n);
    for(ll i=0;i<n;++i)
        cin>>v[i];
    for(ll i=0;i<n-i-1;++i)
    {
        for(ll j=0;j<n-i;++j)
        {
            if(v[j]>v[j+1])
                swap(v[j],v[j+1]);
        }
    }
    cout<<"sorted array :"<<endl;
    for(ll i=0;i<n;++i)
        cout<<v[i]<<" ";
}
