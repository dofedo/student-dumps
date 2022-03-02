#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void wellcome();

class ratio
{
	private:
		int p,denominator;
		
	public:
		ratio (int part=0, int den=1) { setRatio(part, den); }
		void setRatio (int part, int den);
		void show();
		ratio& operator+= (ratio num);
		ratio& operator-= (ratio num);
		ratio operator/ (ratio num2);
		bool operator!= (ratio num);
		bool operator< (ratio num);
		bool operator> (ratio num);
		bool operator>= (ratio num);
		bool operator<= (ratio num);
		ratio& operator--();
		ratio operator--(int);
		ratio& operator/= (ratio num2);

	//	ratio getRatio ();
		
		};
		///////////////////////////////////////////////////////////////
/*	ratio& ratio::getRatio()
		{
			return *this;
		}
*/	
        ratio& ratio::operator/= (ratio num2)
        {
        		this->p=this->p*num2.denominator;
			this->denominator=this->denominator*num2.p;
			return *this;
		}

        ratio& ratio::operator--()
        {
        	this->p-this->denominator;
        	return *this;
		}
		
		ratio ratio::operator--(int)
		{
			ratio temp = *this;
			this->p = this->p - this->denominator;
			return temp;
			
		}


    bool ratio :: operator!= (ratio num)
    {
    	return (this->p != num.p || this->denominator != num.p);
	}
    ///////////////////////////////////////////////////////////////////////////////
     bool ratio :: operator< (ratio num)
    {
    	return (this->p * num.denominator <  this->denominator * num.p );
	}
	//////////////////////////////////////////////////////////////////////////////
	
	     bool ratio :: operator<= (ratio num)
    {
    	return (this->p * num.denominator <=  this->denominator * num.p );
	}
	//////////////////////////////////////////////////////////////////////////////
	     bool ratio :: operator>= (ratio num)
    {
    	return (this->p * num.denominator >=  this->denominator * num.p );
	}
	/////////////////////////////////////////////////////////////////////////////
	 bool ratio :: operator> (ratio num)
    {
    	return (this->p * num.denominator >  this->denominator * num.p );
	}
	/////////////////////////////////////////////////////////////////////////////

	 ratio& ratio::operator-=(ratio num)
		{
			this->p=this->p * num.denominator - this->denominator * num.p;
			this->denominator = this->denominator * num.denominator;
			return *this;
				}    


        ratio& ratio::operator+=(ratio num)
		{
			this->p=this->p * num.denominator + this->denominator * num.p;
			this->denominator = this->denominator * num.denominator;
			return *this;
				}        

		/////////////////////////////////////////////////////////////
		ratio ratio::operator/(ratio num)
		{
			ratio temp;
			temp.p=this->p*num.denominator;
			temp.denominator=this->denominator*num.p;
			return temp;
		}
		///////////////////////////////////////////////////////////
			void ratio::setRatio (int part, int den)
			{
					if (den !=0)
			{
				p = part;
				denominator=den;
			}
			else
			cout <<"ERROR: division by zero\n\n";
			}
		
		///////////////////////////////////////////////////////////////
		void ratio :: show()
		{
			cout <<p<<"/"<<denominator<<"\n";
		}
		
		
		
		void menu(ratio num1,ratio num2)
		{
			cout <<"your number:\nnum1: ";
			num1.show();
			cout <<"num2: ";
			num2.show();
			char in;
			cout <<"1. / \t2. += \t 3. -=\t 4. /= \t 5. != \t 6. > \t 7. < \t 8. <= \t 9. >= \t a. --(prefix) b. --(postfix)\n";
			cout <<"0.back\n";
			cout <<"please enter your choise: \n";
			in=getche();
			cout <<"\n";
			switch (in)
			{
				case '1':
					(num1/num2).show();
					cout <<"press any key for back to menu..";
					getch();
					system ("cls");
					menu(num1, num2);
					
				case '2':
					cout <<"num1= num1 + num2\n";
					(num1+=num2).show();
					cout <<"press any key for back to menu..";
					getch();
						system ("cls");
					menu(num1, num2);
				
				case '3':
					cout <<"num1= num1 - num2\n";
					(num1-=num2).show();
					cout <<"\npress any key for back to menu..";
					getch();
						system ("cls");
					menu(num1, num2);
				
				case '4':
					cout <<"num1= num1 / num2\n";
					(num1/=num2).show();
					cout <<"\npress any key for back to menu..";
					getch();
						system ("cls");
					menu(num1, num2);
				
				case '5':
					cout <<"if numbers are equale prints 0 else prints 1\n";
					cout <<(num1 != num2);
					cout <<"\npress any key for back to menu..";
					getch();
						system ("cls");
					menu(num1, num2);
				
				case '6':
					cout <<"if number1 is smaller than number2 prints 0 else prints 1\n";
					cout <<(num1 > num2);
					cout <<"\npress any key for back to menu..";
					getch();
					system ("cls");
					menu(num1, num2);
					
				case '7':
					cout <<"if number1 is greater than number2 prints 0 else prints 1\n";
					cout <<(num1 < num2);
					cout <<"\npress any key for back to menu..";
					getch();
						system ("cls");
					menu(num1, num2);
				
				case '8':
					cout <<(num1 <= num2);
						cout <<"\npress any key for back to menu..";
					getch();
					system ("cls");
					menu(num1, num2);
					
				case '9':
					cout <<(num1 >= num2);
						cout <<"\npress any key for back to menu..";
					getch();
						system ("cls");
					menu(num1, num2);
				
				case 'a':
					cout <<"num2 = num2 - 1";
					(--num2).show();
				
						cout <<"\npress any key for back to menu..";
					getch();
					system ("cls");	
					menu(num1, num2);
				
				case 'b':
				(num2--).show();
					cout <<"\n curent num2: ";
					num2.show();
						cout <<"\npress any key for back to menu..";
					getch();
						system ("cls");
					menu(num1, num2);
				
				case '0':
				system("cls");
					wellcome();
				
				default:
					cout <<"error: invalid input..\n";
						cout <<"\npress any key for back to menu..";
					getch();
					system ("cls");
					menu(num1, num2);
					
					
					
			}
			
				}
		
		

void wellcome()
{
	int part, den;
cout <<" you can see and test this program by entering tow short numbers in form of (part / denominator)\n";
cout <<"num1: \npart: ";
cin >>part;
cout <<"denominator: ";
cin >>den;
ratio num1(part,den);
cout <<"num2: \npart: ";
cin >>part;
cout <<"denominator: ";
cin >>den;
ratio num2 (part, den);
cout <<"ok, please press any key to go to menu..";
getch();
system("cls");
menu(num1, num2);

	
}


int main ()
{
cout <<"hello\n";
wellcome();
	return 0;
}





