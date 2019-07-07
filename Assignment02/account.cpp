#include "account.h"

void set_account_ID(string &account_ID)
{
	account_ID.clear();
	bool exit_set_account_ID = false;
	int t = 0;
	while (exit_set_account_ID == false)
	{
		getline(cin, account_ID);
		fstream infile;
		string line, ID;
		int MS;
		infile.open("account.txt", ios::in);
		getline(infile, line);
		getline(infile, line);
		while (!infile.eof())
		{
			getline(infile, line);
			stringstream line1(line);
			line1 >> MS >> ID;
			if (account_ID == ID)
			{
				cout << "Ten tai khoan da co nguoi su dung roi, xin moi nhap lai: " << endl;
				t = 1;
				break;
			}
			else t = 0;
		}
		infile.close();
		if (t == 1)continue;
		else
		{
			if (account_ID.length() < 6 || account_ID.length() > 20)
			{
				system("cls");
				cout << "ID can co so ki tu nam trong khoand tu 6 den 20 ki tu, vui long nhap lai" << endl;
			}
			else
			{
				exit_set_account_ID = true;
				for (size_t i = 0; i < account_ID.length(); i++)
				{
					if (account_ID[i] == ' ')
					{
						system("cls");
						cout << "Tai khoan khong duoc chua dau cach, vui long nhap lai" << endl;
						exit_set_account_ID = false;
						break;
					}
				} //End for check dau cach
			} //End else
		}
	} //End while set account_ID
}
void set_account_Password(string &account_Password)
{
	account_Password.clear();
	char ch;
	ch = _getch();
	while (ch != 13) //Nhan enter de ket thuc
	{
		if (ch == 8) //Khi nhan nut backspace
		{
			if (account_Password.length() > 0) //Neu length > 0 thi moi xoa
			{
				cout << '\b'; //Xoa ki tu trong console
				cout << ' '; //Thay the ki tu do bang space
				cout << '\b'; //Xoa space vua moi them vao
				account_Password.erase(account_Password.length() - 1, 1); //Xoa ki tu luu trong string
			}
		}
		else
		{
			account_Password.push_back(ch); // Them char vao string password
			cout << '*'; //Hien thi dau *
		}

		ch = _getch();
	} //End while
}
void Set_Account(Account &acc, User user) //Set ID
{
	fstream outfile;
	outfile.open("account.txt", ios::app);
	acc.student_ID = user.student_ID;
	//Nhap ten tai khoan
	cout << "Nhap tai khoan: ";
	set_account_ID(acc.account_ID);

	//Nhap mat khau
	cout << "Nhap mat khau: ";
	set_account_Password(acc.account_Password);
	cout << endl;

	//Nhap lai mat khau
	string account_Password_test; //Kiem tra lai mat khau bang cach nhap lai
	string choice; //Dung de lua chon nhap lai pass hay nhap lai pass test
	while (true)
	{
		cout << "Xac nhan lai mat khau: ";
		set_account_Password(account_Password_test);
		cout << endl;
		if (account_Password_test == acc.account_Password)
			break;
		else //Neu mat khau xac nhan khac mat khau
		{
			cout << "Mat khau xac nhan khong trung khop,hay xem xet lua chon ben duoi" << endl;
			cout << "Yes:Nhap lai mat khau xac nhan" << endl
				<< "No:Nhap lai mat khau" << endl
				<< "Nhap y de xac nhan Yes,n de xac nhan la No" << endl;
			//Nhap lua chon
			while (true)
			{
				cin >> choice;
				if (choice == "y" || choice == "n")
					break;
				else //Neu nhap sai choice nhap lai toi khu dung
				{
					cout << "Khong xac nhan duoc lua chon,vui long nhap lai" << endl;
					continue;
				}
			} //End while nhap lua chon

			  //Thuc hien chuc nang tu lua chon
			if (choice == "y")
				continue; //Tiep tuc nhap mat khau xac nhan
			else
			{
				cout << "Nhap mat khau: ";
				set_account_Password(acc.account_Password); //Nhap lai mat khau
				cout << endl;
				continue; //Nhap mat khau xac nhan
			}

		} //End else
	} //End while xac nhan mat khau

	outfile << left << setw(10) << user.student_ID << left << setw(30) << acc.account_ID << left << setw(30) << acc.account_Password <<
		left << setw(15) << "user" << left << setw(15) << "activated" << endl;
	outfile.close();
}
void Set_User(User &user)
{
	fstream outfile;
	cout << "THEM NGUOI DUNG" << endl << endl;
	outfile.open("user.txt", ios::app);
	cout << "Nhap ho va ten: ";
	set_user_name(user.user_name);

	cout << "Nhap mssv: ";
	set_user_student_ID(user.student_ID);

	cout << "Nhap cong viec cua ban: ";
	set_user_job(user.user_job);
	set_user_email(user.user_mail);
	set_user_ngay_sinh(user.user_date_of_birth);

	string choice;
	bool edit_set_user = false;
	while (edit_set_user == false)
	{
		system("cls");
		cout << "THONG TIN CA NHAN" << endl << endl;
		cout << " " << setfill('_') << setw(95) << "" << endl << setfill(' ');
		cout << "|" << left << setw(10) << "MSSV"
			<< "|" << left << setw(25) << "Ten nguoi dung"
			<< "|" << left << setw(10) << "Ngay sinh"
			<< "|" << left << setw(15) << "Cong viec"
			<< "|" << left << setw(30) << "Email" << "|" << endl;
		cout << setfill('_')
			<< setw(11) << "|" << setw(26) << "|" << setw(11)
			<< "|" << setw(16) << "|" << setw(31) << "|" << "|" << endl
			<< setfill(' ');

		cout << "|" << left << setw(10) << user.student_ID
			<< "|" << left << setw(25) << RE_dinh_dang_chuoi(user.user_name)
			<< "|" << left << setw(10) << user.user_date_of_birth
			<< "|" << left << setw(15) << RE_dinh_dang_chuoi(user.user_job)
			<< "|" << left << setw(30) << user.user_mail
			<< "|" << endl;
		cout << setfill('_')
			<< setw(11) << "|" << setw(26) << "|" << setw(11)
			<< "|" << setw(16) << "|" << setw(31) << "|" << "|" << endl
			<< setfill(' ');


		cout << "Xem lai thong tin,chinh sua" << endl;
		cout << "1.  Xac nhan thong tin" << endl;
		cout << "2.  Chinh sua ho va ten" << endl;
		cout << "3.  Chinh sua mssv" << endl;
		cout << "4.  Chinh sua cong viec" << endl;
		cout << "5.  Chinh sua email" << endl;
		cout << "6.  Chinh sua ngay sinh" << endl;
		getline(cin, choice);
		if (choice == "1")
		{
			edit_set_user = true;
		}
		else if (choice == "2")
		{
			cout << "Nhap ho va ten: ";
			set_user_name(user.user_name);
		}
		else if (choice == "3")
		{
			cout << "Nhap mssv: ";
			set_user_student_ID(user.student_ID);
		}
		else if (choice == "4")
		{
			cout << "Nhap cong viec cua ban: ";
			set_user_job(user.user_job);
		}
		else if (choice == "5")
		{
			set_user_email(user.user_mail);
		}
		else if (choice == "6")
		{
			set_user_ngay_sinh(user.user_date_of_birth);
		}
		else
		{
			cout << "Khong xac nhan duoc lua chon,nhan enter de tiep tuc" << endl;
			system("pause");
		}
	}
	outfile << left << setw(10) << user.student_ID << left << setw(30) << dinh_dang_chuoi(user.user_name) << left
		<< setw(20) << user.user_date_of_birth << left << setw(30) << dinh_dang_chuoi(user.user_job) << left << setw(40)
		<< user.user_mail << endl;
	outfile.close();


}

