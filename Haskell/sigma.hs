-- Athur
-- DEFINISI DAN SPESIFIKASI 
sigma :: Int -> Int -> (Int -> Float) -> (Int -> Int) -> Float 
-- sigma a b f s adalah penjumlahan dari deret f i dengan mengambil nilai a s adalah
-- REALISASI 
sigma a b f s = if a>b then 0 
					else (f a) + sigma (s a) b f s 