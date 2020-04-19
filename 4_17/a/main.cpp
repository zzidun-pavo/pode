#include <bits/stdc++.h>

using namespace std;

static unsigned int t, nr, ng, nb;
static vector<long long> r, g, b;
static long long ans;



long long lb(vector<long long> &a, vector<long long> &b, vector<long long> &c)
{
    long long ret = 0x3f3f3f3f3f3f3f3f;
    for(long long x : a)
    {
        long long y, z;

        unsigned int pos = lower_bound(b.begin(), b.end(), x) - b.begin();
        if(pos >= b.size()) continue;
        else y = b[pos];

        pos = lower_bound(c.begin(), c.end(), x) - c.begin();
        if(pos >= c.size()) continue;
        else z = c[pos];


        ret = min(ret, (x-y)*(x-y) + (x-z)*(x-z) + (y-z)*(y-z));
    }
    return ret;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%u%u%u", &nr, &ng, &nb);
        r.resize(nr);
        g.resize(ng);
        b.resize(nb);
        for(unsigned int i = 0; i < nr; ++i)
            scanf("%lld", &r[i]);
        for(unsigned int i = 0; i < ng; ++i)
            scanf("%lld", &g[i]);
        for(unsigned int i = 0; i < nb; ++i)
            scanf("%lld", &b[i]);
        sort(r.begin(), r.end());
        sort(g.begin(), g.end());
        sort(b.begin(), b.end());
        ans = 0x3f3f3f3f3f3f3f3f;
        ans = min(ans, lb(r, g, b));
        ans = min(ans, lb(r, b, g));
        ans = min(ans, lb(g, r, b));
        ans = min(ans, lb(g, b, r));
        ans = min(ans, lb(b, r, g));
        ans = min(ans, lb(b, g, r));
        printf("%lld\n", ans);
    }
}
