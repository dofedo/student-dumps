#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

using namespace std;

#define size 1000


class polynomial {

	private :
		int count;
		int po[size];
		float co[size];
        string pol;
	
	public :
		polynomial (int i,float j);
		polynomial (int p[],float f[],int c);
		polynomial (string _pol);
		polynomial (){};
		polynomial operator+ (polynomial p);
		polynomial operator/ (polynomial p);
		polynomial operator- (polynomial p);
		polynomial operator* (polynomial p);
		polynomial operator% (polynomial p);
		int eval(int value);
		void power(int pow);
		void showpol();
		void derive();
		void integral();
		void shift(int j);
		void set();
		void sort();	
};


///////////////////////////////////////////////////////////////////////////////
//////////////////////////Class member Fnctions////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


polynomial polynomial::operator/(polynomial p) {
	int power=0;
	float coef=0;
	polynomial p1=*this;
	polynomial result(power, coef);

	while (p1.po[0] >= p.po[0] ) {
		power=p1.po[0]-p.po[0];
		coef=p1.co[0]/p.co[0];
		polynomial	temp(power,coef);
		result=result+temp;
		polynomial t2=p*temp;
		p1=p1-t2;
	}
	return result;
}

polynomial polynomial::operator%(polynomial p) {
	polynomial p1=*this/p;
	p1=p1*p;
	polynomial result=*this-p1;
	return result;
}

polynomial polynomial::operator* (polynomial p) {
	int i,j,c=0;
	int count=this->count*p.count;
	if (count>size) count=size;
	int power[size];
	float coef[size];
	for (i=0; i<this->count; ++i)
	for (j=0; j<p.count; ++j) {
		power[c]=this->po[i]+p.po[j];
		coef[c]=this->co[i]*p.co[j];
		++c;
	}
	polynomial res(power,coef,count);
	return res;
}



polynomial polynomial::operator-(polynomial p) {
	
	int power[size];
	float coef[size];
	int i,c=0;
	int j=p.count+this->count;
	for(i=0;i<this->count;++i) {
		power[i]=this->po[i];
		coef[i]=this->co[i];
	
	}
	for(i;i<j;++i) {
		power[i]=p.po[c];
		coef[i]=-p.co[c];
		++c;
		}
	polynomial result(power,coef,i);
	return result;
}

polynomial polynomial::operator+(polynomial p) {
	
	int power[size];
	float coef[size];
	int i,c=0;
	int j=p.count+this->count;
	for(i=0;i<this->count;++i) {
		power[i]=this->po[i];
		coef[i]=this->co[i];
	
	}
	for(i;i<j;++i) {
		power[i]=p.po[c];
		coef[i]=p.co[c];
		++c;
	}
	polynomial result(power,coef,i);
	return result;
}

polynomial::polynomial(int i, float j) {
	po[0]=i;
	co[0]=j;
	count=1;
}

polynomial::polynomial(int p[size], float f[size], int c) {
	int i;
	count=c;
	for (i=0;i<c;++i) {
		po[i]=p[i];
		co[i]=f[i];
	}
	this->set();
	this->sort();
}

void polynomial::integral() {
	int i;
	for (i=0; i<count;++i) 
	{
	++po[i];
		co[i]=co[i]/po[i];
	}
	this->showpol();
 } 

void polynomial::derive() {
	int i;
	for(i=0;i<count;++i) {
		if (po[i] == 0) --count;
		else
		{
			co[i]*=po[i];
			--po[i];
		}
	}
	this->showpol();
}

void polynomial::sort() {
	int i,t,j;
	double t2;
//	bool flag=0;
	 for (i=0; i<count; ++i)
	 for (j=0; j<count; ++j)
	 {
	 	if(po[i] > po[j])
	 	{
	 		t=po[i];
	 		t2=co[i];
	 		po[i]=po[j];
	 		co[i]=co[j];
	 		po[j]=t;
	 		co[j]=t2;
		 }
	 	
	 }
}



void polynomial::power(int pow) {
	polynomial pol=*this;
	int i;
	if(pow > 0) {
		for (i=0; i<pow-1; ++i)
		*this=*this*pol;
	}
	this->showpol();
}

int pow(int j,int val) {
	int res=1;
	int i;
	for(i=0; i<j; ++i) res*=val;
	return res;
}

int polynomial::eval(int value) {
	int j,i;
	float result=0;
	for (i=0; i<count; ++i) {
		j=po[i];
		if (po[i]!=0) 
			result=co[i]*pow(j,value)+result;
		else result+=co[i];
	}
	return result;
}


void polynomial::showpol() {
	int i;
	for (i=0;i<this->count;++i) {
		if (co[i]==0) cout <<"+0";
		else {
			if (co[i]>0 && i!=0) cout <<"+";
			cout <<co[i]<<"x^"<<po[i];
		}
	}

}

void polynomial::shift(int j) {

	for (j; j<count; ++j) {
		po[j]=po[j+1];
		co[j]=co[j+1];
	}
}

