def primes_to(n):
    sieve = [True] * (n//2)
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i//2]:
            sieve[i*i//2::i] = [False] * ((n-i*i-1)//(2*i)+1)
    return ([2] if n >= 2 else []) + [2*i+1 for i in range(1,n//2) if sieve[i]]

if __name__ == "__main__":
    print(primes_to(100))
    print(primes_to(1))
    print(primes_to(2))