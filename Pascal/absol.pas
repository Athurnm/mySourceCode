Program absoluteValue; 
{program untuk melihat nilai mutlak}

{kamus}
var
	x: integer;

{Algoritma}
begin
	writeln('masukan nilai x'); readln(x);
	if x<0 then x:= -x else x:= x;
	writeln ('nilai |x| = ', x);
	readln;
end.
	