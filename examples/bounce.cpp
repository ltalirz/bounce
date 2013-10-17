#include "types.hpp"
using namespace types;
#include "parsers.hpp"
#include "state.hpp"

int main(int ac, char* av[]) {

    InputParser p(ac, av);

    Bounce mycalc();
    mycalc.init(p);

    mycalc.calculate();

    return 0;
}

