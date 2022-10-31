#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,vector<ll> >graph;
vector<pair<ll,ll> >vp;
bool visited[10007];
ll dis[10007];
ll low[10007];
ll timer=0;
void dfs(ll v,ll parent)
{
    visited[v]=true;
    dis[v]=low[v]=timer++;
    for(ll i=0;i<graph[v].size();++i)
    {
        if(graph[v][i] == parent)continue;
        if(visited[graph[v][i]])
            low[v] = min(low[v],dis[graph[v][i]]);
        else
        {
            dfs(graph[v][i],v);
            low[v] = min(low[v],low[graph[v][i]]);
            if(low[graph[v][i]]>dis[v])
                vp.push_back({min(graph[v][i],v),max(graph[v][i],v)});
        }
    }


}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll test;
    cin>>test;
    for(ll i=1;i<=test;++i)
    {
        ll nodes;
        cin>>nodes;
        memset(visited,false,sizeof(visited));
        memset(dis,-1,sizeof(dis));
        memset(low,-1,sizeof(low));
        timer=0;
        set<ll>s;
        set<ll>::iterator it;
        for(ll i=1;i<=nodes;++i)
        {
            char c1,c2;
            ll p,t;
            cin>>p>>c1>>t>>c2;
            while(t--)
            {
                ll v;
                cin>>v;
                s.insert(v);
                graph[p].push_back(v);
            }
        }
        for(it=s.begin();it!=s.end();++it)
        {
            ll val = *it;
            if(!visited[val])
                dfs(val,-1);
        }
        sort(vp.begin(),vp.end());
        cout<<"Case "<<i<<":"<<endl;
        cout<<vp.size()<<" critical links"<<endl;
        for(ll i=0;i<vp.size();++i)
            cout<<vp[i].first<<" - "<<vp[i].second<<endl;
        vp.clear();
        graph.clear();
    }
}


