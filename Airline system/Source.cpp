#include <iostream>
#include <string>
#include <ctime>
using namespace std;
int first_class[5][6],economy_class[15][6],seat_number[120]
,seat_kind[120],Travelers_number[120],Seat_number_index[120];
string ID[1000];
//it Transfers string numbers to integer and if there is a character or it is empty it returns -1
int Trans_string(string s)
{
	int total = 0,multiple=1;
	for (int i = s.size()-1; i >= 0; i--)
	{
		if (s[i] == '0')
		{
			total += multiple * 0;
			multiple *= 10;
		}
		else if (s[i] == '1')
		{
			total += multiple * 1;
			multiple *= 10;
		}
		else if (s[i] == '2')
		{
			total += multiple * 2;
			multiple *= 10;
		}
		else if (s[i] == '3')
		{
			total += multiple * 3;
			multiple *= 10;
		}
		else if (s[i] == '4')
		{
			total += multiple * 4;
			multiple *= 10;
		}
		else if (s[i] == '5')
		{
			total += multiple * 5;
			multiple *= 10;
		}
		else if (s[i] == '6')
		{
			total += multiple * 6;
			multiple *= 10;
		}
		else if (s[i] == '7')
		{
			total += multiple * 7;
			multiple *= 10;
		}
		else if (s[i] == '8')
		{
			total += multiple * 8;
			multiple *= 10;
		}
		else if (s[i] == '9')
		{
			total += multiple * 9;
			multiple *= 10;
		}
		else if (s[i] == '#')
		{
			return -2;
		}
		else
		{
			return -1;
		}
	}
	if (s.size() == 0)
		return -1;
	else
	return total;
}
//..............................................//

//........It checks the similarity between two strings.
//It returns -1 if they are not similar and the index of the array of string if they are the same
int Check_similarity(string ID[1000],string id)
{
	for (int i = 0; i < 1000; i++)
	{
		if (ID[i] == "\0")
		{
			return -1;
			break;
		}
		if (id == ID[i])
		{
			return i;
			break;
		}
	}
}
//................................................................................//

//.........Generating ID serial number..........//
int ID_generator(string ID[1000])
{
	int user_index, random_number ,similar;
	//.........detecting the empty index for the user........//
	for (int i = 0; i < 1000; i++)
	{
		if (ID[i] == "\0")
		{
			user_index = i;
			break;
		}
	}
	//.........Generating the ID number.........//
	while (1) {
		//.........Generating the ID number.........//
		string generated_id;
		for (int i = 0; i < 14; i++)
		{
			random_number = rand() % 10;
			if (random_number == 0)
			{
				generated_id.insert(i, "0");
			}
			else if (random_number == 1)
			{
				generated_id.insert(i, "1");
			}
			else if (random_number == 2)
			{
				generated_id.insert(i, "2");
			}
			else if (random_number == 3)
			{
				generated_id.insert(i, "3");
			}
			else if (random_number == 4)
			{
				generated_id.insert(i, "4");
			}
			else if (random_number == 5)
			{
				generated_id.insert(i, "5");
			}
			else if (random_number == 6)
			{
				generated_id.insert(i, "6");
			}
			else if (random_number == 7)
			{
				generated_id.insert(i, "7");
			}
			else if (random_number == 8)
			{
				generated_id.insert(i, "8");
			}
			else if (random_number == 9)
			{
				generated_id.insert(i, "9");
			}
		}
		//.........Checking for the id similarity.........// 
		similar = Check_similarity(ID, generated_id);
		//.....If non-similar.....//
		if (similar == -1)
		{
			ID[user_index] = generated_id;

			break;
		}
	}
	return user_index;
}
//..............................................//

//..........Checking for the seat number entered by the user............//
bool seat_avalibility(int first_class[5][6], int economy_class[15][6]
	,bool First,bool Economy,int seat)
{
	//......If the user chose the first class......//
	if (First)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (seat == first_class[i][j])
				{
					first_class[i][j] = '\0';
					return 1;
				}
			}
		}
	}
	//.............................................//

	//......If the user choose the economy class......//
	else
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (seat == economy_class[i][j])
				{
					economy_class[i][j] = '\0';
					return 1;
				}
			}
		}
	}
	//...............................................//

	//.........If the seat number entered was taken or wrong.........//
	return 0;
}
//......................................................................//

