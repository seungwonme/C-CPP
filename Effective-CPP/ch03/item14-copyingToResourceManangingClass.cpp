#include <iostream>
#include <unistd.h>

class Uncopyable
{
private:
	Uncopyable(const Uncopyable&);
	Uncopyable& operator=(const Uncopyable&);
};

// 1. 복사를 금지한다.
// class Lock : private Uncopyable
class Lock
{
private:
	// 2. 관리하고 있는 자원에 대해 참조 카운팅을 수행한다.
	// std::shared_ptr<pthread_mutex_t> mpMutex;
	pthread_mutex_t *mpMutex;
public:
	explicit Lock(pthread_mutex_t *pm) 
	: mpMutex(pm)
	{
		pthread_mutex_lock(mpMutex);
	}
	/* 2. 관리하고 있는 자원에 대해 참조 카운팅을 수행한다.
	explicit Lock(pthread_mutex_t *pm) 
	: mpMutex(pm, pthread_mutex_unlock) // 삭제자로 unlock을 지정
	{
		pthread_mutex_lock(mpMutex.get());
	} 
	*/
	~Lock()
	{
		pthread_mutex_unlock(mpMutex);
	};
};

int i = 0;

void	*threadFunc(void *arg)
{
	pthread_mutex_t *mutex = static_cast<pthread_mutex_t*>(arg);

	{
		Lock m1(mutex);
		Lock m2(mutex);
		// 이 경우 m1이 m2에 복사될 때 같은 뮤텍스에 대해 두 번 락을 걸게 되므로 교착 상태에 빠짐1
		// RAII 객체가 복사될 때 어떤 동작이 일어나야 하는가?
		std::cout << ++i << " threadFunc()" << std::endl;
	}
	return NULL;
}

int	main(void)
{
	pthread_t thread[10];
	pthread_mutex_t mutex;
	
	pthread_mutex_init(&mutex, NULL);

	for (int i = 0; i < 10; i++)
	{
		pthread_create(&thread[i], NULL, threadFunc, &mutex);
	}

	for (int i = 0; i < 10; i++) 
	{
		pthread_join(thread[i], NULL);
	}
	// sleep(5);
	return 0;
}

/*
pthread_join을 하지 않았을 때
프로세스가 main문에서 return되어 종료되어 출력은 `num threadFunc()` 형태로 출력되지만 모든 스레드가 출력하지 못하는 것을 기대했으나
------------------
12 threadFunc() threadFunc()
6 threadFunc()7
9 threadFunc()
 threadFunc()
8 threadFunc()
45 threadFunc()
------------------
12 threadFunc() threadFunc()
5 threadFunc()
57
3 threadFunc()4


threadFunc()%    
------------------
같이 비정상적인 출력을 확인

for (int i = 0; i < 10; i++) 
{
	pthread_join(thread[i], NULL);
} 
혹은 sleep(5)를 사용하여 스레드가 종료될 때까지 기다렸을 때
1 threadFunc()
2 threadFunc()
3 threadFunc()
4 threadFunc()
5 threadFunc()
6 threadFunc()
7 threadFunc()
8 threadFunc()
9 threadFunc()
10 threadFunc()
정상 출력되는 것을 확인

main문의 종료가 프로세스가 종료라고 추상적으로 생각했는데
프로세스의 종료 과정 순서에 따른 문제라고 생각됨
예를 들어 1. 뮤텍스 락을 반환받는다. 2. 스레드를 종료시킨다. 3. 프로세스를 종료시킨다.
라는 순서라고 가정하면

뮤텍스 락을 반환받는 즉시 기다리던 모든 스레드가 std::cout 버퍼에 데이터를 넣게 되고
이는 버퍼의 내용이 뒤죽박죽이거나, 초기화되지 않은 메모리를 접근하는 등의 Undefined Behavior를 발생시키는 것으로 추정됨
*/
