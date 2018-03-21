selfGCD :: Integral f => f -> f -> f
selfLCM :: Int -> Int -> Int
selfGCD a b
	| b == 0 = a
	| otherwise = selfGCD b (mod a b)
selfLCM a b = div (a*b) (selfGCD a b)