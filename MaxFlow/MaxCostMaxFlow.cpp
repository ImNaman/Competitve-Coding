#include <bits/stdc++.h>
using namespace std;
#define FOR(i,x,y) for(int i=x;i<=y;++i)
#define N 220

int dis[N],st[N],c[N*N],Next[N*N],head[N],e[N*N],len,v[N*N],S,T,flag[N],bfs[N*1000];
int dv[N][N],n,Id[N][N],m;

void addedge(int x,int y,int w){
	Next[++len]=head[x]; head[x]=len; e[len]=y; c[len]=1; v[len]=w;
	Next[++len]=head[y]; head[y]=len; e[len]=x; c[len]=0; v[len]=-w;
}
int Costflow()
{
	int l,r,ans=0;
	for(;;){
		FOR(i,1,T)dis[i]=-1<<30;
		dis[S]=0;
		bfs[l=r=1]=S;
		while(l<=r){
			int x=bfs[l++],y;
			flag[x]=0;
			for(int i=head[x];i;i=Next[i])if(c[i] && dis[x]+v[i]>dis[y=e[i]]){
				dis[y]=dis[x]+v[i];
				st[y]=i;
				if(!flag[y]){
					flag[y]=1;
					bfs[++r]=y;
				}
			}
		}
		if(dis[T]<-1000)return ans;
		for(int i=T;i!=S;i=e[st[i]^1])c[st[i]]--,c[st[i]^1]++;
		ans+=dis[T];
	}
}
int main()
{
	
	return 0;	
}