#include <iostream>
#include <cmath>

using namespace std;

const long a = 3;
const long b = 5;
const long c = 7;
const long p = pow(10, 12) * 5;  //5 * 10^12 五万亿	

int main() {
	int x = 0;  	 //3的指数
	int y = 0;	//5的指数
	int z = 0;	//7的指数
	
	int ct = 0;   //统计数
	long ai = 0; 
	long bi = 0; 
	long ci = 0;
	while ((ai = pow(a, x)) <= p) { // ai = a^x 
		
		while ((bi = ai * pow(b, y)) <= p) { // bi = a^x * b^y

			while ((ci = bi * pow(c, z)) <= p) { // ci = a^x * b^y * c^z
				++ct;
				cout << "( " << x << " | " << y << " | " << z << " )"; //观察
				cout << "---- " << ci << "<=" << p <<"-----" << ct << endl; //观察
				++z;
			}
			z = 0;
			++y;
		}
		y = 0;
		++x;
	}
	cout << "<< " << ct-1 << " >>" << endl;	//除去0,0,0情况
				
	return 0;
}
