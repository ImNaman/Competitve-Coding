#include <bits/stdc++.h> 
vector<ll> Fact;
vector<ll> Invfact;
vector<ll> Inv;
 
//Preprocessing factorial and its inverses in O(p) time.
void compute(int P)
{
	Fact.clear();
	Invfact.clear();
	Fact.resize(P);
	Invfact.resize(P);
	Inv.clear();
    Inv.resize(P);
        
	Fact[0]=Fact[1]=1;
	Invfact[0]=Invfact[1]=1;
	Inv[0]=1;
    Inv[1]=1;
	
	for(int i=2;i<P;i++)
	{
		Fact[i]=mult(Fact[i-1],i);
		Inv[i]= mult((P-P/i),Inv[P%i]);
	}
	for(int i=2;i<P;i++)
		Invfact[i] = Inv[Fact[i]];
}
 