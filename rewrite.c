#include<stdio.h>

float bezahlt = 0;
float preis = 0;
int wahl = 0;


int bezahlvorgang(void)
{
	float temp_bezahlt = 0;
	while(bezahlt < preis)
	{
		printf("Noch %f€\n", preis - bezahlt);
		scanf("%f", &temp_bezahlt);
		bezahlt += temp_bezahlt;
		temp_bezahlt = 0;
	}
	if(bezahlt > preis)
	{
		printf("Du bekommst %f Rückgeld. Vielen Dank für ihren Einkauf\n", bezahlt - preis);
	}
	else
	{
		puts("Passt. Vielen Dank für ihren Einkauf.");
	}
}


int angebot(void)
{
	puts("1: Cola: 1,20€");
	puts("2: Bier: 2,00€");
	puts("3: Something Else: 2,50€");
	scanf("%i", &wahl);
	switch(wahl)
	{
		case 1:
			puts("Du hast Cola ausgewählt, bitte bezahle 1,20€"); /*Ineffizient. structs währen besser...*/
			preis = 1.20;
			bezahlvorgang();
			break;
		case 2:
			puts("Du hast Bier ausgewählt, bitte bezahle 2€");
			preis = 2;
			bezahlvorgang();
			break;
		case 3:
			puts("Sie haben irgendwas ausgewählt, bitte bezahle 2,50€");
			preis = 2.50;
			bezahlvorgang();
			break;
		default:
			puts("Beende Program");
			return 1;
	}
	return 0;
}


int main(void)
{
	puts("Welcome to Getränkeautomat software v2");
	for(;;)
	{
		angebot();
		preis = 0;
		bezahlt = 0;
	}
}


