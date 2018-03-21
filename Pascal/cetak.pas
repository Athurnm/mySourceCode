Program cetakhelloworld;
{kamus}
var
i:integer;
N:integer;
sum:integer;
{algoritma}
begin
	write('masukan jumlah pengulangan'); read(N);
	sum:=0;
	for i:=1 to N do
	begin	
		writeln(i);
		sum:=sum+i;
	end;
	writeln(sum);
	readln;
	readln;
end.