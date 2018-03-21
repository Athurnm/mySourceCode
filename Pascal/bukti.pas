program bukti;
var
	a,b: real;
	luas: real;
	
	Function F(x:real):real;
	begin
		F:=(1/3)*x*x*x+x;
	end;

Begin
	readln (a);
	readln (b);
	luas := F(b)-F(a);
	writeln ('luas = ', luas:4:2);
end.