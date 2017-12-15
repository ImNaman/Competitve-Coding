#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,p,q,r;
int mod=10007;
const int N=4;
 
void mul(int a[N][N],int b[N][N])
{
    int c[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            c[i][j]=0;
            for(int k=0;k<N;k++)
            c[i][j]=(c[i][j]+(a[i][k]*b[k][j])%mod)%mod;
        }
    }
   
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        a[i][j]=c[i][j];
   
}
 
 
void matrix_expo(int a[N][N],int n)
{
    if(n<=1)
    return;
   
   
    matrix_expo(a,n/2);
    mul(a,a);
   
    if(n%2!=0)
    {
    	int F[N][N];
        F[0][0]=p;F[0][1]=0;F[0][2]=q;F[0][3]=1;
        F[1][0]=1;F[1][1]=0;F[1][2]=0;F[1][3]=0;
        F[2][0]=0;F[2][1]=1;F[2][2]=0;F[2][3]=0;
        F[3][0]=0;F[3][1]=0;F[3][2]=0;F[3][3]=1;
        mul(a,F);
    }
}
 
int main()
{
    
    int tc;cin>>tc;
    while(tc--)
    {
        cin>>n>>p>>q>>r;
        if(n<=2)
        printf("Case %d: %d\n",tc,0);
        else
        {
	        int F[N][N];
	        F[0][0]=p;F[0][1]=0;F[0][2]=q;F[0][3]=1;
	        F[1][0]=1;F[1][1]=0;F[1][2]=0;F[1][3]=0;
	        F[2][0]=0;F[2][1]=1;F[2][2]=0;F[2][3]=0;
	        F[3][0]=0;F[3][1]=0;F[3][2]=0;F[3][3]=1;
	        matrix_expo(F,n-2);
	        int ans=(F[0][3]*r)%mod;
	        printf("Case %d: %d\n",tc,ans);
        }
    } 
    return 0;
}