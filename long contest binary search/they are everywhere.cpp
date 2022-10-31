#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string s;
map<char,ll>mp;
map<char,ll>:: iterator itr;
ll check(ll n,ll u)
{
    ll uniq=0;
    for(itr = mp.begin();itr!=mp.end();++itr)
        itr->second = 0;
    for(ll i=0;i<s.length();++i)
    {
        if(i<n)
        {
            if(mp[s[i]] == 0){uniq++; mp[s[i]] =1;}
            else mp[s[i]]++;
        }
        else
        {
            mp[s[i-n]]--;
            if(mp[s[i-n]]==0) uniq--;
            if(mp[s[i]] == 0){uniq++; mp[s[i]] =1;}
            else mp[s[i]]++;
        }
        if(uniq == u)
            return 1;
    }
    return 0;
}
int main()
{
    ll n,hi,lo,mid,r;
    cin>>n>>s;
    for(ll i=0;i<s.length();++i)
        mp.insert({s[i],0});
    ll sz = mp.size();
    if(sz == n)
        cout<<sz<<endl;
    else
    {
        hi = n;
        lo = sz;
        while(lo<hi)
        {
            mid = (hi+lo)/2;
            r = check(mid,sz);
            //cout<<mid<<" "<<r<<endl;
            if(r) hi = mid;
            else lo = mid+1;
        }
        cout<<lo<<endl;
    }
}
