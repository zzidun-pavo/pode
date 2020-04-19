#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

static ll n, rt, sum, ans, a[200100];
static vector<ll> G[200100];

static ll tot;
static ll fa[200100], len[200100], son[200100];
static ll dfn[200100], rnk[200100];
static ll lid[200100], rid[200100];

void dfs1(ll u)
{
    for(ll v : G[u])
    {
        if(v == fa[u]) continue;
        fa[v] = u;
        dfs1(v);
        if(len[v] > len[son[u]]) son[u] = v;
    }
    len[u] = len[son[u]]+1;
}

void dfs2(ll u)
{
    dfn[u] = ++tot; rnk[tot] = u;

    lid[u] = dfn[u];
    if(son[u]) dfs2(son[u]);
    rid[u] = tot;

    for(ll v : G[u])
    {
        if(v == fa[u] || v == son[u]) continue;
        dfs2(v);
    }
}

static ll seg[200100<<2], lazy[200100<<2];

void pushup(ll rt)
{
    seg[rt] = seg[rt*2] + seg[rt*2+1];
}

void pushdown(ll rt)
{
    seg[rt*2] += lazy[rt]; lazy[rt*2] += lazy[rt];
    seg[rt*2+1] += lazy[rt]; lazy[rt*2+1] += lazy[rt];
    lazy[rt] = 0;
}

void build(ll rt, ll l, ll r)
{
    if(l == r)
    {
        seg[rt] = 0;
        lazy[rt] = 0;
        return;
    }
    ll mid = (l+r)/2;
    build(rt*2, l, mid);
    build(rt*2+1, mid+1, r);
    pushup(rt);
}

void update(ll rt, ll l, ll r, ll ql, ll qr, ll val)
{
    if(ql <= l && r <= qr)
    {
        seg[rt] += val;
        lazy[rt] += val;
        return;
    }
    pushdown(rt);
    ll mid = (l+r)/2;
    if(ql <= mid) update(rt*2, l, mid, ql, qr, val);
    if(mid < qr) update(rt*2+1, mid+1, r, ql, qr, val);
    pushup(rt);
}

ll query(ll rt, ll l, ll r, ll ql, ll qr)
{
    if(ql <= l && r <= qr)
        return seg[rt];
    pushdown(rt);
    ll mid = (l+r)/2;
    ll ret = 0;
    if(ql <= mid) ret += query(rt*2, l, mid, ql, qr);
    if(mid < qr) ret += query(rt*2+1, mid+1, r, ql, qr);
    return ret;
}

ll no01(ll rt, ll l, ll r, ll ql, ll qr)
{
    if(ql <= l && r <= qr)
        return no[rt];
    pushup(rt);
    ll mid = (l+r)/2;
    ll ret = 0;
    if(ql <= mid) ret += query(rt*2, l, mid, ql, qr);
    if(mid < qr) ret += query(rt*2+1, mid+1, r, ql, qr);
    return ret;
}

void dfs(ll u)
{
    if(son[u])
        dfs(son[u]);
    for(ll v : G[u])
    {
        if(v == fa[u] || v == son[u]) continue;
        dfs(v);
        for(ll i = lid[v]; i <= rid[u]; ++i)
        {
            ll tmp = query(1, 1, n, i, i);
            update(1, 1, n, lid[u]+(i - lid[v]), lid[u]+(i - lid[v]), tmp);

        }
    }

    update(1, 1, n, lid[u], lid[u], a[u]);

    ans -= no01(1, 1, n, lid[u], rid[u]);
    update(1, 1, n, lid[u], rid[u], -1);
}

int main()
{
    scanf("%lld%lld", &n, &rt);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    for(int i = 1; i <= n; ++i)
    {
        ll u, v;
        scanf("%lld%lld", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(rt);
    dfs2(rt);

    build(1, 1, n);

    dfs(rt);

    printf("%lld\n", ans);
}
