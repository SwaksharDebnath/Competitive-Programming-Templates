#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,m,u,pos;
    cin>>n>>m>>u;
    vector<ll>v(n),v1(n);
    for(ll i=0; i<n; ++i)
    {
        cin>>v1[i];
        v[i] = v1[i];
    }
    ll len = ceil(sqrt(n)),mn;
    for(ll i=0; i<len; ++i)
    {
        pos = i*len;
        mn = min(n,(pos+len));
        if(pos < n)
            sort(v.begin()+pos,v.begin()+mn);
    }
    ll l,r,e,p,cl,cr,sum=0,val,val2,x,y;
    //cin>>l>>r>>e;
    //cl = l/len;
    //p = (cl*len+(len-1));
    //cout<<p<<endl;
    //pos = lower_bound(v.begin()+l,v.begin()+p,e) - v.begin();
    //cout<<pos<<endl;
    while(m--)
    {
        cin>>l>>r>>e>>p;
        --l;
        --r;
        cl = l/len;
        cr = r/len;
        pos = 0;
        sum = 0;
        if(cl == cr)
        {
            for(ll i=l; i<=r; ++i)
            {
                if(v1[i]<e)
                    sum++;
            }
            cout<<"sum"<<" "<<sum<<endl;
        }
        else
        {
            val = (cl*len+(len-1));
            val2 = (l/len)*len;
            if(e>=v[val2] && e<= v[val])
            {
                for(ll i=l; i<=val; ++i)
                {
                    if(v1[i]<e)
                        sum++;
                }
            }
            else
            {
                if(e>v[val]) sum += val-(l-1);
            }
            cout<<"sum"<<" "<<sum<<endl;
            if(cr - cl >1)
            {
                for(ll i=cl+1; i<cr; ++i)
                {
                    val = (i*len+(len-1));
                    val2 = i*len;
                    if(e>=v[val2] && e<= v[val])
                    {
                        pos = lower_bound(v.begin()+val2,v.begin()+val,e) - v.begin();
                        sum += pos - val2;
                    }
                    else
                    {
                        if(e>v[val]) sum += len;
                    }
                }

            }
          cout<<"sum"<<" "<<sum<<endl;
            val = cr*len;
            val2 = val+(len-1);
            if(e>=v[val] && e<= v[val2])
            {
                for(ll i=val; i<=r; ++i)
                    if(v1[i]<e)
                        sum++;
            }
            else
            {
                if(e>v[r]) sum+= (r-val)+1;
            }
            cout<<"sum"<<" "<<sum<<endl;
        }
        cout<<"sum"<<" "<<sum<<" "<<cl<<" "<<cr<<endl;
        p--;
        x = (p/len)*len;
        y = min(n,x+len);
        v1[p] = (u*sum)/((r-l)+1);

        for(ll i=x; i<y; ++i)
            v[i] = v1[i];
        sort(v.begin()+x,v.begin()+y);

        //for(ll i=x,j=0; i<y; ++i,++j)
        // v[i] = v3[j];
        //v3.clear();
        for(ll i=0; i<n; ++i)
           cout<<v[i]<<endl;

    }

    for(ll i=0; i<n; ++i)
        cout<<v1[i]<<endl;

}
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,m,u,pos;
    cin>>n>>m>>u;
    vector<ll>v(n),v1(n);
    for(ll i=0; i<n; ++i)
    {
        cin>>v1[i];
        v[i] = v1[i];
    }
    ll len = ceil(sqrt(n)),mn;
    for(ll i=0; i<len; ++i)
    {
        pos = i*len;
        mn = min(n,(pos+len));
        if(pos < n)
            sort(v.begin()+pos,v.begin()+mn);
    }
    ll l,r,e,p,cl,cr,sum=0,val,val2,x,y;
    //cin>>l>>r>>e;
    //cl = l/len;
    //p = (cl*len+(len-1));
    //cout<<p<<endl;
    //pos = lower_bound(v.begin()+l,v.begin()+p,e) - v.begin();
    //cout<<pos<<endl;
    while(m--)
    {
        cin>>l>>r>>e>>p;
        --l;
        --r;
        cl = l/len;
        cr = r/len;
        pos = 0;
        sum = 0;
        if(cl == cr)
        {
            for(ll i=l; i<=r; ++i)
            {
                if(v1[i]<e)
                    sum++;
            }
            cout<<"sum"<<" "<<sum<<endl;
        }
        else
        {
            val = (cl*len+(len-1));
            val2 = (l/len)*len;
            if(e>=v[val2] && e<= v[val])
            {
                for(ll i=l; i<=val; ++i)
                {
                    if(v1[i]<e)
                        sum++;
                }
            }
            else
            {
                if(e>v[val]) sum += val-(l-1);
            }
            cout<<"sum"<<" "<<sum<<endl;
            if(cr - cl >1)
            {
                for(ll i=cl+1; i<cr; ++i)
                {
                    val = (i*len+(len-1));
                    val2 = i*len;
                    if(e>=v[val2] && e<= v[val])
                    {
                        pos = lower_bound(v.begin()+val2,v.begin()+val,e) - v.begin();
                        sum += pos - val2;
                    }
                    else
                    {
                        if(e>v[val]) sum += len;
                    }
                }

            }
          cout<<"sum"<<" "<<sum<<endl;
            val = cr*len;
            val2 = val+(len-1);
            if(e>=v[val] && e<= v[val2])
            {
                for(ll i=val; i<=r; ++i)
                    if(v1[i]<e)
                        sum++;
            }
            else
            {
                if(e>v[r]) sum+= (r-val)+1;
            }
            cout<<"sum"<<" "<<sum<<endl;
        }
        cout<<"sum"<<" "<<sum<<" "<<cl<<" "<<cr<<endl;
        p--;
        x = (p/len)*len;
        y = min(n,x+len);
        v1[p] = (u*sum)/((r-l)+1);

        for(ll i=x; i<y; ++i)
            v[i] = v1[i];
        sort(v.begin()+x,v.begin()+y);

        //for(ll i=x,j=0; i<y; ++i,++j)
        // v[i] = v3[j];
        //v3.clear();
        for(ll i=0; i<n; ++i)
           cout<<v[i]<<endl;

    }

    for(ll i=0; i<n; ++i)
        cout<<v1[i]<<endl;

}
