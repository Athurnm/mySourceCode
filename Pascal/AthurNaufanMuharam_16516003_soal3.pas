{
Nama/NIM	: Athur Naufan Muharam/16516003
Kelas PTI 	: 07
Fakultas 	: STEI
Soal 		: 03
}
program luaskurva;
{program untuk menghitung luas kurva dengan pecahan trapesium}
{kamus}
var
	a: real; {interval awal}
	b: real; {interval akhir}
	delta: real; {panjang interval}
	LuasT: real; {luas trapesium}
	LuasK: real; {luas kurva}
	
	{function}
	function F(x:real):real;
	{kamus fungsi}
	{algoritma fungsi}
	begin
		F:=x*x*x + x +1;
	end;
	
{algoritma}
begin
	write ('masukan nilai interval awal : '); readln (a);
	write ('masukan nilai interval akhir : '); readln (b);
	write ('masukan delta : '); readln (delta);
	luask:=0; 
	{menghitung luas kurva dengan pecahan trapesium}
	while (a<b) do
		begin
			luasT:= ((F(a)+F(a+delta))/2)*delta; {rumus luas trapesium}
			a:= a + delta;
			luasK:= luasK+luasT;
		end;
		{menghitung luas kurva yang kelebihan}
	if (a>b) then 
		begin
			luasT:= (a-b)*(F(a)+F(b))/2;
			luasK:= LuasK - LuasT;
		end;
	writeln ('luas kurva = ', LuasK:4:2);
end.
	