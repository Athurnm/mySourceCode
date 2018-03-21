Program jumlahganjil;
{kamus}
var
	n:integer;
	i:integer;
	sum:integer;
{algoritma}
begin
	writeln('masukan nilai untuk dihitung'); readln(n);
	if (n mod 2=1) then
		begin 
		sum:=0;
		i:=1;
		while (i<=n)do
			begin
			sum:=sum+i;
			i:=i+2;
			end;
		end else {n bilangan genap} 
		begin
		sum:=0;
		i:=1;
		n:=n-1;
		while (i<=n)do
			begin
			sum:=sum+i;
			i:=i+2;
			end;
		end;
	writeln('maka hasil penjumlahannya = ', sum);
	readln;
end.