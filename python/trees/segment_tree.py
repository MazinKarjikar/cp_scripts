
# Pass in combine function and optionally a default value.
# Usage Sum: st = SegmentTree(arr, lambda a,b: a+b)
# Usage Max: st = SegmentTree(arr, max, -inf)
# Usage Min: st = SegmentTree(arr, min, inf)
class SegmentTree:
    def __init__(self, arr, combine, default = 0):
        n = len(arr)
        self.n = n
        self.default = default
        self.combine = combine
        self.t = [default] * n + arr
        for i in range(n - 1, 0, -1):
            self.t[i] = combine(self.t[2*i], self.t[2*i+1])

    def query(self, l, r) -> int:
        res = self.default
        l, r = l + self.n, r + self.n
        while l <= r:
            if l % 2 == 1:
                res = self.combine(res, self.t[l])
                l += 1
            if r % 2 == 0:
                res = self.combine(res, self.t[r])
                r -= 1
            l, r = l // 2, r // 2
        return res

    def update(self, i, val):
        i += self.n
        self.t[i] = val
        i //= 2
        while i >= 1:
            self.t[i] = self.combine(self.t[2*i], self.t[2*i+1])
            i //= 2