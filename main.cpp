#include "factory.h"
#include "adapter.h"
#include "flyweight.h"

void exec(IDrawer & d)
{
	std::shared_ptr<Node> arr = createGroup();
	arr->add( createNum(3) );
	arr->add( createNum(4) );
	arr->add( createNum(6) );

	std::map<std::string, double> mapObject;
	mapObject["height"] = 4.1;
	mapObject["width"] = 2.4;
	mapObject["depth"] = 2.2;

	std::shared_ptr<Node> obj = createGroup();
	obj->add(createPair("params", NodePtr(new MapAdapterNode(mapObject))) );
	obj->add(createPair("key1", createFlyweightString("big data")));
	obj->add(createPair("key2", createFlyweightString("big data")));
	obj->add(createPair("key3", createFlyweightString("big data 2")));
	obj->add(createPair("nums", createArr(arr)));

	obj->add(createPair("proxy", NodePtr( new ProxyNode<NumNode, int, 778>() ) ));

	std::shared_ptr<INode> res = createObj(obj);
	res->draw(d);
	d.draw("\n");
	res->draw(d);
	d.draw("\n");
}

int main(int argc, char* argv[])
{
	ConsoleDrawer d;
	exec(d);
	return 0;
}cd ..

// {
//    "params":{
//       "depth":2.2,
//       "height":4.1,
//       "width":2.4
//    },
//    "key1":"big data",
//    "key2":"big data",
//    "key3":"big data",
//    "nums":[
//       3,
//       4,
//       6
//    ],
//    "proxy":778
// }