Program LatUAS414;
{kamus}
Type
	TabInt = Array [1..3,1..3] of integer;
var
	M1:TabInt;
	M2:TabInt;
	M3:TabInt;
	Menu:integer;
	
	Procedure IsiMatriks (Var M:TabInt);
	{kamus}
	var	
		i,j:integer;
	{algoritma lokal}
	begin
		for i:= 1 to 3 do
		begin
			for j:= 1 to 3 do
			begin
				read(M[i,j]);
			end;
			writeln();
		end;
	end;
	
	Procedure PrintMatriks (M:TabInt);
	{kamus}
	var
		i,j:integer;
	{algoritma lokal}
	begin 
		for i:= 1 to 3 do
		begin
			for j:= 1 to 3 do
			begin
				write (M[i,j],' '); 
			end;
			writeln();
		end;
	end;
	
	Procedure JumlahMatriks (A1:TabInt;A2:TabInt;Var A3:TabInt);
	{kamus lokal}
	Var
		i,j:integer;
	{algoritma lokal}
	begin
		for i:= 1 to 3 do 
		begin
			for j:= 1 to 3 do 
			begin
				A3[i,j]:= A1[i,j]+A2[i,j];
			end;
		end;
	end;
	
	Procedure KaliMatriks (B1:TabInt;B2:TabInt; var B3:TabInt);
	{kamus lokal}
	var
		i,j,k:integer; {increment}
	{algoritma lokal}
	begin
		for i:= 1 to 3 do 
		begin
			for j:= 1 to 3 do 
			begin
				B3[i,j]:= 0;
				for k:= 1 to 3 do 
				begin
					B3[i,j]:= B3[i,j] + (B1[i,k]*B2[k,j]);
				end;
			end;
		end;
	end;
	
	Function CekMatriks (C1:TabInt):boolean;
	{kamus lokal}
	var
		i,j:integer;
	{algoritma lokal}
	begin
		CekMatriks:=true;
		for i:= 1 to 3 do 
		begin
			for j:= 1 to 3 do 
			begin
				if (C1[i,j] > 1 ) or (C1[i,j] < 0) then
				begin
					CekMatriks:=false;
				end;
			end;
		end;
	end;
	
	{algoritma utama}
Begin
	writeln ('Masukan nilai Matriks A = ');
	IsiMatriks(M1);
	writeln('Masukan nilai Matriks B = ');
	IsiMatriks(M2);
	Writeln (' Pilihan Menu : ');
	writeln (' 1. Perkalian Matriks');
	writeln (' 2. Penjumlahan Matriks');
	writeln (' 3. Mengecek matriks satuan');
	write (' Masukan pilihan anda : ');
	readln (menu);
	Case menu of
		1: 	begin
				writeln ('Hasil perkalian Matriks A dan B = ');
				KaliMatriks(M1,M2,M3);
				PrintMatriks(M3);
			end;
			
		2:	Begin
				writeln ('Hasil penjumlahan matriks A dan B = ');
				JumlahMatriks(M1,M2,M3);
				PrintMatriks(M3);
			end;
			
		3:	Begin
				If CekMatriks(M1) then
				begin
					writeln ('Matriks A adalah matriks satuan');
				end else
				begin
					writeln ('Matriks A bukan matriks satuan');
				end;
				If CekMatriks(M2) then
				begin
					writeln ('Matriks B adalah matriks satuan');
				end else
				begin
					writeln ('Matriks B bukan matriks satuan');
				end;
			end;
		else writeln ('Bukan pilihan yang tepat');
	end;
end.