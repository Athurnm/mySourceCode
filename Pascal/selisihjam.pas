Program selisihWaktuSms;
{declaration}
Type 
	Jam=record
	jj: integer ;
	mm: integer;
	dd: integer;
end;
var
	J1s,j2s,sisa,selisihwaktu:integer;
	J1,J2,J3 : jam;

{algoritma}
begin
	write('masukan waktu pengiriman jam ='); read (j1.jj);
	write('menit ='); read(j1.mm);
	write('detik ='); read(j1.dd);
	writeln ('masukan waktu sampai (jam,menit,detik)') ;
	readln (j2.jj,j2.mm,j2.dd);
	J1s := j1.jj*3600+j1.mm*60+j1.dd;
	j2s := j2.jj*3600+j2.mm*60+j2.dd;
	selisihwaktu:=j2s-j1s;
	j3.jj:=selisihwaktu div 3600;
	sisa:=selisihwaktu mod 3600;
	j3.mm:=sisa div 60;
	j3.dd:=sisa mod 60;
	writeln ('selisih waktu sms = ',J3.jj,':',j3.mm,':',j3.dd);
	readln();
end.