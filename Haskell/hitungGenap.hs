-- Athur Naufan Muharam	
module CountEven where 
-- program menghitung jumlah bilangan genap antar range tertentu   			hitungGenap a b
-- DEFINISI DAN SPESIFIKASI 
hitungGenap :: Int -> Int -> Int 
-- fungsi untuk menghitung jumlah bilangan genap dalam range tertentu
-- REALISASI
hitungGenap a b
	| a >= b = 0
	| a < b && mod (b-1) 2 == 0 = 1 + hitungGenap a (b-1)
	| otherwise = hitungGenap a (b-1)