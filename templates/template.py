from sys import stdin, stdout

def I(): return stdin.readline().strip(" \r\n")
def II(): return int(I()) # input int
def IL(): return I().split() # input is already a list, take it in and split
def ICL(): return list(I()) # input char list
def IIL(): return list(map(int, IL())) # input int list
def IM(): return map(str, IL())
def IIM(): return map(int, IL())
def ICIM(): return map(int, ICL())
def ICIL(): return list(map(int, ICL()))
def P(*args,sep=' ',end=''): stdout.write(sep.join([str(s) for s in args]) + end)
def PL(*args,sep=' '): P(*args, sep=sep, end='\n')
def F(): stdout.flush()
def YES(): PL("YES")
def NO(): PL("NO")

def main():
    for _ in range(II()):
        solve()

def solve():
    n = II()


if __name__ == "__main__":
    main()