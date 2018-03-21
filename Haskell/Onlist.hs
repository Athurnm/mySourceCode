--Athur Naufan M
module Onlist where 
-- predikat dasar pada haskell
-- Definisi dan Spesifikasi
isEmpty :: [Int] -> Bool
-- fungsi isEmpty L akan bernilai true jika list kosong
-- REALISASI
isEmpty l = null l 

isOneElmt :: [Int] -> Bool
-- fungsi isOneElmt akan menghasilkan ture jika list hanya memiliki satu anggota
-- Realisasi
isOneElmt l = length l == 1 

-- Definisi dan Spesifikasi Konstruktor 
konso :: Int -> [Int] -> [Int]
{- Konso e l akan menghasilkan sebuah list baru dg e sbg elemen pertama -}
-- Realiasi
konso e l = [e] ++ l

konsDot :: [Int] -> Int -> [Int]
{- konsDot akan menghasilkan sebuah list baru dg e sbg last element -}
-- Realisasi
konsDot l e = l ++ [e]

-- fungsi nbElmt untuk menghitung banyaknya elemen
-- Definisi dan spesifikasi 
nbElmt :: [Int] -> Int 
-- fungsi nbElmt l akan menghasilkan jumlah elemen pada list
-- Realisasi
nbElmt l 
	| isEmpty l = 0
	| otherwise = 1 + nbElmt (tail l)
	
-- fungsi untuk mengecek keanggotaan elemen
-- Definisi dan Spesifikasi
isMember :: Int -> [Int] -> Bool
-- fungsi isMember x L akan mengecek apakah x anggota dari l
-- Realisasi
isMember x l 
	| isEmpty l = False
	| head l == x = True
	| otherwise = isMember x (tail l)
	
-- fungsi untuk mengcopy list copy l 
-- definisi dan spesifikasi 
copy :: [Int] -> [Int]
-- fungsi untuk mengcopy list lama pada list baru 
-- Realisasi 
copy l
	| isEmpty l = []
	| otherwise = konso (head l) (copy(tail l))
	
-- fungsi untuk menginverse suatu list 
-- Definisi dan Spesifikasi 
inverse :: [Int] -> [Int]
-- fungsi inverse l akan menghasilkan list yang beterbalikan
inverse l 
	| isEmpty l = []
	| otherwise = konsDot (inverse (tail l)) (head l)
	
-- fungsi untuk mengecek apakah 2 list sama 
-- Definisi dan Spesifikasi 
isEq :: [Int] -> [Int] -> Bool
-- fungsi isEq akan menghasilkan true jika kedua list sama
cekEq :: [Int] -> [Int] -> Bool
isEq l1 l2 
	| nbElmt l1 /= nbElmt l2 = False
	| otherwise = cekEq l1 l2 

cekEq l1 l2 
	| isEmpty l1 && isEmpty l2 = True 
	| head l1 == head l2 = cekEq (tail l1) (tail l2)
	| otherwise = False
	
-- Fungsi untuk mencari elemen ke-n dari suatu list 
-- Definisi dan Spesifikasi 
elmtKeN :: Int -> [Int] -> Int 
-- fungsi elmtKeN akan menghasilkan nilai dari elemen ke N pd list 
-- Prekon: N > 0 list tidak kosong serta N <= banyaknya elemen pd list 
-- Realisasi
elmtKeN n l 
	| isOneElmt l = head l -- basis
	| n == 1 = head l -- basis
	| otherwise = elmtKeN (n-1) (tail l) --rekurens
	
-- fungsi untuk menggabungkan 2 buah list 
-- definisi dan spesifikasi 
konkat :: [Int] -> [Int] -> [Int]
-- fungsi konkat l1 l2 akan menghasilkan sebuah list baru yang merupakan list 
-- gabungan l1 dan l2 
-- Realisasi
konkat l1 l2 
	| isEmpty l1 = l2
	| isEmpty l2 = l1
	| otherwise = konso (head l1) (konkat (tail l1) l2)
	
