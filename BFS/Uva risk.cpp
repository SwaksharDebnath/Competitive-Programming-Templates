#include<bits/stdc++.h>
#include<stdio.h>
using namespace  std;
#define ll long long int
vector<vector<ll> >v(100001);
vector<ll>vis(100001,0);
vector<ll>level(100001,0);
void bfs(ll s,ll d)
{
    ll c=0;
    queue<ll>q;
    q.push(s);
    vis[s] = 1;
    while(!q.empty())
    {
        ll u = q.front();
        q.pop();
        for(ll i=0; i<v[u].size(); ++i)
        {
            if(vis[v[u][i]] == 0)
            {
                vis[v[u][i]] = 1;
                q.push(v[u][i]);
                level[v[u][i]] = level[u]+1;
                if(v[u][i] == d)
                {
                    printf("%2lld to %2lld: %lld\n",s,d,level[v[u][i]]);
                    c=1;
                    break;
                }
            }
        }
        if(c == 1)
            break;
    }
    vis.clear();
    level.clear();
    vis.resize(100001,0);
    level.resize(100001,0);
}
int main()
{
    ll a,x,i=1,t,m,n,c=1;
    while(scanf("%lld",&a)!=EOF)
    {
        if(i == 1)
        {
            v.clear();
            vis.clear();
            level.clear();
            v.resize(100001);
            vis.resize(100001,0);
            level.resize(100001,0);
        }
        if(i<=19)
        {
            for(ll j=0; j<a; ++j)
            {
                scanf("%lld",&x);
                v[i].push_back(x);
                v[x].push_back(i);
            }

            ++i;
        }
        else
        {
            printf("Test Set #%lld\n",c);++c;
            for(ll j=0; j<a; ++j)
            {
                scanf("%lld %lld",&m,&n);
                bfs(m,n);
            }
            i=1;
        }
        /*for(ll i=1;i<=20;++i)
        {
            cout<<i<<"-->";
            for(ll j=0;j<v[i].size();++j)
            {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }*/



    }
}
