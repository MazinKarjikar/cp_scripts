# Pass in combine function and optionally a default value.
# Usage Sum: st = SparseTable(arr, lambda a,b: a+b)
# Usage XOR: st = SparseTable(arr, lambda a,b: a^b)
# Usage Min: st = SparseTable(arr, min, inf)
class SparseTable:
    def __init__(self, arr, combine, default = 0):
        self.default = default
        self.combine = combine
        self.t = [arr[:]]
        step = 1
        while step < len(arr):
            prev = self.t[-1]
            row = []
            for i in range(len(prev) - step):
                row.append(combine(prev[i], prev[i + step]))
            self.t.append(row)
            step *= 2

    # O(1) for idempotent combine, else O(log n)
    def query(self, l, r, idempotent=False):
        if idempotent:
            j = (r - l + 1).bit_length() - 1
            return self.combine(self.t[j][l], self.t[j][r - (1 << j) + 1])
        res = self.default
        length = r - l + 1
        while length > 0:
            j = length.bit_length() - 1
            res = self.combine(res, self.t[j][l])
            l += 1 << j
            length -= 1 << j
        return res
