gcdl :: Integral f => f -> f -> f
input :: Int -> Int -> Int
input a b
	| a >= b = gcdl a b
	| otherwise = gcdl b a
gcdl a b
	| a == b = a
	| otherwise = gcdl b (a-b)