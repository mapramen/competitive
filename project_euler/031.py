import functools

coins = [1, 2, 5, 10, 20, 50, 100, 200]

@functools.cache
def coin_sums(n, max_coin = max(coins)):
	if n < 0:
		return 0
	
	if n == 0:
		return 1
	
	return sum(coin_sums(n - i, i) for i in coins if i <= n and i <= max_coin)

print(coin_sums(200))