#include<bits/stdc++.h>
using namespace std;
#define ll long long int
double func(double x,double y,double md)
{
    double h1 = (sqrt(x*x-md*md));
    double h2 = (sqrt(y*y-md*md));
    return (h1*h2)/(h1+h2);
}
int main()
{
    ll n,cnt=0;
    cin>>n;
    double x,y,c,hi,lo,md,val;
    for(ll i=1; i<=n; ++i)
    {
        cin>>x>>y>>c;
        cnt = 150;
        lo = 0;
        hi = min(x,y);
        while(cnt--)
        {
            md = (lo+hi)/2.0;

            val= func(x,y,md);

            if(val <= c) hi = md;
            else lo = md;

        }
        printf("Case %lld: %0.7lf\n",i,hi);
    }
}
