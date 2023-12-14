#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

enum eName
{
	FIFTY = 0,
	THIRTY = 1,
	TWENTY = 2
};

const int ValuesForViewingProbabilities = 1000000; // 1,000,000

int cnt[3];

int main(void)
{
	vector<int>	idx;
	string		who[3];

	for (int i = 0; i < 5; i++)
		idx.push_back(FIFTY);
	for (int i = 0; i < 3; i++)
		idx.push_back(THIRTY);
	for (int i = 0; i < 2; i++)
		idx.push_back(TWENTY);

	cout << "50% : ";
	cin >> who[FIFTY];
	cout << "30% : ";
	cin >> who[THIRTY];
	cout << "20% : ";
	cin >> who[TWENTY];


	// 시드값을 얻기 위한 random_device 생성.
	random_device random_device;

	// random_device 를 통해 난수 생성 엔진을 초기화 한다.
	mt19937 gen(random_device());

	// 0 부터 9 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
	uniform_int_distribution<int> dis(0, 9);

	for (size_t i = 0; i < ValuesForViewingProbabilities; i++)
	{
		string s = who[idx[dis(gen)]];

		if (s == who[FIFTY])
			++cnt[FIFTY];
		else if (s == who[THIRTY])
			++cnt[THIRTY];
		else if (s == who[TWENTY])
			++cnt[TWENTY];
	}

	double probability[3];

	probability[FIFTY] = (double)cnt[FIFTY] / ValuesForViewingProbabilities;
	probability[THIRTY] = (double)cnt[THIRTY] / ValuesForViewingProbabilities;
	probability[TWENTY] = (double)cnt[TWENTY] / ValuesForViewingProbabilities;

	cout << "\033[37m";
	cout << "----------확률 분포----------\n";
	cout << "       " << who[FIFTY] << " : " << probability[FIFTY] * 100 << "%" << endl;
	cout << "       " << who[THIRTY] << " : " << probability[THIRTY] * 100 << "%" << endl;
	cout << "       " << who[TWENTY] << " : " << probability[TWENTY] * 100 << "%" << endl;
	cout << "-----------------------------\n\n";
	cout << "\033[0m";

	cout << "🧹 바닥 쓸기 👉 " << who[idx[dis(gen)]] << " 👈" << endl;
	cout << "🪣  바닥 닦기 👉 " << who[idx[dis(gen)]] << " 👈" << endl;
	cout << "🧺 빨래하기  👉 " << who[idx[dis(gen)]] << " 👈" << endl;
	cout << "🥼 빨래 널기 👉 " << who[idx[dis(gen)]] << " 👈" << endl;
	cout << "👖 빨래 널기 👉 " << who[idx[dis(gen)]] << " 👈" << endl;
	// cout << "🧽 분리수거    👉 " who[idx[dis(gen)]] << " 👈" << endl;
}
