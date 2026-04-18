#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;
int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	int numQuestions = 20,num1,num2,result;
	int correctAnswer = 0,answer;
	char sign1 = '+',sign2='-';
	char plus[] = "¡Á";
	char divide[] = "¡Â";
	auto start = chrono::system_clock::now();
	for (int i = 0; i < numQuestions / 4; i++) {
		for (int j=0; j < 4; j++) {
			switch (j) {
			case 0:
				  do {
					num1 = rand() % 100 + 1;
					num2 = rand() % 100 + 1;
					result = num1 + num2;
				  } while (result > 100); 
				  cout << num1 << sign1 << num2 << '=' << " ";
				    break;
			case 1:
					num1 = rand() % 100 + 1;
					num2 = rand() % 100 + 1;
					if (num1 < num2) 
						swap(num1, num2);
					result = num1 - num2;
					cout << num1 << sign2<< num2 << '=' << " ";
					break;
			case 2:
				do {	
					num1 = rand() % 100 + 1;
					num2 = rand() % 100 + 1;
					result = num1 * num2;
				}   while (result > 100||num1==1||num2==1);
				    cout << num1 << plus<< num2 << '=' << " ";
				    break;
			case 3:
				do {
					num1 = rand() % 100 + 1;
					num2 = rand() % 100 + 1;
					result = num1 / num2;
				}   while (num1 % num2 != 0||num2==1||num1==num2);
				    cout << num1 << divide<< num2 << '=' << " ";
				    break;
			}
			cin >> answer;
			if (answer == result)
				correctAnswer++;
		}
	}
	auto end = chrono::system_clock::now();
	double accuracy = 1.0*correctAnswer / numQuestions * 100;
	chrono::duration<double> interval = end - start;
	cout << "ÕýÈ·ÂÊ£º" << accuracy<<"%" << endl;
	cout << "ÓÃÊ±£º" << interval.count()<<"Ãë"<< endl;
}
