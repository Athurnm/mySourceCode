Program soal4UAS;
{kamus}
Type
	TabChar = array [1..3,1..3] of char;
var
	M : TabChar;
	i,j:integer;
	s: char;
	
	Procedure InputMatriks (b:char; var A:TabChar);
	var
		i,j:integer;
	begin
		for i:= 1 to 3 do
		begin
			for j:= 1 to 3 do
			begin
				A[i,j]:= b;
			end;
		end;
	end;
	
	function CekMatriks(A:TabChar):boolean;
	var
		i,j:integer;
	begin
		CekMatriks:=false;
		for i:= 1 to 3 do
		begin
			for j:= 1 to 3 do 
			begin
				if (A[i,j]=' ') then 
				begin
					CekMatriks:=true;
				end;
			end;
		end;
	end;
	
	Procedure PrintMatriks (A:TabChar);
	var 
		i,j:integer;
	begin
		for i:= 1 to 3 do 
		begin
			for j:= 1 to 3 do
			begin
				write(A[i,j], ' ' );
			end;
			writeln();
		end;
	end;

{algoritma utama}
Begin
	InputMatriks(' ',M);
	readln(s);
	while S<>'#' do
	begin
		read(i); readln(j);
		M[i,j]:= s;
		readln(s);
	end;
	If CekMatriks(M) then 
	begin
		writeln ('Matriks belum penuh');
	end else
	begin
		PrintMatriks(M);
	end;
end.
	
		
	