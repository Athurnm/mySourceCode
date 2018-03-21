splitAlternate :: [Char] -> ([Char],[Char])
ganjil :: Int -> [Char] -> [Char]
genap :: Int -> [Char] -> [Char]
konso :: Char -> [Char] -> [Char]
konso e l = [e] ++ l 

ganjil x l = if (null l) then []
			else if mod x 2 == 1 then (konso (head l) (ganjil (x+1) (tail l)) )
			else ganjil (x+1) (tail l)
genap x l = if (null l) then []
			else if mod x 2 == 0 then (konso (head l) (genap (x+1) (tail l)) )
			else ganjil (x+1) (tail l)
splitAlternate l = (ganjil 1 l,genap 2 l)