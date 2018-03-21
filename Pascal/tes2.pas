{
Nama:Athur Naufan Muharam
NIM: 16516003
Soal: Soal 05 Latihan Matriks dan File eksternal
}
Program MatriksSegitigaAtas;
{program untuk menentukan Apakah matriks segitiga atas atau tidak}
{kamus}
Type
	MatInt=array [1..10,1..10] of integer;
Var
	M:MatInt;
	Nkol,Nbrs:integer;{Neff matriks}
	
	{procedure untuk mengisi matriks}
	Procedure InputMatriks (n1:integer; n2:integer; var M1:MatInt);
	{kamus lokal}
	var	
		i,j:integer;
	{algoritma}
	begin	
		for i:= 1 to n1 do
		begin
			for j:= 1 to n2 do 
			begin
				read(M1[i,j]);
			end;
			writeln;
		end;
	end;
	
	{procedure untuk menampilkan matriks}
	Procedure PrintMatriks (n1:integer; n2:integer; var M1:MatInt);
	{kamus lokal}
	var	
		i,j:integer;
	{algoritma}
	begin	
		for i:= 1 to n1 do
		begin
			for j:= 1 to n2 do 
			begin
				write(M1[i,j]);
			end;
			writeln;
		end;
	end;
	
	{fungsi untuk mengecek apakah matriks segitiga atas atau bukan}
	Function Cek(Nbrs:integer;Nkol:integer;M:MatInt):boolean;
	{kamus lokal}
	var
		i,j:integer;
	{algoritma}
	begin
		Cek:=true;
		for j:= 1 to Nkol do
		begin
			for i:= Nbrs downto j+1 do
			begin
				if (M[i,j]<>0) then
				begin
					cek:=false;
				end;
			end;
		end;
	end;
	
{algoritma utama}
begin
	write('Masukan Nbrs : '); readln(Nbrs);
	write('Masukan Nkol : '); readln(Nkol);
	if (Nbrs<>Nkol) then
	begin
		writeln ('Matriks yang anda akan input bukan matriks segitiga atas');
	end else
	begin
	writeln ('Input nilai matriks :');
	InputMatriks(Nbrs,Nkol,M);
	
		writeln ('Matriks yang anda input: ');
		PrintMatriks(Nbrs,Nkol,M);
		if cek(Nbrs,Nkol,M) then 
		begin
			writeln ('adalah matriks segitiga atas! ');
		end else 
		begin
			writeln ('adalah Bukan matriks segitiga atas');
		end;
	end;
end.