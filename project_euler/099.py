import sys
import math

print(max(((i, list(map(int, line.split(',')))) for i, line in enumerate(sys.stdin.readlines())), key=lambda x: x[1][1] * math.log(x[1][0])))