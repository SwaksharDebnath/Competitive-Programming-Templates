#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz 26
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
int main(){
    int T,n,x,y,ans;
    char c;
    string s;

    scanf("%d\n\n",&T);

    for(int tc=1;tc<=T;tc++){
        getline(cin,s);
        n=s[0]-'A'+1;

        ans=n;
        for(int i=0;i<n;i++) make_set(i);

        while(1){
            if(!getline(cin,s) || s.empty()) break;

            x=s[0]-'A'; y=s[1]-'A';

            if(find_set(x)!=find_set(y)){
                union_sets(x,y);
                ans--;
            }
        }

        if(tc!=1) printf("\n");
        printf("%d\n",ans);
    }

    return 0;
}

