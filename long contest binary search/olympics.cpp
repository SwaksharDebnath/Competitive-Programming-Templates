#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n;
    double a,b,r,d,th,s,x;
    cin>>n;
    for(ll i=1;i<=n;++i)
    {
        scanf("%lf : %lf",&a,&b);
        r = sqrt(a*a+b*b)/2.0;
        d = (r*r+r*r-b*b)/(2.0*r*r);
        th = acos(d);
        s = r*th;
        x = 400.0/(2.0*s+2.0*a);
        a = x*a; b = x*b;
        printf("Case %d: %.8lf %.8lf\n",i,a,b);
    }
}
