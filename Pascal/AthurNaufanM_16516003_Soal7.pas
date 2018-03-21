{
Nama:Athur Naufan Muharam
NIM: 16516003
Soal: Soal 07 Latihan Matriks dan File eksternal
}
Program HitungRataDariFileInput;
{program untuk menghitung banyaknya data dan rata2 angka file input}
{kamus}
var
	Fin:file of integer; {nama logic file}
	Sum:integer; 
	rata2:real;
	Count:integer;
	N:integer;
{algoritma}
begin
	assign(fin,'dataku.dat');
	reset(fin);
	sum:=0;
	count:=0;
	while (not(eof(fin))) do
	begin
		read(fin,N);
		Sum:=Sum+N;
		Count:=Count+1;
	end;
	rata2:= Sum/count;
	writeln('Rata-rata dari dataku.dat adalah : ',rata2:0:2);
	close(fin);
end.