#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Doctor {
private:
	int ID;
	float Experience;
	char Hospital[40];
	char Location[30];
	char Specialist[30];
	char Time[30];
	float Rate;
	bool Availability;
	float Rating;

public:
	Doctor(int id=0,string loc = "", string spec = "", string t = "", float rate = 0, bool avail = 0, float rating = 0) {
		ID = id;
		strcpy_s(Location, loc.c_str());
		strcpy_s(Specialist, spec.c_str());
		strcpy_s(Time, t.c_str());

		Rate = rate;
		Availability = avail;
		Rating = rating;
	}
	void setID() {
		cout << "Enter your ID:\n" << endl;
		cin >> ID;
	}
	int getID() {
		return ID;
	}
	void setExperience() {
		cout << "Enter your years of experience: " << endl;
		cin >> Experience;
	}
	void setHospital() {
		string hos;
		cout << "Enter your Hospital Name: " << endl;
		cin >> hos;
		strcpy_s(Hospital, hos.c_str());

	}
	void setLoction() {
		string l;
		cout << "Enter your Location or City Name: " << endl;
		cin >> l;

		strcpy_s(Location, l.c_str());

	}
	void setSpecialist() {
		string spec;
		cout << "Enter your Specialization" << endl;
		cin >> spec;
		strcpy_s(Specialist, spec.c_str());

	}
	void setTimings() {
		string t;
		cout << "Enter your timings" << endl;
		cin >> t;
		strcpy_s(Time, t.c_str());
	}
	void setRate() {
		cout << "Enter your Hourly Rate:" << endl;
		cin >> Rate;
	}
	void setAvailability() {
		cout << "Are you available Now\nPress 1 for avaiable and 0 for unavaiable" << endl;
		cin >> Availability;
	}
	void setRating(float rating) {
		Rating = rating;
	}
	float getExperience() {
		return Experience;
	}
	char* getSpecialist() {
		return Specialist;
	}
	char* getHospital() {
		return Hospital;
	}
	char* getLoction() {
		return Location;
	}
	char* getTimings() {
		return Time;
	}
	float getRate() {
		return Rate;
	}
	bool getAvailability() {
		return Availability;
	}
	float getRating() {
		return Rating;
	}
	void Display() {
		cout << "Location: " << Location << endl;
		cout << "Specialization: " << Specialist << endl;
		cout << "Time: " << Time << endl;
		cout << "Hourly Rate: " << Rate << endl;
		cout << "Availability: " << Availability << endl;
		cout << "Rating out of five(5): " << Rating << endl;
	}
	
};

class Patient :public Doctor {
private:
	char MedicalData[40];
	float AmountDue;
	float Rating;
	char Review[200];
public:
	Patient(string MD = "", float AD = 0, float rating = 0, string review = "") :Doctor() {
		strcpy_s(MedicalData, MD.c_str());
		AmountDue = AD;
		Rating = rating;
		strcpy_s(Review, review.c_str());

	}
	void setMedicalData(string MD) {
		strcpy_s(MedicalData, MD.c_str());

	}
	void setAmountDue(float AD) {
		AmountDue = AD;

	}
	void setRating(float rating) {
		Rating = rating;

	}
	void setReview(string review) {
		strcpy_s(Review, review.c_str());

	}
	char* getMedicalData() {
		return MedicalData;
	}
	float getAmountDue() {
		return AmountDue;
	}
	float getRating() {
		return Rating;
	}
	char* getReview() {
		return Review;
	}
	void Display() {
		cout << "Medical Data: " << MedicalData << endl;
		cout << "Amount Due: " << AmountDue << endl;
		cout << "Rating: " << Rating << endl;
		cout << "Review: " << Review << endl;
	}
	void searchDoctorBySpeciality() {
		string s1; bool flag=false;
		Doctor obj;
		cout << "Please Enter correct spell\ni.e. Gynecologist\n"
			<< "Dermatologist\nOncologist\nOrthopedic" << endl;
		cin >> s1;
		ifstream fin("Doctor.bin", ios::binary);
		while (fin.read((char*)&obj, sizeof(obj)))
		{
			if (s1 == obj.getSpecialist()) {
				cout << "Loading...\nDoctor found\n" << endl;
				obj.Display();
				flag = true;
				break;

			}

		}
		if (!flag) {
			cout << "Doctor Not found..." << endl;
		}

	}

