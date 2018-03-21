Program prak4;
{kamus}
Type
	TabInt=array[1..100] of integer;
vsr
	t:tabint;
	i:integer;
	j:integer;
	menu:integer;
	
	{procedure menampilkan menu}
	procedure mainmenu ();
	{kamus lokal}
	//kosong
	{algoritma}
	begin
		writeln();
		writeln('Pilihan menu: ');
		writeln('1. Masukan nilai ke tabel');
		writeln('2. Tampilkan Tabel');
		writeln('3. Mengubah isi Tabel');
		writeln('4. Menukar isi Tabel');
		writeln('5. menjumlahkan isi tabel yang ganjil');
		writeln('6. menampilkan bilangan palindrome');
		writeln('7. Exit.');
		write('Pilihan : ');
	end;
	
	{prosedur masukan nilai ke array}
	Procedure InputN(Var a:tabint; var i:integer);
	{kamus lokal}
	//kosong
	{algoritma}
	begin
		write('Masukkan sebuah nilai x (0<=x<=10000) : '); readln(a[i]);
		while (a[i]>10000) or (a[i]<0) do
		begin
			write('Masukkan sebuah nilai x (0<=x<=10000) : '); readln(a[i]);
		end;
		i:=i+1;
		writeln('Data berhasil dimasukan ke dalam tabel');
	end;
	
	{prosedur tampilkan tabel}
	procedure PrintN(a:tabint,i:integer);
	var
		j:integer;
	begin
		writeln ('Tabel memiliki ',i,' buah nilai yaitu : ');
		for j:= 1 to i do 
		begin
			writeln (a[j]);
		end;
	{prosedur mengubah isi array}
	procedure ChangeN(t:tabint,i:integer);
	{kamus lokal}
	var
		a:integer;
		b:integer;
	{algoritma lokal}
	begin
		write('masukan indeks tabel yang ingin anda ubah : '); readln(a);
		write('masukan sebuah nilai x (0<=x<=10000) : '); readln(b);
		while (b<0) or (b>10000) do
		begin
			writeln ('Masukan ERROR!! Masukan kembali nilai x!');
			readln(b);
		end;
		if (a>0) and (a<=i)then 
		begin
			t[a]:=b;
			writeln ('Data pada indeks ke ',a,' berhasil diubah');
		end else
		begin
			writeln('Data ERROR!! Indeks tidak tersedia');
		end;
	end;