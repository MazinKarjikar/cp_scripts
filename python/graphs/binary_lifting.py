# Used for when your graph has maximum 1 out degree, thus maximum 1 parent.
# Can be used to jump forward or backward, as long as there's one way to do it.

# Can be used in rho graphs (cycle with trees outwards)
p = [0, 0, 0, 1, 2, 0] # DONT COPY
n = len(p) # DONT COPY

# -------------BINARY LIFTING------------------
max_bit = 31
bl = [[-1] * max_bit for _ in range(n)]

for i in range(n):
    bl[i][0] = p[i]

for k in range(1, max_bit): # jump of 2^k is 2 jumps of 2^k-1
    for i in range(n):
        bl[i][k] = bl[bl[i][k - 1]][k - 1]
# -------------BINARY LIFTING------------------
