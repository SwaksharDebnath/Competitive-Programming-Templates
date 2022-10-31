#include<bits/stdc++.h>
using namespace std;
#define ll long long int
char grid[501][501];
ll visited[501][501]={0};
ll fx[]={1,-1,0,0};
ll fy[]={0,0,1,-1};
ll cnt=0;
void dfs(ll x,ll y,ll m,ll n)
{
    ++cnt;
    visited[x][y] = 1;
    for(ll i=0;i<4;++i)
    {
        ll nx = x+fx[i];
        ll ny = y+fy[i];
        if(nx >=0 && nx <= m && ny >=0 && ny <= n)
        {
            if(grid[nx][ny]!='#' && visited[nx][ny]==0){

                dfs(nx,ny,m,n);
            }
        }
    }
}
int main()
{
    ll n,x,y,nx,ny,i=0;
    cin>>n;
    while(n--)
    {
        ++i;
        cin>>y>>x;
        for(ll i=0;i<x;++i)
        {
            for(ll j=0;j<y;++j)
            {
                cin>>grid[i][j];
                if(grid[i][j] == '@') {nx = i;ny = j;}

            }
        }
        dfs(nx,ny,x-1,y-1);
        memset(visited,0,sizeof visited);
        printf("Case %lld: %lld\n",i,cnt);
        cnt = 0;

    }
}
