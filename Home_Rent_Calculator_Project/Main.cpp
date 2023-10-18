#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <cstring>
#include <io.h>
#include <algorithm>
#include <vector>
#include <map>
#include <ctime>
#include<math.h>
#include <fstream>
#include <direct.h>
using namespace std;

enum Color
{
	Black, Blue, Green, Cyan, Red, Magenta, Brown,
	LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
void setColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
enum Direction { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, Esc = 27 };

void setCursor(int x, int y)
{
	COORD myCoords = { x,y };
	SetConsoleCursorPosition(hStdOut, myCoords);
}



void ShowMenu(vector<string>printMenu, int MenuPoint, int X, int Y)
{
	//int X = 42, Y = 13;
	for (size_t i = 0; i < printMenu.size(); i++)
	{
		setCursor(X, Y + i);
		if (i == MenuPoint)
		{
			setColor(LightMagenta, Black);
		}
		else
		{
			setColor(White, Black);
		}

		cout << printMenu[i];
	}
	setColor(White, Black);

}
int MenuChoice(vector<string>printMenu, int X, int Y)
{
	int key;
	int menuPointNumber = 0;
	do
	{
		ShowMenu(printMenu, menuPointNumber, X, Y);
		key = _getch();//возвращает код нажатой клавиши
		switch (key)
		{
		case Up:
			if (menuPointNumber > 0)
			{
				menuPointNumber--;
			}
			break;

		case Down:
			if (menuPointNumber < printMenu.size() - 1)
			{
				menuPointNumber++;
			}
			break;
		case Enter:
			if (menuPointNumber == printMenu.size() - 1)
			{
				return -1;
			}
			return menuPointNumber;
			break;
		}
	} while (key != Esc);
	return -1;
}



class Apartment
{
public:
	double Area;
	int NumberOfOccupants;
	int FloorNumbers;



	void setArea(double newArea)
	{
		if (newArea > 0.0 && newArea < 100000.00)
		{
			Area = newArea;
		}
	}
	void setOccupants(int newOccupants)
	{
		if (newOccupants > 0 && newOccupants < 99)
		{
			NumberOfOccupants = newOccupants;
		}
	}
	void setFloor(int newFloor)
	{

		if (newFloor > 0 && newFloor < 50)
		{
			FloorNumbers = newFloor;
		}
	}

	// Getter methods
	double getArea() const
	{
		return Area;
	}
	int getNumberOfOccupants() const
	{
		return NumberOfOccupants;;
	}
	int getFloorNumbers() const
	{
		return FloorNumbers;
	}
	Apartment()
	{
		Area = Area;
		NumberOfOccupants = NumberOfOccupants;
		FloorNumbers = FloorNumbers;;
	}
	// Constructor to initialize apartment parameters
	Apartment(double Area, int NumberOfOccupant, int NumberOfFloor)
	{
		this->Area = Area;
		this->NumberOfOccupants = NumberOfOccupant;
		this->FloorNumbers = FloorNumbers;
	}


