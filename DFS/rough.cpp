#include<bits/stdc++.h>
using namespace std;
#define ll long long int
map<ll,vector<ll> >mp;
ll vis[101],mx=0,ff;
void dfs(ll u,ll cnt)
{
    vis[u]=1;
    for(ll i=0;i<mp[u].size();++i){
        if(vis[mp[u][i]]==0){
            if(cnt>=mx)mx=cnt,ff=mp[u][i];
            dfs(mp[u][i],cnt+1);
        }

    }
}
int main()
{
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;++i)
    {
        ll x,y;
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    dfs(1,1);
    cout<<mx<<" "<<ff<<endl;

}
