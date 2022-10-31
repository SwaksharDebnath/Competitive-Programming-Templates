#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
map<ll,vector<ll> >graph,bridge_tree;
map<pair<ll,ll>,ll >bridge;
map<ll,ll>mark;
vector<pair<ll,ll> >links;
ll vis[100009];
ll low[100009];
ll dis[100009];

ll n,m,timer=0,x,far=0;
void dfs1(ll u,ll parent)
{
    vis[u]=1;
    dis[u]=low[u]=timer++;
    for(ll i=0;i<graph[u].size();++i)
    {
        ll v = graph[u][i];
        if(v == parent)continue;
        if(vis[v]==1)
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
    vis[u] = 1;
    for(ll i=0;i<graph[u].size();++i)
    {
        ll v = graph[u][i];
        if(bridge[{u,v}]==1)continue;
        if(vis[v]==0)
            dfs2(v,node);
    }
}
void dfs_diameter(ll u,ll cnt)
{
    vis[u]=1;
    for(ll i=0;i<bridge_tree[u].size();++i)
    {
        if(vis[bridge_tree[u][i]] == 0){
            if(cnt>=far){
                x = bridge_tree[u][i];
                far = cnt;
            }
            dfs_diameter(bridge_tree[u][i],cnt+1);
        }
    }
}
void diameter()
{
    far = 0;
    memset(vis,0,sizeof(vis));
    dfs_diameter(1,1);
    memset(vis,0,sizeof(vis));
    far = 0;
    dfs_diameter(x,1);

}
int solve()
{
    for(ll i=1;i<=n;++i)
        if(vis[i]==0)
            timer=0,dfs1(i,-1);
    memset(vis,0,sizeof(vis));
    ll node=1;
    for(ll i=1;i<=n;++i)
        if(vis[i]==0)
            dfs2(i,node),node++;

    ///constructing bridge tree
    for(ll i=0;i<links.size();++i)
    {
        ll a = mark[links[i].first];
        ll b = mark[links[i].second];
        bridge_tree[a].push_back(b);
        bridge_tree[b].push_back(a);
    }
    diameter();
    //cout<<links.size()<<" "<<far<<endl;
    return links.size()-far;


}
int main()
{
    Fast;
    ll test;
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
        cout<<ans<<endl;
        graph.clear();
        bridge_tree.clear();
        bridge.clear();
        mark.clear();
        links.clear();
        memset(low,0,sizeof(low));
        memset(dis,0,sizeof(dis));
        memset(vis,0,sizeof(vis));
    }

}