void khoa_tai_khoan(Account account, User user)
{

	fstream infile, outfile;
	string line;
	infile.open("account.txt", ios::in);
	outfile.open("temp.txt", ios::out);
	getline(infile, line);
	outfile << line << endl;
	getline(infile, line);
	outfile << line << endl;
	while (!infile.eof())
	{
		int find = 0;
		getline(infile, line);
		stringstream line1(line);
		line1 >> account.student_ID >> account.account_ID >> account.account_Password
			>> account.role >> account.account_ative;
		user.student_ID = account.student_ID;
		for (int i = 0; i < dem_list_ID_block; i++)
		{
			if (account.account_ID == list_ID_block[i])
			{
				outfile << left << setw(10) << user.student_ID << left << setw(30) << account.account_ID <<
					left << setw(30) << account.account_Password <<
					left << setw(15) << account.role << left << setw(15) << "blocked" << endl;
				find = 1;
				break;
			}
		}

		if (find != 1)outfile << line << endl;


	}
	infile.close();
	outfile.close();


	infile.open("temp.txt", ios::in);
	outfile.open("account.txt", ios::out);
	while (getline(infile, line))
	{
		outfile << line << endl;			// copy noi dung 2 file
	}
	infile.close();
	outfile.close();
	cin.ignore();
	cout << "Cac tai khoan nay se bi khoa vi tra sach tre han!!" << endl;
	cout << "1. Tro ve menu chinh." << endl;
	cout << "Xin moi lua chon: ";
	string chon;
	getline(cin, chon);
	while (chon != "1")
	{
		cout << "Nhap sai, xin moi nhap lai!!" << endl;
		getline(cin, chon);
	}

}
void mo_khoa_tai_khoan(Account account, User user)
{
	string ID_can_unlock;
	fstream infile, outfile;
	string line;
	ID_can_unlock = ID_temp;
	infile.open("account.txt", ios::in);
	outfile.open("temp.txt", ios::out);
	getline(infile, line);
	outfile << line << endl;
	getline(infile, line);
	outfile << line << endl;
	while (!infile.eof())
	{

		getline(infile, line);
		stringstream line1(line);
		line1 >> account.student_ID >> account.account_ID >> account.account_Password
			>> account.role >> account.account_ative;
		user.student_ID = account.student_ID;


		if (account.account_ID == ID_can_unlock)
		{
			outfile << left << setw(10) << user.student_ID << left << setw(30) << account.account_ID <<
				left << setw(30) << account.account_Password <<
				left << setw(15) << account.role << left << setw(9) << "activated" << endl;


		}
		else outfile << line << endl;


	}
	infile.close();
	outfile.close();



	infile.open("temp.txt", ios::in);
	outfile.open("account.txt", ios::out);
	while (getline(infile, line))
	{
		outfile << line << endl;			// copy noi dung 2 file
	}
	infile.close();
	outfile.close();



}
void tim_kiem_thong_tin_user(Account account, User user)
{
	string ID_can_tim_thong_tin;
	fstream infile, infile1;
	string line, line1;
	int find = 0;
	cin.ignore();
	do {
		cout << "Nhap ten tai khoan can tim kiem thong tin: ";

		getline(cin, ID_can_tim_thong_tin);
		ID_temp = ID_can_tim_thong_tin;
		infile.open("account.txt", ios::in);
		infile1.open("user.txt", ios::in);
		getline(infile, line); //bo 2 dong
		getline(infile, line);
		getline(infile1, line1); //bo 2 dong
		getline(infile1, line1);
		while (!infile.eof() && !infile1.eof())
		{
			getline(infile, line);
			stringstream temp(line);
			temp >> account.student_ID >> account.account_ID >> account.account_Password
				>> account.role >> account.account_ative;
			user.student_ID = account.student_ID;

			getline(infile1, line1);
			stringstream temp1(line1);
			temp1 >> user.student_ID >> user.user_name >> user.user_date_of_birth >> user.user_job >> user.user_mail;

			if (account.account_ID == ID_can_tim_thong_tin)
			{
				system("cls");
				cout << "Thong tin nguoi dung: " << endl;
				cout << " " << setfill('_') << setw(131) << "" << endl << setfill(' ');
				cout << "|" << left << setw(10) << "MSSV"
					<< "|" << left << setw(25) << "Ten nguoi dung"
					<< "|" << left << setw(10) << "Ngay sinh"
					<< "|" << left << setw(20) << "Cong viec"
					<< "|" << left << setw(30) << "Email"
					<< "|" << left << setw(20) << "Ten tai khoan"
					<< "|" << left << setw(10) << "Trang thai" << "|" << endl;
				cout << setfill('_') << setw(11) << "|" << setw(26) << "|" << setw(11) << "|"
					<< setw(21) << "|" << setw(31) << "|" << setw(21) << "|" << setw(11) << "|" << "|" << endl << setfill(' ');
				cout << "|" << left << setw(10) << user.student_ID
					<< "|" << left << setw(25) << user.user_name
					<< "|" << left << setw(10) << user.user_date_of_birth
					<< "|" << left << setw(20) << user.user_job
					<< "|" << left << setw(30) << user.user_mail
					<< "|" << left << setw(20) << account.account_ID
					<< "|" << left << setw(10) << account.account_ative << "|" << endl;
				cout << setfill('_') << setw(11) << "|" << setw(26) << "|" << setw(11) << "|"
					<< setw(21) << "|" << setw(31) << "|" << setw(21) << "|" << setw(11) << "|" << "|" << endl << setfill(' ');
				find = 1; break;
			}

		}
		infile.close();
		infile1.close();
		if (find != 1)cout << "Khong tim thay tai khoan, ban da nhap sai xin moi nhap lai!!" << endl;
	} while (find != 1);

}
void xoa_tai_khoan(Account account, User user)
{
	string ID_can_xoa;
	fstream infile, infile1, outfile, outfile1;
	string line, line1;

	ID_can_xoa = ID_temp;
	infile.open("account.txt", ios::in);
	infile1.open("user.txt", ios::in);
	outfile.open("temp.txt", ios::out);
	outfile1.open("temp1.txt", ios::out);
	getline(infile, line); //bo 2 dong
	outfile << line << endl;
	getline(infile, line);
	outfile << line << endl;
	getline(infile1, line1); //bo 2 dong
	outfile1 << line1 << endl;
	getline(infile1, line1);
	outfile1 << line1 << endl;
	while (!infile.eof() && !infile1.eof())
	{

		getline(infile, line);
		stringstream temp(line);
		temp >> account.student_ID >> account.account_ID >> account.account_Password
			>> account.role >> account.account_ative;
		user.student_ID = account.student_ID;

		getline(infile1, line1);
		if (account.account_ID == ID_can_xoa)
		{

		}
		else
		{
			outfile << line << endl;
			outfile1 << line1 << endl;
		}
	}
	infile.close();
	infile1.close();
	outfile.close();
	outfile1.close();


	/////////////copy file temp qua file goc
	infile.open("temp.txt", ios::in);
	outfile.open("account.txt", ios::out);
	while (getline(infile, line))
	{
		outfile << line << endl;			// copy noi dung 2 file
	}
	infile.close();
	outfile.close();
	//
	infile1.open("temp1.txt", ios::in);
	outfile1.open("user.txt", ios::out);
	while (getline(infile1, line1))
	{
		outfile1 << line1 << endl;			// copy noi dung 2 file
	}
	infile1.close();
	outfile1.close();
}
void edit_account(Account account, User user)
{

	system("cls");
	cout << "Tim kiem nguoi dung" << endl;
	tim_kiem_thong_tin_user(account, user);
	cout << "1. Xoa tai khoan nay khoi he thong." << endl;
	cout << "2. Mo khoa tai khoan nay neu bi khoa." << endl;
	cout << "3. Tro ve menu chinh." << endl;
	cout << "Xin moi lua chon: ";
	string chon;
	bool chon_sai = true;
	string chuc_nang;
	do {
		cin >> chuc_nang;
		switch (chuc_nang[0] - '0')
		{
		case 1:
			xoa_tai_khoan(account, user);
			system("cls");
			cout << "XOA TAI KHOAN KHOI HE THONG THANH CONG!!!" << endl << endl;
			cout << "1. Tro ve menu chinh." << endl;
			cout << "Xin moi lua chon: ";
			cin.ignore();
			getline(cin, chon);
			while (chon != "1")
			{
				cout << "Nhap sai, xin nhap lai!!" << endl;
				getline(cin, chon);
			}
			if (chon == "1")
			{
				system("cls");
				in_menu_quan_li();
				chon_menu_quan_li(account, user);
			}
			chon_sai = false;
			break;
		case 2:
			mo_khoa_tai_khoan(account, user);
			system("cls");
			cout << "MO KHOA TAI KHOAN THANH CONG!!!" << endl << endl;

			cout << "1. Tro ve menu chinh." << endl;
			cout << "Xin moi lua chon: ";
			cin.ignore();
			getline(cin, chon);
			while (chon != "1")
			{
				cout << "Nhap sai, xin nhap lai!!" << endl;
				getline(cin, chon);
			}
			if (chon == "1")
			{
				system("cls");
				in_menu_quan_li();
				chon_menu_quan_li(account, user);
			}
			chon_sai = false;
			break;
		case 3:
			system("cls");
			in_menu_quan_li();
			chon_menu_quan_li(account, user);
			chon_sai = false;
			break;
		default:
			chon_sai = true;
			cout << "Xin moi nhap lai!!!!" << endl;

		}
	} while (chon_sai);
}

