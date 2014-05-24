#!/usr/bin/python2.7

import sys
import random

if len(sys.argv) < 4:
    print 'usage: ./prog <N> <K> <output_fpath>'
    sys.exit(-1)

N = int(sys.argv[1])
K = int(sys.argv[2])

f = open(sys.argv[3], 'w')
f.write('\n'.join(map(str, random.sample(range(N), K))));
f.close()