	void searchDoctorByLocation() {
		string s1; bool flag = false;
		Doctor obj;
		cout << "Please Enter correct spell\ni.e. Karachi\n"
			<< "Islamabad\nLahore\nMultan" << endl;
		cin >> s1;
		ifstream fin("Doctor.bin", ios::binary);
		while (fin.read((char*)&obj, sizeof(obj)))
		{
			if (s1 == obj.getLoction()) {
				cout << "Loading...\nDoctor found\n" << endl;
				obj.Display();
				flag = true;
				break;

			}

		}
		if (!flag) {
			cout << "Doctor Not found..." << endl;
		}

	}
	void searchDoctorByHospital() {
		string s1; bool flag = false;
		Doctor obj;
		cout << "Please Enter correct spell\ni.e. Agha_Khan\n"
			<< "Quaid_E_Azam\nShifa\nNishter" << endl;
		cin >> s1;
		ifstream fin("Doctor.bin", ios::binary);
		while (fin.read((char*)&obj, sizeof(obj)))
		{
			if (s1 == obj.getHospital()) {
				cout << "Loading...\nDoctor found\n" << endl;
				obj.Display();
				flag = true;
				break;

			}

		}
		if (!flag) {
			cout << "Doctor Not found..." << endl;
		}

	}
};

class Register:public Doctor {
private:
	char CNIC[14];
	//string Email;
	char Password[9];
public:
	Register(string cnic, string pass):Doctor() {
		strcpy_s(CNIC, cnic.c_str());
		strcpy_s(Password, pass.c_str());

	}
	void  setCNIC(string ic) {
		strcpy_s(CNIC, ic.c_str());

	}

	void setPassword(string p) {
		strcpy_s(Password, p.c_str());

	}
	char* getCNIC() {
		return CNIC;
	}
	char* getPassword() {
		return Password;
	}
	Register RegisterUser(char check) {
		Register temp("", "");
		if (check == 'p' || check == 'P') {
			
			cout << "Enter CNIC without Dashes \n i.e. 38XXXXXXXXXXX " << endl;
			cin >> temp.CNIC;

			cout << "Create Password\n NOTE: your password must contain 8 characters and a minimum of one special characteruppercase, lowercase, and the numeric digit" << endl; \
				cin >> temp.Password;
			CheckCNIC(temp);
			CheckPassword(temp);
			return temp;

	}
		else if (check == 'd' || check == 'D') {
			
			cout << "Enter CNIC without Dashes \n i.e. 38XXXXXXXXXXX " << endl;
			cin >> temp.CNIC;

			cout << "Create Passwor\n NOTE: your password must contain 8 characters and a minimum of one special characteruppercase, lowercase, and the numeric digit" << endl; \
				cin >> temp.Password;
			CheckCNIC(temp);
			CheckPassword(temp);
			cout << "We need some extra information" << endl;
			Doctor::setAvailability();
			Doctor::setExperience();
			Doctor::setHospital();
			Doctor::setLoction();
			Doctor::setRate();
			Doctor::setSpecialist();
			Doctor::setTimings();
			return temp;

		}
	
	}
	void CheckCNIC(Register obj) {
		int count = 0;
		bool WrongNumCheck = false;

		for (int i = 0; obj.getCNIC()[i] != '\0'; i++) { count++; }

		for (int i = 0; obj.getCNIC()[i] != '\0'; i++) {

			if (int(obj.getCNIC()[i]) < 48 || int(obj.getCNIC()[i]) > 57) { WrongNumCheck = true; break; }


		}
		if (count != 13 || WrongNumCheck) {
			cout << "EROR!!!  Invalid CNIC" << endl;
			cout << "Enter Again!!\nEnter CNIC without Dashes \n i.e. 38XXXXXXXXXXX " << endl;
			Register check("", "");
			string s;
			cin >> s;
			check.setCNIC(s);
			CheckCNIC(check);
		}
	}
	void CheckPassword(Register obj) {
		int count = 0;
		bool NumCheck = false, UperCaseCheck = false,
			lowerCaseCheck = false, specialCheck = false;

		for (int i = 0; obj.getPassword()[i] != '\0'; i++) {
			if (int(obj.getPassword()[i]) >= 48 && int(obj.getPassword()[i]) <= 57) { NumCheck = true; }

			if (int(obj.getPassword()[i]) >= 32 && int(obj.getPassword()[i]) <= 47) { specialCheck = true; }


			if (int(obj.getPassword()[i]) >= 97 && int(obj.getPassword()[i]) <= 122) { lowerCaseCheck = true; }

			if (int(obj.getPassword()[i]) >= 65 && int(obj.getPassword()[i]) <= 90) { UperCaseCheck = true; }

			count++;

		}

		if (count != 8 || !lowerCaseCheck || !UperCaseCheck || !NumCheck || !specialCheck) {

			cout << "EROR!!!  Invalid Password\nEnter password again" << endl;
			cout << "Create Passwor\n NOTE: your password must contain 8 characters\n and a minimum of one special character uppercase, lowercase, and the numeric digit" << endl; \
				Register check("","");
			string s1;
			cin >> s1;
				check.setPassword(s1);
			CheckPassword(check);

		}
	}

