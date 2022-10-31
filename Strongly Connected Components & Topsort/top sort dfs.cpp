#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>graph[200];
ll col[200],disc[200],tim=0,n,m;
vector<pair<ll,ll> >fin(200,{0,0});
void dfs(ll u)
{
    disc[u]=tim;
    col[u]=1;
    for(auto v: graph[u])
        if(col[v] == 0)
            dfs(v);
    col[u]=2;
    fin[u].first=++tim;
    fin[u].second=u;
}
int main()
{
    cin>>n>>m;
    for(ll i=0;i<m;++i)
    {
        ll x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }
    memset(disc,-1,sizeof(disc));
    for(ll i=0;i<n;++i)
        if(disc[i] == -1)
            dfs(i);

    sort(fin.begin(),fin.begin()+n,greater<pair<ll,ll> >());
    for(ll i=0;i<n;++i)
        cout<<fin[i].second<<" ";

}
