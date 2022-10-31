#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,m,x;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0;i<n;++i)
        cin>>v[i];
    cin>>m;
    vector<ll>::iterator it;
    while(m--)
    {
        cin>>x;
        it = lower_bound(v.begin(),v.end(),x);
        if(it == v.begin())
            cout<<"X ";
        else
            cout<<*(it-1)<<" ";

        it = upper_bound(v.begin(),v.end(),x);
        if(it == v.end())
            cout<<"X"<<endl;
        else
            cout<<*it<<endl;
    }
}

