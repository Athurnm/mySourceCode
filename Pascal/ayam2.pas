Program anakayam;
{deklarasi}
var
	i,n:integer;
begin
	writeln('masukan jumlah anak ayam yang diinginkan');read(n);
	i:=n;
	writeln('tekotek2 anakayam turun ',i);
	while (i>1) do 
		begin	
			i:=i-1;
			writeln('mati satu tinggal ',i,' ayam');
		end;
	writeln('Mati satu tinggal induknya');
	readln();
	readln();
end.