#include <stdio.h>
#include <unistd.h>

// 간단한 메모리 블록 구조체 정의
typedef struct Block 
{
	size_t	size;		// 할당된 메모리 블록의 크기
	struct	Block* next;	// 다음 메모리 블록의 포인터
}	Block;

// 초기 메모리 블록
static Block* head = NULL;

// 간단한 malloc 함수 구현
void*	malloc(size_t size) 
{
	// 메모리 블록의 크기에 추가 정보를 저장하기 위해 sizeof(Block)만큼 추가로 할당
	size_t totalSize = size + sizeof(Block);

	// 새로운 메모리 블록 할당
	Block* block = (Block*)sbrk(totalSize);

	if (block == (void*)-1) 
	{
		// sbrk 호출이 실패한 경우
		return NULL;
	}

	// 메모리 블록 정보 설정
	block->size = size;
	block->next = NULL;

	// 메모리 블록을 연결 리스트에 추가
	if (head == NULL) 
	{
		head = block;
	} 
	else 
	{
		Block* current = head;
		while (current->next != NULL) 
		{
			current = current->next;
		}
		current->next = block;
	}

	// 할당된 메모리 블록의 시작 주소 반환
	return (void*)((char*)block + sizeof(Block));
}

int main() 
{
	int* dynamicArray = (int*)malloc(10 * sizeof(int));

	for (size_t i = 0; i < 10; i++)
	{
		dynamicArray[i] = i;
	}
	
	for (size_t i = 0; i < 10; i++)
	{
		printf("%d ", dynamicArray[i]);
	}
	return 0;
}

/* 
man brk

설명
	brk 및 sbrk 함수는 가상 메모리가 등장하기 전 초창기부터 사용되던 역사적 호기심입니다.
	관리가 등장하기 전의 역사적 호기심입니다.  brk() 함수는 프로세스의 데이터 세그먼트(초기화되지 않은 데이터)의 중단 또는 가장 낮은 주소를 addr
	(bss 바로 위)로 설정합니다.  데이터 주소 지정은 addr과 스택 세그먼트에 대한 가장 낮은 스택 포인터 사이에서 제한됩니다.  메모리
	는 페이지 크기 단위로 brk에 의해 할당되며, addr가 시스템 페이지 크기로 균등하게 나눌 수 없는 경우 다음
	페이지 경계까지 증가합니다.

	프로그램 중단의 현재 값은 "sbrk(0)"에 의해 안정적으로 반환됩니다 (end(3) 참조).  getrlimit(2) 시스템 호출은 다음과 같습니다.
	데이터 세그먼트의 최대 허용 크기를 결정하는 데 사용될 수 있으며, 이 시스템 호출에서 반환된 rlim_max
	값(예: "qetext + rlp→rlim_max")을 초과하여 나누기를 설정할 수 없습니다. (etext의 정의는 end(3)을 참조하십시오).

반환 값
	Brk는 성공하면 메모리의 새 끝을 가리키는 포인터를 반환하고, 그렇지 않으면 할당 실패 이유를 나타내는 errno가 설정된 -1을 반환합니다.
	sbrk 함수는 성공하면 새 스토리지의 베이스에 대한 포인터를 반환하고, 그렇지 않으면 -1과 함께 할당 실패 이유를 나타내는 errno가 설정된
	할당에 실패했음을 나타냅니다.
 */
