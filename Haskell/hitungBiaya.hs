-- Athur Naufan M 
-- DEFINISI DAN SPESIFIKASI 
hitungBiaya :: Int -> Int -> Int -> Bool -> Int
{- HitungBiaya(k,h,s,a) menghasilkan besar biaya yang harus dibayar
oleh seorang pasien rawat inap dengan status keanggotaan a yang
menginap pada kamar kelas k selama h hari,
menggunakan s orang dokter spesialis.
k bernilai [1..3], h >= 0, s >= 0
Ketentuan perhitungan biaya adalah sbb:
Biaya yang harus dibayarkan oleh pasien terdiri dari dua komponen,
yaitu biaya kamar dan biaya dokter spesialis
(dokter yang bukan spesialis dianggap bagian dari biaya kamar).
Biaya kamar bervariasi berdasarkan kelasnya:
Kelas 1 = Rp. 750.000,-/hari
Kelas 2 = Rp. 600.000,-/hari
Kelas 3 = Rp. 400.000,-/hari
Biaya dokter spesialis adalah Rp. 1.500.000,- per dokter
setiap kali menginap (tidak memperhitungkan jumlah hari).
Bagi pasien yang merupakan Anggota (a = true),
maka berhak atas potongan 20% dari biaya kamar dan
potongan 10% dari biaya dokter spesialis. -}
-- REALISASI 
hitungBiaya k h s a 
	| k == 1 = if a == True then (div (8*750000*h) 10) + (div (9*1500000*s) 10) else 750000*h+1500000*s 
	| k == 2 = if a == True then (div (8*600000*h) 10) + (div (9*1500000*s) 10) else 600000*h+1500000*s
	| k == 3 = if a == True then (div (8*400000*h) 10) + (div (9*1500000*s) 10) else 400000*h+1500000*s