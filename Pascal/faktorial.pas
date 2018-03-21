Program Faktorial;
{kamus}
var
	a,b,c,d,e:integer;
	i:integer;
{algoritma}
begin
	write ('masukan angka faktorial : '); read(a);writeln('!');
	b:=1;
	for i:=1 to a do
		begin
		b:=b*i;
		end;
	write (a, '! : ', b);
	readln;
end.