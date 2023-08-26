```zsh
❯ ./a.out
AddressSanitizer:DEADLYSIGNAL
=================================================================
==27847==ERROR: AddressSanitizer: stack-overflow on address 0x00016ac66f30 (pc 0x00010499bc64 bp 0x00016b4670c0 sp 0x00016ac66f20 T0)
    #0 0x10499bc64 in main stackoverflow.c:5
    #1 0x1a4fd7f24  (<unknown module>)

SUMMARY: AddressSanitizer: stack-overflow stackoverflow.c:5 in main
==27847==ABORTING
[1]    27847 abort      ./a.out
```

> 쓰레드마다 별도의 스택을 지니며 그 스택의 크기는 m1 mac 환경에서는 8MB이다. 이를 넘어서면 stack overflow가 발생한다.
> 매개변수, 지역변수 등이 스택에 저장되며 이를 자동변수라고 한다.

ulimit 명령어를 통해 스택 사이즈를 조절할 수 있다.
```zsh
❯ ulimit -a
-t: cpu time (seconds)              unlimited
-f: file size (blocks)              unlimited
-d: data seg size (kbytes)          unlimited
-s: stack size (kbytes)             8176
-c: core file size (blocks)         0
-v: address space (kbytes)          unlimited
-l: locked-in-memory size (kbytes)  unlimited
-u: processes                       2666
-n: file descriptors                8192
❯ ulimit -s
8192
❯ ulimit -s 16384
❯ ulimit -s
16384
```

- [Related Resources1](https://stackoverflow.com/questions/2279052/increase-stack-size-in-linux-with-setrlimit)
- [Related Resources2](https://knight0706.tistory.com/45)
- [Related Resources2](https://velog.io/@soopsaram/Kernel-warning-stack-frame-size-of-xxxx-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0)