//..................Modifying arrays after deleting reservation..................// 
void Shift(int Array[120],int index,int shift_number)
{
	for (int i = index; i < 120; i++)
	{
		if (Array[i] == -858993460)
		{
			break;
		}
		Array[i] = Array[i + shift_number];
	}
}
//...............................................................................//

//.................Adding a passenger...............//
void Add_passenger(string ID[1000],int first_class[5][6],int economy_class[15][6],int seat_kind[120]
	,int seat_number[120],int Travelers_number[120],int Seat_number_index[120])
{
	int seat,user_index,seat_index,Travelers;
	string choice;
	bool First = 0, Economy = 0,valid_seat_number;
	//.........Determining the seat index in the array of seat number..........//
	for (int i = 0; i < 120; i++)
	{
		if (i > 0)
		{
			if (Seat_number_index[i] == '\0')
			{
				seat_index = Seat_number_index[i - 1];
				seat_index += Travelers_number[i - 1];
				break;
			}
		}
		else
		{
			if (Travelers_number[i] == '\0')
			{
				seat_index = i;
				break;
			}
		}
	}
	//.........................................................................//
class_kind:

	cout <<"Adding passenger\n\n";
	//.........choose First or Economy class........//
	while (1)
	{
	cout << "Choose the class.\n\n1-First class\n2-Economy class\n0-Main Menu\n";
	getline(cin,choice);
	if (choice == "1")
	{
		First = 1;
		break;
	}
	else if (choice == "2")
	{
		Economy = 1;
		break;
	}
	else if (choice == "0")
	{
		goto Exit;
	}
	else
	{
		system("cls");
		cout << "Adding passenger\n\nWrong choice\n";
	}
	}
	//.............................................//

	//......If the choice is the first class......//
	if (First)
	{
		choose_travelers1:
	 system("cls");
	 cout << "Adding passenger\n\n";
		//.........choose the number of travelers........//
		while (1)
		{
			cout << "Choose the number of travelers (maximum 3 travelers in the first class).\n"
				<< "\n1-1\n2-2\n3-3\n#-Back\n0-Main Menu\n";
			getline(cin, choice);
			if (choice == "1")
			{
				Travelers = 1;
				break;
			}
			else if (choice == "2")
			{
				Travelers = 2;
				break;
			}
			else if (choice == "3")
			{
				Travelers = 3;
				break;
			}
			else if (choice == "#")
			{
				First = 0;
				system("cls");
				goto class_kind;
			}
			else if (choice == "0")
			{
				goto Exit;
			}
			else
			{
				system("cls");
				cout << "Adding passenger\n\nWrong choice\n";
			}
		}
		//.....................................................//

		//..........Choosing the seat number.............//
			system("cls");
			for (int i = 0; i < Travelers; i++)
			{
				choose_seat1:
				while (1)
				{
					cout << "Choose a seat number, enter 0 to go to Main Menu or enter # to go back.\nNote that,"
						<< " the symbol (||) means an aisle and (X) means a taken seat.\n";
					//.........Displaying the seats numbers.........//
					for (int i = 0; i < 5; i++)
					{
						for (int j = 0; j < 6; j++)
						{
							if (j == 2)
							{
								if (first_class[i][j] == '\0')
								{
									cout << "X    ||   ";
								}
								else if ((i * 6) + j + 1 < 9)
								{
									cout << first_class[i][j] << "    ||   ";
								}
								else if ((i * 6) + j + 1 == 9)
								{
									cout << first_class[i][j] << "    ||   ";
								}
								else
								{
									cout << first_class[i][j] << "   ||   ";
								}
							}
							else if (first_class[i][j] == '\0')
							{
								cout << "X   ";
							}
							else
							{
								if ((i * 6) + j + 1 < 9)
								{
									cout << first_class[i][j] << "   ";
								}
								else
								{
									cout << first_class[i][j] << "  ";
								}
							}
						}
						cout << endl;
					}
					//..............................................//

					getline(cin, choice);
					seat = Trans_string(choice);
					if (seat == 0)
					{
						system("cls");
						while (1)
						{
							cout << "Are you sure you want to go to Main Menu. You will lose everything saved.\n\n"\
								<< "1-Sure\n2-Continue adding passenger\n";
							getline(cin, choice);
							//.......If the user sure to go to Main Menu........//
							if (choice == "1")
							{
								Cancel1:
								//........Deleting Data........//
								for (int j = 0; j < Travelers; j++)
								{
									if (seat_number[seat_index + j] % 6 == 0)
									{
										first_class[((seat_number[seat_index + j]) / 6) - 1][5]
											= seat_number[seat_index + j];
									}
									else
									{
										first_class[(seat_number[seat_index + j]) / 6][(seat_number[seat_index + j] % 6) - 1]
											= seat_number[seat_index + j];
									}
								}
								Shift(seat_number, seat_index, Travelers);
								goto Exit;
							}
							//.......If the user want to Continue adding passenger........//
							else if (choice == "2")
							{
								system("cls");
								goto choose_seat1;
							}
							//............Wrong choice.............//
							else
							{
								system("cls");
								cout << "Wrong choice\n";
							}
						}						
					}
					//...........Back...........//
					else if (seat == -2)
					{
						if (i == 0)
						{
							goto choose_travelers1;
						}
						else
						{
							system("cls");
							i--;
							if (seat_number[seat_index + i] % 6 == 0)
							{
								first_class[((seat_number[seat_index + i]) / 6) - 1][5]
									= seat_number[seat_index + i];
							}
							else
							{
								first_class[(seat_number[seat_index + i]) / 6][(seat_number[seat_index + i] % 6) - 1]
									= seat_number[seat_index + i];
							}
							seat_number[seat_index + i] = '\0';
							goto choose_seat1;
						}
					}
					//.......Checking for the seat number entered......//
					valid_seat_number = seat_avalibility(first_class, economy_class, First, Economy, seat);
					//.......If the seat number entered is valid........//
					if (valid_seat_number)
					{
						//......Saving seat number.......//
						seat_number[seat_index+i] = seat;
						break;
					}
					//.......If the seat number entered is not valid........//
					else
					{
						system("cls");
						cout << "Adding passenger\n\n" << "Wrong or taken seat number\n";
					}
				}
				if (i == Travelers - 1)
				{
				    system("cls");
			        cout << "Adding passenger\n\n";
					choose_process_1:
					cout << "Are you sure you want these seats numbers ( ";
					for (int j = 0; j < Travelers; j++)
					{
						if (j == Travelers - 1)
						{
							cout << seat_number[seat_index+j] << " )?\n\n";
							break;
						}
						cout << seat_number[seat_index + j] << " - ";
					}
					cout << "1- Sure\n2- Re-choose\n3- Cancel the process\n";
					getline(cin, choice);
					if (choice == "1"){}
					else if (choice == "2")
					{
						for (int j = 0; j < Travelers; j++)
						{
							if (seat_number[seat_index + j] % 6 == 0)
							{
								first_class[((seat_number[seat_index + j]) / 6) - 1][5]
									= seat_number[seat_index + j];
							}
							else
							{
								first_class[(seat_number[seat_index + j]) / 6][(seat_number[seat_index + j] % 6) - 1]
									= seat_number[seat_index + j];
							}
							seat_number[seat_index + j] = '\0';
						}
						i = 0;
						system("cls");
						goto choose_seat1;
					}
					else if (choice == "3")
					{						
						goto Cancel1;
					}
					else
					{
						system("cls");
						cout << "Adding passenger\n\nWrong Choice\n\n";
						goto choose_process_1;
					}
				}
				system("cls");
			}
		//...............................................//
	}
	//...........................................//

	//.....If the choice is the economy class.....//
	else if (Economy)
	{
	choose_travelers2:
		system("cls");
		cout << "Adding passenger\n\n";
		//.........choosing the number of travelers........//
		while (1)
		{
			cout << "Choose the number of travelers (maximum 4 travelers in the economy class).\n"
				<< "\n1-1\n2-2\n3-3\n4-4\n#-Back\n0-Main Menu\n";
			getline(cin, choice);
			if (choice == "1")
			{
				Travelers = 1;
				break;
			}
			else if (choice == "2")
			{
				Travelers = 2;
				break;
			}
			else if (choice == "3")
			{
				Travelers = 3;
				break;
			}
			else if (choice == "4")
			{
				Travelers = 4;
				break;
			}
			else if (choice == "#")
			{
				Economy = 0;
				system("cls");
				goto class_kind;
			}
			else if (choice == "0")
			{
				goto Exit;
				break;
			}
			else
			{
				system("cls");
				cout << "Adding passenger\n\nWrong choice\n";
			}
		}
		//.....................................................//

		system("cls");
		//.........Choosing the seat number........//
			for (int i = 0; i < Travelers; i++)
			{
			  choose_seat2:
				while (1)
				{
					cout << "Choose a seat number, enter 0 to go to Main Menu or # to go back.\nNote that,"
						<< " the symbol (||) means an aisle and (X) means a taken seat.\n";
					//.........Displaying the seats numbers.........//
					for (int i = 0; i < 15; i++)
					{
						for (int j = 0; j < 6; j++)
						{
							if (j == 2)
							{
								if (economy_class[i][j] == '\0')
								{
									cout << "X    ||   ";
								}
								else if ((i * 6) + j + 1 < 9)
								{
									cout << economy_class[i][j] << "    ||   ";
								}
								else if ((i * 6) + j + 1 == 9)
								{
									cout << economy_class[i][j] << "    ||   ";
								}
								else
								{
									cout << economy_class[i][j] << "   ||   ";
								}
							}
							else if (economy_class[i][j] == '\0')
							{
								cout << "X   ";
							}
							else
							{
								if ((i * 6) + j + 1 < 9)
								{
									cout << economy_class[i][j] << "   ";
								}
								else
								{
									cout << economy_class[i][j] << "  ";
								}
							}
						}
						cout << endl;
					}
					//..............................................//

					getline(cin, choice);
					seat = Trans_string(choice);
					if (seat == 0)
					{
						system("cls");
						while (1)
						{
							cout << "Are you sure you want to go to Main Menu. You will lose everything saved.\n\n"\
								<< "1-Sure\n2-Continue adding passenger\n";
							getline(cin, choice);
							//.......If the user sure to go to Main Menu........//
							if (choice == "1")
							{
								Cancel2:
								//........Modifying seat numbers........//
								for (int j = 0; j < Travelers; j++)
								{
									if (seat_number[seat_index + j] % 6 == 0)
									{
										economy_class[((seat_number[seat_index + j]) / 6) - 1][5]
											= seat_number[seat_index + j];
									}
									else
									{
										economy_class[(seat_number[seat_index + j]) / 6][(seat_number[seat_index + j] % 6) - 1]
											= seat_number[seat_index + j];
									}
								}
								Shift(seat_number, seat_index, Travelers);
								goto Exit;
							}
							//.......If the user wants to Continue adding passenger........//
							else if (choice == "2")
							{
								system("cls");
								goto choose_seat2;
							}
							//........Wrong choice........//
							else
							{
								system("cls");
								cout << "Wrong choice\n";
							}
						}
					}
					else if (seat == -2)
					{
						if (i == 0)
						{
							goto choose_travelers2;
						}
						else
						{
							system("cls");
							i--;
							if (seat_number[seat_index + i] % 6 == 0)
							{
								economy_class[((seat_number[seat_index + i]) / 6) - 1][5]
									= seat_number[seat_index + i];
							}
							else
							{
								economy_class[(seat_number[seat_index + i]) / 6][(seat_number[seat_index + i] % 6) - 1]
									= seat_number[seat_index + i];
							}
							seat_number[seat_index + i] = '\0';
							goto choose_seat2;
						}
					}
					//.......Checking for the seat number entered......//
					valid_seat_number = seat_avalibility(first_class, economy_class, First, Economy, seat);
					//.......If the seat number entered is valid........//
					if (valid_seat_number)
					{
						//......Saving Data.......//
						seat_number[seat_index + i] = seat;
						break;
					}
					//.......If the seat number entered is not valid........//
					else
					{
						system("cls");
						cout << "Adding passenger\n\n" << "Wrong or taken seat number\n";
					}
				}
				//........If the user wanted to go to Main Menu........//
					if (i == Travelers - 1)
					{
					   system("cls");
			           cout << "Adding passenger\n\n";
					choose_process_2:
						cout << "Are you sure you want these seats numbers ( ";
						for (int j = 0; j < Travelers; j++)
						{
							if (j == Travelers - 1)
							{
								cout << seat_number[seat_index + j] << " )?\n\n";
								break;
							}
							cout << seat_number[seat_index + j] << " - ";
						}
						cout << "1- Sure\n2- Re-choose\n3- Cancel the process\n";
						getline(cin, choice);
						if (choice == "1"){}
						else if (choice == "2")
						{
							system("cls");
							for (int j = 0; j < Travelers; j++)
							{
								if (seat_number[seat_index + j] % 6 == 0)
								{
									economy_class[((seat_number[seat_index + j]) / 6) - 1][5]
										= seat_number[seat_index + j];
								}
								else
								{
									economy_class[(seat_number[seat_index + j]) / 6][(seat_number[seat_index + j] % 6) - 1]
										= seat_number[seat_index + j];
								}
								seat_number[seat_index + j] = '\0';
							}
							i = 0;
							goto choose_seat2;
						}
						else if (choice == "3")
						{
							goto Cancel2;
						}
						else
						{
							system("cls");
							cout << "Adding passenger\n\nWrong Choice\n\n";
							goto choose_process_2;
						}
					}
					system("cls");
			}
		//.....................................//
	}
    //...........................................//

	//.........If the procees is done successfully..........//
	user_index = ID_generator(ID);
	cout << "Adding passenger\n\n";
	if (ID[user_index].empty() == 0)
	{
		if (First)
		    seat_kind[user_index] = 1;
		else
			seat_kind[user_index] = 2;
		Seat_number_index[user_index] = seat_index;
		Travelers_number[user_index] = Travelers;
		cout << "Your ID is [" << ID[user_index] << "], save it for using later.\n";
		cout << "Enter any key to continue.\n";
		getline(cin, choice);
	}
	//..................................................//

Exit:
	system("cls");
}
//..................................................//