	void Display() {
		cout << "Registered CNIC is: " << CNIC << endl;
		cout << "Registered Password is: " << Password << endl;
	}

};

void write(string file_name, Register obj) {
	ofstream fout(file_name, ios::app | ios::binary);
	fout.write((char*)&obj, sizeof(obj));
	fout.close();
}
void read(string file_name){
	Register temp("", "");
	ifstream fin(file_name, ios::binary);
	while (fin.read((char*)&temp, sizeof(temp)))
		temp.Display();


	fin.close();
}

bool update(string file_Name, int id, string update){
	fstream my_file(file_Name, ios::in | ios::out | ios::binary);
	Doctor temp;
	bool flag = false;
	while (my_file.read((char*)&temp, sizeof(temp)))
	{	
		if (temp.getID() == id)
		{
			
			

				strcpy_s(temp.getLoction(), sizeof(update.c_str()), update.c_str());
				int a = my_file.tellg();
				int size = sizeof(temp);
				my_file.seekp(a - size);
				my_file.write((char*)&temp, size);
				flag = true;
				break;
			
		}
	}
	my_file.close();
	return flag;
}
bool Delete(string filename, int id) {
	fstream file(filename, ios::in | ios::out | ios::binary);
	fstream taskfile("temp.bin", ios::binary | ios::in | ios::out | ios::app);
	 Doctor obj;
	bool flag = false;
	while (file.read((char*)&obj, sizeof(obj))) {
		if (obj.getID() == id) {
			flag = false;
		}
		else {
			flag = true;
			taskfile.write((char*)&obj, sizeof(obj));
		}
	}
	file.close();
	taskfile.close();
	remove(filename.c_str());
	rename("temp.bin", filename.c_str());

	return flag;
}

class Login :public Register {

public:
	Login() :Register("", "") {

	}

