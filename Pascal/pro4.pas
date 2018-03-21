program pro4;
{kamus}
var
	a,b : integer;
	{procedure}
	procedure tukar(var a,b: Integer);
	(*deklarasi*)
	var
		c: integer;
	begin
		c:=b;
		b:=a;
		a:=c;
	end;
begin
	write('masukan nilai yang akan ditukar a = '); readln (a);
	write('masukan nilai yang akan ditukar b = '); readln (b);
	tukar (a,b);
	writeln ('nilai a = ', a);
	writeln ('nilai b = ', b);
end.
	