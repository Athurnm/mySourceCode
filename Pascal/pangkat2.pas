Program Pangkat2; {program memangkatkan angka dengan struktur while}
{kamus}
var
	a:integer;
	i:integer;
	p:integer;
	n:integer;
{algoritma}
begin
	readln (a); readln(n);
	i:=1; p:=1;
	while (i<=n) do 
		begin
		p:=p*a;
		i:=i+1;
		end;
	writeln(p);
	readln;
	readln;
end.
		