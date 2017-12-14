// Naman Shukla

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const int MOD = (int)1e9+7;
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
// Solves systems of linear modular equations.mat[i][C]=b[i];
// Build a matrix of coefficients and call run(mat, R, C, mod).
// If no solution,returns -1, else returns # of free variables.
// If i-th variable free,row[i]=-1,else it’s value = ans[i].


// Time complexity: O(R * C^2) - MAXC is the number of columns
namespace Gauss {
	const int MAXC = 1001;int row[MAXC];ll
	ans[MAXC];
	ll inv(ll x, ll mod) {
		return fpow(x, mod-2, mod);
	}
	int run(ll mat[][MAXC], int R, int C, ll mod) 
	{
		REP(i, C)row[i] = -1;int r = 0;
		REP(c, C)
		{
			int k = r;
			while (k < R && mat[k][c] == 0) ++k;
			if(k==R)continue;
			REP(j,C+1)swap(mat[r][j],mat[k][j]);
			ll div=inv(mat[r][c],mod);
			REP(i,R)
			if(i!=r)
			{
				ll w = mat[i][c]*(mod-div)%mod;
				REP(j, C+1) mat[i][j] = (mat[i][j] + mat[r][j] * w) %
				mod;
			}
			row[c] = r++;
		}
		REP(i,C)
		{
			int r = row[i];
			ans[i]=(r==-1?0:mat[r][C])*inv(mat[r][i],mod)%mod;
			
			}
			FOR(i, r, R)if(mat[i][C])return -1;
			return C - r;
		}
}


// Gauss-Jordan elimination solves (AX = B). O(n^3)
// INPUT: a[][] = an nxn matrix
// b[][] = an nxm matrix
// OUTPUT: X = an nxm matrix (stored in b[][])
// A^{-1} = an nxn matrix (stored in a[][])
// returns determinant of a[][]
const double EPS = 1e-10;
typedef double T;typedef vector<T> VT;typedef vector<VT> VVT;
T GaussJordan(VVT &a, VVT &b) 
{
	const int n=a.size(),m=b[0].size();
	vi irow(n),icol(n),ipiv(n);
	T det=1;
	for(int i=0;i<n;i++)
	{
		int pj=-1,pk=-1;
		for(int j=0;j<n;j++)if(!ipiv[j])
		for(int k=0;k<n;k++)if(!ipiv[k])
		if(pj==-1||fabs(a[j][k])>fabs(a[pj][pk])){pj=j;pk=k;}
		if(fabs(a[pj][pk])<EPS){cerr<<"Matrix is singular."<<endl;exit(0);}
		ipiv[pk]++;swap(a[pj], a[pk]);
		swap(b[pj],b[pk]);
		if(pj!=pk)det*=-1;
		irow[i]=pj;icol[i]=pk;
		T c =1.0/a[pk][pk];
		det*=a[pk][pk];
		a[pk][pk]=1.0;
		for(int p=0;p<n;p++)
			a[pk][p]*=c;
		for(int	p=0;p<m;p++)
			b[pk][p]*=c;
		for(int p=0;p<n;p++)if(p!=pk)
		{
			c=a[p][pk];a[p][pk]=0;
			for(int q=0;q<n;q++)a[p][q]-=a[pk][q]*c;
			for(int q=0;q<m;q++)b[p][q]-=b[pk][q]*c;
		}
	}for(int p=n-1;p>=0;p--)if(irow[p]!=icol[p])
	for(int k=0;k<n;k++)swap(a[k][irow[p]],a[k][icol[p]]);
	return det;
}

int main()
{
	return 0;
}