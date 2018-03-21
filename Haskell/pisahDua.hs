--Athur Naufan M
module PisahDua where 
-- fungsi untuk memisahkan list menjadi dua list 
-- DEFINISI DAN SPESIFIKASI 		pisahDua L n 
pisahDua :: [Int] -> Int -> ([Int],[Int])

listBesar :: [Int] -> Int -> [Int]
listKecil :: [Int] -> Int -> [Int]

-- REALISASI
listBesar l n
	| null l = [] --basis 0
	| head l > n = [head l] ++  listBesar (tail l) n -- rekurens
	| otherwise = listBesar (tail l) n -- rekurens

listKecil l n 
	| null l = [] --basis 0
	| head l <= n = [head l] ++  listKecil (tail l) n -- rekurens
	| otherwise = listKecil (tail l) n -- rekurens
	
pisahDua l n = ((listKecil l n),(listBesar l n))