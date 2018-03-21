program trial;
type
	point = record
		x:integer;
		y:integer;
	end;
	T_point = array [1..10] of point;
var
	p1 : point;
	p2 : point;
	TP1 : T_point;
	TP2 : T_point;
	i: integer;
begin
	for i := 1 to 2 do 
	begin
		readln (TP1[i].x); readln (TP1[i].y);
		Tp2 [i] := TP1 [i];
	end;
	for i := 1 to 2 do 
	begin
		writeln (TP2[i].x); writeln (TP2[i].y);
	end;
end.