#!/usr/bin/python2.7

# translate from ints to strings
# pass --str2int flag to go from string to ints

import sys
import operator

if len(sys.argv) < 3:
    print 'Usage: ./prog <ids file> <image names file> [--str2int]'
    sys.exit(-1)

str2int = False
if (len(sys.argv) > 3 and sys.argv[3] == '--str2int'):
    str2int = True

f = open(sys.argv[1])
ids = map(str.strip, f.readlines())
if not str2int:
    ids = map(int, ids)
f.close();

f = open(sys.argv[2])
names = map(str.strip, f.readlines())
if str2int:
    names = dict(zip(names, range(len(names))))
f.close();

elts = operator.itemgetter(*ids)(names)
print '\n'.join(map(str, elts))
