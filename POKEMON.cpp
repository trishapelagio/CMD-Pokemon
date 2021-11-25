/*  
	Programmed by : Trisha Gail P. Pelagio , S11A
	Description: This program is a pokemon game which includes fighting, healing and switching between pokemons
	Last modified: 11/16/2018
	[Acknowledgements : 
		delay function taken from: https://c-for-dummies.com/blog/?p=69 // ]
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>


void opponent_print();
void bulbasaur_print();
void bellsprout_print();
void oddish_print();
void charmander_print();
void ninetails_print();
void ponyta_print();
void squirtle_print();
void psyduck_print();
void seel_print();
void print_status(int, int);
void delay(int);
void HPBar(int,int);
int pokAttackType(int, int*);
int OpokAttackType(int, int*);
int initial_ap(int);
int initial_hp(int);
void pokemon_name(int);
void pokemon_print(int);
int rand_OPok(int ,int ,int);
int rand_opponent_pok(int, int, int);
int randomA(int, int);
int HitMiss(int);
void swap(int*, int*, int*);
float effectiveness(int, int);
int accuracy(int, int);
int rand_oact();

int main()
{

	int Pok1, Pok2, Pok3, HP1, HP2, HP3, OPok1, OPok2, OPok3, SOPok, SPok, SAP, SHP, SOHP, SOAP, act, oact;
	int PowerPoints,  Hit, A, OPowerPoints, Accuracy, OAccuracy, attacktype, oattacktype,Attack, OHit, OA, OAttack;
	int swapchoice, Pok1AP, Pok1HP, Pok2AP, Pok2HP, Pok3AP, Pok3HP, OPok1AP, OPok1HP, OPok2AP, OPok2HP, OPok3AP, OPok3HP, SPokError, SOPokError;
	int oswapchoice, difficulty, end, turn, oturn;
	float Effectiveness, OEffectiveness;
	char trainer[256], opponent[256], dump;
	system("COLOR 0E");
	printf("\n\n\n                                  ,'\\\n");
	printf("    _.----.        ____         ,'  _\\   ___    ___     ____\n");
	printf("_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`.\n");
	printf("\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |\n");
	printf(" \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |\n");
	printf("   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |\n");
	printf("    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |\n");
	printf("     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |\n");
	printf("      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |\n");
	printf("       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |\n");
	printf("        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |\n");
	printf("                                `'                            '-._|\n\n");
	printf("		|)          _|_  ,_  o  ,  |)    _, \n");
	printf("	 	|/\\_|  |     |  /  | | / \\_|/\\  / |  , \n");
	printf("	 	 \\/  \\/|/    |_/   |/|/ \\/ |  |/\\/|_/\n");
	printf("	 	      (|                             \n");
	printf ("\n\n\n  	               Press Any Key to Play!");
	getch();
	system("cls");
	system("COLOR 0A");
	printf ("\n            What is your name, trainer?\n            ");
	scanf ("%s", &trainer);
	printf ("\n            What is your opponent's name?\n            ");
	scanf ("%s", &opponent);
	while (1)
	{
	printf ("\n\n                Choose a level. \n");
	do {
	printf ("                Level [1] Easy \n                Level [2] Hard\n\n                Enter Number: ");
	scanf ("%d", &difficulty);
	scanf ("%c", &dump); } while (difficulty!=1&&difficulty!=2);
	system ("cls");
	if (difficulty==1)
	{
	system ("COLOR 0D");
	printf ("\n\n");
	printf ("			Type               HP         AP\n\n");
	printf ("			GRASS \n\n");
	printf ("		1   Bulbasaur             160        40\n");
	printf ("		2   Bellsprout            140        60\n");
	printf ("		3   Oddish                150        50\n");
	printf ("			FIRE\n\n");
	printf ("		4   Charmander             25        70\n");
	printf ("		5   Ninetails             130        50\n");
	printf ("		6   Ponyta                140        60\n");
	printf ("			WATER \n\n");
	printf ("		7   Squirtle              180        20\n");
	printf ("		8   Psyduck               170        40\n");
	printf ("		9   Seel                  150        50\n\n");
	printf ("			Trainer %s, choose 3 pokemons!\n\n", trainer);

	//user's pokemon choice//
	do
	{
	printf ("            	 Pokemon 1:");
	scanf ("%d", &Pok1);
	scanf ("%c", &dump);}
	while (Pok1!=1&&Pok1!=2&&Pok1!=3&&Pok1!=4&&Pok1!=5&&Pok1!=6&&Pok1!=7&&Pok1!=8&&Pok1!=9);
	do
	{
	printf ("            	 Pokemon 2:");
	scanf ("%d", &Pok2);
	scanf ("%c", &dump);}
	while (Pok1==Pok2||(Pok2!=1&&Pok2!=2&&Pok2!=3&&Pok2!=4&&Pok2!=5&&Pok2!=6&&Pok2!=7&&Pok2!=8&&Pok2!=9));
	do
	{
	printf ("            	 Pokemon 3:");
	scanf ("%d", &Pok3);
	scanf ("%c", &dump);}
	while (Pok3==Pok1 || Pok3 == Pok2||(Pok3!=1&&Pok3!=2&&Pok3!=3&&Pok3!=4&&Pok3!=5&&Pok3!=6&&Pok3!=7&&Pok3!=8&&Pok3!=9));
	system ("cls");

	system ("COLOR 0C"); //change screen text to red//
	opponent_print();
	printf ("\n    Oh no! Trainer %s has challenged you! Press any key to fight!", opponent);
	getch();
	system ("cls");
	system ("COLOR 0A"); //change screen text to green//
	
	//random computer pokemon pick//
	srand (time(NULL));
	OPok1 = rand()%9+1;
	while ((OPok1==Pok1)||(OPok1==Pok2)||(OPok1==Pok3))
	{ OPok1=rand()%9+1;}
	
	OPok2 = rand()%9+1;
	while ((OPok2==Pok1)||(OPok2==Pok2)||(OPok2==Pok3)||(OPok2==OPok1))
	{ OPok2=rand()%9+1;}
	
	OPok3 = rand()%9+1;	
	while ((OPok3==Pok1)||(OPok3==Pok2)||(OPok3==Pok3)||(OPok3==OPok2)||(OPok3==OPok1))
	{ OPok3= rand()%9+1;}
	//show user pokemons and opponent pokemons//
	pokemon_print(OPok1);
	printf ("\nTrainer %s's pokemons are...      ",opponent );
	printf("\n                      ");
	pokemon_name(OPok1);
	printf ("\n			    Press any key to continue.....");
	getch();
	system ("cls");
	pokemon_print(OPok2);
	printf("                      ");
	pokemon_name(OPok2);
	printf ("\n			    Press any key to continue.....");
	getch();
	system ("cls");
	pokemon_print(OPok3);
	printf("                      ");
	pokemon_name(OPok3);
	printf ("\n			    Press any key to continue.....");
	getch();
	system ("cls");
	printf ("\n                     What Pokemon would you like to use first?\n");
	printf("                      ");
	printf ("1: ");
	pokemon_name(Pok1);
	printf ("\n");
	pokemon_print(Pok1);
	printf ("\n			    Press any key to continue.....");
	getch();
	system ("cls");
	printf("                      ");
	printf ("\n2: ");
	pokemon_name(Pok2);
	printf ("\n");
	pokemon_print(Pok2);
	printf ("\n			    Press any key to continue.....");
	getch();
	system ("cls");
	printf("                      ");
	printf ("\n3: ");
	pokemon_name(Pok3);
	printf ("\n");
	pokemon_print(Pok3);
	do
	{
	printf ("\n\n            Enter [1] ");
	pokemon_name(Pok1);
	printf (" [2] ");
	pokemon_name(Pok2);
	printf (" [3] ");
	pokemon_name(Pok3);
	printf (" : ");
	scanf ("%d", &SPok);
	scanf ("%c", &dump);
	} while (SPok!=1&&SPok!=2&&SPok!=3);
	//transfer value to Starter Pokemon//
	if (SPok==1)
	SPok=Pok1;
	else if(SPok==2)
	SPok=Pok2;
	else if(SPok==3)
	SPok=Pok3;
	system("cls");
	printf ("\n               Your starter pokemon is .....\n");
	pokemon_print(SPok);
	printf("                      ");
	pokemon_name(SPok);
	printf ("\n            Press any key to continue...");
	getch();
	system ("cls");
	printf ("			    Your enemy's starter pokemon is.....\n");
	SOPok = rand_OPok(OPok1, OPok2, OPok3);
	pokemon_print(SOPok);
	printf("                      ");
	pokemon_name(SOPok);
	printf ("\n			    Press any key to continue.....");
	getch();
	system ("cls");
	
	//initialize the hp/ap values for all chosen pokemons//
	turn = 0;
	oturn = 0;
	
	SHP=initial_hp(SPok);
	SAP=initial_ap(SPok);
	
	SOAP = initial_ap(SOPok);
	SOHP = initial_hp(SOPok);
	
	Pok1AP = initial_ap(Pok1);
	Pok1HP = initial_hp(Pok1);
	Pok2AP = initial_ap(Pok2);
	Pok2HP = initial_hp(Pok2);
	Pok3AP = initial_ap(Pok3);
	Pok3HP = initial_hp(Pok3);
	
	OPok1AP = initial_ap(OPok1);
	OPok1HP = initial_hp(OPok1);
	OPok2AP = initial_ap(OPok2);
	OPok2HP = initial_hp(OPok2);
	OPok3AP = initial_ap(OPok3);
	OPok3HP = initial_hp(OPok3);
	
	do
	{

	system ("COLOR 0C");
	delay(1000);
	if (end!=1&&turn!=2)
	{
	turn = 0;
	do {
	pokemon_print(SPok);
	print_status(SHP, SOHP);
	printf ("               ");
	pokemon_name(SPok);
	printf ("'s HP \n");
	HPBar(SHP, initial_hp(SPok));
	delay (1000);
	printf ("Your turn!\n");
	delay (1000);
	printf ("What do you want ");
	pokemon_name(SPok);
	printf(" to do?\n1. Attack  2. Use a potion 3. Switch.\n\n");
	do{
	printf ("Enter Number: ");
	scanf (" %d", &act); } while (act!=1&&act!=2&&act!=3);
	printf("\n");

	//attack action//
	if (act==1)
	{
	PowerPoints = pokAttackType(SPok, &attacktype);
	Accuracy = accuracy(SPok, attacktype);
	Hit = HitMiss(Accuracy);
	Effectiveness = effectiveness(SPok, SOPok);
	A = randomA(PowerPoints, SAP);
	Attack = A * Hit * Effectiveness;
	printf("You have dealt %d damage to ", Attack);
	pokemon_name(SOPok);
	SOHP-=Attack;
	if (SOHP>0)
	{
	printf("\nOpponent's HP is now %d.\nIt is now his turn.\n\n", SOHP);
	oturn=0;	
	}
	if (SOHP<=0)
	{	
		SOHP=0;
		if ((OPok2HP>0&&OPok3HP>0)||(OPok1HP>0&&OPok2HP>0)||(OPok3HP>0&&OPok1HP>0))
		{
		printf ("\n");
		pokemon_name(SOPok);
		printf (" has fainted! \nTrainer %s is chooosing a pokemon. \n\n", opponent );

		while(SOHP == 0){
		oswapchoice = rand()%3+1;
		SOPokError = SOPok;
		if (oswapchoice==1)
		{
			if (OPok2==SOPok&&OPok1HP>0)
			{
				printf ("\nTrainer %s swapped ", opponent);
				pokemon_name(SOPok);
				swap (&SOPok, &OPok2, &OPok1);
				swap (&SOHP, &OPok2HP, &OPok1HP);
				printf ("\n");
			}
			else if (OPok3==SOPok&&OPok1HP>0)
			{
				printf ("\nTrainer %s swapped ", opponent);
				pokemon_name(SOPok);
				swap (&SOPok, &OPok3, &OPok1);
				swap (&SOHP, &OPok3HP, &OPok1HP);
				swap (&SOAP, &OPok3AP, &OPok1AP);
				printf (" to ");
				pokemon_name(SOPok);
				printf ("\n");
			}
			else 
			{
			oswapchoice = rand()%3+1;
			}
			
		}
		else if (oswapchoice==2)
		{
			if (OPok1==SOPok&&OPok2HP>0)  
			{
				printf ("\nTrainer %s swapped ", opponent);
				pokemon_name(SOPok);
				swap (&SOPok, &OPok1, &OPok2);	
				swap (&SOHP, &OPok1HP, &OPok2HP);
				swap (&SOAP, &OPok1AP, &OPok2AP);
				printf (" to ");
				pokemon_name(SOPok);
				printf ("\n");			
			}
			else if (OPok3==SOPok&&OPok2HP>0)
			{
				printf ("\nTrainer %s swapped ", opponent);
				pokemon_name(SOPok);
				swap (&SOPok, &OPok3, &OPok2);
				swap (&SOHP, &OPok3HP, &OPok2HP);
				swap (&SOAP, &OPok3AP, &OPok2AP);
				printf (" to ");
				pokemon_name(SOPok);
				printf ("\n");
			}
			else 
			{
			oswapchoice = rand()%3+1;
			}
		}
		else if (oswapchoice==3)
		{
			if (OPok1==SOPok&&OPok3HP>0)  
			{
				printf ("\nTrainer %s swapped ", opponent);
				pokemon_name(SOPok);
				swap (&SOPok, &OPok1, &OPok3);	
				swap (&SOHP, &OPok1HP, &OPok3HP);
				swap (&SOAP, &OPok1AP, &OPok3AP);
				printf (" to ");
				pokemon_name(SOPok);
				printf ("\n");			
			}
			else if (OPok2==SOPok&&OPok3HP>0)
			{
				printf ("\nTrainer %s swapped ", opponent);
				pokemon_name(SOPok);
				swap (&SOPok, &OPok2, &OPok3);	
				swap (&SOHP, &OPok2HP, &OPok3HP);
				swap (&SOAP, &OPok2AP, &OPok3AP);
				printf (" to ");
				pokemon_name(SOPok);
				printf ("\n");
			}
			else 
			{
			oswapchoice = rand()%3+1;
			}
			
		}
		oturn=1;
	}
	}
	else 
	{
	printf("\nOpponent's HP is now O.");
	end = 1;
	}
	}
	turn =1;
	}

	
	else if (act==2)
	{
		if (SHP+20<initial_hp(SPok))
		{
		SHP = SHP + 20;
		printf ("\nYou have healed ");
		pokemon_name(SPok);
		printf (" by 20 HP. Your HP is now %d.\n", SHP);
		}
		else
		{
		pokemon_name(SPok);
		printf (" is now full HP.\n");
		SHP = initial_hp(SPok);
	}
	oturn=0;
	turn = 1;
	}
	else if (act==3)
	{
	if ((Pok2HP>0&&Pok3HP>0)||(Pok1HP>0&&Pok2HP>0)||(Pok3HP>0&&Pok1HP>0))
	{
		oturn=0;
		printf ("\nWhat Pokemon do you want to use?\n");
		printf ("1: ");
		pokemon_name(Pok1);
		if (SPok==Pok1)
		printf (" %d HP", SHP);
		else
		printf (" %d HP", Pok1HP);
		printf ("\n2: ");
		pokemon_name(Pok2);
		if (SPok==Pok2)
		printf (" %d HP", SHP);
		else
		printf (" %d HP", Pok2HP);
		printf ("\n3: ");
		pokemon_name(Pok3);
		if (SPok==Pok3)
		printf (" %d HP", SHP);
		else
		printf (" %d HP\n", Pok3HP);
	do
	{
		SPokError = SPok;
		do {
		printf ("\nEnter number:");
		scanf (" %d", &swapchoice); }
		while (swapchoice!=1&&swapchoice!=2&&swapchoice!=3);
		if (swapchoice==1)
		{
			if (Pok1==SPok)  
			{
				printf ("You are currently using this pokemon, invalid choice.\n");
			}
			else if (Pok2==SPok&&Pok1HP>0)
			{
				printf ("\nYou have swapped ");
				pokemon_name(SPok);
				swap (&SPok, &Pok2, &Pok1);
				swap (&SHP, &Pok2HP, &Pok1HP);
				swap (&SAP, &Pok2AP, &Pok1AP);
				printf (" to ");
				pokemon_name(SPok);
				printf ("\n");
			}
			else if (Pok3==SPok&&Pok1HP>0)
			{
				printf ("\nYou have swapped ");
				pokemon_name(SPok);
				swap (&SPok, &Pok3, &Pok1);
				swap (&SHP, &Pok3HP, &Pok1HP);
				swap (&SAP, &Pok3AP, &Pok1AP);
				printf (" to ");
				pokemon_name(SPok);
				printf ("\n");
			}
			else
			printf ("\nThis pokemon has fainted. Invalid choice.\n");
		}
		
		if (swapchoice==2)
		{
			if (Pok1==SPok&&Pok2HP>0)  
			{
				printf ("\nYou have swapped ");
				pokemon_name(SPok);
				swap (&SPok, &Pok1, &Pok2);	
				swap (&SHP, &Pok1HP, &Pok2HP);
				swap (&SAP, &Pok1AP, &Pok2AP);
				printf (" to ");
				pokemon_name(SPok);	
				printf ("\n");		
			}
			else if (Pok2==SPok)
			{
				printf ("\nYou are currently using this pokemon, invalid choice.\n");
			}
			else if (Pok3==SPok&&Pok2HP>0)
			{
				printf ("\nYou have swapped ");
				pokemon_name(SPok);
				swap (&SPok, &Pok3, &Pok2);
				swap (&SHP, &Pok3HP, &Pok2HP);
				swap (&SAP, &Pok3AP, &Pok2AP);
				printf (" to ");
				pokemon_name(SPok);
				printf ("\n");
			}
			else
			printf ("\nThis pokemon has fainted. Invalid choice.\n");
		}
		
		if (swapchoice==3)
		{
			if (Pok1==SPok&&Pok3HP>0)  
			{
				printf ("\nYou have swapped ");
				pokemon_name(SPok);
				swap (&SPok, &Pok1, &Pok3);	
				swap (&SHP, &Pok1HP, &Pok3HP);
				swap (&SAP, &Pok1AP, &Pok3AP);
				printf (" to ");
				pokemon_name(SPok);	
				printf ("\n");		
			}
			else if (Pok2==SPok&&Pok3HP>0)
			{
				printf ("\nYou have swapped ");
				pokemon_name(SPok);
				swap (&SPok, &Pok2, &Pok3);	
				swap (&SHP, &Pok2HP, &Pok3HP);
				swap (&SAP, &Pok2AP, &Pok3AP);
				printf (" to ");
				pokemon_name(SPok);
				printf ("\n");
			}
			else if (Pok3==SPok)
			{
				printf ("\nYou are currently using this pokemon, invalid choice.\n");
			}
			else
			printf ("\nThis pokemon has fainted. Invalid choice.\n");
		}
	
	} while (SPok==SPokError||SHP<=0);
	turn = 1;
	} 
	else 
	{
	turn = 0;
	delay (1500);
	printf ("No more pokemons to swap with.\n");
	}
	}
	} while (turn==0);
	} 
	

	if (end!=1&&oturn!=1)
	{
	oturn=0;
	delay (2500);
	printf ("\nTrainer %s is choosing a move for ", opponent);
	pokemon_name(SOPok);
	printf ("\n\n");
	pokemon_print (SOPok);
	delay (2500);
	do 
	{
	oact = rand_oact();
	if (oact==1)
	{
	OPowerPoints = OpokAttackType(SOPok, &oattacktype);
	OAccuracy = accuracy(SOPok, oattacktype);
	OHit = HitMiss(OAccuracy);
	OEffectiveness = effectiveness(SOPok, SPok);
	OA = randomA(OPowerPoints, SOAP);
	OAttack = OA * OHit * OEffectiveness;
	printf("\nTrainer %s's ", opponent);
	pokemon_name(SOPok);
	printf(" have dealt %d damage to your ", OAttack);
	pokemon_name(SPok);
	printf (".\n");
	SHP-=OAttack;
	if (SHP>0)
	{
	pokemon_name(SPok);
	printf("'s HP is now %d.\n", SHP);
	turn=0;
	}
	if (SHP<=0)
	{
		SHP=0;
		if ((Pok2HP>0&&Pok3HP>0)||(Pok1HP>0&&Pok2HP>0)||(Pok3HP>0&&Pok1HP>0))
		{
		pokemon_name(SPok);
		printf (" has fainted! Please choose a new pokemon. \n\n");
		printf ("What Pokemon do you want to use?\n");
		printf ("1: ");
		pokemon_name(Pok1);
		if (SPok==Pok1)
		printf (" %d HP", SHP);
		else
		printf (" %d HP", Pok1HP);
		printf ("\n2: ");
		pokemon_name(Pok2);
		if (SPok==Pok2)
		printf (" %d HP", SHP);
		else
		printf (" %d HP", Pok2HP);
		printf ("\n3: ");
		pokemon_name(Pok3);
		if (SPok==Pok3)
		printf (" %d HP", SHP);
		else
		printf (" %d HP\n", Pok3HP);
	while (SHP==0)
	{
		SPokError = SPok;
		printf ("\nEnter number:");
		scanf (" %d", &swapchoice);
	
		if (swapchoice==1)
		{
			if (Pok1==SPok)  
			{
				printf ("\nThis pokemon has fainted, invalid choice.\n");
			}
			else if (Pok2==SPok&&Pok1HP>0)
			{
				printf ("\nYou have swapped ");
				pokemon_name(SPok);
				swap (&SPok, &Pok2, &Pok1);
				swap (&SHP, &Pok2HP, &Pok1HP);
				swap (&SAP, &Pok2AP, &Pok1AP);
				printf (" to ");
				pokemon_name(SPok);
				printf ("\n");
			}
			else if (Pok3==SPok&&Pok1HP>0)
			{
				printf ("\nYou have swapped ");
				pokemon_name(SPok);
				swap (&SPok, &Pok3, &Pok1);
				swap (&SHP, &Pok3HP, &Pok1HP);
				swap (&SAP, &Pok3AP, &Pok1AP);
				printf (" to ");
				pokemon_name(SPok);
				printf ("\n");
			}
			else 
			{
				printf ("\nThis pokemon has fainted, invalid choice.\n");
			}
		}
		if (swapchoice==2)
		{
			if (Pok1==SPok&&Pok2HP>0)  
			{
				printf ("\nYou have swapped ");
				pokemon_name(SPok);
				swap (&SPok, &Pok1, &Pok2);	
				swap (&SHP, &Pok1HP, &Pok2HP);
				swap (&SAP, &Pok1AP, &Pok2AP);
				printf (" to ");
				pokemon_name(SPok);	
				printf ("\n");		
			}
			else if (Pok2==SPok)
			{
				printf ("\nThis pokemon has fainted, invalid choice.\n");
			}
			else if (Pok3==SPok&&Pok2HP>0)
			{
				printf ("\nYou have swapped ");
				pokemon_name(SPok);
				swap (&SPok, &Pok3, &Pok2);
				swap (&SHP, &Pok3HP, &Pok2HP);
				swap (&SAP, &Pok3AP, &Pok2AP);
				printf (" to ");
				pokemon_name(SPok);
				printf ("\n");
			}
			else 
			{
				printf ("\nThis pokemon has fainted, invalid choice.\n");
			}
		}
		
		if (swapchoice==3)
		{
			if (Pok1==SPok&&Pok3HP>0)  
			{
				printf ("\nYou have swapped ");
				pokemon_name(SPok);
				swap (&SPok, &Pok1, &Pok3);	
				swap (&SHP, &Pok1HP, &Pok3HP);
				swap (&SAP, &Pok1AP, &Pok3AP);
				printf (" to ");
				pokemon_name(SPok);	
				printf ("\n");		
			}
			else if (Pok2==SPok&&Pok3HP>0)
			{
				printf ("\nYou have swapped ");
				pokemon_name(SPok);
				swap (&SPok, &Pok2, &Pok3);	
				swap (&SHP, &Pok2HP, &Pok3HP);
				swap (&SAP, &Pok2AP, &Pok3AP);
				printf (" to ");
				pokemon_name(SPok);
				printf ("\n");
			}
			else if (Pok3==SPok)
			{
				printf ("\nThis pokemon has fainted, invalid choice.\n");
			}
			else 
			{
				printf ("\nThis pokemon has fainted, invalid choice.\n");
			}
		}
		
		turn=2;
		oturn=0;
	} 
		}
		else 
		{
		end=1;
		printf("\nYour HP is now O.\n");
		}
		
	}
	}
	if (oact==2)
	{
		if (SOHP+20<initial_hp(SOPok))
		{
		SOHP = SOHP + 20;
		printf ("\nTrainer %s have healed ", opponent);
		pokemon_name(SOPok);
		printf (" by 20 HP.\n");
		pokemon_name(SOPok);
		printf ("'s HP is now %d\n", SOHP);
		}
		else
		{
		printf ("Trainer %s chose to use a potion.\n", opponent);
		pokemon_name(SOPok);
		printf (" is now full HP.\n");
		SOHP = initial_hp(SOPok);	
		}
		turn=0;
		oturn=0;
	}
	
	if (oact==3)
	{
		turn=0;
	if ((OPok2HP>0&&OPok3HP>0)||(OPok1HP>0&&OPok2HP>0)||(OPok3HP>0&&OPok1HP>0))
	{
		oturn=0;
	do{
		oswapchoice = rand()%3+1;
		SOPokError = SOPok;
		if (oswapchoice==1)
		{
			if (OPok2==SOPok&&OPok1HP>0)
			{
				printf ("\nTrainer %s swapped ", opponent);
				pokemon_name(SOPok);
				swap (&SOPok, &OPok2, &OPok1);
				swap (&SOHP, &OPok2HP, &OPok1HP);
				swap (&SOAP, &OPok2AP, &OPok1AP);
				printf (" to ");
				pokemon_name(SOPok);
				printf ("\n\n");
			}
			else if (OPok3==SOPok&&OPok1HP>0)
			{
				printf ("\nTrainer %s swapped ", opponent);
				pokemon_name(SOPok);
				swap (&SOPok, &OPok3, &OPok1);
				swap (&SOHP, &OPok3HP, &OPok1HP);
				swap (&SOAP, &OPok3AP, &OPok1AP);
				printf (" to ");
				pokemon_name(SOPok);
				printf ("\n\n");
			}
			else 
			{
			oswapchoice = rand()%3+1;
			}
		}
		else if (oswapchoice==2)
		{
			if (OPok1==SOPok&&OPok2HP>0)  
			{
				printf ("\nTrainer %s swapped ", opponent);
				pokemon_name(SOPok);
				swap (&SOPok, &OPok1, &OPok2);	
				swap (&SOHP, &OPok1HP, &OPok2HP);
				swap (&SOAP, &OPok1AP, &OPok2AP);
				printf (" to ");
				pokemon_name(SOPok);
				printf ("\n\n");			
			}
			else if (OPok3==SOPok&&OPok2HP>0)
			{
				printf ("\nTrainer %s swapped ", opponent);
				pokemon_name(SOPok);
				swap (&SOPok, &OPok3, &OPok2);
				swap (&SOHP, &OPok3HP, &OPok2HP);
				swap (&SOAP, &OPok3AP, &OPok2AP);
				printf (" to ");
				pokemon_name(SOPok);
				printf ("\n\n");
			}
			else 
			{
			oswapchoice = rand()%3+1;
			}
		}
		else if (oswapchoice==3)
		{
			if (OPok1==SOPok&&OPok3HP>0)  
			{
				printf ("\nTrainer %s swapped ", opponent);
				pokemon_name(SOPok);
				swap (&SOPok, &OPok1, &OPok3);	
				swap (&SOHP, &OPok1HP, &OPok3HP);
				swap (&SOAP, &OPok1AP, &OPok3AP);
				printf (" to ");
				pokemon_name(SOPok);
				printf ("\n\n");			
			}
			else if (OPok2==SOPok&&OPok3HP>0)
			{
				printf ("\nTrainer %s swapped ", opponent);
				pokemon_name(SOPok);
				swap (&SOPok, &OPok2, &OPok3);	
				swap (&SOHP, &OPok2HP, &OPok3HP);
				swap (&SOAP, &OPok2AP, &OPok3AP);
				printf (" to ");
				pokemon_name(SOPok);
				printf ("\n\n");
			}
			else 
			{
			oswapchoice = rand()%3+1;
			}
			
		}
	
	} while (SOPokError == SOPok||SOHP<=0);
	}
	else oturn=3;
	}
	} while (oturn==3);
	} 
 	}
	while (end!=1);	
	} 
	
	if (difficulty==2)
	{
		system ("COLOR 0C"); //text color to red//
	printf ("\n\n");
	printf ("			Type               HP         AP\n\n");
	printf ("			GRASS \n\n");
	printf ("		1   Bulbasaur             160        40\n");
	printf ("		2   Bellsprout            140        60\n");
	printf ("		3   Oddish                150        50\n");
	printf ("			FIRE\n\n");
	printf ("		4   Charmander             25        70\n");
	printf ("		5   Ninetails             130        50\n");
	printf ("		6   Ponyta                140        60\n");
	printf ("			WATER \n\n");
	printf ("		7   Squirtle              180        20\n");
	printf ("		8   Psyduck               170        40\n");
	printf ("		9   Seel                  150        50\n\n");
	printf ("			Trainer %s, choose 3 pokemons!\n\n", trainer);

	//user's pokemon choice//
	do
	{
	printf ("            	 Pokemon 1:");
	scanf ("%d", &Pok1);
	scanf ("%c", &dump);}
	while (Pok1!=1&&Pok1!=2&&Pok1!=3&&Pok1!=4&&Pok1!=5&&Pok1!=6&&Pok1!=7&&Pok1!=8&&Pok1!=9);
	do
	{
	printf ("            	 Pokemon 2:");
	scanf ("%d", &Pok2);
	scanf ("%c", &dump);}
	while (Pok1==Pok2||(Pok2!=1&&Pok2!=2&&Pok2!=3&&Pok2!=4&&Pok2!=5&&Pok2!=6&&Pok2!=7&&Pok2!=8&&Pok2!=9));
	do
	{
	printf ("            	 Pokemon 3:");
	scanf ("%d", &Pok3);
	scanf ("%c", &dump);}
	while (Pok3==Pok1 || Pok3 == Pok2||(Pok3!=1&&Pok3!=2&&Pok3!=3&&Pok3!=4&&Pok3!=5&&Pok3!=6&&Pok3!=7&&Pok3!=8&&Pok3!=9));
	system ("cls");

	system ("COLOR 0D"); //change screen text to purple//
	opponent_print();
	printf ("\n    Oh no! Trainer %s has challenged you! Press any key to fight!", opponent);
	getch();
	system ("cls");
	system ("COLOR 0E"); //change screen text to green//
	
	//computer picks pokemon who counters the user's pick//
	if (Pok1==1||Pok1==2||Pok1==3)
	{
	srand (time(NULL));
	OPok1 = rand()%3+4;
	while ((OPok1==Pok1)||(OPok1==Pok2)||(OPok1==Pok3))
	{ OPok1=rand()%3+4;}
	}
	else if (Pok1==4||Pok1==5||Pok1==6)
	{
	srand (time(NULL));
	OPok1 = rand()%3+7;
	while ((OPok1==Pok1)||(OPok1==Pok2)||(OPok1==Pok3))
	{ OPok1=rand()%3+7;}
	}
	else if (Pok1==7||Pok1==8||Pok1==9)
	{
	srand (time(NULL));
	OPok1 = rand()%3+1;
	while ((OPok1==Pok1)||(OPok1==Pok2)||(OPok1==Pok3))
	{ OPok1=rand()%3+1;}
	}
	
	if ((Pok2==1||Pok2==2||Pok2==3))
	{
	OPok2 = rand()%3+4;
	while ((OPok2==Pok1)||(OPok2==Pok2)||(OPok2==Pok3)||(OPok2==OPok1))
	{ OPok2=rand()%3+4;}
	}
	else if ((Pok2==4||Pok2==5||Pok2==6))
	{
	OPok2 = rand()%3+7;
	while ((OPok2==Pok1)||(OPok2==Pok2)||(OPok2==Pok3)||(OPok2==OPok1))
	{ OPok2=rand()%3+7;}
	}
	else if ((Pok2==7||Pok2==8||Pok2==9))
	{
	OPok2 = rand()%3+1;
	while ((OPok2==Pok1)||(OPok2==Pok2)||(OPok2==Pok3)||(OPok2==OPok1))
	{ OPok2=rand()%3+1;}
	}
		
	if (Pok3==1||Pok3==2||Pok3==3)
	{
	OPok3 = rand()%3+4;	
	while ((OPok3==Pok1)||(OPok3==Pok2)||(OPok3==Pok3)||(OPok3==OPok2)||(OPok3==OPok1))
	{ OPok3= rand()%3+4;}
	}
	else if (Pok3==4||Pok3==5||Pok3==6)
	{
	OPok3 = rand()%3+7;	
	while ((OPok3==Pok1)||(OPok3==Pok2)||(OPok3==Pok3)||(OPok3==OPok2)||(OPok3==OPok1))
	{ OPok3= rand()%3+7;}
	}
	else if (Pok3==7||Pok3==8||Pok3==9)
	{
	OPok3 = rand()%3+1;	
	while ((OPok3==Pok1)||(OPok3==Pok2)||(OPok3==Pok3)||(OPok3==OPok2)||(OPok3==OPok1))
	{ OPok3= rand()%3+1;}
	}
	//show user pokemons and opponent pokemons//
	pokemon_print(OPok1);
	printf ("\nTrainer %s's pokemons are...      ",opponent );
	printf("\n                      ");
	pokemon_name(OPok1);
	printf ("\n			    Press any key to continue.....");
	getch();
	system ("cls");
	pokemon_print(OPok2);
	printf("                      ");
	pokemon_name(OPok2);
	printf ("\n			    Press any key to continue.....");
	getch();
	system ("cls");
	pokemon_print(OPok3);
	printf("                      ");
	pokemon_name(OPok3);
	printf ("\n			    Press any key to continue.....");
	getch();
	system ("cls");
	printf ("\n                     What Pokemon would you like to use first?\n");
	printf("                      ");
	printf ("1: ");
	pokemon_name(Pok1);
	printf ("\n");
	pokemon_print(Pok1);
	printf ("\n			    Press any key to continue.....");
	getch();
	system ("cls");
	printf("                      ");
	printf ("\n2: ");
	pokemon_name(Pok2);
	printf ("\n");
	pokemon_print(Pok2);
	printf ("\n			    Press any key to continue.....");
	getch();
	system ("cls");
	printf("                      ");
	printf ("\n3: ");
	pokemon_name(Pok3);
	printf ("\n");
	pokemon_print(Pok3);
	do
	{
	printf ("\n\n            Enter [1] ");
	pokemon_name(Pok1);
	printf (" [2] ");
	pokemon_name(Pok2);
	printf (" [3] ");
	pokemon_name(Pok3);
	printf (" : ");
	scanf ("%d", &SPok);
	scanf ("%c", &dump);
	} while (SPok!=1&&SPok!=2&&SPok!=3);
	//transfer value to Starter Pokemon//
	if (SPok==1)
	SPok=Pok1;
	else if(SPok==2)
	SPok=Pok2;
	else if(SPok==3)
	SPok=Pok3;
	system("cls");
	printf ("\n               Your starter pokemon is .....\n");
	pokemon_print(SPok);
	printf("                      ");
	pokemon_name(SPok);
	printf ("\n            Press any key to continue...");
	getch();
	system ("cls");
	printf ("			    Your enemy's starter pokemon is.....\n");
	//computer will choose the pokemon counter to the user's pokemon//
	if (SPok==Pok1)
	SOPok=OPok1;
	else if (SPok==Pok2)
	SOPok=OPok2;
	else if (SPok==Pok3)
	SOPok=OPok3;
	pokemon_print(SOPok);
	printf("                      ");
	pokemon_name(SOPok);
	printf ("\n			    Press any key to continue.....");
	getch();
	system ("cls");
	
	//initialize the hp/ap values for all chosen pokemons//
	turn = 0;
	oturn = 0;
	
	SHP=initial_hp(SPok);
	SAP=initial_ap(SPok);
	
	SOAP = initial_ap(SOPok);
	SOHP = initial_hp(SOPok);
	
	Pok1AP = initial_ap(Pok1);
	Pok1HP = initial_hp(Pok1);
	Pok2AP = initial_ap(Pok2);
	Pok2HP = initial_hp(Pok2);
	Pok3AP = initial_ap(Pok3);
	Pok3HP = initial_hp(Pok3);
	
	OPok1AP = initial_ap(OPok1);
	OPok1HP = initial_hp(OPok1);
	OPok2AP = initial_ap(OPok2);
	OPok2HP = initial_hp(OPok2);
	OPok3AP = initial_ap(OPok3);
	OPok3HP = initial_hp(OPok3);
	
	do
	{

	system ("COLOR 0B");
	delay(1000);
	if (end!=1&&turn!=2)
	{
	turn = 0;
	do {
	pokemon_print(SPok);
	print_status(SHP, SOHP);
	printf ("               ");
	pokemon_name(SPok);
	printf ("'s HP \n");
	HPBar(SHP, initial_hp(SPok));
	delay (1000);
	printf ("Your turn!\n");
	delay (1000);
	printf ("What do you want ");
	pokemon_name(SPok);
	printf(" to do?\n1. Attack  2. Use a potion 3. Switch.\n\n");
	do{
	printf ("Enter Number: ");
	scanf (" %d", &act); } while (act!=1&&act!=2&&act!=3);
	printf("\n");

	//attack action//
	if (act==1)
	{
	PowerPoints = pokAttackType(SPok, &attacktype);
	Accuracy = accuracy(SPok, attacktype);
	Hit = HitMiss(Accuracy);
	Effectiveness = effectiveness(SPok, SOPok);
	A = randomA(PowerPoints, SAP);
	Attack = A * Hit * Effectiveness;
	printf("You have dealt %d damage to ", Attack);
	pokemon_name(SOPok);
	SOHP-=Attack;
	if (SOHP>0)
	{
	printf("\nOpponent's HP is now %d.\nIt is now his turn.\n\n", SOHP);
	oturn=0;	
	}
	if (SOHP<=0)
	{	
		SOHP=0;
		if ((OPok2HP>0&&OPok3HP>0)||(OPok1HP>0&&OPok2HP>0)||(OPok3HP>0&&OPok1HP>0))
		{
		printf ("\n");
		pokemon_name(SOPok);
		printf (" has fainted! \nTrainer %s is chooosing a pokemon. \n\n", opponent );

		while(SOHP == 0){
		oswapchoice = rand()%3+1;
		SOPokError = SOPok;
		if (oswapchoice==1)
		{
			if (OPok2==SOPok&&OPok1HP>0)
			{
				printf ("\nTrainer %s swapped ", opponent);
				pokemon_name(SOPok);
				swap (&SOPok, &OPok2, &OPok1);
				swap (&SOHP, &OPok2HP, &OPok1HP);
				printf ("\n");
			}
			else if (OPok3==SOPok&&OPok1HP>0)
			{
				printf ("\nTrainer %s swapped ", opponent);
				pokemon_name(SOPok);
				swap (&SOPok, &OPok3, &OPok1);
				swap (&SOHP, &OPok3HP, &OPok1HP);
				swap (&SOAP, &OPok3AP, &OPok1AP);
				printf (" to ");
				pokemon_name(SOPok);
				printf ("\n");
			}
			else 
			{
			oswapchoice = rand()%3+1;
			}
			
		}
		else if (oswapchoice==2)
		{
			if (OPok1==SOPok&&OPok2HP>0)  
			{
				printf ("\nTrainer %s swapped ", opponent);
				pokemon_name(SOPok);
				swap (&SOPok, &OPok1, &OPok2);	
				swap (&SOHP, &OPok1HP, &OPok2HP);
				swap (&SOAP, &OPok1AP, &OPok2AP);
				printf (" to ");
				pokemon_name(SOPok);
				printf ("\n");			
			}
			else if (OPok3==SOPok&&OPok2HP>0)
			{
				printf ("\nTrainer %s swapped ", opponent);
				pokemon_name(SOPok);
				swap (&SOPok, &OPok3, &OPok2);
				swap (&SOHP, &OPok3HP, &OPok2HP);
				swap (&SOAP, &OPok3AP, &OPok2AP);
				printf (" to ");
				pokemon_name(SOPok);
				printf ("\n");
			}
			else 
			{
			oswapchoice = rand()%3+1;
			}
		}
		else if (oswapchoice==3)
		{
			if (OPok1==SOPok&&OPok3HP>0)  
			{
				printf ("\nTrainer %s swapped ", opponent);
				pokemon_name(SOPok);
				swap (&SOPok, &OPok1, &OPok3);	
				swap (&SOHP, &OPok1HP, &OPok3HP);
				swap (&SOAP, &OPok1AP, &OPok3AP);
				printf (" to ");
				pokemon_name(SOPok);
				printf ("\n");			
			}
			else if (OPok2==SOPok&&OPok3HP>0)
			{
				printf ("\nTrainer %s swapped ", opponent);
				pokemon_name(SOPok);
				swap (&SOPok, &OPok2, &OPok3);	
				swap (&SOHP, &OPok2HP, &OPok3HP);
				swap (&SOAP, &OPok2AP, &OPok3AP);
				printf (" to ");
				pokemon_name(SOPok);
				printf ("\n");
			}
			else 
			{
			oswapchoice = rand()%3+1;
			}
			
		}
		oturn=1;
	}
	}
	else 
	{
	printf("\nOpponent's HP is now O.");
	end = 1;
	}
	}
	turn =1;
	}

	
	else if (act==2)
	{
		if (SHP+20<initial_hp(SPok))
		{
		SHP = SHP + 20;
		printf ("\nYou have healed ");
		pokemon_name(SPok);
		printf (" by 20 HP. Your HP is now %d.\n", SHP);
		}
		else
		{
		pokemon_name(SPok);
		printf (" is now full HP.\n");
		SHP = initial_hp(SPok);
	}
	oturn=0;
	turn = 1;
	}
	else if (act==3)
	{
	if ((Pok2HP>0&&Pok3HP>0)||(Pok1HP>0&&Pok2HP>0)||(Pok3HP>0&&Pok1HP>0))
	{
		oturn=0;
		printf ("\nWhat Pokemon do you want to use?\n");
		printf ("1: ");
		pokemon_name(Pok1);
		if (SPok==Pok1)
		printf (" %d HP", SHP);
		else
		printf (" %d HP", Pok1HP);
		printf ("\n2: ");
		pokemon_name(Pok2);
		if (SPok==Pok2)
		printf (" %d HP", SHP);
		else
		printf (" %d HP", Pok2HP);
		printf ("\n3: ");
		pokemon_name(Pok3);
		if (SPok==Pok3)
		printf (" %d HP", SHP);
		else
		printf (" %d HP\n", Pok3HP);
	do
	{
		SPokError = SPok;
		do {
		printf ("\nEnter number:");
		scanf (" %d", &swapchoice); }
		while (swapchoice!=1&&swapchoice!=2&&swapchoice!=3);
		if (swapchoice==1)
		{
			if (Pok1==SPok)  
			{
				printf ("You are currently using this pokemon, invalid choice.\n");
			}
			else if (Pok2==SPok&&Pok1HP>0)
			{
				printf ("\nYou have swapped ");
				pokemon_name(SPok);
				swap (&SPok, &Pok2, &Pok1);
				swap (&SHP, &Pok2HP, &Pok1HP);
				swap (&SAP, &Pok2AP, &Pok1AP);
				printf (" to ");
				pokemon_name(SPok);
				printf ("\n");
			}
			else if (Pok3==SPok&&Pok1HP>0)
			{
				printf ("\nYou have swapped ");
				pokemon_name(SPok);
				swap (&SPok, &Pok3, &Pok1);
				swap (&SHP, &Pok3HP, &Pok1HP);
				swap (&SAP, &Pok3AP, &Pok1AP);
				printf (" to ");
				pokemon_name(SPok);
				printf ("\n");
			}
			else
			printf ("\nThis pokemon has fainted. Invalid choice.\n");
		}
		
		if (swapchoice==2)
		{
			if (Pok1==SPok&&Pok2HP>0)  
			{
				printf ("\nYou have swapped ");
				pokemon_name(SPok);
				swap (&SPok, &Pok1, &Pok2);	
				swap (&SHP, &Pok1HP, &Pok2HP);
				swap (&SAP, &Pok1AP, &Pok2AP);
				printf (" to ");
				pokemon_name(SPok);	
				printf ("\n");		
			}
			else if (Pok2==SPok)
			{
				printf ("\nYou are currently using this pokemon, invalid choice.\n");
			}
			else if (Pok3==SPok&&Pok2HP>0)
			{
				printf ("\nYou have swapped ");
				pokemon_name(SPok);
				swap (&SPok, &Pok3, &Pok2);
				swap (&SHP, &Pok3HP, &Pok2HP);
				swap (&SAP, &Pok3AP, &Pok2AP);
				printf (" to ");
				pokemon_name(SPok);
				printf ("\n");
			}
			else
			printf ("\nThis pokemon has fainted. Invalid choice.\n");
		}
		
		if (swapchoice==3)
		{
			if (Pok1==SPok&&Pok3HP>0)  
			{
				printf ("\nYou have swapped ");
				pokemon_name(SPok);
				swap (&SPok, &Pok1, &Pok3);	
				swap (&SHP, &Pok1HP, &Pok3HP);
				swap (&SAP, &Pok1AP, &Pok3AP);
				printf (" to ");
				pokemon_name(SPok);	
				printf ("\n");		
			}
			else if (Pok2==SPok&&Pok3HP>0)
			{
				printf ("\nYou have swapped ");
				pokemon_name(SPok);
				swap (&SPok, &Pok2, &Pok3);	
				swap (&SHP, &Pok2HP, &Pok3HP);
				swap (&SAP, &Pok2AP, &Pok3AP);
				printf (" to ");
				pokemon_name(SPok);
				printf ("\n");
			}
			else if (Pok3==SPok)
			{
				printf ("\nYou are currently using this pokemon, invalid choice.\n");
			}
			else
			printf ("\nThis pokemon has fainted. Invalid choice.\n");
		}
	
	} while (SPok==SPokError||SHP<=0);
	turn = 1;
	} 
	else 
	{
	turn = 0;
	delay (1500);
	printf ("No more pokemons to swap with.\n");
	}
	}
	} while (turn==0);
	} 
	
	if (end!=1&&oturn!=1)
	{
	oturn=0;
	delay (2500);
	printf ("\nTrainer %s is choosing a move for ", opponent);
	pokemon_name(SOPok);
	printf ("\n\n");
	pokemon_print (SOPok);
	delay (2500);
	
	if (act==1)
	oact=1;
	else if (act==3)
	oact=3;
	else
	oact = rand_oact();
	
	if (oact==1)
	{
	OPowerPoints = OpokAttackType(SOPok, &oattacktype);
	OAccuracy = accuracy(SOPok, oattacktype);
	OHit = HitMiss(OAccuracy);
	OEffectiveness = effectiveness(SOPok, SPok);
	OA = randomA(OPowerPoints, SOAP);
	OAttack = OA * OHit * OEffectiveness;
	printf("\nTrainer %s's ", opponent);
	pokemon_name(SOPok);
	printf(" have dealt %d damage to your ", OAttack);
	pokemon_name(SPok);
	printf (".\n");
	SHP-=OAttack;
	if (SHP>0)
	{
	pokemon_name(SPok);
	printf("'s HP is now %d.\n", SHP);
	turn=0;
	}
	if (SHP<=0)
	{
		SHP=0;
		if ((Pok2HP>0&&Pok3HP>0)||(Pok1HP>0&&Pok2HP>0)||(Pok3HP>0&&Pok1HP>0))
		{
		pokemon_name(SPok);
		printf (" has fainted! Please choose a new pokemon. \n\n");
		printf ("What Pokemon do you want to use?\n");
		printf ("1: ");
		pokemon_name(Pok1);
		if (SPok==Pok1)
		printf (" %d HP", SHP);
		else
		printf (" %d HP", Pok1HP);
		printf ("\n2: ");
		pokemon_name(Pok2);
		if (SPok==Pok2)
		printf (" %d HP", SHP);
		else
		printf (" %d HP", Pok2HP);
		printf ("\n3: ");
		pokemon_name(Pok3);
		if (SPok==Pok3)
		printf (" %d HP", SHP);
		else
		printf (" %d HP\n", Pok3HP);
	while (SHP==0)
	{
		SPokError = SPok;
		printf ("\nEnter number:");
		scanf (" %d", &swapchoice);
	
		if (swapchoice==1)
		{
			if (Pok1==SPok)  
			{
				printf ("\nThis pokemon has fainted, invalid choice.\n");
			}
			else if (Pok2==SPok&&Pok1HP>0)
			{
				printf ("\nYou have swapped ");
				pokemon_name(SPok);
				swap (&SPok, &Pok2, &Pok1);
				swap (&SHP, &Pok2HP, &Pok1HP);
				swap (&SAP, &Pok2AP, &Pok1AP);
				printf (" to ");
				pokemon_name(SPok);
				printf ("\n");
			}
			else if (Pok3==SPok&&Pok1HP>0)
			{
				printf ("\nYou have swapped ");
				pokemon_name(SPok);
				swap (&SPok, &Pok3, &Pok1);
				swap (&SHP, &Pok3HP, &Pok1HP);
				swap (&SAP, &Pok3AP, &Pok1AP);
				printf (" to ");
				pokemon_name(SPok);
				printf ("\n");
			}
			else 
			{
				printf ("\nThis pokemon has fainted, invalid choice.\n");
			}
		}
		if (swapchoice==2)
		{
			if (Pok1==SPok&&Pok2HP>0)  
			{
				printf ("\nYou have swapped ");
				pokemon_name(SPok);
				swap (&SPok, &Pok1, &Pok2);	
				swap (&SHP, &Pok1HP, &Pok2HP);
				swap (&SAP, &Pok1AP, &Pok2AP);
				printf (" to ");
				pokemon_name(SPok);	
				printf ("\n");		
			}
			else if (Pok2==SPok)
			{
				printf ("\nThis pokemon has fainted, invalid choice.\n");
			}
			else if (Pok3==SPok&&Pok2HP>0)
			{
				printf ("\nYou have swapped ");
				pokemon_name(SPok);
				swap (&SPok, &Pok3, &Pok2);
				swap (&SHP, &Pok3HP, &Pok2HP);
				swap (&SAP, &Pok3AP, &Pok2AP);
				printf (" to ");
				pokemon_name(SPok);
				printf ("\n");
			}
			else 
			{
				printf ("\nThis pokemon has fainted, invalid choice.\n");
			}
		}
		
		if (swapchoice==3)
		{
			if (Pok1==SPok&&Pok3HP>0)  
			{
				printf ("\nYou have swapped ");
				pokemon_name(SPok);
				swap (&SPok, &Pok1, &Pok3);	
				swap (&SHP, &Pok1HP, &Pok3HP);
				swap (&SAP, &Pok1AP, &Pok3AP);
				printf (" to ");
				pokemon_name(SPok);	
				printf ("\n");		
			}
			else if (Pok2==SPok&&Pok3HP>0)
			{
				printf ("\nYou have swapped ");
				pokemon_name(SPok);
				swap (&SPok, &Pok2, &Pok3);	
				swap (&SHP, &Pok2HP, &Pok3HP);
				swap (&SAP, &Pok2AP, &Pok3AP);
				printf (" to ");
				pokemon_name(SPok);
				printf ("\n");
			}
			else if (Pok3==SPok)
			{
				printf ("\nThis pokemon has fainted, invalid choice.\n");
			}
			else 
			{
				printf ("\nThis pokemon has fainted, invalid choice.\n");
			}
		}
		turn=2;
	} 
		}
		else 
		{
		end=1;
		printf("\nYour HP is now O.\n");
		}
		
	}
	}
	if (oact==2)
	{
		if (SOHP+20<initial_hp(SOPok))
		{
		SOHP = SOHP + 20;
		printf ("\nTrainer %s have healed ", opponent);
		pokemon_name(SOPok);
		printf (" by 20 HP.\n");
		pokemon_name(SOPok);
		printf ("'s HP is now %d\n", SOHP);
		}
		else
		{
		printf ("Trainer %s chose to use a potion.\n", opponent);
		pokemon_name(SOPok);
		printf (" is now full HP.\n");
		SOHP = initial_hp(SOPok);	
		}
		turn=0;
	}
	
	if (oact==3)
	{
		turn=0;
	if ((OPok2HP>0&&OPok3HP>0)||(OPok1HP>0&&OPok2HP>0)||(OPok3HP>0&&OPok1HP>0))
	{
		oturn=0;
	do{
		oswapchoice = rand()%3+1;
		SOPokError = SOPok;
		if (oswapchoice==1)
		{
			if (OPok2==SOPok&&OPok1HP>0)
			{
				printf ("\nTrainer %s swapped ", opponent);
				pokemon_name(SOPok);
				swap (&SOPok, &OPok2, &OPok1);
				swap (&SOHP, &OPok2HP, &OPok1HP);
				swap (&SOAP, &OPok2AP, &OPok1AP);
				printf (" to ");
				pokemon_name(SOPok);
				printf ("\n\n");
			}
			else if (OPok3==SOPok&&OPok1HP>0)
			{
				printf ("\nTrainer %s swapped ", opponent);
				pokemon_name(SOPok);
				swap (&SOPok, &OPok3, &OPok1);
				swap (&SOHP, &OPok3HP, &OPok1HP);
				swap (&SOAP, &OPok3AP, &OPok1AP);
				printf (" to ");
				pokemon_name(SOPok);
				printf ("\n\n");
			}
			else 
			{
			oswapchoice = rand()%3+1;
			}
		}
		else if (oswapchoice==2)
		{
			if (OPok1==SOPok&&OPok2HP>0)  
			{
				printf ("\nTrainer %s swapped ", opponent);
				pokemon_name(SOPok);
				swap (&SOPok, &OPok1, &OPok2);	
				swap (&SOHP, &OPok1HP, &OPok2HP);
				swap (&SOAP, &OPok1AP, &OPok2AP);
				printf (" to ");
				pokemon_name(SOPok);
				printf ("\n\n");			
			}
			else if (OPok3==SOPok&&OPok2HP>0)
			{
				printf ("\nTrainer %s swapped ", opponent);
				pokemon_name(SOPok);
				swap (&SOPok, &OPok3, &OPok2);
				swap (&SOHP, &OPok3HP, &OPok2HP);
				swap (&SOAP, &OPok3AP, &OPok2AP);
				printf (" to ");
				pokemon_name(SOPok);
				printf ("\n\n");
			}
			else 
			{
			oswapchoice = rand()%3+1;
			}
		}
		else if (oswapchoice==3)
		{
			if (OPok1==SOPok&&OPok3HP>0)  
			{
				printf ("\nTrainer %s swapped ", opponent);
				pokemon_name(SOPok);
				swap (&SOPok, &OPok1, &OPok3);	
				swap (&SOHP, &OPok1HP, &OPok3HP);
				swap (&SOAP, &OPok1AP, &OPok3AP);
				printf (" to ");
				pokemon_name(SOPok);
				printf ("\n\n");			
			}
			else if (OPok2==SOPok&&OPok3HP>0)
			{
				printf ("\nTrainer %s swapped ", opponent);
				pokemon_name(SOPok);
				swap (&SOPok, &OPok2, &OPok3);	
				swap (&SOHP, &OPok2HP, &OPok3HP);
				swap (&SOAP, &OPok2AP, &OPok3AP);
				printf (" to ");
				pokemon_name(SOPok);
				printf ("\n\n");
			}
			else 
			{
			oswapchoice = rand()%3+1;
			}
			
		}
	
	} while (SOPokError == SOPok||SOHP<=0);
	}
	else oturn=3;
	}
	} while (oturn==3);
	}  	while (end!=1);	
 	}  
	
	
	printf ("\nThe game has ended.\n\n");
	if (SHP>0)
	{
		delay (2000);
		printf ("\n /$$     /$$                        /$$   /$$                                     /$$      /$$                    \n");
		printf ("|  $$   /$$/                       | $$  | $$                                    | $$  /$ | $$                    \n");
		printf (" \\  $$ /$$//$$$$$$  /$$   /$$      | $$  | $$  /$$$$$$  /$$    /$$ /$$$$$$       | $$ /$$$| $$  /$$$$$$  /$$$$$$$ \n");
		printf ("  \\  $$$$//$$__  $$| $$  | $$      | $$$$$$$$ |____  $$|  $$  /$$//$$__  $$      | $$/$$ $$ $$ /$$__  $$| $$__  $$\n");
		printf ("   \\  $$/| $$  \\ $$| $$  | $$      | $$__  $$  /$$$$$$$ \\  $$/$$/| $$$$$$$$      | $$$$_  $$$$| $$  \\ $$| $$  \\ $$\n");
		printf ("    | $$ | $$  | $$| $$  | $$      | $$  | $$ /$$__  $$  \\  $$$/ | $$_____/      | $$$/ \\  $$$| $$  | $$| $$  | $$\n");
		printf ("    | $$ |  $$$$$$/|  $$$$$$/      | $$  | $$|  $$$$$$$   \\  $/  |  $$$$$$$      | $$/   \\  $$|  $$$$$$/| $$  | $$\n");
		printf ("    |__/  \\______/  \\______/       |__/  |__/ \\_______/    \\_/    \\_______/      |__/     \\__/ \\______/ |__/  |__/\n\n");
		printf ("\n\n                                                                                                                                           \n");
		printf ("                                                               _|                _|              _|      _|                                \n");
		printf ("   _|_|_|    _|_|    _|_|_|      _|_|_|  _|  _|_|    _|_|_|  _|_|_|_|  _|    _|  _|    _|_|_|  _|_|_|_|        _|_|    _|_|_|      _|_|_|  \n");
		printf (" _|        _|    _|  _|    _|  _|    _|  _|_|      _|    _|    _|      _|    _|  _|  _|    _|    _|      _|  _|    _|  _|    _|  _|_|      \n");
		printf (" _|        _|    _|  _|    _|  _|    _|  _|        _|    _|    _|      _|    _|  _|  _|    _|    _|      _|  _|    _|  _|    _|      _|_|  \n");
		printf ("   _|_|_|    _|_|    _|    _|    _|_|_|  _|          _|_|_|      _|_|    _|_|_|  _|    _|_|_|      _|_|  _|    _|_|    _|    _|  _|_|_|    \n");
		printf ("                                     _|                                                                                                    \n");
		printf ("                                 _|_|                                                                                                      \n");
		}

		
	else if (SOHP>0)
	{
		delay (2000);
		printf ("            $$\\     $$\\                         $$\\                       $$\\     \n");
		printf ("            \\$$\\   $$  |                        $$ |                      $$ |    \n");
		printf ("             \\$$\\ $$  /$$$$$$\\  $$\\   $$\\       $$ | $$$$$$\\   $$$$$$$\\ $$$$$$\\   \n");
		printf ("              \\$$$$  /$$  __$$\\ $$ |  $$ |      $$ |$$  __$$\\ $$  _____|\\_$$  _|  \n");
		printf ("               \\$$  / $$ /  $$ |$$ |  $$ |      $$ |$$ /  $$ |\\$$$$$$\\    $$ |    \n");
		printf ("                $$ |  $$ |  $$ |$$ |  $$ |      $$ |$$ |  $$ | \\____$$\\   $$ |$$\\ \n");
		printf ("                $$ |  \\$$$$$$  |\\$$$$$$  |      $$ |\\$$$$$$  |$$$$$$$  |  \\$$$$  |\n");
		printf ("                \\__|   \\______/  \\______/       \\__| \\______/ \\_______/    \\____/ \n\n\n");
		
	}
	printf ("                                               Press any key to play again. ");
	getch();
	system ("cls");
	system ("COLOR 0A");
	end=0;
	}

	return 0;		
}

/*
	This function prints the hp status of both the user and the opponent's active pokemon
	@param (int) HP is the health of the user's pokemon
	@param (int) OHP is the health of the opponent's pokemon
	@return (void) no return value
*/
void print_status(int HP, int OHP)
{

	printf ("------------------------------------------\n");
	printf ("-             Your Health: %d          \n", HP);
	printf ("-             Enemy's Health: %d      \n", OHP);
	printf ("------------------------------------------\n\n");
}
/*
	This function randomizes the opponent's actions with 2/3 probability of choosing attack (act=1),
	1/6 probability of choosing heal (act=2) and 1/6 probability of choosing switch pokemon (act=3).
	@return (int) returns an integer 1 (attack) , 2 (heal) or 3 (switch)
*/
int rand_oact()
{
	int act;
	srand(time(NULL));
	act = rand()%6+1;
	if (act==1||act==2||act==3||act==4)
	act = 1;
	if (act==5)
	act = 2;
	if (act==6)
	act = 3;
	return act;
}
/*
	This function stores the values of the active pokemon to the original pokemon and it stores the value
	of the swapped pokemon to the active pokemon. 
	@param (int) *SPok is the active pokemon.
	@param (int) *Pok is the original pokemon.
	@param (int) *SwapPok is the swapped pokemon.
	@return (void) no return value
*/
void swap(int *SPok, int *Pok, int *SwapPok)
{
	*Pok = *SPok;
	*SPok = *SwapPok;
}
// delay function taken from: https://c-for-dummies.com/blog/?p=69 //
/*
	This function outputs a delay interval between the execution of the functions. 
	@param (int) milliseconds is the duration of the delay 
	@return (void) no return value
*/
void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}
/*
	This function returns a value 1 or 0 is the user hit or missed
	@param (int) accuracy is the accuracy of the move chosen by the user. 
	@param (int) OHP is the health of the opponent's pokemon
	@return (void) no return value
*/
int HitMiss(int accuracy)
{
	srand(time(NULL));
	int Hit, percent;
	percent = rand()%100+1;
	if (percent>accuracy)
	Hit = 0;
	if (percent <= accuracy)
	Hit = 1;
	return (Hit);
}
/*
	This function gets attacktype chosen per pokemon to determine the accuracy of each. 
	@param (int) Pok is the pokemon chosen from 1-9
	@param (int) attacktype is the attack type chosen form 1-3
	@return (int) accuracy returns the accuracy from 30-100 based on each attack.
*/
int accuracy(int Pok, int attacktype)
{
	int accuracy;
	switch(Pok)
	{
		case 1:
		case 2:
		case 3:
		{
		if (attacktype==1)
		  	accuracy=90 ; 
		if (attacktype==2)
			accuracy=100 ; 
		if (attacktype==3)
			accuracy=95 ; 
		break;
		}
		case 4:
		case 5:
		case 6:
		{
		if (attacktype==1)
		  	accuracy=100 ;
		if (attacktype==2)
			accuracy=80 ;
		if (attacktype==3)
			accuracy=90 ; 
		break;
		}
		case 7:
		case 8:
		case 9:
		{
		if (attacktype==1)
		  	accuracy=100 ;
		if (attacktype==2)
			accuracy=30 ;
		if (attacktype==3)
			accuracy=90 ; 
		break;
		}
	}
	return (accuracy);
}
/*
	This function chooses a random attack power or power point, if it is less than the attack power.
	@param (int) PowerPoints is the power points per attack type.
	@param (int) AP is AP per pokemon.
	@return (int) it will return random attack power or power points
*/
int randomA(int PowerPoints, int AP)
{
	int A=0;
	srand(time(NULL));
	if (AP>PowerPoints)
	{
	do
	{ A= rand()%PowerPoints+1; }
	while (!((PowerPoints-20)<=A&&PowerPoints>=A));
	}
	if(PowerPoints>=AP)
	{
	do
	{A= rand()%AP+1; }
	while (!((AP-20)<=A && AP>=A));
	}	
	return (A); 
}
/*
	This function lets the user choose an attack type and will return the power points per
	attack type/pokemon type.
	@param (int) Pok is the number of Pokemon to determine the pokemon type
	@param (int) *attacktypee is the pointer for the address of the attacktype, to return the attack type value chosen
	@return (int) it will return an integer with the value of the power points per pokemon type/attack type chosen.
*/
int pokAttackType(int Pok, int *attacktypee)
{
	int attack, attacktype;
	char dump; //to dump non-number characters in scan//
	switch(Pok)
	{
		case 1: 
		case 2: 
		case 3: 
		{
			printf("Pick an attack: \n1. Leaf Storm (130 Power Points)\n2. Mega Drain (50 Power Points)\n3. Razor Leaf (55 Power Points)\n");
			do {
			printf ("Enter number: ");
			scanf ("%d", &attacktype); 
			scanf ("%c", &dump);} while (attacktype!=1&&attacktype!=2&&attacktype!=3);
			if (attacktype==1)
			attack=130;
			else if (attacktype==2)
			attack=50;
			else if (attacktype==3)
			attack=55;	
		break;
		}
		case 4: 

		case 5: 

		case 6: 
		{
			printf("Pick an attack: \n1. Ember (60 Power Points)\n2. Fire Punch (85 Power Points)\n3. Flame Wheel (70 Power Points)\n");
			do {
			printf ("Enter number: ");
			scanf ("%d", &attacktype); 
			scanf ("%c", &dump);} while (attacktype!=1&&attacktype!=2&&attacktype!=3);
			if (attacktype==1)
			attack=60;
			else if (attacktype==2)
			attack=85;
			else if (attacktype==3)
			attack=70;	
		break;
		}
		case 7: 

		case 8: 

		case 9: 
		{
			printf("Pick an attack: \n1. Bubble (40 Power Points)\n2. Hydro Pump (185 Power Points)\n3. Surf (70 Power Points)\n");
			do {
			printf ("Enter number: ");
			scanf ("%d", &attacktype); 
			scanf ("%c", &dump);} while (attacktype!=1&&attacktype!=2&&attacktype!=3);
			if (attacktype==1)
			attack=40;
			else if (attacktype==2)
			attack=185;
			else if (attacktype==3)
			attack=70;	
		break;
		}

	}	*attacktypee = attacktype;	
	printf ("\n");
	return (attack);
}

