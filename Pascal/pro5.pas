program pro5;
{kamus}
var
	n: integer;
	rata:real;
	{procedure}
	procedure rata2 (n:integer; var u: real);
	var
		x:integer;
		k:integer;
		total:integer;
	begin
		total := 0;
		for k:=1 to n do
			begin
				write ('masukan data nilai '); readln (x);
				total := total+x;
			end;
		u:= total/n;
	end;
{algoritma}
begin
	write('masukan jumlah siswa = '); read (n);
	rata2(n,rata);
	writeln ('rata-rata nilai siswa = ', rata:0:2);
end.