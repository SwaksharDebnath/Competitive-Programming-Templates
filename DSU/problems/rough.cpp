#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz 100
ll parent[sz];
ll sixe[sz];
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

    char a,b;
        while(scanf("%c%c",&a,&b)){
            ll x = a -'A'+1;///x,y is less then equal n
            ll y = b -'A'+1;
            cout<<x<<" "<<y<<endl;
            getchar();
            //union_sets(x,y);
        }

}


