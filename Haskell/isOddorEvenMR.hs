-- Athur Naufan Muharam
module IsOddorIsEven where

-- Mencari tahu apakah nilai bilangan ganjil atau genap 	isOddorEven n
-- Definisi dan Spesifikasi
isOdd :: Int -> Bool
-- mencari tahu apakah nilai ganjil?
isEven :: Int -> Bool
-- mencari tahu apakah nilai genap?
-- Asumsi n >= 0

-- Realisasi
isOdd n 
	| n == 0 = False
	| otherwise = isEven (n-1)
	
isEven n 
	| n == 0 = True
	| otherwise = isOdd (n-1)
	
-- Aplikasi
-- isOdd 3
-- True