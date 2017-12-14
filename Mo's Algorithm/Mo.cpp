// Naman Shukla
// Mo's Algorithm
// Range sum query

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
struct Query 
{
    int l, r;
    int idx;
    Query() 
    {    }
 
    Query(int l, int r, int idx) 
    {
        this->l = l;
        this->r = r;
        this->idx = idx;
    }
};
 
int S;
void initS(int n) {S = sqrt(n);}
 
bool compare(Query a, Query b) 
{
    if (a.l/S != b.l/S) 
    {
        return a.l/S < b.l/S;
    } 
    else 
    {
        return a.r > b.r;
    }
}

const int MAX = 200005;
ll answer[MAX],a[MAX];
Query query[MAX]; 
ll cost = 0;
inline void insert(int v) 
{
    cost += a[v];
}
 
inline void erase(int v) 
{
    cost -= a[v];
}
 
 
int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
    int n, q;cin>>n>>q;
    
    initS(n);
 
    for (int i = 0; i < n; i++) 
    	cin>>a[i];
 
    for (int i = 0; i < q; i++) {
        int l, r;
        cin>>l>>r;
        l--, r--;
        query[i]=Query(l, r, i);
    }
    sort(query, query+q, compare);
 
    int left = 0;
    int right = -1;
    for (int i = 0; i < q; i++) 
    {
        int l = query[i].l;
        int r = query[i].r;
        if (right < r) 
        {
            while (right < r) 
            {
                right++;
                insert(right);
            }
        } 
        else 
        {
            while (right > r) 
            {
                erase(right);
                right--;
            }
        }
 
        if (left < l) 
        {
            while (left < l) 
            {
                erase(left);
                left++;
            }
        } 
        else 
        {
            while (left > l) 
            {
                left--;
                insert(left);
            }
        }
        answer[query[i].idx] = cost;
    }
 
    for (int i = 0; i < q; i++) 
    {
        printf("%lld\n", answer[i]);
    }
    return 0;
}