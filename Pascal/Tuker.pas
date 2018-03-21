Program Pertukaran; 
{program untuk mempertukarkan nilai A dan B.}

{kamus}
var
A, B, C:Integer;

{Algoritma}
begin
	a:=8; b:=5;
	writeln ('nilai A dan B sebelum ditukar: ');
	writeln ('A= ', a);
	writeln ('B= ', b);
{pertukaran berlangsung}
	c:= a;
	a:= b;
	b:= c;
{sesudah pertukaran}
	writeln ('Nilai A dan B sesudah pertukaran: ');
	writeln ('A= ', A);
	writeln ('B= ', B);
	readln;
end.