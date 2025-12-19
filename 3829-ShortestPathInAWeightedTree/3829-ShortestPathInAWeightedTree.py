# Last updated: 19/12/2025, 19:21:52
class BIT:
    def __init__(s, n):
        s.n = n + 2
        s.b = [0] * s.n

    def u(s, i, x):
        while i < s.n:
            s.b[i] += x
            i += i & -i

    def q(s, i):
        r = 0
        while i:
            r += s.b[i]
            i -= i & -i
        return r

    def ra(s, l, r, x):
        s.u(l, x)
        s.u(r + 1, -x)

class Solution(object):
    def treeQueries(s, n, edg, qry):
        g = defaultdict(list)
        for u, v, w in edg:
            g[u].append((v, w))
            g[v].append((u, w))

        tin = [0] * (n + 1)
        tout = [0] * (n + 1)
        d = [0] * (n + 1)
        p = [0] * (n + 1)
        ew = {}
        t = [1]

        def dfs(u, par):
            tin[u] = t[0]
            t[0] += 1
            for v, w in g[u]:
                if v != par:
                    p[v] = u
                    d[v] = d[u] + w
                    ew[(u, v)] = w
                    ew[(v, u)] = w
                    dfs(v, u)
            tout[u] = t[0] - 1

        dfs(1, 0)

        b = BIT(n)
        for i in range(1, n + 1):
            b.ra(tin[i], tin[i], d[i])

        res = []

        for q in qry:
            if q[0] == 1:
                _, u, v, nw = q
                if p[v] == u:
                    a, c = u, v
                else:
                    a, c = v, u
                ow = ew[(a, c)]
                delta = nw - ow
                ew[(a, c)] = nw
                ew[(c, a)] = nw
                b.ra(tin[c], tout[c], delta)
            else:
                _, x = q
                res.append(b.q(tin[x]))

        return res
