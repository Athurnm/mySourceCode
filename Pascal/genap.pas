Program bilangangenap;
{program untuk menentukan bilangangenap}

{kamus}
var
	x:integer;
{algotritma}
begin
	writeln('masukan nilai x '); read(x);
	if x mod 2 = 0 then writeln('x = bilangan genap!')
	else writeln ('x = bilangan ganjil');
	readln;
	readln;
end.