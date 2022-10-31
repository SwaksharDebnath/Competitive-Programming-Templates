#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,j;
    cout<<"n:";
    cin>>n;
    vector<ll>v(n+1);
    for(ll i=1;i<=n;++i)
        cin>>v[i];
    for(ll i=2;i<=n;++i)
    {
        j=i;
        while(j>1 && v[j]<v[j-1])
        {
            swap(v[j],v[j-1]);
            --j;
        }

    }
    cout<<"sorted array :"<<endl;
    for(ll i=1;i<=n;++i)
        cout<<v[i]<<" ";
}
