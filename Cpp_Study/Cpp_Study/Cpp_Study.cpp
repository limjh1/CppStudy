#include <iostream>
using namespace std;

#pragma region 정수
/*
// ctrl + k + c 주석달기, ctrl + k + u 주석 해제

int hp = 100;

char a; // 1byte -128 ~ 127
short b; // 2byte -32768 ~ 32767
int c; // 4byte -21.4억 ~ 21.4억
__int64 d; // 8byte (long long) 겁나 큼

unsigned char ua; // 1byte 0 ~ 255
unsigned short ub; // 2byte 0 ~ 65536
unsigned int uc; // 4byte 0 ~ 42.9억
unsigned __int64 ud; // 8byte (long long) 겁나 큼

// 참고) 이론적으로 양수만 존재할 수 있는 데이터는 unsigned?
// 무조건 unsigned를 사용할지 말지 의견이 갈림
// - 레벨이 음수라는 것은 말이 안된다 -> 그럼 차라리 그 자리에서 프로그램을 크래시 내서 버그를 찾는게 낫다
// - unsigned / signed 사이의 변환

// -> 콘솔/모바일 게임 -> 메모리가 늘 부족하다.
// -> 온라인 게임 -> 4바이트 * 1만명 ㄷㄷ

int main()
{
    // 정수 오버플로우
    b = 32767;
    b = b + 1;
    cout << b << endl; // -32768

    //언더플로우
    ub = 0;
    ub -= 1;
    cout << ub << endl;

    cout << "체력이 " << hp << " 남았습니다" << endl;
}*/
#pragma endregion

#pragma region 불리언과 부동소수점
/*
bool isHighLevel = true;
bool isPlayer = true;
bool isMale = true;

// [Note]
// bool은 그냥 1byte 정수에 불과
int isFemale = 1;

// bool < 1byte 정수

// 실수 (부동소수점)
// float double

// 부동(뜰 부, 움직일 동)소수점 
// . 을 유동적으로 움직여서 표현하는 방법

// 3.1415926535
// 3.1415926535 = 0.31415926535 * 10 = 314.15926535 * 10^-2
// 1) 정규화 = 0.31415926535 * 10
// 2) 31415926535 (유효숫자) 1 (지수)

// float 부호(1) 지수(8) 유효숫자(23) = 32비트 = 4바이트
// double 부호(1) 지수(1) 유효숫자(52) = 64비트 = 8바이트
float attackSpeed = -3.375f; // 4 byte
double attackSpeed2 = 123.4123; // 8 byte

// ex) -3.375라는 값을 저장
// 1) 2진수 변환 = (3) + (0.375) = 0b11 + 0b0.011 = 0b11.011
// 0.375 = 0.5 * 0 + 0.25 * 1 + 0.125 * 1 = 0b0.011
// 2) 정규화 0b1.1011 * 2^1
// 1(부호) 1(지수) 1011(유효숫자)
// 단 지수는 unsigned byte라고 가정하고 숫자+127 만들어줌
// 예상 결과 : 0b 1 10000000 1011000'0000'0000'0000'0000

// 프로그래밍할 때 부동소수점은 항상 '근사값'이라는 것을 기억
// 1/3 = 0.3333333333333333333333333333333333
// 특히 수가 커질 수록 오차 범위도 매우 커짐
// 실수 2개를 == 으로 비교하는 것은 지양

int main() 
{
    cout << isHighLevel << endl;
}
*/
#pragma endregion

#pragma region 문자와 문자열
/*
// char : 알파벳 / 숫자 문자를 나타낸다.
// wchar_t : 유니코드 문자를 나타낸다.

// ASCII CODE

// '문자'의 의미로 작은 따옴표 '' 사용
char ch = 'a'; // 97
char ch2 = '1'; // 49
char ch3 = 'a' + 1; // 98

// 전 세계 모든 문자에 대해 유일 코드를 부여한 것이 유니코드
// 참고) 유니코드에서 가장 많은 번호를 차지하는게 한국어/중국어 ~ (뚥쿩웱홁)

// 유니코드 표기 방식 여러가지. 대표적으로 UTF8 UTF16
// UTF8
// - 알파벳, 숫자 1바이트 (ASCII 와 동일한 번호)
// - 유럽 지역의 문자는 2바이트
// - 한글, 한자 등 3바이트
// UTF16
// - 한글, 숫자, 알파벳, 한자 등 대부분 2바이트
// - 매우 예외적인 고대 문자만 4바이트 (사실상 무시해도 됨)

wchar_t wch = 0xc548; //L'안';

// Escape Sequence
// 표기하기 애매한 애들을 표현
// \t = 아스키코드9 = tab
// \n = 아스키코드10 = LineFeed (한줄 아래로)
// \r = 아스키코드13 = carriageReturn (커서 <<)
// \'
// \0 = NULL

// 문자열
// 문자들이 열을 지어서 모여 있는 것 (문자 배열?)
// 정수 (1~8바이트) 고정 길이로
// Ex) Hello World 123453dafsd d3af5sd4fasdf dsfasdf32ds4fsda fds2a3f4sd23
// \0 끝에 들어가 있어야 함 끝은 NULL (0)

char str[] = { 'h','e','l','l','o' ,'\0' };
char str2[] = "Hello World";
wchar_t str3[] = L"Hello World";

int main()
{
    //cout << ch << endl;
    //cout << ch2 << endl;
    //cout << ch3 << endl;

    //wcout.imbue(locale("kor"));
    //wcout << wch << endl;
    
    cout << str << endl;
    cout << str2 << endl;    
    cout << str3 << endl;
}
*/
#pragma endregion

