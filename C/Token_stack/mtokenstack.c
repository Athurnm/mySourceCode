/* file : mtokenstack.c */
#include "kata.h"
#include "stack.h"

int convTokentoInt (Token ctoken)
{
	//kamus lokal
	int total=0;
	int i;
	//Algoritma lokal
	i = 1;
	for(;;)
	{
		int x = ctoken.tkn[i]-'0';
		total = total*10 + x;
		if (i>=ctoken.length)
		{
			break;
		}else
		{
			i++;
		}
	}
	return (total);
}

bool IsOperator (Token ctoken)
{
	int i=1; 
	if (ctoken.length = 1)
	{
		if (ctoken.tkn[i]=='+'||ctoken.tkn[i]=='-'||ctoken.tkn[i]=='*'||ctoken.tkn[i]=='/')
		{
			return(true);
		}else 
		{
			return(false);
		}
	}
}

int calculate (char C, int Op1, int Op2)
{
	//Kamus lokal
	int result = 0;
	//Algoritma lokal
	if (C =='+')
	{
		result = Op1+Op2;
	}else if (C == '-')
	{
		result = Op1-Op2;
	}else if (C == '*')
	{
		result = Op1*Op2;
	}else if (C == '/')
	{
		result = Op1/Op2;
	}
	return (result);
}

bool IsOperand (Token ctoken)
{
	return(!IsOperator(ctoken));
}
int main()
{
	//Kamus global
	Stack S;
	int op1,op2;
	//Algoritma
	STARTKATA();
	if(EndKata)
	{
		printf("Kosong \n");
	}else
	{
		while (!EndKata)
		{
			if (IsOperand(ctoken))
			{
				op1 = convTokentoInt(ctoken);
				Push (&S,op1);
			}else if (IsOperator(ctoken))
			{
				Pop(&S,&op2);
				if (!IsEmpty (S))
				{
					Pop(&S,&op1);
					Push(&S, calculate(ctoken.tkn[1],op1,op2));
				}else
				{
					printf("Error \n");
				}
			}
			ADVKATA();
		}
		//sudah mencapai EndKata
		Pop(&S,&op1);
	}
	printf("Hasil perhitungan = %d \n", op1);
	return 0;	
}

