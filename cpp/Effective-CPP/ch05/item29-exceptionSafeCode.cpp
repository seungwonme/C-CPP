#include <iostream>

// private 멤버, 데이터가 캡슐화되어 있기 때문에 구조체로 선언
struct PMImp1
{
	std::shared_ptr<Image> bgImage;
	int imageChanges;
};

class Lock
{
private:
	pthread_mutex_t *mpMutex;
public:
	explicit Lock(pthread_mutex_t *pm) 
	: mpMutex(pm)
	{
		pthread_mutex_lock(mpMutex);
	}
	~Lock()
	{
		pthread_mutex_unlock(mpMutex);
	};
};

class Image
{
public:
	Image(std::istream& imgSrc)
	{
		std::cout << "Image constructor" << std::endl;
	}
};

class PrettyMenu
{
public:
	PrettyMenu() 
	: bgImage(NULL)
	, imageChanges(0)
	{
		pthread_mutex_init(&mutex, NULL);
	}
	void changeBackground(std::istream& imgSrc);
private:
	pthread_mutex_t mutex;
	// Image* bgImage;
	// std::shared_ptr<Image> bgImage; // 강력한 보장
	std::shared_ptr<PMImp1> bgImage;
	int imageChanges;
};

/* void PrettyMenu::changeBackground(std::istream& imgSrc)
{
	pthread_mutex_lock(&mutex);
	delete bgImage;
	++imageChanges;
	bgImage = new Image(imgSrc); 
	// 예외 시
	// 1. 뮤텍스 잠금 해제 안됨
	// 2. bgImage 객체가 할당되지 않음
	pthread_mutex_unlock(&mutex);
} */

void PrettyMenu::changeBackground(std::istream& imgSrc) 
{
	Lock m1(&mutex); // 자원 관리 객체를 사용하여 락을 건다. 1번 해결
	bgImage.reset(new Image(imgSrc)); // bgImage의 내부 포인터를 new Image(imgSrc)의 실행 결과로 대체한다. 2번 해결
	++imageChanges;
}

void PrettyMenu::changeBackground(std::istream& imgSrc) 
{
	using std::swap;

	Lock m1(&mutex); // 자원 관리 객체를 사용하여 락을 건다. 1번 해결
	std::shared_ptr<PMImp1> pNew(new PMImp1(*bgImage)); // 객체의 데이터 부분을 복사한다.

	pNew->bgImage.reset(new Image(imgSrc)); // 사본을 수정한다.
	++pNew->imageChanges;
	swap(pNew, bgImage); // 사본을 원본에 적용한다. 2번 해결
}

int	main(void)
{
	
	return 0;
}
