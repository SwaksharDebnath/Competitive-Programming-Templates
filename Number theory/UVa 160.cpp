#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool isprime[101];
int lpf[101]={0};
int pf[101]={0};
void leprfa()
{
    memset(isprime,true,sizeof isprime);
    lpf[1]=1;
    for(ll p=2;p<=101;++p)
    {
        if(isprime[p] == true)
        {
            lpf[p] = p;
            for(ll i= p*2;i<=101;i+=p)
            {
                if(lpf[i] == 0)
                    lpf[i] = p;
                isprime[i] = false;
            }
        }
    }
}
void prfa(int n)
{
    while(n!=1)
    {
        ++pf[lpf[n]];
        n = n/lpf[n];
    }
}
int main()
{
    ll x,y,c=0;
    leprfa();
    while(1)
    {
        cin>>x;
        c = 0;
        if(x==0)
            return 0;
        y=x;
        printf("%3d! =",x);
        while(x>1)
        {
            prfa(x);
            --x;
        }
        for(ll i=2;i<=y;++i)
        {
            if(isprime[i] == true)
            {
                ++c;
                if(c < 16)
                    printf("%3d",pf[i]);
                if(c == 16){
                    cout<<endl;
                    printf("%9d",pf[i]);
                }
                if(c > 16)
                    printf("%3d",pf[i]);

            }
                //cout<<pf[i]<<" ";

        }
        cout<<endl;

        memset(pf,0,sizeof pf);
    }
}
