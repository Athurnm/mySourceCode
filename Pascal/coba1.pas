{
Headings
}
Program PrimaPrima;
{kamus}
var
	M: integer; {range}
	N: integer; {range}
	a:integer; {increment bilangan 1}
	b: integer; {increment bil 2}
	c: integer;
	d: integer;
	pp: boolean;
	
	
	{Fungsi Prima}
	function Prima(a:integer):boolean;
	{kamus lokal}
	var
		count: integer; {faktor}
		i: integer; {increment}
		
	{algoritma}
	begin
		count:= 0;
		for i:=1 to a do
		begin
			if (a mod i = 0) then 
			begin
				count:= count+1;
			end;
		end;
		if (count=2) then 
		begin
			prima:= true;
		end else {count<>2} 
		begin
			prima:= false;
		end;
	end;
	
	{fungsi ndigit}
	function ndigit(x:integer):integer;
	{kamus lokal}
	var
		a: integer;
	{algoritma}
	begin
		a:=0;
		while x>0 do
		begin
			a:=a+1;
			x:= x div 10;
		end;
		ndigit:= a;
	end;
	
	{fungsi menyatukan dua bilangan}
	function ntotal (a,c:integer):integer;
	{kamus lokal}
	var
		i: integer; {increment}
	{algoritma}
	begin
		for i:= 1 to c do 
		begin
			a:= a*10;
		end;
		ntotal:= a;
	end;
	
{algoritma}
begin
	pp:= true;
	write ('Masukan nilai range A dan B : '); read(M); readln (n);
	for a:= m to n do
	begin
		for b:= m to n do
		begin
			if prima(a) and prima(b) then
			begin
				c:= ndigit(b);
				d:= ntotal(a,c)+b;
				if prima(d) then 
				begin
					writeln (a, ' ' , b);
					pp:=false;
				end;
			end;
		end;
	end;
	if pp then 
	begin
		writeln ('TIDAK ADA');
	end;
end.
	
	