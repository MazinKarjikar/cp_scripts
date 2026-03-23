MAXN = 50001
spf = list(range(MAXN))  # spf[i] = i initially

for i in range(2, int(MAXN**0.5) + 1):
    if spf[i] == i:  # i is prime
        for j in range(i*i, MAXN, i):
            if spf[j] == j:
                spf[j] = i

def factor(n):
    factors = {}
    while n > 1:
        p = spf[n]
        while n % p == 0:
            factors[p] = factors.get(p, 0) + 1
            n //= p
    return factors

def divisors_from_factors(n):
    f = factor(n)
    divs = [1]
    for p, e in f.items():
        divs = [d * p**i for d in divs for i in range(e + 1)]
    return sorted(divs)

def divisors(n):
    divs = []
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            divs.append(i)
            if i != n // i:
                divs.append(n // i)
    return sorted(divs)

# prime factorization sqrt(n) TC
def prime_factorize(n):
    d, f = 2, {}
    while d * d <= n:
        while n % d == 0:
            f[d] = f.get(d, 0) + 1
            n //= d
        d += 1
    if n > 1:
        f[n] = f.get(n, 0) + 1
    return f

if __name__ == "__main__":
    print(factor(897612484786617600))