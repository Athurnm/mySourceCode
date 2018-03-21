Program decimalbiner;
{kamus}
var
	a:integer;
	biner:string;
	i:integer;
{algoritma}
begin
	write('masukan bilangan yang ingin dikonversi ke biner : '); readln(a);
	biner:='';
	while (a<>0) do 
		begin
		i:=a mod 2;
		a:= a div 2;
			case i of
				1: biner:=biner + '1';
				0: biner:=biner + '0';
			end;
		end;
	writeln ('hasil konversi = ', biner);
	readln;
end.		
			