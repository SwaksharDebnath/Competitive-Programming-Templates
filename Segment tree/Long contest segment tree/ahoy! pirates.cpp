#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 100005

string s="-";
struct info{
    ll z=0,o=0;
    char l1='0',l2='0';
}tree[4*MAX];
void init(ll node,ll b,ll e)
{
    if(b == e)
    {
        if(s[b] == '0')
            tree[node].z = 1;
        else
            tree[node].o = 1;
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].z = tree[left].z+tree[right].z;
    tree[node].o = tree[left].o+tree[right].o;
}
void magic(struct info *p,char val)
{
    if(p->l2 == 'I' && val == 'I')
        p->l2 = p->l1;
    else
    {
        p->l1 = p->l2;
        p->l2 = val;
    }
}
void up(struct info *p,char c,ll num)
{
    if(c == 'F'){ p->o = num; p->z = 0; }
    else if(c == 'E'){ p->z = num; p->o = 0; }
    else if(c == 'I'){
        ll t = p->z;
        p->z = p->o;
        p->o = t;
    }
}
void update(ll node,ll b,ll e,ll i,ll j,char val)
{
    if(tree[node].l1 != '0' || tree[node].l2 != '0')
    {
        if(tree[node].l1 != '0') up(&tree[node],tree[node].l1,(e-b+1));
        if(tree[node].l2 != '0') up(&tree[node],tree[node].l2,(e-b+1));
        if(b != e)
        {
            if(tree[node].l1 != '0'){magic(&tree[node*2],tree[node].l1); magic(&tree[node*2+1],tree[node].l1);}
            if(tree[node].l2 != '0'){magic(&tree[node*2],tree[node].l2); magic(&tree[node*2+1],tree[node].l2);}
        }
        tree[node].l1 = '0';tree[node].l2 = '0';
    }
    if(b>j || e<i)
        return;
    else if(b>=i && e<= j)
    {
        up(&tree[node],val,(e-b+1));
        if(b != e)
            {magic(&tree[node*2],val); magic(&tree[node*2+1],val);}
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;
    update(left,b,mid,i,j,val);
    update(right,mid+1,e,i,j,val);
    tree[node].z = tree[left].z+tree[right].z;
    tree[node].o = tree[left].o+tree[right].o;
}
ll query(ll node,ll b,ll e,ll i,ll j)
{
    if(b>j || e<i)
        return 0;
    if(tree[node].l1 != '0' || tree[node].l2 != '0')
    {
        if(tree[node].l1 != '0') up(&tree[node],tree[node].l1,(e-b+1));
        if(tree[node].l2 != '0') up(&tree[node],tree[node].l2,(e-b+1));
        if(b != e)
        {
            if(tree[node].l1 != '0'){magic(&tree[node*2],tree[node].l1); magic(&tree[node*2+1],tree[node].l1);}
            if(tree[node].l2 != '0'){magic(&tree[node*2],tree[node].l2); magic(&tree[node*2+1],tree[node].l2);}
        }
        tree[node].l1 = '0';tree[node].l2 = '0';
    }
    if(b>=i && e<=j)
        return tree[node].o;
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;
    ll p = query(left,b,mid,i,j);
    ll q = query(right,mid+1,e,i,j);
    return (p+q);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s1;
    char val;
    ll t,len,m,t1,q,start,nd,p;
    cin>>t;
    for(ll i=1;i<=t;++i)
    {
        memset(tree,0,sizeof tree);
        s.clear();
        s = "-";
        cin>>m;
        while(m--)
        {
            cin>>t1;
            cin>>s1;
            while(t1--) s+=s1;

        }
        len = s.length();len--;
        cout<<s<<endl;
        init(1,1,len);
        cout<<len<<endl;
        cin>>q;
        ll cnt = 0;
        cout<<"Case "<<i<<":"<<endl;
        for(ll j=1;j<=q;++j)
        {
            cin>>val>>start>>nd;
            start++;nd++;
            //cout<<val<<endl;
            if(val == 'S'){
                ++cnt;
                p = query(1,1,len,start,nd);
                cout<<"Q"<<cnt<<": "<<p<<endl;
            }
            else
                update(1,1,len,start,nd,val);
        /*cout<<"--------------"<<endl;
        for(ll k=1;k<=2*len;++k)
            cout<<tree[k].z<<" "<<tree[k].o<<endl;*/
        }
    }










    /*cin>>s1;
    s += s1;
    //printf("%s",s);
    cout<<s<<endl;
    ll p = -1;
    ll n = s.length();
    cout<<n<<endl;
    init(1,1,n-1);
    p = query(1,1,n-1,2,4);
    cout<<p<<endl;
    update(1,1,n-1,2,4,'F');
    update(1,1,n-1,2,4,'I');
    update(1,1,n-1,2,4,'I');
    p = query(1,1,n-1,2,4);
    cout<<p<<endl;*/
}
