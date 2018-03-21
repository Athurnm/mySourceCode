program databaseperpus; {program untuk menyimpan dan menyusun database di perpus}

{kamus}
type	
	database=record
	namabuku:string;
	no:integer;
	genre:string;
	end;
var
	db:database;
	
{algoritma}
begin
	writeln('masukan nama buku: '); readln(db.namabuku);
	writeln('masukan nomor ISBN: '); readln(db.no);
	writeln('masukan genre buku: '); readln(db.genre);
	write('buku bergenre ',db.genre,'dengan judul ',db.namabuku,'dengan nomor ISBN ',db.no, 'berhasil disimpan!');
	
	case (db.genre) of
		'Komedi': writeln ('buku tersebut terletak di lorong 1');
		'Romantis','horror' : writeln ('buku tersebut terletak di lorong 2');
		'pelajaran kelas 1','pelajaran kelas 2','pelajaran kelas 3': writeln('buku tersebut terletak di lorong 3');
	else writeln('genre tidak tersedia');
	end;
readln;
readln;
end.
		
