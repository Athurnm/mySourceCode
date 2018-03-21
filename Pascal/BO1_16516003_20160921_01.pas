Program untungrugi; {program untuk menentukan apakah tuan vin untung atau rugi}
{Kamus}
var
	modalawal, hasilpenjualan:integer;
	
{algoritma}
begin
	writeln('masukan modal awal :'); readln (modalawal);
	writeln('masukan hasil penjualan :'); readln(hasilpenjualan);
	if (modalawal>hasilpenjualan) then 
		begin writeln ('Hasil danusan Tuan Vin menguntungkan');
		end else
		writeln ('Hasil danusan Tuan Vin tidak mendapatkan keuntungan');
end.
