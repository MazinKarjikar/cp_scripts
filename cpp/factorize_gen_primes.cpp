#include<bits/stdc++.h>
using namespace std;

// SIEVE OF ERASTOTHENES

int PRIME_GEN_MAX = 2 * 1e5 + 10;
vector<bool> is_prime(PRIME_GEN_MAX + 1, true);
vector<int> primes;

int main() {

    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i <= PRIME_GEN_MAX; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= PRIME_GEN_MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
    // optional to get list of primes. needed for factorization. consider sqrt(max(array)) for factorization.
    for(int i = 2; i <= PRIME_GEN_MAX; i++) if (is_prime[i]) primes.push_back(i);

    // Vector of prime factors, O(10^4) if n <= 1e5
    auto vfactorize = [&](long long n) -> vector<long long> {
        vector<long long> factorization;
        for (long long d : primes) {
            if (d * d > n)
                break;
            while (n % d == 0) {
                factorization.push_back(d);
                n /= d;
            }
        }
        if (n > 1)
            factorization.push_back(n);
        return factorization;
    };

    // Frequency map of prime factors, O(10^4 lg 10^4)
    auto mfactorize = [&](long long n) -> map<long long, long long> {
        map<long long, long long> factorization;
        for (long long d : primes) {
            if (d * d > n)
                break;
            while (n % d == 0) {
                factorization[d]++;
                n /= d;
            }
        }
        if (n > 1)
            factorization[n]++;
        return factorization;
    };



}
