#include <iostream>
#include <string>
using namespace std;

int choice;
char x;

string book[100] = {"Les Misérables", "The Little Prince", "The Tantourineh"};
string author[100] = {"Victor Hugo", "Antoine de Saint-Exupéry	", "Radwa Ashour"};
string status[100] = {"Available", "Available", "Available"};
int count = 3;

void add_b()
{
    string new_book;
    cout << "Enter new book : ";
    getline(cin, new_book);

    string new_author;
    cout << "Enter author name: ";
    getline(cin, new_author);

    book[count] = new_book;
    author[count] = new_author;
    status[count] = "Available";
    count++;
    cout << " Book added successfully! \n";
}

void view_b()
{

    for (int i = 0; i < count; i++)
    {
        cout << i + 1 << "- ";
        cout << "Book Title : " << book[i] << "\n";
        cout << "Author Name : " << author[i] << "\n";
        cout << "status : " << status[i] << "\n\n";
    }
}

void Return_b()
{
    string bookTitle;
    cout << "Enter book title to return: ";
    getline(cin, bookTitle);

    bool found = false;

    for (int i = 0; i < count; i++)
    {
        if (book[i] == bookTitle)
        {
            found = true;

            if (status[i] == "Borrowed")
            {
                status[i] = "Available";
                cout << "Book returned successfully!" << endl;
            }
            else
            {
                cout << "This book is already in the library!" << endl;
            }
            break;
        }
    }

    if (!found)
    {
        cout << "Book not found!" << endl;
    }
}
void search_b()
{

    string booksearch;
    cout << "Enter name of book : ";
    getline(cin, booksearch);

    bool found = false;
    for(int i =0; i<count; i++){
        if (book[i] == booksearch){

            cout << "Book Title : "<< book[i]<< endl;
            cout << "Author : "<< author[i]<< endl;
            cout << "Status : "<< status[i]<< endl;

            found = true;
            break;
        }
    }
        if(!found){
            cout << "Book not found" << endl;
            cout << "author not found" << endl;
            cout << "status : Not Available " << endl;
        }
    
    
}
void Borrow_b()
{
    
    string name;
    cout << "Enter name of book: ";
    getline(cin, name);
    
    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (book[i] == name)
        {
            found = true;
            if (status[i] == "Available")
            {
                status[i] = "Borrowed";
                cout << "Book Borrowed successfully" << endl;
            }
            else
            {
                cout << "Book is already Borrowed" << endl;
            } break;
        }
    }
    if (found == false)
        cout << "Book not found" << endl;
}

int main()
{
    cout << "   *** Welcome to our library ***\n\n";
    do
    {
        cout
            << "     1-Add New Book.\n"
            << "     2-Search for a Book by Title.\n"
            << "     3-Borow a Book.\n"
            << "     4-Return a Book.\n"
            << "     5-View All Books.\n"
            << "     6-Exit.\n"
            << "=> Select an option\n";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            add_b();
            break;
        case 2:
            search_b();
            break;
        case 3:
            Borrow_b();
            break;
        case 4:
            Return_b();
            break;
        case 5:
            view_b();
            break;
        case 6:
            cout << "Exiting program...\n";
            return 0;
            break;

        default:
            cout << "wrong Input\n";
            break;
        }

        cout << "Do you want to do something else? (y/n): ";
        cin >> x;
        x = tolower(x);
        if (x != 'y')
        {
            cout << "Thank you for using our library system!";
            return 0;
            
        }
    } while (x == 'y');
    
}