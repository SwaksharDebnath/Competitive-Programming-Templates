#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool isprime[2010];
void sieve()
{
    memset(isprime,true,sizeof isprime);
    isprime[1] = false;
    for(ll i=2;i*i<=2010;++i)
    {
        if(isprime[i])
        {
            for(ll j=i*i;j<=2010;j+=i)
                isprime[j] = false;
        }
    }
}
int main()
{
    sieve();
    ll n,c=0;
    string s;
    vector<char>v;
    cin>>n;
    map<char,ll>mp;
    for(ll j=1;j<=n;++j)
    {
        cin>>s;
        c=0;
        cout<<"Case "<<j<<": ";
        for(ll i=0;i<s.length();++i)
            ++mp[s[i]];
        for(ll i=0;i<s.length();++i)
        {
            if(isprime[mp[s[i]]]){
                v.push_back(s[i]);
                mp[s[i]] = 1;c=1;
            }
        }
        if(c == 0)
            cout<<"empty"<<endl;
        else
        {
            sort(v.begin(),v.end());
            for(ll i=0;i<v.size();++i)
                cout<<v[i];
            cout<<endl;
        }
        mp.clear();
        v.clear();
    }
}
