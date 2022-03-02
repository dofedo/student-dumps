#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>

#define size 10
using namespace std;
///////////////////////////////////////////////////////////////////
int scounter=-1;

struct edu
{
	string field;
	unsigned int term;
	unsigned int avr;
	unsigned int id;
	
};

struct student 
{
	string fname;
	string lname;
	unsigned int nId;		//  persons national id
	edu data;
};

struct student account[size];
///////////////////////////////////////////////////////////////////////////

int counter=-1;

struct city {
	string c;
	unsigned int ccdoe;
};

struct address {
	string city;
	unsigned int citycdoe;
};

struct name {
	string first;
	string last; 
};

struct tel {
	unsigned code;
	unsigned telnum;
};

struct contact  {
	 tel ptel;
   	 name pname;
	unsigned int p_id;		//persons nation id
	 address cityname;
};

struct city cities[5]={{"hamedan",111},{"tehran",222},{"tabriz",333},{"shiraz",444},{"esfahan",555}};

struct contact contacts[size];
///////////////////////////////////////////////////////////////
void fmain();
void fmenu();
void f_menu();
int f_indId(int id);
int findId(int id);

void fenter(int index) {
	cout <<"\nplease fill all options:\n\n";
	cout <<"name: "; cin >> account[index].fname;
	cout <<"last name: "; cin >> account[index].lname;
	cout <<"student id: "; cin >> account[index].data.id;
	cout <<"enter your field: "; cin >>account[index].data.field;
	cout <<"enter your degree(term): "; cin >> account[index].data.term;
//	cout <<"your national id: "; cin >>account[index].nId;
	cout <<"enter your average in last term: "; cin >>account[index].data.avr;
}

void fenter2(int index) {
	cout <<"name :"<<account[index].fname;
	cout <<"\nlast name: "<<account[index].lname;
	cout <<"\nstudent id: "; cin >> account[index].data.id;
	cout <<"enter your field: "; cin >>account[index].data.field;
	cout <<"enter your degree(term): "; cin >> account[index].data.term;
//	cout <<"your national id: "; cin >>account[index].nId;
	cout <<"enter your average in last term: "; cin >>account[index].data.avr;
	
}

void fadd() {
	int index=scounter+1;
	int nId;
	int temp;
	if (index < size)
	{
		cout <<"your national id: "; cin >>nId;
	temp=f_indId(nId);
	if (temp == -1)
	{
		temp=findId(nId);
		if (temp == -1)
		{
			account[index].nId=nId;
			fenter(index);
		}
		else
		{
			account[index].fname=contacts[temp].pname.first;
			account[index].lname=contacts[temp].pname.last;
			fenter2(index);
		}
		
		cout <<"\nyour account added...";
		++scounter;
	}
		else cout<<"\nchange your id...\n";
		
		getch();
		system ("cls");
		fmenu();
	}
	else 
	{
		cout <<"\nlist is full...";
	getch();
		system ("cls");
		fmenu();
	}
	
}

int f_indId(int id) {
	int i;
	for (i=0; i<scounter+1; ++i)
	{
		if (account[i].nId == id) return i;
	}
	return -1;
}

int f_indId2(int id) {
	int i;
	for (i=0; i<scounter+1; ++i)
	{
		if (account[i].data.id == id) return i;
	}
	return -1;
}


void fshow(int index) {
        cout <<"\nname: "<< account[index].fname;
		cout <<"\nlast name: " <<account[index].lname;
		cout <<"\nnational id: " << account[index].nId;
		cout <<"\nyour id: " << account[index].data.id;
		cout <<"\nyou are in term: " << account[index].data.term;	
        cout <<"\nyour current field: " << account[index].data.field;
		cout <<"\nyour last average: " << account[index].data.avr;	
		cout <<"\n";
	}
	
	void fedit2() {
	if (scounter==-1) 
	{
		cout <<"\nlist is empty...";
		getch();
		system ("cls");
		fmenu();
		}
	else
	{
		int index;
	unsigned int id;
	cout <<"\nenter your student id: "; cin >>id;
	index=f_indId2(id);
	if (index==-1)
	{
		cout <<"\nthere is no this id...";
		getch();
		system ("cls");
		fmenu();
	}
	else
	{
		cout <<"\nyour current account:\n";
		fshow(index);
		fenter(index);
		cout <<"\nyour account edited...";
		getch();
		system ("cls");
		fmenu();
	}
	}
	
}

