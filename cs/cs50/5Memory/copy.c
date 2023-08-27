#include <stdio.h>
#include <ctype.h>
#include <string.h> // strlen
#include <stdlib.h> // malloc

int main(void)
{
  // 포인터를 사용했을 때

  char s[100];
  printf("s : ");
  scanf("%s",s);
  char *t = s; // 문자열의 시작을 나타내는 주소를 저장한 s를 참조하는 포인터 변수이므로

  t[0] = toupper(t[0]); // t[0]을 대문자로 바꾸면 s[0] 또한 바뀐다.

  printf("s : %s\n",s);
  printf("t : %s\n",t);

  // 각자 메모리 공간을 할당했을 때

  char s1[100];
  printf("s1 : ");
  scanf("%s", s1);

  char *t1 = malloc(strlen(s1) + 1); // 어떤 문자를 받던 그 문자의 길이 + 1(\0 때문) 바이트 할당

  for (int i = 0, n = strlen(s1); i <= n; i++) // 비교 시 함수 반복 사용을 막기 위해 n에 값 저장
  {
    t1[i] = s1[i];
  }
  
  t1[0] = toupper(t1[0]);
  printf("s1 : %s\nt1 : %s\n",s1,t1);

  // 각자 메모리 공간을 할당했기 때문에 t[0]을 대문자로 비꿔도 s에 영향을 주지 못한다.
  // 메모리 할당이란 메모리의 일부분을 가져와서 그 곳을 가리키는 포인터를 주는 것이다.
  // malloc 의 반대는 free 함수이다. free는 할당되었던 메모리를 다시 반환한다. 이 것을 메모리 해제라고 한다.
  // malloc은 입주 free는 빈방
  
  // 사용하지 않은 메모리는 프로그램 혹은 컴퓨터가 느려지게하는 원인이 될 수 있으므로 해제를 해줘야한다.
  // 이 때 사용할 수 있는 디버깅 툴이 있는데 valgrind라고 한다.

  // 불행히도 arm64 기반의 m1에서는 사용이 불가하다.
  // https://github.com/LouisBrunner/valgrind-macos#user-content-fn-2-0a0c42e2ebbdd91807b4449b6c21279e
  // https://www.reddit.com/r/mac/comments/z721xj/can_i_use_valgrind_on_m1_mac/
  // https://doesitarm.com/ 이 사이트에서 arm64 호환성을 볼 수 있다.
  // 그리고 arch 명령어로 m1 아키텍쳐를 알 수 있다. (arm64)

  // 대신 leaks 라는 명령어로 메모리 누수를 알 수 있다 !
  // https://velog.io/@taelee/C-%EB%A9%94%EB%AA%A8%EB%A6%AC-%EB%88%84%EC%88%98-%EA%B2%80%EC%82%AC%ED%95%98%EA%B8%B0
  // https://sondho.tistory.com/68
  // https://80000coding.oopy.io/457f637f-b101-4f79-adc8-0ca72bd3c6f3
  // 역시 42서울의 자랑 팔만코딩경 개땡큐 ~

  system("leaks copy > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");

  return 0;
}