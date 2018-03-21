-- Athur Naufan M

-- APAKAH ORIGIN 			isOrigin(x,y)

-- DEFINISI DAN SPESIFIKASI
isOrigin :: Int -> Int -> Boolean
-- isOrigin (x,y) benar jika (x,y) = (0,0)

-- REALISASI
isOrigin x y = (x == 0) && (y == 0)

-- APLIKASI
-- isOrigin 1 0 = False