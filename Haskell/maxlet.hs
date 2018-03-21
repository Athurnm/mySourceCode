max3 :: Integral f => f -> f -> f -> f
max3 a b c
	= let m = case () of 
		| a>b = a
		| a<b = b
	in case () of 
		| m>c = m
		| m<c = m