	bool VerifyPatient() {
		cout << "*******************************************" << endl;
		cout << "		Patient	LOGIN		" << endl;
		cout << "*******************************************\n\n" << endl;
		string cnic, password;
		cout << "Enter User Name:..." << endl;
		cin >> cnic;


		cout << "Enter your Password\n" << endl;
		cin >> password;

		Register obj("", "");
		bool flag = false;

		ifstream fin("Patient.bin", ios::binary);
		while (fin.read((char*)&obj, sizeof(obj)))
		{
			if (cnic == obj.getCNIC() && password == obj.getPassword()) {
				cout << "Loading...\n" << endl;
				cout << "**Patient Login Successfully**" << endl;
				flag = true;
				break;

			}

		}
		if (!flag) {
			cout << "ERROR!!!!!\n\nNO Record Found\n" << endl;

		}

		fin.close();
		return flag;

	}
	bool verifyAdmin() {
		cout << "*******************************************" << endl;
		cout << "		Admin	LOGIN		" << endl;
		cout << "*******************************************\n\n" << endl;
		string cnic, password;
		bool flag = false;
		cout << "Enter User Name:..." << endl;
		cin >> cnic;
		cout << "Enter your Password\n" << endl;
		cin >> password;
		if (cnic == "admin" && password == "Fast*001") {
			cout << "Admin Login successfully..." << endl;
			flag = true;
		}
		else {
			cout << "ERROR!!!\n you entered invalid User name or password\nPlease try again ..." << endl;
			//verifyAdmin();
		}
		return flag;
	}
	bool verifyDoctor() {
		cout << "*******************************************" << endl;
		cout << "		Doctor's	LOGIN		" << endl;
		cout << "*******************************************\n\n" << endl;
		string cnic, password;
		cout << "Enter User Name:..." << endl;
		cin >> cnic;


		cout << "Enter your Password\n" << endl;
		cin >> password;

		Register obj("", "");
		bool flag = false;

		ifstream fin("Doctor.bin", ios::binary);
		while (fin.read((char*)&obj, sizeof(obj)))
		{
			if (cnic == obj.getCNIC() && password == obj.getPassword()) {
				cout << "Loading...\n" << endl;
				cout << "**Doctor's Login Successfully**" << endl;
				flag = true;
				break;

			}

		}
		if (!flag) {
			cout << "ERROR!!!!!\n\nNO Record Found\n" << endl;

		}

		fin.close();
		return flag;

	}
};


