#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define     mod                 1000000007
#define     rep1(a,b)           for(ll i=a;i<=b;++i)
#define     rep0(a,b)           for(ll i=a;i<b;++i)
#define     addM(a,b)           (((a)%mod)+((b)%mod))%mod
#define     subM(a,b)           (((((a)%mod)-((b)%mod))+ mod)%mod)
#define     mulM(a,b)           (((a)%mod)*((b)%mod))%mod
#define     pb                  push_back
#define     pp                  pop_back
#define     ff                  first
#define     ss                  second

template<typename T>void print_queue(T q){while(!q.empty()){cout<< q.top().ff<<" "<<q.top().ss<<endl; q.pop();}} /// generic function for printing queue, passed value, original queue will remain as it is

class cmp{///declare a class cmp and overload operator() for it
public:
    bool operator()( pair<ll,ll> lhs , pair<ll,ll> rhs)///type of queue data
    {
        ///'<':ascending order  '>':descending order
        if(lhs.ss!=rhs.ss)
            return lhs.ss > rhs.ss;
        if(lhs.ff!=rhs.ff)
            return lhs.ff > rhs.ff;
    }
};

void solve()
{
    ll n;
    cin>>n;
    ///priority_queue<pair<ll,ll >,vector<pair<ll,ll> >, cmp>pq; /// If need compare function
    ///dont need if its needed to sort queue in decreasing order.
    priority_queue<pair<ll,ll > >pq;

    for(ll i=1;i<=n;++i){
        ll x;
        cin>>x;
        pq.push({x,i});
    }

    print_queue(pq);

}
int main()
{
    ll test;
    cin>>test;
    while(test--)
    {
        solve();
    }
}



