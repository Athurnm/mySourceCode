Program MatriksArray1; {program menjumlahkan baris dan kolom pada matriks}
{kamus}
Type
	MatInt=array [1..10,1..10] of integer;
var
	M:MatInt;
	i,j:integer;
	Nbrs,Nkol:integer;
	
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
	
{algoritma utama}
begin
	write('masukan nbaris : '); readln(Nbrs);
	write('Masukan nKolom : '); readln(Nkol);
	InputMatriks (Nbrs,Nkol,M);
	{algoritma menghitung baris}
	for i:= 1 to Nbrs do 
	begin
		M[i,Nkol+1]:=0;
		for j:= 1 to Nkol do
		begin
			M[i,Nkol+1]:= M[i,Nkol+1] + M[i,j];
		end;
	end;
	{algoritma menghitung kolom}
	for j:= 1 to Nkol do
	begin
		M[Nbrs+1,j]:=0;
		for i:= 1 to Nbrs do
		begin
			m[Nbrs+1, j]:=M[Nbrs+1,j]+M[i,j];
		end;
	end;
	writeln ('Hasil penghitungan Matriks : ');
	writeln ('------------------------------------');
	{algoritma menampilkan matriks kelayar}
	for i:= 1 to Nbrs+1 do
	begin
		for j:=1 to Nkol+1 do
		begin
			write(M[i,j]);
		end;
		writeln();
	end;
end.