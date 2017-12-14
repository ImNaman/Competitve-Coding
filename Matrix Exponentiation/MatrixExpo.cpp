// Naman Shukla
// Template has't been tested

#include <bits/stdc++.h>
using namespace std;
typedef int ll;

class matrix
{
public:
	ll **a;
	ll n;

	matrix(ll g=2)
	{
		n = g;
		a = new ll*[n];
		for(ll i=0;i<n;i++)
			a[i] = new ll[n];

		for(ll i=0;i<n;i++)
			for(ll j=0;j<n;j++)
				a[i][j] = 0;
	}
	void identity()
	{
		for(ll i=0;i<n;i++)
			for(ll j=0;j<n;j++)
				a[i][j] = (i==j);
	}
	void print()
	{
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<n;j++)
				cout<<a[i][j]<<" ";cout<<"\n";
		}
	}
};

matrix mul(matrix A, matrix B)
{
	matrix ans(A.n);
	ll sz = A.n;
	for(ll i=0;i<sz;i++)
	{
		for(ll j=0;j<sz;j++)
		{
			for(ll k=0;k<sz;k++)
			{
				ans.a[i][j] += A.a[i][k]*B.a[k][j];
			}
		}
	}
	return ans;
}


matrix expo(matrix M, ll k)
{
	matrix N(M.n);
	N = M;
	matrix ans(M.n);
	ans.identity();

	for (; k; k >>= 1) 
	{
		if (k & 1) 
			ans = mul(ans,N) ; 
		N = mul(N,N) ;
	}
	return ans;	
}


int main()
{
	// Example to print the nth Fibonacci number  1 , 1 , 2 , 3....
	// a(n) = a(n-1) + a(n-2)

	matrix a(2);

	a.a[0][0] = 1;
	a.a[0][1] = 1;
	a.a[1][0] = 1;

	matrix ans = expo(a,22);  // To print the 22nd fibo numer
	cout<<ans.a[0][0]<<endl;	
		
	return 0;
}