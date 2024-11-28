#include"Cinema.h"

int main() {
	Cinema cinema; 
	int luaChon;
	do {
		cout << "QUAN LY TAI CINEMA" << endl;
		cout << "1. Khoi tao danh sach bo phim." << endl;
		cout << "2. Xuat danh sach cac bo phim." << endl;
		cout << "3. Xuat so luong bo phim." << endl;
		cout << "4. Them bo phim." << endl;
		cout << "5. Tim kiem bo phim theo ma bo phim." << endl;
		cout << "6. Tim kiem bo phim theo khoang gia." << endl;
		cout << "7. Sap xep danh sach bo phim." << endl;
		cout << "8. Xoa bo phim." << endl;
		cout<<"9. Thoat." << endl;
		cout << "Chon mot tuy chon: ";
		cin >> luaChon;
		switch (luaChon)
		{
		case 1:
			cinema.nhap(); break;
		case 2:
			cinema.xuat(); break;
		case 3:
			cout << "\nSo luong bo phim: " << cinema.getCount() << endl;
			break;
		case 4: {
			int movieNumber;
			string movieName;
			float ticketPrice;
			cout << "Nhap ma phim: ";
			cin >> movieNumber;
			cout << "Nhap ten phim: "; cin.ignore();
			getline(cin, movieName);
			cout << "Nhap gia ve: ";
			cin >> ticketPrice;
			if (cinema.addMovie(movieNumber, movieName, ticketPrice)) {
				cout << "Them phim thanh cong.\n";
			}
			else {
				cout << "Phim da ton tai.\n";
			}
			break;
		}
		case 5: {
			int movieNumber;
			cout << "Nhap ma phim can tim: ";
			cin >> movieNumber;
			int viTri = cinema.searchMovie(movieNumber);
			if (viTri != -1) {
				cinema.getListMovie()[viTri]->hienThiThongTin();
			}
			else {
				cout << "Khong tim thay phim.\n";
			}
			break;
		}
		case 6: {
			float start, end;
			cout << "Nhap khoang gia ve (start end): ";
			cin >> start >> end;
			cinema.searchRange(start, end);
			break;
		}
		case 7: {
			int order; 
			cout << "Nhap thu tu sap xep (1: tang dan, -1: giam dan): ";
			cin >> order; 
			cinema.sortPrice(order); 
			break;
		}
		case 8: {
			int movieNumber; 
			cout << "Nhap ma phim can xoa: "; 
			cin >> movieNumber; 
			if (cinema.removeMovie(movieNumber)) { 
				cout << "Xoa phim thanh cong.\n"; 
			}
			else { 
				cout << "Khong tim thay phim.\n"; 
			}
			break;
		}
		case 9:
			cout<<"\nThoat chuong trinh." << endl;
			break;
		default:
			cout << "Lua chon khong hop le!";
		}
	} while (luaChon != 9);
	return 0;
}
