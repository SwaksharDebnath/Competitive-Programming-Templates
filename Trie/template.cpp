#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
///trie[no of char in input][26];
///we[no of char in input]->word end
ll trie[100][26],sz=0,we[100];
void insrt(string s)
{
    ll v=0;
    for(ll i=0;i<s.size();++i)
    {
        ll c = s[i]-'a';
        if(trie[v][c] == -1)
            trie[v][c] = ++sz;
        v = trie[v][c];
    }
    we[v]++;
}
bool srch(string s)
{
    ll v=0;
    for(ll i=0;i<s.size();++i)
    {
        ll c =s[i]-'a';
        if(trie[v][c] == -1)
            return false;
        v = trie[v][c];
    }
    if(we[v])return true;
}
void dlt(string s)
{
    ll v=0;
    for(ll i=0;i<s.size();++i)
    {
        ll c = s[i] - 'a';
        if(trie[v][c] == -1)
            cout<<"string does not exist."<<endl;
        v = trie[v][c];
    }
    we[v]--;
}
int main()
{
    ll n;
    cin>>n;
    memset(trie,-1,sizeof(trie));
    string s;
    for(ll i=1;i<=n;++i)
    {
        cin>>s;
        insrt(s);
    }
    cout<<"Enter a string to be searched :";
    cin>>s;
    bool ret = srch(s);
    cout<<ret<<endl;

}
