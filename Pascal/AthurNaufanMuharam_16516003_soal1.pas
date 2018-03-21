{
Nama/NIM	: Athur Naufan Muharam/16516003
Kelas PTI 	: 07
Fakultas 	: STEI
Soal 		: 01
}
program pecahuang; {program untuk memecah uang}
{kamus}
var
	TabUang : array [1..7] of longint;
	a: longint; {nominal uang}
	s: longint; {sisa uang}
	i,i1: integer; {increment}
	j: integer; {jumlah lembar uang}
	x: integer; {banyaknya uang yang akan dipecah}
{algoritma}
begin
	{masukan pecahan uang ke array}
	TabUang [1]:= 100000;
	TabUang [2]:= 50000;
	TabUang [3]:= 20000;
	TabUang [4]:= 10000;
	TabUang [5]:= 5000;
	Tabuang [6]:= 2000;
	TabUang [7]:= 1000;
	{memecah uang}
	write ('masukan jumlah uang yang akan dipecah '); readln (x);
	for i:=1 to x do
		begin
			write ('masukan nominal uang '); readln (a);
			for i1:=1 to 7 do 
				begin
					j:= a div TabUang [i1];
					if (j<>0) then 
						begin
							writeln (j,' lembar Rp. ', TabUang[i1]);
							s:= a mod TabUang [i1];
							a:= s;
						end;
				end;
		end;
end.
				
					
	