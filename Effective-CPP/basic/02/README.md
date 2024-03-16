# 02

## Dynamic Memory Allocation
- c++에서는 메모리를 할당/해제하는 개념이 아니라 클래스에 대한 인스턴스를 생성/삭제하는 방식
- `new` 연산자를 통해 인스턴스를 생성하고 `delete` 연산자를 통해 인스턴스를 삭제한다. (메모리 크기 명시가 필요하지 않음)

```cpp
// c

int* pData = malloc(sizeof(int)); // 사용자가 메모리 크기를 명시해야함

free(pData);

// c++

int* pData = new int; // 사용자가 메모리 크기를 명시하지 않음

delete pData;
```

## Reference
- `reference`는 `별명`이라고 생각하면 된다.
- `int * const ptr`처럼 값을 변경 못하는 포인터 정도로 생각하면 된다.
- `reference`는 반드시 선언과 동시에 실제 인스턴스를 참조해야 한다.

## Temporary Object
- `Temporary Object`는 `r-value`이다.
