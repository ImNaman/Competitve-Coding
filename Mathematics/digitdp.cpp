// Naman Shukla
 
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll len ,bool isequal, bool fg,string R)
{    
    if(len==R.length()) 
    {
        return 1;
    }
    
    ll sol=0;
    if(isequal==false)
    {
        for(ll i=0 ; i<=9 ;i++)
        {
            if(fg==0 && i==0)
              sol+=solve(len+1,0,0,R);
         
            else sol+=solve(len+1,0,1,R);
        }
    }
    else
    {
        for(ll i=0 ; i<=R[len]-'0' ;i++)
        {
            if(i < R[len]-'0' )
            {
                sol+=solve(len+1,0,1,R);
            }
            else 
            {
              	sol+=solve(len+1,1 ,1,R);
            }
        }
    }
    return sol;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);   
	return 0;
}  