/*******************DOI MAT KHAU********************/
void doi_mat_khau_user(Account &account, User user)
{
	system("cls");
	in_doi_mat_khau();
	string c;
	getline(cin, c);
	while (c != "1" && c != "2")
	{
		cout << "Xin moi nhap lai: ";
		getline(cin, c);
	}
	if (c == "2")
	{
		system("cls");
		in_menu_user(); cin.clear();
		chon_menu_user(account, user);
	}
	else
	{
		fstream infile, outfile;
		string line;
		bool dang_nhap = false;

		while (!dang_nhap)
		{

			string newPASS;
			cout << "Nhap mat khau cu: ";
			set_account_Password(pass_da_dang_nhap);
			infile.open("account.txt", ios::in);
			outfile.open("temp.txt", ios::out);
			getline(infile, line);
			outfile << line << endl;
			getline(infile, line);
			outfile << line << endl;
			while (!infile.eof())
			{

				getline(infile, line);
				stringstream line1(line);
				line1 >> account.student_ID >> account.account_ID >> account.account_Password
					>> account.role >> account.account_ative;
				user.student_ID = account.student_ID;
				if ((id_da_dang_nhap == account.account_ID) && (pass_da_dang_nhap == account.account_Password))
				{
					dang_nhap = true;

					if (dang_nhap == true)
					{
						cout << endl << "Xin moi nhap mat khau moi: ";
						set_account_Password(newPASS);
						string account_Password_test; //Kiem tra lai mat khau bang cach nhap lai
						string choice; //Dung de lua chon nhap lai pass hay nhap lai pass test
						while (true)
						{
							cout << endl << "Xac nhan lai mat khau: ";
							set_account_Password(account_Password_test);
							cout << endl;
							if (account_Password_test == newPASS)
								break;
							else //Neu mat khau xac nhan khac mat khau
							{
								cout << "Mat khau xac nhan khong trung khop,hay xem xet lua chon ben duoi" << endl;
								cout << "Yes:Nhap lai mat khau xac nhan" << endl
									<< "No:Nhap lai mat khau" << endl
									<< "Nhap y de xac nhan Yes,n de xac nhan la No" << endl;
								//Nhap lua chon
								while (true)
								{
									cin >> choice;
									if (choice == "y" || choice == "n")
										break;
									else //Neu nhap sai choice nhap lai toi khu dung
									{
										cout << "Khong xac nhan duoc lua chon,vui long nhap lai" << endl;
										continue;
									}
								} //End while nhap lua chon

								  //Thuc hien chuc nang tu lua chon
								if (choice == "y")
									continue; //Tiep tuc nhap mat khau xac nhan
								else
								{
									cout << "Nhap mat khau: ";
									set_account_Password(newPASS); //Nhap lai mat khau
									cout << endl;
									continue; //Nhap mat khau xac nhan
								}

							} //End else
						} //End while xac nhan mat khau

						outfile << left << setw(10) << user.student_ID << left << setw(30) << account.account_ID <<
							left << setw(30) << newPASS <<
							left << setw(15) << account.role << left << setw(9) << account.account_ative << endl;
						pass_da_dang_nhap = newPASS;
					}
				}
				else
				{
					outfile << line << endl;
				}
			}
			infile.close();
			outfile.close();

			infile.open("temp.txt", ios::in);
			outfile.open("account.txt", ios::out);
			while (getline(infile, line))
			{
				outfile << line << endl;			// copy noi dung 2 file
			}
			infile.close();
			outfile.close();
			if (dang_nhap != true)
			{
				cout << endl;
				cout << "Ten tai khoan/mat khau khong dung!! Xin moi nhap lai!!" << endl;
			}
			else
			{
				cout << endl << "DOI MAT KHAU THANH CONG!!!!" << endl;
				cin.ignore();
				system("cls");
				in_menu_user(); cin.clear();
				chon_menu_user(account, user);
			}
		}
	}
}
void doi_mat_khau_thu_thu(Account &account, User user)
{
	system("cls");
	in_doi_mat_khau();
	string c;
	getline(cin,c);
	while( c!= "1" && c!="2" )
	{
		cout<<"Xin moi nhap lai: ";
		getline(cin,c);
	}
	if(c=="2")
	{
	system("cls");
	in_menu_thu_thu();
	chon_menu_thu_thu(account,user);
	}
	else
	{fstream infile, outfile;
	string line;
	bool dang_nhap = false;

	while (!dang_nhap)
	{

		string newPASS;
		cout << "Nhap mat khau cu: ";
		set_account_Password(pass_da_dang_nhap);
		infile.open("account_thu_thu.txt", ios::in);
		outfile.open("temp.txt", ios::out);
		getline(infile, line);
		outfile << line << endl;
		getline(infile, line);
		outfile << line << endl;
		while (!infile.eof())
		{

			getline(infile, line);
			stringstream line1(line);
			line1 >> account.student_ID >> account.account_ID >> account.account_Password
				>> account.role >> account.account_ative;
			user.student_ID = account.student_ID;
			if ((id_da_dang_nhap == account.account_ID) && (pass_da_dang_nhap == account.account_Password))
			{
				dang_nhap = true;

				if (dang_nhap == true)
				{
					cout << endl << "Xin moi nhap mat khau moi: ";
					set_account_Password(newPASS);
					string account_Password_test; //Kiem tra lai mat khau bang cach nhap lai
					string choice; //Dung de lua chon nhap lai pass hay nhap lai pass test
					while (true)
					{
						cout << endl << "Xac nhan lai mat khau: ";
						set_account_Password(account_Password_test);
						cout << endl;
						if (account_Password_test == newPASS)
							break;
						else //Neu mat khau xac nhan khac mat khau
						{
							cout << "Mat khau xac nhan khong trung khop,hay xem xet lua chon ben duoi" << endl;
							cout << "Yes:Nhap lai mat khau xac nhan" << endl
								<< "No:Nhap lai mat khau" << endl
								<< "Nhap y de xac nhan Yes,n de xac nhan la No" << endl;
							//Nhap lua chon
							while (true)
							{
								cin >> choice;
								if (choice == "y" || choice == "n")
									break;
								else //Neu nhap sai choice nhap lai toi khu dung
								{
									cout << "Khong xac nhan duoc lua chon,vui long nhap lai" << endl;
									continue;
								}
							} //End while nhap lua chon

							  //Thuc hien chuc nang tu lua chon
							if (choice == "y")
								continue; //Tiep tuc nhap mat khau xac nhan
							else
							{
								cout << "Nhap mat khau: ";
								set_account_Password(newPASS); //Nhap lai mat khau
								cout << endl;
								continue; //Nhap mat khau xac nhan
							}

						} //End else
					} //End while xac nhan mat khau

					outfile << left << setw(10) << user.student_ID << left << setw(30) << account.account_ID <<
						left << setw(30) << newPASS <<
						left << setw(15) << account.role << left << setw(9) << account.account_ative << endl;
					pass_da_dang_nhap = newPASS;
				}
			}
			else
			{
				outfile << line << endl;
			}
		}
		infile.close();
		outfile.close();
		///////////////////////////////
		outfile.open("account_thu_thu.txt", ios::out);
		infile.open("temp.txt", ios::in);

		while (getline(infile, line))
		{
			outfile << line << endl;				// copy noi dung 2 file
		}
		infile.close();
		outfile.close();
		if (dang_nhap != true)
		{
			cout << endl;
			cout << "Ten tai khoan/mat khau khong dung!! Xin moi nhap lai!!" << endl;

		}
		else
		{
			cout << endl << "DOI MAT KHAU THANH CONG!!!!" << endl;
			cin.ignore();
			system("cls");
			in_menu_thu_thu();
			chon_menu_thu_thu(account, user);
		}

	}}

}
void doi_mat_khau_quan_ly(Account &account, User user)
{
	system("cls");
	in_doi_mat_khau();
	string c;
	getline(cin, c);
	while (c != "1" && c != "2")
	{
		cout << "Xin moi nhap lai: ";
		getline(cin, c);
	}
	if (c == "2")
	{
		system("cls");
		in_menu_quan_li();
		chon_menu_quan_li(account, user);
	}
	else
	{
		fstream infile, outfile;
		string line;
		bool dang_nhap = false;

		while (!dang_nhap)
		{

			string newPASS;
			cout << "Nhap mat khau cu: ";
			set_account_Password(pass_da_dang_nhap);
			infile.open("account_quan_ly.txt", ios::in);
			outfile.open("temp.txt", ios::out);
			getline(infile, line);
			outfile << line << endl;
			getline(infile, line);
			outfile << line << endl;
			while (!infile.eof())
			{

				getline(infile, line);
				stringstream line1(line);
				line1 >> account.student_ID >> account.account_ID >> account.account_Password
					>> account.role >> account.account_ative;
				user.student_ID = account.student_ID;
				if ((id_da_dang_nhap == account.account_ID) && (pass_da_dang_nhap == account.account_Password))
				{
					dang_nhap = true;

					if (dang_nhap == true)
					{
						cout << endl << "Xin moi nhap mat khau moi: ";
						set_account_Password(newPASS);
						string account_Password_test; //Kiem tra lai mat khau bang cach nhap lai
						string choice; //Dung de lua chon nhap lai pass hay nhap lai pass test
						while (true)
						{
							cout << endl << "Xac nhan lai mat khau: ";
							set_account_Password(account_Password_test);
							cout << endl;
							if (account_Password_test == newPASS)
								break;
							else //Neu mat khau xac nhan khac mat khau
							{
								cout << "Mat khau xac nhan khong trung khop,hay xem xet lua chon ben duoi" << endl;
								cout << "Yes:Nhap lai mat khau xac nhan" << endl
									<< "No:Nhap lai mat khau" << endl
									<< "Nhap y de xac nhan Yes,n de xac nhan la No" << endl;
								//Nhap lua chon
								while (true)
								{
									cin >> choice;
									if (choice == "y" || choice == "n")
										break;
									else //Neu nhap sai choice nhap lai toi khu dung
									{
										cout << "Khong xac nhan duoc lua chon,vui long nhap lai" << endl;
										continue;
									}
								} //End while nhap lua chon

								  //Thuc hien chuc nang tu lua chon
								if (choice == "y")
									continue; //Tiep tuc nhap mat khau xac nhan
								else
								{
									cout << "Nhap mat khau: ";
									set_account_Password(newPASS); //Nhap lai mat khau
									cout << endl;
									continue; //Nhap mat khau xac nhan
								}

							} //End else
						} //End while xac nhan mat khau

						outfile << left << setw(10) << user.student_ID << left << setw(30) << account.account_ID <<
							left << setw(30) << newPASS <<
							left << setw(15) << account.role << left << setw(9) << account.account_ative << endl;
						pass_da_dang_nhap = newPASS;
					}
				}
				else
				{
					outfile << line << endl;
				}
			}
			infile.close();
			outfile.close();

			/////////////////////////////
			infile.open("temp.txt", ios::in);
			outfile.open("account_quan_ly.txt", ios::out);
			while (getline(infile, line))
			{
				outfile << line << endl;						// copy noi dung 2 file
			}
			infile.close();
			outfile.close();

			if (dang_nhap != true)
			{
				cout << endl;
				cout << "Ten tai khoan/mat khau khong dung!! Xin moi nhap lai!!" << endl;
			}
			else
			{
				cout << endl << "DOI MAT KHAU THANH CONG!!!!" << endl;
				cin.ignore();
				system("cls");
				in_menu_quan_li();
				chon_menu_quan_li(account, user);
			}

		}
	}
}

