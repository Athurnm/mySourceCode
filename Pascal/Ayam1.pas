Program AnakAyam;
{deklarasi}
Var
	i:integer; {jumlah anak ayam}
	n:integer;

{algoritma}
begin
	writeln('masukan jumlah anak ayam yang diinginkan'); read(n);
	i:= n;
	writeln('tekotek2 anak ayam turunlah ',n);
	repeat 
		i:=i-1;
		writeln('Mati satu tinggallah ', i);
	until (i<=1);
	writeln('mati satu tinggal induknya');
	readln();
	readln();
end.