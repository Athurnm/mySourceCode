Program bilprima; {mencari bilangan prima}
{
Nim/Nama	: 16516003/Athur Naufan Muharam
Nama file	: B02-16516003-161005-01.pas
Tanggal		: 05 oktober 2016
deskripsi	: 
}
var
	N: integer; {banyak pengulangan}
	a: integer; {angka yang di cek}
	x: integer; {hasil bagi}
	i1,i2: integer; {increment}
{algoritma}
begin
	write('masukan banyaknya bilangan : '); readln(N);
	for i1:=1 to N do 
	begin
		write ('masukan bilangan ke - ',i1, ' : ');
		read(a);
		if (a>3) then 
		begin
			for i2:=2 to trunc(sqrt(a)) do 
			begin
				x:=a mod i2;
			end;
			if (x<>0) then 
			begin
				writeln(a, ' merupakan bilangan prima');
			end else 
			begin {x=0}
				writeln(a, ' bukan merupakan bilangan prima');
			end;
		end else if (a<=1) then 
		begin
			writeln (a, ' bukan bilangan prima');
		end else {1<a<3} 
		begin
			writeln(a, ' merupakan bilangan prima');
		end;
	end;
	readln;
	readln;
end.