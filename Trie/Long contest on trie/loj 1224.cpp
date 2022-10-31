#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
map<char,ll>asme;
ll trie[2500100][4],sz=0,mx=0,cc[2500100];
void insrt(string s)
{
    ll v=0;
    for(ll i=0;i<s.size();++i)
    {
        ll c = asme[s[i]];
        if(trie[v][c] == -1)
            trie[v][c] = ++sz;
        cc[trie[v][c]]++;
        v = trie[v][c];
    }
}
void check(string s)
{
    ll v=0;
    ll ss = s.size();
    for(ll i=0;i<ss;++i)
    {
        ll c = asme[s[i]];
        mx = max(mx,cc[trie[v][c]]*(i+1));
        v = trie[v][c];
    }

}
void clr()
{
    memset(trie,-1,sizeof(trie));
    memset(cc,0,sizeof(cc));
    sz=0,mx=0;

}
int main()
{
    Fast;
    ll test,cs=1;
    cin>>test;
    asme['A'] = 0;
    asme['C'] = 1;
    asme['G'] = 2;
    asme['T'] = 3;
    while(test-- )
    {
        clr();
        ll n;
        cin>>n;
        vector<string>vs;
        for(ll i=0;i<n;++i)
        {
            string s;
            cin>>s;
            vs.push_back(s);
            insrt(s);
        }
        //cout<<sz<<endl;
        for(ll i=0;i<n;++i)
            check(vs[i]);
        ll ans = mx;

        printf("Case %lld: %lld\n",cs++,ans);
    }
}
