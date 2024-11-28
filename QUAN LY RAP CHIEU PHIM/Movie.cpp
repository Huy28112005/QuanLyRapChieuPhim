#include "Movie.h"

Movie::Movie() {
	movieNumber = 0;
	movieName = "";
	ticketPrice = 0.0f;
}
Movie::Movie(int movieNumber, const string& movieName, float ticketPrice) {
	this->movieNumber = movieNumber;
	this->movieName = movieName;
	this->ticketPrice = ticketPrice;
}
// lấy mã bộ phim
int Movie::getMovieNumber() const { return movieNumber; }
// lấy tên bộ phim
string Movie::getMovieName() const { return movieName; }
// lấy giá vé
float Movie::getTicketPrice() const { return ticketPrice; }
// hiển thị thông tin bộ phim
void Movie::hienThiThongTin() const {
	cout << "\nMa bo phim: " << movieNumber << rows2;
	cout << "Ten bo phim: " << movieName << rows2;
	cout << setprecision(2) << fixed;//hiển thị chữ số thập phân là 2
	cout << "Gia ve: " << ticketPrice << " VND" << rows2;
}
