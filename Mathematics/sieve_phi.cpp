#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9+7;

int fac[1000005]; // stores the largest prime factor of n   
int phi[1000005]; // stores number of numbers co-prime with n less than n
 
void sieve()   // 2853708 computations
{
	for(int i=2;i<=1e6;i++)
	{
		if(fac[i]==0)
		{
			for(int j=i;j<=1e6;j+=i)
				fac[j]=i,
				phi[j]=phi[j]*(i-1)/i;
		}
	}
}

ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;} // returns (x^y)%z

ll modInverse(int a,int m) // returns inverse mod of a 
{
	return fpow(a, phi[m]-1,m);
}

	 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	return 0;
}