Program hitungluassegitiga;
{kamus}
var
	i,N: integer;
	procedure hitungluassegitiga;
	var
		alas: real;
		tinggi: real;
		luas: real;
	begin
		write ('masukan alas segitiga '); readln(alas);
		write ('masukan tinggi segitiga '); readln (tinggi);
		Luas:=(alas*tinggi)/2;
		writeln ('luas segitiga: ',Luas:0:2);
	end;
begin
	write('berapa banyak segitiga yang mau dihitung? '); read(N);
	for i:=1 to N do
		begin
			writeln('luas segitiga ke-',i);
			hitungluassegitiga;
		end;
end.
	