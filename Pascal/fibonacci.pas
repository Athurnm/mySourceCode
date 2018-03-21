Program fibonacci;
var
	a:integer;
	j:integer;
	i1,i2,i3:integer;
{algorithm}
begin
	write('Berapa banyak bilangan fibonacci yang ingin ditampilkan? a: '); readln(a);
	j:=1;
	i2:=0;
	i3:=1;
	for i1:=1 to a do 
		begin
		write(j,' ');
		j:=j+i2;
		i2:=i3;
		i3:=j;
		end;
	readln;
end.