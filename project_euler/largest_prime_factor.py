N = 600851475143

largestPrimeFactor = 0

p = 2
while p * p <= N:
	if N % p == 0:
		largestPrimeFactor = p
		
		while N % p == 0:
			N = N // p

	p += 1

if N != 1:
	largestPrimeFactor = N
	
print(largestPrimeFactor)