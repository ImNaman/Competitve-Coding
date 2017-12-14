#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = (int)1e9+7;
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}


bool miller_rabin_primality(ll N)
{
	static const int p[12]={2,3,5,7,11,13,17,19,23,29,31,37};
	if(N<=1)return false;
	for(int i=0;i<12;++i){
	if(p[i]==N)return true;if(N%p[i]==0)return false;
	}ll c =N-1,g=0;while(!(c&1))c>>=1,++g;
	for(int i=0;i<12;++i){
	ll k=fpow(p[i],c,N);
	for(int j=0;j<g;++j){
	ll kk=mult(k,k,N);if(kk==1&&k!=1&&k!=N-1)return false;
	k=kk;}if(k!=1)return false;
	}return true;
}
ll pollard_rho(ll N)
{
	if(N%2==0)return 2;
	ll xx=uniform_int_distribution<ll>()(gen)%N,x=xx;
	ll c=uniform_int_distribution<ll>()(gen)%N,d=1;
	for(int iters=0;iters<2000;++iters){
	x=(mult(x,x,N)+c)%N;xx=(mult(xx,xx,N)+c)%N;
	xx=(mult(xx,xx,N)+c)%N;d=__gcd(abs(x-xx),N);
	if(d!=1&&d!=N)break;
	}
	return d;

}

//solves a^2=x(mod p),return -1 if x not exist
#define M(x) x%p
ll root_of_x(ll x,ll p)
{
	ll r=0,s=p-1,n,m,x,b,g,coff,t;
	if(power(a,((p-1)>>1),p)==p-1)return -1;
	//calcute (a^((p-1)/2))%p;
	while((s&1)==0){
		s=(s>>1);r++;}
	for(ll i=2;i<p;i++)
	if(power(i,((p-1)>>1),p)==p-1){n=i;break;}
	b=power(a,s,p);g=power(n,s,p);
	x=power(a,((s+1)>>1),p);
	while(r>0){
		t=b;
		for(m=0;m<r;m++){if(M(t)==1)break;t=M(t*t);}
		if(m>0)
		{
			coff=power(g,(1<<(r-(m+1))),p);x=M(x*coff);
			g=M(coff*coff);b=M(b*g);
		}
		r=m;
	}
	return x;
}