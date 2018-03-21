-- Athur Naufan M

-- APAKAH JAM VALID						isJamValid(j,m,d)
-- DEFINISI DAN SPESIFIKASI
isJamValid :: Int -> Int -> Int -> Bool
	{- isJamValid (j m d) akan menghasilkan True apabila jam antara 0 smp 23
	menit 0 smp 59 detik 0 smp 59 -}
	
-- REALISASI
isJamValid j m d = ((j>=0) && (j<=23)) && ((m>=0) && (m<=59)) && ((d>=0) && (d<=59))

-- APLIKASI
-- isJamValid 0 0 0 = true