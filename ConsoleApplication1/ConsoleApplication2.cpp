#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BorrowedTicketList {
	struct Item {
		string PersonBorrowing;
		string ticketID;
	
		int BorrowedAmount;
		int DaysBorrowed;
		int ID;

		Item* next = nullptr;
		};

	Item* nextObj;
	public:
		void insert() {
			Item* newTicket = new Item();

			Item* previous = nextObj;
			while (previous->next != nullptr) {
				previous = previous->next;
			}

			previous->next = newTicket;
		};
};


/*void ShowAll(vector<BorrowedTicket> List) {
	for (BorrowedTicket ticket : List)
	{
		//ticket.ShowAllInfo();
	}
}

void TicketIDSearch(vector<BorrowedTicket> List, string SearchID) {
	for (BorrowedTicket ticket : List)
	{
		if (ticket.showID() == SearchID)
		{
			//ticket.ShowAllInfo();
			return;
		}
	}
}

string HighestSearch(vector<BorrowedTicket> List) {
	int HighestBooks = 0;
	string HighestID;

	for (BorrowedTicket ticket : List)
	{
		if (ticket.showBooksBorrowed() > HighestBooks) {
			HighestBooks = ticket.showBooksBorrowed();
			HighestID = ticket.showID();
		}
	}

	return HighestID;
};
string LowestSearch(vector<BorrowedTicket> List) {
	int LowestBooks = 670000;
	string LowestID;

	for (BorrowedTicket ticket : List)
	{
		if (LowestBooks > ticket.showBooksBorrowed()) {
			LowestBooks = ticket.showBooksBorrowed();
			LowestID = ticket.showID();
		}
	}

	return LowestID;
};

// reference: https://www.w3schools.com/cpp/cpp_input_validation.asp
int NumberCheck(string text) {
	int input = 0;
	while (input == 0) {
		cout << text;
		cin >> input;
		cin.clear();
		cin.ignore(10000, '\n');
	}

	return input;
}

string TextCheck(string text) {
	string input;
	while (input.empty()) {
		cout << text;
		getline(cin, input);
	}

	return input;
}

int main() {
	int numberOfBorrows = NumberCheck("Enter amount of tickets: ");

	//vector<BorrowedTicket> TicketsList;
	BorrowedTicket* lastTicket{};
	for (int i = 0; i < numberOfBorrows; i++)
	{
		string Name = TextCheck("Name of person borrowing?: ");
		string TicketID = TextCheck("ID of ticket?: ");
		int daysUserBorrowed = NumberCheck("How many days has this person borrowed?: ");
		int BooksBorrowed = NumberCheck("How many books has this person borrowed?: ");

		BorrowedTicket newTicket(Name, TicketID, BooksBorrowed, daysUserBorrowed, i, lastTicket);
		cout << lastTicket;
		if (i != 0 && i != numberOfBorrows)
		{
			lastTicket->nextObj = &newTicket;
		}
		//TicketsList.push_back(newTicket);
	};

	int choice = 1;
	string idToSearch;

	/*while (choice != 5) {
		cout << "\n" << "Option: " << "\n";
		cout << "[1]: Show All" << "\n";
		cout << "[2]: Search" << "\n";
		cout << "[3]: Highest book borrows" << "\n";
		cout << "[4]: Lowest book borrows" << "\n";
		cout << "[5]: Exit" << "\n";

		choice = NumberCheck("Enter Option: ");

		switch (choice) {
		case 1:
			ShowAll(TicketsList);
			break;
		case 2:
			idToSearch = TextCheck("\nInput ID to search: ");

			TicketIDSearch(TicketsList, idToSearch);
			break;
		case 3:
			TicketIDSearch(TicketsList, HighestSearch(TicketsList));;
			break;
		case 4:
			TicketIDSearch(TicketsList, LowestSearch(TicketsList));;
			break;
		default:
			cout << "Exiting app";
		}
	};*/

	//return 0;
//}

int main() {
	BorrowedTicketList a;
	a.insert();

	return 0; }