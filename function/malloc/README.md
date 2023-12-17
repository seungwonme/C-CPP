# How to limit process memory size

malloc이 할당하는 메모리의 크기를 제한하는 방법에 대해 알아보고자 찾아보았는데 [비슷한 내용을 가진 질문들](https://unix.stackexchange.com/questions/44985/limit-memory-usage-for-a-single-linux-process)을 찾았다.

- [1](https://apple.stackexchange.com/questions/454832/limiting-process-memory-using-ulimit)
- [2](https://discussions.apple.com/thread/3786069?sortBy=best)

```zsh
ulimit -v 400000000
ulimit: setrlimit failed: invalid argument
ulimit -v 410000000    

ulimit -v          
410000000

ulimit -a
-t: cpu time (seconds)              unlimited
-f: file size (blocks)              unlimited
-d: data seg size (kbytes)          unlimited
-s: stack size (kbytes)             8176
-c: core file size (blocks)         0
-v: address space (kbytes)          410000000
-l: locked-in-memory size (kbytes)  unlimited
-u: processes                       2666
-n: file descriptors                10496
```

m1 mac 환경에서는 `ulimit -v`로 최소 410000000(410MB)부터 제한할 수 있었다. 이렇게 제한된 메모리 크기를 넘어서 `malloc`을 호출하면 `malloc`은 `NULL`을 반환한다.

