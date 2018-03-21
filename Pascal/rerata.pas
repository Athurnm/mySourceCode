program rata2;
{kamus}
var	
	i:integer;
	n:integer;
	a:integer;
	sum:integer;
	mean:integer;
{algoritma}
begin
	writeln('masukan jumlah data'); readln(n);
	writeln('masukan angka');
	sum:=0;
	for i:=1 to n do
	begin	
		readln(a);
		sum:=sum+a;
	end;
	mean:=sum div n;
	writeln('rata-ratanya adalah ', mean);
	readln;
	readln;
end.