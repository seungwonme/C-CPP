## LLDB

lldb는 apple에서 개발하고 있는 디버거이고 [gdb는 지원을 종료했다고 한다.](https://stackoverflow.com/questions/67310123/how-to-install-gdb-on-mac-m1-apple-silicon)

vscode의 default debugger는 gdb이기 때문에 lldb extension을 다운
![](../img/lldb.png)
- [manual](https://github.com/vadimcn/codelldb/blob/master/MANUAL.md)
- [ref](https://velog.io/@hye0n/Mac-%ED%99%98%EA%B2%BD-vscode-%EC%97%90%EC%84%9C-C%EC%96%B8%EC%96%B4-%EA%B0%9C%EB%B0%9C%ED%99%98%EA%B2%BD-%EC%84%B8%ED%8C%85-feat.%EB%94%94%EB%B2%84%EA%B9%85)

### lldb 사용법
- 변수 및 메모리 검사:
	- print [expression] 또는 p [expression]: 변수나 식의 값을 출력합니다.
	- expression [expression] 또는 expr [expression]: 변수나 식을 평가하여 결과를 출력합니다.
	- x/[length_specifier][format_specifier] [address]: 메모리 내용을 출력합니다.

- 실행 관리:
	- run 또는 r: 프로그램을 실행합니다.
	- continue 또는 c: 중단점을 무시하고 실행을 계속합니다.
	- step [count] 또는 s [count]: 다음 명령어로 단계별 실행을 수행합니다.

- 변수 및 스코프 관리:
	- frame variable 또는 fr v: 현재 스택 프레임의 변수를 나열합니다.
	- target variable [expression] 또는 tar va [expression]: 현재 스코프에 있는 변수를 확인합니다.

> watch 탭에서 변수의 값을 보려면 var,[suffix] 를 입력하면 된다!

- [ref](https://hyeyoo.com/64)
- [tutorial](https://aaronbloomfield.github.io/pdr/tutorials/02-lldb/index.html)
- [cmdsum](https://aaronbloomfield.github.io/pdr/docs/lldb_summary.html)
- [tuto](https://lldb.llvm.org/use/tutorial.html)
- [cmd](https://lldb.llvm.org/use/map.html)

## leaks

- man atexit
- man system
- [valgrind](https://github.com/LouisBrunner/valgrind-macos)라는 도구도 있지만 내 작업 환경에서는 사용이 불가능하다
- [ref](https://velog.io/@taelee/C-%EB%A9%94%EB%AA%A8%EB%A6%AC-%EB%88%84%EC%88%98-%EA%B2%80%EC%82%AC%ED%95%98%EA%B8%B0)
- [gcc -fsanitize](https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html)

