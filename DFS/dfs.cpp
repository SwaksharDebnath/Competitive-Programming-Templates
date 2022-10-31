#include<bits/stdc++.h>
using namespace std;
#define ll long long int
map<ll,vector<ll> >mp;
ll visited[101];
ll cnt=0;
void dfs(int s)
{
    visited[s] = 1;
    ++cnt;
    for(ll i=0;i<mp[s].size();++i)
    {
        if(visited[mp[s][i]] == 0)
            dfs(mp[s][i]);
        else
            visited[mp[s][i]] = -1;

    }
}
int main()
{
    ll x,y,z,c;

    while(1)
    {
        cnt = 0;
        cin>>x;
        if(x == 0){
            break;
        }
        while(1)
        {
            cin>>y;
            if(y == 0)
                break;
            while(1)
            {
                cin>>z;
                if(z == 0)
                    break;

                mp[y].push_back(z);

            }
        }
        cin>>c;
         for(ll i=0;i<c;++i)
        {
            cin>>y;
            memset(visited,0,sizeof visited);
            dfs(y);
            //cout<<cnt<<" dhur ";
            if(visited[y] == -1)
                cout<<x - cnt;
            else{
                cout<<(x - cnt)+1;
                visited[y] = 0;
            }
            cnt=0;
            for(ll j=1;j<=x;++j)
            {
                if(visited[j] == 0)
                    cout<<" "<<j;
            }
            cout<<endl;
        }
        mp.clear();
    }
}
