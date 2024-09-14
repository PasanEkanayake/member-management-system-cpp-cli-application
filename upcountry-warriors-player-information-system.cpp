#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void logo();
void login();
void registration();
void forgotPassword();
void displayPlayers();
void addUpdatePlayers();
void removePlayer();
void managePlayers();
void manageTeams();
void displayTeams();
void searchPlayers();
void logout();
void searchTeams();
void systemHeader();
void dashboard();
void transition();
void createTeam();
bool checkDuplicates(const string arr[], int size, const string newPlayer);
void updateTeam();
void availableplayers();

//Player personal details structure and also the order of data input in player details file (.txt file)
struct Players
{
	int regNumber;
	string firstname;
	string lastname;
	string dob;
	int age;
	string hometown;
	float runsScored;
};

//Main function
int main() {

	char loginChoice, dashChoice;

	systemHeader();

	logo();

	transition();

	cout << "\n\t\t\t ***** PLEASE MAXIMIZE YOUR COMMAND PROMPT WINDOW TO HAVE A BETTER EXPERIENCE *****\n\n";

	systemHeader();

	cout << "\t\t\t\t\t\tPress '1' to LOGIN\n" << endl;
	cout << "\t\t\t\t\t\tPress '2' to REGISTER\n" << endl;
	cout << "\t\t\t\t\t\tPress '3' if FORGOT PASSWORD\n" << endl;
	cout << "\t\t\t\t\t\tPress '4' to EXIT\n\n\n\n" << endl;
	cout << "\t\t\t\tYour Response\t:  ";
	cin >> loginChoice;
	cin.ignore();
	system("cls");

	switch (loginChoice) {

	case '1': login(); break;
	case '2': registration(); break;
	case '3': forgotPassword(); break;
	case '4': system("cls"); exit(0); break;
	default: systemHeader();
			 cout << "\n\n\t\t\t\tYour have entered an invalid input. Please try again.\n\n";
			 transition();
			 main();
			 break;

	}

	dashboard();

	system("pause>0");

	return 0;

}

//UI's header that appears in every page
void systemHeader() {

	cout << "\t\t\t,___________________________________________________________________________________,\n";
	cout << "\t\t\t|                        U P C O U N T R Y   W A R R I O R S                        |\n";
	cout << "\t\t\t|                             Player Information System                             |\n";
	cout << "\t\t\t|___________________________________________________________________________________|\n\n\n\n";

}

//Function to make the flow of the application smoother
void transition() {

	cout << "\n\n\t\t\t\tPress 'Enter' to continue.";
	system("pause>0");
	system("cls");

}

//Company logo that appears at the beginning of the application
void logo() {

	cout << "\t\t\t\t                                  .        .                     " << endl;
	cout << "\t\t\t\t           ..              :      -.      .             ...      " << endl;
	cout << "\t\t\t\t         -*==+@:            =     =.    .:.          .-@=-=#.    " << endl;
	cout << "\t\t\t\t        -#-+%%#%@=  .-.     :-    +.   .*.     .    +@%#%#==@:   " << endl;
	cout << "\t\t\t\t        -@@@%@=--=@=  .+.    *-   *:   *:    .=  .*%---*%%@@@:   " << endl;
	cout << "\t\t\t\t          *@@#+===--%= .=+    #. .#-. -+   .*...*%--=+==%@@+.    " << endl;
	cout << "\t\t\t\t            +@%%====-=%- .@-. -@..#= -@. .*+ .+#=-=+-=@%@-       " << endl;
	cout << "\t\t\t\t              -@%@+-=-==@- =@:.#*.%*.@:.=@. =%-=-==*@%@.         " << endl;
	cout << "\t\t\t\t               -+%@@*+=--=@:.%@#+    =#@+.-%=--=+#@@#+-          " << endl;
	cout << "\t\t\t\t                   -@@#=+%%@@=-++=  .++:-@@%#==%@%:.             " << endl;
	cout << "\t\t\t\t                      *@@%@%=.=+++  .=+:.:@@@@@+.                " << endl;
	cout << "\t\t\t\t                        .#@*:.+*=-  .+*= :*@*.                   " << endl;
	cout << "\t\t\t\t                     .....@+=-+==   .-=*::*#.....                " << endl;
	cout << "\t\t\t\t                  . :*@*:.+%+#*+:    .++#+@-.:*@*:.              " << endl;
	cout << "\t\t\t\t               .=+...:#@@@@@@*+:.    .-=*@@@@@@#-...+=.          " << endl;
	cout << "\t\t\t\t             :..+@%=...-+%@@@@@*+---=+*@@@@@#+-...=#@*. :-.      " << endl;
	cout << "\t\t\t\t         . :#+.-#@@#=....  -@+*@@@@@@@@*+@- . ..:+%@@*:.+%:...   " << endl;
	cout << "\t\t\t\t       .=:*@@-..=#*-.. . .@@@#:%%::::-=+%@@@..  ..-*#-..+@@*:=.  " << endl;
	cout << "\t\t\t\t         .*@@-.*=.  .  .%%@=.:%@@*-:..:-:.+%%%.     .+*.=@@+.    " << endl;
	cout << "\t\t\t\t            .*%*..=+..#%@-          ..      =@%#..#- .#@+        " << endl;
	cout << "\t\t\t\t               :#*-.#%@-  -@@@@@@@@@@@@@@@@* .=@%#.=+#..         " << endl;
	cout << "\t\t\t\t                 .@%@+ .=*@=@*--.       . =%%- .*@%%..           " << endl;
	cout << "\t\t\t\t              .:%%@++.-.=@#..%*.=::       .*##.=.+*@%#.          " << endl;
	cout << "\t\t\t\t            .#@@%*.  :-=@@@**:+#..-:.: . ..:+%+-.  .#%@@*.       " << endl;
	cout << "\t\t\t\t            .@@@#.   .+@@%@%%%=-+#..---.=#----@-    .#@@@.       " << endl;
	cout << "\t\t\t\t                       .#@@%%%%@+.:#.-%+-===%:                   " << endl;
	cout << "\t\t\t\t                          -@@%%#%@%@=+--=#%.                     " << endl;
	cout << "\t\t\t\t                            .%@%%%%=---%*.                       " << endl;
	cout << "\t\t\t\t                              .*@%%==@=                          " << endl;
	cout << "\t\t\t\t                                .:@@:                            " << endl;

}

//Function to handle User Login
void login() {

	string username, password, uName, pWord;

	systemHeader();

	cout << "\t\t\t\tPlease enter your Username and Password to LOGIN.\n\n\n";
	cout << "\t\t\t\t\tUSERNAME\t:  ";
	getline(cin >> ws, username);
	cout << "\n\t\t\t\t\tPASSWORD\t:  ";
	getline(cin >> ws, password);

	transition();

	ifstream read(username + "_user_login_info.txt");
	getline(read, uName);
	getline(read, pWord);

	if (username == uName && password == pWord) {

		systemHeader();

		cout << "\t\t\t\t\tYou have logged in successfully.\n\n";
		transition();

		systemHeader();

		cout << "\n\n\t\t\t   Welcome to Upcountry Warriors - Player Information System, " << username << endl << endl;
		cout << "\n\n\n\t\t\t\tPress 'Enter' to open the DASHBOARD.";
		system("pause>0");
		system("cls");

	}
	else {

		char tryAgain;

		systemHeader();

		cout << "\n\n\t\t\t\tYou have entered incorrect USERNAME or PASSWORD. Please try again.\n\n\n";
		cout << "\t\t\t\tPress '1' to try LOGIN again.";
		cout << "\n\n\t\t\t\tPress '2' to Go to the initial page.";
		cout << "\n\n\n\n\t\t\t\tYour Response\t:  ";
		cin >> tryAgain;
		cout << endl;
		system("cls");

		if (tryAgain == '1') {

			login();

		}
		else if (tryAgain == '2') {

			main();

		}
		else {

			systemHeader();
			cout << "\n\n\n\t\t\t\tYour response is invalid. So you will be redirected to the initial page.";
			transition();
			main();

		}

	}
	read.close();

}

