#include<bits/stdc++.h>
using namespace std;


vector<int> prime_factors_sqrt(int number) {
    vector<int> prime_factors;
    for(int i = 2; i * i <= number; i++) {
        while(number % i == 0) {
            prime_factors.push_back(i);
            number /= i;
        }
    }
    if (number > 1) prime_factors.push_back(number);
    return prime_factors;
};


// usage
int main() {

    vector<int> nums = {1, 2, 3, 4, 360};

    for(auto x: nums) {
        cout << x << ": ";
        vector<int> prime_factors = prime_factors_sqrt(x);
        for(auto f: prime_factors) cout << f << " ";
        cout << endl;
    }

};