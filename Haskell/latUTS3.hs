-- UTS 2015/2016

-- DEFINISI DAN SPESIFIKASI PRIMITIF LIST
-- KONSTRUKTOR
konso :: Int -> [Int] -> [Int]
konso e l = [e] ++ l
{- konso e li menghasilkan sebuah list of integer dari e dan li
dengan e sebagai elemen pertama -}
konsDot :: [Int] -> Int -> [Int]
konsDot l e = l ++ [e]
{- konsDot li e menghasilkan sebuah list of integer dari li dan e
dengan e sebagai elemen terakhir -}
-- SELEKTOR
-- head : [Int] -> Int
{- head l menghasilkan elemen pertama list l, l tidak kosong -}
-- tail : [Int] -> [Int]
{- tail l menghasilkan list tanpa elemen pertama list l, l tidak kosong -}
-- last : [Int] -> Int
{- last l menghasilkan elemen terakhir list l, l tidak kosong -}
-- init : [Int] -> [Int]
{- init l menghasilkan list tanpa elemen terakhir list l, l tidak kosong -}
-- PREDIKAT DASAR
isEmpty :: [Int] -> Bool
isEmpty l = null l
{- isEmpty l true jika list of elemen l kosong, false jika tidak -}
isOneElmt :: [Int] -> Bool
isOneElmt l = null (tail l)
{- isOneElmt l true jika list of integer l hanya mempunyai satu elemen, false jika tidak -}


-- Soal no 2 List 
-- DEFINISI DAN SPESIFIKASI 
nilaiEkstrim :: [Int] -> (Int,Int)
{- nilaiEkstrim l mengembalikan pasangan integer (min,max), dengan min adalah nilai terkecil pada
l dan max adalah nilai terbesar pada l.
Prekondisi: l tidak kosong
Contoh: nilaiEkstrim [3,2,6,5,8,0,1,2,12,56,44,3,28] = (0,56) -}
trunc :: [Int] -> Int -> [Int]
{- trunc l i mengembalikan i buah elemen terdepan dari l.
Apabila i lebih besar dari jumlah elemen pada l, maka fungsi mengirimkan l.
Prekondisi: i > 0
Contoh: trunc [3,2,6,5,8] 3 = [3,2,6] -}
splitList :: [Int] -> ([Int],[Int])
{- splitList l mengembalikan dua buah list lfront dan lback, dengan lfront memuat elemen l
bagian depan dan lback memuat elemen l bagian belakang.
Jumlah elemen pada lfront sama dengan atau 1 elemen lebih banyak dari pada lback.
Contoh: splitList [3,2,6,5,8] = ([3,2,6],[5,8]) -}
insSorted :: Int -> [Int] -> [Int]
{- insSorted x l menerima sebuah integer x dan sebuah list l yang terurut membesar serta
mengembalikan list l yang telah ditambahkan x sedemikian sehingga elemen-elemennya tetap
terurut membesar.
Contoh: insSorted 4 [2,3,5,6] = [2,3,4,5,6] -}
-- REALISASI 
nilaiEkstrim l 
	| isOneElmt l = ((head l),(head l))
	| otherwise = let (min,max) = nilaiEkstrim (tail l)
				  in 	if (head l) > max then (min, (head l)) else 
						if (head l) < min then ((head l), max) else 
						(min,max)
trunc l i 
	| isOneElmt l = l
	| i == 0 = []
	| otherwise = konso (head l) (trunc (tail l) (i-1))

splitList l
	| isEmpty l = ([],[]) -- basis 0
	| isOneElmt l = ([head l],[]) -- basis 1
	| otherwise = let (lfront,lback) = splitList (init(tail l))
				  in 	(konso (head l) lfront, konsDot lback (last l))

insSorted x l 
	| isEmpty l = [x]
	| x > head l = konso (head l) (insSorted x (tail l)) 
	| otherwise = konso x l 
	
-- soal 3 fungsi dengan parameter fungsi 
-- DEFINISI DAN SPESIFIKASI 
sumInteger :: Int -> Int -> (Int -> Bool) -> Int 
-- sumInteger m n f = jumlah2 integer m n yang memenuhi f
isGenap :: Int -> Bool 
gtThan5 :: Int -> Bool 
-- REALISASI
sumInteger m n f
	| m>n = 0
	| f m = m + sumInteger (m+1) n f 
	| otherwise = sumInteger (m+1) n f 
	
isGenap x = mod x 2 == 0 
gtThan5 x = x>5 



	