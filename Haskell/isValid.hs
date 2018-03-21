-- Athur Naufan M

-- APAKAH VALID  				isValid(x)
-- DEFINISI DAN SPESIFIKASI
isValid :: Int -> Bool
	-- isValid (x) akan menghasilkan nilai True apabila x lebih kecil 5
	-- atau lebih besar 500

-- REALISASI
isValid x = (x<5)||(x>500)

-- APLIKASI
-- isValid 501 = True