#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll> >v(201);
vector<ll>vis(201,0);
vector<ll>color(201);
ll bfs(ll s)
{

    ll c = 1;
    queue<ll>q;
    q.push(s);
    vis[s] = 1;
    color[s] = 1;

    while(!q.empty())
    {
        ll u = q.front(),x;
        q.pop();
        for(ll i=0;i<v[u].size();++i)
        {
            if(vis[v[u][i]] == 0)
            {
                vis[v[u][i]] = 1;
                q.push(v[u][i]);
                if(color[u]== 1)
                    color[v[u][i]] = 0;
                else
                    color[v[u][i]] = 1;
            }

        }
        if(color[u]== 1)
            x = 0;
        else
            x = 1;
        for(ll i=0;i<v[u].size();++i)
        {
            if(color[v[u][i]] != x){
                c = 0;
                break;
            }
        }
        if(c == 0)
            break;
    }
    v.clear();vis.clear();color.clear();
    v.resize(201);vis.resize(201,0);color.resize(201);
    return c;
}
int main()
{
    ll x;
    scanf("%lld",&x);
    printf("%lld",x);

}
