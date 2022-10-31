#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f first
#define s second
ll board[9][9];
ll visited[9][9]={0};
ll dis[9][9]={0};
ll fx[]={-1,-2,-2,-1,1,2,2,1};
ll fy[]={-2,-1,1,2,2,1,-1,-2};
int bfs(pair<ll,ll> p1,pair<ll,ll> p2)
{
    for(ll i=0;i<9;++i)
        for(ll j=0;j<9;++j){
            visited[i][j]=0;
            dis[i][j]=0;
        }
    if(p1 == p2){
        cout<<0<<endl;
        return 0;
    }
    ll x,y,nx,ny;
    queue<pair<ll,ll> >q;
    pair<ll,ll> u;
    q.push(p1);
    visited[p1.f][p1.s] = 1;
    dis[p1.f][p1.s] = 0;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        x = u.f;
        y = u.s;
        for(ll i=0;i<8;++i)
        {
                     nx = x+fx[i];
            ny = y+fy[i];
            if(nx >=1 && nx <= 8 && ny >=1 && ny <= 8)
            {
                if(visited[nx][ny] == 0)
                {
                    visited[nx][ny] = 1;
                    q.push({nx,ny});
                    dis[nx][ny] = dis[x][y]+1;
                    if(nx == p2.f && ny == p2.s ){
                        cout<<dis[nx][ny]<<endl;
                        return 0;
                    }
                }
            }
        }

    }
        //dis[9][9]={0};
}
int main()
{
    ll n,x,y,x1,y1,c;
    cin>>n;
    //char s1[5],s2[5];
    string s1,s2;
    pair<ll,ll>p1,p2;
            getchar();
    while(n--)
    {

       // scanf("%s%s",s1,s2);

            cin>>s1>>s2;
            //getline(cin,s1);
            //cout<<s1<<endl;
    x = s1[0]-'`';
    x1 = s2[0]-'`';
    y = s1[1]-'0';
    y1 = s2[1]-'0';
    //cout<<x<<" "<<y<<" "<<x1<<" "<<y1<<endl;
            p1 = {x,y};
            p2 = {x1,y1};
             bfs(p1,p2);
             //getchar();
            //cout<<c<<endl;

    }
    return 0;
}
