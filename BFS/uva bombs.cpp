#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<ll,ll>
ll fx[]={1,-1,0,0};
ll fy[]={0,0,1,-1};
ll arr[1001][1001];
ll vis[1001][1001];
ll lev[1001][1001];
void bfs(pii s, pii d,ll row,ll col)
{
    ll c=0;
    memset(vis,0,sizeof vis);
    memset(lev,0,sizeof lev);
    queue<pii>q;
    q.push(s);
    vis[s.first][s.second] = 1;
    while(!q.empty())
    {
        pii top = q.front();
        q.pop();
        for(ll i=0;i<4;++i)
        {
            ll tx = top.first+fx[i];
            ll ty = top.second+fy[i];
            if(tx>=0 && tx <row && ty>=0 && ty<col && vis[tx][ty] == 0 && arr[tx][ty]!=-1)
            {
                vis[tx][ty] = 1;
                lev[tx][ty] = lev[top.first][top.second]+1;
                if(pii(tx,ty) == d){
                    cout<<lev[tx][ty]<<endl;
                    c=1;break;
                }
                q.push(pii(tx,ty));
            }
        }
        if(c == 1)
            break;
    }
}

int main()
{
    ll r,c,r1,x,a,y,sx,sy,dx,dy;

    while(1)
    {
        memset(arr,0,sizeof arr);
        cin>>r>>c;
        if(r==0 && c==0)
            break;
        cin>>r1;
        for(ll i=0;i<r1;++i)
        {
            cin>>x>>a;
            for(ll j=0;j<a;++j)
            {
                cin>>y;
                arr[x][y]=-1;
            }
        }
        cin>>sx>>sy>>dx>>dy;
        pii p1 = make_pair(sx,sy);
        pii p2 = make_pair(dx,dy);
        bfs(p1,p2,r,c);

    }

}
