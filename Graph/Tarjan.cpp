//Articulation Points and Bridges Tarjan
//dfs_num : Discovery Time dfs_low : Low Time
//For Bridges : dfs_num(u)< dfs_low[v]
vector<int>graph[MAX];
int n,m,cnt;
bool visited[MAX],artpoint[MAX];
int dfs_low[MAX],dfs_num[MAX],degroot,time,root;
void dfs(int u)
{
    visited[u]=1;
    time++;
    dfs_low[u]=dfs_num[u]=time;
    FOR(i,0,graph[u].size())
    {
        int v=graph[u][i];
        if(!visited[v])
        {
            dfs(v);
            if(u==root) degroot++;
            if(degroot>=2)
            {
                artpoint[root]=1;
            }
 
            dfs_low[u]=min(dfs_low[u],dfs_low[v]);
            if(dfs_low[v]>=dfs_num[u] && u!=root)
            {
                artpoint[u]=1;
            }
 
        }
        else
            dfs_low[u]=min(dfs_low[u],dfs_num[v]);
    }
}