/*
	This function lets the opponent have a random attack type and will return the power points per
	attack type/pokemon type.
	@param (int) Pok is the number of Pokemon to determine the pokemon type
	@param (int) *attacktypee is the pointer for the address of the attacktype, to return the attack type value chosen
	@return (int) it will return a random integer with the value of the power points per pokemon type/attack type.
*/
int OpokAttackType(int Pok, int *attacktypee)
{
	int attack, attacktype;
	srand(time(NULL));
	switch(Pok)
	{
		case 1: 
		case 2: 
		case 3: 
		{
			attacktype = rand()%3+1;
			if (attacktype==1)
			attack=130;
			else if (attacktype==2)
			attack=50;
			else if (attacktype==3)
			attack=55;	
		break;
		}
		case 4: 

		case 5: 

		case 6: 
		{
			attacktype = rand()%3+1;
			if (attacktype==1)
			attack=60;
			else if (attacktype==2)
			attack=85;
			else if (attacktype==3)
			attack=70;	
		break;
		}
		case 7: 

		case 8: 

		case 9: 
		{
			attacktype = rand()%3+1;
			if (attacktype==1)
			attack=40;
			else if (attacktype==2)
			attack=185;
			else if (attacktype==3)
			attack=70;	
		break;
		}

	}	*attacktypee = attacktype; return (attack);
}
/*
	This function returns the the initial HP values of pokemons 1-9.
	@param (int) Pok is the number of Pokemon 
	@return (int) it will return an integer with the HP value per pokemon
*/
int initial_hp(int Pok)
{
	int HP;
	switch(Pok)
	{
		case 1:HP=160 ; break;
		case 2:HP=140 ; break;
		case 3:HP=150 ; break;
		case 4:HP=125 ; break;
		case 5:HP=130 ; break;
		case 6:HP=140 ; break;
		case 7:HP=180 ; break;
		case 8:HP=170 ; break;
		case 9:HP=150 ; break;
	}
	return (HP);
}
/*
	This function determines the effectiveness of an attack through the types of the two pokemons.
	@param (int) Pok is the Pokemon attacking
	@param (int) OPok is the Pokemon beng attacked
	@return (int) it will return a 1 or 1.5 as effectiveness based on pokemon types
*/
float effectiveness(int Pok, int OPok)
{
	float effectiveness=1;
	if ((Pok==1||Pok==2||Pok==3)&&(OPok==7||OPok==8||OPok==9))
	effectiveness=1.5;
	if((Pok==7||Pok==8||Pok==9)&&(OPok==4||OPok==5||OPok==6))
	effectiveness=1.5;
	if((Pok==4||Pok==5||Pok==6)&&(OPok==1||OPok==2||OPok==3))
	effectiveness=1.5;
	return (effectiveness);
}
/*
	This function returns the the initial AP values of pokemons 1-9.
	@param (int) Pok is the number of Pokemon 
	@return (int) it will return an integer with the AP value per pokemon
*/
int initial_ap(int Pok)
{
	int AP;
	switch(Pok)
	{
		case 1:AP=40 ; break;
		case 2:AP=60 ; break;
		case 3:AP=60 ; break;
		case 4:AP=70 ; break;
		case 5:AP=50 ; break;
		case 6:AP=60 ; break;
		case 7:AP=20 ; break;
		case 8:AP=40 ; break;
		case 9:AP=50 ; break;
	}
	return (AP);
}
/*
	This function chooses a random pokemon for the opponent
	@param (int) OPok1 is the number of Pokemon 1
	@param (int) OPok2 is the number of Pokemon 2
	@param (int) OPok3 is the number of Pokemon 3
	@return (int) it will return an integer value corresponding to the chosen pokemon
*/
int rand_OPok(int OPok1,int OPok2,int OPok3)
{
	srand (time(NULL));
	int SPok;
	SPok = rand()%3+1;
	switch(SPok)
	{
		case 1: SPok = OPok1; break;
		case 2: SPok = OPok2; break;
		case 3: SPok = OPok3; break;
	}
	return (SPok);
}
/*
	This function prints the pokemon name based on the Pokemon value
	@param (int) Pok is the number of Pokemon 
	@return (void) no return value
*/
void pokemon_name(int Pok)
{
	switch(Pok)
	{
		case 1: printf ("Bulbasaur"); break;
		case 2: printf ("Bellsprout"); break;
		case 3: printf ("Oddish"); break;
		case 4: printf ("Charmander"); break;
		case 5: printf ("Ninetails"); break;
		case 6: printf ("Ponyta"); break;
		case 7: printf ("Squirtle"); break;
		case 8: printf ("Psyduck"); break;
		case 9: printf ("Seel"); break;
	}
}
/*
	This function prints the pokemon ascii art based on the Pokemon value
	@param (int) Pok is the number of Pokemon 
	@return (void) no return value
*/
void pokemon_print(int Pok)
{
	switch(Pok)
	{
		case 1: bulbasaur_print(); break;
		case 2: bellsprout_print(); break;
		case 3: oddish_print(); break;
		case 4: charmander_print(); break;
		case 5: ninetails_print(); break;
		case 6: ponyta_print(); break;
		case 7: squirtle_print(); break;
		case 8: psyduck_print(); break;
		case 9: seel_print(); break;
	}
}
/*
	This function prints the HP bar of the current pokemon 
	@param (int) x is the current HP of the Pokemon
	@param (int) z is the maximum HP of the Pokemon 
	@return (void) no return value
*/
void HPBar(int x,int z)
{
	float percent, remaining;
	percent = x*1.0/z;
	percent = percent * 42 ;
	remaining = 42-percent;
	for (;percent>0;percent--)
	{
		printf ("*");
	}
	for (;remaining>0;remaining--)
	{
		printf ("-");
	}
	printf ("\n\n");
}