//....................Deleting reservation........................//
void Delete_reservation(string ID[1000], int first_class[5][6]
	, int economy_class[15][6], int seat_kind[120], int seat_number[120],
	int Travelers_number[120], int Seat_number_index[120])
{
	int user_index,seat_index,Travelers,Kind;
	string id;
	cout << "Deleting reservation\n\n";
	cout <<"Enter your ID or enter 0 to Cancel.\n";
Enter_id:
	
	//...................Asking the user to Enter his ID..................//
	getline(cin,id);
	user_index = Check_similarity(ID, id);
	if (id == "0")
	{
		goto Exit;
	}
	else if (user_index == -1)
	{
		system("cls");
		cout << "Deleting reservation\n\nInvalid ID\nPlease enter a valid ID or enter 0 to cancel.\n";
		goto Enter_id;
	}
	//....................................................................//

	seat_index = Seat_number_index[user_index];
	Travelers = Travelers_number[user_index];
	Kind = seat_kind[user_index];
	system("cls");
	cout << "Deleting reservation\n\n";
Delete:
	
	//.......................Asking the user if he is sure...........................//
	cout << "Are you sure you want to delete your reservation?\n1-Sure\n2-Cancel\n";
	getline(cin,id);
	if (id == "2")
		goto Exit;
	else if (id == "1"){}
	else
	{
		system("cls");
		cout << "Deleting reservation\n\nWrong choice\n";
		goto Delete;
	}
	//...............................................................................//
	
	if (Kind == 1)
	{
		for (int j = 0; j < Travelers; j++)
		{
			if (seat_number[seat_index + j] % 6 == 0)
			{
				first_class[((seat_number[seat_index + j]) / 6) - 1][5]
					= seat_number[seat_index + j];
			}
			else
			{
				first_class[(seat_number[seat_index + j]) / 6][(seat_number[seat_index + j] % 6) - 1]
					= seat_number[seat_index + j];
			}
		}
	}
	else if (Kind == 2)
	{
		for (int j = 0; j < Travelers; j++)
		{
			if (seat_number[seat_index + j] % 6 == 0)
			{
				economy_class[((seat_number[seat_index + j]) / 6) - 1][5]
					= seat_number[seat_index + j];
			}
			else
			{
				economy_class[(seat_number[seat_index + j]) / 6][(seat_number[seat_index + j] % 6) - 1]
					= seat_number[seat_index + j];
			}
		}
	}
	Shift(seat_kind, user_index, 1);
	Shift(seat_number, seat_index, Travelers);
	Shift(Travelers_number, user_index, 1);
	Shift(Seat_number_index, user_index, 1);
	for (int i = user_index; i < 1000; i++)
	{
		if (ID[i] == "\0")
			break;
		ID[i] = ID[i + 1];
	}
	system("cls");
	cout << "Your Reservation deleted successfully. Enter any key to continue.\n";
	getline(cin, id);
Exit:
	system("cls");
}
//................................................................//

