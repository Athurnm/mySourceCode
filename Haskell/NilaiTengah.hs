-- Athur Naufan M
module NilaiTengah where
-- Nilai Tengah 					nilaiTengah a b c
-- DEFINISI DAN SPESIFIKASI 
nilaiTengah :: Int -> Int -> Int -> Int
-- fungsi nilaiTengah a b c akan menghasilkan sebuah median dari 3 data yang diberikan
max3 :: Int -> Int -> Int -> Int
-- fungsi untuk mencari nilai max antar 3 bilangan
min3 :: Int -> Int -> Int -> Int 
-- fungsi untuk mencari nilai min antar 3 bilangan 

-- REALISASI
max3 a b c 
	| (a>=b) && (a>=c) = a
	| (b>=a) && (b>=c) = b
	| otherwise = c
	
min3 a b c
	| (a<=b) && (a<=c) = a
	| (b<=a) && (b<=c) = b
	| otherwise = c
	
nilaiTengah a b c = a + b + c - (max3 a b c) - (min3 a b c)

-- APLIKASI
-- nilaiTengah 1 2 3 = 2