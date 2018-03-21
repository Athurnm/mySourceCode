program menu;
var
	nomormenu:integer;
begin
	repeat
	writeln(' MENU ');
	writeln('1. Baca Data');
	writeln('2. Cetak Data');
	writeln('3. Ubah Data ');
	writeln('4. Hapus Data');
	writeln('5. Keluar program');
	writeln(' Masukan pilihan (1/2/3/4/5)');
	readln(nomormenu);
	case nomormenu of
		1: begin 
			writeln('anda memilih menu 1');
			end;
		2: begin
			writeln('anda memilih menu 2');
			end;
		3: begin
			writeln('anda memilih menu 3');
			end;
		4: begin
			writeln('anda memilih menu 4');
			end;
		5: begin
			writeln('anda memilih menu 5');
			end;
		else writeln('pilihan yang salah');
		end;
	until nomormenu = 5;
	readln;
end.