program NilaiMahasiswa;
{kamus}
type
	TabInt = array [1..100] of integer;
var
	T1: tabint; neff1:integer;
	T2: tabint; neff2:integer;
	x: integer; {batas nilai}
	i:integer; {increment}
	
	function CountLebihBesar(x:integer;neff:integer;t:tabint):integer;
	{kamus lokal}
	var
		i:integer; {increment}
	{algoritma}
	begin
		CountLebihBesar:=0;
		for i:= 1 to neff do
			begin
			if (t[i]>x) then 
				begin
				CountLebihBesar:=CountLebihBesar+1;
				end;
			end;
	end;
	
	procedure CopyNilai (t1:tabint; neff1:integer; x:integer; var t2:tabint);
	{kamus lokal}
	var
		i :integer;
		j: integer;
	{algoritma}
	begin
	j:= 1;
	for i:= 1 to neff1 do 
		begin
		if (t1[i]>x) then 
			begin
			t2[j]:=t1[i];
			j:=j+1;
			end;
		end;	
	end;
	
	procedure PrintArray (tab:tabint; neff:integer);
	{kamus lokal}
	var
		i:integer;
	{algoritma}
	begin
	for i:= 1 to neff do
		begin
		writeln (tab[i]);
		end;
	end;
	
{algoritma}
begin
	write('masukan nilai neff: '); readln (neff1);
	write('masukan batas nilai lulus: '); readln (x);
	writeln ('masukan nilai siswa pada line berikut = ');
	for i:= 1 to neff1 do
		begin
		readln (T1[i]);
		end;
	neff2 := CountLebihBesar(x,neff1,T1);
	if (neff2 <> 0) then 
		begin
		CopyNilai (T1, neff1, x, T2);
		writeln ('Banyaknya nilai yang lulus = ', neff2);
		writeln ('daftar nilai yang lulus = ');
		PrintArray(T2,neff2);
	end else {neff2=0}
			begin
			writeln ('Tidak ada yang lulus');
			end;
end.
			