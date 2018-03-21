program himpunan;
{file: himpunan.pas}
{kamus}
type
	hari = (senin,selasa,rabu,kamis,jumat,sabtu,minggu);
	weekday = set of hari;
var
	h: hari ;
	h3,h1,h2 : hari;
	w : weekday; 
{algoritma}
begin
	h2 := selasa ;
	h3:= succ (h2);
	h1 := pred (h2);
	for h:= senin to minggu do 
	begin 
		writeln ('selamat pagi ...');
		writeln ('ordinal : ', ord(h));
	end;
	case h1 of 
		senin : begin
					writeln ('senin');
				end;
		selasa :begin 
					writeln ('selasa');
				end;
		rabu :	begin
					writeln ('rabu');
				end;
		kamis : begin 
					writeln ('kamis');
				end;
		jumat : begin
					writeln ('jumat');
				end;
		else begin
				writeln ('tidak terdefinisi');
			end;
	end;
end.