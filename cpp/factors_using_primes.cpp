#include<bits/stdc++.h>
using namespace std;


int main() {

//----------- Assume you have computed primes (perhaps using Sieve until sqrt(n) or sqrt(a[i]) )-----------------
    vector<int> primes;
    auto factorize = [&](long long n) {
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

// -------------- Done ------------------------------------------------


}