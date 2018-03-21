program matkul;
{kamus}
const
	Nmax = 100;
	
type 
	Matkul1 = record
		KodeMK : string;
		NamaMK : string;
		pengajar : string;
		jmlPeserta : integer;
	end;
	
	TabMatkul = record
		TM : array [1..100] of Matkul1;
		Neff : integer;
	end;
	
var
	TabM : TabMatkul;
	P : string;
	asc : boolean;
	x : string;
	n: integer;
	
function pengajarMK (P:string; T1:TabMatkul):integer;
// I.S. : TabMatkul terdefinisi, TabMatkul mungkin kosong
// F.S. : indeks nama pengajar yang dicari, jika tidak ada atau kosong
{kamus lokal}
var
	i : integer;
	iFound : integer;
{algoritma lokal}
// Algoritma searching tanpa boolean
begin
	if (T1.neff > 0) then 
	begin
		ifound := 0;
		for i := 1 to T1.Neff do 
		begin
			if (T1.TM[i].pengajar = p) then 
			begin
				ifound := i ;
			end;
		end;
		pengajarMK := ifound;
	end else // T1.neff = 0 
	begin
		pengajarMK := 0;
	end;
end;

procedure writeKuliahKosong (T1 : TabMatkul);
// I.S. : T1 Terdefinisi, T1 mungkin kosong 
// F.S. : menuliskan ke layar kodeMK, namaMK, dan Pengajar untuk jmlPeserta = 0
{kamus lokal}
var
	i : integer;	
{algoritma lokal}
begin 
	if (T1.neff > 0) then 
	begin
		for i := 1 to T1.neff do 
		begin
			if (T1.TM[i].jmlPeserta = 0) then 
			begin 
				write ('Kode Mata Kuliah : '); writeln (T1.TM[i].KodeMK);
				write ('Nama Mata Kuliah : '); writeln (T1.TM[i].NamaMK);
				write ('Nama Pengajar : '); writeln (T1.TM[i].pengajar);
			end;
		end;
	end else // T1.neff = 0
	begin
		writeln ('Tidak ada data');
	end;
end;

procedure updateMatkul (var T1:TabMatkul; N:integer);
// I.S. : T1 terdefinisi, T1 mungkin kosong. N terdefinisi >= 0
// F.S. : Jmlpeserta pada T1 terupdate menjadi N-peserta
{kamus lokal}
var
	i : integer;
{Algoritma lokal}
begin	
	if (T1.neff > 0) then 
	begin
		//inisialisasi
		i := 1 ;
		while (i <= T1.neff) do 
		begin
			T1.TM[i].jmlPeserta := N ;
			i := i + 1; // nxt element
		end;
	end else //T1.neff = 0 
	begin
		writeln ('Tidak ada data');
	end;
end;

procedure sortJmlPeserta (var T1:TabMatkul; asc:boolean);
// I.S. : T1 terdefinisi acak tak terurut, T1 mungkin kosong. asc bernilai true maka terurt menaik
// F.S. : T1 terurut
{kamus lokal}
var
	i : integer;
	pass : integer;
	temp : matkul1;
	imax : integer;
	imin : integer;
{algoritma lokal}
//sorting dengan algoritma selection sort
begin 
	if (T1.neff > 1) then 
	begin
		if not (asc) then // asc false, urut mengecil
		begin
			for pass := 1 to (T1.neff-1) do 
			begin
				imax := pass ;
				for i := pass+1 to T1.neff do 
				begin
					if (T1.TM[i].jmlPeserta > T1.TM[imax].jmlPeserta) then 
					begin
						imax := i;
					end;
				end;
				temp := T1.TM[imax];
				T1.TM[imax] := T1.TM[pass];
				T1.TM [pass] := temp;
			end;
		end else 
		begin
			for pass := 1 to (T1.neff -1) do 
			begin
				imin := pass;
				for i := pass+1 to T1.neff do 
				begin
					if (T1.TM[i].jmlPeserta < T1.TM[imin].jmlPeserta) then 
					begin
						imin := i;
					end;
				end;
				temp := T1.TM[imin];
				T1.TM [imin] := T1.TM[pass];
				T1.TM[pass] := temp;
			end;
		end;
	end;
end;
				
				
procedure isiTabMatKul (var T1:TabMatkul);
//I.S. : TabMatkul mungkin kosong, mungkin isi.
//F.S. : TabMatkul diisi
{kamus}
var
	i : integer;
	a : string;
{algoritma lokal}
begin
	if (T1.neff < Nmax) and (T1.neff >= 0) then 
	begin
		i := T1.neff+1;
		readln (a);
		while (i < Nmax) and (a <> 'XX9999' ) do 
		begin
			readln (T1.TM[i].NamaMK);
			readln (T1.TM[i].Pengajar);
			readln (T1.TM[i].jmlPeserta);
			T1.TM[i].KodeMK := a;
			i := i+1;
			readln (a);
		end;
		T1.neff := i;
	end else // T1.neff maksimum
	begin
		writeln ('Tabel Penuh');
	end;
end;

procedure print (T1:TabMatkul);
var
	i:integer;
begin
	for i := 1 to T1.neff do 
	begin
		write ('Nomor : ');
		writeln (i);
		write ('Kode Mata Kuliah : ');
		writeln (T1.TM[i].KodeMK);
		write ('Nama Mata Kuliah : ');
		writeln (T1.Tm[i].NamaMK);
		write ('Nama Pengajar : ');
		writeln (T1.TM[i].pengajar);
		write ('jumlah peserta : ');
		writeln (T1.TM[i].jmlpeserta);
	end;
	writeln ('DONE!!');
end;

{algoritma utama}
begin
	write ('Masukan jumlah data : ');
	readln (TabM.neff);
	isiTabMatKul (TabM);
	writeKuliahKosong (TabM);
	write ('Masukan nama pengajar yang ingin dicari : ');
	readln (p);
	writeln ('Pengajar yang anda cari berada pada indeks ke-',pengajarMK (p,tabm));
	write ('Masukan banyaknya jml peserta : ');
	readln (N);
	writeKuliahKosong (TabM);
	writeln ('pilih sortir, membesar atau mengecil : ');
	readln (x);
	if (x = 'besar') then 
	begin
		asc := True;
	end else if (x = 'kecil') then
	begin
		asc := false;
	end;
	sortJmlPeserta (TabM,asc);
	if (TabM.neff = 0) then 
	begin
		writeln ('Data kosong');
	end else 
	begin
		print (TabM);
	end;
end.
		
	
