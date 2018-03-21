Program Hitungkaraktersampetitik;
{kamus}
var
	cc:char;{karakter yang dimasukan}
	Ncc:integer;{jumlah karakter}
	
{algoritma}
begin
	writeln('masukan karakter yang ingin ditulis, lalu akhiri dengan "." ');
	Ncc:=0;
	read(cc);
	while (cc<>'.') do {cc tidak = '.'}
		begin
		Ncc:=Ncc+1;
		read(cc);
		end; {cc = '.'}
	writeln ('jumlah karakter yang dimasukan sebanyak ',Ncc, ' char');
	readln();
	readln();
end.