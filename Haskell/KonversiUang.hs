-- Athur Naufan M
module KonversiUang where

-- Mengonversi quarter dime nickel dan penny menjadi dolar dan sen   konversi q d s
-- DEFINISI DAN SPESIFIKASI 
konversiUang :: Int -> (Int,Int)
-- Fungsi untuk mengonversi
konversiS :: Int -> Int -> Int -> Int -> Int
-- REALISASI
konversiS q d n p = 25*q+10*d+5*n+p
konversiUang s = (div (konversiS q d n p) 100, mod (konversiS q d n p) 100 )

-- APLIKASI
-- konversiUang 1 1 1 1 = (0, 41)