//Function to handle User Registration
void registration() {

	string username, password, email, alldata, userdata;

	systemHeader();


	cout << "\n\t\t\t\tProvide an USERNAME, EMAIL, and PASSWORD to register.\n\n\n";
	cout << "\t\t\t\t\tUSERNAME\t:  ";
	getline(cin >> ws, username);
	cout << "\n\t\t\t\t\tEMAIL\t\t:  ";
	getline(cin >> ws, email);
	cout << "\n\t\t\t\t\tPASSWORD\t:  ";
	getline(cin >> ws, password);

	transition();

	ifstream read("all_registered_users.txt");

	while (getline(read, alldata)) {

		ifstream readUser(alldata + "_user_login_info.txt");

		while (getline(readUser, userdata)) {

			if (userdata == username) {

				char tryAgain;

				systemHeader();

				cout << "\n\n\t\t\t\tEntered USERNAME already exist. Please try again with a different USERNAME.\n\n\n";
				cout << "\t\t\t\tPress '1' to try REGISTER again.";
				cout << "\n\n\t\t\t\tPress '2' to Go to the initial page.";
				cout << "\n\n\n\n\t\t\t\tYour Response\t:  ";
				cin >> tryAgain;
				cout << endl;
				system("cls");

				if (tryAgain == '1') {

					registration();
					break;

				}
				else if (tryAgain == '2') {

					main();
					break;

				}
				else {

					systemHeader();
					cout << "\n\n\n\t\t\t\tYour response is invalid and you will be redirected to the initial page.";
					transition();
					main();
					break;

				}

			}
			else if (userdata == password) {

				char tryAgain;

				systemHeader();

				cout << "\n\n\t\t\t\tEntered PASSWORD already exist. Please try again with a different PASSWORD.\n\n\n";
				cout << "\t\t\t\tPress '1' to try REGISTER again.";
				cout << "\n\n\t\t\t\tPress '2' to Go to the initial page.";
				cout << "\n\n\n\n\t\t\t\tYour Response\t:  ";
				cin >> tryAgain;
				cout << endl;
				system("cls");

				if (tryAgain == '1') {

					registration();
					break;

				}
				else if (tryAgain == '2') {

					main();
					break;

				}
				else {

					systemHeader();
					cout << "\n\n\n\t\t\t\tYour response is invalid and you will be redirected to the initial page.";
					transition();
					main();
					break;

				}

			}
			else if (userdata == email) {

				char tryAgain;

				systemHeader();

				cout << "\n\n\t\t\t\tEntered EMAIL already exist. Please try again with a new EMAIL.\n\n\n";
				cout << "\t\t\t\tPress '1' to try REGISTER again.";
				cout << "\n\n\t\t\t\tPress '2' to Go to the initial page.";
				cout << "\n\n\n\n\t\t\t\tYour Response\t:  ";
				cin >> tryAgain;
				cout << endl;
				system("cls");

				if (tryAgain == '1') {

					registration();
					break;

				}
				else if (tryAgain == '2') {

					main();
					break;

				}
				else {

					systemHeader();
					cout << "\n\n\n\t\t\t\tYour response is invalid and you will be redirected to the initial page.";
					transition();
					main();
					break;

				}

			}

		}

		readUser.close();

	}

	read.close();

	ofstream userLogin;
	userLogin.open(username + "_user_login_info.txt");
	userLogin << username << endl << password << endl << email;
	userLogin.close();

	ofstream allUsers("all_registered_users.txt", ios::out | ios::app);
	allUsers << username << endl;
	allUsers.close();

	systemHeader();

	cout << "\t\t\t\t\tYou have successfully REGISTERED with the system.\n\n\n";
	transition();
	main();
}

//Function to recover the forgotten password
void forgotPassword() {

	systemHeader();

	char choice;
	string username, email, existUname, existEmail, pword;

	cout << "\n\n\t\t\t\tPress '1' to RECOVER PASSWORD (required vaild EMAIL confirmation.)\n";
	cout << "\n\t\t\t\tPress '2' to try LOGIN again\n";
	cout << "\n\t\t\t\tPress '3' to REGISTER as a new USER\n";
	cout << "\n\t\t\t\tPress '4' to EXIT\n\n";

	cout << "\n\n\t\t\t\tYour Response\t:  ";
	cin >> choice;
	cout << endl;
	system("cls");

	if (choice == '1') {

		systemHeader();
		cout << "\n\n\t\t\t\t\tEnter the USERNAME you remember\t:  ";
		getline(cin >> ws, username);
		system("cls");

		ifstream read(username + "_user_login_info.txt");
		
		if (!read) {

			systemHeader();
			cout << "\n\n\t\t\t\tUSERNAME you entered isn't REGISTERED with the system.";
			cout << "\n\n\t\t\t\tPlease try LOGIN with a vaild USERNAME and PASSWORD.";
			transition();
			main();

		}

		getline(read, existUname);
		getline(read, existEmail);
		getline(read, pword);
		read.close();

		if (username == existUname) {

			systemHeader();
			cout << "\n\n\t\t\t\t\tEnter your EMAIL\t:  ";
			getline(cin >> ws, email);

			if (email == existEmail) {

				cout << "\n\n\t\t\t\t Your recovered USERNAME\t:  " << existUname << endl << endl;
				cout << "\t\t\t\t Your recovered PASSWORD\t:  " << pword << endl << endl;
				transition();
				main();

			}
			else {

				cout << "\n\n\t\t\t\tUSERNAME and EMAIL you entered aren't matching with\n\t\t\t\tany data in the USER LOGIN database.";
				cout << "\n\n\t\t\t\tPlease try LOGIN or REGISTER with a vaild USERNAME and PASSWORD.";
				transition();
				main();

			}

		}
		else {

			systemHeader();
			cout << "\n\n\t\t\t\tUSERNAME and EMAIL you entered aren't matching with any data in the USER LOGIN database.";
			cout << "\n\n\t\t\t\tPlease try LOGIN or REGISTER with a vaild USERNAME and PASSWORD.";
			transition();
			main();

		}

	}
	else if (choice == '2') {

		login();

	}
	else if (choice == '3') {

		registration();

	}
	else {

		exit(0);

	}
}

//Function to log out from the system
void logout() {

	systemHeader();

	cout << "\t\t\t\tYou have logged out of the Player Information System.\n\n";

	transition();
	main();

}

//Display the main functions in the system and helps navigate between them
void dashboard() {

	systemHeader();

	char dashChoice;

	cout << "\n\n\t\t\t   Press '1' to DISPLAY PLAYER INFORMATIONS    |    Press '2' to DISPLAY TEAMS\n";
	cout << "\t\t\t                                               |\n";
	cout << "\t\t\t   Press '3' to MANAGE TEAMS                   |    Press '4' to MANAGE PLAYERS\n";
	cout << "\t\t\t                                               |\n";
	cout << "\t\t\t   Press '5' to SEARCH PLAYERS                 |    Press '6' to SEARCH TEAMS\n";
	cout << "\t\t\t                                               |\n";
	cout << "\t\t\t   Press '7' to LOGOUT                         |    Press '8' to EXIT\n\n";

	cout << "\n\n\t\t\t\tYour Response\t:  ";
	cin >> dashChoice;
	cout << endl;
	system("cls");

	switch (dashChoice) {

	case '1': displayPlayers(); break;
	case '2': displayTeams(); break;
	case '3': manageTeams(); break;
	case '4': managePlayers(); break;
	case '5': searchPlayers(); break;
	case '6': searchTeams(); break;
	case '7': logout(); break;
	case '8': exit(0); break;
	default: systemHeader();
		cout << "\n\n\t\t\t\tYour response is invalid.\n\n\t\t\t\tPlease select an option available in the DASHBOARD.\n\n";
		transition();
		dashboard();
		break;

	}

}

