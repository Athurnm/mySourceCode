module CharList where 
-- Athur Naufan M
-- list karakter 
-- konstruktor dasar  konso
-- definisi dan spesifikasi
konso :: Char -> [Char] -> [Char]
-- konso 'e' l akan menghasilkan l baru dg 'e' elemen pertamanya
konsDot :: [Char] -> Char -> [Char]
-- konsDot l 'e' akan menghasilkan l baru dg 'e' elemen akhirnya 
isEmpty :: [Char] -> Bool 
-- isEmpty l akan menghasilkan True jika list kosong 
isOneElmt :: [Char] -> Bool 
-- isOneElmt l akan menghasilkan True jika list hanya memiliki satu anggota 
-- Realisasi 
konso e l = [e] ++ l 
konsDot l e = l ++ [e]
isEmpty l = null l 
isOneElmt l = length l == 1
-- fungsi hitung A 
nbA :: [Char] -> Int 
-- fungsi nbA t akan menghasilkan bny A pada list t 
-- Realisasi 
nbA t 
	| isEmpty t = 0
	| head t == 'A' = nbA (tail t) + 1
	| otherwise = nbA (tail t)

-- fungsi nbc c l fungsi untuk menghitung jumlah character c pada list l 
nbc :: Char -> [Char] -> Int 
-- fungsi nbc c l akan menghitung jumlah character c pada l 
-- Realisasi 
nbc c l 
	| isEmpty l = 0 
	| head l == c = 1 + nbc c (tail l) 
	| otherwise = nbc c (tail l)
	
-- fungsi atLeast n c l ; fungsi untuk mengecek apakah karakter c muncul minimal n
-- kali pada list l 
-- definisi dan spesifikasi 
atLeast :: Int -> Char -> [Char] -> Bool
-- Realisasi 
atLeast n c l
	| n==0 && isEmpty l = True --Basis
	| n==0 = True -- Basis 
	| n>=1 && isEmpty l = False --Basis 
	| n>=1 && c == head l = atLeast (n-1) c (tail l)
	| otherwise = atLeast n c (tail l)
	
-- fungsi untuk mengecek apakah suatu list character adalah palindrom
-- isPalindrome l 
-- Definisi dan Spesifikasi 
isPalindrome :: [Char] -> Bool 
-- Realisasi 
isPalindrome l 
	| isEmpty l = True --Basis 0
	| isOneElmt l = True  -- basis 1 
	| head l == last l = isPalindrome (init(tail l)) -- rekurens
	| otherwise = False 
	
-- fungsi untuk mengecek apakah dua list of character memiliki potongan awal yang sama
-- isEqFront l1 l2 
-- Definisi dan Spesifikasi 
isEqFront :: [Char] -> [Char] -> Bool 
-- fungsi isEqFront l1 l2 akan menghasilkan true jika sebagian atau seluruh anggota awal 
-- l2 sama dengan l1 
-- prekon: l1 dan l2 tidak kosong, nb l2 >= nb l1 
-- Realisasi 
isEqFront l1 l2 
	| isOneElmt l1 = head l1 == head l2 --basis 1 
	| head l1 == head l2 = isEqFront (tail l1) (tail l2)
	| otherwise = False 
	
-- fungsi untuk mengecek apakah list merupakan list yang unik dimna tidak ada 
-- karakter yang muncul lebih dari sekali 
-- isUnique l 
-- Definisi dan Spesifikasi
isUnique :: [Char] -> Bool
{- isUnique(lc) menghasilkan true jika lc adalah list
	dengan elemen unik, yaitu tidak ada elemen pada lc
	yang muncul lebih dari 1 kali -}
isUniqueRec :: [Char] -> [Char] -> Char -> Bool
{- isUniqueRec lc li ch akan mengecek kesamaan karakter ch pada list secara rekursif-}
-- Realisasi
isUnique lc
	| isEmpty lc || isOneElmt lc = True --Basis 
	| otherwise = isUniqueRec lc (tail lc) (head lc) --rekurens menggunakan fungsi antara
	
isUniqueRec lc li ch
	| (ch == (head li)) = False --Basis
	| ((length li) > 1) && (ch /= (head li)) = isUniqueRec lc (tail li) ch --rekursif
	| ((length li) == 1) && (ch /= (head li)) = isUnique (tail lc) --rekursif
-- fungsi untuk mengetahui posisi elemen dari list 
-- posOfX e lc 
-- Definisi dan Spesifikasi 
posOfX :: Char -> [Char] -> Int
{- posOfX(e,lc) menghasilkan sebuah bilangan integer yang
   menyatakan posisi e pada list of character lc. Jika e
   bukan elemen dari lc, fungsi akan menghasilkan 0.
   Prekondisi: lc memiliki elemen unik -}
isMember :: Char -> [Char] -> Bool
-- Realisasi 
posOfX e lc 
	| e == head lc = 1 --basis 1
	| not(isMember e lc) = 0 --basis 0
	| otherwise = 1 + posOfX e (tail lc)
	
isMember x l 
	| isEmpty l = False
	| head l == x = True
	| otherwise = isMember x (tail l)
	
-- fungsi untuk memisahkan list menjadi dua list, list genap dan list ganjil
-- splitAlternate lc 
-- Definisi dan Spesifikasi
splitAlternate :: [Char] -> ([Char],[Char])
{- splitAlternate(l) menghasilkan dua buah list, misalnya
   l1 dan l2. l1 berisi semua elemen l pada posisi
   ganjil, l2 berisi semua elemen l pada posisi genap -}
elemenGanjil :: [Char] -> Int -> [Char]
-- fungsi elemenGanjil l x akan menambahkan elemen2 pada indeks ganjil ke list baru dalam tuple list
elemenGenap :: [Char] -> Int -> [Char]
-- fungsi elemenGenap l x akan menambahkan elemen2 pada indeks genap ke list baru dalam tuple list

-- Realisasi 
elemenGanjil l x 
	| isEmpty l = [] -- Basis 0
	| mod x 2 == 1 = konso (head l) (elemenGanjil (tail l)(x+1)) -- rekurens
	| otherwise = elemenGanjil (tail l) (x+1) -- rekurens
elemenGenap l x 
	| isEmpty l = [] -- Basis 0
	| mod x 2 == 0 = konso (head l) (elemenGenap (tail l)(x+1)) -- rekurens
	| otherwise = elemenGenap (tail l) (x+1) -- rekurens
	
splitAlternate lc = ((elemenGanjil lc 1),(elemenGenap lc 1))
	
-- fungsi makeUnique lc
-- DEFINISI DAN SPESIFIKASI 
isEqual :: [Char] -> Char -> Bool 
-- fungsi isEqual lc c akan menghasilkan true jika terdapat elemen yang sama dengan c 
makeUnique :: [Char] -> [Char]
-- fungsi makeUnique lc akan menghasilkan list karakter yang unik 

-- REALISASI 
isEqual lc c 
	| isEmpty lc = False 
	| head lc == c = True 
	| otherwise = isEqual (tail lc) c 
	
makeUnique lc 
	| isEmpty lc = []
	| isOneElmt lc = [head lc]
	| isEqual (init lc) (last lc) = makeUnique (init lc)
	| otherwise = konsDot (makeUnique (init lc)) (last lc)

