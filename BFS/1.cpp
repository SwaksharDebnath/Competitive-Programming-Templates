
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,vector<ll> >graph;
ll vis[1000],s;
map<ll,ll>parent;

void bfs()
{
    queue<ll>q;
    q.push(s);
    vis[s] = 1;
    parent[s]=-1;
    while(!q.empty())
    {
        ll u = q.front();
        q.pop();
        for(ll i=0;i<graph[u].size();++i)
        {
            if(vis[graph[u][i]]==0)
            {

                vis[graph[u][i]] = 1;
                parent[graph[u][i]]=u;
                q.push(graph[u][i]);
            }

        }
    }
}
int main()
{
    ll node,edge,x,y;
    cout<<"enter number of nodes and edges:"<<endl;
    cin>>node>>edge;
    cout<<"enter edges"<<endl;
    for(ll i=1;i<=edge;++i)
    {
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    cout<<"enter source :"<<endl;
    cin>>s;
    bfs();
    //cout<<v[6][0]<<endl;
    map<ll,ll>::iterator it;
    for(it = parent.begin();it!=parent.end();++it)
    {
        ll v = it->first;
        if(v!=s)
        {
        cout <<"route from "<<v<<" :";
            vector<ll>path;
            path.push_back(v);
            while(parent[v]!=-1){
                path.push_back(parent[v]);
                v = parent[v];
            }
            for(ll i=path.size()-1;i>=0;--i)
                cout<<path[i]<<" ";
            cout<<endl;

        }
    }


}
