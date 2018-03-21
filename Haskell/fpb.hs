-- Athur Naufan M
module Fpb where
-- mencari fpb menggunakan pengurangan nilai minimum  fpb a b 
-- Definisi dan Spesifikasi
hitung :: Int -> Int -> Int -> Int
-- fungsi fpb a b akan menghasilkan nilai fpb dari kedua bilangan tersebut
fpb :: Int -> Int -> Int
-- fungsi min2 a b akan menghasilkan nilai terkecil dari a dan b
-- Realisasi
fpb a b 
	| b>=a = hitung a b a
	| otherwise = hitung a b b
	
hitung a b c
	| ((mod a c)==0)&&((mod b c) == 0) = c
	| c == 1 = 1
	| otherwise = hitung a b (c-1)
	