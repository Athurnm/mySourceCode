-- Athur Naufan M
module HitungFaktorDarix where 
-- program untuk menghitung jumlah faktor dari suatu bilangan 		hitungFaktor a b 
-- DEFINISI DAN SPESIFIKASI 
hitungFaktor :: Int -> Int -> Int 
-- REALISASI
hitungFaktor a b 
	| a == b = 1
	| a < b && mod b a == 0 = 1 + hitungFaktor (a+1) b
	| otherwise = hitungFaktor (a+1) b 