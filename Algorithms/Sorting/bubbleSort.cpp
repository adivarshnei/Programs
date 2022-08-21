#include <iostream>
#include <random>

class Sorting {
private:
    const int ARRAY_SIZE = 50;
    const int ELEM_LIMIT = 10;
    int*      array;

public:
    Sorting();
    Sorting* init_array_values();
    void     sort();
};

Sorting::Sorting() {
    this->array = new int[ARRAY_SIZE];
}

Sorting*
Sorting::init_array_values() {
    return this;
}

// Add lambda for sorting functions as argument
void
Sorting::sort() { }

int
main(int argc, char** argv) {
    Sorting().init_array_values()->sort([](){});
}
