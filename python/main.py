#!/usr/bin/env python3

# hello world
print('Hello from python!')

# loop, condition and arithmetic
for i in range(3):
 a=i**2.
 if i==1:
  print('i is 1')
  a *= 2.
 else:
  print('i is not 1')
  a += 0.5
 print('It=%i, a=%.6f' %(i,a))


# file io
import numpy as np
theFile='../input.dat' # assign a string
dat=np.loadtxt(theFile)

avg=np.mean(dat)
print('avg of '+theFile+' is %.8f' %avg)

# write the value with crazy precision to disk again
with open('out.dat', 'w') as fid:
 fid.write('%.40f\n' %dat[3,1])

