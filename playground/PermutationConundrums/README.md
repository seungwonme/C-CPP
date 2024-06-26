[확률 1000000000000000000000000000000배 높이기](https://www.youtube.com/watch?v=PE4vLbyOgw0&list=PLD_T8q5A90DkYN9T_qKB-wHL44_XGWI71)

## 문제
```
1부터 100까지 번호가 매겨진 100명의 죄수가 있다.
방에는 100개의 상자가 있고, 각 상자에는 죄수의 번호가 적힌 쪽지가 무작위로 들어있다.
죄수들은 한 번에 한 명씩 방 안에 들어가 50개의 상자를 열어 쪽지를 확인할 수 있다.
그 후 방을 원래대로 정리하고 다음 죄수가 들어가서 똑같이 50개의 상자를 열어 쪽지를 확인한다.
이 때, 죄수들은 서로 대화할 수 없다.
모든 죄수가 자신의 번호를 확인했다면, 죄수들은 석방되지만, 하나라도 다른 죄수의 번호를 확인하지 않았다면 모두가 사형당한다.
```

죄수들이 아무 전략없이 무작위로 상자를 선택한다고 했을 때 모두가 살아남을 확률은
$(\frac{1}{2})^{100} = 7.88860905 \times 10^{-31}$이다.\
10만 번 시뮬레이션을 돌렸을 때 본인의 번호를 확인한 죄수의 수의 최대는 43명이었다.

## 전략
1. 모든 죄수는 처음 방에서 여는 상자의 번호를 자신의 번호로 정한다.
2. 상자의 쪽지를 확인하고, 쪽지에 적힌 번호의 상자를 열어본다.

n개의 상자에 1부터 n까지의 번호가 무작위로 적힌 쪽지가 들어있다고 가정하자.\
n번째 상자를 열고 상자 안 쪽지의 번호를 따라서 상자를 열어보면, 결국에는 n번째 상자로 돌아오게 된다.\
결국 순환하는 상자들의 집합이 생기게 되고, 이 집합의 길이가 죄수들이 선택할 수 있는 상자의 수보다 작다면 모든 죄수가 살아남을 수 있다.

### 예시
> 상자[쪽지]

#### 2개의 상자
- 1[1] 2[2]
    - 1번 죄수는 1번 상자를 열어 1번 쪽지를 확인한다.
    - 2번 죄수는 2번 상자를 열어 2번 쪽지를 확인한다.
- 1[2] 2[1]
    - 1번 죄수는 1번 상자를 열어 2번 쪽지를 확인 후 2번 상자를 열어 1번 쪽지를 확인한다.
    - 2번 죄수는 2번 상자를 열어 1번 쪽지를 확인 후 1번 상자를 열어 2번 쪽지를 확인한다.

#### 3개의 상자
- 1[1] 2[2] 3[3]
    - 1번 죄수는 1번 상자를 열어 1번 쪽지를 확인한다.
    - 2번 죄수는 2번 상자를 열어 2번 쪽지를 확인한다.
    - 3번 죄수는 3번 상자를 열어 3번 쪽지를 확인한다.
- 1[2] 2[3] 3[1]
    - 1번 죄수는 1번 상자를 열어 2번 쪽지를 확인 후 2번 상자를 열어 3번 쪽지를 확인 후 3번 상자를 열어 1번 쪽지를 확인한다.
    - 2번 죄수는 2번 상자를 열어 3번 쪽지를 확인 후 3번 상자를 열어 1번 쪽지를 확인 후 1번 상자를 열어 2번 쪽지를 확인한다.
    - 3번 죄수는 3번 상자를 열어 1번 쪽지를 확인 후 1번 상자를 열어 2번 쪽지를 확인 후 2번 상자를 열어 3번 쪽지를 확인한다.
- 1[3] 2[1] 3[2]
    - 1번 죄수는 1번 상자를 열어 3번 쪽지를 확인 후 3번 상자를 열어 2번 쪽지를 확인 후 2번 상자를 열어 1번 쪽지를 확인한다.
    - 2번 죄수는 2번 상자를 열어 1번 쪽지를 확인 후 1번 상자를 열어 3번 쪽지를 확인 후 3번 상자를 열어 2번 쪽지를 확인한다.
    - 3번 죄수는 3번 상자를 열어 2번 쪽지를 확인 후 2번 상자를 열어 1번 쪽지를 확인 후 1번 상자를 열어 3번 쪽지를 확인한다.
