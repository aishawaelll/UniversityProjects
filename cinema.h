struct tmpSeats {
	double price;
	string seat;
	void setPrice(double p) {
		price = p;
	}
};

class movieInfo {
	public:
		/*
		 * movies are here
		 */
};

class cinema {
	private:
		int response, id;
		tmpSeats s;
		sysObjects sys;
		ux UX;
	public:
		/*
		 * The main menu here
		 */
		client Client;
		seats reserve;
		void mainMenuData () {
			/*
			 * This function previews entries for main menu, and take response
			 */
			sys.clearScreen();
			UX.welcome();
			cout << "	1) Movies information\n";
			cout << "	2) Reserve a ticket\n";
			cout << "	3) View your reservations\n";
			cout << "	4) Register a new account\n";
			cout << "	5) Exit\n" << endl;
			int entries = 5;

			cout << "Please write your choice: ";
			cin >> response;

			while (response>entries || response<1) {
				cout << "Can you please enter a valid choice? ";
				cin >> response;
			}
		}
						
		void mainMenu() {
			/*
			 * Here choosing from main menu and redirection for the 
			 * other functionalities occur
			 */
			cout << "\nHow can I help you today? :)\n\n";
			mainMenuData();
			switch(response) {
				case 2:
					switch(reserve.movieRegistration("Movies.txt")) {
						case -1:
							mainMenu();	
						case -3:
							if(Client.personalInfo() == -1) mainMenu();
					}
				case 4:
					if(Client.personalInfo() == -1) mainMenu();
				case 5:
					sys.clearScreen(); UX.welcome();
					cout << "\n\nThank you for your visit. Have a nice day!\n\n"; 
					exit(2);
			}
		}

};
