program palindrome;
{kamus}
type 
	tabint=array [1..100] of char;
var
	T1:tabint;
	a:integer;
	
	procedure IsiArray (n:integer; var T:tabint);
	var
		i:integer;
	begin
		for i:= 1 to n do
			begin
			write ('masukan nilai ke-',i,' : '); readln (T[i]);
			end;
	end;
	
	function cekpalindrome (t:tabint;n:integer):boolean;
	var
		i:integer;
	begin
		cekpalindrome:=true;
		for i:= 1 to n do
			begin
			if (t[i]=t[n-(i-1)]) then
				begin
				cekpalindrome:=true;
			end else {t[i]<>t[n-(i-1)]}
				begin
				cekpalindrome:=false;
				end;
			end;
	end;
	
	procedure printarray (t:tabint; n:integer);
	var
		i:integer;
	begin
		for i:= 1 to n do
			begin
			write (t[i]);
			end;
	end;
	
{algoritma}
begin
	write ('masukan neff array : '); readln (a);
	isiarray(a,T1);
	writeln('kata yang diinput : '); printarray(t1,a);
	if (cekpalindrome (t1,a)) then
		begin
		writeln (' bilangan palindrome');
	end else 
		begin
		writeln (' bukan bilangan palindrome');
		end;
end.
	