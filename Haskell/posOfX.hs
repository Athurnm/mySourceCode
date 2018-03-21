posOfX :: Char -> [Char] -> Int
isMember :: Char -> [Char] -> Bool

isMember e lc = if (null lc) then False
					else if (head lc == e) then True
					else isMember e (tail lc)
posOfX e lc = if (isMember e lc) then if (null lc) then 0
									else if (head lc == e) then 1
										else 1 + posOfX e (tail lc)
			else 0