//Function to add or update player/s to the database
void addUpdatePlayers() {

	string existRegNo;

	systemHeader();

	char choice;

	cout << "\n\n\t\t\t\tPress '1' to ADD or UPDATE players\n";
	cout << "\n\t\t\t\tPress '2' to go back to the DASHBOARD\n\n";

	cout << "\n\n\t\t\t\tYour Response\t:  ";
	cin >> choice;
	cout << endl;
	system("cls");

	if (choice == '2') {

		dashboard();

	}

	systemHeader();

	int amount;
	cout << "\n\n\t\t\t\t\tHow many players do you want to ADD or UPDATE\t:  ";
	cin >> amount;
	cout << endl << endl;

	transition();

	Players player;

	if (amount == 1) {

		systemHeader();

		cout << "\n\n\t\t\t\tEnter Player's Information";
		cout << "\n\n\t\t\t\t01. REGISTRATION NUMBER\t\t:  ";
		cin >> player.regNumber;
		cin.ignore();

		if (player.regNumber <= 202400000) {

			cout << "\n\n\t\t\t\tEntered REGISTRATION NUMBER doesn't match with club's official format.";
			cout << "\n\n\t\t\t\tPlease try again with a vaild REGISTRATION NUMBER.";
			transition();
			addUpdatePlayers();

		}

		cout << "\n\t\t\t\t02. FIRST NAME\t\t\t:  ";
		getline(cin >> ws, player.firstname);
		cout << "\n\t\t\t\t03. LAST NAME\t\t\t:  ";
		getline(cin >> ws, player.lastname);
		cout << "\n\t\t\t\t04. DATE OF BIRTH (DD/MM/YYYY)\t:  ";
		getline(cin >> ws, player.dob);
		cout << "\n\t\t\t\t05. AGE (years)\t\t\t:  ";
		cin >> player.age;
		cin.ignore();
		cout << "\n\t\t\t\t06. HOMETOWN\t\t\t:  ";
		getline(cin >> ws, player.hometown);
		cout << "\n\t\t\t\t07. RUNS SCORED\t\t\t:  ";
		cin >> player.runsScored;
		cin.ignore();

		transition();

		string stringRegNo = to_string(player.regNumber);

		ifstream read(stringRegNo + "_player_personal_details.txt");
		getline(read, existRegNo);
		read.close();

		if (stringRegNo != existRegNo) {

			ofstream addPlayer;
			addPlayer.open(stringRegNo + "_player_personal_details.txt");
			addPlayer << player.regNumber << endl << player.firstname << endl << player.lastname << endl << player.dob << endl << player.age << endl << player.hometown << endl << player.runsScored;
			addPlayer.close();

			systemHeader();

			cout << "\t\t\t\t\tYou have successfully registered the player's information.\n\n\n";
			transition();
			dashboard();

		}
		else {

			char tryAgain;

			systemHeader();

			cout << "\n\n\t\t\t\tEntered REGISTRATION NUMBER already exist.\n\n\t\t\t\tPlease select a different REGISTRATION NUMBER or UPDATE the information.\n\n\n\n";
			cout << "\t\t\t\tPress '1' to try again.";
			cout << "\n\n\t\t\t\tPress '2' to UPDATE the player's information.";
			cout << "\n\n\t\t\t\tPress '3' to Go to the DASHBOARD.";
			cout << "\n\n\n\n\t\t\t\tYour Response\t:  ";
			cin >> tryAgain;
			cout << endl;
			system("cls");

			if (tryAgain == '1') {

				addUpdatePlayers();

			}
			else if (tryAgain == '3') {

				dashboard();

			}
			else if (tryAgain == '2') {

				systemHeader();

				char choice;
				cout << "\n\n\t\t\t\tDo you want to Update Registration Number: " << stringRegNo << " Player's Information?\n\n";
				cout << "\n\n\n\n\t\t\t\tYour Response ('y' for YES, 'n' for NO)\t:  ";
				cin >> choice;
				system("cls");

				choice = toupper(choice);

				if (choice == 'Y') {

					systemHeader();

					cout << "\n\n\t\t\t\tYou have successfully updated the player's information.\n\n";

					ofstream addPlayer;
					addPlayer.open(stringRegNo + "_player_personal_details.txt");
					addPlayer << player.regNumber << endl << player.firstname << endl << player.lastname << endl << player.dob << endl << player.age << endl << player.hometown << endl << player.runsScored;
					addPlayer.close();

					transition();
					dashboard();

				}
				else {

					systemHeader();
					cout << "\n\n\t\t\t\tYou have chosen not to update player's information.\n\n\t\t\t\tYou will be redirected to the DASHBOARD.\n\n";
					transition();
					dashboard();

				}

			}
			else {

				systemHeader();
				cout << "\n\n\n\t\t\t\tYour response is invalid and you will be redirected to the DASHBOARD.";
				transition();
				dashboard();

			}

		}

		ofstream allPlayers("all_player_reg_numbers.txt", ios::out | ios::app);
		allPlayers << stringRegNo << endl;
		allPlayers.close();

	}
	else {

		for (int i = 1; i <= amount; i++) {

			systemHeader();

			cout << "\n\n\t\t\t\tEnter Player " << i << "'s Information\n\n";
			cout << "\n\n\t\t\t\t01. REGISTRATION NUMBER\t\t:  ";
			cin >> player.regNumber;
			cin.ignore();

			if (player.regNumber <= 202400000) {

				cout << "\n\n\t\t\t\tEntered REGISTRATION NUMBER doesn't match with club's official format.";
				cout << "\n\n\t\t\t\tPlease try again with a vaild REGISTRATION NUMBER.";

				cout << "\n\n\t\t\t--------------------------------------------------------------------------------------\n";

				char tryAgain;

				cout << "\n\n\t\t\t\tDo you want to continue with the next player?\n\n\n";
				cout << "\t\t\t\tPress '1' to continue";
				cout << "\n\n\t\t\t\tPress '2' to Go to the DASHBOARD";
				cout << "\n\n\n\n\t\t\t\tYour Response\t:  ";
				cin >> tryAgain;
				cout << endl;
				system("cls");

				if (tryAgain == '1') {

					continue;

				}
				else {

					addUpdatePlayers();
					break;

				}

			}

			cout << "\n\t\t\t\t02. FIRST NAME\t\t\t:  ";
			getline(cin >> ws, player.firstname);
			cout << "\n\t\t\t\t03. LAST NAME\t\t\t:  ";
			getline(cin >> ws, player.lastname);
			cout << "\n\t\t\t\t04. DATE OF BIRTH (DD/MM/YYYY)\t:  ";
			getline(cin >> ws, player.dob);
			cout << "\n\t\t\t\t05. AGE (years)\t\t\t:  ";
			cin >> player.age;
			cin.ignore();
			cout << "\n\t\t\t\t06. HOMETOWN\t\t\t:  ";
			getline(cin >> ws, player.hometown);
			cout << "\n\t\t\t\t07. RUNS SCORED\t\t\t:  ";
			cin >> player.runsScored;
			cin.ignore();

			transition();

			string stringRegNo = to_string(player.regNumber);

			ifstream read(stringRegNo + "_player_personal_details.txt");
			getline(read, existRegNo);
			read.close();

			if (stringRegNo != existRegNo) {

				ofstream addPlayer;
				addPlayer.open(stringRegNo + "_player_personal_details.txt");
				addPlayer << player.regNumber << endl << player.firstname << endl << player.lastname << endl << player.dob << endl << player.age << endl << player.hometown << endl << player.runsScored;
				addPlayer.close();

				systemHeader();

				cout << "\t\t\t\t\tYou have successfully registered the player " << i << "'s information.\n\n\n";
				transition();

			}
			else {

				char tryAgain;

				systemHeader();

				cout << "\n\n\t\t\t\tEntered REGISTRATION NUMBER already exist.\n\n\t\t\t\tPlease select a different REGISTRATION NUMBER or UPDATE the information.";
				cout << "\n\n\t\t\t\tYou have already entered " << i - 1 << " out of " << amount << " player informations successfully.";
				cout << "\n\n\t\t\t\tIncluding the one that failed, there are " << amount - (i - 1) << " remaining players to enter into the system.\n\n\n";
				cout << "\t\t\t\tPress '1' to try again.";
				cout << "\n\n\t\t\t\tPress '2' to UPDATE the player's information.";
				cout << "\n\n\t\t\t\tPress '3' to Go to the DASHBOARD.";
				cout << "\n\n\n\n\t\t\t\tYour Response\t:  ";
				cin >> tryAgain;
				cout << endl;
				system("cls");

				if (tryAgain == '1') {

					addUpdatePlayers();
					break;

				}
				else if (tryAgain == '3') {

					dashboard();
					break;

				}
				else if (tryAgain == '2') {

					systemHeader();

					char choice;
					cout << "\n\n\t\t\t\tDo you want to Update Registration Number: " << stringRegNo << " Player's Information?\n\n";
					cout << "\n\n\n\n\t\t\t\tYour Response ('y' for YES, 'n' for NO)\t:  ";
					cin >> choice;
					system("cls");

					choice = toupper(choice);

					if (choice == 'Y') {

						systemHeader();

						cout << "\n\n\t\t\t\tYou have successfully updated the player's information.\n\n";

						ofstream addPlayer;
						addPlayer.open(stringRegNo + "_player_personal_details.txt");
						addPlayer << player.regNumber << endl << player.firstname << endl << player.lastname << endl << player.dob << endl << player.age << endl << player.hometown << endl << player.runsScored;
						addPlayer.close();

						transition();

					}
					else {

						systemHeader();
						cout << "\n\n\t\t\t\tYou have chosen not to update the player's information.\n\n\t\t\t\tLet's continue with adding rest of the players informations.\n\n";
						transition();

					}

				}
				else {

					systemHeader();
					cout << "\n\n\n\t\t\t\tYour response is invalid. So you will be redirected to the DASHBOARD.";
					transition();
					dashboard();
					break;

				}

			}

			ofstream allPlayers("all_player_reg_numbers.txt", ios::out | ios::app);
			allPlayers << stringRegNo << endl;
			allPlayers.close();

		}

		systemHeader();

		char choice;
		cout << "\n\n\t\t\t\tDo you want to ADD or UPDATE more player/s?\n\n";
		cout << "\n\n\n\n\t\t\t\tYour Response ('y' for YES, 'n' for NO)\t:  ";
		cin >> choice;
		system("cls");

		choice = toupper(choice);

		if (choice == 'Y') {

			addUpdatePlayers();

		}
		else {

			systemHeader();
			cout << "\n\n\t\t\t\tYou will be redirected to the DASHBOARD.\n\n";
			transition();
			dashboard();

		}

	}

}

