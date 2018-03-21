program anakayam;
{deklarasi}
var
	a:integer;
	b:integer;
{algoritma}
begin
	writeln('masukan jumlah anak ayam = ');read(a);
	b:=a;
	writeln('tekotek2 anak ayam turun ',b);
	for b:= a-1 downto 1 do
		begin
			writeln('mati satu tinggal ',b);
		end;
	writeln('mati satu tinggal induknya');
	readln();
	readln();
end.