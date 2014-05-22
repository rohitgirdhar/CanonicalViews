#!/usr/bin/python2.7

import sys
import os

if len(sys.argv) < 4:
    print 'Usage: ./prog <dir> <files list> <output file>'
    sys.exit(-1)

def file_len(fname):
    try:
        with open(fname) as f:
            for i, l in enumerate(f):
                pass
        return i + 1
    except:
        return 0

dpath = sys.argv[1]
fpath = sys.argv[2]
opfile = sys.argv[3]

f = open(fpath)
files = f.readlines()
N = len(files)
f.close()

mat = [[0 for col in range(N)] for row in range(N)]
i = 0
for f1 in files:
    j = 0
    for f2 in files:
        matches_path = os.path.join(dpath.strip(), f1.strip(), 'matches_' + f2.strip() + '.txt')
        if os.path.exists(matches_path):
            mat[i][j] = file_len(matches_path)
        j += 1
    i += 1
    print i

f = open(opfile, 'w')
for row in mat:
    print >>f, ' '.join(map(str, row))
f.close()
