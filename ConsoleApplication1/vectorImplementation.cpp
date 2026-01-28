#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
int NumberCheck(string text) {
	int input = 0;
	while (input <= 0) {
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
	};

	return input;
}

// extra options
void TicketNameSearch(vector<BorrowedTicket> List, string personName) {
	for (BorrowedTicket ticket : List)
	{
		if (ticket.showID() == personName)
		{
			ticket.ShowAllInfo();
			return;
		}
	}
};

void removeTicket(vector<BorrowedTicket> &List, int index) { //the '&' is so youre ACTUALLY referencing the list, without it would copy the entire vector
	List.erase(List.begin() + index);
};

void changeProperties(BorrowedTicket &ticketToChange) {
	cout << "\n" << "[1]: Books borrowed";
	cout << "\n" << "[2]: Books borrow length" << "\n";
	int propertyID = NumberCheck("Property to change?: ");
	int BooksToChange;
	int LengthToChange;

	switch (propertyID) {
	case 1:
		BooksToChange = NumberCheck("Amount of books borrowed: ");
		ticketToChange.BorrowedAmount = BooksToChange;
		break;
	case 2:
		LengthToChange = NumberCheck("Days borrowed: ");
		ticketToChange.DaysBorrowed = LengthToChange;
		break;
	default:
		cout << "\nNothing was changed!";
	};
}

void Statistics(vector<BorrowedTicket> List) {
	int size = List.size();
	int total = 0;
	
	for (BorrowedTicket ticket : List) {
		total = total + ticket.showBooksBorrowed();
	}

	cout << "Total borrowed: " << total << " Average books: " << (total / size);
	return;
}

void AddIndTicket(vector<BorrowedTicket>& List) {
	string Name = TextCheck("Name of person borrowing?: ");
	string TicketID = TextCheck("ID of ticket?: ");
	int daysUserBorrowed = NumberCheck("How many days has this person borrowed?: ");
	int BooksBorrowed = NumberCheck("How many books has this person borrowed?: ");

	BorrowedTicket newTicket(Name, TicketID, BooksBorrowed, daysUserBorrowed, List.size());
	List.push_back(newTicket);
	return;
}

void MoreSettingsShow(vector<BorrowedTicket> &List){
	int moreChoice = 1;
	int TicketIndexRemove;
	int TicketPropertyChangeID;
	string nameToSearch;

	while (moreChoice < 5) {
		cout << "\n" << "Extra Option: " << "\n";
		cout << "[1]: Name Search" << "\n";
		cout << "[2]: Remove Ticket" << "\n";
		cout << "[3]: Statistics" << "\n";
		cout << "[4]: Add new ticket" << "\n";
		cout << "[5]: Change borrowed amount and borrow length" << "\n";
		cout << "[6 or more]: Exit Extended Options" << "\n";

		moreChoice = NumberCheck("Enter Option: ");

		switch (moreChoice) {
		case 1:
			nameToSearch = TextCheck("\nName of person to search?: ");

			TicketNameSearch(List, nameToSearch);
			break;
		case 2: 
			TicketIndexRemove = NumberCheck("\nTicket at position to remove: ");
			removeTicket(List, TicketIndexRemove);
			break;
		case 3:
			Statistics(List);
			break;
		case 4:
			AddIndTicket(List);
			break;
		case 5:
			TicketPropertyChangeID = NumberCheck("ID of ticket to change property of: ");
			changeProperties(List[TicketPropertyChangeID - 1]);
			break;
		default: 
			cout << "Returning to standard menu" << "\n";
		}
	}; 
};

int main() {
	int numberOfBorrows = NumberCheck("Enter amount of tickets: ");
	
	vector<BorrowedTicket> TicketsList;
	for (int i = 0; i < numberOfBorrows; i++)
	{
		string Name = TextCheck("Name of person borrowing?: ");
		string TicketID = TextCheck("ID of ticket?: ");
		int daysUserBorrowed = NumberCheck("How many days has this person borrowed?: ");
		int BooksBorrowed = NumberCheck("How many books has this person borrowed?: ");

		BorrowedTicket newTicket(Name, TicketID, BooksBorrowed, daysUserBorrowed, i);
		TicketsList.push_back(newTicket);
	};

	int choice = 1;
	string idToSearch;

	while (choice < 6) {
		cout << "\n" << "Option: " << "\n";
		cout << "[1]: Show All" << "\n";
		cout << "[2]: Search" << "\n";
		cout << "[3]: Highest book borrows" << "\n";
		cout << "[4]: Lowest book borrows" << "\n";
		cout << "[5]: More Options" << "\n";
		cout << "[6 or more]: Exit" << "\n";

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
		case 5:
			MoreSettingsShow(TicketsList);
			break;
		default:
			cout << "Exiting app";
		}
	};

	return 0;
}