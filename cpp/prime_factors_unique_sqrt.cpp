#include<bits/stdc++.h>
using namespace std;


map<int,int> factorize(int number) {
    map<int, int> prime_factors;
    for(int i = 2; i * i <= number; i++) {
        while(number % i == 0) {
            prime_factors[i]++;
            number /= i;
        }
    }
    if (number > 1) prime_factors[number]++;
    return prime_factors;
};


// usage
int main() {

    vector<int> nums = {1, 2, 3, 4, 360};

    for(auto x: nums) {
        cout << x << ": ";
        map<int,int> prime_factors = factorize(x);
        for(auto [prime, count]: prime_factors) cout << prime << "," << count << " ";
        cout << endl;
    }

};