/********************CHON MENU**********************/
void chon_menu_quan_li(Account &account, User user)
{
	string chon;
	bool lua_chon_sai = true;
	string chuc_nang;
	do {
		cin >> chuc_nang;
		switch (chuc_nang[0] - '0')
		{
		case 1: //Them nguoi dung
			system("cls");
			
			cin.ignore();
			Set_User(user);
			Set_Account(account, user);
			cout << "Them nguoi dung thanh cong!!!" << endl;
			cout << endl << "1. Tro ve menu chinh." << endl;
			getline(cin, chon);
			while (chon != "1")
			{
				cout << "Xin moi nhap lai :";
				getline(cin, chon);
			}
			if (chon == "1")
			{
				system("cls");
				in_menu_quan_li();
				chon_menu_quan_li(account, user);
			}
			lua_chon_sai = false;
			break;

		case 2: //Xem thong tin va chinh sua
			cout << "Tim kiem nguoi dung" << endl;
			edit_account(account, user);
			in_menu_quan_li();
			chon_menu_quan_li(account, user);
			lua_chon_sai = false;
			break;

		case 3: //Xem nguoi dung qua han tra sach va khoa tai khoan
			cout << "Xem danh sach nguoi dung qua han tra sach va khoa tai khoan" << endl;
			kiem_tra_qua_han();
			khoa_tai_khoan(account, user);
			system("cls");
			in_menu_quan_li();
			chon_menu_quan_li(account, user);
			lua_chon_sai = false;
			break;
		case 4: //Doi mat khau
			cout << "Doi mat khau" << endl;
			doi_mat_khau_quan_ly(account, user);
			lua_chon_sai = false;
			break;
		case 5: //Dang xuat
			system("cls");
			menu_dang_nhap(account, user);
			lua_chon_sai = false;
			break;
		default:
			lua_chon_sai = true;
			system("cls");
			in_menu_quan_li();
			cout << "Xin moi nhap lai!!!!" << endl;

		}
	} while (lua_chon_sai);

}
void chon_menu_user(Account &account, User user)
{
	string chon;
	bool lua_chon_sai = true;
	string chuc_nang;
	do {
		getline(cin, chuc_nang);
		switch (chuc_nang[0] - '0')
		{
		case 1: //Tim sach va muon sach
			Cart_Main_Menu(account.account_ID);
			system("cls");
			in_menu_user();
			chon_menu_user(account, user);
			lua_chon_sai = false;
			break;
		case 2: //Xem thong bao
			user_notification(account);
			system("cls");
			in_menu_user();
			chon_menu_user(account, user);
			lua_chon_sai = false;
			break;
		case 3: //Xem thong tin
			system("cls");
			xem_thong_tin_user(account, user);
			lua_chon_sai = false;
			break;
		case 4: //Doi mat khau
			doi_mat_khau_user(account, user);
			lua_chon_sai = false;
			break;
		case 5: //Dang xuat
			system("cls");
			menu_dang_nhap(account, user);
			lua_chon_sai = false;
			break;
		default:
			lua_chon_sai = true;
			system("cls");
			in_menu_user();
			cout << "Xin moi nhap lai!!!!" << endl;
		}
	} while (lua_chon_sai);
}
void chon_menu_thu_thu(Account &account, User user)
{
	string chon;
	bool lua_chon_sai = true;
	string chuc_nang;
	do {
		getline(cin, chuc_nang);
		switch (chuc_nang[0] - '0')
		{
		case 1: //Them sach
			Add_Book();
			system("cls");
			in_menu_thu_thu();
			chon_menu_thu_thu(account, user);
			lua_chon_sai = false;
			break;
		case 2: //Tra sach cho nguoi dung
			tra_sach(account, user);
			system("cls");
			in_menu_thu_thu();
			chon_menu_thu_thu(account, user);
			lua_chon_sai = false;
			break;
		case 3: //Tim va sua thong tin sach
			Erase_and_edit_book();
			system("cls");
			in_menu_thu_thu();
			chon_menu_thu_thu(account, user);
			lua_chon_sai = false;
			break;
		case 4: //Yeu cau cua doc gia
			check_book();
			system("cls");
			in_menu_thu_thu();
			chon_menu_thu_thu(account, user);
			lua_chon_sai = false;
			break;
		case 5: //Xem danh sach nguoi dung qua han muon sach
			kiem_tra_qua_han();
			cout << "1. Tro ve menu chinh." << endl;
			getline(cin, chon);
			while (chon != "1")
			{
				cout << "Nhap sai, xin moi nhap lai!!" << endl;
				getline(cin, chon);
			}
			system("cls");
			in_menu_thu_thu();
			chon_menu_thu_thu(account, user);
			lua_chon_sai = false;
			break;
		case 6: //Doi mat khau
			cout << "Doi mat khau" << endl;
			lua_chon_sai = false;
			doi_mat_khau_thu_thu(account, user);
			break;
		case 7: //Dang xuat
			system("cls");
			menu_dang_nhap(account, user);
			lua_chon_sai = false;
			break;
		default:
			lua_chon_sai = true;
			system("cls");
			in_menu_thu_thu();
			cout << "Xin moi nhap lai!!!!" << endl;
		}
	} while (lua_chon_sai);
}
/********************DANG NHAP**********************/
void menu_dang_nhap(Account account, User user)
{
	in_menu_dang_nhap();
	cout << endl;
	cout << "Xin moi lua chon: ";
	bool lua_chon_sai = true;
	string chuc_nang;
	do {
		getline(cin, chuc_nang);
		switch (chuc_nang[0] - '0')
		{
		case 1:
			cout << "Xin moi doc gia dang nhap." << endl
				<< "Khong phai doc gia?" << endl
				<< "Bo trong tai khoan de chon lai vai tro cua ban!" << endl;
			lua_chon_sai = false;
			dang_nhap_user(account, user);

			break;
		case 2:
			cout << "Xin moi thu thu dang nhap." << endl
				<< "Khong phai thu thu?" << endl
				<< "Bo trong tai khoan de chon lai vai tro cua ban!" << endl;
			lua_chon_sai = false;
			dang_nhap_thu_thu(account, user);
			in_menu_thu_thu();
			chon_menu_thu_thu(account, user);
			break;
		case 3:
			cout << "Xin moi quan ly nguoi dung dang nhap." << endl
				<< "Khong phai quan ly nguoi dung?" << endl
				<< "Bo trong tai khoan de chon lai vai tro cua ban!" << endl;
			lua_chon_sai = false;
			dang_nhap_quan_ly(account, user);
			in_menu_quan_li();
			chon_menu_quan_li(account, user);
			break;
		case 4:
			exit(0);
		default:
			lua_chon_sai = true;
			system("cls");
			menu_dang_nhap(account, user);
			cout << "Xin moi nhap lai!!!!" << endl;

		}
	} while (lua_chon_sai);
}
void dang_nhap_user(Account account, User user)
{
	bool dang_nhap = false;
	bool doc_file = false;
	;
	while (!dang_nhap)
	{
		string accID, PASS;
		cout << "Nhap tai khoan: ";
		getline(cin, accID);
		if (accID.length() == 0) {
			system("cls");
			menu_dang_nhap(account, user);
			return;
		}
		cout << "Nhap mat khau: ";
		set_account_Password(PASS);

		fstream infile;
		string line;
		infile.open("account.txt", ios::in);
		getline(infile, line);
		getline(infile, line);
		while (!doc_file)
		{
			if (infile.eof() == 1)break;
			getline(infile, line);
			stringstream line1(line);
			line1 >> account.student_ID >> account.account_ID >> account.account_Password
				>> account.role >> account.account_ative;
			user.student_ID = account.student_ID;
			if ((accID == account.account_ID) && (PASS == account.account_Password))
			{
				dang_nhap = true;
				doc_file = true;
				if (dang_nhap == true)
				{
					if (account.account_ative == "activated")
					{
						cout << endl << "DANG NHAP THANH CONG!" << endl;
						cin.ignore();
						system("cls");
						id_da_dang_nhap = account.account_ID;
						pass_da_dang_nhap = account.account_Password;
						mssv_da_dang_nhap = account.student_ID;
						in_menu_user();
						chon_menu_user(account, user);
					}
					else {
						cout << endl << "TAI KHOAN CUA BAN DA BI KHOA!" << endl; TK_bi_khoa = true;
					}
				}
			}
		}
		if (infile.eof() == 1)
		{
			cout << endl;
			cout << "Ten tai khoan/mat khau khong dung!! Xin moi nhap lai!!" << endl;

		}
		infile.close();
	}
}
void dang_nhap_quan_ly(Account account, User user)
{
	bool dang_nhap = false;
	bool doc_file = false;
	while (!dang_nhap)
	{
		string accID, PASS;
		cout << "Nhap tai khoan: ";
		getline(cin, accID);
		if (accID.length() == 0) {
			system("cls");
			menu_dang_nhap(account, user);
			return;
		}
		cout << "Nhap mat khau: ";
		set_account_Password(PASS);

		fstream infile;
		string line;
		infile.open("account_quan_ly.txt", ios::in);
		getline(infile, line);
		getline(infile, line);
		while (!doc_file)
		{
			if (infile.eof() == 1)break;
			getline(infile, line);
			stringstream line1(line);
			line1 >> account.student_ID >> account.account_ID >> account.account_Password
				>> account.role >> account.account_ative;
			user.student_ID = account.student_ID;
			if ((accID == account.account_ID) && (PASS == account.account_Password))
			{
				dang_nhap = true;
				doc_file = true;
				if (dang_nhap == true)
				{
					if (account.account_ative == "activated")
					{
						cout << endl << "DANG NHAP THANH CONG!" << endl;
						cin.ignore();
						system("cls");
						id_da_dang_nhap = account.account_ID;
						pass_da_dang_nhap = account.account_Password;
						mssv_da_dang_nhap = account.student_ID;
					}
					else { cout << endl << "TAI KHOAN CUA BAN DA BI KHOA!" << endl; TK_bi_khoa = true; }
				}
			}
		}
		if (infile.eof() == 1)
		{
			cout << endl;
			cout << "Ten tai khoan/mat khau khong dung!! Xin moi nhap lai!!" << endl;

		}
		infile.close();
	}
}
void dang_nhap_thu_thu(Account account, User user)
{
	bool dang_nhap = false;
	bool doc_file = false;
	while (!dang_nhap)
	{
		string accID, PASS;
		cout << "Nhap tai khoan: ";
		getline(cin, accID);
		if (accID.length() == 0) {
			system("cls");
			menu_dang_nhap(account, user);
			return;
		}
		cout << "Nhap mat khau: ";
		set_account_Password(PASS);

		fstream infile;
		string line;
		infile.open("account_thu_thu.txt", ios::in);
		getline(infile, line);
		getline(infile, line);
		while (!doc_file)
		{
			if (infile.eof() == 1)break;
			getline(infile, line);
			stringstream line1(line);
			line1 >> account.student_ID >> account.account_ID >> account.account_Password
				>> account.role >> account.account_ative;
			user.student_ID = account.student_ID;
			if ((accID == account.account_ID) && (PASS == account.account_Password))
			{
				dang_nhap = true;
				doc_file = true;
				if (dang_nhap == true)
				{
					if (account.account_ative == "activated")
					{
						cout << endl << "DANG NHAP THANH CONG!" << endl;
						cin.ignore();
						system("cls");
						id_da_dang_nhap = account.account_ID;
						pass_da_dang_nhap = account.account_Password;
						mssv_da_dang_nhap = account.student_ID;
					}
					else { cout << endl << "TAI KHOAN CUA BAN DA BI KHOA!" << endl; TK_bi_khoa = true; }
				}
			}
		}
		if (infile.eof() == 1)
		{
			cout << endl;
			cout << "Ten tai khoan/mat khau khong dung!! Xin moi nhap lai!!" << endl;
		}
		infile.close();
	}
}

