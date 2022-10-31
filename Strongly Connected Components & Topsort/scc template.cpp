#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>graph[200];
ll disc[200],low[200],tim=0,n,m;
bool stkck[200];
stack<ll>st;
void dfs(ll u)
{
    disc[u] = low[u] = tim;
    tim++;
    st.push(u);
    stkck[u]=true;
    for(int v : graph[u])
    {
        if(disc[v] == -1)
        {
            dfs(v);
            low[u] = min(low[u],low[v]);
        }else if(stkck[v])
            low[u] = min(low[u],disc[v]);
    }
    if(low[u] == disc[u]){
        cout<<"scc : ";
        while(st.top()!=u)
        {
            cout<<st.top()<<" ";
            stkck[st.top()] = false;
            st.pop();
        }
        cout<<st.top()<<endl;
        stkck[st.top()] = false;
        st.pop();
    }
}
int main()
{
    cin>>n>>m;
    memset(disc,-1,sizeof(disc));
    memset(low,-1,sizeof(low));
    for(ll i=0;i<m;++i)
    {
        ll x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }
    for(ll i=0;i<n;++i)
        if(disc[i] == -1)
            dfs(i);
}
