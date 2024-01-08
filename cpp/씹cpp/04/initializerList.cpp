#include <iostream>

class Marine {
	int hp;                // 마린 체력
	int coord_x, coord_y;  // 마린 위치
	int damage;            // 공격력
	bool is_dead;

 public:
	Marine();              // 기본 생성자
	Marine(int x, int y);  // x, y 좌표에 마린 생성

	int attack();                       // 데미지를 리턴한다.
	void be_attacked(int damage_earn);  // 입는 데미지
	void move(int x, int y);            // 새로운 위치

	void show_status();  // 상태를 보여준다.
};

// 생성자 뒤에 오는 것들을 초기화 리스트라고 한다.
// (생성자 이름) : var1(arg1), var2(arg2) {}
// 초기화 리스트를 사용한 버전의 경우 생성과 초기화를 동시에 하게 됩니다.
// 반면에 초기화 리스트를 사용하지 않는다면 생성을 먼저 하고 그 다음에 대입 을 수행하게 됩니다.
// 쉽게 말하면 초기화 리스트를 사용하는 것은
// int a = 10; 이라 하는 것과 같고,
// 그냥 예전 버전의 생성자를 사용하는 것은
// int a;
// a = 10; 하는 것과 같다.
Marine::Marine() : hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false) {}

Marine::Marine(int x, int y) : hp(50), coord_x(x), coord_y(y), damage(5), is_dead(false) {}

void Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
	std::cout << " *** Marine *** " << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
	std::cout << " HP : " << hp << std::endl;
}

int main() {
	Marine marine1(2, 3);
	Marine marine2(3, 5);

	marine1.show_status();
	marine2.show_status();
}
