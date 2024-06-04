#include <algorithm>
#include <iostream>
#include <random>
using namespace std;

// https://modoocode.com/304
// 시드값을 얻기 위한 random_device 생성.
std::random_device rd;

// random_device 를 통해 난수 생성 엔진을 초기화 한다.
std::mt19937 gen(rd());

bool MontyHall(void)
{
    // 0 부터 2 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
    std::uniform_int_distribution<int> dis(0, 2);

    bool doors[3];
    fill(doors, doors + 3, false);

    int sportsCarIdx = dis(gen);
    doors[sportsCarIdx] = true;
    
    int goats[2];
    int goatIdx = 0;
    for (size_t i = 0; i < 3; i++)
    {
        if (i != sportsCarIdx)
        {
            goats[goatIdx++] = i;
        }
    }

    int choice = dis(gen);
    // if (doors[choice] == true)
    // {
    //     cout << choice + 1 << "번 문을 선택했습니다. " << goats[0] + 1 << "번 문에는 염소가 있습니다.\n";
    //     cout << "🐐 바꾼 " << goats[1] + 1 << "번 문은 염소였습니다.. 메에에.. 🐐\n";
    // }
    // else
    // {
    //     cout << choice + 1 << "번 문을 선택했습니다. " << goats[0] + 1 << "번 문에는 염소가 있습니다.\n";
    //     cout << "🏎️ 바꾼 " << sportsCarIdx + 1 << "번 문은 스포츠카였습니다 !! 🏎️\n";
    // }
    if (doors[choice])
    {
        // 선택을 바꾼다면 염소가 있는 문 선택
        return false;
    }
    else 
    {
        // 선택을 바꾼다면 스포츠카가 있는 문 선택
        return true;
    }
}

int main(void)
{
    int cnt = 0;
    for (size_t i = 0; i < 10000; i++)
    {
        if (MontyHall())
        {
            ++cnt;
        }
    }
    double percent = static_cast<double>(cnt) / 100;
    cout << "🏎️  " << percent << "% 확률로 스포츠카를 얻을 수 있습니다! 🏎️\n";

    return 0;
}
