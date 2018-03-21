Program kincir;
{
Nim/Nama	: 16516003/Athur Naufan Muharam
Nama file	: B02-16516003-161005-01.pas
Tanggal		: 05 oktober 2016
deskripsi	: 
}
{kamus}
var
	N: integer; {banyaknya bintang pada baris ke-N}
	x,y,z,a,c,d,e:integer;
	i1,i2: integer; {increment}
	b: char; {karakter bintang}
	s: char; {karakter spasi}
{algoritma}
begin
	write('Masukan nilai N : '); read(N);
	b:='*'; s:=' ';
	for i1:= 1 to N do
	begin
		for x:= 1 to i1 do
		begin
			write (b);
		end;
		for y:= N downto i1 do
		begin 
			write (s);
		end;
		for z:= N downto i1 do
		begin
			write (b);
		end;
	writeln();
	end; 
	for x:=1 to N do 
	begin
		write (s);
	end;
	writeln('X');
	for i2:= 1 to N do
	begin
		for a:= N-1 downto i2 do 
		begin
			write (s);
		end;
		for c:= 1 to i2 do
		begin
			write(b);
		end;
		for e:= 1 to i2 do
		begin
			write(s);
		end;
		for d:= N downto i2 do
		begin
			write (b);
		end;
		writeln;
	end;
end.