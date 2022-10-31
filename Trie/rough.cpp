#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000
int dis[100005];
vector<int> adj[100005];
queue<int> q;
stack<int> s;
int par[100005];
int n,e;
void bfs(int src){
    for(int i = 0; i < n; i++){
        dis[i] = INF;
    }
    dis[src] = 0;
    par[src] = src;
    q.push(src);
    while(!q.empty()){
        int u = q.front();
        int v;
        q.pop();
        for(int i = 0; i < adj[u].size(); i++){
            v = adj[u][i];
            if(dis[v]!=INF){
                dis[v] = dis[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
}
void path_print(int src, int des){
    bfs(src);
    int curr = des;
    while(curr!=src){
        //printf("this: %d\n",curr);
        s.push(curr);
        curr = par[curr];

    }
    //printf("This: %d\n",src);
    s.push(src);
    while(!s.empty()){
            cout<<s.top()<<'\t';
            s.pop();
    }
}
int main(){
 int u,v;
// intput
// 5 5
// 1 2
// 5 1
// 3 5
// 2 3
// 3 4
 scanf("%d %d",&n,&e);
 for(int i = 0; i < e; i++){
    scanf("%d %d",&u,&v);
    adj[u].push_back(v);
    adj[v].push_back(u);
 }
 //bfs(1);
 path_print(3,1);
 //path_print(3,5);

 return 0;

}

