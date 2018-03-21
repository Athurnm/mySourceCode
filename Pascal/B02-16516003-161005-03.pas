{ 
Nim/Nama: 16516003/Athur Naufan Muharam
Nama file: B01-16516003-161005-03.pas
Tanggal: 05 Oktober 2016
deskripsi: program menentukan apakah input bilangan prima
}
program prima;
{kamus}
var
	a:longint;{bilangan pertama}
	b:longint;{bilangan kedua}
	i1:integer;{increment}
	count:integer;{jumlah faktor dari bilangan 'ab'}
{algoritma}
begin
	write('Masukan nilai A : '); readln(a);writeln;
	write('Masukan nilai B : '); readln(b);writeln;
	{algoritma menambahkan angka a dan b}
	if (b>10000) then 
	begin 
		writeln ('ERROR angka melebihi 10000');
	end else if (b>1000) and (b<10000) and (a=0) then
		begin
			a:=b;
		end else if (b<1000) and (b>99) then 
			begin
				a:=a*1000+b;
			end else if (b<=99) and (b>9) then
				begin
					a:=a*100+b;
				end else {b<=9}
					begin
						a:=a*10+b;
					end;
	{algoritma menentukan prima atau tidak}
	if (a<10000) then 
	begin
		count:=0;
		for i1:=1 to a do
		begin 
			if (a mod i1 = 0) then 
			begin
				count:=count+1;
			end;
		end;
		if (count = 2) then 
		begin
			writeln (a, ' adalah bilangan prima');
		end else {count<>2}  
		begin 
			writeln(a, ' bukan bilangan prima');
		end;
	end else {a>100000} 
	begin
		writeln ('ERROR bilangan melebihi 10000');
	end;
end.
