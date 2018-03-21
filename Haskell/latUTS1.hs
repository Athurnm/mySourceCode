-- UTS 2014/2015

-- soal 1.a. Ubah arah 
-- DEFINISI DAN SPESIFIKASI 
ubahArah :: Int -> Int -> Int 
-- fungsi ubahArah s r akan menghitung total perubahan arah dalam derajat 
-- dengan syarat derajat terbesar adalah 360 
-- prekon : -359<=r<=359 ; 0 <= s <= 359
-- REALISASI 
ubahArah s r 
	| (s+r) >= 0 && (s+r) < 360 = s+r
	| (s+r) < 0 = 360 + (s+r)
	| otherwise = (s+r)-360 
-- APLIKASI 
-- ubahArah 0 (-100) 
-- 260
-- ubahArah 10 20 
-- 30 

-- soal 1.b. Pangkat
-- DEFINISI DAN SPESIFIKASI
pangkat :: Int -> Int -> Int 
-- fungsi pangkat a b akan menghasilkan nilai a^b 
-- prekon : a > 0 dan b>= 0 
-- REALISASI 
pangkat a b = a^b
-- APLIKASI 
-- pangkat 1 1000 
-- 1 
-- pangkat 2 5 
-- 32

-- soal 2 List 
-- DEFINISI DAN SPESIFIKASI LIST 
-- KONSTRUKTOR
konso :: Int -> [Int] -> [Int]
{- konso e li menghasilkan sebuah list of integer dari e dan li dengan e sebagai elemen pertama -}
konsDot :: [Int] -> Int -> [Int]
{- konsDot li e menghasilkan sebuah list of integer dari li dan e dengan e sebagai elemen terakhir -}
-- SELEKTOR
-- head : [Int] -> Int
{- head l menghasilkan elemen pertama list l, l tidak kosong -}
-- tail : [Int] -> [Int]
{- tail l menghasilkan list tanpa elemen pertama list l, l tidak kosong -}
-- last : [Int] -> Int
{- last l menghasilkan elemen terakhir list l, l tidak kosong -}
-- init : [Int] -> [Int]
{- init l menghasilkan list tanpa elemen terakhir list l, l tidak kosong -}
-- PREDIKAT
isEmpty :: [Int] -> Bool
{- isEmpty l true jika list of elemen l kosong, false jika tidak -}
isOneElmt :: [Int] -> Bool
{- isOneElmt l true jika list of integer l hanya mempunyai satu elemen, false jika tidak -}
isAllGanjil :: [Int] -> Bool 
{- isAllGanjil l mengembalikan true apabila seluruh elemen l adalah bilangan ganjil.
Fungsi mengembalikan true jika l adalah list kosong -}
getSmallest :: [Int] -> Int
{- getSmallest l mengembalikan elemen terkecil di l. Prekondisi: l tidak kosong. -}
delElement :: Int -> [Int] -> [Int]
{- delElement x l mengembalikan list l dengan elemen x yang telah dihapus dari l.
Jika x bukan elemen l, maka fungsi mengembalikan l semula.
Prekondisi: elemen l unik (setiap elemen hanya muncul 1 kali). -}
sortList :: [Int] -> [Int]
{- sortList l mengembalikan hasil pengurutan list l hingga elemen-elemennya terurut membesar.
Prekondisi: l tidak kosong dan semua elemennya unik. -}
-- REALISASI 
konso e li = [e] ++ li 
konsDot li e = li ++ [e]
isEmpty li = null li 
isOneElmt li = null (tail li)
isAllGanjil li 
	| isEmpty li = True -- basis 0 
	| mod (head li) 2 == 1 = isAllGanjil (tail li) -- rekurens
	| otherwise = False  -- basis 
getSmallest li 
	| isOneElmt li = head li -- basis 1
	| head li <= head (tail li) = getSmallest (konso (head li) (tail (tail li))) 
	| otherwise = getSmallest (tail li)
delElement x li 
	| isEmpty li = []
	| isOneElmt li && x /= (head li) = [head li]
	| x == (head li) = delElement x (tail li)
	| otherwise = konso (head li) (delElement x (tail li))
sortList li 
	| isOneElmt li = [head li]
	| otherwise = konso (getSmallest li) (sortList (delElement (getSmallest li) li))
	
-- soal 3 fungsi dengan parameter fungsi 
-- DEFINISI DAN SPESIFIKASI
id1 :: Float -> Float 
-- id x mengirimkan nilai x
p1 :: Float -> Float
-- p1 x mengirimkan nilai x + 1
p2 :: Float -> Float
-- p2 x mengirimkan nilai x + 2
offsetList :: (Float -> Float) -> (Float -> Float) -> Float -> Float -> [Float]
-- fungsi offsetList f g a b akan menghasilkan list hasil pengolahan f a dg g increment
-- dan b batas 
-- REALISASI 
offsetList f g a b 
	| a > b = []
	| otherwise =  [(f a)] ++ (offsetList f g (g a) b)
id1 x = x 
p1 x = x+1
p2 x = x+2 
-- APLIKASI
-- offsetList (\x -> x) (\x -> x+2) 1.2 7.1
-- [1.2,3.2,5.2]
-- offsetList (\x -> if x < 0 then -999.0 else x+3.2) (\x -> x+3.2) (-1.0) 1.0
-- [-999.0]
-- offsetList (\x -> x*x) (\x -> x+1) 0.0 81.0
-- [0.0, 1.0, 4.0, 9.0, 16.0, 25.0, 36.0, 49.0, 64.0,81.0]