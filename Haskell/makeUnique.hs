-- makeUnique 
konso :: Char -> [Char] -> [Char]
konso e l = [e] ++ l 
konsDot :: [Char] -> Char -> [Char]
konsDot l e = l ++ [e]
isEmpty :: [Char] -> Bool 
isEmpty l = null l 
isOneElmt l = null (tail l)
isEq :: [Char] -> Char -> Bool 
isEq l c 
	| isEmpty l = False  
	| head l /= c = isEq (tail l) c
	| otherwise = True 
	
makeUnique l 
	| isEmpty l = []
	| isEq (init l) (last l) = makeUnique (init l)
	| otherwise = konsDot (makeUnique (init l)) (last l)
	