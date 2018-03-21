Program latPrak1; {program untuk menentukan apakah file matriks hasil rotasi dari matriks sebelumnya}
{kamus}
Type
	TabInt=array[1..100,1..100] of integer;
var
	N:integer;
	A:tabint;
	B:tabint;
	
	Procedure InputArray (a:integer; var M:tabint);
	var
		i,j:integer;
	Begin
		for i:= 1 to a do 
		begin
			for j:= 1 to a do
			begin
				read(M[i,j]); writeln(' ');
			end;
			writeln;
		end;
	end;
	
	Procedure RotasiArray (N:integer; var M:tabint);
	var
		i,j:integer;
		a:tabint;
	begin
		for i:= 1 to n do
		begin
			for j:=1 to n do 
			begin
				a[i,j]:= M[j,i];
			end;
		end;
		for i:= 1 to n do
		begin
			for j:=1 to n do 
			begin
				M[i,j]:= a[i,n-j+1];
			end;
		end;
	end;
	
	Function Ceksama (M1:tabint; M2:tabint):boolean;
	var
		i,j:integer;
	begin
		ceksama:=true;
		for i:= 1 to N do
		begin 
			for j:= 1 to N do 
			begin
				if (M1[i,j]<>M2[i,j]) then 
				begin
					ceksama:=false;
				end 
			end;
		end;
	end;
	
	{algoritma utama}
begin
	write ('Masukan nilai N : '); readln(N);
	writeln('Matriks A');
	InputArray(N,A);
	writeln('Matriks B');
	InputArray(N,B);
	If ceksama(A,B) then
	begin
		writeln('Matriks B merupakan Matriks A yang diputar 0 derajat');
	end else
	begin
		RotasiArray(N,A);
		if ceksama(A,B) then 
		begin
			writeln('Matriks B merupakan Matriks A yang diputar 90 derajat');
		end else
		begin
			RotasiArray(N,A);
			if ceksama(A,B) then 
			begin
				writeln('Matriks B merupakan Matriks A yang diputar 180 derajat');
			end else
			begin
				RotasiArray(N,A);
				if ceksama(A,B) then 
				begin
					writeln('Matriks B merupakan Matriks A yang diputar 270 derajat');
				end else
				begin
					writeln ('Matriks B bukan Matriks A yang dirotasikan');
				end;
			end;
		end;
	end;
end.