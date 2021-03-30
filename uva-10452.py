#	Author	: debugster
#	Email	: alive.dew@gmail.com
#	Date	: 2020-05-27 16:31:06

import sys
import os

if os.environ.get("DEBUGSTER_PYTHON"):
	sys.stdin = open('in.txt', 'r')
	sys.stdout = open('out.txt','w')

t = int(input())
for _ in range(t):
	m, n = map(int, input().split())
	#m = int(m)
	#n = int(n)

	w = []
	for __ in range(m):
		w.append(input())

	sx = m - 1
	sy = -1
	for i in range(n):
		if w[sx][i] == '@':
			sy = i
			break

	# @IEHOVA#
	target = {
		'@' : 'I',
		'I' : 'E',
		'E' : 'H',
		'H' : 'O',
		'O' : 'V',
		'V' : 'A',
		'A' : '#'
	}

	ans = []
	while True:
		if w[sx][sy] == '#':
			break

		# forth
		tx = sx - 1
		ty = sy
		if w[tx][ty] == target[w[sx][sy]]:
			sx, sy = tx, ty
			ans.append('forth')
			continue

		# right
		tx = sx
		ty = sy + 1
		if w[tx][ty] == target[w[sx][sy]]:
			sx, sy = tx, ty
			ans.append('right')
			continue

		# left
		tx = sx
		ty = sy - 1
		if w[tx][ty] == target[w[sx][sy]]:
			sx, sy = tx, ty
			ans.append('left')
			continue

	for i in range(len(ans) - 1):
		print(ans[i], end = ' ')
	print(ans[-1])