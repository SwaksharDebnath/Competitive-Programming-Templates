#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    ll a,b;
};
int main()
{
    ll b = 4;//(abs(1-4)+1);
    cout<<b<<endl;
    if(((abs(1-4)+1)&1) == 0)
        cout<<"000"<<endl;
    else
        cout<<"111"<<endl;

}
