#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll trie[6200000][2],mark[6200000][2],sz=0;
vector<ll>bin;
void insrt(string s)
{
    ll v=0;
    for(ll i=0;i<s.size();++i)
    {
        ll c = s[i] - '0';
        if(trie[v][c] == -1)
            trie[v][c] = ++sz;
        mark[v][c]++;
        v = trie[v][c];
    }
    //we[v]++;
}
void dlt(string s)
{
    ll v=0;
    for(ll i=0;i<s.size();++i)
    {
        ll c=s[i] -'0';
        mark[v][c]--;
        v = trie[v][c];
    }
    //we[v]--;
}
void srch(string s)
{
    ll v=0;
    for(ll i=0;i<s.size();++i)
    {
        ll c = s[i]-'0';
        // || mark[v][c]<1
        if(trie[v][c] == -1 || mark[v][c]<1)c^=1;
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
    memset(mark,0,sizeof(mark));
    sz=0;
}
int main()
{
    ll q,n;
    char ch;
    cin>>q;
    clr();
    string s;
    s = bitset<31>(0).to_string();
    insrt(s);
    while(q--)
    {
        cin>>ch>>n;
         s = bitset<31>(n).to_string();
        //cout<<s<<endl;
        if(ch == '+')insrt(s);
        if(ch == '-')dlt(s);
        if(ch == '?')
        {
            ll xr = n^1073741823;
            string ss = bitset<31>(xr).to_string();
            //cout<<ss<<endl;
            srch(ss);
            ll val = dec();bin.clear();
            val^=n;
            cout<<val<<endl;
        }
    }
}
