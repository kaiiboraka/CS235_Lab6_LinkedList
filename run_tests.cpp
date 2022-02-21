#include "SLList.h"

template<class T>
void test(const string& message, T const& expected, T const& observed)
{
	cout << message << endl;
	cout << "Expected: >" << expected;
	cout << "< Observed: " << observed << endl;

	if (expected == observed)
	{
		cout << "Passed ✅" << endl;
	}
	else
	{
		cerr << "failed!" << endl;
		throw invalid_argument(message);
	}

}

int run_tests()
{
	SLList<int> list;

	cout << "empty?" << endl;

	//assert(list.isEmpty());
	//assert(list.size() == 0);

	test("empty", true, list.isEmpty());
	test("size", 0, list.size());
	test("toString", (string) "", list.toString());

	try
	{
		list.front();
	}
	catch (exception const& ex)
	{
		cerr << "fix ur crap. Something borked: " << ex.what() << endl;
	}

	list.push_back(1);
	test("empty", false, list.isEmpty());
	test("size", 1, list.size());
	test("front", 1, list.front());

	list.push_back(2);
	test("front", 1, list.front());

	list.push_back(7);
	test("empty", false, list.isEmpty());
	test("size", 3, list.size());
	test("front", 1, list.front());

	test("toString", (string) "1 2 7", list.toString());

	list.pop_front();
	test("size", 2, list.size());
	test("front", 2, list.front());
	test("toString", (string)"2 7", list.toString());


	return 0;
}
//
// Created by Brandon on 2/20/2022.
//

