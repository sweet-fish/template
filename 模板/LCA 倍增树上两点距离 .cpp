struct edge
{
    int to,nxt;
}e[1000005];
int tot=0;
int head[500005];
int fa[500005];
int dep[500005];
int jmp[500005][20];
void init(int n)
{
    tot=0;
    for(int i=1;i<=n;++i)
    {
        dep[i]=0;
        head[i]=-1;
        for(int j=0;j<20;++j)
            jmp[i][j]=0;
    }
}
void ae(int u,int v)
{
    e[tot]={v,head[u]};
    head[u]=tot++;
    e[tot]={u,head[v]};
    head[v]=tot++;
}
void dfs(int rt)
{
    jmp[rt][0]=fa[rt];
    for(int i=1;i<20;++i)
        jmp[rt][i]=jmp[jmp[rt][i-1]][i-1];
    for(int i=head[rt];~i;i=e[i].nxt)
        if(e[i].to!=fa[rt])
        {
            int u=e[i].to;
            fa[u]=rt;
            dep[u]=dep[rt]+1;
            dfs(u);
        }
}
int lca(int u,int v)
{
    if(dep[u]>dep[v])
        swap(u,v);
    for(int i=19;~i;--i)
        if(dep[u]<=dep[jmp[v][i]])
            v=jmp[v][i];
    if(u==v)
        return v;
    for(int i=19;~i;--i)
        if(jmp[u][i]!=jmp[v][i])
        {
            u=jmp[u][i];
            v=jmp[v][i];
        }
    return jmp[u][0];
}
