#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,temp;
    cout<<"n:";
    cin>>n;
    vector<ll>v(n+1);
    for(ll i=1;i<=n;++i)
        cin>>v[i];

    for(ll i=1;i<=n;++i)
    {
        temp = i;
        for(ll j = i+1;j<=n;++j)
            if(v[j]< v[temp])
                temp = j;

        swap(v[i],v[temp]);

    }
    cout<<"sorted array :"<<endl;
    for(ll i=1;i<=n;++i)
        cout<<v[i]<<" ";
}
