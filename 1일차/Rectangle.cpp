#include "Rectangle.h"

int main() {
	Shape* s = new Rectangle;
	s->scale ();
	delete s;

	Rectangle* r = new Rectangle;
	r->draw();
	delete r;
}