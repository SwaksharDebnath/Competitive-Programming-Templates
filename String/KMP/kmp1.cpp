#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string text,pattern;
ll pi[1000];
void prefixfunction()
{
    ll now;
    pi[0] = now = -1;
    ll len = pattern.length();
    for(ll i=1;i<len;++i)
    {
        while(now!=-1 && pattern[now+1] != pattern[i])
            now = pi[now];
        if(pattern[now+1] == pattern[i])pi[i] = ++now;
        else
            pi[i]=now=-1;
    }
}
ll kmpp()
{
    ll now=-1;
    ll n = text.length();
    ll m = pattern.length();
    for(ll i=0;i<n;++i)
    {
        while(now!=-1 && pattern[now+1] !=text[i])
            now = pi[now];
        if(pattern[now+1] == text[i])++now;
        else
            now=-1;
        if(now==m-1)return 1;
        //cout<<"bbb"<<endl;
    }
    return 0;
}
int main()
{
    cin>>text>>pattern;
    prefixfunction();
    ll ans = kmpp();
    cout<<ans<<endl;
    if(ans)cout<<"FOUND"<<endl;
    else cout<<"NOT"<<endl;

    for(ll i=0;i<pattern.length();++i)
        cout<<pi[i]<<" ";

}
