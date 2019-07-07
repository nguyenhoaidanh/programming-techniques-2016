#include "cart.h"

void Cart_Main_Menu(string account_ID)
{
	vector<book> book_search; //Luu sach search
	vector<book> book_borrow; //Luu sach gio hang
	string choice;

	// Lua chon menu chinh
	bool exit_main_menu = false;

	while (exit_main_menu == false) //Meunu chinh
	{
		system("cls");
		in_Cart_Main_Menu();
		getline(cin, choice);

		//Chon menu tim sach
		if (choice == "1")
		{
			Cart_Search_Menu(book_search, book_borrow); //Search sach,su dung book_search luu ket qua search va borrow de lay ket qua vao gio hang
		} //End if menu tim sach
		else if (choice == "2")
		{
			Cart_Manage_Menu(book_borrow, book_search, account_ID); //Su dung borrow de xuat gio hang + mssv
		} //End menu gio hang
		else if (choice == "3")
		{
			Exit_Cart_Main_Menu(account_ID, book_borrow, exit_main_menu);
		}
		else
		{
			cout << "Khong xac dinh duoc lua chon,vui long nhap lai (nhan enter de tiep tuc)" << endl;
			cin.ignore();
		}
	} //End while menu chinh
}
void Exit_Cart_Main_Menu(string account_ID, vector<book> &book_borrow, bool &exit_main_menu)
{
	unsigned short choice;
	bool exit_exit_main_menu = false;

	enum Exit_main_menu
	{
		YES = 1,
		NO = 2
	};
	if (book_borrow.size() != 0)
	{
		while (exit_exit_main_menu == false)
		{
			cout << "Ban chua xac nhan gio hang,ban co muon thoat khong ?" << endl;
			cout << "1. CO" << endl;
			cout << "2. KHONG" << endl;
			cin >> choice;

			if (choice == YES)
			{
				cin.ignore();
				exit_exit_main_menu = true;
				exit_main_menu = true;
			}
			else if (choice == NO)
			{
				cin.ignore();
				exit_exit_main_menu = true;
			}
			else
			{
				cout << "Khong xac dinh duoc lua chon,vui long nhap lai (nhan enter de tiep tuc)" << endl;
				cin.ignore();
			}
		} //End while
	}//End if
	else
	{
		exit_main_menu = true;
	}
}
//void Read_Data(string account_ID, vector<book> &book_borrow)
//{
//	fstream infile;
//	infile.open("luu_gio_hang.txt", ios::in);
//	string line;
//	string student_ID_test;
//	string book_name;
//	while (!infile.eof())
//	{
//		getline(infile, line);
//		stringstream temp(line);
//		temp >> student_ID_test;
//		if (student_ID_test == account_ID) {
//
//		};
//
//	}
//
//}
//void Save_Data(string account_ID, vector<book> &book_borrow)
//{
//	fstream outfile;
//	outfile.open("luu_gio_hang.txt", ios::app);
//	for (size_t i = 0; i < book_borrow.size(); i++)
//	{
//		outfile << setw(20) << left << account_ID
//			<< setw(70) << left << book_borrow[i].name
//			<< setw(20) << left << xuat_thoi_gian() << endl;
//	}
//	outfile.close();
//	book_borrow.clear();
//}
void Cart_Search_Menu(vector<book> &book_search, vector<book> &book_borrow)
{
	string choice;
	unsigned ID;

	//Lua chon menu con
	bool exit_cart_search_menu = false;
	while (exit_cart_search_menu == false)
	{
		//Tien hanh tim sach
		system("cls");
		search_book(book_search);
		cout << endl;

		//Lua chon menu con trong menu tim sach
		cout << "Sach da duoc tim,xin vui long chon 1 trong cac lenh sau" << endl;
		cout << "1.  Xem thong tin sach" << endl;
		cout << "2.  Tim kiem lai" << endl;
		cout << "3.  Tro ve menu chinh" << endl;
		getline(cin, choice);

		//Chon xem thong tin sach
		if (choice == "1")
		{
			cout << "Nhap stt sach ban muon xem thong tin" << endl;
			//Lay ID sach
			while (true)
			{
				cin >> ID;
				if (ID <= book_search.size() && ID > 0) break;
				else //Neu nhap sai choice nhap lai toi khu dung
				{
					cout << "Khong xac nhan duoc stt sach,vui long nhap lai" << endl;
					continue;
				}
			} //End while nhap ID
			cin.ignore();
			bool exit_read_book = false;
			while (exit_read_book == false)
			{
				//Menu them sach vao gio hang
				/*Khuc nay se xuat thong tin sach*/
			//	cin.ignore();
				system("cls");
				cout << "THONG TIN SACH" << endl << endl;

				cout  << "Ten sach: ";
				display_string(book_search[ID - 1].name);
				for (int i = 0; i < 119; i++) cout << "_"; cout << endl << endl;
				cout << "Tac gia: ";
				display_string(book_search[ID - 1].author);
				for (int i = 0; i < 119; i++) cout << "_"; cout << endl << endl;

				cout << "Noi dung so luoc:" << endl;
				display_string(book_search[ID - 1].content);
				for (int i = 0; i < 119; i++) cout << "_"; cout << endl << endl;


				/*--------------------------------------------*/
				cout << "1.  Them sach vao danh sach yeu cau muon sach" << endl;
				cout << "2.  Tro ve menu truoc" << endl;
				getline(cin, choice);
				if (choice == "1")
				{
					book_borrow.push_back(book_search[ID - 1]);
					cout << "Da them thanh cong " << book_search[ID - 1].name << " vao danh sach yeu cau muon sach" << endl;
					system("pause");
					exit_read_book = true;
				}
				else if (choice == "2")
				{
					exit_read_book = true;
				}
				else
				{
					cout << "Khong xac dinh duoc lua chon, vui long nhap lai (nhan enter de tiep tuc)" << endl;
					system("pause");
				}
			} //End while Menu doc thong tin sach,chua menu gio hang
		} //End if menu doc thong tin sach

		else if (choice == "2")
		{
			book_search.clear();
		}
		else if (choice == "3")
		{
			book_search.clear();
			exit_cart_search_menu = true;
		}
		else
		{
			cout << "Khong xac dinh duoc lua chon, vui long nhap lai (nhan enter de tiep tuc)" << endl;
			system("pause");
		}
	} //End while menu tim sach,chua menu con tim sach
}
void Cart_Manage_Menu(vector<book> &book_borrow, vector<book> &book_search, string account_ID)
{
	string choice;
	bool exit_cart_manage_menu = false;
	while (exit_cart_manage_menu == false)
	{
		system("cls");
		// Neu khong co muon sach thi khong can xem gio hang
		if (book_borrow.size() == 0)
		{
			cout << "Danh sach yeu cau trong,nhan enter ra ngoai menu chinh" << endl;
			exit_cart_manage_menu = true;
			cin.ignore();
		}
		else
		{
			system("cls");
			cout << "DANH SACH YEU CAU" << endl << endl;
			print_book_in_cart(book_borrow); //Xuat sach da them vao gio hang
			cout << "1.  Gui danh sach yeu cau" << endl;
			cout << "2.  Chinh sua danh sach yeu cau" << endl;
			cout << "3.  Tro ve menu truoc" << endl;
			cout << "Xin moi lua chon: ";
			getline(cin, choice);

			if (choice == "1")
			{
				system("cls");
				cout << "Ban da gui yeu cau thanh cong,nhan enter de ra ngoai menu chinh" << endl;
				confirm_cart(book_borrow, account_ID); //Xuat sach ra file + mssv muon sach + clear gio hang
				exit_cart_manage_menu = true;
				system("pause");
			} // End menu xac nhan sach
			else if (choice == "2")
			{
				bool exit_edit_cart = false;
				while (exit_edit_cart == false)
				{
					system("cls");
					cout << "CHINH SUA DANH SACH" << endl << endl;
					print_book_in_cart(book_borrow);
					cout << "1.  Bo sung danh sach" << endl;
					cout << "2.  Xoa sach" << endl;
					cout << "3.  Tro ve menu truoc" << endl;
					cout << "Xin moi lua chon: ";
					getline(cin, choice);

					if (choice == "1")
					{
						Cart_Search_Menu(book_search, book_borrow);
					}
					else if (choice == "2")
					{
						erase_cart(book_borrow, exit_cart_manage_menu, exit_edit_cart);
					}
					else if (choice == "3")
						exit_edit_cart = true;
				}

			}
			else if (choice == "3")
			{
				exit_cart_manage_menu = true;
			}
			else
			{
				cout << "Khong xac dinh duoc lua chon,vui long nhap lai (nhan enter de tiep tuc)" << endl;
				cin.ignore();
			}
		} //End menu con gio hang
	} //End while chua menu con cua gio hang
}
void erase_cart(vector<book> &book_borrow, bool &exit_cart_manage_menu, bool &exit_edit_cart)
{
	string choice;
	unsigned int ID;
	bool exit_erase_book_borrow = false;
	while (exit_erase_book_borrow == false)
	{
		system("cls");
		cout << "XOA SACH TRONG DANH SACH" << endl << endl;
		print_book_in_cart(book_borrow);
		cout << "Nhap ID sach can xoa" << endl;
		cin >> ID;
		book_borrow.erase(book_borrow.begin() + ID - 1);

		if (book_borrow.size() == 0) //Neu khong con sach nua thi thoat 
		{
			system("cls");
			cout << "Danh sach cua ban da trong,nhan enter de tiep tuc" << endl;
			exit_erase_book_borrow = true;
			exit_edit_cart = true;
			exit_cart_manage_menu = true;
			system("pause");
		}
		else
		{
			//Co muon xoa tiep khong
			system("cls");
			print_book_in_cart(book_borrow);
			cout << "Ban co muon xoa tiep khong ? Y/N (Nhap y de xoa tiep,n de xac nhan gio hang)" << endl;
			while (true)
			{
				cin >> choice;
				if (choice == "y" || choice == "n") break;
				else //Neu nhap sai choice nhap lai toi khu dung
				{
					cout << "Khong xac nhan duoc lua chon,vui long nhap lai" << endl;
					continue;
				}
			} //End while nhap lua chon
			if (choice == "y") exit_erase_book_borrow = false;
			else exit_erase_book_borrow = true;
		}
	} //End while xoa don hang
}
void print_book_in_cart(vector<book> book_borrow)
{
	cout << " "; for (int i = 0; i < 118; i++) cout << "_"; cout << " " << endl;
	cout << setw(10) << left << "|ID"
		<< setw(70) << left << "|Ten sach"
		<< setw(39) << left << "|Tac gia" << "|" << endl;
	cout << setfill('_')
		<< setw(10) << "|" << setw(70) << "|" << setw(39) << "|" << "|"
		<< setfill(' ') << endl;
	for (size_t i = 0; i < book_borrow.size(); i++)
	{
		cout << "|" << setw(9) << left << i + 1
			<< "|" << setw(69) << left << book_borrow[i].name
			<< "|" << setw(38) << left << book_borrow[i].author
			<< "|" << endl;
	}
	cout << setfill('_')
		<< setw(10) << "|" << setw(70) << "|" << setw(39) << "|" << "|"
		<< setfill(' ') << endl;
}
void confirm_cart(vector<book> &book_borrow, string account_ID)
{
	fstream outfile;
	outfile.open("danh_sach_muon_sach_pending.txt", ios::app);
	for (size_t i = 0; i < book_borrow.size(); i++)
	{
		outfile << setw(20) << left << account_ID
			<< setw(70) << left << book_borrow[i].name
			<< setw(20) << left << xuat_thoi_gian() << "Pending" << endl;
	}
	outfile.close();
	book_borrow.clear();
}