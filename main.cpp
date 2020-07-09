#include "factory.h"

void exec()
{
	std::shared_ptr<Node> arr = createGroup();
	arr->add( createNum(3) );
	arr->add( createNum(4) );
	arr->add( createNum(6) );

	std::shared_ptr<Node> obj = createGroup();
	obj->add(createPair("key1", createString("big data")));
	obj->add(createPair("key2", createString("big data")));
	obj->add(createPair("key3", createString("big data")));
	obj->add(createPair("nums", createArr(arr)));

	obj->add(createPair("proxy", NodePtr( new ProxyNode<NumNode, int, 778>() ) ));

	std::shared_ptr<INode> res = createObj(obj);
	res->draw();
	std::cout << std::endl;
	res->draw();
	std::cout << std::endl;
}

int main(int argc, char* argv[])
{
	exec();
	return 0;
}