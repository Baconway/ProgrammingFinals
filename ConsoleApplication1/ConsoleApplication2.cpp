#include <iostream>
#include <list>
#include <string>
#include <limits.h>
using namespace std;

class BorrowedTicket {
private:
	string PersonBorrowing;
	string ticketID;
	int ID;
public:
	int BorrowedAmount;
	int DaysBorrowed;

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

// base functions
void ShowAll(list<BorrowedTicket> List) {
	for (BorrowedTicket ticket : List)
	{
		ticket.ShowAllInfo();
	}
};

void TicketIDSearch(list<BorrowedTicket> List, string SearchID) {
	for (BorrowedTicket ticket : List)
	{
		if (ticket.showID() == SearchID)
		{
			ticket.ShowAllInfo();
			return;
		}
	}
};

string HighestSearch(list<BorrowedTicket> List) {
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

string LowestSearch(list<BorrowedTicket> List) {
	int LowestBooks = INT_MAX;
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

//input validation (reference: https://www.w3schools.com/cpp/cpp_input_validation.asp)
int NumberCheck(string text, bool limited, int to = 0, int from = 0) {
	int input = 0;
	if (!limited) {
		while (input <= 0) {
			cout << text;
			cin >> input;
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
	else {
		while (input <= to || input > from) {
			cout << text;
			cin >> input;
		}
	}
	return input;
}

string TextCheck(string text) {
	string input;
	while (input.empty()) {
		cout << text;
		getline(cin, input);
	};

	return input;
}

int main() {
	int numberOfBorrows = NumberCheck("Enter amount of tickets: ", false);

	list<BorrowedTicket> TicketsList;
	for (int i = 0; i < numberOfBorrows; i++)
	{
		string Name = TextCheck("Name of person borrowing?: ");
		string TicketID = TextCheck("ID of ticket?: ");
		int daysUserBorrowed = NumberCheck("How many days has this person borrowed?: ", false);
		int BooksBorrowed = NumberCheck("How many books has this person borrowed?: ", false);

		BorrowedTicket newTicket(Name, TicketID, BooksBorrowed, daysUserBorrowed, i);
		TicketsList.push_back(newTicket);
	};

	int choice = 1;
	string idToSearch;

	while (choice < 5) {
		cout << "\n" << "Option: " << "\n";
		cout << "[1]: Show All" << "\n";
		cout << "[2]: Search" << "\n";
		cout << "[3]: Highest book borrows" << "\n";
		cout << "[4]: Lowest book borrows" << "\n";
		cout << "[5 or more]: Expect" << "\n";

		choice = NumberCheck("Enter Option: ", false);

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
	};

	return 0;
}