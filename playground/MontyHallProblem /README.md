# Monty Hall Problem

[몬티 홀 문제 - 나무위키](https://namu.wiki/w/%EB%AA%AC%ED%8B%B0%20%ED%99%80%20%EB%AC%B8%EC%A0%9C)

## 문제
```
3개의 문 중 하나의 문 뒤에는 자동차가 있고, 나머지 두 문 뒤에는 염소가 있다.
참가자는 문을 하나 선택한다.
진행자는 참가자가 선택한 문을 제외한 다른 두 문 중 하나를 열어 염소가 있다는 것을 보여준다.
참가자는 처음 선택한 문을 바꿀 수 있다.
```

1. 처음에 염소가 있는 문을 선택할 확률 $\frac{2}{3}$
    - 두 문 중 염소가 있는 문을 공개하면 남은 문은 자동차가 있는 문
    - 처음 선택한 문을 바꾸면 무조건 자동차가 있는 문
2. 처음에 자동차가 있는 문을 선택할 확률 $\frac{1}{3}$
    - 염소가 있는 문을 공개하면 남은 문도 마찬가지로 염소가 있는 문
    - 처음 선택한 문을 바꾸면 무조건 염소가 있는 문

처음 선택 시 염소가 있는 문을 선택할 확률이 더 높으므로, 처음 선택한 문을 바꾸는 것이 유리하다.
