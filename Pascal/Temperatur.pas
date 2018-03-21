Program Temperatur;
var
	fout: file of integer;
	temp,i,N: integer;
begin
	assign (fout, 'temperatur.dat');
	rewrite(fout);
	write('masukan jumlah data N, N>=0 '); readln (N);
	for i:= 1 to N do
	begin
		readln(temp);
		write(fout,temp);
	end;
	close(fout);
end.