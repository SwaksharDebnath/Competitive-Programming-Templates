#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pll pair<ll,ll>
ll fx[]={1,-1,0,0};
ll fy[]={0,0,1,-1};
ll arr[10][10];
ll vis[10][10];
ll lev[10][10];
ll bfs(pll p1,pll p2,ll row,ll col)
{
    ll c=0;
    memset(vis,0,sizeof vis);
    memset(lev,0,sizeof lev);
    queue<pll>q;
    q.push(p1);
    vis[p1.first][p1.second] = 1;
    while(!q.empty())
    {
        pll top = q.front();
        q.pop();
        for(ll i=0;i<4;++i)
        {
            ll tx = top.first+fx[i];
            ll ty = top.second+fy[i];
            if(tx>=1 && tx<=row && ty>=1 && ty<=col && vis[tx][ty] == 0)
            {
                vis[tx][ty] == 1;
                lev[tx][ty] = lev[top.first][top.second]+1;
                q.push(pll(tx,ty));

                if(pll(tx,ty) == p2){
                    return lev[tx][ty];
                }

            }
        }
    }

}
int main()
{
    ll r1,r2,c1,c2;
    char co1,co2;
    while(1)
    {
        cin>>co1>>r1>>co2>>r2;
        c1 = co1 - '`';c2 = co2 - '`';
        pll p1 = make_pair(r1,c1);
        pll p2 = make_pair(r2,c2);
        cout<<"To get from "<<co1<<r1<<" to "<<co2<<r2<<" takes "<<bfs(p1,p2,8,8)<<" moves."<<endl;

    }


}
