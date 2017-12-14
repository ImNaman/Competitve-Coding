// Naman Shukla

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int lps[100005];

void LPS(string str)
{
	ll p1=1,p2=0;
	lps[0] = 0;	
	ll n = str.length();
	
	while(p1<n)
	{
		if(str[p1]==str[p2])
		{
			lps[p1] = lps[p1-1]+1;
			p1+=1;
			p2+=1;
		}
		else
		{
			if(p2==0)
			{
				lps[p1] = 0;
				p1+=1;
			}
			else
			{
				p2 = lps[p2-1];
			}
		}
	}
}

void KMP(string str,string pat)
{
	ll n1 = str.length();
	ll n2 = pat.length();

	LPS(pat);

	ll p1=0,p2=0;	

	while(p1<n1)
	{
		if(str[p1]==pat[p2])
			p1+=1,p2+=1;

		if(p2==n2)
			p2 = lps[p2-1],cout<<"Pattern found "<<p1-p2<<endl;

		else if(p1<n1 && str[p1]!=pat[p2])
		{
			if(p2!=0)
				p2 =  lps[p2-1];
			else
				p1+=1;
		}
	}
}


int main()
{	
	string a = "ABABABCABABABCABABABC";
	string b = "ABABA";
	KMP(a,b);
}	