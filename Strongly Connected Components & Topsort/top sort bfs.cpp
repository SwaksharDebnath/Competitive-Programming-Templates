#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>graph[200];
ll vis[200];
ll indegree[200];
vector<ll>ans;
ll n,m;
void bfs()
{
    queue<ll>q;
    for(ll i=0;i<n;++i)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
            ans.push_back(i);
            vis[i]=1;
        }
    }
    while(!q.empty())
    {
        ll u = q.front();
        q.pop();
        for(ll i=0;i<graph[u].size();++i)
        {
            if(vis[graph[u][i]] == 0)
            {
                indegree[graph[u][i]]--;
                if(indegree[graph[u][i]]==0){
                    vis[graph[u][i]] = 1;
                    q.push(graph[u][i]);
                    ans.push_back(graph[u][i]);
                }
            }
        }
    }
    for(ll i=0;i<n;++i)
        if(indegree[i] != 0)
            cout<<"There is a cycle in this graph!"<<endl;

    //for(ll i=0;i<n;++i)
      //  cout<<indegree[i]<<" ";
    //cout<<endl;

}
int main()
{

    cin>>n>>m;
    memset(vis,0,sizeof(vis));
    memset(indegree,0,sizeof(indegree));
    for(ll i=0;i<m;++i)
    {
        ll x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        indegree[y]++;
    }
    //for(ll i=0;i<n;++i)
        //cout<<indegree[i]<<" ";
    bfs();
    for(ll i=0;i<ans.size();++i)
        cout<<ans[i]<<" ";
}
