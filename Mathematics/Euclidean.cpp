// Naman Shukla


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

ll mod(ll a, ll b) 	// return a % b (positive value)
{
	while(a<0)a += b;
	return (a%b);
}

ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}  // computes gcd(a,b)

ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}	// computes lcm(a,b)

// returns d = gcd(a,b); finds x,y such that d = ax + by
ll extended_euclid(ll a, ll b, ll &x, ll &y) 
{
	ll xx = y = 0;
	ll yy = x = 1;
	while (b) 
	{
		ll q = a/b;
		ll t = b; b = a%b; a = t;
		t = xx; xx = x-q*xx; x = t;
		t = yy; yy = y-q*yy; y = t;
	}
return a;
}

// finds all solutions to ax = b (mod n)
vi modular_linear_equation_solver(ll a, ll b, ll n) 
{
	ll x, y;
	vi solutions;
	ll d = extended_euclid(a, n, x, y);
	
	if (!(b%d)) 
	{
		x = mod (x*(b/d), n);
		
		for (ll i = 0; i < d; i++)
			solutions.push_back(mod(x + i*(n/d), n));
	}

	return solutions;
}


// computes x and y such that ax + by = c; on failure, x = y =-1
// Note that solution exists iff c is a mulltiple of gcd(a,b)
void linear_diophantine(ll a, ll b, ll c, ll &x, ll &y) 
{
	ll d = gcd(a,b);
	if (c%d) 
	{
		x = y = -1;
	} 
	else 
	{
		extended_euclid(a,b,x,y);
		x = x*(c/d);
		y = y*(c/d);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	return 0;
}