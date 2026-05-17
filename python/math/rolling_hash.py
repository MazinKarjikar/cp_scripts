
# initialize on a string or a list of integers. a[i] <= 1e9.
# init is O(n). query is O(1), and returns two hashes.
# two subarrays are the same if both the hashes are the same - both different or only 1 matching means they are not the same.
class PolyHash:
    def __init__(self, seq, m=10**9 + 9):
        a = [ord(c) - ord('a') + 1 for c in seq] if isinstance(seq, str) else [x + 1 for x in seq]
        p1, p2 = (31, 37) if isinstance(seq, str) else (100237, 199777)
        n = len(a)
        self.m = m
        self.pre1 = [0] * (n + 1)
        self.pre2 = [0] * (n + 1)
        self.pi1 = [1] * (n + 1)
        self.pi2 = [1] * (n + 1)
        pw1 = pw2 = 1
        inv1, inv2 = pow(p1, m - 2, m), pow(p2, m - 2, m)
        for i in range(n):
            self.pre1[i + 1] = (self.pre1[i] + a[i] * pw1) % m
            self.pre2[i + 1] = (self.pre2[i] + a[i] * pw2) % m
            pw1 = pw1 * p1 % m
            pw2 = pw2 * p2 % m
            self.pi1[i + 1] = self.pi1[i] * inv1 % m
            self.pi2[i + 1] = self.pi2[i] * inv2 % m

    def query(self, i, j):
        m = self.m
        return ((self.pre1[j+1] - self.pre1[i]) % m * self.pi1[i] % m,
                (self.pre2[j+1] - self.pre2[i]) % m * self.pi2[i] % m)