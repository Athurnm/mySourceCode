Program UmurPenduduk;
{ Membaca data umur sebanyak jumlah penduduk dan menyimpan ke file }
{ KAMUS }
var
	fin : file of integer;
	i,N,umur : integer;
{ ALGORITMA }
begin
	assign(fin,'dataku.dat');
	reset(fin);
	while (not EOF(fin)) do
	begin
		read(fin,umur);
		writeln(umur);
	end;
	close(fin);
end.