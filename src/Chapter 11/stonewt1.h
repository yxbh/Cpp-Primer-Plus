// Stonewt_book1.h -- revised definition for the Stonewt_book class
#ifndef Stonewt_book1_H_
#define Stonewt_book1_H_
class Stonewt_book
{
private:
    enum {Lbs_per_stn = 14};      // pounds per stone
    int stone;                    // whole stones
    double pds_left;              // fractional pounds
    double pounds;                // entire weight in pounds
public:
    Stonewt_book(double lbs);          // construct from double pounds
    Stonewt_book(int stn, double lbs); // construct from stone, lbs
    Stonewt_book();                    // default constructor
    ~Stonewt_book();
    void show_lbs() const;        // show weight in pounds format
    void show_stn() const;        // show weight in stone format
	Stonewt_book operator*(const double &) const;
//friend function
	friend Stonewt_book operator*(const double &, const Stonewt_book &);
// conversion functions
    operator int() const;
    operator double() const;
};
#endif
