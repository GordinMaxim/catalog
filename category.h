#ifndef _CATEGORY_H_
#define _CATEGORY_H_

#include <vector>
#include <string>
#include <algorithm>
#include "product_tree.h"

namespace catalog {
using std::vector;
using std::string;

class Visitor;

class Category : public Component {
public:
	typedef vector<Component*>::iterator ChildIterator;

    Category(const string &name);
    string getName() const;
    void setName(const string &name);
    void addChild(Component *child);
    ChildIterator begin();
    ChildIterator end();
    void removeChild(Component *child);
    void clear();
    void accept(Visitor &v, int state);
	virtual ~Category() {}

protected:
	vector<Component*> children_;
	string name_;
};
/*
template <>
inline void Category<Component>::accept(Visitor &v, int state);
*/
} /*end namespace catalog */

#endif /* _CATEGORY_H_ */