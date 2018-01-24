#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <math.h>
#include <conio.h>
#include <time.h>

using namespace std;

int f();
void findMax();
int isLeap(int year);
void getCountDayInMonth_5(int year, int month, int day);
int getCountDaysInMonth(int month, int year);
int task9(char letter);

int main()
{
	setlocale(LC_ALL, "Russian");
	int z;
	do
	{
		cout << "Kakoe zadanie?" << endl;
		cin >> z;
		switch (z)
		{
		case 1:
		{
			cout << f();
			
		}
		break;

		case 2:
		{
			findMax();
			break;
		}
		break;

		case 5:
		{
			cout << "Vvedite god: " << endl;
			int year;
			cin >> year;

			cout << "Vvedite mesyac: " << endl;
			int month;
			cin >> month;

			cout << "Vvedite den': " << endl;
			int day;
			cin >> day;
			getCountDayInMonth_5(year, month, day);
		
		
		}
		break;

		case 6:
		{
			char letter;
			cin >> letter;
			int countLetter = task9(letter);
			cout << "Kol-vo naidennyh bukv " << letter << " = " << countLetter << endl;

		}
		break;

		}
	} while (z <= 0);

	system("pause");

}

//1.	�������� ������� int f(int h, int m, int s), ������� ��������� ��� ����� ���������(���� h, ������ m � ������� s) � ���������� ���������� ������, ��������� � ������ ���
int f()
{
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);

	int startDayH = 6;
	int startDayM = 00;
	int startDayS = 00;

	float totalSeconds = (timeinfo->tm_hour - startDayH) * 3600;
	totalSeconds += (timeinfo->tm_min) * 60;

	return totalSeconds;
}
//4.	���� ����� ��������� �����.���������� ������������ �� ���. (���������� �������, ��������� �������� �� ���� ��������� �����.)
void findMax()
{
	srand(time(NULL));
	int a[6];
	int max = 0;
	for (int i = 0; i < 6; i++)
	{
		a[i] = -1 + rand() % 50;
		if (max < a[i])
			max = a[i];
	}
	cout << "Max = " << max << endl;
}
//5.	���� ���������� ��� ��������������� ����� ������������ ������� : g(���), m(���������� ����� ������) � n(�����).�� �������� g, n � m ����������
//(���������� �������, �������������� ���������� ���� � ��� ��� ���� ������) :
//	a.���� ����������� ���;
//b.���� ���������� ���

void getCountDayInMonth_5(int year,int month, int day)
{
	int leap = isLeap(year);
	//	a.���� ����������� ���;
	if (day == 1)
	{
		if (day == 1 && month == 1)
		{
			year = year - 1;
		}
		if (month == 1)
			month = 12;
		else
			month = month - 1;

		
		day = getCountDaysInMonth(month, year);
	}
	else
		day = day - 1;

	cout << "���� ����������� ���: " << day << "." << month << "." << year << endl;
}

int getCountDaysInMonth(int month, int year)
{
	int leap = isLeap(year);

	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else if (month == 2)
	{
		/*if (isLeap(year) == 1)
			return 29;
		else
			return 28;*/

		return isLeap(year) == 1 ? 29 : 28;
	}
	else
		return 31;
}

//6.	� ����� ������� ����������� ��� ������ :
//a.�������� ��� �� �������� ����������;
//b.�������� ��� ����� ���� ����������

int isLeap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	else
		return 0;
}


/*9.	��������� ��������� ��� ���������� ������ ���������� �������� �����  � ���� �������� ������������. (���������� ������� ��� ������� ���������� ��������� ����� � �����������.)*/
int task9(char letter)
{
	char str1[100];
	char str2[100];
	char str3[100];

	for (int i = 0; i < 20; i++)
	{
		str1[i] = getchar();
	}
	int countLetter = 0;

	for (int i = 0; i < 20; i++)
	{
		if (letter == str1[i])
			countLetter++;
	}


	cout << "Vvedite vtoruyu stroku?" << endl;
    str2[20];
	char *result;
	result = gets_s(str2);

	for (int i = 0; i < 20; i++)
	{
		if (letter == str2[i])
			countLetter++;
	}

	return countLetter;
}
