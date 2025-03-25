#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Client
{
private:
    string name;

public:
    Client(string name) : name(name) {}

    string getName() const
    {
        return name;
    }
};

class Review
{
private:
    string content;
    Client *client; // pointer catre client

public:
    Review(string content, Client *client) : content(content), client(client) {}

    string getContent() const
    {
        return content;
    }

    Client *getClient() const
    {
        return client;
    }
};

class Book
{
private:
    string title;
    vector<Review> reviews;

public:
    Book(string title) : title(title) {}

    string getTitle() const
    {
        return title;
    }

    void addReview(const Review &review)
    {
        reviews.push_back(review);
    }

    void displayReviews() const
    {
        cout << "\nReviews for " << title << ":\n";
        if (reviews.empty())
        {
            cout << "No reviews yet.\n";
        }
        else
        {
            for (const auto &review : reviews)
            {
                cout << "Review by " << review.getClient()->getName() << ": " << review.getContent() << endl;
            }
        }
    }

    vector<Review> getReviews() const
    {
        return reviews;
    }
};

// clasa pt. librarie pt. a gestiona cartile
class Library
{
private:
    vector<Book> books;

public:
    void addBook(const Book &book)
    {
        books.push_back(book);
    }

    void addReviewToBook(const string &bookTitle, const Review &review)
    {
        for (auto &book : books)
        {
            if (book.getTitle() == bookTitle)
            {
                book.addReview(review);
                return;
            }
        }
        cout << "Book with title " << bookTitle << " not found.\n";
    }

    void displayAllBooks() const
    {
        cout << "\nBooks in the library:\n";
        for (const auto &book : books)
        {
            cout << book.getTitle() << endl;
        }
    }

    // functie pt. a cauta text in reviews / carti
    void searchReviews(const string &searchText) const
    {
        bool found = false;
        for (const auto &book : books)
        {
            for (const auto &review : book.getReviews())
            {
                if (review.getContent().find(searchText) != string::npos || review.getClient()->getName().find(searchText) != string::npos)
                {
                    cout << "Found in Book: " << book.getTitle() << endl;
                    cout << "Review by " << review.getClient()->getName() << ": " << review.getContent() << endl;
                    found = true;
                }
            }
        }
        if (!found)
        {
            cout << "No matching reviews found.\n";
        }
    }
};

#endif