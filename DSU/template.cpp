#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz 100
ll parent[sz];
ll sixe[sz];/// sixe->size
void make_set(ll v){
    parent[v] = v;
    sixe[v] = 1;
}
int find_set(ll v){
    if(parent[v] == v)
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(ll a,ll b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
       if(sixe[a] < sixe[b])
            swap(a,b);
        parent[b] = a;
        sixe[a] += sixe[b];
    }
}
int main()
{
    ll n,m;///nodes & edges
    cin>>n>>m;
    for(ll i=1;i<=n;++i)
        make_set(i);
    while(m--){
        ll x,y;
        cin>>x>>y;///x,y is less then equal n
        union_sets(x,y);
    }
    set<ll>st;
    //for(ll i=1;i<=n;++i)cout<<parent[i]<<" ";cout<<endl;
    //sfor(ll i=1;i<=n;++i)cout<<parent[i]<<" ";
    for(ll i=1;i<=n;++i){
        ll v = find_set(i);
        st.insert(v);
    }
    cout<<st.size()<<endl;

}
