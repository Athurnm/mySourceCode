Program pangkat1; {program perpangkatan dalam for}
{kamus}
var
	i:Integer; {increment}
	a:integer; {bilangan yang akan dipangkatkan}
	N:integer; {Pangkat}
	P:integer; {hasil pangkat}

{algoritma}
Begin
	write ('Masukan bilangan dasar yang akan dipangkatkan : '); readln (a);
	write ('Masukan jumlah pangkat : '); readln(N);
	p:=1;
	for i:=1 to N do 
		begin
		p:=p*a;
		end;
	writeln ('hasil pangkat : ', p);
	readln;
end.