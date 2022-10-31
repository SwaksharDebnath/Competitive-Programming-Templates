#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 100000
vector<ll>v[MAX];
int main()
{
    ll node,edge,x,y;
    cin>>node>>edge;
    for(ll i=1;i<=edge;++i)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cout<<"adjacency list:"<<endl;;
    for(ll i=1;i<=node;++i)
    {
        cout<<"node"<<i<<"-->";
        for(ll j=0;j<v[i].size();++j)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}
