A(m, n) := block(if (m = 0) then n + 1
		 else if (n = 0) then A(m - 1, 1)
		 else A(m - 1, A(m, n - 1)));