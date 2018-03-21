program piramidaangka;
var
	n:integer;
	j:integer;
	procedure spasi (n:integer);
	var
		i:integer;
	begin 
		for i:= n downto j do 
		begin
			write (' ');
		end;
	end;
	procedure angka1 (n:integer);
	var
		i:integer;
	begin
		for i:= 1 to j do
		begin
			write (i+(j-1));
		end;
	end;
	procedure angka2;
	var
		i:integer;
	begin 
		for i:= j-1 downto 1 do
		begin
			write (i+(j-1));
		end;
	end;
begin
	write ('masukan ketinggian n = '); readln (n);
	for j:= 1 to n do 
		begin
			spasi (n);
			angka1 (n);
			angka2;
			writeln;
		end;
end.
	