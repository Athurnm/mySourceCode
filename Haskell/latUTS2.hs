-- lat UTS 2015/2016

-- DEFINISI DAN SPESIFIKASI KONSTRUKTOR 
konso :: Int -> [Int] -> [Int]
-- konso(e,li) menghasilkan sebuah list dari e (sebuah
-- integer) dan li (list of integer),
-- dengan e sebagai elemen pertama: e o li -> li'
konso e li = [e] ++ li
-- DEFINISI DAN SPESIFIKASI SELEKTOR
-- head : [Int] -> Int
-- head(l) menghasilkan elemen pertama list l, l tidak kosong
-- tail : [Int] -> [Int]
-- tail(l) menghasilkan list tanpa elemen pertama list l,
-- l tidak kosong
-- DEFINISI DAN SPESIFIKASI PREDIKAT
isEmpty :: [Int] -> Bool
-- isEmpty(li) true jika list of integer li kosong
isEmpty li = null li
isOneElmt :: [Int] -> Bool
-- isOneElmt(li) true jika list of integer li hanya
-- mempunyai satu elemen
isOneElmt li = null (tail li)

-- soal 2 ekstrak Tanda
-- DEFINISI DAN SPESIFIKASI 
ekstrakTanda :: [Int] -> [Int]
-- fungsi ekstrakTanda li akan menghasilkan list dengan elemen yang bernilai
-- 1 untuk (+), -1 untuk (-), dan 0 untuk 0
-- REALISASI 
ekstrakTanda li 
	| isEmpty li = []
	| head li > 0 = konso 1 (ekstrakTanda (tail li))
	| head li == 0 = konso 0 (ekstrakTanda (tail li))
	| otherwise = konso (-1) (ekstrakTanda (tail li))

-- soal 3 pisah dua 
-- DEFINISI DAN SPESIFIKASI
pisahDua :: [Int] -> Int -> ([Int],[Int])
-- fungsi pisahDua li akan memecah list menjadi dua
-- l1 yang terdiri atas elemen-elemen li yang bernilai <= n
-- l2 berisi elemen-elemen li yang bernilai >= n
-- REALISASI 
pisahDua li
	| isEmpty li = ([],[])
	| head l1 <= n = ((konso (head li) (fst(pisahDua (tail li)))), (snd(pisahDua (tail li))))
	| otherwise = (fst(pisahDua (tail li)),(konso (head li) snd(pisahDua(tail li))))

-- soal 4 konversi suhu 
-- DEFINISI DAN SPESIFIKASI 
konversiSuhu :: Float -> (Float->Float) -> Float 
{- KonversiSuhu(t,f) dengan T merepresentasikan suhu dalam
derajat tertentu dan fungsi f yang merupakan fungsi konversi
suhu, menghasilkan konversi t ke suhu pada derajat
tertentu berdasarkan fungsi f. -}
konversiCtoK :: Float -> Float 
-- fungsi konversiCtoK t akan mengonversi t yang sebelumnya dalam celsius menjadi kelvin
konversiRtoC :: Float -> Float 
-- fungsi konversiRtoC t akan mengonversi t yang sebelumnya dalam Reamur ke Celsius 
-- REALISASI 
konversiSuhu t f = f t 
konversiCtoK x = x + 273.0
konversiRtoC x = 5/4 * x
-- APLIKASI 
-- konversiSuhu 100.0 konversiCtoK 
-- 373.0
-- konversiSuhu 100.0 konversiRtoC
-- 125.0

-- soal 5 deletelf
-- DEFINISI DAN SPESIFIKASI 
deletelf :: [Int] -> (Int->Bool) -> [Int]
-- fungsi deleteIf yang menerima masukan sebuah
-- list of integer, misalnya L, dan sebuah kondisi,
-- misalnya f, dan menghasilkan sebuah list of
-- integer baru yang merupakan L yang telah
-- dihapus elemen-elemennya yang memenuhi
-- kondisi f. Gunakan definisi type list of integer
-- pada soal 2
isLebih5 :: Int -> Bool 
-- IsLebih5(x) true jika x > 5
isBetween :: Int -> Bool
-- isBetween(x) true jika 0 <= x <= 100
isEqual10 :: Int -> Bool
-- isEqual10(x) true jika x = 10
-- REALISASI 
deletelf li f 
		| isEmpty li = []
		| f (head li) = deletelf (tail li) f 
		| otherwise = konso (head li) (deletelf (tail li) f)
		
isLebih5 x = x>5
isBetween x = x >= 0 && x <= 100
isEqual10 x = x == 10


