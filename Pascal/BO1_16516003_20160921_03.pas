Program Alarm; {program untuk menentukan berapa lama tuan vin tertidur}
{kamus}
type
	jam=record
	hh:integer; {jam}
	mm:integer; {menit}
	ss:integer; {detik}
	end;
var
	Jam1:jam; {jam saat tertidur}
	jam2:jam; {jam akan bangun}
	sisa:integer; {sisa waktu}
	total1:longint;
	total2:longint;
	selisih:longint;
	pukulJ:integer; {lama tidur dalam jam}
	pukulm:integer; {lamatidur dalam menit}
	pukuls:integer; {lamatidur dalam detik}
	i:char;
	
{algoritma}
begin
	writeln('masukan jam sekarang : '); read(jam1.hh);
	writeln('masukan menit sekarang : '); read(jam1.mm);
	writeln('masukan detik sekarang : '); read(jam1.ss);
	writeln('masukan jam alarm : '); read(jam2.hh);
	writeln('masukan menit alarm : '); read(jam2.mm);
	writeln('masukan detik alarm : '); read(jam2.ss);
	total1:=jam1.hh*3600+jam1.mm*60+jam1.ss;
	total2:=jam2.hh*3600+jam2.mm*60+jam2.ss;
	if (total1>total2) then 
		begin selisih:= (24*3600-total1)+total2;
		end else {total1<=total2}
		begin selisih:=total2-total1;
	end;
	pukulj:= selisih div 3600;
	sisa:=selisih mod 3600;
	pukulm:=sisa div 60;
	pukuls:=sisa mod 60;
	write('tuan vin akan tertidur ',pukulj,' jam ',pukulm);
	writeln( ' menit dan ',pukuls,' detik');
	readln;
	readln;
	writeln('ingin mencoba lagi ? (y/n) '); read(i);
	while (i ='y') do
	begin
		writeln('masukan jam sekarang : '); read(jam1.hh);
		writeln('masukan menit sekarang : '); read(jam1.mm);
		writeln('masukan detik sekarang : '); read(jam1.ss);
		writeln('masukan jam alarm : '); read(jam2.hh);
		writeln('masukan menit alarm : '); read(jam2.mm);
		writeln('masukan detik alarm : '); read(jam2.ss);
		total1:=jam1.hh*3600+jam1.mm*60+jam1.ss;
		total2:=jam2.hh*3600+jam2.mm*60+jam2.ss;
		if (total1>total2) then 
			begin selisih:= (24*3600-total1)+total2;
			end else {total1<=total2}
			begin selisih:=total2-total1;
		end;
		pukulj:= selisih div 3600;
		sisa:=selisih mod 3600;
		pukulm:=sisa div 60;
		pukuls:=sisa mod 60;
		write('tuan vin akan tertidur ',pukulj,' jam ',pukulm);
		writeln( ' menit dan ',pukuls,' detik');
		readln;
		readln;
		writeln('ingin mencoba lagi ? (y/n) '); read(i);
	end;
end.
