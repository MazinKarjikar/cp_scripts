#include<bits/stdc++.h>
using namespace std;

// Factors in sqrt(n) time
vector<int> factors_sqrt(int n) {
    vector<int> factors1;
    vector<int> factors2;
    for(int i = 1; i <= (int) sqrt(n); i++) {
        if (n % i == 0) {
            factors1.push_back(i);
            if (n / i != i) factors2.push_back(n / i);
        }
    }
    reverse(factors2.begin(), factors2.end());
    vector<int> factors;
    for(auto x: factors1) factors.push_back(x);
    for(auto x: factors2) factors.push_back(x);
    return factors;
};

// Vector of prime factors in sqrt(n) time
vector<int> vfactorize(int n) {
    vector<int> prime_factors;
    for(int i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            prime_factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) prime_factors.push_back(n);
    return prime_factors;
};

// Frequency map of prime factors in sqrt(n) time
map<int,int> mfactorize(int n) {
    map<int, int> prime_factors;
    for(int i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            prime_factors[i]++;
            n /= i;
        }
    }
    if (n > 1) prime_factors[n]++;
    return prime_factors;
};


// usage
int main() {

    vector<int> nums = {1, 2, 3, 4, 360};

    for(auto x: nums) {
        cout << x << ": ";
        vector<int> prime_factors = vfactorize(x);
        for(auto f: prime_factors) cout << f << " ";
        cout << endl;
    }

};