/***************************************************/
void kiem_tra_qua_han()
{
	system("cls");
	fstream infile, outfile;
	string line;
	infile.open("danh_sach_muon_sach.txt", ios::in);
	outfile.open("danh_sach_qua_han.txt", ios::out);
	outfile << "Dach sach doc gia chua tra sach: (Tinh den ngay: " << xuat_thoi_gian() << " )" << endl;
	outfile << setw(20) << left << "ID account" << setw(70) << left << "Ten sach" << setw(20) << left << "Thoi gian muon" << endl;

	getline(infile, line);
	getline(infile, line);
	while (!infile.eof())
	{
		getline(infile, line);
		if (line.length() == 0) continue;
		string time1;
		for (size_t i = 90; i < line.length(); i++)
		{
			time1 = time1 + line[i];
		}
		string time2 = xuat_thoi_gian();
		stringstream temp1(time1), temp2(time2);
		int hour1, min1, second1, day1, month1, year1;
		int hour2, min2, second2, day2, month2, year2;
		char ki_tu;
		temp1 >> hour1 >> ki_tu >> min1 >> ki_tu >> second1 >> ki_tu >> ki_tu >> day1 >> ki_tu >> month1 >> ki_tu >> year1;
		temp2 >> hour2 >> ki_tu >> min2 >> ki_tu >> second2 >> ki_tu >> ki_tu >> day2 >> ki_tu >> month2 >> ki_tu >> year2;
		int ngay_muon;
		if (year2 != year1)
		{
			ngay_muon = so_ngay_so_voi_dau_nam(day2, month2, year2) + ngay_trong_nam(year1) - so_ngay_so_voi_dau_nam(day1, month1, year1);
		}
		else
		{
			if (month1 == month2)ngay_muon = day2 - day1;
			else ngay_muon = so_ngay_so_voi_dau_nam(day2, month2, year2) - so_ngay_so_voi_dau_nam(day1, month1, year1);
		}
		if (ngay_muon > 30)
		{
			stringstream temp(line);
			temp >> list_ID_block[dem_list_ID_block];
			dem_list_ID_block++;
			for (int i = 0; i < 90; i++)
				outfile << line[i];
			outfile << ngay_muon << " ngay" << endl;
		}
	}
	infile.close();
	outfile << endl << endl;
	outfile.close();
	infile.open("danh_sach_qua_han.txt", ios::in);
	getline(infile, line); cout << line << endl;
	getline(infile, line);
	cout << " " << setfill('_') << setw(112) << "" << setfill(' ') << endl;
	cout << "|" << left << setw(20) << "Account ID"
		<< "|" << left << setw(70) << "Ten sach"
		<< "|" << left << setw(20) << "Thoi gian muon" << "|" << endl;
	cout << setfill('_') << setw(21) << "|" << setw(71) << "|" << setw(21) << "|" << "|" << setfill(' ') << endl;
	while (!infile.eof())
	{
		getline(infile, line);
		if (line.length() > 0)
		{
			string id = line.substr(0, 20); delete_space(id);
			string ten_sach = line.substr(20, 70); delete_space(ten_sach);
			string thoi_gian_muon = line.substr(90); delete_space(thoi_gian_muon);
			cout << "|" << left << setw(20) << id
				<< "|" << left << setw(70) << ten_sach
				<< "|" << left << setw(20) << thoi_gian_muon << "|" << endl;
		}
	}
	cout << setfill('_') << setw(21) << "|" << setw(71) << "|" << setw(21) << "|" << "|" << setfill(' ') << endl;
	infile.close();
}
void xem_thong_tin_user(Account account, User user)
{
	fstream infile, infile1;
	string line, line1;
	string ID_can_tim_thong_tin = id_da_dang_nhap;
	infile.open("account.txt", ios::in);
	infile1.open("user.txt", ios::in);
	getline(infile, line); //bo 2 dong
	getline(infile, line);
	getline(infile1, line1); //bo 2 dong
	getline(infile1, line1);
	while (!infile.eof() && !infile1.eof())
	{
		getline(infile, line);
		stringstream temp(line);
		temp >> account.student_ID >> account.account_ID >> account.account_Password
			>> account.role >> account.account_ative;
		user.student_ID = account.student_ID;
		cout << "this line is ok\n";
		getline(infile1, line1);
		stringstream temp1(line1);
		temp1 >> user.student_ID >> user.user_name >> user.user_date_of_birth >> user.user_job >> user.user_mail;

		if (account.account_ID == ID_can_tim_thong_tin)
		{
			system("cls");
			cout << "THONG TIN CUA TAI KHOAN" << endl << endl;
			
			cout << " " << setfill('_') << setw(126) << "" << endl << setfill(' ');
			cout << "|" << left << setw(10) << "MSSV"
				<< "|" << left << setw(20) << "Ten tai khoan"
				<< "|" << left << setw(25) << "Ten nguoi dung"
				<< "|" << left << setw(10) << "Ngay sinh"
				<< "|" << left << setw(15) << "Cong viec"
				<< "|" << left << setw(30) << "Email"
				<< "|" << left << setw(10) << "Trang thai" << "|" << endl;
			cout << setfill('_')
				<< setw(11) << "|" << setw(21) << "|" << setw(26) << "|" << setw(11)
				<< "|" << setw(16) << "|" << setw(31) << "|" << setw(11) << "|" << "|" << endl
				<< setfill(' ');
			cout << setw(11) << "|" << setw(21) << "|" << setw(26) << "|" << setw(11)
				<< "|" << setw(16) << "|" << setw(31) << "|" << setw(11) << "|" << "|" << endl;

			cout << "|" << left << setw(10) << user.student_ID
				<< "|" << left << setw(20) << account.account_ID
				<< "|" << left << setw(25) << RE_dinh_dang_chuoi(user.user_name)
				<< "|" << left << setw(10) << user.user_date_of_birth
				<< "|" << left << setw(15) << RE_dinh_dang_chuoi(user.user_job)
				<< "|" << left << setw(30) << user.user_mail
				<< "|" << left << setw(10) << account.account_ative << "|" << endl;
			cout << setfill('_')
				<< setw(11) << "|" << setw(21) << "|" << setw(26) << "|" << setw(11)
				<< "|" << setw(16) << "|" << setw(31) << "|" << setw(11) << "|" << "|" << endl
				<< setfill(' ');
			break;
		}
	}
	infile.close();
	infile1.close();

	string chon;
	cout << "1. Tro ve menu truoc" << endl;
	//cin.ignore();
	getline(cin, chon);
	while (chon != "1"&&chon != "2")
	{
		cout << "Nhap sai, xin nhap lai!!" << endl;
		getline(cin, chon);
	}
	if (chon == "1")
	{
		system("cls");
		in_menu_user(); cin.clear();
		chon_menu_user(account, user);
	}
}
void user_notification(Account acc)
{
	fstream infile, outfile;
	string line, name, ID, date, status, choice;
	bool exit_user_notification = false;
	while (exit_user_notification == false)
	{
		system("cls");
		in_user_notification();
		getline(cin, choice);
		if (choice == "1")
		{
			system("cls"); bool empty = true;
			cout << "DANH SACH SACH DA MUON" << endl;
			cout << " " << setfill('_') << setw(91) << "" << setfill(' ') << endl;
			cout << "|" << setw(70) << left << "Ten sach" << "|" << setw(20) << left << "Thoi gian" << "|" << endl;
			cout << setfill('_') << setw(71) << "|" << setw(21) << "|" << "|" << endl << setfill(' ');

			infile.open("danh_sach_muon_sach.txt", ios::in);
			while (getline(infile, line))
			{
				if (line.length() > 90)
				{
					ID = line.substr(0, 20); delete_space(ID);
					date = line.substr(90); delete_space(date);
					if (acc.account_ID == ID)
					{
						empty = false;
						name = line.substr(20, 70);
						delete_space(name);
						cout << "|" << setw(70) << left << name << "|" << setw(20) << left << date << "|" << endl;
					}
				}
			} //End while doc file
			if (empty)
			{
				cout << "|" << left << setw(91) << "Khong co sach nao duoc muon gan day" << "|" << endl;
				cout << setfill('_') << setw(92) << "|" << "|" << endl << setfill(' ');
			}
			else
				cout << setfill('_') << setw(71) << "|" << setw(21) << "|" << "|" << endl << setfill(' ');
			infile.close();
			cin.ignore();
		}
		else if (choice == "2")
		{
			system("cls");
			cout << "THONG BAO SACH MUON" << endl << endl;
			
			bool exit_user_pending = false;
			while (exit_user_pending == false)
			{
				bool empty = true;
				infile.open("danh_sach_muon_sach_pending.txt", ios::in);
				outfile.open("danh_sach_muon_sach_pending_temp.txt", ios::out);
				system("cls");
				cout << "THONG TIN SACH MUON" << endl;
				cout << " " << setfill('_') << setw(91) << "" << setfill(' ') << endl;
				cout << "|" << setw(70) << left << "Ten sach" << "|" << left << setw(20) << "Tinh trang" << "|" << endl;
				cout << setfill('_') << setw(71) << "|" << setw(21) << "|" << "|" << endl << setfill(' ');
				while (getline(infile, line))////////////////
				{
					if (line.length() > 0)
					{
						ID = line.substr(0, 20);
						delete_space(ID);
						if (acc.account_ID == ID)
						{
							name = line.substr(20, 70);
							delete_space(name);
							status = line.substr(110);
							delete_space(status);

							if (status == "Pending")
							{
								cout << "|" << setw(70) << left << name << "|" << setw(20) << "Dang duoc xu li" << "|" << endl;
								empty = false;
							}
							else if (status == "Fail")
							{
								cout << "|" << setw(70) << left << name << "|" << setw(20) << "Muon sach that bai" << "|" << endl;
								empty = false;
							}
						}
					}
				} //End while doc file
				if (empty)
				{
					cout << "|" << left << setw(91) << "Khong co sach nao duoc muon gan day" << "|" << endl;
					cout << setfill('_') << setw(92) << "|" << "|" << endl << setfill(' ');
				}
				else
					cout << setfill('_') << setw(71) << "|" << setw(21) << "|" << "|" << endl << setfill(' ');

				infile.close();
				outfile.close();

				cout << "1.  Xoa lich su sach khong muon duoc" << endl;
				cout << "2.  Tro ve menu truoc" << endl;
				cout << "Xin moi lua chon: ";
				getline(cin, choice);

				if (choice == "1")
				{
					infile.open("danh_sach_muon_sach_pending.txt", ios::in);
					outfile.open("danh_sach_muon_sach_pending_temp.txt", ios::out);
					while (getline(infile, line))/////////////////////
					{
						if (line.length() > 0)
						{
							ID = line.substr(0, 20);
							delete_space(ID);

							status = line.substr(110);
							delete_space(status);
							if (acc.account_ID == ID && status == "Fail")
								continue;
							else
								outfile << line << endl;
						}
					}//End while doc file
					infile.close();
					outfile.close();


					infile.open("danh_sach_muon_sach_pending_temp.txt", ios::in);
					outfile.open("danh_sach_muon_sach_pending.txt", ios::out);
					while (getline(infile, line))//////////////////
					{
						if (line.length() > 0)
							outfile << line << endl;
					}
					infile.close();
					outfile.close();
					cout << "Xoa thanh cong!"; cin.ignore();
					exit_user_pending = true;
				}
				else if (choice == "2")
				{
					exit_user_pending = true;
				}
				else
				{
					cout << "Khong xac dinh duoc lua chon,vui long nhap lai (nhan enter de tiep tuc)" << endl;
					system("pause");
				}
			} //End while menu
		}

		else if (choice == "3")
		{
			exit_user_notification = true;
		}
		else
		{
			cout << "Khong xac dinh duoc lua chon,vui long nhap lai (nhan enter de tiep tuc)" << endl;
			system("pause");
		}
	}
}
void tra_sach(Account account, User user)
{
	while (true)
	{
		system("cls");
		in_danh_sach_muon_sach();
		int ID = 0;
		fstream infile, outfile;
		string line;
		bool found = false;
		cout << "Nhap so thu tu sach can tra (nhap 0 de quay lai man hinh truoc): ";
		while (!found)
		{
			cin >> ID;
			if (cin.fail())
			{
				cout << "Nhap sai. Nhap lai so thu tu sach can tra: ";
				cin.clear(); cin.ignore(128, '\n');
				continue;
			}
			if (ID <= 0) break;
			infile.open("danh_sach_muon_sach.txt", ios::in);
			outfile.open("temp.txt", ios::out);

			getline(infile, line);
			outfile << line << endl;
			getline(infile, line);
			outfile << line << endl;
			int stt = 0;
			while (!infile.eof())
			{
				getline(infile, line);
				if (line.length() > 0)
					stt++;

				if (stt == ID)
					found = true;
				else
					outfile << line << endl;	//Xoa dong ID va ghi vao temp.txt
			}
			infile.close();
			outfile.close();
			if (!found)
				cout << "Nhap sai. Nhap lai so thu tu sach can tra: ";
		}

		if (!found)
		{
			cin.ignore();
			break;
		}
		else
		{
			infile.open("temp.txt", ios::in);
			outfile.open("danh_sach_muon_sach.txt", ios::out);
			while (getline(infile, line))
			{
				outfile << line << endl;	//copy lai tu temp.txt
			}
			infile.close();
			outfile.close();
			cout << "TRA SACH THANH CONG !!" << endl;
			cin.ignore(); cin.ignore();
		}
	}
	system("cls");
	in_menu_thu_thu();
	chon_menu_thu_thu(account, user);
}
