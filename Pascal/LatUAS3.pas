Program Soal03;
{kamus}
const NMax = 31;
Type
	Tabint = array [1..NMax] of integer;
	TabReal = array [1..NMax] of real;
var
	TempF:Tabint;
	temp:integer;
	TempK:TabReal;
	Neff1:integer;
	Neff2:integer;
	rerata:real;
	fin:file of Integer; {nama lojik file tersebut}
	i:integer;
	
	Procedure HitungRerata (Tab:Tabint; Neff:integer; var rerata:real);
	var
		sum:integer;
		i:integer;
	begin
		sum:=0;
		for i:= 1 to Neff do
		begin
			sum:= Tab[i] + sum;
		end;
		rerata:= sum/Neff;
	end;
	
	Function KonversiFkeK (TF:integer):real;
	{kamus}
		//kosong
	begin
		KonversiFkeK:= (TF +459.67)*5/9;
	end;
	
{algoritma Utama}
Begin
	assign (fin,'temperatur.dat');
	reset (fin);
	neff1:= 0;
	while not(eof(fin)) do 
	begin
		read(fin,temp);
		neff1:=neff1+1;
		TempF[neff1]:=temp;
	end;
	close (fin);
	HitungRerata(TempF,Neff1,rerata);
	writeln ('Rata-rata temperatur suatu kota (dalam fahrenheit) adalah ',rerata:0:2,' derajat fahrenheit');
	neff2:=neff1;
	for i:= 1 to neff1 do
	begin
		TempK[i]:= KonversiFkeK(TempF[i]);
	end;
	for i:= 1 to neff2 do
	begin
		writeln(TempK[i]:0:2);
	end;
end.
		