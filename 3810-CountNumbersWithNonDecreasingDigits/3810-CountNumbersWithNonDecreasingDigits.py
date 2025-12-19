# Last updated: 19/12/2025, 19:22:01
class Solution(object):
    def countNumbers(self, l, r, b):
        MOD = 10**9 + 7

        def to_base(a, b):
            if a == 0:
                return [0]
            c = []
            while a > 0:
                c.append(a % b)
                a = a // b
            return c[::-1]

        def ccnd(f):
            d = to_base(f, b)
            e = {}

            def dp(i, th, g):
                if i == len(d):
                    return 1
                k = (i, th, g)
                if k in e:
                    return e[k]
                l = d[i] if th else b - 1
                ab = 0
                for h in range(g, l + 1):
                    th_new = th and (h == l)
                    ab += dp(i + 1, th_new, h)
                e[k] = ab
                return ab

            return dp(0, True, 0)

        a_num = int(l)
        b_num = int(r)
        cy = ccnd(b_num) - ccnd(a_num - 1)
        return cy % MOD
