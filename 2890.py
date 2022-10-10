MOD = 1000007

n = int(input())

while n != 0:
	if n == 1:
		print(1)
	elif n == 2:
		print(2 + 1)
	elif n == 3:
		print(3 + 3 + 1)
	elif n == 4:
		print(4 + 6 + 4 + 1)
	elif n >= 5:
		ans = n
		atu = (n*(n-1)) % MOD
		ans = (ans + atu * 500004) % MOD
		atu = (atu * (n - 2)) % MOD
		ans = (ans + atu * 166668) % MOD
		atu = (atu * (n - 3)) % MOD
		ans = (ans + atu *  41667) % MOD

		print(ans)

	n = int(input())