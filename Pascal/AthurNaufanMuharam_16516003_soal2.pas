{
Nama/NIM	: Athur Naufan Muharam/16516003
Kelas PTI 	: 07
Fakultas 	: STEI
Soal 		: 02
}
Program hitungvokal;
{Program untuk menghitung jumlah huruf vokal yang diinput user}
{kamus}
var
	n: integer; {jumlah huruf yang akan dimasukan}
	count:integer; {jumlah huruf vokal}
	
	{Function}
	function IsVokal(i:char):boolean;
	{kamus fungsi}
	{algoritma fungsi}
	begin
		if (i = 'a') or (i = 'i') or (i = 'u') or (i = 'e') or (i = 'o') then 
			begin
				IsVokal:= true;
			end else 
			 begin
				IsVokal := false;
			 end;
	end;
	
	{procedure}
	procedure hitungvokal (n:integer; var count:integer);
	{kamus prosedur}
	var
		i: char;
		i1:integer; {increment}
	{algoritma prosedur}
	begin
		count:=0;
		for i1:= 1 to n do
			begin
				write ('masukan huruf kecil '); readln (i);
				if (IsVokal(i) = true) then 
					begin
						count:= count+1;
					end;
			end;
	end;
{algoritma}
begin
	write ('masukan jumlah huruf yang akan dimasukan '); readln (n);
	hitungvokal (n,count);
	writeln ('jumlah huruf vokal = ', count);
end.
	
	