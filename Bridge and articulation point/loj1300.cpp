#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,vector<ll> >graph;
set<ll>fresh[100007];
map<pair<ll,ll>,ll >briz;

bool vis[10007],checker=false;
ll dis[10007];
ll low[10007];
ll lvl[10007];
ll timer=0,cnt=0;

void dfs(ll v,ll parent)
{
    vis[v]=true;
    dis[v]=low[v]=timer++;
    for(ll i=0;i<graph[v].size();++i)
    {
        if(graph[v][i]==parent)continue;
        if(vis[graph[v][i]]==true)
            low[v] = min(low[v],dis[graph[v][i]]);
        else{
            dfs(graph[v][i],v);
            low[v] = min(low[v],low[graph[v][i]]);
            if(low[graph[v][i]]>dis[v]){
                fresh[graph[v][i]].erase(v);
                fresh[v].erase(graph[v][i]);
            }
        }
    }
}
void dfscheck(ll v,ll parent,ll cost)
{
    vis[v]=true;
    lvl[v]=cost;
    cnt++;
    for(auto i:fresh[v])
    {

        if(!vis[i])
            dfscheck(i,v,cost+1);
        else if((lvl[v]-lvl[i])%2==0)
            checker=true;


    }

}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll test,c=1,node;
    cin>>test;
    while(test--)
    {
        set<ll>st;
        set<ll>::iterator sit;
        ll n,m;
        cin>>n>>m;
        for(ll i=0;i<m;++i)
        {
            ll x,y;
            cin>>x>>y;
            st.insert(x);
            st.insert(y);
            graph[x].push_back(y);fresh[x].insert(y);
            graph[y].push_back(x);fresh[y].insert(x);
        }
        for(sit=st.begin();sit!=st.end();++sit)
        {
            if(!vis[*sit])
                timer=0,dfs(*sit,-1);
        }
        memset(vis,false,sizeof(vis));
        ll res=0;
        for(sit=st.begin();sit!=st.end();++sit)
        {
            if(!vis[*sit]){
                checker=false,cnt=0,dfscheck(*sit,-1,0);
                if(checker )
                    res+=cnt;

            //cout<<cnt<<" "<<*sit<<endl;
            }
        }
        cout<<"Case "<<c++<<": "<<res<<endl;
        graph.clear();
        for(ll i=0;i<n;++i)
            fresh[i].clear();
        memset(dis,0,sizeof(dis));
        memset(low,0,sizeof(low));
        memset(lvl,0,sizeof(lvl));
        memset(vis,false,sizeof(vis));



    }
    return 0;
}
