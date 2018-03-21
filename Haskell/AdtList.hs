-- Athur 
-- program lat 1 
-- definisi dan spesifikasi 
countEven :: Int -> Bool
-- fungsi untuk menghitung banyaknya list yang genap
-- REALISASI
countEven x = mod x 2 == 0		
count0 :: Int -> Bool
count0 x = x == 0 
		 
countMultOf5 :: Int -> Bool
countMultOf5 x = mod x 5 == 0  
	 
countCond :: Int -> Bool 
countCond x
	| mod (x) 2 == 1 && mod (x) 3 == 0 && mod (x) 5 /= 0 = True
	| mod (x) 2 == 0 && (x) < 100 && (x) > 51  = True
	| x == 0 = True
	| otherwise = False
	
countAll :: [Int] -> (Int -> Bool) -> Int
countAll l f
	| null l = 0 -- basis 0
	| f (head l) = 1 + countAll (tail l) f
	| otherwise = countAll (tail l) f