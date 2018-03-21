program findingthesmallest;
{Kamus}
var
	Cmin:integer;
	N,C,i:integer;
begin
	write('masukan banyaknya angka yang akan dimasukan '); readln(n);
	writeln('masukan angka yang ingin dicari');
	readln(C);
	Cmin:= C;
	for i:=2 to N do
		begin
		readln(c);
		if (cmin >=c) then 
			begin
			cmin:=C;
			end;
		end;
	writeln ('nilai min ' , cmin );
	readln;
	readln;
end.