void fedit() {
	if (scounter==-1) 
	{
		cout <<"\nlist is empty...";
		getch();
		system ("cls");
		fmenu();
		}
	else
	{
		int index;
	unsigned int id;
	cout <<"\nenter your national id: "; cin >>id;
	index=f_indId(id);
	if (index==-1)
	{
		cout <<"\nthere is no this id...";
		getch();
		system ("cls");
		fmenu();
	}
	else
	{
		cout <<"\nyour current account:\n";
		fshow(index);
		fenter(index);
		cout <<"\nyour account edited...";
		getch();
		system ("cls");
		fmenu();
	}
	}
	
}


int callbyname() {
	int i;
	string fname;
	string lname;
	cout <<"\nenter your first name: "; cin >>fname;
	cout <<"enter your last name: "; cin >>lname;
	for (i=0; i<scounter+1; ++i)
	{
		if (account[i].fname==fname && account[i].lname==lname)  return i;
	}
	return -1;
}

int callbyNid() {
	int i;
	unsigned int id;
	cout <<"\nenter your national id: "; cin >>id;
	for (i=0; i<scounter+1; ++i)
	{
		if (account[i].nId==id) return i;
	}
	return -1;
}

int callbySid() {
	int i;
	unsigned int id;
	cout <<"\nenter student id: "; cin >>id;
	for (i=0; i<scounter+1; ++i)
	{
		if (account[i].data.id==id) return i;
	}
	return -1;
}


void help(int index) {
	if (index == -1) cout <<"\nyour accont isn't in the list...";
			   else fshow(index);
			   	getch();
	 	        system ("cls");
	 	    	fmenu();
}

void Fshow() {
	int choise;
	char input;
	if (scounter==-1)
	{
		cout <<"list is empty...";
		getch();
		system ("cls");
		fmenu();
	}
	else
	{
		cout <<"show by: 1.name   2.national id   3.student id    0.back to menu\n";
		input = getche();
		switch (input)
		{
			case '1':
			   choise=callbyname();
			   help(choise);
			   	break;
	 	    	
	 	    case '2':
			 	choise=callbyNid();
			 	 help(choise);
			 	break;
			case '3':
			 	choise=callbySid();
				 help(choise);	
				 break;
			case '0':
				system("cls");
				fmenu(); 
			 	break;
			 default:
			 	cout <<"invalid input...";
			 	getch();
		system ("cls");
		fmenu();
		break;
				 }
			
		}
	return;
	}

void fSearch() {
    int i,j=0;
	string field; // city code
	if (scounter==-1)
	{
		cout <<"\nlist is empty...";
		getch();
		system ("cls");
		fmenu();
		return;
	}
	else
	{
			cout <<"\n!you can see all of the students in a special field by entering the name of that field..\n";
	cout <<"\nenter name of field: "; cin >>field;
	
	for (i=0; i<scounter+1; ++i)
	{
		if (account[i].data.field == field)
		{
			++j;
			fshow (i);
			cout <<"\n-----------------------------------------------------------------------------\n";
		}	}
	if (j==0) cout <<"\nthere is no contact this city...\n";
	}
	getch();
	system("cls");
	fmenu();
return;
}

void fbest () {
		if (scounter==-1)
	{
		cout <<"\nlist is empty...";
		getch();
		system ("cls");
		fmenu();
		return;
	}
	
	int max1=0,m1=-1;
	int max2=0,m2=-1;
	int max3=0,m3=-1;
	int i;
	for (i=0; i<scounter+1; ++i)
	{
		if (account[i].data.avr>max3)
		{
			max1=max2;
			max2=max3;
			max3=account[i].data.avr;
			m1=m2;
			m2=m3;
			m3=i;
		}
	}
	if (m3 !=-1)
	{	cout << "first***";
	fshow(m3);
	}
    if (m2 !=-1)
    {
    	cout << "secound**";
	fshow(m2);
	}
		if (m1 !=-1)
		{
			cout << "third*";
	fshow(m1);
		}
		
	getch();
		system ("cls");
		fmenu();
		return;
}

void fmanage(char option) {
	char choise;
	switch(option)
	{
		case '1':
			fadd();
			break;
		case '2':
			cout <<"\nedit the account with: national id(1)      student id(2)"; choise=getche();
			if (choise == '1') fedit();
			else if (choise == '2') fedit2();
			else
			{
			 cout <<"\ninvalid input...";
		 getch();
		 system("cls");
		 fmenu(); 
			}
			break;
		case '3':
			Fshow();
			break;
		case '4':	
		    fSearch();
		    break;
		case '5':
			fbest();
			break;
		case '0':
			fmain();
		 
		 default :
		 	cout <<"invalid input...";
			 	getch();
		system ("cls");
		fmenu();
		   
	}
	return;
}

