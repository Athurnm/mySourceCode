-- Athur Naufan 16516003

module PenanggalanK where

-- Penanggalan 					penanggalanK d m y
-- DEFINISI DAN SPESIFIKASI
penanggalanK  :: Int -> Int -> Int -> Int 
-- Penanggalan d m y akan menghasilkan hari ke- pada input hari bulan dan tahun
-- user
-- Asumsi d m y dimasukan dengan benar (1<=d<=31, 1<=m<=12, 1<=y<=99)
dpm  :: Int -> Int 
-- dpm m akan menghitung jumlah hari pada awal bulan m 
isKabisat :: Int -> Bool
-- isKabisat y akan menghasilkan true jika y kabisat
-- REALISASI
penanggalanK d m y 
	| (isKabisat y == True && m == 1 || m == 2) || (isKabisat y == False) = dpm m + d
	| isKabisat y == True && m > 2 && m <= 12 = dpm m + d + 1
dpm 1 = 0 
dpm 2 = 31
dpm 3 = 59
dpm 4 = 90
dpm 5 = 120
dpm 6 = 151
dpm 7 = 181
dpm 8 = 212
dpm 9 = 243
dpm 10= 273
dpm 11= 304
dpm 12= 334

isKabisat y = if ((mod y 4 )== 0) && ((mod y 100 )/= 0) || ((mod y 400) == 0) then True else False
 -- APLIKASI
 -- penanggalan 1 1 1 = 1