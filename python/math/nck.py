MOD = 10**9 + 7
MAXN = int(1e6 + 10)

fact = [1]
invfact = [1]
for v in range(1, MAXN):
    fact.append(fact[-1] * v % MOD)
    invfact.append(pow(fact[-1], MOD - 2, MOD))

def choose(n, x):
    return fact[n] * invfact[x] % MOD * invfact[n - x] % MOD

if __name__ == "__main__":
    print(choose(5,2))
    print(choose(7,3))
