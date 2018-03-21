-- Athur Naufan Muharam 
module CountKabisat where 
-- program menghitung jumlah tahun kabisat pada range tertentu 				hitungKabisat a b
-- DEFINISI DAN SPESIFIKASI 
isKabisat :: Int -> Bool
{- fungsi untuk mencari tahu apakah suatu tahun kabisat atau tidak -}
hitungKabisat :: Int -> Int -> Int 
{- fungsi untuk menghitung jumlah tahun kabisat pada range tahun a b -}

-- REALISASI
isKabisat a 
	| mod a 4 == 0 && mod a 100 /= 0 || mod a 400 == 0 = True 
	| otherwise = False
	
hitungKabisat a b 
	| a >= b && not(isKabisat b)= 0
	| b>=a && isKabisat b = 1 + hitungKabisat a (b-1)  
	| otherwise = hitungKabisat a (b-1)