//Display all the active players registered in the systrem
void displayPlayers() {

	systemHeader();
	cout << "\n\t,_____________________________________________________________________________________________________________,\n";
	cout << "\t|   Reg. No.  | First Name  |   Last Name    |     DoB     | Age |    Hometown    | Runs Scored |   Status    |\n";
	cout << "\t|-------------|-------------|----------------|-------------|-----|----------------|-------------|-------------|";

	string data, filename, status;

	ifstream getRegNum("all_player_reg_numbers.txt");
	getline(getRegNum, filename);

	do {

		int count = 0;
		int checker = 0;
		filename.append("_player_personal_details.txt");

		ifstream read(filename);

		while (getline(read, status)) {

			checker++;

		}

		read.close();

		ifstream getData(filename);

		if (!getData) {

			break;

		}

		if (checker == 7) {

			cout << "\n\t| ";

			while (getline(getData, data)) {

				if (count == 2) {

					cout << setw(14) << data << " | ";

				}
				else if (count == 4) {

					cout << setw(3) << data << " | ";

				}
				else if (count == 5) {

					cout << setw(14) << data << " | ";

				}
				else {

					cout << setw(11) << data << " | ";

				}

				count++;

			}

			if (count == 7) {

				cout << setw(14) << " | ";

			}

		}
		getData.close();

	} while (getline(getRegNum, filename));

	cout << "\n\t'-------------'-------------'----------------'-------------'-----'----------------'-------------'-------------'\n";

	transition();
	dashboard();

}

