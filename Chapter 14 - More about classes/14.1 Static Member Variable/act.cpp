#include <iostream>
#include <iomanip>

using namespace std;


class Tree
{
	private:
		static int objectCount;
	public:
		Tree(){
			objectCount++;
		}

		int getObjectCount() const{
			return  objectCount;
		}
	
};

int Tree::objectCount = 0;

int main(int argc, char const *argv[])
{
	Tree tree1;
	Tree tree2;

	cout << "We have " <<  tree1.getObjectCount()
		 << " trees in out program.\n";
	return 0;
}	