void fmenu() {
	char option;
	
	cout <<"\n1.add\t\t2.edit\t\t3.show\t\t4.students in a special field\t\t5.best students\t\t0.exit";
	cout <<"\n\nenter your choise: ";
	option=getche();
	system("cls");
	fmanage(option);
	return;
}

void f_menu();

void entercity(int index) {
	int in;
	cout <<"\nenter your city(code): \n";
	cout <<"1.hamedan(111)\t\t2.tehran(222)\t\t3.tabriz(333)\t\t4.shiraz(444)\t\t5.esfahan(555)\n? ";
	cin>>in;
	if (in>0 && in<6)
	{
		contacts[index].cityname.city = cities[in-1].c;
	contacts[index].cityname.citycdoe = cities[in-1].ccdoe;
	}
	else
	{
	cout <<"\ninvalid input...\n";
			getch();
	entercity(index);
	 } 

	return;
}

void f_enter(int index) {
	cout <<"\nplease fill all options:\n\n";
		cout <<"name: "; cin >> contacts[index].pname.first;
		cout <<"last name: "; cin >> contacts[index].pname.last;
		cout <<"code of your phone: "; cin >> contacts[index].ptel.code;
		cout <<"your phone number: "; cin >> contacts[index].ptel.telnum;
		//cout <<"your national id: "; cin >>account[index].p_id;
		entercity(index);
}

void f_enter2(int index) {
	cout <<"name: "<< contacts[index].pname.first;
		cout <<"last name: " << contacts[index].pname.last;
		cout <<"\ncode of your phone: "; cin >> contacts[index].ptel.code;
		cout <<"your phone number: "; cin >> contacts[index].ptel.telnum;
		//cout <<"your national id: "; cin >>account[index].p_id;
		entercity(index);
}

void f_add() {
	int index=counter+1;
	int nId;
	int temp;
	if (index < size)
	{
		cout <<"your national id: "; cin >>nId;
	temp=findId(nId);
	if (temp == -1)
	{
		temp=findId(nId);
		if (temp == -1)
		{
			contacts[index].p_id=nId;
			f_enter(index);
		}
		else
		{
			contacts[index].pname.first=account[temp].fname;
		contacts[index].pname.last=account[temp].lname;
			f_enter2(index);
		}
		
		cout <<"\nyour account added...";
		++counter;
	}
		else cout<<"\nchange your id...\n";
		
		getch();
		system ("cls");
		fmenu();
	}
	else 
	{
		cout <<"\nlist is full...";
	getch();
		system ("cls");
		f_menu();
	}
	
}

int findId(int id) {
	int i;
	for (i=0; i<counter+1; ++i)
	{
		if (contacts[i].p_id == id) return i;
	}
	return -1;
}

void f_show(int index) {
	cout <<"\nname: "<< contacts[index].pname.first;
	cout <<"\nlast name: " <<contacts[index].pname.last;
	cout <<"\ncode of your phone: " << contacts[index].ptel.code;
	cout <<"\nyour phone number: " << contacts[index].ptel.telnum;
	cout <<"\nyour national id: " << contacts[index].p_id;	
	cout <<"\nyour city name: " << contacts[index].cityname.city;
	cout <<"\nyour city code: " << contacts[index].cityname.citycdoe;	
}

void f_edit() {
	if (counter==-1) 
	{
		cout <<"\nlist is empty...";
		getch();
		system ("cls");
		f_menu();
		}
	else
	{
		int index;
	unsigned int id;
	cout <<"\nenter your national id: "; cin >>id;
	index=findId(id);
	if (index==-1)
	{
		cout <<"\nthere is no this id...";
		getch();
		system ("cls");
		f_menu();
	}
	else
	{
		cout <<"\nyour current account:\n";
		f_show(index);
		f_enter(index);
		cout <<"\nyour account edited...";
		getch();
		system ("cls");
		f_menu();
	}
	}
	
}


int callbynames() {
	int i;
	string fname;
	string lname;
	cout <<"\nenter your first name: "; cin >>fname;
	cout <<"enter your last name: "; cin >>lname;
	for (i=0; i<counter+1; ++i)
	{
		if (contacts[i].pname.first==fname && contacts[i].pname.last==lname)  return i;
	}
	return -1;
}

int callbyTell() {
	int i;
	unsigned int tell;
	cout <<"\nenter your phone number: "; cin >>tell;
	for (i=0; i<counter+1; ++i)
	{
		if (contacts[i].ptel.telnum==tell) return i;
	}
	return -1;
}

