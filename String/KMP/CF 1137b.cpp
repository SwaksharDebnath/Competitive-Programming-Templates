#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s,t;
ll pi[500007];
void prefixfunction()
{
    ll now,len = t.length();
    pi[0] = now = -1;
    for(ll i=1;i<len;++i)
    {
        while(now!=-1 && t[now+1]!=t[i])
            now = pi[now];
        if(t[now+1] == t[i])pi[i]=++now;
        else
            pi[i] = now = -1;
    }
}
int main()
{
    cin>>s>>t;
    ll n = s.length();
    ll m = t.length();
    ll szr=0,son=0,tzr=0,ton=0;
    for(ll i=0;i<max(n,m);++i)
    {
        if(i<n)
        {
            if(s[i] == '1')son++;
            if(s[i] == '0')szr++;
        }
        if(i<m)
        {
            if(t[i] == '1')ton++;
            if(t[i] == '0')tzr++;
        }
    }
    if(n<m || szr<tzr || son<ton)
        cout<<s<<endl;
    else
    {
        prefixfunction();
        ll id = pi[m-1];
        cout<<t;
        szr-=tzr;son-=ton;

        while(1)
        {
            ll mark=0;
            for(ll i=id+1;i<m;++i)
            {
                if(szr == 0 || son == 0){
                    mark=1;
                    break;
                }
                cout<<t[i];
                if(t[i] == '0')szr--;
                if(t[i] == '1')son--;
            }
            if(mark==1)break;
        }
        for(ll i=1;i<=szr;++i)cout<<0;
        for(ll i=1;i<=son;++i)cout<<1;
    }

}
