n = int(input())

edges = []
vist = (n+1)*[False]

for i in range(n-1):
	u, v, c = map(int, input().split())
	edges.append([min(u, v), max(u, v), c])

ans = (n+1)*[10**9 + 10]

for u, v, c in edges:



print(ans[1], end = '')
for i in range(2,n):
	print(" %d" %ans[i], end = '')
print()