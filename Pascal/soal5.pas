program HitungLuas;
{kamus}
var
	x1:integer; {batas bawah}
	x2:integer; {batas atas}
	delta:real;
	i:real;
	luas:real;
	luast:real;
	
	function f(x:real):real;
	{kamus lokal}
	//kosong
	{algoritma}
	begin
		f:= x*x +1;
	end;
	
	
	function luas_segmen(x:real):real;
	{kamus lokal}
	//kosong
	{algoritma}
	begin
		luas_segmen:= delta*(f(x)+f(x+delta))/2;
	end;
	
{algoritma}
begin
	write ('masukan x1 (batas kanan) dan x2 (batas kiri) : '); readln (x1); readln (x2);
	write ('masukan nilai delta : '); readln (delta);
	while (x1>x2) or (delta<=0)do
		begin
		writeln ('masukan salah! Ulangi kembali pemasukan');
		write ('masukan x1 (batas kanan) dan x2 (batas kiri) : '); readln (x1); readln (x2);
		write ('masukan nilai delta : '); readln (delta);
		end;
	if (x1<x2) and (delta>0) then
		begin
		i:= x1;
		luas:=0;
		while (i<x2) do 
			begin
			luas:= luas + luas_segmen(i);
			i:= i + delta;
			end;
		end;
	if (i>x2) then
		begin
		luast:= (i-x2)*(f(i)+f(x2))/2;
		luas:= luas - luast;
		end;
	writeln ('luas kurva = ', luas:0:2);
end.
			
			