//.........................Show seeats numbers...........................//
void Show_seeting(string ID[1000],int seat_kind[120], int seat_number[120],
	int Travelers_number[120], int Seat_number_index[120])
{
	int user_index, seat_index, Travelers, Kind, Seats[15][6] = {'\0'};
	string id;
	cout << "Show Seeting\n\n";
	cout << "Enter your ID or enter 0 to Cancel.\n";
Enter_id:

	//...................Asking the user to Enter his ID..................//
	getline(cin, id);
	user_index = Check_similarity(ID, id);
	if (id == "0")
	{
		goto Exit;
	}
	else if (user_index == -1)
	{
		system("cls");
		cout << "Show Seeting\n\nInvalid ID\nPlease enter a valid ID or enter 0 to cancel.\n";
		goto Enter_id;
	}
	//....................................................................//
	seat_index = Seat_number_index[user_index];
	Travelers = Travelers_number[user_index];
	Kind = seat_kind[user_index];
	system("cls");
		for (int j = 0; j < Travelers; j++)
		{
			if (seat_number[seat_index + j] % 6 == 0)
			{
				Seats[((seat_number[seat_index + j]) / 6) - 1][5]
					= seat_number[seat_index + j];
			}
			else
				{
					Seats[(seat_number[seat_index + j]) / 6][(seat_number[seat_index + j] % 6) - 1]
						= seat_number[seat_index + j];
				}
		}
	cout << "Show Seeting\n\n";
	if (Kind == 1)
	{
		for (int i = 0; i < 5;i++)
		{
			for (int j = 0;j < 6;j++)
			{
				if (j == 2)
				{
					if (Seats[i][j] == '\0')
					{
						cout << "X    ||    ";
					}
					else if ((i * 6) + j + 1 < 9)
					{
						cout << Seats[i][j] << "    ||    ";
					}
					else if ((i * 6) + j + 1 == 9)
					{
						cout << Seats[i][j] << "    ||    ";
					}
					else
					{
						cout << Seats[i][j] << "   ||    ";
					}
				}
				else if (Seats[i][j] == '\0')
				{
					cout << "X   ";
				}
				else
				{
					if ((i * 6) + j + 1 < 9)
					{
						cout << Seats[i][j] << "   ";
					}
					else
					{
						cout << Seats[i][j] << "  ";
					}
				}
			}
			cout << "\n";
		}
	}
	else if (Kind == 2)
	{
		for (int i = 0; i < 15;i++)
		{
			for (int j = 0;j < 6;j++)
			{
				if (j == 2)
				{
					if (Seats[i][j] == '\0')
					{
						cout << "X    ||    ";
					}
					else if ((i * 6) + j + 1 < 9)
					{
						cout << Seats[i][j] << "    ||    ";
					}
					else if ((i * 6) + j + 1 == 9)
					{
						cout << Seats[i][j] << "    ||    ";
					}
					else
					{
						cout << Seats[i][j] << "   ||    ";
					}
				}
				else if (Seats[i][j] == '\0')
				{
					cout << "X   ";
				}
				else
				{
					if ((i * 6) + j + 1 < 9)
					{
						cout << Seats[i][j] << "   ";
					}
					else
					{
						cout << Seats[i][j] << "  ";
					}
				}
			}
			cout << "\n";
		}
	}
	cout << "\nEnter any key to continue.\n";
	getline(cin, id);

Exit:
	system("cls");
}
//.......................................................................//

