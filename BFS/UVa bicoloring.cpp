#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll> >v(201);
vector<ll>vis(201,0);
//vector<ll>parent(201,-1);
vector<ll>color(201,-1);
ll bfs(ll s)
{

    ll n,c=1;
    queue<ll>q;
    q.push(s);
    vis[s]=1;
    color[s]=0;
    n = s;
    while(!q.empty())
    {
        ll u = q.front();
        q.pop();
        for(ll i=0;i<v[u].size();++i)
        {
            if(vis[v[u][i]]==0)
            {
                vis[v[u][i]] = 1;
                //parent[v[u][i]] = u;
                q.push(v[u][i]);
                if(color[u] == 0)
                    color[v[u][i]] = 1;
                else
                    color[v[u][i]] = 0;

            }
            else if(color[v[u][i]]== color[u])
            {
                c=0;break;
            }
        }

        //cout<<n<<"   "<<c<<" "<<endl;
        if(c==0)
            break;

    }
    v.clear();vis.clear();color.clear();
    v.resize(201);vis.resize(201);color.resize(201,-1);
    return c;
}
int main()
{
    ll n,l,x,y,root=0;
    while(1)
    {
        cin>>n;
        if(n==0)
            break;
        cin>>l;
        for(ll i=0;i<l;++i)
        {
            cin>>x>>y;
            if(i == 0)
                root = x;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        //x = v[v[0][0]][0];
        ll c = bfs(root);

        if(c== 1)
            cout<<"BICOLORABLE."<<endl;
        else
            cout<<"NOT BICOLORABLE."<<endl;

    }
}
