{
Nama:Athur Naufan Muharam
NIM: 16516003
Soal: Soal 06 Latihan Matriks dan File eksternal
}
Program TulisKeFileEksternal;
{program untuk menuliskan data ke file lain}
{kamus}
var
	Fout:file of integer;
	i:integer; {increment}
	N:integer; {banyaknya angka}
	a:integer; {variabel untuk menampung angka}
{algoritma}
begin
	assign (fout, 'dataku.dat');
	rewrite(fout);
	{algoritma untuk masukan n agar n positif}
	Repeat
		write('Masukan nilai N(N >=0) : ');
		readln (N);
	until (N>=0);
	for i:= 1 to N do
	begin
		readln(a);
		write(fout,a); {syntax penulisan pada file external}
	end;
end.