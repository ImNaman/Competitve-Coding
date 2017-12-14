// Naman Shukla
// Segtree with Lazy Propogation

#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;

ll tree[400005],lazy[400005],A[100005];

void build(ll node, ll start, ll end)
{
    if(start == end)
    {
        tree[node] = A[start];
    }
    else
    {
        ll mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
void updateRange(int node, int start, int end, int l, int r, int val)
{
    if(lazy[node] != 0)
    { 
        tree[node] += (end - start + 1) * lazy[node];    
        if(start != end)
        {
            lazy[node*2] += lazy[node];                  
            lazy[node*2+1] += lazy[node];                
        }
        lazy[node] = 0;                                      
    }

    if(start > end or start > r or end < l)              
        return;
    if(start >= l and end <= r)
    {
        tree[node] += (end - start + 1) * val;
        if(start != end)
        {
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        
    updateRange(node*2 + 1, mid + 1, end, l, r, val);  
    tree[node] = tree[node*2] + tree[node*2+1];         
}

int queryRange(int node, int start, int end, int l, int r)
{
    if(start > end or start > r or end < l)
        return 0;         
    if(lazy[node] != 0)
    {
        tree[node] += (end - start + 1) * lazy[node]; 
        if(start != end)
        {
            lazy[node*2] += lazy[node];   
            lazy[node*2+1] += lazy[node]; 
        }
        lazy[node] = 0;                 
    }
    if(start >= l and end <= r)             
        return tree[node];
    int mid = (start + end) / 2;
    int p1 = queryRange(node*2, start, mid, l, r);      
    int p2 = queryRange(node*2 + 1, mid + 1, end, l, r);
    return (p1 + p2);
}

int main()
{
    
    return 0;
}