int main ()
{
//.......Set up the seats numbers.......//
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (i < 5)
			{
				first_class[i][j] = (i * 6) + j + 1;
			}
			economy_class[i][j] = (i * 6) + j + 1;
		}
	}
	srand(time(0));
	string choice;
	cout << "Main Menu\n\n";
	while (1)
	{
		while (1)
		{
			cout << "1-Add Passengers\n2-Show Seating\n3-Delete Reservation\n4-Quit\n";
			getline(cin, choice);
			if (choice == "1")
			{
				system("cls");
				Add_passenger(ID, first_class, economy_class, seat_kind, seat_number, Travelers_number, Seat_number_index);
				cout << "Main Menu\n\n";
				break;
			}
			else if (choice == "2")
			{
				system("cls");
				Show_seeting(ID, seat_kind, seat_number, Travelers_number, Seat_number_index);
				cout << "Main Menu\n\n";
				break;
			}
			else if (choice == "3")
			{
				system("cls");
				Delete_reservation(ID, first_class, economy_class, seat_kind, seat_number, Travelers_number, Seat_number_index);
				cout << "Main Menu\n\n";
				break;
			}
			else if (choice == "4")
				return 0;
			else
			{
				system("cls");
				cout << "Main Menu\n\nWrong Choice\n";
				break;
			}
		}
	}
	return 0;
}