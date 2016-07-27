#include "category.h"
#include "visitor.h"
#include "product_tree.h"

namespace catalog {

template <>
void Category<Component>::accept(Visitor &v, int state) {
	v.visit(this, state);
}

}