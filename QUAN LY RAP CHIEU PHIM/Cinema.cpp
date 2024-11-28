#include "Cinema.h"
#include<algorithm> // thư viện dùng hàm sort

Cinema::Cinema() : numBer(0), listMovie(nullptr) {} //khởi tạo giá trị mặc định

Cinema::~Cinema() { // thêm phương thức huỷ để tránh rò rỉ bộ nhớ khi dùng con trỏ động
	for (int i = 0; i < numBer; ++i)
		delete listMovie[i];
	delete[] listMovie;
}
void Cinema::nhap() {
	cout << "\nNhap so luong: "; cin >> numBer;
	if (numBer == 0) return;
	listMovie = new Movie * [numBer];
	for (int i = 0; i < numBer; ++i) {
		int movieNumber;
		string movieName;
		float ticketPrice;
		cout << "\nNhap Ma bo phim: "; cin >> movieNumber;
		cin.ignore();
		cout << "\nNhap Ten bo phim: "; getline(cin, movieName);
		cout << "\nNhap gia ve: "; cin >> ticketPrice;
		// thêm vào listMovie
		listMovie[i] = new Movie(movieNumber, movieName, ticketPrice);
	}
}

void Cinema::xuat() const {
	cout << "\nSo luong bo phim: " << numBer << rows2;
	for (int i = 0; i < numBer; ++i) {
		cout << "\Bo phim thu " << i + 1 << " : " << rows2;
		listMovie[i]->hienThiThongTin();
		cout << "------------" << rows2;
	}
}

// get số lượng
int Cinema::getCount() const {
	return numBer;
}

bool Cinema::addMovie(int movieNumber, string movieName, float ticketPrice) {
	if (searchMovie(movieNumber) != -1) return false;// phim đã tồn tại
	Movie** listNew = new Movie*[numBer + 1];
	for (int i = 0; i < numBer; ++i) {// sao chép sang mảng mới listNew
		listNew[i] = listMovie[i];
	}
	listNew[numBer] = new Movie(movieNumber, movieName, ticketPrice);
	++numBer;//tăng số lượng lên 1 sau khi thêm thành công
	delete[] listMovie;// giải phóng bộ nhớ tránh rò rỉ
	listMovie = listNew;// trỏ đến listNew
	return true;// thêm thành công
}
// viết hàm seach trước nha
int Cinema::searchMovie(int movieNumber) const {
	for (int i = 0; i < numBer; ++i) {
		if (listMovie[i]->getMovieNumber() == movieNumber)
			return i;
	}
	return -1;
}

void Cinema::searchRange(float start, float end) const {
	cout << "\nDanh sach co gia tu " << start << " den " << end << " : " << rows2;
	for (int i = 0; i < numBer; ++i) {
		float gia = listMovie[i]->getTicketPrice();
		if (start <= gia && gia <= end) {
			listMovie[i]->hienThiThongTin();
			cout << "------------" << rows2;
		}
	}
}

// CÁCH KHÁC
//void Cinema::sortPrice(int order) {
//	auto compare = [order](Movie* a, Movie* b)
//		{ return order == 1 ? a->getTicketPrice() < b->getTicketPrice()
//		: a->getTicketPrice() > b->getTicketPrice(); }; 
//	sort(listMovie, listMovie + numBer, compare);
//}

void Cinema::sortPrice(int order) {
	if (order == 1) {
		sort(listMovie, listMovie + numBer, [](Movie* a, Movie* b) {
			return a->getTicketPrice() < b->getTicketPrice();
			});
	}
	else if (order == -1) {
		sort(listMovie, listMovie + numBer, [](Movie* a, Movie* b) {
			return a->getTicketPrice() > b->getTicketPrice();
			});
	}
}

bool Cinema::removeMovie(int movieNumber) {
	int viTri = searchMovie(movieNumber);
	if (viTri == -1) return false;// không tìm thấy bộ phim
	delete listMovie[viTri];
	for (int i = viTri; i < numBer - 1; ++i) {
		listMovie[i] = listMovie[i + 1];
	}
	--numBer;
	return true;// xoá thành công
}

// getter listMovie để sử dụng bên hàm main bắt buộc phải getter
Movie** Cinema::getListMovie() const { return listMovie; }

