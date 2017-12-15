ll A[N],DP[K][N],cost[N][N];
int k; 
void solve(int l,int r,int L,int R)
{ 
	if(l>r)return; 
	int mid = (l+r)/2,best = L;
	DP[k][mid]=INF; 
	
	for(int i = min(R,mid-1);i>=L;i--) 
		if(DP[k-1][i] + cost[i+1][mid] <= DP[k][mid]) 
			DP[k][mid] = DP[k-1][i] + cost[i+1][mid],best = i; 
	
	solve(l,mid-1,L,best);solve(mid+1,r,best,R); 
}

	/*in main
	for(int i=1;i<=n;i++)DP[1][i]=cost[1][i]; 
	for(k=2;k<=kk;k++)solve(1,n,1,n); */

/*
//Given an array A of 2^N integers,calculate x, F(x) = Sum of
//all A[i] such that x & i = i, i.e., i is a subset of x.
//dp[mask][i]:subsets where first i bits of mask can differ
REP(mask,(1<<N)){dp[mask][-1] = A[mask];//handle base case
REP(i,N)if(mask&(1<<i))
dp[mask][i] = dp[mask][i-1] + dp[mask^(1<<i)][i-1];
else dp[mask][i] = dp[mask][i-1];
}F[mask] = dp[mask][N-1];
}//memory optimized, super easy to code.
REP(i,(1<<N))F[i] = A[i];
REP(i,N)REP(mask,(1<<N))
if(mask&(1<<i))F[mask]+=F[mask^(1<<i)];
//note : to iterate over submasks of a mask use this
for(int s=m; s; s=(s-1)&m) //process 0 separately
*/