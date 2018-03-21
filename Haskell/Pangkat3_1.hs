-- Athur Lat Haskell

-- PANGKAT3 (ver 2) 			fx3(x)
fx3 :: Int -> Int
	{- fx3(x) menghitung pangkat 3 dari x, sebuah bilangan
	integer dengan aplikasi fx2 sebagai fungsi antara -}
fx2 :: Int -> Int
	{- fx2(x) menghitung pangkat 2 dari x, sebuah bilangan integer -}

-- REALISASI
fx3 x = (fx2 x) * x
fx2 x = x * x

-- APLIKASI
-- fx3 2 = 8