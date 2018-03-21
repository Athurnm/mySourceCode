program cobasort;

type 
	T1 = array [1..100] of integer;
	
var
	T : T1;
	neff : integer;
	
procedure isiTab (var T2:T1; n:integer);
var
	i : integer;

begin
	for i:= 1 to n do 
	begin
		readln (T2[i]);
	end;
end;

procedure bubbleSort (var T2:T1;n:integer);
var
	k : integer;
	pass : integer;
	temp : integer;
	
begin
	if N>1 then 
	begin
		for pass := 1 to N-1 do 
		begin
			for k := N downto pass+1 do 
			begin
				if (T2[k]>T2[k-1]) then 
				begin
					temp := T2[k];
					T2[k] := T2[k-1];
					T2[k-1] := temp;
				end;
			end;
		end;
	end;
end;

procedure TulisArray (T2:T1;n:integer);
var
	i : integer;
	
begin
	for i:= 1 to n do 
	begin
		writeln (T2[i]);
	end;
end;

begin
	write ('masukan jumlah data : ');
	readln (neff);
	isiTab (T,neff);
	writeln ();
	TulisArray (T,neff);
	bubbleSort (T,neff);
	writeln ();
	TulisArray (T,neff);
end.