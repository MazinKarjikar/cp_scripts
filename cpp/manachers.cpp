#include<bits/stdc++.h>
using namespace std;

// p[0][i] = radius of palindrome centered at s[i], excluding s[i]
// p[1][i] = radius of palindrome centered at space between s[i], s[i-1]
vector<vector<int>> manachers(string s) {
    int n = s.size();
    vector<vector<int>> p(2,vector<int>(n,0));
    for(int z=0,l=0,r=0;z<2;z++,l=0,r=0) {
        for(int i=0;i<n;i++) {
            if(i<r) p[z][i]=min(r-i+!z,p[z][l+r-i+!z]);
            while(i-p[z][i]-1>=0 && i+p[z][i]+1-!z<n && s[i-p[z][i]-1]==s[i+p[z][i]+1-!z]) p[z][i]++;
            if(i+p[z][i]-!z>r) l=i-p[z][i],r=i+p[z][i]-!z;
        }
    }
    return p;
}

// inclusive [l, r]
bool isPalindrome(vector<vector<int>>& p, int l, int r) {
    bool odd = (r - l + 1) % 2;
    if (odd and p[1][(r+l)/2] >= (r-l+1)/2) return true;
    if (not odd and p[0][(r+l)/2+1] >= (r-l+1)/2) return true;
    return false;
}