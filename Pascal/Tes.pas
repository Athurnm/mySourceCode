Program CekMatriksSatuan; 
{program untuk mengecek apakah matriks merupakan matriks satuan}
{kamus}
Type
	MatInt=array [1..10,1..10] of integer;
var
	M:MatInt;
	Nkol,Nbrs:integer; {Neff matriks}
	
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
	
	{fungsi untuk mengecek isi matriks}
	Function Cek(M:MatInt):boolean;
	var
		i,j:integer;
	begin
		cek:= true;
		for i:= 1 to Nbrs do
		begin
			for j:=1 to Nkol do
			begin
				if (M[i,j]<0)or (M[i,j]>1) then
				begin
					cek:=false;
				end;
			end;
		end;
	end;
	
{algoritma Utama}
begin
	Write('masukan Nkol Matriks: ');readln(Nkol);
	write('Masukan Nbar Matriks: ');readln(Nbrs);
	writeln('Masukan Input Matriks : ');
	InputMatriks(Nbrs,Nkol,M);
	If cek(m) then
	begin
		writeln('Matriks adalah matriks satuan');
	end else
	begin
		writeln('Matriks bukan matriks satuan');
	end;
end.