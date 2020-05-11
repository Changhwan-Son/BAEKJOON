/*
5. 나이계산 (문자열 컨트롤)
주민등록증의 번호가 주어지면 주민등록증 주인의 나이와 성별을 판단하여 출력하는 프로그램
을 작성하세요. 주민등록증의 번호는 -를 기준으로 앞자리와 뒷자리로 구분된다.
뒷자리의 첫 번째 수가 1이면 1900년대생 남자이고, 2이면 1900년대생 여자, 3이면 2000년대
생 남자, 4이면 2000년대생 여자이다.
올해는 2019년입니다. 해당 주민등록증 주인의 나이와 성별을 출력하세요.

▣ 입력설명
첫 줄에 주민등록증 번호가 입력됩니다.

▣ 출력설명
첫 줄에 나이와 성별을 공백을 구분으로 출력하세요. 성별은 남자는 M(man), 여자는
W(Woman)로 출력한다.

*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string number;

	cin >> number;

	int year;
	int sex_num;
	int age;
	char sex;

	year = stoi(number.substr(0, 2));
	sex = stoi(number.substr(7, 1));

	switch (sex) {
	case 1:
		year += 1900;
		sex = 'M';
		break;
	case 2:
		year += 1900;
		sex = 'W';
		break;
	case 3:
		year += 2000;
		sex = 'M';
		break;
	case 4:
		year += 2000;
		sex = 'W';
		break;
	}

	age = 2020 - year;

	cout << age << " " << sex;

	return 0;

}
