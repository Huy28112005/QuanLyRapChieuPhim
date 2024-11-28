#pragma once
#include "Movie.h"

class Cinema
{
private:
	int numBer;
	Movie** listMovie;
public:
	Cinema();
	~Cinema();
	// nhập xuất
	void nhap();
	void xuat() const;
	int getCount() const;
	bool addMovie(int movieNumber, string movieName, float ticketPrice);
	int searchMovie(int movieNumber) const;
	void searchRange(float start, float end) const;
	void sortPrice(int order);
	bool removeMovie(int movieNumber);
	Movie** getListMovie() const;
};

