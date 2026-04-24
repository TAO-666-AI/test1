#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int numerator;
	int denominator;
}RatNum;
int gcd(int a, int b) {
	while (b != 0) {
		int temp;
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
void simplify(RatNum* rational) {
	if (rational->denominator < 0) {
		rational->numerator = -rational->denominator;
		rational->denominator = -rational->numerator;
	}
	int common = gcd(abs(rational->numerator), rational->denominator);
	rational->numerator /= common;
	rational->denominator /= common;
}
RatNum create(int a, int b) {
	RatNum rational;
	rational.numerator = a;
	rational.denominator = b;
	simplify(&rational);
	return rational;
}
RatNum inputRat() {
	int a, b;
	do {
		printf("输入有理数的分子：");
		scanf("%d", &a);
		printf("输入有理数的分母：");
		scanf("%d", &b);
		if (b == 0)printf("分母不得为0.请重新输入：\n");
	} while (b == 0);
	return create(a, b);
}
RatNum add(RatNum a, RatNum b) {
	RatNum r;
	r.numerator = a.numerator * b.denominator + a.denominator * b.numerator;
	r.denominator = a.denominator * b.denominator;
	return r;
}
RatNum subtract(RatNum a, RatNum b) {
	RatNum r;
	r.numerator = a.numerator * b.denominator - a.denominator * b.numerator;
	r.denominator = a.denominator * b.denominator;
	return r;
}
RatNum multiply(RatNum a, RatNum b) {
	RatNum r;
	r.numerator = a.numerator * b.numerator;
	r.denominator = a.denominator * b.denominator;
	return r;
}
RatNum divide(RatNum a, RatNum b) {
	RatNum r;
	while (b.numerator == 0) {
		printf("除数不得为0，请重新输入第二个有理数：\n");
		b = inputRat();
	}
	r.numerator = a.numerator * b.denominator;
	r.denominator = a.denominator * b.numerator;
	return r;
}
void printfRat(RatNum a) {
	if (a.denominator == 1) {
		printf("%d\n", a.numerator);
	}
	else {
		printf("%d/%d\n", a.numerator, a.denominator);
	}
}
int main() {
	RatNum rat1, rat2, rat;
	int a, b, order;
	do {
		printf("加法-1，减法-2，乘法-3，除法-4,结束-0\n");
		scanf("%d", &order);
		switch (order) {
		case 1:printf("输入第一个有理数：\n");
			rat1 = inputRat();
			printf("输入第二个有理数：\n");
			rat2 = inputRat();
			rat = add(rat1, rat2);
			simplify(&rat);
			printf("结果是：\n");
			printfRat(rat);
			break;
		case 2:printf("输入第一个有理数：\n");
			rat1 = inputRat();
			printf("输入第二个有理数：\n");
			rat2 = inputRat();
			rat = subtract(rat1, rat2);
			simplify(&rat);
			printf("结果是：\n");
			printfRat(rat);
			break;
		case 3:printf("输入第一个有理数：\n");
			rat1 = inputRat();
			printf("输入第二个有理数：\n");
			rat2 = inputRat();
			rat = multiply(rat1, rat2);
			simplify(&rat);
			printf("结果是：\n");
			printfRat(rat);
			break;
		case 4:printf("输入第一个有理数：\n");
			rat1 = inputRat();
			printf("输入第二个有理数：\n");
			rat2 = inputRat();
			rat = divide(rat1, rat2);
			simplify(&rat);
			printf("结果是：\n");
			printfRat(rat);
			break;
		}
	} while (order != 0);
	return 0;
}

