class Menu :public Login, public Register,public Patient {
public:
	Menu(string id = "", string pass = "") :Register(id, pass), Login(),Patient() {

	}
	void MainMenu() {
		int choice;
		cout << "ENTER YOUR CHOICE: " << endl;
		cout << "1.Admin Login\n2.Patient Login\n3.Doctor Login\n4.Register\n" << endl;
		cin >> choice;
		switch (choice) {
		case 1:

			//cout << "admin login \n";
			if (verifyAdmin()) {
				AdminMenu();
			}
			else {
				cout << "\nCannot login admin" << endl;
				MainMenu();
			}

			break;
		case 2:
			///	cout << "Patient login" << endl;
			if (VerifyPatient()) {
				PatientMenu();
			}
			else {
				cout << "\ncannot login patient..." << endl;
				MainMenu();
			}
			break;
		case 3:
			//cout << "Doctor Login" << endl;
			if (verifyDoctor()) {
				
				DoctorMenu();
			}
			else {
				cout << "Cannot login Doctor" << endl;
				MainMenu();
			}
			break;
		case 4:
			int choice;
			cout << "Enter your Choice\n" << endl;
			cout << "1.Patient Register\n2.Doctor Register\n0.Main Menu\n" << endl;
			cin >> choice;
			switch (choice) {
			case 1:
				
				write("Patient.bin", Register::RegisterUser('p'));
				cout << "Please Login again..." << endl;
				MainMenu();
				break;
			case 2:
				write("Doctor.bin", Register::RegisterUser('d'));
				cout << "Please Login again..." << endl;
				MainMenu();
				break;
			case 0:
				Menu::MainMenu();
				break;
			default:
				cout << "ERROR!!! please try again" << endl;
				Menu::MainMenu();
			}
		default:
			cout << "ERROR!!! please try again" << endl;
			Menu::MainMenu();
		}

	}
	void PatientMenu() {
		int n;
		cout << "\n2.Reset Password\n3.Search Doctor\n4.Doctor Avaiability and Charges\n"
			<< "5.Book and cancel appointment\n6.Update appointment Details\n7.Edit Profile"
			<< "\n8. Check all appoinment\n9. Recharge Account\n0. Main Menu " << endl;
		cout << "ENTER YOUR CHOICE: " << endl;
		cin >> n;
		switch (n) {
		
		case 2:
			cout << "*******************************************" << endl;
			cout << "			Reset Password	" << endl;
			cout << "*******************************************\n\n" << endl;
			PatientMenu();
			break;
		case 3:
			int ch;
			cout << "*******************************************" << endl;
			cout << "			Search Doctor	" << endl;
			cout << "*******************************************\n\n" << endl;
			cout << "How you want to search\n" << endl;
			cout << "1.search by Location\n2.search by Hospital\n3.search by speciality\n0.MainMenu/logout" << endl;
			cin >> ch;
			switch (ch) {
			case 1:
				Patient::searchDoctorByLocation();

				break;
			case 2:
				Patient::searchDoctorByHospital();
				break;
			case 3:
				Patient::searchDoctorBySpeciality();
				break;
			case 0:
				MainMenu();
				break;
			default:
				cout << "ERROR!!!!\nYou entered invalide Number\n please try again..." << endl;
				PatientMenu();
			}
			PatientMenu();
			break;
		case 4:
			cout << "*******************************************" << endl;
			cout << "    Doctor Availability and Charges    " << endl;
			cout << "*******************************************\n\n" << endl;
			PatientMenu();
			break;
		case 5:
			cout << "*******************************************" << endl;
			cout << "	Book and Cancel Appointment	" << endl;
			cout << "*******************************************\n\n" << endl;
			PatientMenu();
			break;
		case 6:
			cout << "*******************************************" << endl;
			cout << "    Update appointment Details  	" << endl;
			cout << "*******************************************\n\n" << endl;
			PatientMenu();
			break;
		case 7:
			cout << "*******************************************" << endl;
			cout << "		Edit Profile    	" << endl;
			cout << "*******************************************\n\n" << endl;
			PatientMenu();
			break;
		case 8:
			cout << "*******************************************" << endl;
			cout << "  Check All Appointments	" << endl;
			cout << "*******************************************\n\n" << endl;
			PatientMenu();
			break;
		case 9:
			cout << "*******************************************" << endl;
			cout << "		Recharge Account	" << endl;
			cout << "*******************************************\n\n" << endl;
			PatientMenu();
			break;
		case 0:
			cout << "*******************************************" << endl;
			cout << "		Main Menu			" << endl;
			cout << "*******************************************\n\n" << endl;
			MainMenu();
			break;
		default:
			cout << "ERROR!!!!!!!!!!!\nYou Entered an Ivalid number\nPlease try Again..." << endl;
			PatientMenu();
		}
		PatientMenu();
	}

	
	void DoctorMenu() {
		int n;
		cout << "ENTER YOUR CHOICE: " << endl;
		cout << "";
		cin >> n;
		DoctorMenu();

	}
	void AdminMenu() {
		int n;
		cout << "ENTER YOUR CHOICE: " << endl;
		cout << "1.Add Doctor\n2.Edit Doctor's Data\n3.Delete Doctor's Data\n0.Logout or main menu" << endl;
		cin >> n;
		switch (n) {
		case 1:
			write("Doctor.bin", Register::RegisterUser('d'));
			break;
	
		case 3:
			cout << "Enter ID of Doctor whose data you want to delete\n" << endl;
			int id;
			cin >> id;
			Delete("Doctor.bin", id);
			break;
		case 4:
			cout << "!!!!!		View all patient Data		!!!!!!" << endl;

			break;

		case 0:
			MainMenu();
			break;
		default:
			cout << "you Entered an invalid NUmber\nplease try again..." << endl;
			AdminMenu();
		}

		AdminMenu();
	}
};
class Admin:public Doctor,public Patient {
private:
public:
	void viewPatientData() {

	}

};