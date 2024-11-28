#pragma once
#include<string>
#include<iostream>
#include<iomanip>
#define endl "\n"
#define rows2 "\n\n"
using namespace std;

class Movie
{
private:
	int movieNumber;
	string movieName;
	float ticketPrice;
public:
	// nên khởi tạo mặc định
	Movie();
	Movie(int movieNumber, const string& movieName, float ticketPrice);
	int getMovieNumber() const;
	string getMovieName() const;
	float getTicketPrice() const;
	void hienThiThongTin() const;
};

