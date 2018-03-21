Program UmurPenduduk;
{ Membaca data umur sebanyak jumlah penduduk dan menyimpan ke file }
{ KAMUS }
var
	fout : file of integer;
	i,N,umur : integer;
{ ALGORITMA }
begin
	assign(fout,'dataumur.dat');
	rewrite(fout);
	N := 5;
	for i:=1 to N do
	begin
		read(umur);
		write(fout,umur);
	end;
close(fout);
end.

