-- Athur Naufan M 
module IsDateValid where
-- Apakah tanggal valid 					isDateValid d m y
-- DEFINISI DAN SPESIFIKASI 
isDateValid :: Int -> Int -> Int -> Bool
-- isDateValid d m y akan menghasilkan nilai true jika input d m y tepat dan false 
-- pada sebaliknya
isKabisat :: Int -> Bool 
-- isKabisat akan mereturn true jika tahun kabisat dan false pada sebaliknya

-- REALISASI
isKabisat y = (mod y 4 == 0) && (mod y 100 /= 0) || (mod y 400 == 0) 
isDateValid d m y
	| m == 1 && d<=31 && d>=1 = True
	| m == 2 && isKabisat y == True && d>=1 && d<=29 = True
	| m == 2 && isKabisat y == False && d>=1 && d<=28 = True
	| m == 3 || m == 5 || m ==7 || m == 8 || m == 10 || m == 12 && d>= 1 && d<= 31 = True 
	| m == 4 || m == 6 || m == 9 || m == 11 && d>= 1 && d<= 30 = True
	| otherwise = False
	
-- Aplikasi 
-- isDateValid 1 1 1 = True