void polynomial::set () {
	int i,j;
	for (i=0; i<count; ++i)
	for (j=i+1; j<count; ++j) {
		if (po[i]==po[j]) 
		{
			co[i]+=co[j];
			this->shift(j);
			--count;
			--j;
		}
	}
	for (i=0; i<count; ++i)
		if (co[i]==0) {
			this->shift(i);
			--count;
		}	
	this->sort();
}

int finds(string pol, int begin) {
	int i=begin;
	while (pol[i]!='\0') {
		if ((pol[i]=='+' || pol[i]=='-') && i!=0) return i;
		++i;
	}
	return i;
}


int findx(string pol,int begin, int end) {
	int i=begin;
	while (i!=end) {
		if (pol[i]=='x' || pol[i]=='X') return i;
		++i;
	}
	return i;
}

float stof(string s,int i,int j) {
	int k=0;
	float f;
	if (s[i-1]=='-') --i;
	char num[j-i];
    for (i; i<j; ++i, ++k)	num[k]=s[i];
    num[k]='\0';
    f=atof(num);
    return f;
}




int numOfSign(string pol) {
	int j=0,i=0;
	while (pol[i]!='\0') {
		if (pol[i]=='-' || pol[i]=='+') ++j;
		++i;
	}
//	if (j==0) return j;
	return j+1;
}

polynomial::polynomial(string _pol) {
	pol = _pol;
	float p;
	int x, s, begin = 0, i, c;
	c = numOfSign(pol);
	if (pol[0] == '-' || pol[0] == '+') --c;
	count = c;

	for (i = 0; i<c; ++i) {

		s = finds(pol, begin);
		x = findx(pol, begin, s);

		if (s == x) p = stof(pol, begin, x);
		else if (pol[x - 1] == '-') p = -1;
		else if (pol[x - 1] == '+') p = 1;
		else if(x==0) p=1;
		else  p = stof(pol, begin, x);
		co[i] = p;
		begin = s + 1;
	}

	begin = 0;
	s = 0;
	x = 0;
	for (i = 0; i<c; ++i) {
		s = finds(pol, begin);
		x = findx(pol, begin, s);

		if (s == x) p = 0;
		else if (s - x == 1) p = 1;
		else p = stof(pol, x + 2, s);

		po[i] = p;
		//t[i].seta(p);
		begin = s + 1;
	}
	this->set();

}

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////Main Functions////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


void menu();

void finish() {
	cout <<"\n press any key to left...";
	getch();
	system("clear");
	menu();
}

void manage(string pol,char in) {
	int i;
	polynomial	p1;
	string pol2;
	if (in>'0' && in<'6') {
		cout <<"\ng(x)= ";
		cin >> pol2;
		polynomial t(pol2);
		p1=t;
	}
	polynomial p(pol);
	polynomial po;

	switch (in) {
		case '1':
			cout <<"\nh(x) = f(x) + g(x)\ng(x)= ";
			po=p+p1;
			cout <<"h(x)= ";
			po.showpol();
			finish();
			break;
		case '2':
			cout <<"\nh(x) = f(x) - g(x)\ng(x)= ";
			po=p-p1;
			cout <<"h(x)= ";
			po.showpol();
			finish();
			break;
		case '3':
			cout <<"\nh(x) = f(x) * g(x)\ng(x)= ";
			po=p*p1;
			cout <<"h(x)= ";
			po.showpol();
			finish();
			break;
		case '4':
			cout <<"\nh(x) = f(x) / g(x)\ng(x)= ";
			po=p/p1;
			cout <<"h(x)= ";
			po.showpol();
			finish();
			break;
		case '5':
			cout <<"\nh(x) = f(x) % g(x)\ng(x)= ";
			po=p%p1;
			cout <<"h(x)= ";
			po.showpol();
			finish();
			break;
		case '6':
			cout <<"integral of F(x)= ";
			p.integral();
			cout <<"\n";
			finish();
			break;
		case '7':
			cout <<"derive of F(x)= ";
			p.derive();
			cout <<"\n";
			finish();
			break;	
		case '8':
			cout <<"\nenter power\npower= "; cin >>i;
			cout <<"f(x) ^ power= ";
			p.power(i);
			finish();
			break;
		case '9':
			cout <<"\nenter value\nvalue= "; cin >>i;
			cout <<"f(value)= ";
			cout<<p.eval(i);
			finish();
			break;
		case '0': 
			system("clear");
			menu();
			break;	
		default: 
			cout <<"\nerror: invalid input...";
			getch();
			return;		
	}
	return;
}

void menu() {
	char in;
	string str;
	cout << "you can enter one polynomial in form of below:\ne.g : F(x)= -2.5x^3 + 2x^2 + x - 9\nf(x)=";
	cin >> str;
	cout << "\nplease choose operator:\n1.'+'\t2.'-'\t3.'*'\t4.'/'\t5.'%'\t6.integral\t7.derive\t8.power\t\t9.evaluate\t0.EXIT\n";
	in = getch();
	manage(str,in);
	return;
}



int main() {
	cout <<"hello, polynomial class representation.\n";
	cout <<"at first you must enter one polynomial";
	menu();
	return 0;	
}


