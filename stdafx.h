#pragma once
#define _CRTDBG_MAP_ALLOC

#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif


#include <iostream>

#include <algorithm>
#include <queue>
#include <deque>
#include <vector>
#include <unordered_map>
#include <list>

#include <string>

#include "Singleton.h"

#include "Stack.h"
#include "Queue.h"
#include "List.h"
#include "BinaryTree.h"

#include "Search.h"

#include "Sort.h"

#include "StringUtils.h"