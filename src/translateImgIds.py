#!/usr/bin/python2.7

import sys
import operator

if len(sys.argv) < 3:
    print 'Usage: ./prog <ids file> <image names file>'
    sys.exit(-1)

f = open(sys.argv[1])
ids = map(int, f.readlines())
f.close();

f = open(sys.argv[2])
names = map(str.strip, f.readlines())
f.close();

elts = operator.itemgetter(*ids)(names)
print '\n'.join(elts)
