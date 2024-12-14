#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct booking
{
	int code;
	char booked;
	char name[30];
	char surname[30];
}bk;

struct booking seats102[12];
struct booking seats311[12];
struct booking seats444[12];
struct booking seats519[12];
int sum_free(struct booking* arr);
void list_free(struct booking* arr);
void list_passengers(struct booking* arr);
void ticket(struct booking* arr, int race);
void ticket_cancel(struct booking* arr, int race);
void save_file();

void main()
{
	int race = 0;
	char ch = 'a';
	char* booked = ' ';
	char name[30], surname[30];
	int ch1 = 1;

	int res = 0;
	int seat = 0;
	struct booking* actual_seat = seats102;

	int i_102 = 0;
	int i_311 = 0;
	int i_444 = 0;
	int i_519 = 0;
	int i = 0;
	FILE* fp;
	char line[255];
	int num_race = 0;
	char stt[255];


	fp = fopen("data_air.txt", "r");

	if (fp == NULL)
	{
		printf("\nFile not Found. Initialization started.");
		for (i = 0; i < 12; i++)
		{
			seats102[i].code = i + 1;
			seats311[i].code = i + 1;
			seats444[i].code = i + 1;
			seats519[i].code = i + 1;


			seats102[i].booked = 'N';
			seats311[i].booked = 'N';
			seats444[i].booked = 'N';
			seats519[i].booked = 'N';

			strcpy(seats102[i].name, "");
			strcpy(seats311[i].name, "");
			strcpy(seats444[i].name, "");
			strcpy(seats519[i].name, "");

			strcpy(seats102[i].surname, "");
			strcpy(seats311[i].surname, "");
			strcpy(seats444[i].surname, "");
			strcpy(seats519[i].surname, "");

		}
	}
	else
	{
		printf("\nReading from file. Wait a second...");
		while (fgets(line, 255, fp) != NULL) {
			strcpy(stt, line);


			num_race = atoi(strtok(stt, ","));
			seat = atoi(strtok(NULL, ","));
			booked = strtok(NULL, ",");
			strcpy(name, strtok(NULL, ","));
			strcpy(surname, strtok(NULL, ","));
			surname[strlen(surname) - 1] = '\0';

			if (num_race == 102)
			{
				seats102[i_102].code = seat;
				seats102[i_102].booked = booked[0];
				strcpy(seats102[i_102].name, name);
				strcpy(seats102[i_102].surname, surname);

				i_102++;
			}
			else if (num_race == 311)
			{
				seats311[i_311].code = seat;
				seats311[i_311].booked = booked[0];
				strcpy(seats311[i_311].name, name);
				strcpy(seats311[i_311].surname, surname);

				i_311++;
			}
			else if (num_race == 444)
			{
				seats444[i_444].code = seat;
				seats444[i_444].booked = booked[0];
				strcpy(seats444[i_444].name, name);
				strcpy(seats444[i_444].surname, surname);

				i_444++;
			}
			else if (num_race == 519)
			{
				seats519[i_519].code = seat;
				seats519[i_519].booked = booked[0];
				strcpy(seats519[i_519].name, name);
				strcpy(seats519[i_519].surname, surname);

				i_519++;
			}

		}
		fclose(fp);

	}


	do {
		system("cls");
		ch = ' ';
		printf("\n==================================");
		printf("\n\n");
		printf("  Airline Ticket booking ");
		printf("\n");
		printf("\n==================================\n");
		printf("\n Choose your flight: \n");
		printf("\n 1 102 ");
		printf("\n 2 311 ");
		printf("\n 3 444 ");
		printf("\n 4 519 \n");
		printf("\n 0 Exit \n");
		printf("\nEnter your Choice:  ");
		scanf(" %d", &ch1);
		switch (ch1)
		{
		case 1:
			race = 102;
			break;
		case 2:
			race = 311;
			break;

		case 3:
			race = 444;
			break;

		case 4:
			race = 512;
			break;

		case 0:
			save_file();
			exit(0);
			break;

		default:
			printf("Wrong choice !");
			break;
		}
		system("cls");



		if (race == 102)
			actual_seat = &seats102;
		else if (race == 311)
			actual_seat = &seats311;
		else if (race == 444)
			actual_seat = &seats444;
		else
			actual_seat = &seats519;



		do {
			printf("\n============ flight #%d ============", race);
			printf("\n\n");
			printf("  Airline Ticket booking ");
			printf("\n");
			printf("\n=======================================\n");

			printf("\n a) Number of free seats");
			printf("\n b) List of free seats");
			printf("\n c) List of passengers ");
			printf("\n d) Book the Ticket");
			printf("\n e) Cancel booking");
			printf("\n f) Upper menu\n");
			printf("\nEnter your Choice:  \n");
			scanf(" %c", &ch);
			switch (ch)
			{
			case 'a':
				res = sum_free(actual_seat);
				printf("\n=======================================\n\n");
				printf("Free seats %d ", res);
				printf("\n=======================================\n");
				printf("\n\n");
				printf("Press any key\n");
				getch();
				break;

			case 'b':
				list_free(actual_seat);
				printf("Press any key");
				getch();
				break;

			case 'c':
				list_passengers(actual_seat);
				printf("Press any key");
				getch();
				break;

			case 'd':
				ticket(actual_seat, race);
				break;

			case 'e':
				ticket_cancel(actual_seat, race);
				break;


			case 'f':
				system("cls");
				break;

			default:
				printf("Wrong choice !");
				printf("\n\n");
				printf("Press any key");
				getch();
				break;
			}
			system("cls");
		} while (ch != 'f');
	} while (ch1 != 0);
}

