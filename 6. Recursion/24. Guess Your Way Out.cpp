def solve(h,n,turn):
	if h==0:
		return 0
	if turn:
		tmp = 2**(h-1)
		if n>tmp:
			ans = 2**h - 1
			ans += solve(h-1,n-tmp,turn)
			return ans+1
		else:
			return solve(h-1,n,not(turn))+1
	else:
		tmp = 2**(h-1)
		if n<=tmp:
			ans = 2**h - 1
			ans += solve(h-1,n,turn)
			return ans+1
		else:
			return solve(h-1,n-tmp,not(turn))+1

t = int(input())

while t>0:
	s_input = input()
	s_input = s_input.split();
	h,n = int(s_input[0]),int(s_input[1])
	ans = solve(h,n,True)
	print(ans)
	t -= 1