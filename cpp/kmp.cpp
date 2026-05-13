#include<bits/stdc++.h>
using namespace std;

// Computes the KMP failure/prefix function for sequence s.
// pi[i] = length of the longest suffix of s[0..i] that is also a proper prefix.
// Runs in O(n) time.
vector<int> kmp(auto& s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for(int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 and s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
