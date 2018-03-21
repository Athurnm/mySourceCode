Program soal2; {program untuk menampilkan bilangan prima menggunakan file input/output}
var
	fout:file of integer;
	n:integer;
	i:integer;
	a:integer;
	count:integer;
	
	function cekprima (a:integer):boolean;
	{kamus}
	var
		i:integer;
		count:integer;
	{algoritma}
	begin
		count:=0;
		for i:= 1 to a do
		begin
			if (a mod i = 0) then
			begin
				count:=count+1;
			end;
		end;
		if (count=2) then
		begin
			cekprima:=true;
		end else
		begin
			cekprima:=false;
		end;
	end;
	
{algoritma}
begin
	assign(fout,'fout.dat');
	rewrite(fout);
	count:=0;
	Repeat
		write('Masukan Banyaknya bilangan : ');
		readln (N);
	until (N>=0);
	writeln('Masukan ',N,' bilangan tersebut : ');
	for i:= 1 to n do 
	begin
		readln (a);
		if (cekprima(a)) then
		begin
			write(fout,a);
			count:=count+1;
		end;
	end;
	close(fout);
	reset(fout);
	if (count>0) then 
	begin
		writeln('File berhasil dimasukan ke dalam fout.dat');
		writeln('Ada ',count,' bilangan prima yaitu: ');
		while(not(eof(fout))) do
		begin
			read (fout,a);
			writeln(a);
		end;
	end else
	begin
		writeln('Tidak ada data yang dapat dimasukan kedalam file');
	end;
	close(fout);
end.
	