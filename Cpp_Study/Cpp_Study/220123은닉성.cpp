#include <iostream>
using namespace std;

// 은닉성 = 캡슐화

// 객체지향 (OOP Object Oriented Programming)
// - 상속성
// - 은닉성
// - 다형성

// 은닉성(Data Hiding) = 캡슐화(Encapsulation)
// 몰라도 되는 것을 숨긴다.
// 이유
//  1) 건드리면 안되는 경우
//  2) 다른 경로로 접근하길 원하는 경우

// 자동차
// - 핸들
// - 페달
// - 엔진
// - 문
// - 각종 전기선

// 일반 구매자 입장에서 사용하는 것
// - 핸들, 페달, 문
// 몰라도 되는 부분 (건드리면 큰일나는 부분)
// - 엔진, 각종 전기선

// public (공개) protected (보호) private (개인)
// - public    : 공개
// - protected : 자손들한테만 허락
// - private   : class 내부에서만 사용

// 상속 접근 지정자 : 다음 세대한테 유산을 어떻게 물려줄지?
// 꼭 똑같이 물려줘야 하진 않음
// - public : 설계 그대로 상속 (public -> public, protected -> protected, private -> 상속X)
// - protected : 자손들한테만 물려줌 (public -> protected, protected -> protected, private -> 상속X)
// - private : 안줌 (public -> private, protected -> private)

class Car
{
public: // (멤버) 접근 지정자
	void MoveHandle() {}
	void PushPedal() {}
	void OpenDoor() {}

	void TurnKey()
	{
		// ...
		RunEngine();
	}

protected:
	void RunEngine() {} // 엔진을 구동시킨다

private:
	void DisassembleCar() {} // 차를 분해한다	
	void ConnectCircuit() {} // 전기선 연결

public:
	// 핸들
	// 페달
	// 엔진
	// 문
	// 각종 전기선

};

class SuperCar : public Car // 상속 접근 지정자
{
public:
	void PushRemoteController()
	{
		RunEngine();
	}
};

// 지정안해주면 기본값으로 private로 지정함
class TestSuperCar : SuperCar
{
	// OpenDoor();
};

// 캡슐화
// 연관된 데이터와 함수를 논리적으로 묶어놓은 것

class Berserker
{
public:

	int GetHp() { return _hp; }
	void SetHp(int hp)
	{		
		_hp = hp;
		if (_hp <= 50) SetBerserkerMode();
	}

private:
	// 사양 : 체력이 50 이하로 떨어지면 버서커 모드 발동
	void SetBerserkerMode()
	{
		cout << "매우 강해짐" << endl;
	}

private:
	int _hp = 100;
};

int main()
{
	Car car;

	SuperCar s_car;
	s_car.PushRemoteController();

	Berserker b;

	b.SetHp(20);

	TestSuperCar t_car;
	

	return 0;
}