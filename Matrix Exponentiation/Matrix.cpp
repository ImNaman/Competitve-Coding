#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mk make_pair
#define pp pair<ll,ll>
#define inf 1e9
using namespace std;
ll siev[1000005];
ll phi[1000005];
 
inline void Scan_f(ll &a){char c = 0;while(c<33)c = getc(stdin);a = 0;while(c>33){a = a*10 + c - '0';c = getc(stdin);}}
void sieve(){for(ll i=2;i<=1e6;i++){if(siev[i]==0){for(ll j=i;j<=1e6;j+=i)siev[j]=i,phi[j]=phi[j]*(i-1)/i;}}}
ll gcd(ll a,ll b){if(a<b)swap(a,b);while(b!=0){ll temp=b;b=a%b;a=temp;}return a;}
ll power(ll x, ll y){if (y == 0)return 1;ll p = power(x, y/2);p = (p * p) ;return (y%2 == 0)? p : (x * p);}
ll modInverse(ll a,ll m){return power(a, phi[m]-1);}
 
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
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    /*for(ll i=1;i<=1e6;i++)
    phi[i]=i;
    phi[0]=0;
    sieve();*/
   
 
       
   
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
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