//Function to search all players in the database
void searchPlayers() {

	systemHeader();

	string regNum, fname, lname, hTown, existfname, existlname, existhTown, existstatus;
	char choice;

	cout << "\n\n\t\t\t\tPress '1' to SEARCH with REGISTRATION NUMBER\n";
	cout << "\n\t\t\t\tPress '2' to SEARCH with FIRST NAME\n";
	cout << "\n\t\t\t\tPress '3' to SEARCH with LAST NAME\n";
	cout << "\n\t\t\t\tPress '4' to SEARCH with HOMETOWN\n";
	cout << "\n\t\t\t\tPress '5' to SEARCH with STATUS\n";
	cout << "\n\t\t\t\tPress '6' to go back to the DASHBOARD\n\n";

	cout << "\n\n\t\t\t\tYour Response\t:  ";
	cin >> choice;
	cout << endl;
	system("cls");

	if (choice == '1') {

		int count = 0;
		systemHeader();

		cout << "\t\t\t\tEnter REGISTRATION NUMBER\t:  ";
		getline(cin >> ws, regNum);

		cout << "\n\t,_____________________________________________________________________________________________________________,\n";
		cout << "\t|   Reg. No.  | First Name  |   Last Name    |     DoB     | Age |    Hometown    | Runs Scored |   Status    |\n";
		cout << "\t|-------------|-------------|----------------|-------------|-----|----------------|-------------|-------------|";

		ifstream read(regNum + "_player_personal_details.txt");

		string data;

		cout << "\n\t| ";

		while (getline(read, data)) {

			if (count == 2) {

				cout << setw(14) << data << " | ";

			}
			else if (count == 4) {

				cout << setw(3) << data << " | ";

			}
			else if (count == 5) {

				cout << setw(14) << data << " | ";

			}
			else {

				cout << setw(11) << data << " | ";

			}

			count++;

		}
		read.close();

		if (count == 7) {

			cout << setw(14) << " | ";

		}

		cout << "\n\t'-------------'-------------'----------------'-------------'-----'----------------'-------------'-------------'\n";

	}
	else if (choice == '2') {

		systemHeader();

		cout << "\t\t\t\tEnter FIRST NAME\t:  ";
		getline(cin >> ws, fname);

		cout << "\n\t,_____________________________________________________________________________________________________________,\n";
		cout << "\t|   Reg. No.  | First Name  |   Last Name    |     DoB     | Age |    Hometown    | Runs Scored |   Status    |\n";
		cout << "\t|-------------|-------------|----------------|-------------|-----|----------------|-------------|-------------|";

		string data;
		string filename;

		ifstream getRegNum("all_player_reg_numbers.txt");
		getline(getRegNum, filename);

		do {

			int count = 0;
			filename.append("_player_personal_details.txt");

			ifstream read(filename);

			while (getline(read, existfname)) {

				if (existfname == fname) {

					break;

				}

			}

			read.close();

			ifstream getData(filename);

			if (!getData) {

				break;

			}

			if (fname == existfname) {

				cout << "\n\t| ";

				while (getline(getData, data)) {

					if (count == 2) {

						cout << setw(14) << data << " | ";

					}
					else if (count == 4) {

						cout << setw(3) << data << " | ";

					}
					else if (count == 5) {

						cout << setw(14) << data << " | ";

					}
					else {

						cout << setw(11) << data << " | ";

					}

					count++;

				}

				if (count == 7) {

					cout << setw(14) << " | ";

				}

			}
			getData.close();

		} while (getline(getRegNum, filename));

		getRegNum.close();

		cout << "\n\t'-------------'-------------'----------------'-------------'-----'----------------'-------------'-------------'\n";

	}
	else if (choice == '3') {

		systemHeader();

		cout << "\t\t\t\tEnter LAST NAME\t:  ";
		getline(cin >> ws, lname);

		cout << "\n\t,_____________________________________________________________________________________________________________,\n";
		cout << "\t|   Reg. No.  | First Name  |   Last Name    |     DoB     | Age |    Hometown    | Runs Scored |   Status    |\n";
		cout << "\t|-------------|-------------|----------------|-------------|-----|----------------|-------------|-------------|";

		string data;
		string filename;

		ifstream getRegNum("all_player_reg_numbers.txt");
		getline(getRegNum, filename);

		do {

			int count = 0;
			filename.append("_player_personal_details.txt");

			ifstream read(filename);

			while (getline(read, existlname)) {

				if (existlname == lname) {

					break;

				}

			}

			read.close();

			ifstream getData(filename);

			if (!getData) {

				break;

			}

			if (lname == existlname) {

				cout << "\n\t| ";

				while (getline(getData, data)) {

					if (count == 2) {

						cout << setw(14) << data << " | ";

					}
					else if (count == 4) {

						cout << setw(3) << data << " | ";

					}
					else if (count == 5) {

						cout << setw(14) << data << " | ";

					}
					else {

						cout << setw(11) << data << " | ";

					}

					count++;

				}

				if (count == 7) {

					cout << setw(14) << " | ";

				}

			}
			getData.close();

		} while (getline(getRegNum, filename));

		getRegNum.close();

		cout << "\n\t'-------------'-------------'----------------'-------------'-----'----------------'-------------'-------------'\n";

	}
	else if (choice == '4') {

		systemHeader();

		cout << "\t\t\t\tEnter HOMETOWN\t:  ";
		getline(cin >> ws, hTown);

		cout << "\n\t,_____________________________________________________________________________________________________________,\n";
		cout << "\t|   Reg. No.  | First Name  |   Last Name    |     DoB     | Age |    Hometown    | Runs Scored |   Status    |\n";
		cout << "\t|-------------|-------------|----------------|-------------|-----|----------------|-------------|-------------|";

		string data;
		string filename;

		ifstream getRegNum("all_player_reg_numbers.txt");
		getline(getRegNum, filename);

		do {

			int count = 0;
			filename.append("_player_personal_details.txt");

			ifstream read(filename);

			while (getline(read, existhTown)) {

				if (existhTown == hTown) {

					break;

				}

			}

			read.close();

			ifstream getData(filename);

			if (!getData) {

				break;

			}

			if (hTown == existhTown) {

				cout << "\n\t| ";

				while (getline(getData, data)) {

					if (count == 2) {

						cout << setw(14) << data << " | ";

					}
					else if (count == 4) {

						cout << setw(3) << data << " | ";

					}
					else if (count == 5) {

						cout << setw(14) << data << " | ";

					}
					else {

						cout << setw(11) << data << " | ";

					}

					count++;

				}

				if (count == 7) {

					cout << setw(14) << " | ";

				}

			}
			getData.close();

		} while (getline(getRegNum, filename));

		getRegNum.close();

		cout << "\n\t'-------------'-------------'----------------'-------------'-----'----------------'-------------'-------------'\n";

	}
	else if (choice == '5') {

		systemHeader();

		char option;
		cout << "\n\t\t\t\tPress '1' to SEARCH active PLAYERS\n";
		cout << "\n\t\t\t\tPress '2' to SEARCH inactive PLAYERS\n";
		cout << "\n\t\t\t\tPress '3' to view more SEARCH options\n";
		cout << "\n\t\t\t\tPress '4' to go back to DASHBOARD\n";

		cout << "\n\n\t\t\t\tYour Response\t:  ";
		cin >> option;
		cout << endl;
		system("cls");

		string data;
		string filename;

		ifstream getRegNum("all_player_reg_numbers.txt");
		getline(getRegNum, filename);

		if (option == '2') {

			systemHeader();
			cout << "\n\t,_____________________________________________________________________________________________________________,\n";
			cout << "\t|   Reg. No.  | First Name  |   Last Name    |     DoB     | Age |    Hometown    | Runs Scored |   Status    |\n";
			cout << "\t|-------------|-------------|----------------|-------------|-----|----------------|-------------|-------------|";

			do {

				int count = 0;
				filename.append("_player_personal_details.txt");

				ifstream read(filename);

				while (getline(read, existstatus)) {

					if (existstatus == "Inactive") {

						break;

					}

				}

				read.close();

				ifstream getData(filename);

				if (!getData) {

					break;

				}

				if (existstatus == "Inactive") {

					cout << "\n\t| ";

					while (getline(getData, data)) {

						if (count == 2) {

							cout << setw(14) << data << " | ";

						}
						else if (count == 4) {

							cout << setw(3) << data << " | ";

						}
						else if (count == 5) {

							cout << setw(14) << data << " | ";

						}
						else {

							cout << setw(11) << data << " | ";

						}

						count++;

					}

				}
				getData.close();

			} while (getline(getRegNum, filename));

			cout << "\n\t'-------------'-------------'----------------'-------------'-----'----------------'-------------'-------------'\n";

		}
		else if (option == '1') {

			systemHeader();
			cout << "\n\t,_____________________________________________________________________________________________________________,\n";
			cout << "\t|   Reg. No.  | First Name  |   Last Name    |     DoB     | Age |    Hometown    | Runs Scored |   Status    |\n";
			cout << "\t|-------------|-------------|----------------|-------------|-----|----------------|-------------|-------------|";

			do {

				int count = 0;
				int checker = 0;
				filename.append("_player_personal_details.txt");

				ifstream read(filename);

				while (getline(read, existstatus)) {

					checker++;

				}

				read.close();

				ifstream getData(filename);

				if (!getData) {

					break;

				}

				if (checker == 7) {

					cout << "\n\t| ";

					while (getline(getData, data)) {

						if (count == 2) {

							cout << setw(14) << data << " | ";

						}
						else if (count == 4) {

							cout << setw(3) << data << " | ";

						}
						else if (count == 5) {

							cout << setw(14) << data << " | ";

						}
						else {

							cout << setw(11) << data << " | ";

						}

						count++;

					}

					if (count == 7) {

						cout << setw(14) << " | ";

					}

				}
				getData.close();

			} while (getline(getRegNum, filename));

			cout << "\n\t'-------------'-------------'----------------'-------------'-----'----------------'-------------'-------------'\n";

		}
		else if (option == '3') {

			searchPlayers();

		}
		else {

			systemHeader();
			cout << "\n\n\n\t\t\t\tYou will be redirected to the DASHBOARD.\n\n\n";
			transition();
			dashboard();

		}

		getRegNum.close();

	}

	else if (choice == '6') {

		systemHeader();
		cout << "\n\n\n\t\t\t\tYou will be redirected to the DASHBOARD.\n\n\n";
		transition();
		dashboard();

	}
	else {

		systemHeader();
		cout << "\n\n\n\t\t\t\tYour response is invalid. So you will be redirected to the DASHBOARD.\n\n\n";
		transition();
		dashboard();

	}

	transition();
	systemHeader();

	char repeatchoice;
	cout << "\n\n\t\t\t\tDo you want to SEARCH player/s again?\n\n";
	cout << "\n\n\n\n\t\t\t\tYour Response ('y' for YES, 'n' for NO)\t:  ";
	cin >> repeatchoice;
	system("cls");

	repeatchoice = toupper(repeatchoice);

	if (repeatchoice == 'Y') {

		searchPlayers();

	}
	else {

		systemHeader();
		cout << "\n\n\t\t\t\tYou will be redirected to the DASHBOARD.\n\n";
		transition();
		dashboard();

	}

}

//Display the functions for CREATE, UPDATE or REMOVE team/s in the system and helps navigate between them
void manageTeams() {

	systemHeader();

	char choice;

	cout << "\t\t\t\t\t\tPress '1' to CREATE a team\n" << endl;
	cout << "\t\t\t\t\t\tPress '2' to UPDATE a team\n" << endl;
	cout << "\t\t\t\t\t\tPress '3' to REMOVE a team\n" << endl;
	cout << "\t\t\t\t\t\tPress '4' to FIND available players\n" << endl;
	cout << "\t\t\t\t\t\tPress '5' to go back to DASHBOARD\n\n\n\n" << endl;
	cout << "\t\t\t\tYour Response\t:  ";
	cin >> choice;
	cin.ignore();
	system("cls");

	switch (choice) {

	case '1': createTeam(); break;

	case '2': updateTeam(); break;

	case '3': 
		
		systemHeader();
		cout << "\n\t\t\t\tSystem is unable to fullfill your request.\n\n\t\t\t\tSystem is kindly advising you to go to the directories manually\n\t\t\t\tand remove the data file of the relevant TEAM.\n";
		transition();
		manageTeams();
		break;

	case '4': availableplayers(); break;
	
	case '5': dashboard(); break;

	default: dashboard(); break;

	}

}

//Function to check whether there are duplicate elemants in a string array
bool checkDuplicates(const string arr[], int size, const string newPlayer) {

	for (int i = 0; i < size; i++) {

		if (arr[i] == newPlayer) {

			return true;

		}

	}

	return false;

}

