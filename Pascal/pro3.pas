program pro3;
{kamus}
var
	i,n : integer;
	a,t,l:real;
	{procedure}
	procedure hitungluassegitiga (alas,tinggi: real; var l:real);
	begin
		l:= (alas*tinggi)/2;
	end;
{algoritma}
begin
	write('masukan jumlah segitiga yang ingin dihitung '); readln (N);
	for i:=1 to n do 
		begin
			writeln ('segitiga ke-',i);
			write('masukan alas segitiga = '); readln(a);
			write('masukan tinggi segitiga = '); readln (t);
			hitungluassegitiga (a,t,l);
			writeln ('luas segitiga ke-',i,' = ', l:0:2);
		end;
end.