#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define siz 300007
vector<ll>graph[siz],bridge_tree[siz];
map<pair<ll,ll>,ll >bridge;
map<ll,ll>mark;
vector<pair<ll,ll> >links;
ll vis[siz];
ll low[siz];
ll dis[siz];

ll n,m,timer=0,x,st,nd,far=0;
void dfs1(ll u,ll parent)
{
    vis[u]=1;
    dis[u]=low[u]=timer++;
    for(ll i=0;i<graph[u].size();++i)
    {
        ll v = graph[u][i];
        if(v == parent)continue;
        if(vis[v] == 1)
            low[u] = min(low[u],dis[v]);
        else
        {
            dfs1(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v]>dis[u])
            {
                bridge[{u,v}]=1;
                bridge[{v,u}]=1;
                links.push_back({u,v});
            }
        }
    }
}
void dfs2(ll u,ll node)
{
    mark[u]=node;
    vis[u]=1;
    for(ll i=0;i<graph[u].size();++i)
    {
        ll v = graph[u][i];
        if(bridge[{u,v}] == 1)continue;
        if(vis[v] == 0)
            dfs2(v,node);
    }
}
void dfs_diameter(ll u,ll cnt)
{
    vis[u]=1;
    for(ll i=0;i<bridge_tree[u].size();++i)
    {
        ll v = bridge_tree[u][i];
        if(vis[v]==0)
        {
            if(cnt>=far)
            {
                x = v;
                far = cnt;
            }
            dfs_diameter(v,cnt+1);
        }
    }
}
void diameter()
{
    far = 0;
    memset(vis,0,sizeof(vis));
    dfs_diameter(1,1);st=x;
    memset(vis,0,sizeof(vis));
    far = 0;
    dfs_diameter(x,1);nd=x;
}
void solve()
{
    for(ll i=1;i<=n;++i)
        if(vis[i] == 0)
            timer=0,dfs1(i,-1);
    memset(vis,0,sizeof(vis));
    ll node=1;
    for(ll i=1;i<=n;++i)
        if(vis[i] == 0)
            dfs2(i,node),node++;

    for(ll i=0;i<links.size();++i)
    {
        ll a = mark[links[i].first];
        ll b = mark[links[i].second];

        bridge_tree[a].push_back(b);
        bridge_tree[b].push_back(a);
    }
    diameter();
    cout<<far<<endl;
}
int main()
{
    Fast;
    ll test;

        cin>>n>>m;
        for(ll i=0;i<m;++i)
        {
            ll x,y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        solve();
}