//Function to update a already created team in the system
void updateTeam() {

	systemHeader();

	string playerRegNo, teamNo;
	const int size = 9;
	string teamMembers[size];
	int currentIndex = 0;
	bool restart = true;

	cout << "\n\n\t\t\t\t\tEnter the TEAM NAME needed to UPDATE\t:  ";
	getline(cin >> ws, teamNo);
	cout << endl << endl;
	transition();

	string stringTeamNo = teamNo;
	stringTeamNo.append("_team's_member_reg_numbers.txt");

	ifstream read(stringTeamNo);

	if (!read) {

		systemHeader();

		cout << "\n\n\t\t\t\tTeam with a TEAM NAME " << teamNo << " doesn't exist in the database.";
		cout << "\n\n\t\t\t\tPlease enter a valid TEAM NAME.";
		transition();
		updateTeam();

	}
	read.close();

	while (restart) {

		restart = false;

		systemHeader();
		cout << "\t\t\t\t\tTEAM NAME\t:  " << teamNo << endl;
		cout << "\n\t\t\t --> You are only allowed to put 09 players in a team.\n";
		cout << "\t\t\t --> And same player can only be assigned to no more than two teams.\n";
		cout << "\t\t\t --> Be mindful when assiging players,\n\t\t\t     since system will not check player's current teams when updating new teams.\n";
		cout << "\n\t\t\t\t\tEnter the Team's new REGISTRATION NUMBERS.\n\n";

		for (int i = 0; i < size; i++) {

			cout << "\n\t\t\t\tPlayer No. 0" << i + 1 << "\t:  ";
			getline(cin >> ws, playerRegNo);

			string filename, existstatus;

			filename = playerRegNo;
			string temp = filename;
			filename.append("_player_personal_details.txt");

			ifstream read(filename);

			if (!read) {

				cout << "\n\n\t\t\t\tYou have entered a non-existing REGISTRATION NUMBER in the player database.";
				cout << "\n\n\t\t\t\tPlease try again from the beginning with vaild REGISTRATION NUMBERS.";
				transition();
				restart = true;
				break;

			}

			while (getline(read, existstatus)) {

				if (existstatus == "Inactive") {

					break;

				}

			}

			if (existstatus == "Inactive") {

				cout << "\n\n\t\t\t\tYou have entered a player that is no longer active in the club.";
				cout << "\n\n\t\t\t\tPlease create the team with only active players.";
				transition();
				restart = true;
				break;

			}

			read.close();

			teamMembers[i] = temp;

			if (checkDuplicates(teamMembers, i, teamMembers[i])) {

				cout << "\n\n\t\t\t\tYou have entered a player's REGISTRATION NUMBER that's already in the team. ";
				cout << "\n\n\t\t\t\tPlease create a team again with different players.";
				transition();
				currentIndex = 0;
				restart = true;
				break;

			}

			currentIndex++;

		}

		ofstream createTeamList(stringTeamNo);

		if (createTeamList) {

			for (int i = 0; i < size; i++) {

				createTeamList << teamMembers[i] << endl;

			}

			createTeamList.close();

		}
		else {

			cout << "\n\n\t\t\t\tUpdating the TEAM has failed. Please try again.\n\n";
			transition();
			restart = true;
			break;

		}

	}

	transition();

	char tryAgain;

	systemHeader();

	cout << "\n\n\t\t\t\tYou have successfully UPDATED the TEAM.\n\n\n";
	cout << "\n\n\t\t\t\tDo you want to UPDATE another?\n\n\n";
	cout << "\t\t\t\tPress '1' to UPDATE a TEAM.";
	cout << "\n\n\t\t\t\tPress '2' to Go to the DASHBOARD.";
	cout << "\n\n\n\n\t\t\t\tYour Response\t:  ";
	cin >> tryAgain;
	cout << endl;
	system("cls");

	switch (tryAgain)
	{

	case '1': updateTeam(); break;

	case '2': dashboard(); break;

	default: dashboard(); break;

	}

}

//Function to remove(add status 'inactive') a player from the present data
void removePlayer() {

	systemHeader();

	char choice;

	cout << "\t\t\t\t\t\tPress '1' to REMOVE a player/s\n" << endl;
	cout << "\t\t\t\t\t\tPress '2' to go back to DASHBOARD\n\n\n\n" << endl;
	cout << "\t\t\t\tYour Response\t:  ";
	cin >> choice;
	cin.ignore();
	system("cls");

	if (choice == '1') {

		systemHeader();
		int count;

		cout << "\n\n\t\t\t\tHow many Players do you want to REMOVE\t:  ";
		cin >> count;
		cin.ignore();

		for (int i = 1; i <= count; i++) {

			string regNumber;

			cout << "\n\n\t\t\t\tEnter Player No. " << i << "'s REGISTRATION NUMBER\t:  ";
			getline(cin >> ws, regNumber);

			ifstream read(regNumber + "_player_personal_details.txt");

			if (!read) {

				cout << "\n\n\t\t\t\tThere isn't any player with '" << regNumber << "' REGISTRATION NUMBER in the system.\n";
				cout << "\n\t\t\t--------------------------------------------------------------------------------------\n";

				char tryAgain;

				cout << "\n\n\t\t\t\tDo you want to continue?\n\n\n";
				cout << "\t\t\t\tPress '1' to continue";
				cout << "\n\n\t\t\t\tPress '2' to Go to the DASHBOARD";
				cout << "\n\n\n\n\t\t\t\tYour Response\t:  ";
				cin >> tryAgain;
				cout << endl;
				system("cls");
				systemHeader();

				if (tryAgain == '1') {

					continue;

				}
				else {

					dashboard();
					break;

				}

			}
			read.close();

			ofstream addStatus(regNumber + "_player_personal_details.txt", ios::out | ios::app);
			addStatus << endl << "Inactive";
			addStatus.close();

			cout << "\n\n\t\t\t\tPlayer with REGISTRATION NUMBER " << regNumber << " has been removed from the system.\n";

			ifstream checkteams("personal_teams_of_player_regNo_" + regNumber + ".txt");

			if (checkteams) {

				string name;
				int j = 1;

				cout << "\n\t\t\t\tRemoved player was involved with below club TEAMs.\n";

				while (getline(checkteams, name)) {

					cout << "\n\t\t\t\t\t" << "0" << j << ".\t" << name << endl;
					j++;

				}

				cout << "\n\t\t\t\tPlease update them by providing a suitable replacement.\n";

			}

			if (count != 1) {

				cout << "\n\t\t\t--------------------------------------------------------------------------------------\n";

			}

		}

	}
	else {

		systemHeader();
		cout << "\n\n\t\t\t\tYou will be redirected to the DASHBOARD.\n\n";
		transition();
		dashboard();

	}

	char tryAgain;

	transition();
	systemHeader();

	cout << "\n\n\t\t\t\tDo you want to REMOVE another player/s?\n\n\n";
	cout << "\t\t\t\tPress '1' to REMOVE another player/s";
	cout << "\n\n\t\t\t\tPress '2' to Go to the DASHBOARD";
	cout << "\n\n\n\n\t\t\t\tYour Response\t:  ";
	cin >> tryAgain;
	cout << endl;
	system("cls");

	switch (tryAgain)
	{

	case '1': removePlayer(); break;

	case '2': dashboard(); break;

	default: dashboard(); break;

	}

}

//Display the functions for ADD, UPDATE or REMOVE player/s in the system and helps navigate between them
void managePlayers() {

	systemHeader();

	char choice;

	cout << "\t\t\t\t\t\tPress '1' to ADD or UPDATE a player/s\n" << endl;
	cout << "\t\t\t\t\t\tPress '2' to REMOVE a player/s\n" << endl;
	cout << "\t\t\t\t\t\tPress '3' to go back to DASHBOARD\n\n\n\n" << endl;
	cout << "\t\t\t\tYour Response\t:  ";
	cin >> choice;
	cin.ignore();
	system("cls");

	switch (choice) {

	case '1': addUpdatePlayers(); break;

	case '2': removePlayer(); break;

	case '3': dashboard(); break;

	default: dashboard(); break;

	}

}

