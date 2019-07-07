#include "in_menu.h"

void in_menu_start()
{
	cout << "\n _________________________________________________________________ ";
	cout << "\n|                   THU VIEN DAI HOC BACH KHOA                    |";
	cout << "\n|                                                                 |";
	cout << "\n|_________________________________________________________________|";
	cout << "\n|                                                                 |";
	cout << "\n|Nhan enter de dang nhap vao he thong thu vien                    |";
	cout << "\n|Dang ki voi nguoi quan ly thu vien de duoc cap tai khoan         |";
	cout << "\n|_________________________________________________________________|";
	cout << endl;
}
void in_menu_thu_thu()
{
	cout << "\n _________________________________________________________________ ";
	cout << "\n|                   THU VIEN DAI HOC BACH KHOA                    |";
	cout << "\n|                            Thu thu                              |";
	cout << "\n|_________________________________________________________________|";
	cout << "\n|                                                                 |";
	cout << "\n| 1.  Them sach                                                   |";
	cout << "\n| 2.  Tra sach cho nguoi dung                                     |";
	cout << "\n| 3.  Tim, chinh sua thong tin sach                               |";
	cout << "\n| 4.  Yeu cau cua doc gia                                         |";
	cout << "\n| 5.  Xem danh sach nguoi dung qua han tra sach                   |";
	cout << "\n| 6.  Doi mat khau                                                |";
	cout << "\n| 7.  Dang xuat                                                   |";
	cout << "\n|_________________________________________________________________|";
	cout << "\nHay chon chuc nang: ";
}
void in_menu_quan_li()
{
	cout << "\n _________________________________________________________________ ";
	cout << "\n|                   THU VIEN DAI HOC BACH KHOA                    |";
	cout << "\n|                       Quan li nguoi dung                        |";
	cout << "\n|_________________________________________________________________|";
	cout << "\n|                                                                 |";
	cout << "\n| 1.  Them nguoi dung                                             |";
	cout << "\n| 2.  Xem thong tin va chinh sua                                  |";
	cout << "\n| 3.  Xem nguoi dung qua han tra sach & khoa tai khoan            |";
	cout << "\n| 4.  Doi mat khau                                                |";
	cout << "\n| 5.  Dang xuat                                                   |";
	cout << "\n|_________________________________________________________________|";
	cout << "\nHay chon chuc nang: ";
}
void in_menu_user()
{
	cout << "\n _________________________________________________________________ ";
	cout << "\n|                   THU VIEN DAI HOC BACH KHOA                    |";
	cout << "\n|                            Doc gia                              |";
	cout << "\n|_________________________________________________________________|";
	cout << "\n|                                                                 |";
	cout << "\n| 1.  Tim sach va gui yeu cau muon sach                           |";
	cout << "\n| 2.  Xem thong bao tinh trang muon sach                          |";
	cout << "\n| 3.  Xem thong tin tai khoan                                     |";
	cout << "\n| 4.  Doi mat khau                                                |";
	cout << "\n| 5.  Dang xuat                                                   |";
	cout << "\n|_________________________________________________________________|";
	cout << "\nHay chon chuc nang: ";
}
void in_menu_dang_nhap()
{
	cout << "\n _________________________________________________________________ ";
	cout << "\n|                   THU VIEN DAI HOC BACH KHOA                    |";
	cout << "\n|                           DANG NHAP                             |";
	cout << "\n|_________________________________________________________________|";
	cout << "\n|                                                                 |";
	cout << "\n| Chon vai tro cua ban:                                           |";
	cout << "\n| 1.  Doc gia                                                     |";
	cout << "\n| 2.  Thu thu                                                     |";
	cout << "\n| 3.  Quan ly nguoi dung                                          |";
	cout << "\n| 4.  Thoat chuong trinh                                          |";
	cout << "\n|_________________________________________________________________|";
	cout << endl;
}
void in_doi_mat_khau()
{
	cout << "\n _________________________________________________________________ ";
	cout << "\n|                   THU VIEN DAI HOC BACH KHOA                    |";
	cout << "\n|                         Doi mat khau                            |";
	cout << "\n|_________________________________________________________________|";
	cout << "\n|                                                                 |";
	cout << "\n| 1. Doi mat khau                                                 |";
	cout << "\n| 2. Tro ve                                                       |";
	cout << "\n|_________________________________________________________________|";
	cout << "\nHay chon chuc nang: ";
}
void in_Cart_Main_Menu()
{
	cout << "\n _________________________________________________________________ ";
	cout << "\n|                   THU VIEN DAI HOC BACH KHOA                    |";
	cout << "\n|                 Tim sach va yeu cau muon sach                   |";
	cout << "\n|_________________________________________________________________|";
	cout << "\n|                                                                 |";
	cout << "\n| 1.  Tim sach                                                    |";
	cout << "\n| 2.  Kiem tra, chinh sua yeu cau muon sach                       |";
	cout << "\n| 3.  Tro ve menu truoc                                           |";
	cout << "\n|_________________________________________________________________|";
	cout << "\nHay chon chuc nang: ";
}
void in_danh_sach_muon_sach()
{
	fstream infile;
	string line;
	infile.open("danh_sach_muon_sach.txt", ios::in);
	getline(infile, line);
	getline(infile, line);
	cout << " " << setfill('_') << setw(116) << "" << setfill(' ') << endl;
	cout << "|" << left << setw(3) << "STT"
		<< "|" << left << setw(20) << "Account ID"
		<< "|" << left << setw(70) << "Ten sach"
		<< "|" << left << setw(20) << "Thoi gian muon" << "|" << endl;
	cout << setfill('_') << setw(4) << "|" << setw(21) << "|" << setw(71) << "|"
		<< setw(21) << "|" << "|" << setfill(' ') << endl;
	int stt = 0;
	while (!infile.eof())
	{
		getline(infile, line);
		
		if (line.length() > 0)
		{
			stt++;
			string AccId = line.substr(0, 20);
			string BookName = line.substr(20, 70);
			string BorrowTime = line.substr(90, 20);
			cout << "|" << left << setw(3) << stt
				<< "|" << left << setw(20) << AccId
				<< "|" << left << setw(70) << BookName
				<< "|" << left << setw(20) << BorrowTime << "|" << endl;
		}
	}
	cout << setfill('_') << setw(4) << "|" << setw(21) << "|" << setw(71) << "|"
		<< setw(21) << "|" << "|" << setfill(' ') << endl;
	infile.close();
}
void in_user_notification()
{
	cout << "\n _________________________________________________________________ ";
	cout << "\n|                   THU VIEN DAI HOC BACH KHOA                    |";
	cout << "\n|                         Xem thong bao                           |";
	cout << "\n|_________________________________________________________________|";
	cout << "\n|                                                                 |";
	cout << "\n| 1.  Xem sach da muon                                            |";
	cout << "\n| 2.  Xem sach da gui yeu cau                                     |";
	cout << "\n| 3.  Tro ve menu truoc                                           |";
	cout << "\n|_________________________________________________________________|";
	cout << "\nHay chon chuc nang: ";

}