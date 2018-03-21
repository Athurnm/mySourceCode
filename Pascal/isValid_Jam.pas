program isValidJam;
{program untuk mengecek apakah integer yang diinput valid atau tidak}
{kamus}
type
	jam = record
		jj:integer; {jam}
		mm:integer; {menit}
		dd:integer; {detik}
	end;
var
	a : integer;
	b : integer;
	c : integer;
	j1 : jam ;
{Algoritma}
begin
	write ('Masukan nilai a,b, dan c :');
	readln (a);
	readln (b);
	readln (c);
	if (a>=0) and (a<=23) and (b>=0) and (b<=59) and (c>=0) and (c<=59) then
	begin
		j1.jj := a; j1.mm := b; j1.dd := c;
	end else writeln ('Masukan Salah');
end.
	