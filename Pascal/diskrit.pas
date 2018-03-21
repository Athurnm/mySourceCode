Program sinyaldiskrit;
var
	n:integer;
	c:char;
	i:integer;
	f:integer;
	sum:integer;
	mean:real;
begin
	write('Input nilai n : '); readln (n);
	while (n<1) do {algoritma pengulangan input kalau n<1}
	begin
		write('Input salah, input nilai n : '); readln(n);
	end;
	writeln('magnitud sinyal diskrit anda : ');
	for i:=1 to n do
	begin
		f:=i*i +2*i;
		write(f, ' ');
	end;
	writeln();
	writeln('rata-rata sinyal diskrit anda : ');
	sum:=0;
	for i:=1 to n do
	begin
		f:=i*i + 2*i;
		sum:=sum+f;
	end;
	mean:= sum/n;
	writeln(mean:0:2);
	write('apakah anda ingin mengulang program (y/n) ? '); read(c);
	while (c = 'y') do 
	begin
		write('Input nilai n : '); readln (n);
		while (n<1) do {algoritma pengulangan input kalau n<1}
		begin
			write('Input salah, input nilai n : '); readln(n);
		end;
		writeln('magnitud sinyal diskrit anda : ');
		for i:=1 to n do
		begin
			f:=i*i +2*i;
			write(f, ' ');
		end;
		writeln('rata-rata sinyal diskrit anda : ');
		sum:=0;
		for i:=1 to n do
		begin
			f:=i*i + 2*i;
			sum:=sum+f;
		end;
		mean:= sum/n;
		writeln(mean:0:2);
		write('apakah anda ingin mengulang program (y/n) ? '); read(c);
	end;
	readln;
	readln;
end.
	