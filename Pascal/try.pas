Program inputNilai;
var
    i: Integer;
    a : string;
    skor   : real;
    
begin
    skor := 0.0;
	i:= 1;
    while i <=7 do
    begin
	   if i = 1 or i = 2 then
	   begin
		readln (a);
		case a of 
			'A' : skor := skor + 4*4.0 ;
			'AB': skor := skor + 4*3.5 ;
			'B': skor := skor + 4*3 ;
			'BC': skor := skor + 4*2.5 ;
			'C': skor := skor + 4*2 ;
			'CD': skor := skor + 4*1.5 ;
			'D': skor := skor + 4*1;
        else skor := skor;
		end;
	   end else
	   begin
		readln (a);
		case a of 
			'A' : skor := skor + 2*4.0 ;
			'AB': skor := skor + 2*3.5 ;
			'B': skor := skor + 2*3 ;
			'BC': skor := skor + 2*2.5 ;
			'C': skor := skor + 2*2 ;
			'CD': skor := skor + 2*1.5 ;
			'D': skor := skor + 2*1;
		end;
		end;
	i:= i + 1;
	end;
    writeln (skor:0:2);
end.