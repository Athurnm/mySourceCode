-- Athur Naufan 16516003

module Penanggalan where

-- Penanggalan (tahun bukan kabisat)					penanggalan d m y
-- DEFINISI DAN SPESIFIKASI
penanggalan :: Int -> Int -> Int -> Int 
-- Penanggalan d m y akan menghasilkan hari ke- pada input hari bulan dan tahun
-- user
-- Asumsi d m y dimasukan dengan benar (1<=d<=31, 1<=m<=12, 1<=y<=99)
dpm  :: Int -> Int 
-- dpm m akan menghitung jumlah hari pada awal bulan m 

-- REALISASI
penanggalan d m y = fromIntegral (dpm m + d) 
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
 
 -- APLIKASI
 -- penanggalan 1 1 1 = 1