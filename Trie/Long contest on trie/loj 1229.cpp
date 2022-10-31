#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll trie[100009][11],sz=0;
ll we[100009];
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
    we[v]++;
}
bool check(string s)
{
    ll v=0;
    for(ll i=0;i<s.size();++i)
    {
        ll c = s[i] - '0';
        if(we[v] > 0)
            return false;
        v = trie[v][c];
    }
    if(we[v] > 1)
        return false;
    return true;
}
void clr()
{
    memset(trie,-1,sizeof(trie));
    memset(we,false,sizeof(we));
    sz=0;
}
int main()
{
    ll test,cs=1;
    cin>>test;
    while(test--)
    {
        clr();
        ll n;
        cin>>n;
        set<string>st;
        for(ll i=0;i<n;++i)
        {
            string s;
            cin>>s;
            st.insert(s);
            insrt(s);
        }

        bool ans=true;
        if(st.size() != n)
            ans = false;
        else
        {
            for(auto it=st.begin();it!=st.end();++it)
            {
                string s = *it;
                if(!check(s))
                    {ans = false;break;}
            }

        }
        //for(ll i=0;i<=sz;++i)
           // cout<<we[i]<<" ";
        if(ans)
            printf("Case %lld: YES\n",cs++);
        else
            printf("Case %lld: NO\n",cs++);

    }
}