//Function to add details of newly created team/s into the system
void createTeam() {

	systemHeader();

	string playerRegNo, teamNo;
	const int size = 9;
	string teamMembers[size];
	int currentIndex = 0;
	bool restart = true;

	cout << "\n\n\t\t\t\t\tEnter the new Team's TEAM NAME\t:  ";
	getline(cin >> ws, teamNo);
	cout << endl << endl;
	transition();

	string stringTeamNo = teamNo;
	stringTeamNo.append("_team's_member_reg_numbers.txt");

	ifstream read(stringTeamNo);

	if (read) {

		systemHeader();

		cout << "\n\n\t\t\t\tTEAM NAME '" << teamNo << "' already exist.";
		cout << "\n\n\t\t\t\tPlease enter a different TEAM NAME.";
		transition();
		createTeam();

	}
	read.close();

	while (restart) {

		restart = false;

		systemHeader();
		cout << "\t\t\t\t\tTEAM NAME\t:  " << teamNo << endl;
		cout << "\n\t\t\t --> You are only allowed to put 09 players in a team.\n";
		cout << "\t\t\t --> And same player can only be assigned to no more than two teams.\n";
		cout << "\n\t\t\t\t\tEnter the Team's REGISTRATION NUMBERS.\n\n";

		for (int i = 0; i < size; i++) {

			cout << "\n\t\t\t\tPlayer No. 0" << i + 1 << "\t:  ";
			getline(cin >> ws, playerRegNo);

			string filename, existstatus;

			filename = playerRegNo;
			string temp = filename;
			filename.append("_player_personal_details.txt");

			ifstream read(filename);

			if (!read) {

				cout << "\n\n\t\t\t\tYou have entered a non-existing REGISTRATION NUMBER in the player database.";
				cout << "\n\n\t\t\t\tPlease try again from the beginning with vaild REGISTRATION NUMBERS.";
				transition();
				restart = true;
				break;

			}

			while (getline(read, existstatus)) {

				if (existstatus == "Inactive") {

					break;

				}

			}

			if (existstatus == "Inactive") {

				cout << "\n\n\t\t\t\tYou have entered a player that is no longer active in the club.";
				cout << "\n\n\t\t\t\tPlease create the team with only active players.";
				transition();
				restart = true;
				break;

			}

			read.close();

			int count = 0;
			string checkTeams;
			ifstream playerTeams("personal_teams_of_player_regNo_" + temp + ".txt", ios::in);

			while (getline(playerTeams, checkTeams)) {

				count += 1;

			}
			playerTeams.close();

			if (count >= 2) {

				cout << "\n\n\t\t\t\tThe Player you entered already registered with two TEAMS.\n\t\t\t\tPlease try again.";
				cout << "\n\n\t\t\t\tRule :  Maximum number of TEAMS for a player is TWO.\n\n";
				transition();
				restart = true;
				break;

			}

			teamMembers[i] = temp;

			if (checkDuplicates(teamMembers, i, teamMembers[i])) {

				cout << "\n\n\t\t\t\tYou have entered a player's REGISTRATION NUMBER that's already in the team. ";
				cout << "\n\n\t\t\t\tPlease create a team again with different players.";
				transition();
				currentIndex = 0;
				restart = true;
				break;

			}

			currentIndex++;

		}

		ofstream createTeamList(stringTeamNo);

		if (createTeamList) {

			for (int i = 0; i < size; i++) {

				createTeamList << teamMembers[i] << endl;

			}

			createTeamList.close();

		}
		else {

			cout << "\n\n\t\t\t\tCreating the new TEAM has failed. Please try again.\n\n";
			transition();
			restart = true;
			break;

		}

	}

	string name;
	ifstream readagain(stringTeamNo);

	while (getline(readagain, name)) {

		ofstream playerTeams("personal_teams_of_player_regNo_" + name + ".txt", ios::out | ios::app);
		playerTeams << teamNo << endl;
		playerTeams.close();

	}
	readagain.close();

	ifstream checkTeamNo(stringTeamNo);

	if (checkTeamNo) {

		ofstream allTeams("all_team_names.txt", ios::out | ios::app);
		allTeams << teamNo << endl;
		allTeams.close();

	}

	transition();

	char tryAgain;

	systemHeader();

	cout << "\n\n\t\t\t\tYou have successfully CREATED a new TEAM.\n\n\n";
	cout << "\n\n\t\t\t\tDo you want to CREATE another?\n\n\n";
	cout << "\t\t\t\tPress '1' to CREATE a TEAM.";
	cout << "\n\n\t\t\t\tPress '2' to Go to the DASHBOARD.";
	cout << "\n\n\n\n\t\t\t\tYour Response\t:  ";
	cin >> tryAgain;
	cout << endl;
	system("cls");

	switch (tryAgain)
	{

	case '1': createTeam(); break;

	case '2': dashboard(); break;

	default: dashboard(); break;

	}

}

//Function to search all teams in the database
void searchTeams() {

	systemHeader();

	char response;

	cout << "\n\n\t\t\t\tPress '1' to SEARCH with TEAM NAME\n";
	cout << "\n\t\t\t\tPress '2' to SEARCH with player REGISTRATION NUMBER\n";
	cout << "\n\t\t\t\tPress '3' to go back to the DASHBOARD\n\n";

	cout << "\n\n\t\t\t\tYour Response\t:  ";
	cin >> response;
	cout << endl;
	system("cls");

	if (response == '3') {

		dashboard();

	}
	else if (response == '1') {

		systemHeader();

		string teamNo;

		cout << "\n\n\t\t\t\tEnter the TEAM NAME\t:  ";
		getline(cin >> ws, teamNo);

		string stringteamNo = teamNo;

		ifstream read(stringteamNo + "_team's_member_reg_numbers.txt");

		if (!read) {

			systemHeader();
			cout << "\n\n\t\t\t\tEntered TEAM NAME doesn't exist in the database.\n\t\t\t\tPlease select a valid TEAM NAME.";
			transition();
			searchTeams();

		}

		string teamRegNoArr[9];
		string regNo;
		int x = 0;

		while (getline(read, regNo)) {

			teamRegNoArr[x] = regNo;
			x++;

		}
		read.close();

		cout << "\n\t,_____________________________________________________________________________________________________________,\n";
		cout << "\t|   Reg. No.  | First Name  |   Last Name    |     DoB     | Age |    Hometown    | Runs Scored |   Status    |\n";
		cout << "\t|-------------|-------------|----------------|-------------|-----|----------------|-------------|-------------|";

		for (int i = 0; i < 9; i++) {

			string regNum = teamRegNoArr[i];

			ifstream read(regNum + "_player_personal_details.txt");

			string data;
			int count = 0;

			cout << "\n\t| ";

			while (getline(read, data)) {

				if (count == 2) {

					cout << setw(14) << data << " | ";

				}
				else if (count == 4) {

					cout << setw(3) << data << " | ";

				}
				else if (count == 5) {

					cout << setw(14) << data << " | ";

				}
				else {

					cout << setw(11) << data << " | ";

				}

				count++;

			}
			read.close();

			if (count == 7) {

				cout << setw(14) << " | ";

			}

		}

		cout << "\n\t'-------------'-------------'----------------'-------------'-----'----------------'-------------'-------------'\n";

	}
	else if (response == '2') {

		systemHeader();

		string regNum;
		string teamNum;

		cout << "\n\n\t\t\t\tEnter the player REGISTRATION NUMBER\t:  ";
		getline(cin >> ws, regNum);

		string stringRegNum = regNum;

		ifstream playerTeams("personal_teams_of_player_regNo_" + stringRegNum + ".txt");

		if (!playerTeams) {

			systemHeader();
			cout << "\n\n\t\t\t\tEntered player doesn't have any TEAMS.\n\t\t\t\tPlease try again.";
			transition();
			searchTeams();

		}

		while (getline(playerTeams, teamNum)) {

			ifstream read(teamNum + "_team's_member_reg_numbers.txt");

			if (!read) {

				systemHeader();
				cout << "\n\n\t\t\t\tEntered TEAM NAME doesn't exist in the database.\n\t\t\t\tPlease select a valid TEAM NAME.";
				transition();
				searchTeams();

			}

			string teamRegNoArr[9];
			string regNo;
			int x = 0;

			while (getline(read, regNo)) {

				teamRegNoArr[x] = regNo;
				x++;

			}
			read.close();

			cout << "\n\n\n\t\t\t\tTEAM NAME\t:  " << teamNum;

			cout << "\n\t,_____________________________________________________________________________________________________________,\n";
			cout << "\t|   Reg. No.  | First Name  |   Last Name    |     DoB     | Age |    Hometown    | Runs Scored |   Status    |\n";
			cout << "\t|-------------|-------------|----------------|-------------|-----|----------------|-------------|-------------|";

			for (int i = 0; i < 9; i++) {

				string regNum = teamRegNoArr[i];

				ifstream read(regNum + "_player_personal_details.txt");

				string data;
				int count = 0;

				cout << "\n\t| ";

				while (getline(read, data)) {

					if (count == 2) {

						cout << setw(14) << data << " | ";

					}
					else if (count == 4) {

						cout << setw(3) << data << " | ";

					}
					else if (count == 5) {

						cout << setw(14) << data << " | ";

					}
					else {

						cout << setw(11) << data << " | ";

					}

					count++;

				}
				read.close();

				if (count == 7) {

					cout << setw(14) << " | ";

				}

			}

			cout << "\n\t'-------------'-------------'----------------'-------------'-----'----------------'-------------'-------------'\n";

		}
		playerTeams.close();

	}

	transition();

	systemHeader();

	char choice;
	cout << "\n\n\t\t\t\tDo you want to SEARCH another TEAM?\n\n";
	cout << "\n\n\n\n\t\t\t\tYour Response ('y' for YES, 'n' for NO)\t:  ";
	cin >> choice;
	system("cls");

	choice = toupper(choice);

	if (choice == 'Y') {

		searchTeams();

	}
	else {

		systemHeader();
		cout << "\n\n\t\t\t\tYou will be redirected to the DASHBOARD.\n\n";
		transition();
		dashboard();

	}


}

