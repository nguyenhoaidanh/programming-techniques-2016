#include "xuat_thoi_gian.h"

int ngay_trong_thang(int month, int year)
{
	switch (month)
	{
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	case 2:
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			return 29; break;
		}
		else
		{
			return 28;
			break;
		}
	default:
		return 31;
	}
}
int ngay_trong_nam(int nam)
{
	if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)return 366;
	else return 365;
}
int so_ngay_so_voi_dau_nam(int day, int month, int year)
{
	switch (month)
	{
	default: return 0; break;
	case 1:return (day); break;
	case 2:return (31 + day); break;
	case 3:return (31 + ngay_trong_thang(2, year) + day); break;
	case 4:return (31 + ngay_trong_thang(2, year) + 31 + day); break;
	case 5:return (31 + ngay_trong_thang(2, year) + 31 + 30 + day); break;
	case 6:return (31 + ngay_trong_thang(2, year) + 31 + 30 + 31 + day); break;
	case 7:return (31 + ngay_trong_thang(2, year) + 31 + 30 + 31 + 30 + day); break;
	case 8:return (31 + ngay_trong_thang(2, year) + 31 + 30 + 31 + 30 + 31 + day); break;
	case 9:return (31 + ngay_trong_thang(2, year) + 31 + 30 + 31 + 30 + 31 + 31 + day); break;
	case 10:return (31 + ngay_trong_thang(2, year) + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day); break;
	case 11:return (31 + ngay_trong_thang(2, year) + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day); break;
	case 12:return (31 + ngay_trong_thang(2, year) + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day); break;
	}
}
string xuat_thoi_gian()
{
	time_t rawtime;
	time(&rawtime);
	string thoi_gian = ctime(&rawtime);
	stringstream temp(thoi_gian), temp1;
	string thu, month; int ngay, thang, nam, gio, phut, giay; char haicham;
	temp >> thu >> month >> ngay >> gio >> haicham >> phut >> haicham >> giay >> nam;
	if (month == "Jan")thang = 1;
	else if (month == "Feb")thang = 2;
	else if (month == "Mar")thang = 3;
	else if (month == "Apr")thang = 4;
	else if (month == "May")thang = 5;
	else if (month == "Jun")thang = 6;
	else if (month == "Jul")thang = 7;
	else if (month == "Aug")thang = 8;
	else if (month == "Sep")thang = 9;
	else if (month == "Oct")thang = 10;
	else if (month == "Nov")thang = 11;
	else if (month == "Dec")thang = 12;
	temp1 << gio << haicham << phut << haicham << giay << "__" << ngay << "/" << thang << "/" << nam;
	return temp1.str();
}