#pragma region 산술 연산
// 데이터 연산
/*

int a = 1;
int b = 2;

int main()
{

    // 산술 연산자
    
    // 대입연산
    // a에 b를 대입하고 b를 반환하라
    // -> b라는 바구니 안에 있는 값을, a라는 바구니 안에다 복사한다.
    a = b; 

    // 사칙연산
    // ex) 데미지 계산, 체력 계산
    a = b + 3;
    a = b - 3;
    a = b * 3;
    a = b / 3;
    a = b % 3;

    a += 3;

    // 증감 연산자
    a = a + 1;
    a++;
    ++a;

    b = a++; // b = a 넣고 -> a를 1 증가
    b = ++a; // a 1증가 하고 -> b = a

    b = a + 1 * 3;
}
*/
#pragma endregion

#pragma region 비교 논리 연산
//비교, 논리 연산
/*
int a = 1, b = 2;
bool isSame;
bool isDifferent;
bool isGreater;
bool isSmaller;

bool test;

int Hp;
bool isInvincible; // 무적상태

int main()
{
    isSame = (a == b);
    isDifferent = (a != b);
    isGreater = (a > b);
    isSmaller = (a < b);

    test = !isSame;
    test = (Hp <= 0 && isInvincible == false); // 죽음
    test = (Hp > 0 || isInvincible == true); // 살았음
}*/
#pragma endregion

#pragma region 비트 연산 비트 플래그, const

unsigned char flag; // 부호를 없애야 >> 를 해도 부호비트가 딸려오지 않음

// 한번 정해지면 절대 바뀌지 않을 값들
// constant의 약자인 const를 붙임 (변수를 상수화 한다고 함)
// const를 붙였으면 반드시 초기값 지정해야 함

const int AIR = 0;
const int STUN = 1;
const int POLYMORPH = 2;
const int INVINCIBLE = 3;

// 전역 변수

// [데이터 영역]
// .data (초기값 있는 경우)
int data = 2;

// .bss (초기값 없는 경우)
int bss;

// .rodata (읽기 전용 데이터)
const char* msg = "Hello World";

int main()
{
    // [스택 영역]
    int c = 3;

    // ~ bitwise not
    // 단일 숫자의 모든 비트를 대상으로, 0은 1, 1은 0 뒤바꿈

    // & bitwise and
    // 두 숫자의 모든 비트 쌍을 대상으로, and

    // | bitwise or
    // 두 숫자의 모든 비트 쌍을 대상으로, or

    // ^ bitwise xor
    // 두 숫자의 모든 비트 쌍을 대상으로, xor  두개가 다르면 1

    // << 비트 좌측 이동
    // 비트열을 N만큼 왼쪽으로 이동
    // 왼쪽에 넘치는 N개의 비트는 버림, 새로 생성되는 비트 N개는 0.
    // *2를 할 때 자주 보이는 패턴

    // >> 비트 우측 이동
    // 비트열을 N만큼 오른쪽으로 이동
    // 오른쪽에 넘치는 N개의 비트는 버림.
    // 왼쪽 생성되는 N개의 비트는 
    // - 부호 비트가 존재할 경우 부호 비트를 따라감 (부호있는 정수라면 이 부분을 유의)
    // - 아니면 0

    // 실습 : 비트 플래그
    // 0b0000 [무적][변이][스턴][공중부양]

    // 무적상태로 만든다    
    flag = (1 << INVINCIBLE); // 1000, 8

    // 변이상태를 추가함 ( 무적 + 변이 )
    flag |= (1 << POLYMORPH); // 1100

    // 무적인지 확인하고 싶다? (다른 상태는 관심 x)
    // bitmask
    bool invincible = ((flag & (INVINCIBLE)) != 0);

    // 무적이거나 스턴 상태인지 확인하고 싶다?
    bool mask = (1 << 3) | (1 << 1);
    bool stunOrInvincibie = ((flag % mask) != 0); // mask = 0b1010    
}
#pragma endregion

#pragma region 유의사항

// 1) 변수의 유효범위

// 전역 변수
// int hp = 10;

// 스택
// { } 중괄호의 범위가 생존 범위
// 같은 이름 두번 사용할 때 문제

// 2) 연산 우선순위 --> 괄호 사용

// 3) 타입 변환 ( 형 변환 )
// - 데이터 짤리거나, 정밀도로 손실, 부호 손실

// 4) 사칙 연산 
// - 곱셈 오버플로우 
// - 나눗셈 0으로 나누기 조심.
// - 실수 관련 123/1000 = 0.000000000000000? --> float,double로 바꾸면 해결 , int는 정수만 받기 때문에 정수만 표현해줌


int main()
{
    
}
#pragma endregion

