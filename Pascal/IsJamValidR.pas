program isJamValidR;
{program untuk mengecek inputan user dan mengisi terus inputan sampai valid}
{kamus}
type 
	jam = record
		jj :integer;
		mm :integer;
		dd :integer;
		end;
var
	a,b,c: integer;
	j1 : jam;
	stop : boolean;

{algoritma}
begin
	stop := False;
	repeat
		readln (a);
		readln (b);
		readln (c);
		if (a>=0) and (a<=23) and (b>=0) and (b<=59) and (c>=0) and(c<=59) then 
		begin
			stop := True;
		end else
		writeln ('ERROR! Input kembali');
	until stop;
	j1.jj := a;
	j1.mm := b;
	j1.dd := c;
end.