#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

static ll n, rt, ans;

static ll sum;
static vector<ll> G[200100];
static ll a[200100];

static ll tot;
static ll fa[200100], dep[200100], siz[200100];
static ll son[200100], dfn[200100], tp[200100];

void dfs1(ll u)
{
    dep[u] = dep[fa[u]] + 1;
    siz[u] = 1;
    for(ll v : G[u])
    {
        if(v == fa[u]) continue;
        fa[v] = u;
        dfs1(v);
        if(siz[son[u]] < siz[v]) son[u] = v;
        siz[u] += siz[v];
    }
}

void dfs2(ll u)
{
    dfn[u] = ++tot;
    if(son[u]){
        tp[son[u]] = tp[u];
        dfs2(son[u]);
    }
    for(ll v : G[u])
    {
        if(v == son[u] || v == fa[u]) continue;
        tp[v] = v;
        dfs2(v);
    }
}

ll lca(ll x, ll y)
{
    while(tp[x] != tp[y])
    {
        if(dep[tp[x]] > dep[tp[y]]) x = fa[tp[x]];
        else y = fa[tp[y]];
    }
    return dep[x]>dep[y]?x:y;
}

static ll virual[200100], cnt;

int main()
{
    scanf("%lld%lld", &n, &rt);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    for(int i = 2; i <= n; ++i)
    {
        int u, v;
        scanf("%lld%lld", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(rt);
    tp[rt] = rt;
    dfs2(rt);
    for(int i = 1; i <= n; ++i)
        if(a[i])
            virual[++cnt] = i;
    sort(virual+1, virual+1+n);
    for(int i = 1; i <= n; ++i)
}
