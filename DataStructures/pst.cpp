#include <bits/stdc++.h>
#define MAX 100005
#define pb push_back
#define mp make_pair
using namespace std;

int n,root[MAX];
int l[20*MAX], r[20*MAX], st[20*MAX], NODES = 0;
int newleaf(int value)
{
    int p = ++NODES;
    l[p] = r[p] = 0;
    st[p] = value;
    return p;
}
int newparent(int lef, int rig) {
    int p = ++NODES;
    l[p] = lef;
    r[p] = rig;
    st[p] = st[lef] + st[rig];
    return p;
}
int build( int L=1, int R=n) {
    if (L == R) return newleaf(0);
    else return newparent(build(L, (L+R)/2), build((L+R)/2 + 1, R));
}
int update(int i, int x, int p, int L=1, int R=n) {
    if (L == R) return newleaf(st[p] + x);
    if (i <= (L+R)/2) return newparent(update(i, x, l[p], L, (L+R)/2), r[p]);
    else return newparent(l[p], update(i, x, r[p], (L+R)/2 + 1, R));
}
int query(int rtl,int rtr,int k,int L=1,int R=n)//MKTHNUM Query
{
    if(L==R)
    {
        return L;
    }
    int cnt=st[l[rtr]]-st[l[rtl]];
    int m=(L+R)/2;
    if(cnt>=k)
        return query(l[rtl],l[rtr],k,L,m);
    return query(r[rtl],r[rtr],k-cnt,m+1,R);
}

int main()
{

}