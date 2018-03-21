-- Athur Naufan Lat Haskell

-- APAKAH HURUF A 				isAnA(c)

-- DEFINISI DAN SPESIFIKASI

isAnA :: Char -> Bool
-- isAnA (c) akan benar jika c adalah karakter 'a' atau 'A'
-- REALISASI
isAnA c = c == 'A' || c =='a'

-- APLIKASI
	-- isAnA 'A'