//Display all the team names and team memeber deatails available in the system
void displayTeams() {

	systemHeader();

	char response;

	cout << "\n\n\t\t\t\tPress '1' to DISPLAY all TEAM NAMEs\n";
	cout << "\n\t\t\t\tPress '2' to DISPLAY all TEAM Informations\n";
	cout << "\n\t\t\t\tPress '3' to go back to the DASHBOARD\n\n";

	cout << "\n\n\t\t\t\tYour Response\t:  ";
	cin >> response;
	cout << endl;
	system("cls");

	if (response == '3') {

		dashboard();

	}
	else if (response == '2') {

		systemHeader();

		string teamNo;

		ifstream allTeams("all_team_names.txt");

		while (getline(allTeams, teamNo)) {

			string stringteamNo = teamNo;

			ifstream read(stringteamNo + "_team's_member_reg_numbers.txt");

			if (!read) {

				systemHeader();
				cout << "\n\n\t\t\t\tSomething went wrong. Please try again.";
				transition();
				displayTeams();
				break;

			}

			string teamRegNoArr[9];
			string regNo;
			int x = 0;

			while (getline(read, regNo)) {

				teamRegNoArr[x] = regNo;
				x++;

			}
			read.close();

			cout << "\n\t\t\t\tTeam Name\t:  " << teamNo << endl;
			cout << "\n\t,_____________________________________________________________________________________________________________,\n";
			cout << "\t|   Reg. No.  | First Name  |   Last Name    |     DoB     | Age |    Hometown    | Runs Scored |   Status    |\n";
			cout << "\t|-------------|-------------|----------------|-------------|-----|----------------|-------------|-------------|";

			for (int i = 0; i < 9; i++) {

				string regNum = teamRegNoArr[i];

				ifstream read(regNum + "_player_personal_details.txt");

				string data;
				int count = 0;

				cout << "\n\t| ";

				while (getline(read, data)) {

					if (count == 2) {

						cout << setw(14) << data << " | ";

					}
					else if (count == 4) {

						cout << setw(3) << data << " | ";

					}
					else if (count == 5) {

						cout << setw(14) << data << " | ";

					}
					else {

						cout << setw(11) << data << " | ";

					}

					count++;

				}
				read.close();

				if (count == 7) {

					cout << setw(14) << " | ";

				}

			}

			cout << "\n\t'-------------'-------------'----------------'-------------'-----'----------------'-------------'-------------'\n\n\n";

		}

		allTeams.close();

	}
	else if (response == '1') {

		systemHeader();

		int count = 1;
		string teamName;

		cout << "\n\n\t\t\t\tAll TEAMS registered in the culb\n\n\n";

		ifstream read("all_team_names.txt");

		while (getline(read, teamName)) {

			cout << "\n\t\t\t\t\t" << count << ". " << teamName << endl;
			count++;

		}

		read.close();

	}
	else {

		systemHeader();
		cout << "\n\n\t\t\t\tYou will be redirected to the DASHBOARD.\n\n";
		transition();
		dashboard();

	}

	cout << endl << endl;
	transition();

	systemHeader();

	char choice;
	cout << "\n\n\t\t\t\tDo you want to DISPLAY TEAMs again?\n\n";
	cout << "\n\n\n\n\t\t\t\tYour Response ('y' for YES, 'n' for NO)\t:  ";
	cin >> choice;
	system("cls");

	choice = toupper(choice);

	if (choice == 'Y') {

		displayTeams();

	}
	else {

		systemHeader();
		cout << "\n\n\t\t\t\tYou will be redirected to the DASHBOARD.\n\n";
		transition();
		dashboard();

	}

}

//Display players that are only involved with one team and not in any teams
void availableplayers() {

	systemHeader();

	string regNum, data, status, teams;

	ifstream read("all_player_reg_numbers.txt");

	cout << "\n\t\t\t\tThese players still haven't included in any club team\n";
	cout << "\n\t,_____________________________________________________________________________________________________________,\n";
	cout << "\t|   Reg. No.  | First Name  |   Last Name    |     DoB     | Age |    Hometown    | Runs Scored |   Status    |\n";
	cout << "\t|-------------|-------------|----------------|-------------|-----|----------------|-------------|-------------|";

	while (getline(read, regNum)) {

		ifstream checkplayer("personal_teams_of_player_regNo_" + regNum + ".txt");

		if (!checkplayer) {

			int count = 0;
			int checker = 0;

			ifstream checkstatus(regNum + "_player_personal_details.txt");

			while (getline(checkstatus, status)) {

				checker++;

			}
			checkstatus.close();

			ifstream getData(regNum + "_player_personal_details.txt");

			if (!getData) {

				break;

			}

			if (checker == 7) {

				cout << "\n\t| ";

				while (getline(getData, data)) {

					if (count == 2) {

						cout << setw(14) << data << " | ";

					}
					else if (count == 4) {

						cout << setw(3) << data << " | ";

					}
					else if (count == 5) {

						cout << setw(14) << data << " | ";

					}
					else {

						cout << setw(11) << data << " | ";

					}

					count++;

				}

				if (count == 7) {

					cout << setw(14) << " | ";

				}

			}

			getData.close();
			
		}
		checkplayer.close();

	}
	read.close();

	cout << "\n\t'-------------'-------------'----------------'-------------'-----'----------------'-------------'-------------'\n";

	ifstream readagain("all_player_reg_numbers.txt");

	cout << "\n\n\n\t\t\t\tThese players only have one club team\n";
	cout << "\n\t,_____________________________________________________________________________________________________________,\n";
	cout << "\t|   Reg. No.  | First Name  |   Last Name    |     DoB     | Age |    Hometown    | Runs Scored |   Status    |\n";
	cout << "\t|-------------|-------------|----------------|-------------|-----|----------------|-------------|-------------|";

	while (getline(readagain, regNum)) {

		ifstream checkplayeragain("personal_teams_of_player_regNo_" + regNum + ".txt");

		if (checkplayeragain) {

			int count = 0;
			int checker = 0;
			int amount = 0;

			while (getline(checkplayeragain, teams)) {

				amount++;

			}

			if (amount >= 2) {

				continue;

			}
			
			ifstream checkstatusagain(regNum + "_player_personal_details.txt");

			while (getline(checkstatusagain, status)) {

				checker++;

			}
			checkstatusagain.close();

			ifstream getDataagain(regNum + "_player_personal_details.txt");

			if (!getDataagain) {

				break;

			}

			if (checker == 7) {

				cout << "\n\t| ";

				while (getline(getDataagain, data)) {

					if (count == 2) {

						cout << setw(14) << data << " | ";

					}
					else if (count == 4) {

						cout << setw(3) << data << " | ";

					}
					else if (count == 5) {

						cout << setw(14) << data << " | ";

					}
					else {

						cout << setw(11) << data << " | ";

					}

					count++;

				}

				if (count == 7) {

					cout << setw(14) << " | ";

				}

			}

			getDataagain.close();

		}
		checkplayeragain.close();

	}
	readagain.close();

	cout << "\n\t'-------------'-------------'----------------'-------------'-----'----------------'-------------'-------------'\n";

	transition();
	manageTeams();

}
