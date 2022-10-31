#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct stu{
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
};
bool cmp(stu lhs,stu rhs)
{
    ///'<':ascending order  '>':descending order
    if(lhs.id!=rhs.id)
        return lhs.id < rhs.id;
    if(lhs.mark!=rhs.mark)
        return lhs.mark < rhs.mark;
}
int main()
{
    stu arr[6];
    for(ll i=1;i<=5;++i)
        cin>>arr[i].id>>arr[i].name>>arr[i].mark;
    ///sort(arr+1,arr+6,cmp);///need to write compare function as 3rd parameter
    sort(arr+1,arr+6);///no need to write compare function when using operator overloading

    for(ll i=1;i<=5;++i)
        cout<<arr[i].id<<" "<<arr[i].name<<" "<<arr[i].mark<<endl;
}
/*1 ertr 302
4 quw 341
4 kdife 402
2 oks 109
3 aoi 489*/
