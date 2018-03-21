program pak;
{kamus}
var
	a:integer;
	
	function faktorial(a:integer):integer;
	{kamus lokal}
	var
		i:integer;
	{algoritma}
	begin
		faktorial:= 1;
		for i:= 1 to a do
			begin
			faktorial:=faktorial*i;
			end;
	end;
{algoritma}
begin
	read (a); write('! = ');
	write (faktorial(a));
end.