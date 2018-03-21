Program LatUAS141;
{kamus}
const
	IdxUndef = -99;
	Nmax = 100;
Var
	Tfasilitas : array[1..Nmax] of string;
	Neff:integer;
	Fasilitas:String;
	
	
	Procedure IsiTabel (Neff:integer; var TabString : array of string);
	{kamus lokal}
	var
		i:integer; {increment}
	Begin
		if Neff > 0 then 
		begin
			writeln('Tuliskan nama-nama fasilitas = ');
			for i:= 1 to Neff do
			begin
				readln (TabString[i]);
			end;
		end;
	end;
	
	Procedure PrintTabel (Neff:integer; TabString:array of string);
	{kamus lokal}
	var
		i:integer;
	begin
		if neff > 0 then
		begin
			writeln ('Isi tabel adalah sebagai berikut = ');
			for i:= 1 to neff do
			begin
				writeln ('I ',TabString[i],' I');
			end;
		end else
		begin
			writeln('Tabel kosong cok');
		end;
	end;
	
	Function SearchFasilitas (Fasilitas1:string):integer;
	{kamus lokal}
	var
		i:integer; found:boolean;
	begin
		found:= false;
		for i:=1 to neff do 
		begin
			if (Tfasilitas[i]=Fasilitas1) then
			begin
				SearchFasilitas:= i;
				writeln(' Fasilitas ', Fasilitas1,' terdapat pada indeks ke-',SearchFasilitas);
				found:= true;
			end;
		end;
		if not found then
		begin
			writeln (IdxUndef);
		end;
	end;
	
{algoritma utama}
begin
	write('Masukan Neff dari tabel (0<neff<100) = '); readln(neff);
	IsiTabel(neff,Tfasilitas);
	PrintTabel(neff,Tfasilitas);
	Write('Masukan Fasilitas yang ingin dicari : '); readln(fasilitas);
	SearchFasilitas(fasilitas);
end.
		
		