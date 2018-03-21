Program CalcSS;
{Program untuk menghitung angka dengan kalkulator sederhana}

{kamus}
var 
	A,B,hasil2 : integer;
	Hasil1: real;
	Opsi : char;
{algoritma}
begin 
	writeln('masukan nilai A dan B yang ingin dihitung');
	readln(a);readln(b);
	writeln('masukan opsi a untuk penjumlahan');
	writeln('masukan opsi b untuk pengurangan');
	writeln('masukan opsi c untuk perkalian');
	writeln('masukan opsi d untuk pembagian dengan hasil real');
	writeln('masukan opsi e untuk pemabagian dengan hasil integer');
	writeln('masukan opsi f untuk mencari sisa hasil bagi');
	write('masukan opsi yang anda inginkan ');
	read(opsi);
	
	case opsi of
		'a': begin
				hasil2 := a+b; writeln ('hasil penghitungan: ', hasil2);
			end;
		'b': begin
				hasil2:= a-b; writeln('hasil penghitungan: ',hasil2);
			end;
		'c': begin
				hasil2:= a*b; writeln('hasil penghitungan: ',hasil2);
			end;
		'd': begin
				hasil1:= a/b; writeln('hasil penghitungan: ',hasil1:0:2);
			end;
		'e': begin
				hasil2:= a div b; writeln('hasil penghitungan: ', hasil2);
			end;
		'f': begin
				hasil2:= a mod b; writeln('hasil penghitungan: ',hasil2);
			end;
		else writeln ('tidak tersedia pilihan opsi');
	end;
	readln; writeln('tekan enter untuk menutup app');
	readln;
end.