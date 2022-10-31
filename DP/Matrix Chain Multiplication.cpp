#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF INT_MAX

struct sides{
    ll x,y;
};

float mem[100][100];
vector<sides>poly;

float dist(sides p1, sides p2)
{
     return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

float cost(int i, int j, int k)
{
    sides p1 = poly[i];
    sides p2 = poly[j];
    sides p3 = poly[k];
    return dist(p1,p2) + dist(p2,p3) + dist(p3,p1);
}

float solve(int i,int j)
{
    if(j < i+2)
        return 0;
    float res = INF;

    if(mem [i][j])
        return mem[i][j];

    for(int k = i+1; k<j; ++k)
    {
        float left = solve(i,k);
        float right = solve(k,j);
        float cst = cost(i,k,j);
        float mrg = left + right + cst;
        res = min(res, mrg);
    }
    mem[i][j] = res;
    return mem[i][j];
}
int main()
{
    ll n;
    cout<<"Enter n: ";cin>>n;
    cout<<"Enter vertices (x,y) :"<<endl;
    for(ll i=0;i<n;++i)
    {
        sides s;
        cout<<"Vertex "<<i+1<<endl;
        cout<<"x: ";cin>>s.x;
        cout<<"y: ";cin>>s.y;

        poly.push_back(s);
    }
    float ans = solve(0,n-1);

    cout<<"Minimum Triangulation Cost will be: "<<ans<<endl;
}
