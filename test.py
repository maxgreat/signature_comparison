import example
import time
from numba import jit

@jit(nopython=True)
def numba_countSetBits(n): 
    count = 0
    while (n): 
        count += n & 1
        n >>= 1
    return count 


def countSetBits(n): 
    count = 0
    while (n): 
        count += n & 1
        n >>= 1
    return count 


def test_func(func, n_max=10000):
    t = time.time()
    for i in range(1000000):
        func(i)
    print(f"{func.__name__} time : {time.time()-t} sec")


def test_pairs(func, nb_pairs=1000000*2):
    pairs = [(i, i) for i in range(nb_pairs)]
    t = time.time()
    for a,b in pairs:
        func(a,b)
    print(f"{func.__name__} time : {time.time()-t} sec")


@jit(nopython=True)
def signature_comparison(s1, s2):
    numba_countSetBits(s1 ^ s2)


test_func(countSetBits)
test_func(numba_countSetBits)
test_func(example.rec_countSetBits)
test_func(example.countSetBits)
test_func(example.std_popcount)
test_func(example.bld_popcount)
test_pairs(signature_comparison)
test_pairs(example.signature_comparison)


