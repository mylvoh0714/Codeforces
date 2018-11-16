import math
t = int(input())
while t > 0:
t -= 1
d = int(input())
if d*d - 4 * d < 0 :
	print("N")
else :
	a = ( d + math.sqrt(d*d - 4 * d) ) / 2
	b = ( d - math.sqrt(d*d - 4 * d) ) / 2
	print("Y", end = ' ')
	print(a, b)