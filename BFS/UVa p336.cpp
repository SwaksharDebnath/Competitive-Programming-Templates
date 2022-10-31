#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll> >v(100001);
vector<ll>vis(100001,0);
vector<ll>level(100001,0);
set<ll>st;
ll ctr = 1;
void bfs(ll s,ll l)
{
    set<ll> :: iterator it;
    queue<ll>q;
    q.push(s);
    vis[s] = 1;
    level[s] = 0;
    while(!q.empty())
    {
        ll u = q.front();
        q.pop();
        for(ll i=0;i<v[u].size();++i)
        {
            if(vis[v[u][i]]==0)
            {
                vis[v[u][i]]=1;
                q.push(v[u][i]);
                level[v[u][i]] = level[u]+1;
            }
        }
    }
    ll c=0;
    for(it = st.begin();it!=st.end();++it)
    {
        if((level[*it] > l) || (*it != s && level[*it] == 0)){
            ++c;
        //cout<<*it<<" ";

        }
    }

    cout<<"Case "<<ctr<<": "<<c<<" nodes not reachable from node "<<s<<" with TTL = "<<l<<"."<<endl;
    ++ctr;
    level.clear();vis.clear();
    level.resize(100001);vis.resize(100001);
}
int main()
{
    ll n,x,y;
    //vector<pair<ll,ll> >vp;
    while(1)
    {
        cin>>n;
        if(n==0)
            break;

        for(ll i=1;;++i)
        {
            cin>>x>>y;
            if(i<=n)
            {
                st.insert(x);
                st.insert(y);
                v[x].push_back(y);
                v[y].push_back(x);
            }
            else
            {

                if(x == 0 && y == 0)
                    break;
                bfs(x,y);
                //vp.push_back(make_pair(x,y));
            }

        }
        v.clear();vis.clear();level.clear();st.clear();
        v.resize(100001);vis.resize(100001);level.resize(100001);
    }
}