-- fungsi untuk mengecek apakah banyaknya elemen pada suatu list adalah N 
-- Definisi dan Spesifikasi 
isNbElmtN :: [Int] -> Int -> Bool 
-- fungsi isNbElmtN l n akan mengecek apakah jumlah member dari suatu list l adalah n
-- prekon : N >=0 
-- Realisasi 
isNbElmtN l n 
	| isEmpty l || n==0  = n==0 && isEmpty l 
	| otherwise = isNbElmtN (tail l) (n-1)
	
-- fungsi untuk mengecek apakah x adalah elemen ke N sebuah list 
-- Definisi dan Spesifikasi 
isXelmtKeN :: Int -> Int -> [Int] -> Bool
-- fungsi isXelmtKeN x n l akan menghasilkan true jika x adalah elemen ke-n dari l
-- prekon : n>0 dan n<=banyaknya elemen pada list dan list tidak kosong
-- realisasi
isXelmtKeN x n l
	|  n==1 = head l == x
	| otherwise = isXelmtKeN x (n-1) (tail l)
	
-- fungsi untuk mengecek keinverse-an suatu list 
-- Definisi dan Spesifikasi 
isInverse :: [Int] -> [Int] -> Bool 
-- fungsi isInverse l1 l2 akan menghasilkan true jika l2 merupakan list inverse dari l1 
-- Realisasi
isInverse l1 l2 
	| isEmpty l1 || isEmpty l2  = isEmpty l2 && isEmpty l1
	| head l1 == last l2 && isInverse (tail l1) (init l2) = True
	| otherwise = False 
	
-- fungsi untuk mencari nilai maks sebuah list integer 
-- maxList l 
-- Definisi dan Spesifikasi 
maxList :: [Int] -> Int 
-- fungsi maxList l akan menghasilkan suatu bilangan integer yang terbesar pada 
-- list l
-- prekon : list tak kosong 
-- Realisasi 
maxList l 
	|isOneElmt l = head l -- basis
	|head l > maxList (tail l) = head l -- rekurens 
	| otherwise = maxList (tail l) --rekurens
	
-- fungsi untuk mencari dimensi list    dimensi l 
-- Definisi dan Spesifikasi 
dimensi :: [Int] -> Int 
-- Realisasi 
dimensi l 
	| isEmpty l = 0 
	| otherwise = 1 + dimensi (tail l)
	
-- fungsi untuk menjumlahkan dua list    listPlus l1 l2 
-- Definisi dan Spesifikasi 
listPlus :: [Int] -> [Int] -> [Int]
-- fungsi listPlus l1 l2 akan menghasilkan l3 dimana l3 = l1+l2 
-- Realisasi 
listPlus l1 l2 
	| isEmpty l1 && isEmpty l2 = []
	| isEmpty l1 && not (isEmpty l2) = l2
	| isEmpty l2 && not (isEmpty l1) = l1 
	| otherwise = konso ((head l1) + (head l2)) (listPlus (tail l1) (tail l2))
	
-- fungsi untuk mengsortir list dari kecil ke besar dgn insertion
-- Definisi dan speseifikasi 
insort :: [Int] -> [Int]
{- insort l1 akan menghasilkan list yang terurut kecil ke besar -}
insert :: Int -> [Int] -> [Int]
{- insert x l1 akan menggabungkan elemen x pada l1 -}
-- Realiasi
insort l1
	| isEmpty l1 = []
	| otherwise = insert (head l1) (insort (tail l1))
	
insert e l1 
	| isEmpty l1 = konso e l1 
	| e <= head l1 = konso e l1
	| otherwise = konso (head l1) (insert e (tail l1))
	
-- fungsi untuk menghitung banyaknya faktor dari x 		countFactorOfX n l
-- Definisi dan Spesifikasi 
countFactorOfX :: Int -> [Int] -> Int 
-- countFactorOfX n l akan menghitung jumlah kemunculan bilangan yang merupakan 
-- faktor dari n pada l 
-- Realisasi 
countFactorOfX n l
	| isEmpty l = 0 -- basis 0 
	| isOneElmt l && mod n (head l) == 0 = 1 --basis 1 
	| mod n (head l) == 0 = countFactorOfX n (tail l) + 1 -- rekurens
	| otherwise = countFactorOfX n (tail l) -- rekurens 
	
