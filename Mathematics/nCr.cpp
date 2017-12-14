#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//Template 1 p should be prime
//Template 2 p works for composite too



//Computes C(N,R) modulo P in O(log(n)) time.
ll Lucas(ll N,ll R,int P)
{
  if(R<0||R>N)
    return 0;
  
  if(R==0||R==N)
    return 1;
 
  if(N>=P)
  {
    return mult(Lucas(N/P,R/P,P),Lucas(N%P,R%P,P));
  }
  return mult(Fact[N],mult(Invfact[N-R],Invfact[R]));
}

// sujeets template for C(n,r)
ll ncr(ll n,ll r)
{
   ll cntn=0,cntr=0,cntnr=0;
   ll u=n;
   
   while(u>=mod){
      cntn+=(u/mod);u=u/mod;}
   u=n-r;
   while(u>=mod){
      cntnr+=(u/mod);u=u/mod;}
 
   u=r;
   while(u>=mod){
      cntr+=(u/mod);u=u/mod;}
 
   if(cntn>cntr+cntnr)
      return 0;
   else
   {
     ll num=1,den=1,j=1;
     u=n;
     while(u>0)
     {
         ll v=((power(fac[mod],u/mod)*fac[u%mod])%mod)%mod;
         num=(num*v)%mod;
         u=u/mod;
     }
     
     j=1;u=n-r;
     while(u>0)
     {
        ll v=((power(fac[mod],u/mod)*fac[u%mod])%mod)%mod; 
        den=(den*v)%mod;
        u=u/mod;
     }
 
     j=1;u=r;
     while(u>0)
     {
        ll v=((power(fac[mod],u/mod)*fac[u%mod])%mod)%mod; 
        den=(den*v)%mod;
         u=u/mod;
     }
     return (num*modinverse(den))%mod;
   }
 
}
