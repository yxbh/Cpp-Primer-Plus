#include "chapter16_exercises.h"

struct Review {
    std::string title;
	float price;
    int rating;
	Review() {}
	~Review() {}
};

static bool operator<(const Review & r1, const Review & r2);
static bool operator<(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
//static bool worseThan(const Review & r1, const Review & r2);
static bool worseThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
static bool FillReview(std::shared_ptr<Review> r);
//static void ShowReview(const Review & rr);
static void ShowReview(std::shared_ptr<Review> r);

void ch16ex10(void)
{
	using namespace std;

    vector<shared_ptr<Review>> books;
    shared_ptr<Review> temp(new Review);
    while (FillReview(temp))
	{
		books.push_back(temp);
		temp = shared_ptr<Review>(new Review);
	}
        
    if (books.size() > 0)
    {
        cout << "Thank you. You entered the following "
             << books.size() << " ratings:\n"
              << "Rating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        sort(books.begin(), books.end());
        cout << "Sorted by title:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        sort(books.begin(), books.end(), worseThan);
        cout << "Sorted by rating:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        random_shuffle(books.begin(), books.end());
        cout << "After shuffling:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n";
}

bool operator<(const Review & r1, const Review & r2)
{
    if (r1.title < r2.title)
        return true;
    else if (r1.title == r2.title && r1.rating < r2.rating)
        return true;
    else
        return false;
}

bool operator<(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2)
{
	if (r1->title < r2->title)
        return true;
    else if (r1->title == r2->title && r1->rating < r2->rating)
        return true;
    else
        return false;
}


//bool worseThan(const Review & r1, const Review & r2)
//{
//    if (r1.rating < r2.rating)
//        return true;
//    else
//        return false;
//}

bool worseThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2)
{
	if (r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool FillReview(std::shared_ptr<Review> r)
{
	std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin,r->title);
    if (r->title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> r->rating;
    if (!std::cin)
        return false;
    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    return true;
}


//void ShowReview(const Review & rr)
//{
//    std::cout << rr.rating << "\t" << rr.title << std::endl; 
//}

void ShowReview(std::shared_ptr<Review> r)
{
	std::cout << r->rating << "\t" << r->title << std::endl; 
}
