-- Definisi dan Spesifikasi 
filterList :: [Int] -> (Int -> Bool) -> [Int]
-- FilterList (Li,f) dengan Li adalah list of integer dan f adalah
-- sebuah predikat dengan definisi f(i) menghasilkan true jika i
-- memenuhi suatu kondisi tertentu.
-- FilterList menghasilkan sebuah list
-- integer dengan elemen yang memenuhi predikat f.
konso :: Int -> [Int] -> [Int]
isOneElmt :: [Int] -> Bool 

-- Realisasi 
konso e l = [e] ++ l 
isOneElmt l = (null (tail l))
filterList l f 
	| isOneElmt l = if f (head l) then [(head l)] else []
	| otherwise = if f (head l) then konso (head l) (filterList (tail l) f) else filterList (tail l) f