/* automat.c */
#include <stdio.h>
#include <stdlib.h>

/* Software für einen Getränkeautomaten */

/* Funktion "angebot" zeigt das Angebot und ließt dieses ein. */ 

int angebot() { 
  int wahl;
  
  printf("\n");
  printf("Willkomen!\n\a");
  printf("Bitte wählen Sie ein Getränk:\n");
  printf("Bier(1)\n");
  printf("Cola(2)\n");
  printf("Fanta(3)\n");
  printf("Sprite(4)\n");
  printf("Stilles Wasser(5)\n");
  printf("Sprudelwasser(6)\n");
  printf("Malzbier(7)\n");
  printf("Energydrink(8)\n");
  scanf("%i", &wahl);		//Wahl einlesen
  printf("\nIhre Wahl: ");
  //printf("%i", wahl); //test
  return wahl;
}


/* Funktion "info" verarbeitet die Wahl indem sie, je nach Wahl, den Preis ausgibt. */ 

float info(wahl) {
   
 float preis = 0;
 //printf("%i",wahl); //test
 
switch(wahl) {
    case 0: printf("Beendet.\n");		//Wahl Null beendet Programm
	      exit(0);break;
    case 1: printf("Bier\n");
	      printf("Preis: 1.63 €\n");	//Preis ausgeben	
	      preis = 163;			//Variable preis zuweisen
	      break;
    case 2: printf("Cola\n");
	      printf("Preis: 1.43 €\n");
	      preis = 143;
	      break;
    case 3: printf("Fanta\n");
	      printf("Preis: 1.36 €\n");
	      preis = 136;
	      break;
    case 4: printf("Sprite\n");
	      printf("Preis: 2.72 €\n");
	      preis = 272;
	      break;
    case 5: printf("Stilles Wasser\n");
	      printf("Preis: 0.69 €\n");
	      preis = 69;
	      break;
    case 6: printf("Sprudelwasser\n");
	      printf("Preis: 1.05 €\n");
	      preis = 105;
	      break;
    case 7: printf("Malzbier\n");
	      printf("Preis: 2.09 €\n");
	      preis = 209;
	      break;
    case 8: printf("Energydrink\n");
	      printf("Preis: 2.99 €\n");
	      preis = 299;
	      break;
    default:printf("Bitte geben Sie eine gültige Zahl ein!\n");
	      main();
  }
  //printf("BREAKPOINT: PREIS IN FUNCTION info() = %f", preis);
  return preis;
}


  
/* In Funktion Main werdern die einzelnen Funktionen mit einer Schleife 
 * aufgerufen und wiederholt, wenn der Vorgang abgeschlossen ist */

int main() {
  
int wahl;
float preis;
float back;	//Rückgeld
float gezahlt;	//Bereits gezahlt
float ausstehend;	//Zu zahlen
float gezahlt2;	//Gerade bezahlt 
float preis2;	//Preis in Cent

while(1) {
	wahl = angebot(); //Aufruf Funktion  "angebot"
	preis2 = info(wahl); //Aufruf Funktion "info" ; Problem beim übertragen von Preis von "info" zu main
	printf(" PREIS IN FUNCTION MAIN VAR PREIS2: %f", preis2);
	preis = preis2 / 100;	// Umwandlung zu Dezimalbruch
	//printf("%.2f\n",preis); //test
	printf("\n");
	printf("Bitte bezahlen Sie %.2f €:\n", preis);
	//printf("%f\n", preis);
	scanf("%f", &gezahlt); //Einlesen der "Bezahlung"
	
	/* Endlosschleife läuft so lange bis Preis gleich gezahlt ist */
	
	while(1)
	{
		//Falls zu viel bezahlt:
		if(gezahlt > preis)
		{
			back = gezahlt - preis;
			printf("Rückgeld: %.2f €\n", back);
			break;
		}
		//Falls zu wenig bezahlt:
		else if(gezahlt < preis) {
			ausstehend = preis - gezahlt;
			printf("Bitte zahlen Sie %.2f €!\n", ausstehend);
			gezahlt = gezahlt + scanf("%f", &gezahlt2);
			continue;
		}
  //Falls passend:
  else {
    printf("Passt genau!");
    break;
  }
}
printf("Danke für ihren Einkauf!\n");
}
  return 0;
}