int sum_free(struct booking* arr)
{
	int i = 0, sum = 0;
	for (i = 0; i < 12; i++)
	{
		if (arr[i].booked == 'N')
			sum++;
	}
	return sum;
}

void list_free(struct booking* arr)
{
	int i = 0, n = 1;
	printf("Free seats on flight:\n");

	for (i = 0; i < 12; i++)
	{
		if (arr[i].booked == 'N')
		{

			printf(" %d. Seat number %d \n", n, arr[i].code);
			n++;
		}
	}

}

void list_passengers(struct booking* arr)
{
	int i = 0, n = 1;
	printf("List of passengers on flight:\n");

	for (i = 0; i < 12; i++)
	{
		if (arr[i].booked == 'Y')
		{

			printf(" %d. Seat number %d  passenger %s %s \n", n, arr[i].code, arr[i].name, arr[i].surname);
			n++;
		}
	}

}

void ticket(struct booking* arr, int race)
{
	struct booking bk = { 0,'N',"" };
	int exit_code = 1;
	do {
		system("cls");

		printf("\n============ flight #%d ============", race);
		printf("\n\n");
		printf("  Airline Ticket booking ");
		printf("\n");
		printf("\n=======================================\n");


		printf("Enter seat number You want to book: (0 - for exit) \n");
		scanf(" %d", &bk.code);
		if (bk.code == 0)
			exit_code = 0;
		else if (bk.code < 1 && bk.code>12) {
			printf("Incorrect input. Try once more time. ");
			printf("\n\n");
			printf("Press any key");
			getch();
		}
		else if (arr[bk.code - 1].booked == 'Y')
		{
			printf("Sorry, this seat is already booked. Try once more time.");
			printf("\n\n");
			printf("Press any key");
			getch();
		}
		else
		{
			printf("Enter  passenger name : (0 - for exit) \n");
			scanf(" %s", &bk.name);
			if (bk.name == '0')
				exit_code = 0;
			else
			{
				printf("Enter  passenger surname : (0 - for exit) \n");
				scanf(" %s", &bk.surname);
				if (bk.surname == '0')
					exit_code = 0;
				else
				{
					arr[bk.code - 1].booked = 'Y';
					strcpy(arr[bk.code - 1].name, bk.name);
					strcpy(arr[bk.code - 1].surname, bk.surname);
					printf("\n Congratulations. Booking was successful! \n");
					printf("Do you need one more ticket ? (Yes - 1. No - 0) \n");
					scanf(" %d", &exit_code);
				}

			}
		}
	} while (exit_code == 1);
}



void ticket_cancel(struct booking* arr, int race)
{
	int seat = 0;
	int exit_code = 1;
	do {
		system("cls");

		printf("\n============ flight #%d ============", race);
		printf("\n\n");
		printf("  Airline Ticket booking cancellation ");
		printf("\n");
		printf("\n=======================================\n");


		printf("Enter seat number for cancellation: (0 - for exit) \n");
		scanf(" %d", &bk.code);
		if (bk.code == 0)
			exit_code = 0;
		else if (bk.code < 1 && bk.code>12)
		{
			printf("Incorrect input. Try once more time.");
			printf("\n\n");
			printf("Press any key");
			getch();
		}
		else if (arr[bk.code - 1].booked == 'N') {
			printf("Sorry, this seat is not booked. Try once more time. (0 - for exit) \n");
			printf("\n\n");
			printf("Press any key");
			getch();
		}
		else
		{
			arr[bk.code - 1].booked = 'N';
			strcpy(arr[bk.code - 1].name, "");
			strcpy(arr[bk.code - 1].surname, "");

			printf("\n Congratulations. You have cancelled your ticket! \n");
			printf("Do you need to cancel one more ticket ? (Yes - 1. No - 0)\n ");
			scanf(" %d", &exit_code);

		}
	} while (exit_code == 1);
}


void save_file()
{

	FILE* fp;
	char line[255];
	char* num_race;
	int i = 0;

	fp = fopen("data_air.txt", "w+");

	if (fp == NULL)

		printf("Saving Error.");
	else
	{
		for (i = 0; i < 12; i++)
		{
			sprintf(line, "102,%d,%c,%s ,%s \n", seats102[i].code, seats102[i].booked, seats102[i].name, seats102[i].surname);
			fprintf(fp, line);
			sprintf(line, "311,%d,%c,%s ,%s \n", seats311[i].code, seats311[i].booked, seats311[i].name, seats311[i].surname);
			fprintf(fp, line);
			sprintf(line, "444,%d,%c,%s ,%s \n", seats444[i].code, seats444[i].booked, seats444[i].name, seats444[i].surname);
			fprintf(fp, line);
			sprintf(line, "519,%d,%c,%s ,%s \n", seats519[i].code, seats519[i].booked, seats519[i].name, seats519[i].surname);
			fprintf(fp, line);
		}
		fclose(fp);
	}
}