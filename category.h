#ifndef _CATEGORY_H_
#define _CATEGORY_H_

#include <vector>
#include <string>
#include <algorithm>
// #include "visitor.h"
#include "product_tree.h"


namespace catalog {
using std::vector;
using std::string;

class Visitor;

template <typename TComponent>
class Category : public TComponent {
public:
	typedef typename vector<TComponent*>::iterator ChildIterator;

	Category(const string &name) : name_(name) {}

	string getName() const {
		return name_;
	}

	void setName(const string &name) {
		name_ = name;
	}

	void addChild(TComponent *child) {
		ChildIterator it = std::find(children_.begin(), children_.end(), child);
		if (children_.end() == it) {
			children_.push_back(child);
		}
	}

	ChildIterator begin() {
		return children_.begin();
	}

	ChildIterator end() {
		return children_.end();
	}

	void removeChild(TComponent *child) {
		ChildIterator it = std::find(children_.begin(), children_.end(), child);
		if (children_.end() != it) {
			children_.erase(child);
		}	
	}

	void clear() {
		children_.clear();
	}

	void accept(Visitor &v) {
		// v.visit(this);
	}

	virtual ~Category() {}

protected:
	vector<TComponent*> children_;
	string name_;
};

} /*end namespace catalog */

#endif /* _CATEGORY_H_ */