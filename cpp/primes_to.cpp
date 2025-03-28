#include<bits/stdc++.h>
using namespace std;


int PRIME_GEN_MAX = 2 * 1e5 + 10;

vector<int> primes;
vector<bool> is_prime(PRIME_GEN_MAX + 1, true);

int main() {

// --------- Copy this into main----------

    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i <= PRIME_GEN_MAX; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= PRIME_GEN_MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
    // optional to get list of primes
    for(int i = 2; i <= PRIME_GEN_MAX; i++) if (is_prime[i]) primes.push_back(i);

// -------------- Done --------------------

    for(auto x: primes) cout << x << " ";

}