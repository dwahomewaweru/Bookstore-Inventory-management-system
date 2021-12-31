// Bookstore-Inventory-management-system.cpp 
// C++ Project Proposal

//Libraries
#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

//Create Class for books in inventory
class book {
private:
	char* author, * title, * publisher;
	float* price;
	int* stock;
public:
	book() {
		author = new char[20];
		title = new char[20];
		publisher = new char[20];
		price = new float;
		stock = new int;
	}
	void feeddata();
	void editdata();
	void showdata();
	int search(char[], char[]);
	void buybook();
	 
};

void book::feeddata() {
	cin.ignore();
	cout << "\nEnter Author Name: ";    cin.getline(author, 20);
	cout << "Enter Book Title: ";       cin.getline(title, 20);
	cout << "Enter Publisher Name: ";   cin.getline(publisher, 20);
	cout << "Enter Price of book: ";    cin >> *price;
	cout << "Enter Stock Number: ";     cin >> *stock;

}

void book::editdata() {

	cout << "\nEnter Author Name: ";    cin.getline(author, 20);
	cout << "Enter Book Title: ";       cin.getline(title, 20);
	cout << "Enter Publisher Name: ";   cin.getline(publisher, 20);
	cout << "Enter Price of book: ";    cin >> *price;
	cout << "Enter Stock Number: ";     cin >> *stock;

}

void book::showdata() {
	cout << "\nAuthor Name: " << author;
	cout << "\nBook Title: " << title;
	cout << "\nPublisher Name: " << publisher;
	cout << "\nPrice of book: " << *price;
	cout << "\nStock Number: " << *stock;

}

int book::search(char[], char[])
{
	return 0;
}

void book::buybook() {
	int count;
	cout << "\nEnter Number Of Books to buy: ";
	cin >> count;
	if (count <= *stock) {
		*stock = *stock - count;
		cout << "\nBooks Bought Sucessfully";
		cout << "\nAmount: Rs. " << (*price) * count;
	}
	else
		cout << "\nRequired Copies not in Stock";
}
//System Main Function with Store Menu
int main() {
	book* B[20];
	int i = 0, r, t, choice;
	char titlebuy[20], authorbuy[20];
	while (1) {
		cout << "\n***BOOKSTORE INVENTORY MANAGEMENT SYSTEM***";
		cout << "\n\n\t\tSTORE MENU\n"
			<< "\n1. Add New Book"
			<< "\n2. Buy Book"
			<< "\n3. Search Book"
			<< "\n4. Modify Book Details"
			<< "\n5. Exit"
			<< "\n\nEnter Choice no. : ";
		cin >> choice;

		switch (choice) {
		case 1:	B[i] = new book;
			B[i]->feeddata();
			i++;	break;

		case 2: cin.ignore();
			cout << "\nEnter Title Of Book: "; cin.getline(titlebuy, 20);
			cout << "Enter Author Of Book: ";  cin.getline(authorbuy, 20);
			for (t = 0; t < i; t++) {
				if (B[t]->search(titlebuy, authorbuy)) {
					B[t]->buybook();
					break;
				}
			}
			if (t == 1)
				cout << "\nThis Book is not in Stock";

			break;
		case 3: cin.ignore();
			cout << "\nEnter Title Of Book: "; cin.getline(titlebuy, 20);
			cout << "Enter Author Of Book: ";  cin.getline(authorbuy, 20);

			for (t = 0; t < i; t++) {
				if (B[t]->search(titlebuy, authorbuy)) {
					cout << "\nBook Found Successfully";
					B[t]->showdata();
					break;
				}
			}
			if (t == i)
				cout << "\nThis Book is not in Stock";
			break;

		case 4: cin.ignore();
			cout << "\nEnter Title Of Book: "; cin.getline(titlebuy, 20);
			cout << "Enter Author Of Book: ";  cin.getline(authorbuy, 20);

			for (t = 0; t < i; t++) {
				if (B[t]->search(titlebuy, authorbuy)) {
					cout << "\nBook Found Successfully";
					B[t]->editdata();
					break;
				}
			}
			if (t == i)
				cout << "\nThis Book is Not in Stock";
			break;

		case 5: exit(0);
		default: cout << "\nInvalid Choice Entered";

		}
	}




	return 0;
}