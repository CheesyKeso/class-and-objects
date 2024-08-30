#include <iostream>
using namespace std;

class Book{
    private:
        string title;
        string author;
        int year;

    public:
        void setTitle(string t){
            title = t;
        }
        void setAuthor(string a){
            author = a;
        }
        void setYear(int y){
            year = y;
        }
        string getTitle(){
            return title;
        }
        string getAuthor(){
            return author;
        }
        int getYear(){
            return year;
        }

        bool isEmpty(){
            return title.empty() && author.empty() && year == 0;
        }
};

int main(){
    Book books[5];
    int bookCount = 0;
    int menu;

    while (true) {
        cout << "\nEnter 1 - ADD Book\n";
        cout << "Enter 2 - DISPLAY BOOKS\n";
        cout << "Enter 3 - SEARCH BOOK\n";
        cout << "Enter 4 - EXIT\n";
        cout << "Choose an option: ";
        cin >> menu;
        cin.ignore(); 

        switch(menu){
            case 1: {
                if(bookCount < 5){
                    cout << "1 - Add Book\n";
                    string title;
                    string author;
                    int year;

                    cout << "Enter title: ";
                    getline(cin, title);
                    books[bookCount].setTitle(title);

                    cout << "Enter author: ";
                    getline(cin, author);
                    books[bookCount].setAuthor(author);

                    cout << "Enter year: ";
                    cin >> year;
                    books[bookCount].setYear(year);

                    cout << "Book added successfully!\n";
                    bookCount++;
                } else {
                    cout << "You have reached the maximum number of books (5).\n";
                }
                break;
            }
            case 2: {
                if (bookCount == 0) {
                    cout << "No books added yet.\n";
                } else {
                    cout << "Title\t\tAuthor\t\tYear\t\n";

                for (int i = 0; i < bookCount; i++) {
                    cout << books[i].getTitle() << "\t\t"
                        << books[i].getAuthor() << "\t\t"
                        << books[i].getYear() << endl;
                }
                }
                break;
            }

            case 3: {
                cout << "SEARCH BOOK\n";
                string searchTitle;
                cout << "Enter a book title to search: ";
                getline(cin, searchTitle);

                bool found = false;
                for (int i = 0; i < bookCount; i++) {
                    if (books[i].getTitle() == searchTitle) {
                        cout << "Book found!\n";
                        cout << "Title: " << books[i].getTitle() << "\n";
                        cout << "Author: " << books[i].getAuthor() << "\n";
                        cout << "Year: " << books[i].getYear() << "\n";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Book not found.\n";
                }
                break;
            }
            case 4:
                cout << "Exiting the program...\n";
                return 0;

            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }
    }
    return 0;
}
