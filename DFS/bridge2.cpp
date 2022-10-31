#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,vector<ll> >graph;
bool visited[10007];
ll dis[10007];
ll low[10007];
ll arr[10007];
ll timer = 0,root;
set<ll>st;
void dfs(ll v,ll parent)
{
    visited[v]=true;
    dis[v]=low[v]=timer++;
    ll child=0;
    for(ll i=0;i<graph[v].size();++i)
    {
        if(graph[v][i] == parent)continue;
        if(visited[graph[v][i]])
            low[v] = min(low[v],dis[graph[v][i]]);
        else
        {
            dfs(graph[v][i],v);
            low[v] = min(low[v],low[graph[v][i]]);
            if(low[graph[v][i]]>=dis[v] && parent!=-1)
                st.insert(v);
             child++;
        }
    }
    if(parent == -1 && child>1)
        st.insert(v);
}
int main()
{
    ll test,i=0;
    cin>>test;
    while(test--)
    {
        memset(arr,-1,sizeof(arr));
        memset(visited,false,sizeof(visited));
        memset(dis,-1,sizeof(dis));
        memset(low,-1,sizeof(low));
        timer=0;
        ll n,m;
        cin>>n>>m;
        while(m--)
        {
            ll x,y;
            cin>>x>>y;
            arr[x]=1;
            arr[y]=1;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        for(ll i=1;i<=n;++i)
        {
            if(arr[i] == 1)
                if(!visited[i])
                    dfs(i,-1);
        }
        cout<<"Case "<<++i<<":"<<" "<<st.size()<<endl;
        st.clear();
        graph.clear();

    }
}
