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
    Book b1;
    int menu;

    while (true) {
        cout << "\nEnter 1 - ADD Book\n";
        cout << "Enter 2 - DISPLAY BOOK\n";
        cout << "Enter 3 - EXIT\n";
        cout << "Choose an option: ";
        cin >> menu;
        cin.ignore(); 

        switch(menu){
            case 1: {
                cout << "ADD BOOK\n";
                string title;
                string author;
                int year;

                cout << "Enter the book's title: ";
                getline(cin, title);
                b1.setTitle(title);

                cout << "Enter the book's author: ";
                getline(cin, author);
                b1.setAuthor(author);

                cout << "Enter the book's year: ";
                cin >> year;
                b1.setYear(year);

                cout << "Book added successfully!\n"; 
                break;
            }
            case 2: {
                if (b1.isEmpty()) {
                    cout << "No book added yet.\n";
                } else {
                    cout << "DISPLAY BOOK\n";
                    cout << "Title: " << b1.getTitle() << endl;
                    cout << "Author: " << b1.getAuthor() << endl;
                    cout << "Year: " << b1.getYear() << endl;
                }
                break;
            }
            case 3:
                cout << "Exiting the program...\n";
                return 0;

            
            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }
    }

    return 0;
}
