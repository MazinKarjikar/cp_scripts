#include<bits/stdc++.h>
using namespace std;


vector<int> factors_sqrt(int number) {
    vector<int> factors1;
    vector<int> factors2;
    for(int i = 1; i <= (int) sqrt(number); i++) {
        if (number % i == 0) {
            factors1.push_back(i);
            if (number / i != i) factors2.push_back(number / i);
        }
    }
    reverse(factors2.begin(), factors2.end());
    vector<int> factors;
    for(auto x: factors1) factors.push_back(x);
    for(auto x: factors2) factors.push_back(x);
    return factors;
};


// usage
int main() {

    vector<int> nums = {1, 2, 3, 4, 360};

    for(auto x: nums) {
        cout << x << ": ";
        vector<int> factors = factors_sqrt(x);
        for(auto f: factors) cout << f << " ";
        cout << endl;
    }

};