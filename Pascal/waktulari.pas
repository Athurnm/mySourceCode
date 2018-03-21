Program KonversiWaktuKeDetik; 
{Membaca waktu tempuh dalam jam, menit, detik. lalu merubah itu menjadi sekon}

{Kamus}
type Jam = record
		hh: longint; {jam}
		mm: longint; {menit}
		ss: longint; {detik}
	end;
var
J : jam;
TotalDetik : longint;

{Algoritma}
begin
	write ('Jam: '); readln(J.hh);
	write ('menit: '); readln(J.mm);
	write ('detik: '); readln(J.ss);
	
	Totaldetik := (J.hh*3600)+(J.mm*60)+J.ss;
	writeln ('total waktu tempuh anda: ', totaldetik, 'sekon');
	readln;
end.