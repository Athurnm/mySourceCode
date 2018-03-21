program UTSUAS; 
{kamus}
var
	Uts:integer; {inputan nilai uts}
	uas:integer; {inputan nilai uas}
	i:integer; {increment}
	stop:boolean;
	akhir : integer; {nilai akhir}
	avg : integer; {nilai rata2}
	sum : integer; {total nilai akhir}
	
{algoritma}
begin
	i := 0;
	sum := 0;
	stop := false;
	repeat 
		write ('Nilai UTS = '); readln (uts);
		if (uts>100) or (uts<0) then 
		begin
			stop := True;
			if (i=0) then writeln ('Data kosong, tidak ada nilai rata-rata !');
		end else
		begin
			write ('Nilai UAS = '); readln (uas);
			while (uas>100) or (uas<0) do 
			begin
				writeln ('ulangi input nilai (0..100)!');
				write ('Nilai UAS = '); readln (uas);
			end;
			i := i+1 ; {next elemen}
			akhir := ((uts*2) div 5) + ((uas*3) div 5);
			writeln ('Nilai akhir pelajaran ', i, ' = ',akhir);
			sum := sum + akhir;
		end;
	until stop;
	if (i>0) then 
	begin
		avg := sum div i ;
		write ('Nilai rata-rata dari ',i,' pelajaran adalah = ', avg);
	end;
end.	
		