-- fungsi untuk menghilangkan elemen ke-n dari list 	delNthElmt n l 
-- Definisi dan Spesifikasi 
delNthElmt :: Int -> [Int] -> [Int]
-- fungsi delNthElmt n l akan menghapus elemen ke-n dari L 
-- prekon : n<= jumlah elemen pada l, dan l tidak kosong 
-- Realisasi 
delNthElmt n l 
	| isOneElmt l && n == 1 = []
	| isOneElmt l && n == 0 = l 
	| n == 1 = tail l 
	| otherwise = konso (head l) (delNthElmt (n-1) (tail l))
	
-- fungsi untuk memecah list menjadi 2 dengan list 1 adalah list positif 
-- dan list ke-2 list negatif  		splitList l 
-- Definisi dan Spesifikasi 
splitList :: [Int] -> ([Int],[Int])
{- splitList(li) menghasilkan 2 list of integer, list
	pertama memuat bilangan positif dan 0 yang merupakan
	elemen dari li (dengan urutan kemunculan yang tidak
	berubah), sedangkan list kedua memuat bilangan negatif
	elemen li.
	Prekondisi: li mungkin kosong -}
-- Realisasi 
splitList li 
	| isEmpty li = ([],[]) --basis 0
	| isOneElmt li && (head li) >=0 = ([head li],[]) --basis 1
	| isOneElmt li && (head li) < 0 = ([],[head li]) -- basis 1
	| head li >= 0 = (konso (head li) (fst (splitList(tail li))),snd (splitList (tail li))) 
	| head li < 0 = ((fst (splitList (tail li))),(konso (head li)(snd (splitList(tail li)))))
	
-- fungsi untuk menggabungkan dua list 		mergeList l1 l2 
-- Definisi dan Spesifikasi 
mergeList :: [Int] -> [Int] ->[Int]
-- fungsi mergelist akan menggabungkan dua buah list yang terurut menjadi
-- satu list yang terurut 
-- Realisasi 
mergeList l1 l2 
	| isEmpty l1 && isEmpty l2 = [] -- basis 0
	| isEmpty l1 && not (isEmpty l2) = l2 -- basis 1 
	| isEmpty l2 && not (isEmpty l1) = l1 -- basis 1
	| head l1 <= head l2 = konso (head l1) (mergeList (tail l1) l2) -- rekurens
	| otherwise = konso (head l2) (mergeList l1 (tail l2))	-- rekurens
	
-- fungsi untuk mengecek apakah list l terurut membesar   isOrdered l
-- Definisi dan Spesifikasi
isOrdered :: [Int] -> Bool 
{- isOrdered(l) menghasilkan true jika elemen-elemen pada
   l terurut membesar, false jika tidak.
   Prekondisi: l tidak kosong -}
-- Realisasi 
isOrdered l
	| isOneElmt l = True -- Basis 1
	| head l < head (tail l) = isOrdered (tail l) -- rekurens
	| otherwise = False -- rekurens
	

splitAlternate :: [Int] -> ([Int],[Int])
sort :: [Int] -> [Int]
sortStep :: [Int] -> [Int]
splitAlternate l =
	if isEmpty l then
		([],[])
	else 
		let 
			(l1,l2) = (splitAlternate (tail l)) -- rekurens
		in 
			((konso (head l) l2),l1)
sortStep l 
	| isEmpty (tail l) = l -- basis
	| head l <= head (tail l) = konso (head l) (sortStep (tail l)) -- rekurens
	| otherwise = konso (head (tail l))(sortStep (konso (head l) (tail (tail l)))) -- yet rekurens
	
sort l
	| l == sortStep l = l -- basis jk sekali sort step sudah terurut
	| otherwise = sort (sortStep l) -- rekurens jk sort step terakhir blm terurut

	

	


	


	
	