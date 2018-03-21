-- Athur Naufan M
module Next10Seconds where 
-- Fungsi menghitung waktu 10 detik      next10seconds j m d
-- DEFINISI DAN SPESIFIKASI
next10seconds :: Int -> Int -> Int -> (Int,Int,Int)
{- fungsi akan menghasilkan sebuah tuple untuk 10 detik dari input -}
-- REALISASI
next10seconds j m d =
   let s = 3600*j+60*m+d + 10
   
   in  	
      (div s 3600, div (mod s 3600) 60, mod (mod s 3600) 60)
	  