#define _CRTDBG_MAP_ALLOC

#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif


#include "stdafx.h"


using namespace std;


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

//Stack Ŭ���� �׽�Ʈ
	//Stack<int> stack(4);

	//stack.Push(4);

	//stack.Print();

	//auto element = stack.Pop();

	//std::cout <<  "Pop Element : " << element << std::endl;

	//stack.Print();

	//stack.Pop();
//


//Queue Ŭ���� �׽�Ʈ
	//Queue<int> queue;

	//queue.Push(4);
	//queue.Push(3);


	//queue.Print();

	//auto element = queue.Pop();

	//std::cout <<  "Pop Element : " << element << std::endl;

	//queue.Print();

	//queue.Pop();
//

//List Ŭ���� �׽�Ʈ
	//List<int> list;

	//list.PushBack(4);
	//list.PushFront(3);
	//list.PushFront(2);
	//list.PushBack(5);
	//list.PushFront(1);

	//list.Print();

	//auto element = list.PopBack();

	//std::cout <<  "PopBack Element : " << element << std::endl;

	//element = list.PopFront();

	//std::cout << "PopFront Element : " << element << std::endl;

	//list.Print();


	//int i = 2;
	//element = list.At(i);

	//std::cout << "At "<< i <<  " Element : " << element << std::endl;


	//list.PopFront();
	//list.PopFront();
//



//BubbleSort Ŭ���� �׽�Ʈ
	//int arr[] = {4,4,3,2,1};

	//BubbleSorter<int> sorter = BubbleSorter<int>(arr, 5);

	//sorter.Sort();

	//for (auto& element : arr)
	//{
	//	cout << element << ", ";
	//}
	
//


//StringUtil - GetReverseString �޼ҵ� �׽�Ʈ
	//auto pReverse = GetReverseString("hi~");

	//std::cout << pReverse << std::endl;

	//delete pReverse;
//


//StringUtil - GetReverseStringBySTL �޼ҵ� �׽�Ʈ
	//auto pReverse = GetReverseStringBySTL("hi~");

	//std::cout << pReverse << std::endl;

	//delete pReverse;
//

	return 0;

}