#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
int n,m,sx,sy,dx,dy,mark=0;
int grid[1000][1000];
int visited[1000][1000]={0};
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
map<pair<int,int>,pair<int,int> >mp;
void bfs()
{
    queue<pair<int,int> >q;
    pair<int,int>p1;
    p1.f = sx;p1.s = sy;
    visited[sx][sy]=1;
    q.push(p1);
    while(!q.empty())
    {
        pair<int,int> u;
        u = q.front();q.pop();
        for(int i=0;i<4;++i)
        {
            int nx = u.f+fx[i];
            int ny = u.s+fy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m)
            {
                if(visited[nx][ny] == 0 && grid[nx][ny] == 1)
                {
                    visited[nx][ny] = 1;
                    q.push({nx,ny});
                    mp[{nx,ny}]={u.f,u.s};
                    if(nx == dx && ny == dy)
                        {cout<<"reached"<<endl;mark=1;return;}
                }
            }
        }
    }
}
int main()
{
    cout<<"enter n and m :"<<endl;
    cin>>n>>m;
    cout<<"enter source (x,y) :"<<endl;
    cin>>sx>>sy;
    cout<<"enter destination (x,y) :"<<endl;
    cin>>dx>>dy;
    cout<<"enter maze :"<<endl;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin>>grid[i][j];
    bfs();
    mp[{sx,sy}]={-1,-1};
    if(mark == 0)
        {cout<<"could not reach"<<endl;return 0;}

    vector<pair<int,int> >vp;
    vp.push_back({dx,dy});
    pair<int,int>pp,pq;

    pp.f=dx;pp.s=dy;
    pq.f=-1;pq.s=-1;

    while(mp[pp]!=pq)
    {
        vp.push_back(mp[pp]);
        pp = mp[pp];
    }
    cout<<"path from source to destination :"<<endl;
    for(int i=vp.size()-1;i>=0;--i)
        cout<<vp[i].f<<" "<<vp[i].s<<endl;

    //pair<ll,ll>p1,p2;
    //p1.first=sx;p1.second=sy;
    //p2.first=dx;p2.second=dy;

}
