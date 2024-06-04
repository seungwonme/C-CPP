#include <algorithm>
#include <iostream>
#include <random>
using namespace std;

const int PRISONER_NUM = 100;

// https://modoocode.com/304
// 시드값을 얻기 위한 random_device 생성.
std::random_device rd;
// random_device 를 통해 난수 생성 엔진을 초기화 한다.
std::mt19937 gen(rd());
// 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
std::uniform_int_distribution<int> dis(0, PRISONER_NUM - 1);

int simulationWithSelectRandom(void)
{
    bool bPrisonerChecked[PRISONER_NUM];
    fill(bPrisonerChecked, bPrisonerChecked + PRISONER_NUM, false);

    vector<int> boxes;
    vector<int> choice;
    for (int i = 0; i < PRISONER_NUM; i++)
    {
        boxes.push_back(i);
        choice.push_back(i);
    }
    for (size_t i = 0; i < dis(gen); i++)
    {
        shuffle(boxes.begin(), boxes.end(), gen);
    }

    // 무작위로 골랐을 때
    for (size_t n = 0; n < PRISONER_NUM; n++)
    {
        // n + 1번 죄수 입장
        shuffle(choice.begin(), choice.end(), gen);
        for (size_t i = 0; i < 50; i++)
        {
            if (boxes[choice[i]] == n)
            {
                bPrisonerChecked[i] = true;
                break;
            }
        }
    }

    int cnt = 0;
    for (size_t i = 0; i < PRISONER_NUM; i++)
    {
        if (bPrisonerChecked[i])
        {
            ++cnt;
        }
    }
    // cout << cnt << "명의 죄수가 본인의 번호를 확인했습니다.";
    // if (cnt == PRISONER_NUM)
    // {
    //     cout << " 모든 죄수가 석방되었습니다.\n";
    // }
    // else
    // {
    //     cout << " 모든 죄수가 사형당했습니다.\n";
    // }
    return cnt;
}

bool simulationWithUsingPermutation()
{
    bool bPrisonerChecked[PRISONER_NUM];
    fill(bPrisonerChecked, bPrisonerChecked + PRISONER_NUM, false);

    vector<int> boxes;
    for (int i = 0; i < PRISONER_NUM; i++)
    {
        boxes.push_back(i);
    }
    shuffle(boxes.begin(), boxes.end(), gen);

    /*  */
    // for (size_t i = 0; i < PRISONER_NUM; i++)
    // {
    //     cout << i + 1 << "번 박스에는 " << boxes[i] + 1 << "번이 적혀있다.\n";
    // }
    /*  */

    for (size_t n = 0; n < PRISONER_NUM; n++)
    {
        // n + 1번 죄수 입장
        int choice = n;
        for (size_t i = 0; i < 49; i++)
        {
            // cout << n + 1 << ": " << choice + 1 << "번 박스에는 " << boxes[choice] + 1 << "번이 적혀있다.\n";
            if (boxes[choice] == n)
            {
                bPrisonerChecked[n] = true;
                // cout << n + 1 << ": 탈출!\n";
                break;
            }
            choice = boxes[choice];
            // while (bPrisonerVisited[choice])
            // {
            //     choice = dis(gen);
            // }
        }
    }

    // int cnt = 0;
    // for (size_t i = 0; i < PRISONER_NUM; i++)
    // {
    //     if (bPrisonerChecked[i])
    //     {
    //         ++cnt;
    //     }
    // }

    // bool visited[100];
    // fill(visited, visited + 100, false);
    // int PermutationCnt = 0;
    // for (size_t i = 0; i < 100; i++)
    // {
    //     if (visited[i] == false)
    //     {
    //         ++PermutationCnt;
    //         int cur = i;
    //         cout << PermutationCnt << ": ";
    //         while (visited[cur] == false)
    //         {
    //             visited[cur] = true;
    //             cur = boxes[cur];
    //             cout << cur << ' ';
    //         }
    //         cout << '\n';
    //     }
    // }

    for (size_t i = 0; i < PRISONER_NUM; i++)
    {
        if (!bPrisonerChecked[i])
        {
            return false;
        }
    }
    return true;
    
    // cout << cnt << "명의 죄수가 본인의 번호를 확인했습니다.";
    // if (cnt == PRISONER_NUM)
    // {
    //     cout << " 모든 죄수가 석방되었습니다.\n";
    // }
    // else
    // {
    //     cout << " 모든 죄수가 사형당했습니다.\n";
    // }
}

int main(void)
{
    int cnt = 0, max = 0;
    for (size_t i = 0; i < 100000; i++)
    {
        // cnt = simulationWithSelectRandom();
        if (simulationWithUsingPermutation())
        {
            ++cnt;
        }
    }
    double percent = static_cast<double>(cnt) / 1000;
    cout << percent << "%\n";
    // cout << max << '\n';
    return 0;
}
