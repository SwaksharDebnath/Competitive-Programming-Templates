#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
map<ll,vector<ll> >graph;
map<pair<ll,ll>,ll >bridge;
map<ll,ll>mark;
vector<pair<ll,ll> >links;
ll vis[10009],low[10009],dis[10009],degree[10009];
ll n,m,timer=0;
void dfs1(ll u,ll parent)
{
    vis[u]=1;
    dis[u]=low[u]=timer++;
    for(ll i=0;i<graph[u].size();++i)
    {
        if(graph[u][i] == parent)continue;
        if(vis[graph[u][i]] == 1)
            low[u] = min(low[u],dis[graph[u][i]]);
        else
        {
            dfs1(graph[u][i],u);
            low[u] = min(low[u],low[graph[u][i]]);
            if(low[graph[u][i]]>dis[u])
            {
                bridge[{graph[u][i],u}]=1;
                bridge[{u,graph[u][i]}]=1;
                links.push_back({u,graph[u][i]});
            }
        }
    }

}
void dfs2(ll u,ll node)
{
    vis[u]=1;
    mark[u]=node;
    for(ll i=0;i<graph[u].size();++i){
        if(bridge[{graph[u][i],u}]==1)
            continue;
        if(vis[graph[u][i]]==0)
            dfs2(graph[u][i],node);
    }
}
int solve()
{
    for(ll i=0;i<n;++i)
    {
        if(vis[i] == 0)
            timer=0,dfs1(i,-1);
    }
    memset(vis,0,sizeof(vis));
    ll node=1,leaf=0;
    for(ll i=0;i<n;++i)
    {
        if(vis[i] == 0)
            dfs2(i,node),node++;
    }
    memset(degree,0,sizeof(degree));
    for(ll i=0;i<links.size();++i)
    {
        ll a = mark[links[i].first];
        ll b = mark[links[i].second];
        degree[a]++;
        degree[b]++;
    }
    for(ll i=1;i<node;++i)
        if(degree[i] == 1)leaf++;
    //cout<<leaf<<endl;

    return (leaf+1)/2;
}
int main()
{
    Fast;
    ll test,t=1;
    cin>>test;
    while(test--)
    {
        cin>>n>>m;
        for(ll i=0;i<m;++i)
        {
            ll x,y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        ll ans = solve();
        cout<<"Case "<<t++<<": "<<ans<<endl;
        graph.clear();
        mark.clear();
        bridge.clear();
        links.clear();
        memset(vis,0,sizeof(vis));
        memset(low,0,sizeof(low));
        memset(dis,0,sizeof(dis));

    }
}
