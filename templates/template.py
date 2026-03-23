import sys
from itertools import *
from collections import *
from heapq import *
from bisect import *

input = lambda: sys.stdin.readline().strip()
rint = lambda: int(input())
rdigits = lambda: list(map(int, input()))
rlist = lambda: list(map(int, input().split()))
rgrid = lambda n: [list(map(int, input().split())) for _ in range(n)]
fmin = lambda x, y: x if x < y else y
fmax = lambda x, y: x if x > y else y
inf, ninf = float("inf"), float("-inf")

MOD = 10**9 + 7
MOD = 998244353


def solve():
    N = rint()

# TT = 1
TT = rint()
for _tt in range(TT):
    ans = solve()
    print(ans)

    # print(len(ans))
    # print(*ans)
    # print("\n".join(map(str, ans)))
    # for row in ans:
    #     print(*row)
    # print("Yes" if ans else "No")
    # print("Alice" if ans else "Bob")
