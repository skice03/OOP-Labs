#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "header.h"

using namespace std;

int main()
{
    // creare objects (clieni, carti)
    Client client1("Marian");
    Client client2("Bona");

    Book book1("The Great Gatsby");
    Book book2("1984");

    // creare librarie
    Library library;
    library.addBook(book1);
    library.addBook(book2);

    // adaugare reviews
    Review review1("Amazing story, loved the characters!", &client1);
    Review review2("A bit dystopian, but very thought-provoking.", &client2);

    library.addReviewToBook("The Great Gatsby", review1);
    library.addReviewToBook("1984", review2);

    // afisare carti si reviews
    library.displayAllBooks();
    book1.displayReviews();
    book2.displayReviews();

    // cautare text
    string searchTerm;
    cout << "\nEnter a search term (review or reviewer name): ";
    getline(cin, searchTerm);
    library.searchReviews(searchTerm);

    return 0;
}