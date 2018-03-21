-- Athur 
-- fungsi offset list 
-- DEFINISI DAN SPESIFIKASI 
offsetList :: [Int] -> (Int -> Int)-> [Int]
konso :: Int -> [Int] -> [Int]
isOneElmt :: [Int] -> Bool 
plus2 :: Int -> Int
minus1 :: Int -> Int 
offKond :: Int -> Int 

-- Realisasi 
konso e l = [e] ++ l 
isOneElmt l = (null (tail l))
offsetList l f 
	| isOneElmt l = [f(head l)]
	| otherwise = konso (f(head l)) (offsetList (tail l) f)
	
plus2 a = a+2
minus1 a = a-1
offKond a 
	| a>= 0 && a <= 40 = 10 
	| a>=41 && a<=60 = 5
	| a>=61 && a<=89 = 3
	| a>89 = 1
	| otherwise = 0
