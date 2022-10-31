#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ff first
#define ss second
/*struct stu{
    ll id,mark;
    string name;
    bool operator < (const stu &var) const ///operator overloading
    {
        ///'<':ascending order  '>':descending order
        if(id!=var.id)
            return id < var.id;
        if(mark!=var.mark)
            return mark < var.mark;
    }
};*/
bool cmp(pair<ll,pair<ll,ll> > lhs,pair<ll,pair<ll,ll> > rhs)///type of vector
{
    ///'<':ascending order  '>':descending order
    if(lhs.ff!=rhs.ff)
        return lhs.ff < rhs.ff;
    if(lhs.ss.ss!=rhs.ss.ss)
        return lhs.ss.ss < rhs.ss.ss;
}
int main()
{
    vector<pair<ll,pair<ll,ll> > >vpp;
    for(ll i=0;i<5;++i)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        vpp.push_back({x,{y,z}});
    }
    sort(vpp.begin(),vpp.end(),cmp);

    for(ll i=0;i<5;++i)
        cout<<vpp[i].ff<<" "<<vpp[i].ss.ff<<" "<<vpp[i].ss.ss<<endl;
}
/*1 6 302
4 13 402
4 9 341
2 11 109
3 2 489*/

