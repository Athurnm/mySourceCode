Program CariPalindrome;{program untuk mencari bilangan palindrome}
{kamus}
type
	tabint=array[1..100]of integer;
var
	a:integer; {batas awal}
	b:integer; {batas akhir}
	i:integer; {increment}
	count:integer;
	T1:tabint;

	
	function IsPalindrome(x:integer):boolean;
	{kamus lokal}
	var
		temp:integer;
		invers:integer;
		lastdigit:integer;
		
	{algoritma}
	begin
		IsPalindrome:=false;
		temp:= x;
		invers:=0;
		while (x>0) do
			begin
			lastdigit:= x mod 10;
			invers:= invers*10 + lastdigit;
			x:= x div 10;
			end;
		if (invers=temp) then
			begin
			IsPalindrome:= true;
			end;
	end;
	
	procedure simpenkearray (i:integer; var T1:tabint);
	{kamus}
	var
		j:integer;
	{algoritma}
	begin
		for j:= 1 to 100 do
			begin
			T1[j]:= i;
			end;
	end;
	
	procedure CetakArray (a:integer; T1:tabint);
	var
		i:integer;
	{algoritma}
	begin
		for i:= 1 to a do
			begin
			writeln(T1[i]);
			end;
	end;		
	
{algoritma}
begin
	write ('masukan batas awal = '); readln (a);
	write ('masukan batas akhir = '); readln (b);
	count:=0;
	for i:= a to b do
		begin
		if (IsPalindrome(i)) then 
			begin 
			simpenkearray(i,T1);
			count:=count+1;
			end;
		end;
	if (count = 0) then 
		begin
		writeln (' Tidak ada bilangan palindrome pada range tersebut ');
	end else 
		begin
		writeln ('bilangan palindrome dari ',a, ' sampai ',b,' adalah = ');
		cetakarray(count,T1);
		end;
end.
	