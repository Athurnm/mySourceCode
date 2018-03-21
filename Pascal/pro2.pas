Program pro2;
{kamus}
var
	i, N: integer;
	a, t: real;
	procedure hitungluassegitiga (alas,tinggi:real);
	var
		l: real;
	begin
		l:=(alas*tinggi)/2;
		writeln('luas segitiga = ', l:0:2);
	end;
begin
	write ('berapa banyak segitiga yang ingin dihitung '); readln (n);
	for i:=1 to N do 
		begin
			writeln ('luas segitiga ke -', i);
			write ('masukan alas segitiga '); readln (a);
			write ('masukan tinggi segitiga '); readln (t);
			hitungluassegitiga (a,t);
		end;
end.