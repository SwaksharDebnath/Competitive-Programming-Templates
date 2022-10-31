#include<bits/stdc++.h>
using namespace std;
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll              long long
#define sz              100005

ll dp[2][sz];
bool vis[sz];
ll t,root,len;
vector< ll >cost[sz];
vector< int >adj[sz];
map < int , int > mp;
vector< int >Tree[sz];
ll d[sz],p[sz],low[sz];
vector< pair< int , int > >links;
map < pair< int , int >, int > Cost;
map< pair< int , int >, int  >bridge;


///DFS from finding bridges
void dfs(int u){
    vis[u]=1;
    d[u]=low[u]=++t;
    for(int i=0; i<adj[u].size(); i++){
        int v=adj[u][i];
        if(vis[v]==0){
            p[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>d[u]){
                bridge[{u,v}]=1;
                bridge[{v,u}]=1;
                links.push_back({u,v});///bridge
            }
        }
        else if(v!=p[u]){
            low[u]=min(low[u],d[v]);
        }
    }
}

///DFS for turning bridge less component into a single node
void dfs2(int u, int node){
    vis[u]=1;
    mp[u]=node;
    for(int i=0; i<adj[u].size(); i++){
        int v=adj[u][i];
        if(bridge[{u,v}])
            continue;
        if(vis[v]==0){
            dfs2(v,node);
        }
    }
}

///Finding Diameter
void dfs_len(int v, int u, ll deep){
    if(deep>len){
       len=deep;
       root=v;
    }
    for(int i=0; i<Tree[v].size(); i++){
        int x=Tree[v][i];
        if(x==u)continue;
        dfs_len(x,v,deep+cost[v][i]);
    }
}

void bfs(int s, int id){
    queue< int > q;
    q.push(s);
    memset(dp[id],-1,sizeof(dp[id]));
    dp[id][s]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0; i<Tree[u].size(); i++){
            int v=Tree[u][i];
            if(dp[id][v]==-1){
                q.push(v);
                dp[id][v]=dp[id][u]+cost[u][i];
            }
        }
    }
}

void solve(int n){

    ///save bridges
    for(int i=1; i<=n; i++){
        if(vis[i]==0){
            t=0;
            dfs(i);
        }
    }

    ///Turn Component into a node
    int node=0;
    mp.clear();
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=n; i++){
        if(vis[i]==0){
            node++;
            dfs2(i,node);
        }
    }

    ///Build Bridge Tree
    for(int i=1; i<=node; i++)
        Tree[i].clear(),cost[i].clear();

    for(int i=0; i<links.size(); i++){
        int a=mp[links[i].first];
        int b=mp[links[i].second];
        int c=Cost[{links[i].first,links[i].second}];
        Tree[a].push_back(b);
        Tree[b].push_back(a);
        cost[a].push_back(c);
        cost[b].push_back(c);
    }
    ///Find start and end
    len=-1;
    dfs_len(1,-1,0);
    len=-1;
    int st=root;
    dfs_len(st,-1,0);
    int End=root;
    bfs(st,0);
    bfs(End,1);

    ll city, dis=1e18;
    for(int i=1; i<=n; i++){
        int u=mp[i];
        if(dp[0][u]+dp[1][u]!=len)continue;
        ll mx=max(dp[0][u],dp[1][u]);
        if(mx<dis){
            dis=mx;
            city=i;
        }
    }
    cout<<city<<' '<<dis<<endl;
}

void reset(int n){
    links.clear();
    Cost.clear();
    bridge.clear();
    for(int i=1; i<=n; i++){
        p[i]=-1;
        adj[i].clear();
        d[i]=low[i]=vis[i]=0;
    }
}

int main(){
    Fast;///using Fast I/O
    ll u,v,c,i,t,n,m,cs=1;

    cin>>t;
    while(t--){
        cin>>n>>m;
        reset(n);
        for(i=1; i<=m; i++){
            cin>>u>>v>>c;
            adj[u].push_back(v);
            adj[v].push_back(u);
            Cost[{u,v}]=c;
            Cost[{v,u}]=c;
        }
        solve(n);
    }
    return 0;
}
