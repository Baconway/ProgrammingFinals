#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BorrowedTicket {
	private:
		string PersonBorrowing;
		string ticketID;
		int BorrowedAmount;
		int DaysBorrowed;
		int ID;
	public:
		BorrowedTicket(string person, string tID, int amount, int days, int id) {
			ticketID = tID;
			ID = id;
			BorrowedAmount = amount;
			DaysBorrowed = days;
			PersonBorrowing = person;
		}

		void ShowAllInfo() {
			cout << "[ID]: " << ID << ", Person " << PersonBorrowing << " Has Borrowed " << BorrowedAmount << " Book(s) for " << DaysBorrowed << " day(s)." << "\n";
		};
		
		string showID() {
			return ticketID;
		}

		int showBooksBorrowed() {
			return BorrowedAmount;
		}
};

void ShowAll(vector<BorrowedTicket> List) {
	for (BorrowedTicket ticket : List)
	{
		ticket.ShowAllInfo();
	}
}

void TicketIDSearch(vector<BorrowedTicket> List, string SearchID) {
	for (BorrowedTicket ticket : List)
	{
		if (ticket.showID() == SearchID)
		{
			ticket.ShowAllInfo();
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

int sixSeven(string text) {
	int input = 0;
	while (input == 0) {
		cout << text;
		cin >> input;
		cin.clear();
		cin.ignore(10000, '\n');
	}
	
	return input;
}

string sixSeven2(string text) {
	string input;
	while (input.empty()) {
		cout << text;
		getline(cin, input);
	}

	return input;
}

int main() {
	int numberOfBorrows = sixSeven("Enter amount of tickets: ");
	
	vector<BorrowedTicket> TicketsList;
	for (int i = 0; i < numberOfBorrows; i++)
	{
		string Name = sixSeven2("Name of person borrowing?: ");
		string TicketID = sixSeven2("ID of ticket?: ");
		int daysUserBorrowed = sixSeven("How many days has this person borrowed?: ");
		int BooksBorrowed = sixSeven("How many books has this person borrowed?: ");

		BorrowedTicket newTicket(Name, TicketID, BooksBorrowed, daysUserBorrowed, i);
		TicketsList.push_back(newTicket);
	};

	int choice = 1;
	string idToSearch;

	while (choice != 5) {
		cout << "\n" << "Option: " << "\n";
		cout << "[1]: Show All" << "\n";
		cout << "[2]: Search" << "\n";
		cout << "[3]: Highest book borrows" << "\n";
		cout << "[4]: Lowest book borrows" << "\n";
		cout << "[5]: Exit" << "\n";

		choice = sixSeven("Enter Option: ");

		switch (choice) {
		case 1:
			ShowAll(TicketsList); 
			break;
		case 2:
			idToSearch = sixSeven2("\nInput ID to search: ");

			TicketIDSearch(TicketsList, idToSearch);
			break;
		case 3:
			TicketIDSearch(TicketsList, HighestSearch(TicketsList));;
			break;
		case 4:
			TicketIDSearch(TicketsList, LowestSearch(TicketsList));;
			break;
		default:
			cout << "Could not find option available";
		}
	};

	return 0;
}