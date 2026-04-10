#include<bits/stdc++.h>
using namespace std;

// bits are 0 indexed
struct Bitset {
    vector<unsigned long long> arr;
    int n, words;
    static const unsigned long long AF = -1ULL;

    Bitset() : n(0), words(0) {}
    Bitset(int n) : n(n), words((n + 63) / 64), arr((n + 63) / 64, 0) {}

    // mask for the last (possibly partial) word
    unsigned long long tail_mask() const {
        return (n % 64 == 0) ? AF : (1ULL << (n % 64)) - 1;
    }
    void trim() { if (words) arr[words-1] &= tail_mask(); }

    void flip(int l, int r) {
        if (l / 64 == r / 64) {
            // same word
            unsigned long long mask = ((r % 64 == 63) ? AF : (1ULL << (r % 64 + 1)) - 1)
                                    ^ ((1ULL << (l % 64)) - 1);
            arr[l / 64] ^= mask;
            return;
        }
        arr[l/64] ^= AF ^ ((1ULL << (l % 64)) - 1);
        arr[r/64] ^= (r % 64 == 63) ? AF : (1ULL << (r % 64 + 1)) - 1;
        for (int x = l/64 + 1; x < r/64; x++) arr[x] ^= AF;
    }

    int get(int i) const {
        return (arr[i/64] >> (i % 64)) & 1;
    }

    void set(int i)   { arr[i/64] |=  (1ULL << (i % 64)); }
    void clear(int i) { arr[i/64] &= ~(1ULL << (i % 64)); }

    // next set bit >= i
    int get1(int i) const {
        unsigned long long mask = AF ^ ((1ULL << (i % 64)) - 1);
        int w = i / 64;
        unsigned long long temp = arr[w] & mask;
        if (temp) return w * 64 + __builtin_ctzll(temp);
        for (w++; w < words; w++)
            if (arr[w]) return w * 64 + __builtin_ctzll(arr[w]);
        return -1; // not found
    }

    // next zero bit >= i
    int get0(int i) const {
        unsigned long long mask = AF ^ ((1ULL << (i % 64)) - 1);
        int w = i / 64;
        unsigned long long temp = (arr[w] ^ AF) & mask;
        if (temp) return w * 64 + __builtin_ctzll(temp);
        for (w++; w < words; w++)
            if (arr[w] != AF) return w * 64 + __builtin_ctzll(arr[w] ^ AF);
        return -1;
    }

    void add(int i) { flip(i, get0(i)); }
    void sub(int i) { flip(i, get1(i)); }

    int gethigh() const {
        for (int i = words - 1; i >= 0; i--)
            if (arr[i]) return i * 64 + 63 - __builtin_clzll(arr[i]);
        return -1;
    }

    int count() const {
        int res = 0;
        for (auto w : arr) res += __builtin_popcountll(w);
        return res;
    }

    // --- bitwise ops ---

    Bitset operator|(const Bitset& o) const {
        Bitset res(n);
        for (int i = 0; i < words; i++) res.arr[i] = arr[i] | o.arr[i];
        return res;
    }
    Bitset& operator|=(const Bitset& o) {
        for (int i = 0; i < words; i++) arr[i] |= o.arr[i];
        return *this;
    }
    Bitset operator&(const Bitset& o) const {
        Bitset res(n);
        for (int i = 0; i < words; i++) res.arr[i] = arr[i] & o.arr[i];
        return res;
    }
    Bitset& operator&=(const Bitset& o) {
        for (int i = 0; i < words; i++) arr[i] &= o.arr[i];
        return *this;
    }
    Bitset operator^(const Bitset& o) const {
        Bitset res(n);
        for (int i = 0; i < words; i++) res.arr[i] = arr[i] ^ o.arr[i];
        return res;
    }
    Bitset& operator^=(const Bitset& o) {
        for (int i = 0; i < words; i++) arr[i] ^= o.arr[i];
        return *this;
    }

    // --- shifts ---

    Bitset operator>>=(int k) {
        if (k >= n) { fill(arr.begin(), arr.end(), 0); return *this; }
        int word_shift = k / 64, bit_shift = k % 64;
        if (bit_shift == 0) {
            for (int i = 0; i + word_shift < words; i++)
                arr[i] = arr[i + word_shift];
        } else {
            for (int i = 0; i + word_shift + 1 < words; i++)
                arr[i] = (arr[i + word_shift] >> bit_shift)
                        | (arr[i + word_shift + 1] << (64 - bit_shift));
            arr[words - word_shift - 1] = arr[words - 1] >> bit_shift;
        }
        fill(arr.end() - word_shift, arr.end(), 0);
        return *this;
    }

    Bitset operator<<=(int k) {
        if (k >= n) { fill(arr.begin(), arr.end(), 0); return *this; }
        int word_shift = k / 64, bit_shift = k % 64;
        if (bit_shift == 0) {
            for (int i = words - 1; i >= word_shift; i--)
                arr[i] = arr[i - word_shift];
        } else {
            for (int i = words - 1; i > word_shift; i--)
                arr[i] = (arr[i - word_shift] << bit_shift)
                        | (arr[i - word_shift - 1] >> (64 - bit_shift));
            arr[word_shift] = arr[0] << bit_shift;
        }
        fill(arr.begin(), arr.begin() + word_shift, 0);
        trim(); // truncate bits beyond n
        return *this;
    }

    Bitset operator>>(int k) const { Bitset res = *this; res >>= k; return res; }
    Bitset operator<<(int k) const { Bitset res = *this; res <<= k; return res; }
};