#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define siz 100009
vector<pair<ll,ll> >graph[siz],bridge_tree[siz];
map<pair<ll,ll>,ll >bridge;
map<ll,ll>mark;
vector<pair<ll,pair<ll,ll> > >links;
ll vis[siz];
ll low[siz];
ll dis[siz];
ll n,m,timer=0,x,st,nd,far=0,path_cost[2][siz];

void dfs1(ll u,ll parent)
{
    vis[u]=1;
    dis[u]=low[u]=timer++;
    for(ll i=0;i<graph[u].size();++i)
    {
        ll v = graph[u][i].first;
        ll w = graph[u][i].second;
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
                links.push_back({u,{v,w}});
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
        ll v = graph[u][i].first;
        if(bridge[{u,v}]==1)continue;
        if(vis[v]==0)
            dfs2(v,node);
    }
}
void dfs_diameter(ll u,ll cost)
{
    vis[u]=1;
    if(cost>far){
        x = u;far = cost;}

    for(ll i=0;i<bridge_tree[u].size();++i)
    {
        ll v = bridge_tree[u][i].first;
        ll w = bridge_tree[u][i].second;

        if(vis[v]==0)
            dfs_diameter(v,cost+w);
    }
}
void diameter()
{
    far = 0;
    memset(vis,0,sizeof(vis));
    dfs_diameter(1,0);st=x;
    //cout<<far<<" "<<x<<endl;
    memset(vis,0,sizeof(vis));
    far = 0;
    dfs_diameter(x,0);nd=x;
    //cout<<"FAR : "<<far<<" "<<st<<" "<<nd<<endl;



}
void bfs(ll s,ll id)
{
    queue<ll>q;
    q.push(s);
    memset(vis,0,sizeof(vis));
    path_cost[id][s]=0;
    vis[s]=1;
    while(!q.empty())
    {
        ll u = q.front();
        q.pop();
        for(ll i=0;i<bridge_tree[u].size();++i)
        {
            ll v = bridge_tree[u][i].first;
            ll w = bridge_tree[u][i].second;

            if(vis[v] == 0)
            {
                vis[v]=1;
                q.push(v);
                path_cost[id][v] = path_cost[id][u]+w;
            }
        }
    }
}
void solve()
{
    for(ll i=1;i<=n;++i){
        if(vis[i]==0)
            timer=0,dfs1(i,-1);
    }

    memset(vis,0,sizeof(vis));
    ll node=1;
    for(ll i=1;i<=n;++i){
        if(vis[i]==0)
            dfs2(i,node),node++;

    }

    for(ll i=0;i<links.size();++i)
    {
        ll a = mark[links[i].first];
        ll b = mark[links[i].second.first];
        ll c = links[i].second.second;
        //cout<<links[i].first<<" "<<links[i].second.first<<" "<<links[i].second.second<<endl;
        bridge_tree[a].push_back({b,c});
        bridge_tree[b].push_back({a,c});
    }

    /*cout<<"--------------"<<endl;
    for(ll i=1;i<node;++i)
    {
        for(ll j=0;j<bridge_tree[i].size();++j)
            cout<<i<<" "<<bridge_tree[i][j].first<<" "<<bridge_tree[i][j].second<<endl;
    }*/
    diameter();
    memset(path_cost,0,sizeof(path_cost));
    bfs(st,0);
    bfs(nd,1);
    ll city,cost=INT_MAX;
    for(ll i=1;i<=n;++i)
    {
        ll u = mark[i];
        //cout<<path_cost[0][u]<<" "<<path_cost[1][u]<<endl;
        if(path_cost[0][u]+path_cost[1][u]==far)
        {
            ll mx = max(path_cost[0][u],path_cost[1][u]);
            if(mx<cost){
                cost=mx;
                city=i;
            }
        }
    }
    cout<<city<<" "<<cost<<endl;

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
            ll x,y,z;
            cin>>x>>y>>z;
            graph[x].push_back({y,z});
            graph[y].push_back({x,z});
        }
        solve();
        for(ll i=0;i<=n;++i)
        {
            graph[i].clear();
            bridge_tree[i].clear();

        }
        bridge.clear();
        mark.clear();
        links.clear();
        memset(low,0,sizeof(low));
        memset(dis,0,sizeof(dis));
        memset(vis,0,sizeof(vis));

    }
}