	//print out our apartment
	void output() {
		cout << "Apartment area: " << Area << " sq. m" << "\n";
		cout << "Number of occupants: " << NumberOfOccupants << "\n";
		cout << "Floor: " << FloorNumbers << "\n";
	}
};

//
//class Utility
//{
//public:
//	
//
//	double hotWaterConsumption;
//	double coldWaterConsumption;
//	double gasConsumption;
//	double electricityConsumption;
//	double heatingConsumption;
//	double elevatorConsumption;
//	double cleaningConsumption;
//	double capitalServiceConsumption;
//
//	
//
//	/*Utility()
//	{
//		this->hotWaterTariff = hotWaterTariff;
//		this->coldWaterTariff = coldWaterTariff;
//		this->gasTariff = gasTariff;
//		this->electricityTariff = electricityTariff;
//		this->heatingTariff = heatingTariff;
//		this->elevatorTariff = elevatorTariff;
//		this->cleaningTariff = cleaningTariff;
//
//		this->hotWaterConsumption = hotWaterConsumption;
//		this->coldWaterConsumption = coldWaterConsumption;
//		this->gasConsumption = gasConsumption;
//		this->electricityConsumption = electricityConsumption;
//		this->heatingConsumption = heatingConsumption;
//		this->elevatorConsumption = elevatorConsumption;
//		this->cleaningConsumption = cleaningConsumption;
//	}
//	Utility(double hwTariff, double cwTariff, double _gasTariff, double electricTariff, double heatTariff, double elevaTariff, double cleanTariff)
//	{
//		this->hotWaterTariff= hwTariff;
//		this->coldWaterTariff= cwTariff;
//		this->gasTariff= _gasTariff;
//		this->electricityTariff= electricTariff;
//		this->heatingTariff= heatTariff;
//		this->elevatorTariff= elevaTariff;
//		this->cleaningTariff= cleanTariff;
//	}
//*/
//
//
//};
//
//
//class Billing
//{
//public:
//	Apartment apartment;
//	Utility currentMonth;
//	Utility previousMonth;
//	double hotWater = 201.7;
//	double coldWater = 30.7;
//	double gas = 10.07;
//	double electricity = 9.8;
//	double heating = 2309;
//	double normalheating = 0.0234;
//	double elevator = 2.98;
//	double cleaning = 10.8;
//	double count;
//	double capitalService= 10.9;
//	
//	Billing() 
//	{
//		
//		 this->currentMonth= currentMonth;
//		 this->previousMonth= previousMonth;
//	}
//	
//	Billing(Apartment _apartment, Utility _currentMonth, Utility _previousMonth)
//		: apartment(_apartment), currentMonth(_currentMonth), previousMonth(_previousMonth) {}
//
//
//
//	// Calculate total cost of services for current month
//	double calculateCurrentMonthCost() 
//	{
//		return (previousMonth.hotWaterTariff * previousMonth.hotWaterConsumption +
//			previousMonth.coldWaterTariff * previousMonth.coldWaterConsumption +
//			previousMonth.gasTariff * previousMonth.gasConsumption +
//			previousMonth.electricityTariff * previousMonth.electricityConsumption +
//			previousMonth.heatingTariff * previousMonth.heatingConsumption +
//			previousMonth.elevatorTariff * previousMonth.elevatorConsumption +
//			previousMonth.cleaningTariff * previousMonth.cleaningConsumption);
//	}
//
//
//
//	// Calculate total cost of services for previous month
//	double calculatePreviousMonthCost() {
//		return (previousMonth.hotWaterTariff * previousMonth.hotWaterConsumption +
//			previousMonth.coldWaterTariff * previousMonth.coldWaterConsumption +
//			previousMonth.gasTariff * previousMonth.gasConsumption +
//			previousMonth.electricityTariff * previousMonth.electricityConsumption +
//			previousMonth.heatingTariff * previousMonth.heatingConsumption +
//			previousMonth.elevatorTariff * previousMonth.elevatorConsumption +
//			previousMonth.cleaningTariff * previousMonth.cleaningConsumption);
//	}
//
//double compareRentData(Utility& currentMonth, Utility &previousMonth)
//{
//	double additionalhotwater = (currentMonth.hotWaterConsumption - previousMonth.hotWaterConsumption) * hotWater;
//	cout << " hotwater usage per cubic.M: " << additionalhotwater << " $ " << endl;
//	double additionalColdWater = (currentMonth.coldWaterConsumption - previousMonth.coldWaterConsumption) * coldWater;
//	cout << " Cold water usage per cubic.M: " << additionalColdWater << " $ " << endl;
//	double additionalGas = (currentMonth.gasConsumption - previousMonth.gasConsumption) * gas;
//	cout << " Gas usage per cubic.F: " << additionalGas << " $ " << endl;
//	double additionalElectricity = (currentMonth.electricityConsumption - previousMonth.electricityConsumption) * electricity;
//	cout << " Electricity usage per kwh: " << additionalElectricity << " $ " << endl;
//	double additionalheating = normalheating * count* heating;
//	cout << " heating usage per degrees. C: " << additionalheating << " $ " << endl;
//	double additionalelevator = (currentMonth.elevatorConsumption - previousMonth.elevatorConsumption) *elevator;
//	cout << " Elevator usage per watts ph: " << additionalelevator << " $ " << endl;
//	double additionalcleaning = (currentMonth.cleaningConsumption - previousMonth.cleaningConsumption) * cleaning;
//	cout << " heating usage per square metre: " << additionalcleaning << " $ " << endl;
//	double additionalCapitalExpenses = count * capitalService;
//
//	getting the total sum 
//	double totalCost = additionalhotwater + additionalColdWater + additionalGas + additionalElectricity +
//		additionalheating + additionalelevator + additionalcleaning + additionalCapitalExpenses;
//	cout << " total sum of rent usage: " << totalCost << " $ " << endl;
//
//	/*cout << "\nAdditional utilities payment for over consumption compare to previous and current month (if any):" << endl;
//	cout << "hot water: " << additionalhotwater << " cubic. M" << endl;
//	cout << "cold water: " << additionalColdWater << " cubic. M" << endl;
//	cout << "gas: " << additionalGas << " cubic. ph" << endl;
//	cout << "electricity: " << additionalElectricity << " kWh" << endl;
//	cout << "electricity: " << additionalheating << " degrees. C" << endl;
//	cout << "electricity: " << additionalelevator << " watts ph" << endl;
//	cout << "electricity: " << additionalcleaning << " per square metre" << endl;*/
//	return totalCost;
//}
//
//};

struct User
{
	string login;
	string pass;
	int progress = 0;
};



struct Reciepts
{
	double hotWater;
	double coldWater;
	double gas;
	double electricity;
	double heating;
	double elevator;
	double cleaning;
	double capitalService;
};

struct UtilitiesTariff
{
	//We are creating home utilities necessary for comfortable usage
	double hotWater = 201.7; //all figure can be adjusted depending on the region and location with service charge 
	double coldWater = 30.7;
	double gas = 10.07;
	double electricity = 9.8;
	double heating = 2019;
	double normalheating = 0.0234;
	double elevator = 2.98;
	double cleaning = 10.8;
	double user_count;
	double capitalService = 12.5;
}actualTariff;

void setRecieptData(Reciepts& obj)
{
	cout << "Enter detail the for hot water usage: $";
	cin >> obj.hotWater;
	cout << "Enter details for cold water usage: $";
	cin >> obj.coldWater;
	cout << "Enter details of Gas usage: $";
	cin >> obj.gas;
	cout << "Enter  details for electricity usage: $";
	cin >> obj.electricity;
	cout << "Enter details heat usage : $";
	cin >> obj.heating;
	cout << "Enter details for residential elevator usage : $";
	cin >> obj.elevator;
	cout << "Enter details for cleaning service usage: $";
	cin >> obj.cleaning;
	cout << "Enter details for capital service render: $";
	cin >> obj.capitalService;

}
double compareRentData(Reciepts currentMonth, Reciepts previousMonth)
{
	double additionalhotwater = (currentMonth.hotWater - previousMonth.hotWater) * actualTariff.hotWater;
	double additionalColdWater = (currentMonth.coldWater - previousMonth.coldWater) * actualTariff.coldWater;
	double additionalGas = (currentMonth.gas - previousMonth.gas) * actualTariff.gas;
	double additionalElectricity = (currentMonth.electricity - previousMonth.electricity) * actualTariff.electricity;
	double additionalheating = actualTariff.normalheating * actualTariff.user_count * actualTariff.heating;
	double additionalelevator = (currentMonth.elevator - previousMonth.elevator) * actualTariff.elevator;
	double additionalcleaning = (currentMonth.cleaning - previousMonth.cleaning) * actualTariff.cleaning;
	double additionalCapitalExpenses = actualTariff.user_count * actualTariff.capitalService;

	//getting the total sum of our utility comaparing it with current and last month
	double totalCost = additionalhotwater + additionalColdWater + additionalGas + additionalElectricity +
		additionalheating + additionalelevator + additionalcleaning + additionalCapitalExpenses;
	cout << " total sum of rent usage: " << totalCost << " $ " << endl;

	cout << "\nAdditional utilities payment for over consumption (if any):" << endl;
	cout << "hot water: " << additionalhotwater << " Rubles"/*"cubic. M" */ << endl;
	cout << "cold water: " << additionalColdWater << " Rubles"/*" cubic. M"*/ << endl;
	cout << "gas: " << additionalGas << " Rubles"/*" cubic. ph"*/ << endl;
	cout << "electricity: " << additionalElectricity << " Rubles"/*" kWh"*/ << endl;
	cout << "Heating: " << additionalheating << " Rubles"/*" degrees. C"*/ << endl;
	cout << "resident elevator: " << additionalelevator << " Rubles"/*" watts ph"*/ << endl;
	cout << "cleaning service: " << additionalcleaning << " Rubles"/*" per square metre"*/ << endl;
	return totalCost;
}


int main()
{

	int timeToSleep = 1500;
	setCursor(35, 9);
	string str = "WELCOME TO HOME RENTAGE CALCULATOR PROJECT\n";
	setColor(Black, Magenta);
	cout << str;
	Sleep(timeToSleep);
	setColor(White, Black);
	Sleep(1500);
	Sleep(timeToSleep);
	system("cls");

	bool isCorrect = true;
	vector<string>menu{ "REGISTRATION", "AUTHORIZATION", "QUIT" };
	INT index = MenuChoice(menu, 42, 9);

	do
	{


		if (index == 0)
		{
			Sleep(timeToSleep);
			system("cls");
			isCorrect = true;
		}
		else if (index == 1)
		{

			Sleep(timeToSleep);
			system("cls");
			isCorrect = true;

		}
	} while (!isCorrect);

	User ak_user;
	User temp;

	Reciepts currentMonths, previousMonths;
	Apartment apartment;
	//Utility currentMonths, previousMonths; //
	//Billing bill;
	//регистрация
	do
	{

		// index = MenuChoice(menu, 42, 10);
		if (index == 0)
		{
			Sleep(timeToSleep);
			system("cls");
			setCursor(42, 9);
			setColor(Cyan, Black);
			cout << " LET START THE RENT CALCULATION!!";

			Sleep(timeToSleep);
			system("cls");
			setCursor(42, 8);
			cout << "LOGIN: ";
			cin >> ak_user.login;
			setCursor(47, 10);

			ifstream readF("user.txt");
			system("cls");
			if (readF.is_open())
			{
				while (!readF.eof())
				{
					readF >> temp.login >> temp.pass >> temp.progress;
					//cout << temp.login << "\t" << temp.pass << "\t" << temp.progress << "\n";
					if (temp.login.compare(ak_user.login) == 0)
					{
						setCursor(42, 9);
						cout << "login is busy!" << endl;
						isCorrect = false;
						break;
					}
				}
				readF.close();
			}

			if (isCorrect)
			{
				ofstream writeF("user.txt", ios::app);
				setCursor(42, 8);
				cout << "PASSWORD: ";
				cin >> ak_user.pass;
				setCursor(47, 10);
				//если файл не пуст - записывать перед новым юзером \n
				writeF << ak_user.login << " " << ak_user.pass << " " << ak_user.progress;
				writeF.close();
				setCursor(42, 9);
				cout << "REEGISTRATION IS COMPLETED!!!\n";
				Sleep(timeToSleep);
				system("cls");
				_mkdir(ak_user.login.c_str()); //with the help of direct.h library we are creating file with user detail
				string path = ak_user.login + "userInfo.txt"; //creating name f our file
				string foldFile = ak_user.login + "/" + path;
				writeF.open(foldFile);

				cout << "Enter apartment area: ";
				cin >> apartment.Area;
				cout << "Enter number of occupants: "; //apartment.NumberOfOccuants
				cin >> apartment.NumberOfOccupants;
				cout << "Enter floor: ";
				cin >> apartment.FloorNumbers;

				time_t rtime;
				time(&rtime);
				tm currentTime;
				localtime_s(&currentTime, &rtime);
				int month, year;
				month = currentTime.tm_mon + 1;//current month file
				year = currentTime.tm_year + 1900;

				char* mas = new char[25];
				string fileName = "."; _itoa_s(month, mas, 25, 10);
				//UserFile += ak_user.login;
				fileName += "\\";
				fileName += mas;
				fileName += "_";
				_itoa_s(year, mas, 25, 10);
				fileName += mas;
				fileName += ".txt";

				setCursor(35, 9);
				setColor(Magenta, Black);
				cout << "************KINDLY ENTER DETAILS FOR CURRENT MONTH RENTAGE BELOW************** " << "\n";
				//cout << fileName << "\n";
				setRecieptData(currentMonths);

				string FileDetail = ak_user.login + "/" + fileName;
				writeF.open(FileDetail);
				if (writeF.is_open())
				{
					writeF << currentMonths.hotWater << " " << currentMonths.coldWater << " " << currentMonths.gas << " "
						<< currentMonths.electricity << " " << currentMonths.heating << " " << currentMonths.elevator << " " <<
						currentMonths.cleaning << " " << currentMonths.capitalService;

					/*writeF << currentMonths.hotWaterConsumption << " " << currentMonths.coldWaterConsumption << " " << currentMonths.gasConsumption << " "
						<< currentMonths.electricityConsumption << " " << currentMonths.heatingConsumption << " " << currentMonths.elevatorConsumption << " " <<
						currentMonths.cleaningConsumption << " " << currentMonths.capitalServiceConsumption;*/
					writeF.close();
				}

				time_t rtime1;
				time(&rtime1);
				tm previousTime;
				localtime_s(&previousTime, &rtime1);
				int pre_previousMonth, year1;
				pre_previousMonth = previousTime.tm_mon;//previous month file
				year1 = previousTime.tm_year + 1900;

				char* array = new char[25];
				string fileName2 = ".";
				_itoa_s(pre_previousMonth, array, 25, 10);
				//UserFile += ak_user.login;
				fileName2 += "\\";
				fileName2 += array;
				fileName2 += "_";
				_itoa_s(year1, array, 100, 10);
				fileName2 += array;
				fileName2 += ".txt";
				setCursor(42, 20);
				setColor(Green, Black);
				cout << "************DETAILS FOR PREVIOUS MONTH RENTAGE****************** " << "\n";
				//setCursor(62, 10);
				cout << "\n";
				//cout << fileName2 << "\n";
				setRecieptData(previousMonths);

				string FileDetails = ak_user.login + "/" + fileName2;
				writeF.open(FileDetails);
				if (writeF.is_open())
				{


					writeF << previousMonths.hotWater << " " << previousMonths.coldWater << " " << previousMonths.gas << " "
						<< previousMonths.electricity << " " << previousMonths.heating << " " << previousMonths.elevator << " " <<
						previousMonths.cleaning << " " << previousMonths.capitalService;

					/*	writeF << currentMonths.hotWaterConsumption << " " << currentMonths.coldWaterConsumption << " " << currentMonths.gasConsumption << " "
							<< currentMonths.electricityConsumption << " " << currentMonths.heatingConsumption << " " << currentMonths.elevatorConsumption << " " <<
							currentMonths.cleaningConsumption << " " << currentMonths.capitalServiceConsumption;
						writeF.close();*/

				}

				apartment.output();
				compareRentData(currentMonths, previousMonths);
				/*bill.compareRentData(currentMonths, previousMonths);*/

			}

		}

		else if (index == 1)
		{

			// cout << "Authorization\n";
			setCursor(42, 8);
			setColor(LightBlue, Black);
			cout << "LOGIN: ";
			cin >> ak_user.login;
			setCursor(42, 10);
			ifstream readF("user.txt");
			system("cls");
			if (readF.is_open())
			{
				isCorrect = false;
				while (!readF.eof())
				{

					readF >> temp.login >> temp.pass >> ak_user.progress;
					if (temp.login.compare(ak_user.login) == 0)
					{
						setCursor(42, 12);
						//cout << "login accepted!" <<"\n";
						isCorrect = true;
						break;
					}

				}
				readF.close();
				if (isCorrect)
				{
					isCorrect = false;
					do
					{
						setColor(LightCyan, Black);
						setCursor(42, 9);
						cout << "PASSWORD: ";
						cin >> ak_user.pass;
						setCursor(42, 10);
						if (temp.pass.compare(ak_user.pass) == 0)
						{
							setCursor(42, 13);
							setColor(Cyan, Black);
							cout << " LOGIN & PASSWORD ARE CORRECT, WELCOME!!";
							isCorrect = true;
							Sleep(timeToSleep);
							system("cls");
							setCursor(42, 9);
							setColor(DarkGray, Black);
							cout << "WELCOME TO HOME RENTAGE CALCULATION PROJECT" << "\n";
						}
						else
						{
							setCursor(42, 9);
							cout << "login not correct!\n";
							isCorrect = false;
							setCursor(42, 15);
							cout << "Enter parol ";
							cin >> ak_user.pass;
							Sleep(timeToSleep);
							system("cls");
						}
					} while (!isCorrect);
					Sleep(timeToSleep);
					system("cls");
					time_t rtime1;
					time(&rtime1);
					tm previousTime;
					localtime_s(&previousTime, &rtime1);
					int pre_previousMonth, year1;
					pre_previousMonth = previousTime.tm_mon;//previous month file
					year1 = previousTime.tm_year + 1900;

					char* array = new char[25];
					string fileName2 = ".";
					_itoa_s(pre_previousMonth, array, 25, 10);
					//UserFile += ak_user.login;
					fileName2 += "\\";
					fileName2 += array;
					fileName2 += "_";
					_itoa_s(year1, array, 100, 10);
					fileName2 += array;
					fileName2 += ".txt";
					string FileDetails = ak_user.login + "/" + fileName2;
					readF.open(FileDetails);
					if (readF.is_open())
					{

						/*readF >>currentMonths.hotWaterConsumption >> currentMonths.coldWaterConsumption >> currentMonths.gasConsumption  >>
							 currentMonths.electricityConsumption >> currentMonths.heatingConsumption >> currentMonths.elevatorConsumption >>
							currentMonths.cleaningConsumption >> currentMonths.capitalServiceConsumption;*/

						readF >> previousMonths.hotWater >> previousMonths.coldWater >> previousMonths.gas
							>> previousMonths.electricity >> previousMonths.heating >> previousMonths.elevator >>
							previousMonths.cleaning >> previousMonths.capitalService;
						setColor(Cyan, Black);
						cout << "************DETAILS FOR PREVIOUS MONTH RENTAGE****************** " << "\n";
						cout << " \nhot water: $" << previousMonths.hotWater;
						cout << " \ncold water: $" << previousMonths.coldWater << "\n";
						cout << " \nGas : $" << previousMonths.gas << "\n";
						cout << " \nelectricity : $" << previousMonths.electricity << "\n";
						cout << " \nheating usage : $" << previousMonths.heating << "\n";
						cout << " \nelevator usage : $" << previousMonths.elevator << "\n";
						cout << " \ncleaning service : $" << previousMonths.cleaning << "\n";
						cout << " \ncapital service usage: $" << previousMonths.capitalService << "\n";
						readF.close();
					}
					else
					{
						do
						{
							pre_previousMonth--;
							_itoa_s(pre_previousMonth, array, 25, 10);
							fileName2 += "\\";
							fileName2 += array;
							fileName2 += "_";
							_itoa_s(year1, array, 25, 10);
							fileName2 += array;
							fileName2 += ".txt";
							/*cout << "billing period from user - " << UserFile << "\n";*/
							readF.open(ak_user.login + "/" + fileName2);
						} while (!readF.is_open());

						readF >> previousMonths.hotWater >> previousMonths.coldWater >> previousMonths.gas
							>> previousMonths.electricity >> previousMonths.heating >> previousMonths.elevator >>
							previousMonths.cleaning >> previousMonths.capitalService;
						setColor(Cyan, Black);
						cout << "*********Previous Month detail**************\n";
						cout << " \nhot water: $" << previousMonths.hotWater;
						cout << " \ncold water: $" << previousMonths.coldWater << "\n";
						cout << " \nGas : $" << previousMonths.gas << "\n";
						cout << " \nelectricity : $" << previousMonths.electricity << "\n";
						cout << " \nheating usage : $" << previousMonths.heating << "\n";
						cout << " \nelevator usage : $" << previousMonths.elevator << "\n";
						cout << " \ncleaning service : $" << previousMonths.cleaning << "\n";
						cout << " \ncapital service usage: $" << previousMonths.capitalService << "\n";
						readF.close();
					}
					//_mkdir(ak_user.login.c_str()); //with the help of direct.h library we are creating file with user detail
					string path1 = ak_user.login + "userInfo.txt"; //creating name f our file
					string folds = ak_user.login + "/" + path1;
					readF.open(folds);
					if (readF.is_open())
					{
						readF >> actualTariff.user_count;
						setColor(Cyan, Black);
						cout << "******APARTMENT DETAILS*******" << actualTariff.user_count << "\n";
						readF.close();
					}

					cout << "Enter apartment area: ";
					cin >> apartment.Area;
					cout << "Enter number of occupants: "; //apartment.NumberOfOccuants
					cin >> apartment.NumberOfOccupants;
					cout << "Enter floor: ";
					cin >> apartment.FloorNumbers;
					ofstream writeF;
					time_t rtime;
					time(&rtime);
					tm currentTime;
					localtime_s(&currentTime, &rtime);
					int month, year;
					month = currentTime.tm_mon + 1;//current month file
					year = currentTime.tm_year + 1900;

					char* mas = new char[25];
					string fileName = "."; _itoa_s(month, mas, 25, 10);
					//UserFile += ak_user.login;
					fileName += "\\";
					fileName += mas;
					fileName += "_";
					_itoa_s(year, mas, 25, 10);
					fileName += mas;
					fileName += ".txt";

					setColor(Cyan, Black);
					cout << "************KINDLY ENTER DETAILS FOR CURRENT MONTH RENTAGE BELOW ****************** " << "\n";
					//cout << fileName1 << "\n";
					setRecieptData(currentMonths);
					string FileDetail = ak_user.login + "/" + fileName;
					writeF.open(FileDetail);
					if (writeF.is_open())
					{
						writeF << currentMonths.hotWater << " " << currentMonths.coldWater << " " << currentMonths.gas << " "
							<< currentMonths.electricity << " " << currentMonths.heating << " " << currentMonths.elevator << " " <<
							currentMonths.cleaning << " " << currentMonths.capitalService;

						/*writeF << currentMonths.hotWaterConsumption << " " << currentMonths.coldWaterConsumption << " " << currentMonths.gasConsumption << " "
							<< currentMonths.electricityConsumption << " " << currentMonths.heatingConsumption << " " << currentMonths.elevatorConsumption << " " <<
							currentMonths.cleaningConsumption << " " << currentMonths.capitalServiceConsumption;*/
						writeF.close();
					}

					setColor(Cyan, Black);
					cout << "!!Comparison between previous and current Months rentage below!! " << "\n";
					apartment.output();
					compareRentData(currentMonths, previousMonths);
					//bill.compareRentData(currentMonths, previousMonths);
				}

			}
			else
			{
				setCursor(46, 13);
				cout << "login not correct";
				isCorrect = false;
			}
		}
		else
		{
			setCursor(46, 13);
			cout << "\nGOODBYE, SEE YOU SOME OTHER TIME!!";
			break;
		}

	} while (!isCorrect);
	/*Sleep(timeToSleep);
	system("cls");*/


	return 0;

}