/*
	This function prints bulbasaur ascii art
	@param () no parameter
	@return (void) no return value
*/
void bulbasaur_print()
{
	printf ("                                           /\n");
	printf ("                        _,.------....___,.' ',.-.\n");
	printf ("                     ,-'          _,.--\"        |\n");
	printf ("                   ,'         _.-'              .\n");
	printf ("                  /   ,     ,'                   `\n");
	printf ("                 .   /     /                     ``.\n");
	printf ("                 |  |     .                       \\.\\\n");
	printf ("       ____      |___._.  |       __               \\ `.\n");
	printf ("     .'    `---""       ``\\\"-.--\\\"'`  \\               .  \\\n");
	printf ("    .  ,            __               `              |   .\n");
	printf ("    `,'         ,-\"'  .               \\             |    L\n");
	printf ("   ,'          '    _.'                -._          /    |\n");
	printf ("  ,`-.    ,\".   `--'                      >.      ,'     |\n");
	printf (" . .'\\'   `-'       __    ,  ,-.         /  `.__.-      ,'\n");
	printf (" ||:, .           ,'  ;  /  / \\ `        `.    .      .'/\n");
	printf (" j|:D  \\          `--'  ' ,'_  . .         `.__, \\   , /\n");
	printf ("/ L:_  |                 .  \"' :_;                `.'.'\n");
	printf (".    \"\"'                  \"\"\"\"\"'                    V\n");
	printf (" `.                                 .    `.   _,..  `\n");
	printf ("   `,_   .    .                _,-'/    .. `,'   __  `\n");
	printf ("    ) \\`._        ___....----\"'  ,'   .'  \\ |   '  \\  .\n");
	printf ("   /   `. \"`-.--\"'         _,' ,'     `---' |    `./  |\n");
	printf ("  .   _  `\"\"'--.._____..--\"   ,             '         |\n");
	printf ("  | .\" `. `-.                /-.           /          ,\n");
	printf ("  | `._.'    `,_            ;  /         ,'          .\n");
	printf (" .'          /| `-.        . ,'         ,           ,\n");
	printf (" '-.__ __ _,','    '`-..___;-...__   ,.'\\ ____.___.'\n");
	printf (" `\"^--'..'   '-`-^-'\"--    `-^-'`.''\"\"\"\"\"`.,^.`.--' \n");
}
/*
	This function prints bellsprout ascii art
	@param () no parameter
	@return (void) no return value
*/
void bellsprout_print()
{
	printf ("                _.--\"'\"\"\"--._\n");
	printf ("              .\"             `.\n");
	printf ("             /                 .\n");
	printf ("            j                   .\n");
	printf ("            |                   |\n");
	printf ("            |                   |\n");
	printf ("            | (')              j\n");
	printf ("            `                 ,`.\n");
	printf ("             \\               ,^. `.\n");
	printf ("              .             /   \\  .\n");
	printf ("              |            /     . |\n");
	printf ("              |          ,'      | |\n");
	printf ("             ,'---..___ /        | |\n");
	printf ("            ' `--..___ \"`.      .  |\n");
	printf ("             `\"--....___.'     /  j__.....__\n");
	printf ("                              /   |         `.\n");
	printf ("                             / _,------._     `.\n");
	printf ("                            /,+_         `.     `.\n");
	printf ("                          ,'    `-.        \\      .\n");
	printf ("                         .         `.       \\      \\\n");
	printf ("                         |           `.     |       \\\n");
	printf ("                         |             `.   |_,..__  .\n");
	printf ("                         |\\              \\  |      `.|\n");
	printf ("                         | `.,--------._  \\ |        `\n");
	printf ("                         |  |           `. \\|\n");
	printf ("                         |  |             `.|\n");
	printf ("                         |  |\n");
	printf ("                         |  |\n");
}
/*
	This function prints oddish ascii art
	@param () no parameter
	@return (void) no return value
*/
void oddish_print()
{
	printf ("                           .-\"--.__\n");
	printf ("          _                / '+.--'\n");
	printf ("           \\.-._          j / |\n");
	printf ("            \\`-.`._      . j  |\n");
	printf ("             \\  `. `.    | |  L                        _,,--+='\n");
	printf ("              L   `. `-. | |   \\                  _.-+'    /\n");
	printf ("              |     \\   j  |    \\            _,-'\" .'    ,'\n");
	printf ("              .      \\  |  |     \\         ,'   _,'    ,'\n");
	printf ("               \\      `j   |      \\      .'   ,'      /\n");
	printf ("                `.     |   |       \\   ,'   ,'       /\n");
	printf ("                  \\    |   |        \\ /    /        /\n");
	printf ("  _,-''\"\"\"\"'\"\"'\"\"`--. j    |         V    /      _,+............._\n");
	printf ("-=`...-----...__     `|    |         .   /   _.-'        _,.--\"\",..=.\n");
	printf ("      `-.       `._   |    |          L,'  ,'       _,.-'    ,-'\n");
	printf ("         `.        `. |    |          |  .'     _.-'       ,'\n");
	printf ("            .        \\|    '          L/    _,-'          /\n");
	printf ("             `._      `.    L        /   _,'            ,'\n");
	printf ("                `-._    \\   `       ,' ,'             ,'\n");
	printf ("                    `-.. `   \\     /,-'           _.-'\n");
	printf ("                      ,'\"-..  .   /_,..---\"`+'\"\"\"\"\n");
	printf ("                     /           '           `.\n");
	printf ("                    j                          .\n");
	printf ("                   .                           |\n");
	printf ("                   |   .-.       ,.            |\n");
	printf ("                   |    -'       `.'           |\n");
	printf ("                   `                           '\n");
	printf ("                    `.      .--.             ,'\n");
	printf ("                      `.    `._|          ,-'\n");
}
/*
	This function prints charmander ascii art
	@param () no parameter
	@return (void) no return value
*/
void charmander_print()
{
	printf ("              _.--\"\"`-..\n");
	printf ("            ,'          `.\n");
	printf ("          ,'          __  `.\n");
	printf ("         /|          \" __   \\\n");
	printf ("        , |           / |.   .\n");
	printf ("        |,'          !_.'|   |\n");
	printf ("      ,'             '   |   |\n");
	printf ("     /              |`--'|   |\n");
	printf ("    |                `---'   |\n");
	printf ("     .   ,                   |                       ,\".\n");
	printf ("      ._     '           _'  |                    , ' \\ `\n");
	printf ("  `.. `.`-...___,...---\"\"    |       __,.        ,`\"   L,|\n");
	printf ("  |, `- .`._        _,-,.'   .  __.-'-. /        .   ,    \\\n");
	printf ("-:..     `. `-..--_.,.<       `\"      / `.        `-/ |   .\n");
	printf ("  `,         \"\"\"\"'     `.              ,'         |   |  ',,\n");
	printf ("    `.      '            '            /          '    |'. |/\n");
	printf ("      `.   |              \\       _,-'           |       ''\n");
	printf ("        `._'               \\   '\"\\                .      |\n");
	printf ("           |                '     \\                `._  ,'\n");
	printf ("           |                 '     \\                 .'|\n");
	printf ("           |                 .      \\                | |\n");
	printf ("           |                 |       L              ,' |\n");
	printf ("           `                 |       |             /   '\n");
	printf ("            \\                |       |           ,'   /\n");
	printf ("          ,' \\               |  _.._ ,-..___,..-'    ,'\n");
	printf ("         /     .             .      `!             ,j'\n");
	printf ("        /       `.          /        .           .'/\n");
	printf ("       .          `.       /         |        _.'.'\n");
}
/*
	This function prints ninetails ascii art
	@param () no parameter
	@return (void) no return value
*/
void ninetails_print()
{
	printf ("        ,-\"\"'-.._\n");
	printf ("   .---'\"\" \">` - `--\n");
	printf ("   `.      `-._  .`-.\n");
	printf ("     `-.       \\ .` : -.\n");
	printf ("      _.>._     / ` `:..,\n");
	printf (" ,.../...._`\"-./    '.|, `\n");
	printf ("`---.._\"'-.`-._    |    \"'--.\n");
	printf ("       `--.\\`. `._,'         `.---------------.._\n");
	printf ("            \"-'--.___          \\`'\"-..__         `-._\n");
	printf ("                     `.\"`-\\     ` `\"--..\"`-.-..__    `\".\n");
	printf ("                       `.  `.     |``._ `--. `-..`\"-._`.\\-.\n");
	printf ("                         \\   -....' `-.`-.  `-._ `-.  `-.\\ `.\n");
	printf ("                          `-.__  `.`-. `. `._   `._ `-.  `.  `.\n");
	printf ("                               `-..`` `. `.  `.    `.  `-.     \\\n");
	printf ("                                   \\`.` `  `.  `.    `.   `-.   `.\n");
	printf ("                                    `.`-'`.  \\   .     `.    `.   \\\n");
	printf ("                                      `..  \\  \\  \\      `.    `.,_`.\n");
	printf ("                                         \\` \\  .   `.     '\\     `.`.`._\n");
	printf ("                                          \\``.  \\    \\     \\`.    |\n");
	printf ("                                           ' '.  \\    \\     \\ \\   L\n");
	printf ("                                             \\ \\  '    `    '. `.  \\\n");
	printf ("                                              ` `. \\    `    '.  `. `.\n");
	printf ("                                               `. `,`.   `.   `.   `._.\n");
	printf ("                                                 `-  \\._   `.  `.     \"`\n");
	printf ("                                                      ` `.   `.  .\n");
	printf ("                                                          `-. ``-.:-.\n");
	printf ("                                                              -.`. '\"-'\n");
	printf ("                                                                 `\"-. mh\n");
}
/*
	This function prints ponyta ascii art
	@param () no parameter
	@return (void) no return value
*/
void ponyta_print()
{
	printf ("                    .' .\n");
	printf ("                   .| '\\\n");
	printf ("           _...___/`'   .\n");
	printf ("         ,'             |\n");
	printf ("     ,|,\"             )/|                             , .\n");
	printf ("    / |              / , .                            \\` \\\n");
	printf ("   /            ...-'  ',                              .  \\\n");
	printf ("  .           ,>      .                                |   |\n");
	printf ("  |          .'   ___`,                  .'  ,--.._,.-'/  ,'\n");
	printf ("..|          |.-\"', /                  ,' | /       .\"'   '.\n");
	printf ("\\ '          |  ,'//                   .'  \"    __,._'    |\n");
	printf (" \\ `         /.\"_/'_,                 '.       /         _'\n");
	printf ("  `.\\     _,'   \\.`  ) ,^.              `     '       ,-\"\n");
	printf ("    |.  .'  _   | `. '-  `,            , \\     `.    ,-\n");
	printf ("    | `w  ,\" |  |   \\   .'   _,_ :\"'. / 7 . ,`..'   .'\n");
	printf ("    '|    `.'  /     \\   `-'\"   `   _:_,.}|  :  _. ,'\n");
	printf ("     \\       .'       `-.      _,.-\"       `-+-`  '\n");
	printf ("     |       |           ``--\"'               `.\n");
	printf ("     \\   .- .                                   \\\n");
	printf ("      `.._,\":                                    \\\n");
	printf ("            '                                    `.  '-7\n");
	printf ("             \\                                  .'`-\"  :\n");
	printf ("              \\                        .        `      `-'\n");
	printf ("             j \\                       `.        `.     |\n");
	printf ("             |  `.  |      .^,'.       ,.+        :    _'\n");
	printf ("             |   |`.|      |    \\,  ,-'  :`.       \\  /_.,\n");
	printf ("            /    |  |     /     .,-'.     `.`.      \\   /\n");
	printf ("           /    .' j     / _._,\"     `      ':`.     . (\n");
	printf ("          /    /,-\"|    j  `.         `-.    |  .    |/\n");
	printf ("          .   `'   |    |    7           |   |   |   |\n");
	printf ("           `.   .  |    |  v'            |  .'   |   |\n");
	printf ("             `.  `.|   j'.'              |  |    |  j\n");
	printf ("               \\   |   |                j   |   j   |\n");
	printf ("                `.j   /\\                |_,j    |  j\n");
	printf ("                  /  /`\"              ,\"   |    '  |\n");
	printf ("                 /  j                 '_,.-'   /.-'|\n");
	printf ("                |   |                         /__.-'\n");

}
/*
	This function prints squirtle ascii art
	@param () no parameter
	@return (void) no return value
*/
void squirtle_print()
{
	printf ("               _,........__\n");
	printf ("            ,-'            \"`-.\n");
	printf ("          ,'                   `-.\n");
	printf ("        ,'                        \\\n");
	printf ("      ,'                           .\n");
	printf ("      .'\\               ,\"\".       `\n");
	printf ("     ._.'|             / |  `       \\\n");
	printf ("     |   |            `-.'  ||       `.\n");
	printf ("     |   |            '-._,'||       | \\\n");
	printf ("     .`.,'             `..,'.'       , |`-.\n");
	printf ("     l                       .'`.  _/  |   `.\n");
	printf ("     `-.._'-   ,          _ _'   -\" \\  .     `\n");
	printf ("`.\"\"\"\"\"'-.`-...,---------','         `. `....__.\n");
	printf (".'        `\"-..___      __,'\\          \\  \\     \\\n");
	printf ("\\_ .          |   `\"\"\"\"'    `.           . \\     \\\n");
	printf ("  `.          |              `.          |  .     L\n");
	printf ("    `.        |`--...________.'.        j   |     |\n");
	printf ("      `._    .'      |          `.     .|   ,     |\n");
	printf ("         `--,\\       .            `7\"\"' |  ,      |\n");
	printf ("            ` `      `            /     |  |      |    _,-'\"\"\"`-.\n");
	printf ("             \\ `.     .          /      |  '      |  ,'          `.\n");
	printf ("              \\  v.__  .        '       .   \\    /| /              \\\n");
	printf ("               \\/    `\"\"\\\"\"\"\"\"\"\"`.       \\   \\  /.''                |\n");
	printf ("                `        .        `._ ___,j.  `/ .-       ,---.     |\n");
	printf ("                ,`-.      \\         .\"     `.  |/        j     `    |\n");
	printf ("               /    `.     \\       /         \\ /         |     /    j\n");
	printf ("              |       `-.   7-.._ .          |\"          '         /\n");
	printf ("              |          `./_    `|          |            .     _,'\n");
	printf ("              `.           / `----|          |-............`---'\n");
	printf ("                \\          \\      |          |\n");
	printf ("               ,'           )     `.         |\n");
	printf ("                7____,,..--'      /          |\n");
	printf ("                                  `---.__,--.'\n");
}
/*
	This function prints psyduck ascii art
	@param () no parameter
	@return (void) no return value
*/
void psyduck_print()
{
	printf ("                              ,-'   ,\"\",\n");
	printf ("                             / / ,-'.-'\n");
	printf ("                   _,..-----+-\".\".-'_,..\n");
	printf ("           ,...,.\"'             `--.---'\n");
	printf ("         /,..,'                     `.\n");
	printf ("       ,'  .'                         `.\n");
	printf ("      j   /                             `.\n");
	printf ("      |  /,----._           ,.----.       .\n");
	printf ("     ,  j    _   \\        .'  .,   `.     |\n");
	printf ("   ,'   |        |  ____  |         | .\"--+,^.\n");
	printf ("  /     |`-....-',-'    `._`--....-' _/      |\n");
	printf (" /      |     _,'          `--..__  `        '\n");
	printf ("j       | ,-\"'    `    .'         `. `        `.\n");
	printf ("|        .\\                        /  |         \\\n");
	printf ("|         `\\                     ,'   |          \\\n");
	printf ("|          |                    |   ,-|           `.\n");
	printf (".         ,'                    |-\"'  |             \\\n");
	printf (" \\       /                      `.    |              .\n");
	printf ("  ` /  ,'                        |    `              |\n");
	printf ("   /  /                          |     \\             |\n");
	printf ("  /  |                           |      \\           /\n");
	printf (" /   |                           |       `.       _,\n");
	printf (".     .                         .'         `.__,.',.----,\n");
	printf ("|      `.                     ,'             .-\"\"      /\n");
	printf ("|        `._               _.'               |        /\n");
	printf ("|           `---.......,--\"                  |      ,'\n");
	printf ("'                                            '    ,'\n");
	printf (" \\                                          /   ,'\n");
	printf ("  \\                                        /  ,'\n");
	printf ("   \\                                      / ,'\n");
	printf ("    `.                                   ,+'\n");
	printf ("      >.                               ,'\n");
	printf ("  _.-'  `-.._                      _,-'-._\n");
	printf (",__          `\",-............,.---\"       `.\n");
	printf ("   \\..---. _,-'            ,'               `.\n");
	printf ("          \"                '..,--.___,-\"\"\"---'\n");
}
/*
	This function prints seel ascii art
	@param () no parameter
	@return (void) no return value
*/
void seel_print()
{
	printf ("                            _,.--\"\"\"'--._\n");
	printf ("                          ,\"             `.         _,.--'\"\"\"\"--.._\n");
	printf ("                         /                 `.     ,\"               `.\n");
	printf ("                        |  ,                 \\   '                   `.\n");
	printf ("                        '.'                   \\ /                -..   .\n");
	printf ("                         j                     '                    \\  |\n");
	printf ("                         |                                    .._    . |\n");
	printf ("                         .    .       _...         _,..._        `.  :'\n");
	printf ("                          `-./      ,'    `.      /      \"`.      |  ;\n");
	printf ("                             '.   ,'       |     (          \\     .-'\n");
	printf ("                               `\"'         |      \\          `-..'\n");
	printf ("                                          /        \\\n");
	printf ("                                        ,'          \\\n");
	printf ("                                     _,'             `.\n");
	printf ("                                 _,-'                  \\\n");
	printf ("                               ,'                       \\\n");
	printf ("                              /  /\\                      \\\n");
	printf ("                             /  /  \\                      \\\n");
	printf ("                            /  /    \\                      l\n");
	printf ("                         _,.-\"/      '--._                 |\n");
	printf ("                       ,'      `.  '      `.               |\n");
	printf ("                     ,' _..          _      `.             |\n");
	printf ("                    ,   _  `       ,' `.      \\            |\n");
	printf ("                   .  .\".`          ...        \\           '\n");
	printf ("  _.--\"\"`--....--\"'|  |`' |       .(_) |        .         /\n");
	printf (",'  _              |  `../        `.__.'        |        /\n");
	printf ("| ,'              ,'-\"'--._,...  ______         |    _  /\n");
	printf ("|/  _.           .  .      \\_,'\"'      `-.      '     `'..__,...----._\n");
	printf ("' ,'             | | \\               ,'|  \\    /                      `\n");
	printf (" `|          _,-\"'.|  \\ .---,-._    /  |   | .' __                \"\"`-.\\\n");
	printf ("  `.     _.-'      |  .:   j    `-.j   |  /.'--'  `.           .       |\n");
	printf ("    `'\"\"'           `-''   '     ,'|   | ,'         `.          \\      |\n");
	printf ("                        `-......'--...`-'             \\          .    ,'\n");
	printf ("                                                       `-._      |_,.'\n");
	printf ("                                                           `\"---\"' \n");
}
/*
	This function prints opponent ascii art
	@param () no parameter
	@return (void) no return value
*/
void opponent_print()
{
	printf ("				       ./++++/-     \n");
	printf ("				       osooooos.    \n");
	printf ("				      .h+osdo+do    \n");
	printf ("				      +y::--:-oh-    \n");
	printf ("				       .:-:::::`     \n");
	printf ("				      .:/++///:-    \n");	
	printf ("				.//. .o+ossssoos/   \n");	
	printf ("				://`.-:+-oss-/+-.-  \n");
	printf ("				 .-.--ss+++++ohy:-  \n");
	printf ("				  `.-.y:------hh/-. \n");
	printf ("				     `/://////om+-- \n");
	printf ("				     -::-------y/-: \n");
	printf ("				     /yyyyyyyyss.--:\n");
	printf ("				     shhhhhhhhhh---.\n");
	printf ("				     ohhhhhhhhhh:.` \n");
	printf ("				     :hhhho:hhhh+   \n");
	printf ("				     `yhhh: shhhs   \n");
	printf ("				      syyy: -yyyy   \n");
	printf ("		 		     :ooo.  /soo`  \n");
	printf ("				      `///   `///   \n");
	printf ("				       .--     ::   \n");
	printf ("				       .//`    --.  \n");
	printf ("				   -::+o+/-    ooo: \n");
	printf ("				   .----.-`   `//:/-\n");
	
}
