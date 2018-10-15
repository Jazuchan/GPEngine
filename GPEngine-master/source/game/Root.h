#include <memory>
#include <vector>

class Object;
class Domain;
class Keyboard;

class Root
{
public:
	void start();
	void finish();
	std::shared_ptr<Object> addObject();
	std::shared_ptr<Root> load();

private:
	std::vector<std::shared_ptr<Object>> objects;
	std::shared_ptr<Domain> domain();
	std::shared_ptr<Keyboard> keyboard();
	bool active();
};