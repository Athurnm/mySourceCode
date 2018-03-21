Program GajiBersihKaryawan;{program untuk menghitung gaji bersih karyawan}

{kamus}
const PersentaseTunjangan = 0.2;
const PersentasePajak = 0.15;

var
Gajipokok,tunjangan,pajak,gajibersih: real;
namakaryawan: string; 

begin
writeln('masukan namakaryawan dan gajipokok');
readln(namakaryawan, gajipokok);
Tunjangan:=PersentaseTunjangan*gajipokok;
pajak:= PersentasePajak*(gajipokok+tunjangan);
Gajibersih := gajipokok+tunjangan-pajak;
write ('gaji bersih karyawan', gajibersih);
readln;
end.