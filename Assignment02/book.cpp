#include "book.h"

void Add_Book()
{
	string choice;
	book book_ex;

	bool exit_add_book = false;
	while (exit_add_book == false)
	{
		//Tien hanh nhap thong tin sach
		system("cls");
		cout << "THEM SACH" << endl << endl;

		cout << "Nhap ten sach: ";
		getline(cin, book_ex.name);
		if (book_ex.name.size() == 0)
		{
			cout << "Ten sach khong duoc bo trong" << endl;
			continue;
		}
		delete_space(book_ex.name);

		cout << "Nhap ten tac gia: ";
		getline(cin, book_ex.author);

		delete_space(book_ex.author);

		cout << "Nhap so luoc noi dung sach: ";
		getline(cin, book_ex.content);

		delete_space(book_ex.content);

		//Xac nhan lai va sua sach
		Edit_add_book(book_ex);

		bool exit_add_more_book = false;
		while (exit_add_more_book == false)
		{
			//Lua chon menu add sach
			system("cls");
			cout << "Sach da duoc them,chon cac lua chon sau " << endl;
			cout << "1.  Tiep tuc them sach" << endl;
			cout << "2.  Tro ve menu truoc" << endl;

			getline(cin, choice);

			if (choice == "1")
			{
				exit_add_book = false;
				exit_add_more_book = true;
			}
			else if (choice == "2")
			{
				exit_add_more_book = true;
				exit_add_book = true;
			}
			else
			{
				cout << "Khong xac nhan duoc lua chon,nhan enter de tiep tuc" << endl;
				system("cls");
			}
		}
	}
}
void Edit_add_book(book &book_ex)
{
	string choice;
	bool exit_confirm_add_book = false;
	while (exit_confirm_add_book == false)
	{

		system("cls");
		cout << "KIEM TRA VA XAC NHAN THONG TIN SACH" << endl << endl;

		cout << "Ten sach: ";
		display_string(book_ex.name);
		cout << setfill('_') << setw(119) << "" << endl << setfill(' ');

		cout << "Tac gia: ";
		display_string(book_ex.author);
		cout << setfill('_') << setw(119) << "" << endl << setfill(' ');

		cout << "Noi dung so luoc:" << endl;
		display_string(book_ex.content);
		cout << setfill('_') << setw(119) << "" << endl << setfill(' ');

		//Lua chon menu chinh sua lai thong tin sach
		cout << endl;
		cout << "Vui long kiem tra lai thong tin va xac nhan" << endl;
		cout << "1.  Hoan tat them sach" << endl;
		cout << "2.  Chinh sua lai thong tin" << endl;
		cout << "Xin moi lua chon: ";
		getline(cin, choice);

		if (choice == "1")
		{
			fstream outfile;
			outfile.open("sach.txt", ios::app);

			outfile << endl << setw(70) << left << book_ex.name
				<< setw(40) << left << book_ex.author
				<< book_ex.content;

			//Khong can thiet,nhung clear bo nho de khong phat sinh loi
			book_ex.name.clear();
			book_ex.author.clear();
			book_ex.content.clear();

			outfile.close();
			exit_confirm_add_book = true;
		}
		else if (choice == "2")
		{
			bool exit_edit_add_book = false;
			while (exit_edit_add_book == false)
			{
				system("cls");
				cout << "SUA THONG TIN SACH" << endl << endl;

				cout << "Ten sach: ";
				display_string(book_ex.name);

				cout << "Tac gia: ";
				display_string(book_ex.author);

				cout << setfill('_') << setw(119) << "" << endl << setfill(' ');
				cout << "Noi dung so luoc:" << endl;
				display_string(book_ex.content);
				cout << setfill('_') << setw(119) << "" << endl << setfill(' ');

				cout << "Chon muc can sua" << endl;
				cout << "1.  Ten sach" << endl;
				cout << "2.  Ten tac gia" << endl;
				cout << "3.  Noi dung sach" << endl;
				cout << "4.  Thoat" << endl;
				cout << "Xin moi lua chon :";
				getline(cin, choice);

				if (choice == "1") edit_string(book_ex.name);
				else if (choice == "2") edit_string(book_ex.author);
				else if (choice == "3") edit_string(book_ex.content);
				else if (choice == "4") exit_edit_add_book = true;
				else
				{
					cout << "Thong xac nhan duoc lua chon,nhan enter de tiep tuc" << endl;
					system("cls");
				}
			}
		}
		else
		{
			cout << "Thong xac nhan duoc lua chon,nhan enter de tiep tuc" << endl;
			system("cls");
		}
	}
}
void Erase_and_edit_book()
{
	vector<book> book_search;
	string choice;
	unsigned ID;

	//Lua chon menu con
	bool exit_cart_search_menu = false;
	while (exit_cart_search_menu == false)
	{
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

			bool exit_read_book = false;
			while (exit_read_book == false)
			{
				//Menu them sach vao gio hang
				/*Khuc nay se xuat thong tin sach*/
				cin.ignore();
				system("cls");
				cout << "KIEM TRA VA XAC NHAN THONG TIN SACH" << endl << endl;

				cout << "Ten sach: ";
				display_string(book_search[ID - 1].name);
				cout << setfill('_') << setw(119) << "" << endl << setfill(' ');

				cout << "Tac gia: ";
				display_string(book_search[ID - 1].author);
				cout << setfill('_') << setw(119) << "" << endl << setfill(' ');

				cout << "Noi dung so luoc:" << endl;
				display_string(book_search[ID - 1].content);
				cout << setfill('_') << setw(119) << "" << endl << setfill(' ');

				/*--------------------------------------------*/
				cout << "1.  Xoa sach" << endl;
				cout << "2.  Chinh sua sach" << endl;
				cout << "3.  Quay lai man hinh truoc" << endl;
				getline(cin, choice);
				if (choice == "1")
				{
					string line;
					string line_temp;
					fstream infile, outfile;
					infile.open("sach.txt", ios::in);
					outfile.open("sach_temp.txt", ios::out);

					while (!infile.eof())
					{
						getline(infile, line);
						line_temp = line.substr(0, 40);
						delete_space(line_temp);
						if (line_temp == book_search[ID - 1].name) continue;

						outfile << endl << line;
					}
					infile.close();
					outfile.close();

					infile.open("sach_temp.txt", ios::in);
					outfile.open("sach.txt", ios::out);

					getline(infile, line);

					getline(infile, line);
					outfile << line;
					while (getline(infile, line))
					{
						outfile << endl << line;			// copy noi dung 2 file
					}
					infile.close();
					outfile.close();
					cout << "Ban xoa thanh cong " << book_search[ID - 1].name << " trong thu vien" << endl;

					book_search.erase(book_search.begin() + ID - 1);
					system("pause");
					exit_read_book = true;
				}
				else if (choice == "2")
				{
					edit_book(book_search[ID - 1]);
				}
				else if (choice == "3")
				{
					system("cls");
					exit_read_book = true;
				}
				else
				{
					cout << "Khong xac dinh duoc lua chon,vui long nhap lai (nhan enter de tiep tuc)" << endl;
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
			cout << "Khong xac dinh duoc lua chon,vui long nhap lai (nhan enter de tiep tuc)" << endl;
			system("pause");
		}
	} //End while menu tim sach,chua menu con tim sach
}
void edit_book(book &book_ex)
{
	string choice;
	string book_name = book_ex.name;
	bool exit_confirm_add_book = false;
	while (exit_confirm_add_book == false)
	{
		system("cls");

		cout << "Ten sach: ";
		display_string(book_ex.name);
		cout << endl;

		cout << "Tac gia: ";
		display_string(book_ex.author);
		cout << endl;

		cout << "So luoc noi dung: " << endl;
		display_string(book_ex.content);
		cout << endl << endl;

		//Lua chon menu chinh sua lai thong tin sach
		cout << "Chon mot trong cac lua chon sau" << endl;
		cout << "1.  Chinh sua lai thong tin" << endl;
		cout << "2.  Hoan tat chinh sua" << endl;

		getline(cin, choice);


		if (choice == "1")
		{
			bool exit_edit_add_book = false;
			while (exit_edit_add_book == false)
			{
				system("cls");

				cout << "Ten sach: ";
				display_string(book_ex.name);
				cout << endl;

				cout << "Tac gia: ";
				display_string(book_ex.author);
				cout << endl;

				cout << "So luoc noi dung:" << endl;
				display_string(book_ex.content);
				cout << endl;

				cout << "Chon muc can sua" << endl;
				cout << "1.  Ten sach" << endl;
				cout << "2.  Ten tac gia" << endl;
				cout << "3.  Noi dung sach" << endl;
				cout << "4.  Thoat" << endl;
				cout << "Xin moi lua chon :";
				getline(cin, choice);

				if (choice == "1") edit_string(book_ex.name);
				else if (choice == "2") edit_string(book_ex.author);
				else if (choice == "3") edit_string(book_ex.content);
				else if (choice == "4") exit_edit_add_book = true;
				else
				{
					cout << "Thong xac nhan duoc lua chon,nhan enter de tiep tuc" << endl;
					system("cls");
				}
			}
		}
		else if (choice == "2")
		{
			string line;
			string line_temp;
			fstream infile, outfile;
			infile.open("sach.txt", ios::in);
			outfile.open("sach_temp.txt", ios::out);

			while (!infile.eof())
			{
				getline(infile, line);
				line_temp = line.substr(0, 40);
				delete_space(line_temp);

				if (line_temp == book_name)
				{
					outfile << endl << setw(70) << left << book_ex.name
						<< setw(40) << left << book_ex.author
						<< book_ex.content;
					continue;
				}

				outfile << endl << line;
			}
			infile.close();
			outfile.close();

			infile.open("sach_temp.txt", ios::in);
			outfile.open("sach.txt", ios::out);

			getline(infile, line);

			getline(infile, line);
			outfile << line;
			while (getline(infile, line))
			{
				outfile << endl << line;			// copy noi dung 2 file
			}
			infile.close();
			outfile.close();

			cout << "Sach da duoc sua" << endl;

			exit_confirm_add_book = true;
		}
		else
		{
			cout << "Thong xac nhan duoc lua chon,nhan enter de tiep tuc" << endl;
			system("cls");
		}
	}
}
void search_book(vector<book> &book_search)
{
	bool exit_search_book = false;
	while (exit_search_book == false)
	{
		//Neu chua search thi seach,neu da search roi thi hien thi lai ket qua search
		if (book_search.size() == 0)
		{
			//Search sach
			//Mo file
			string line;
			fstream infile;
			infile.open("sach.txt", ios::in);
			//Skip line 
			getline(infile, line);
			getline(infile, line);

			//Nhap ten sach can search
			string search;
			cout << "Nhap ten sach can tim (Nhan enter de hien len tat ca sach co trong thu vien)" << endl;
			getline(cin, search);
			delete_space(search);

			//Khai bao bien luu tru sach da search
			book x;

			//Hai gia tri dung de gan cho info_book_search
			string book_name;
			string book_author;
			string book_content;
			double ratio;
			//int length;
			//Tien hanh doc file
			while (!infile.eof())
			{
				getline(infile, line);

				book_name = line.substr(0, 70);
				delete_space(book_name);

				book_author = line.substr(70, 40);
				delete_space(book_author);

				book_content = line.substr(110, line.length() - 110);
				delete_space(book_content);

				//Yeu cau nhap dung khoang 28%
				ratio = double(LevenshteinDistance(book_name, search)) / book_name.length();
				if (ratio <= 0.72)
				{
					x.name = book_name;
					x.ratio_Levenshtein = ratio;
					x.author = book_author;
					x.content = book_content;
					book_search.push_back(x);
				}
				else
					continue;
			}
			infile.close();

			//Neu khong tim duoc thi thong bao kh tim duoc,neu tim duoc tien hanh sort theo ratio va xuat ket qua
			if (book_search.size() == 0)
			{
				system("cls");
				cout << "Khong co ket qua nao hop le" << endl;
				exit_search_book = false;
			}
			else
			{
				//Sort theo ratio
				sort(book_search);

				//Xuat ket qua tim duoc
				cout << " "; for (int i = 0; i < 118; i++) cout << "_"; cout << " " << endl;
				cout << setw(10) << left << "|ID"
					<< setw(70) << left << "|Ten sach"
					<< setw(39) << left << "|Tac gia" << "|" << endl;
				cout << setfill('_')
					<< setw(10) << "|" << setw(70) << "|" << setw(39) << "|" << "|"
					<< setfill(' ') << endl;
				for (size_t i = 0; i < book_search.size(); i++)
				{
					cout << "|" << setw(9) << left << i + 1
						<< "|" << setw(69) << left << book_search[i].name
						<< "|" << setw(38) << left << book_search[i].author
						<< "|" << endl;
				}
				cout << setfill('_')
					<< setw(10) << "|" << setw(70) << "|" << setw(39) << "|" << "|"
					<< setfill(' ') << endl;

				exit_search_book = true;
			}
		}
		//Ket thuc search sach

		else
		{
			//Hien thi sach
			cout << " "; for (int i = 0; i < 118; i++) cout << "_"; cout << " " << endl;
			cout << setw(10) << left << "|ID"
				<< setw(70) << left << " Ten sach"
				<< setw(39) << left << " Tac gia" << "|" << endl;
			cout << setfill('_')
				<< setw(10) << "|" << setw(70) << "|" << setw(39) << "|" << "|"
				<< setfill(' ') << endl;

			for (size_t i = 0; i < book_search.size(); i++)
			{
				cout << "|" << setw(9) << left << i + 1
					<< "|" << setw(69) << left << book_search[i].name
					<< "|" << setw(38) << left << book_search[i].author
					<< "|" << endl;
			}
			cout << setfill('_')
				<< setw(10) << "|" << setw(70) << "|" << setw(39) << "|" << "|"
				<< setfill(' ') << endl;
			exit_search_book = true;
		}
	}
}
int LevenshteinDistance(const string book_name, const string input_string)
{
	// Cac truong hop khong can xet
	if (book_name == input_string) return 0;
	if (input_string.length() == 0) return 0;

	// Khai bao 2 bien chua chieu dai cua string s1 va s2
	const size_t len1 = book_name.length(), len2 = input_string.length();

	//Tao 1 matrix co len1 hang va len 2 cot,su dung vector
	vector<vector<unsigned int>> matrix(len1 + 1, vector<unsigned int>(len2 + 1));

	matrix[0][0] = 0;
	//Danh so cac ki tu tham chieu
	for (size_t i = 1; i <= len1; ++i) matrix[i][0] = i;
	for (size_t i = 1; i <= len2; ++i) matrix[0][i] = i;

	//Tao ma tran so sanh ki tu
	int substitutionCost;
	for (size_t i = 1; i <= len1; ++i)
		for (size_t j = 1; j <= len2; ++j)
		{
			if (book_name[i - 1] == input_string[j - 1]
				|| book_name[i - 1] == char(int(input_string[j - 1]) - 32)
				|| book_name[i - 1] == char(int(input_string[j - 1]) + 32))
				substitutionCost = 0;
			else
				substitutionCost = 1;
			matrix[i][j] = min({ matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + substitutionCost });
		}

	//Tra ve khoang cach
	return matrix[len1][len2];
}
void sort(vector<book> &array)
{
	unsigned int cnt;
	for (size_t i = 0; i < array.size() - 1; ++i)
	{
		cnt = 0;
		for (size_t j = 0; j < array.size() - 1 - i; j++)
		{
			if (array[j].ratio_Levenshtein > array[j + 1].ratio_Levenshtein)
			{
				swap(array[j], array[j + 1]);
				++cnt;
			}
		}
		if (cnt == 0)
			break;
	}
}
void xoa_sach()
{
	system("cls");
	cout << "Xoa sach khoi he thong." << endl;
	string sach_can_xoa, ten, ten1, tac_gia, noi_dung, tac_gia1, noi_dung1;
	fstream infile, outfile;
	string line;
	int find = 0;
	//cin.ignore();
	cout << "Nhap ten sach can xoa: ";
	getline(cin, sach_can_xoa);
	while (find != 1)
	{
		infile.open("sach.txt", ios::in);
		getline(infile, line); //bo 2 dong
		getline(infile, line);
		while (!infile.eof())
		{
			getline(infile, line);
			ten = line.substr(0, 70);
			delete_space(ten);
			tac_gia = line.substr(70, 40);
			delete_space(tac_gia);
			noi_dung = line.substr(110, line.length() - 110);
			delete_space(noi_dung);
			if (sach_can_xoa == ten)
			{
				find = 1; cout << "Da tim thay sach:" << endl << "Ten sach: " << left << setw(70)
					<< ten << endl << "Tac gia:" << left << setw(40) << tac_gia << endl; break;
			}
		}
		infile.close();
		if (find != 1)
		{
			cout << "Khong tim thay sach, xin vui long nhap lai sach can xoa :";
			getline(cin, sach_can_xoa);
		}
	};
	string ch;
	cout << "Neu dung la sach ban can xoa, nhan yes ('y'), sau do 'enter' de xoa sach" << endl;

	getline(cin, ch);
	while (ch != "y"&&ch != "Y")
	{
		cout << "Nhap sai, xin hay nhan phim 'y' !!" << endl;
		getline(cin, ch);
	}

	infile.open("sach.txt", ios::in);
	outfile.open("temp.txt", ios::out);
	getline(infile, line); //bo 2 dong
	outfile << line;
	getline(infile, line);
	outfile << endl << line;
	while (!infile.eof())
	{
		getline(infile, line);
		ten1 = line.substr(0, 70);
		delete_space(ten1);
		tac_gia1 = line.substr(70, 40);
		delete_space(tac_gia1);
		noi_dung1 = line.substr(110, line.length() - 110);
		delete_space(noi_dung1);
		if (ten == ten1)
		{

		}
		else
		{
			outfile << endl << line;
		}
	}
	infile.close();
	outfile.close();
	/////////////copy file temp qua file goc
	infile.open("temp.txt", ios::in);
	outfile.open("sach.txt", ios::out);
	getline(infile, line); //bo 2 dong
	outfile << line;
	getline(infile, line);
	outfile << endl << line;
	while (!infile.eof())
	{
		getline(infile, line);
		outfile << endl << line;			// copy noi dung 2 file
	}
	outfile.close();
	infile.close();

	system("cls");
	cout << "Sach nay da duoc xoa thanh cong khoi he thong!!" << endl;
	////////////////////////////////////
	cout << "Ban co muon tiep tuc xoa:" << endl;
	cout << "1. Tiep tuc xoa." << endl;
	cout << "2. Tro ve menu chinh" << endl;
	cout << "Xin moi lua chon: ";
	//cin.ignore();
	string ch1;
	getline(cin, ch1);
	while (ch1 != "1" && ch1 != "2")
	{
		cout << "Nhap sai, xin nhap lai: ";
		getline(cin, ch1);
	}
	if (ch1 == "1")
	{
		system("cls");
		xoa_sach();
	}
	else if (ch1 == "2")
	{
		system("cls");
	}

}
void Search_Menu()
{
	vector<book> book_search;
	unsigned short choice;
	unsigned ID;
	enum SEARCH_BOOK_MENU
	{
		XEM_THONG_TIN_SACH = 1,
		TIM_KIEM_LAI = 2,
		THOAT = 3,

		QUAY_LAI = 1

	};
	//Lua chon menu con
	bool exit_cart_search_menu = false;
	while (exit_cart_search_menu == false)
	{
		//Tien hanh tim sach
		system("cls");
		search_book(book_search);

		//Lua chon menu con trong menu tim sach
		cout << endl << endl << "Sach da duoc tim,xin vui long chon 1 trong cac lenh sau" << endl;
		cout << "1.  Xem thong tin sach" << endl;
		cout << "2.  Tim kiem lai" << endl;
		cout << "3.  Tro ve menu chinh" << endl;
		cout << "Xin moi lua chon: ";
		cin >> choice;

		//Chon xem thong tin sach
		if (choice == XEM_THONG_TIN_SACH)
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

			bool exit_read_book = false;
			while (exit_read_book == false)
			{
				//Menu them sach vao gio hang
				/*Khuc nay se xuat thong tin sach*/
				system("cls");
				cout << "Ten sach: ";
				display_string(book_search[ID - 1].name);
				cout << "Tac gia: ";
				display_string(book_search[ID - 1].author);
				cout << "Noi dung so luoc: " << endl;
				display_string(book_search[ID - 1].content);
				/*--------------------------------------------*/
				cout << "1.  Quay lai man hinh truoc" << endl;
				cin >> choice;
				if (choice == QUAY_LAI)
				{
					exit_read_book = true;
				}
				else
				{
					cout << "Khong xac dinh duoc lua chon,vui long nhap lai (nhan enter de tiep tuc)" << endl;
					system("pause");
				}
			} //End while Menu doc thong tin sach,chua menu gio hang
		} //End if menu doc thong tin sach

		else if (choice == TIM_KIEM_LAI)
		{
			book_search.clear();
		}
		else if (choice == THOAT)
		{
			book_search.clear();
			exit_cart_search_menu = true;
		}
		else
		{
			cout << "Khong xac dinh duoc lua chon,vui long nhap lai (nhan enter de tiep tuc)" << endl;
			system("pause");
		}
	} //End while menu tim sach,chua menu con tim sach
}
void check_book()
{
	string choice;
	string line;
	unsigned int ID;
	vector<string> pending;

	fstream infile, outfile;
	infile.open("danh_sach_muon_sach_pending.txt", ios::in);
	while (getline(infile, line))
	{
		if (line.length() > 110)
		{
			if (line.substr(110, line.length() - 120) == "Pending")
				pending.push_back(line);
		}
	}
	infile.close();

	bool exit_check_book = false;
	while (exit_check_book == false)
	{
		system("cls");
		cout << "CHECK DANH SACH YEU CAU" << endl;
		if (pending.size() == 0)
		{
			cout << endl << "Khong co yeu cau muon sach hien tai" << endl;
			exit_check_book = true;
			cin.ignore();
		}
		else
		{
			cout << " " << setfill('_') << setw(137) << "" << setfill(' ') << endl;
			cout << "|" << left << setw(3) << "STT"
				<< "|" << left << setw(20) << "Account ID"
				<< "|" << left << setw(70) << "Ten sach"
				<< "|" << left << setw(20) << "Thoi gian"
				<< "|" << left << setw(20) << "Tinh trang" << "|" << endl;
			cout << setfill('_') << setw(4) << "|" << setw(21) << "|" << setw(71) << "|"
				<< setw(21) << "|" << setw(21) << "|" << "|" << endl << setfill(' ');

			for (size_t i = 0; i < pending.size(); i++)
			{
				string accountid, bookname, time, status;
				accountid = pending[i].substr(0, 20); delete_space(accountid);
				bookname = pending[i].substr(20, 70); delete_space(bookname);
				time = pending[i].substr(90, 20); delete_space(time);
				status = pending[i].substr(110); delete_space(status);

				cout << "|" << left << setw(3) << i + 1
					<< "|" << left << setw(20) << accountid
					<< "|" << left << setw(70) << bookname
					<< "|" << left << setw(20) << time
					<< "|" << left << setw(20) << status << "|" << endl;
			}
			cout << setfill('_') << setw(4) << "|" << setw(21) << "|" << setw(71) << "|"
				<< setw(21) << "|" << setw(21) << "|" << "|" << endl << setfill(' ');

			cout << "1.  Chon ID" << endl;
			cout << "2.  Tro ve menu truoc" << endl;
			cout << "Xin moi lua chon: ";
			getline(cin, choice);
			if (choice == "1")
			{
				cout << "Nhap ID: ";
				cin >> ID;
				bool exit_edit_check_book = false;
				while (exit_edit_check_book == false)
				{
					cout << "1.  Chap nhan" << endl;
					cout << "2.  Tu choi" << endl;
					cout << "3.  Quay lai" << endl;
					cin.ignore();
					getline(cin, choice);
					if (choice == "1")
					{
						outfile.open("danh_sach_muon_sach.txt", ios::app);
						outfile << setw(90) << left << pending[ID - 1].substr(0, 90)
							<< setw(20) << left << xuat_thoi_gian() << endl;
						outfile.close();

						outfile.open("danh_sach_muon_sach_pending.txt", ios::out);
						for (size_t i = 0; i < pending.size(); i++)
						{
							if (i == ID - 1) continue;
							else
								outfile << pending[i] << endl;
						}
						outfile.close();
						pending.erase(pending.begin() + ID - 1);
						exit_edit_check_book = true;
					}
					else if (choice == "2")
					{
						outfile.open("danh_sach_muon_sach_pending.txt", ios::out);
						for (size_t i = 0; i < pending.size(); i++)
						{
							if (i == ID - 1)
							{
								outfile << setw(110) << left << pending[i].substr(0, 110) << "Fail" << endl;
							}
							else
								outfile << pending[i] << endl;
						}
						outfile.close();
						pending.erase(pending.begin() + ID - 1);
						exit_edit_check_book = true;
					}
					else if (choice == "3")
					{
						exit_edit_check_book = true;
					}
					else
					{
						cout << "Khong xac dinh duoc lua chon,vui long nhap lai (nhan enter de tiep tuc)" << endl;
						system("pause");
					}
				}
			}
			else if (choice == "2")
			{
				exit_check_book = true;
			}
			else
			{
				cout << "Khong xac dinh duoc lua chon,vui long nhap lai (nhan enter de tiep tuc)" << endl;
				system("pause");
			}
		}
	}
}