int callbyId() {
	int i;
	unsigned int id;
	cout <<"\nenter your national id: "; cin >>id;
	for (i=0; i<counter+1; ++i)
	{
		if (contacts[i].p_id==id) return i;
	}
	return -1;
}


void help2(int index) {
	if (index == -1) cout <<"\nyour accont isn't in the list...";
			   else f_show(index);
			   	getch();
	 	        system ("cls");
	 	    	f_menu();
}

void show() {
	int choise;
	char input;
	if (counter==-1)
	{
		cout <<"list is empty...";
		getch();
		system ("cls");
		f_menu();
	}
	else
	{
		cout <<"show by: 1.name   2.telephone number   3.national id    0.back to menu\n";
		input = getche();
		switch (input)
		{
			case '1':
			   choise=callbynames();
			   help2(choise);
			   	break;
	 	    	
	 	    case '2':
			 	choise=callbyTell();
				help2(choise);
			 	break;
			case '3':
			 	choise=callbyId();
				 help2(choise);	
				 break;
			case '0':
				system("cls");
				f_menu(); 
			 	break;
			 default:
			 	cout <<"invalid input...";
			 	getch();
		system ("cls");
		f_menu();
		break;
				 }
			
		}
	return;
	}

void cityCodeSearch() {
    int i,j=0;
	unsigned int ccode; // city code
	if (counter==-1)
	{
		cout <<"\nlist is empty...";
		getch();
		system ("cls");
		f_menu();
		return;
	}
	else
	{
		cout <<"\n!you can see all of the contacts in a city by entering the code of that city..\n";
		cout <<"\nenter code of your city: "; cin >>ccode;
	
		for (i=0; i<counter+1; ++i)
		{
			if (contacts[i].cityname.citycdoe == ccode)
			{
				++j;
				f_show (i);
				cout <<"\n-----------------------------------------------------------------------------\n";
			}	}
		if (j==0) cout <<"\nthere is no contact this city...\n";
		}
	getch();
	system("cls");
	f_menu();
return;
}

void f_manage(char option) {
	switch(option)
	{
		case '1':
			f_add();
			break;
		case '2':
			f_edit();
			break;
		case '3':
			show();
			break;
		case '4':	
		    cityCodeSearch();
		    break;
		case '0':
		 fmain();
		 default :
		 cout <<"\ninvalid input...";
		 getch();
		 system("cls");
		 f_menu();   
	}
	return;
}

void f_menu() {
	char option;
	
	cout <<"\n1.add\t\t2.edit\t\t3.show\t\t4.search in a spcial city\t\t0.exit";
	cout <<"\n\nenter your choise: ";
	option=getche();
	system("cls");
	f_manage(option);
	return;
}


void gsearch() {
	
	int id;
	int temp,temp2;
	
	cout <<"enter your id: "; cin >>id;
	temp = findId(id);
	temp2 =f_indId(id);
	if (temp == -1 && temp2 ==-1) 	cout <<"there is no this id in two lists...";
	else if(temp ==-1 && temp2 != -1)
	{
		fshow(temp2);
		cout <<"this id isn't in contacts list...\n";
	}
	else if(temp != -1 && temp2 ==-1)
	{
		f_show(temp);
			cout <<"this id isn't in students list...\n";	}
		else
		{
			f_show(temp);
				cout <<"\nyour id: " << account[temp2].data.id;
		cout <<"\nyou are in term: " << account[temp2].data.term;	
        cout <<"\nyour current field: " << account[temp2].data.field;
		cout <<"\nyour last average: " << account[temp2].data.avr;	
			}	
			
		getch();
		system ("cls");
		fmain();
}

void managethismenu(char in) {
	switch (in)
	{
		case '1' :
			f_menu();
			break;
		case '2' :
			fmenu();
			break;
		case '3' :
			gsearch();
			break;
		case '0' :
			return;
		default :
		cout <<"invalid input...";
			 	getch();
		system ("cls");
		fmain();
		break;	
				}
}

void fmain() {
	char in;
		cout <<"1.list of contacts\t\t2.student list\t\t3.search in two lists\t\t0.exit\n ";
	cout <<"enter your choise: "; in=getch();
	managethismenu(in);
}

using namespace std;

int main () {
	cout <<"hello, in this program you can enter accounts in two lists:\n 1.contact(public list) 2.studet list's and you can find a spcial contact that is in the one or either two lists.\n";

	fmain();
	return 0;
	
}

























