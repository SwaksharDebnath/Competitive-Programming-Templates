#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll trie[100010][50],sz=0,we[100010];
void insrt(string s)
{
    ll v=0;
    for(ll i=0;i<s.size();++i)
    {
        ll c;
        if(s[i]>='A' && s[i]<='Z')c = s[i]-'A';
        else c = s[i] - 'G';
        if(trie[v][c] == -1)
            trie[v][c] = ++sz;
        v = trie[v][c];
    }
    we[v]++;

}
ll check(string s)
{
    ll v=0;
    for(ll i=0;i<s.size();++i)
    {
        ll c;
        if(s[i]>='A' && s[i]<='Z')c = s[i]-'A';
        else c = s[i] - 'G';
        if(trie[v][c] == -1)
            return 0;
        v = trie[v][c];
    }

    return we[v];
}
void clr()
{
    memset(trie,-1,sizeof(trie));
    memset(we,0,sizeof(we));
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
        for(ll i=0;i<n;++i)
        {
            string s;
            cin>>s;
            if(s.size()>2)
                sort(s.begin()+1,s.end()-1);
            insrt(s);

        }
        ll m;
        string s1;
        cin>>m;
        cin.ignore();
        printf("Case %lld:\n",cs++);
        for(ll i=0;i<m;++i)
        {
            getline(cin,s1);
            string s="";
            ll res = 1;
            for(ll j=0;j<s1.size();++j)
            {
                if(s1[j]!=' ')
                    s += s1[j];
                else{
                    if(s.size()!=0){
                        if(s.size()>2)
                            sort(s.begin()+1,s.end()-1);
                        ll val = check(s);
                        res *= val;
                        if(res == 0)
                            break;
                        s = "";
                    }
                }
            }
            if(s.size()!=0 && res != 0){
                if(s.size()>2)
                    sort(s.begin()+1,s.end()-1);
                ll val = check(s);
                res *= val;
                s = "";
            }
            cout<<res<<endl;
        }
    }
}
