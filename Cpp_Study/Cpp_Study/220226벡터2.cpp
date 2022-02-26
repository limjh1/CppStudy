#include <iostream>
#include <vector>
using namespace std;

// 벡터

int main()
{
	// 컨테니어(Container) : 데이터를 저장하는 객체 (자료구조 Data Structure)

	// vector (동적 배열)
	// - vector의 동작 원리 (size/capacity)
	// - 중간 삽입/삭제
	// - 처음/끝 삽입/삭제
	// - 임의 접근

	// 반복자(Iterator) : 포인터와 유사한 개념, 컨테이너의 원소(데이터)를 가리키고,
	// 다음/이전 원소로 이동 가능
	vector<int> v(10); // 10개의 v 배열

	v.reserve(1000); // 1000칸을 예약


	for (vector<int>::size_type i = 0; i < v.size(); i++)
	{
		v[i] = i;
	}

	//// 반복자
	//vector<int>::iterator it;
	//int* ptr;

	//it = v.begin();
	//ptr = &v[0];

	//cout << (*it) << endl;
	//cout << (*ptr) << endl;

	//// 포인터 문법을 따라감, 데이터 단위 연산
	//it++;
	//++it;
	//ptr++;
	//++ptr;

	//it += 2;
	//ptr += 2;
	//
	//int a = 1;
	//int b = a++; // b=1 -> a=2
	//int c = ++a; // c <- (a=2)

	//vector<int>::iterator itBegin = v.begin();
	//vector<int>::iterator itEnd = v.end();

	// 더 복잡해보이지만 쓰이는 이유
	// iterator 는 vector뿐 아니라 , 다른 컨테이너에도 공통적으로 있는 개념 -> 통일성
	// 다른 컨테이너는 v[i]와 같은 인덱스 접근이 안 될 수도 있음
	for (vector<int>::iterator it = v.begin(); it < v.end(); ++it)
	{
		cout << (*it) << endl;	
	}

	int* ptrBegin = &v[0]; // v.begin()._ptr;
	int* ptrEnd = ptrBegin + 10; // v.end()._ptr;
	for (int* ptr = ptrBegin; ptr != ptrEnd; ++ptr)
	{
		cout << (*ptr) << endl;
	}

	// const int*
	// vector<int>::const_iterator cit1 = v.cbegin();
	// *cit1 = 100; 수정 불가능
	
	// 역방향
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
	{
		cout << (*it) << endl;
	}

	// - 중간 삽입/삭제 (비효율적임, 하나 하려면 다 옮기고나서 넣어야함)
	// -- 천만개라면 천만번 움직어야함
	// - 처음/끝 삽입/삭제
	// -- 처음은 중간이랑 똑같이 비효율적임
	// -- 끝은 한번만 동작하면 된다, 효율적
	// -- v.push_back(), v.pop_back()
	// - 임의 접근 (random access)	
	// -- n번째 데이터를 바로 접근, v[i] = 3;

	// vector = 동적 배열 = 동적으로 커지는 배열 = 배열
	// 원소가 하나의 메모리 블록에 연속하게 저장된다
	

	// 2번째칸을 5로 채워주고 다 한칸씩 밀릴 것
	// 채워준 값이 return
	// vector<int>::iterator insertIt = v.insert(v.begin() + 2, 5);

	// 3번째칸을 지우고 다 한칸씩 땡길 것
	// erase한 값이 return
	// vector<int>::iterator eraseIt1 = v.erase(v.begin() + 3); 

	// 2~3번째칸을 지우고 다 한칸씩 땡길 것, 4는 포함되지 않음
	// return 값은 4번째
	// vector<int>::iterator eraseIt2 = v.erase(v.begin() + 2, v.begin() + 4); 
	
	// 스캔 하면서, 3이라는 데이터가 있으면 일괄 삭제하고 싶다

	for (vector<int>::iterator it = v.begin(); it != v.end();)
	{
		int data = *it;
		if (data == 3)
		{
			// erase하면 바로 유효하지 않기 때문에 그 위치를 return해야 위치를 찾을 수 있음
			// 그냥 하나만 지울거면 하나 지우고 break;해야 for문에서 ++it할 때 크래시 안남
			it = v.erase(it);
		}
		else
		{
			++it;
		}

		// v.clear();
		// break; // break 안하면 바로 충돌. 왜 ? 유효하지 않기 때문에
	}


	return 0;

}