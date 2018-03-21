Program Piramida;
{kamus}
var
	a,b:integer; {banyaknya bintang dan spasi}
	i: integer; {increment}
	N: Integer; {banyak baris}
{algoritma}
begin
	write('masukan nilai N : '); read(N);
	for i:=1 to N do 
	begin
		for b:=N downto i do 
		begin
			write(' ');
		end;
		for a:=2*i-1 downto 1 do
		begin
			write ('*');
		end;
	writeln();
	end;
end.