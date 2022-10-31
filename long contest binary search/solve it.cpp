#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll p,q,r,s,t,u,c=0;
    double fx,hi,lo,md;
    while(scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)!= EOF)
    {
        lo = 0.00;hi = 1.00;c = 0;
        while(lo <= hi)
        {
            md = (lo+hi)/2;
            fx = (p*exp(-md))+(q*sin(md))+(r*cos(md))+(s*tan(md))+(t*md*md)+u;

            if(fx<0.0001 && fx>0)
            {
                cout<<md<<endl;
                break;
                c=1;
            }
            else if(fx<0)
                lo = md+.0001;
            else
                hi = md-.0001;

            //cout<<md<<" "<<fx<<endl;


        }
        if(lo>hi)
            cout<<"No solution"<<endl;

    }
}
