-- Athur Naufan M
module KonversiUang where

-- Mengonversi quarter dime nickel dan penny menjadi dolar dan sen   konversi q d s
-- DEFINISI DAN SPESIFIKASI 
konversiUang :: Int -> Int -> Int -> Int -> (Int,Int)
-- Fungsi untuk mengonversi

-- REALISASI

konversiUang q d n p = 
		let s = 25*q+10*d+5*n+p
		in	(div s 100, mod s 100)
-- APLIKASI
-- konversiUang 1 1 1 1 = (0, 41)