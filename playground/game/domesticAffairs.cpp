#include <iostream>
#include <string>
#include <random>

enum eName
{
	Inlim,
	Yeonwkan,
	Seunan
};

const int ValuesForViewingProbabilities = 1000000; // 1,000,000
const std::string who[3] = { "임인규", "강연우", "안승원" };

int cnt[3];

int main(int ac, const char* av[])
{
	// 시드값을 얻기 위한 random_device 생성.
	std::random_device random_device;

	// random_device 를 통해 난수 생성 엔진을 초기화 한다.
	std::mt19937 gen(random_device());

	// 0 부터 2 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
	std::uniform_int_distribution<int> dis(0, 2);


	for (size_t i = 0; i < ValuesForViewingProbabilities; i++)
	{
		++cnt[dis(gen)];
	}

	double probability[3];

	probability[Inlim] = (double)cnt[Inlim] / ValuesForViewingProbabilities;
	probability[Yeonwkan] = (double)cnt[Yeonwkan] / ValuesForViewingProbabilities;
	probability[Seunan] = (double)cnt[Seunan] / ValuesForViewingProbabilities;

	std::cout << "\033[37m";
	std::cout << "----------확률 분포----------\n";
	std::cout << "       임인규: " << probability[Inlim] * 100 << "%" << std::endl;
	std::cout << "       강연우: " << probability[Yeonwkan] * 100 << "%" << std::endl;
	std::cout << "       안승원: " << probability[Seunan] * 100 << "%" << std::endl;
	std::cout << "-----------------------------\n\n";
	std::cout << "\033[0m";

	std::cout << "🧹 바닥 쓸기 👉 " << who[dis(gen)] << " 👈" << std::endl;
	std::cout << "🪣  바닥 닦기 👉 " << who[dis(gen)] << " 👈" << std::endl;
	std::cout << "🧺 빨래하기  👉 " << who[dis(gen)] << " 👈" << std::endl;
	std::cout << "🥼 빨래 널기 👉 " << who[dis(gen)] << " 👈" << std::endl;
	std::cout << "👖 빨래 널기 👉 " << who[dis(gen)] << " 👈" << std::endl;
	std::cout << "🧽 설거지    👉 " << who[dis(gen)] << " 👈" << std::endl;
}
