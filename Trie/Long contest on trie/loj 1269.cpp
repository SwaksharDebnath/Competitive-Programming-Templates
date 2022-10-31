#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll trie[1650009][2],sz=0,n;
vector<ll>bin;
void insrt(string s)
{
    ll v=0;
    for(ll i=0;i<s.size();++i)
    {
        ll c = s[i]-'0';
        if(trie[v][c] == -1)
            trie[v][c] = ++sz;
        v = trie[v][c];
    }
}
void srch(string s)
{
    ll v=0;

        for(ll i=0;i<s.size();++i)
        {
            ll c=s[i]-'0';
            if(trie[v][c] == -1)c^=1;
            bin.push_back(c);
            v = trie[v][c];
        }
}
ll dec()
{
    ll val=1,sum=0;
    for(ll i=bin.size()-1;i>=0;--i)
    {
        if(bin[i] == 1)
            sum+=val;
        val*=2;
    }
    return sum;
}
void clr()
{
    memset(trie,-1,sizeof(trie));
    sz=0;
}
int main()
{
    ll test,cs=1;
    cin>>test;
    while(test--)
    {
        ll mx,mn;
        clr();
        cin>>n;
        ll xr;
        vector<ll>v(n);
        for(ll i=0;i<n;++i)
        {
            cin>>v[i];
            string s;
            if(i == 0){
                mx = v[i];mn=v[i];
                xr = v[i];
                s = bitset<32>(xr).to_string();
                insrt(s);
            }else{
                xr = xr^v[i];
                ll ch = xr^4294967295;
                string ss = bitset<32>(ch).to_string();
                srch(ss);
                ll val = dec();val^=xr;bin.clear();
                mx = max(mx,max(val,xr));
                string st = bitset<32>(xr).to_string();
                srch(st);
                ll val1 = dec();val1^=xr;bin.clear();
                mn = min(mn,min(val1,xr));
                insrt(st);

            }
        }

        printf("Case %lld: %lld %lld\n",cs++,mx,mn);
    }
}
