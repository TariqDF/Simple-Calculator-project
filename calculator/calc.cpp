#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
using namespace std;
void numbers(double* ptr, int* i, bool* bptr, int* z);
void ops(double *fptr, double *sptr, int op);




int main() {
	double first = 0, second = 0; 
	int i = 0;
	bool Deci= false,snum=false;
	int operate;
	
	while (true)
	{	cout << "enter a number followed by an operation sign" << endl;
		i = _getch();
		if (i == 46) {
			Deci = true;
		}
		
		for (int z=0;(i >= 45 && i <= 57) || i == 46 || (i >= 42 && i <=43);z++) {
			if (((i >= 42 && i <= 43) || (i == 45 || i == 47))&& snum==false) {
				snum = true;
				Deci = false;
				operate = i;
				i = 48;
			}
			else if (((i >= 42 && i <= 43) || (i == 45 || i == 47)) && snum == true) {
				int temp = i;
				i = 48;
				ops(&first, &second, operate);
				second = 0;
				operate = temp;
				
				z = 1;
			}

			if (snum == false) { numbers(&first, &i, &Deci, &z); }
			else {
				
				numbers(&second, &i, &Deci, &z);
			
			}



		}



		if (i == 13) {
		
			ops(&first, &second, operate);
			snum = false;
			Deci = false;
			cout << first <<endl;
			first = 0;
			second = 0;
		
		}




	}




	return 0;
}


void numbers(double *ptr,int* i,bool *bptr, int* z) {
	
	
	
	if (*bptr == false) {
		system("cls");
		*ptr = (*i - 48) + (*ptr * 10);
		cout << "enter a number followed by an operation sign" << endl;
		cout << fixed << setprecision(0) << *ptr << endl;
		*i = _getch();
	}
	else
	{
		if (*i == 46) {
			*i = 48;
			*z = 0;
		}

		system("cls");
		*ptr = *ptr + ((*i - 48) / (pow(10, *z)));
		cout << "enter a number followed by an operation sign" << endl;
		cout << fixed << setprecision(6) << *ptr << endl;
		*i = _getch();

	}
	if (*i == 46 && *bptr == false) {
		*bptr = true;
	}
}


void ops(double* fptr, double* sptr, int op) {

	switch (op) {

	case 43:
		*fptr = *fptr + *sptr;
		break;
	case 45:
		*fptr = *fptr - *sptr;
		break;
	case 47:
		*fptr = *fptr / *sptr;
		break;

	case 42:
		*fptr = *fptr * *sptr;
		break;


	}

}