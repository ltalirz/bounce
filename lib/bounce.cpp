/*
 * bounce.cpp
 */

#include "bounce.hpp"
#include "types.hpp"
using namespace types;
#include "time.hpp"

void Bounce::calculate(){

    Timer timer = Timer();

    std::cout << "Starting calculation.\n";
    timer.print();

    while( ! integrator->done() ){
        integrator->dostep(state);
        
        out.write(integrator, state);
    }


    std::cout << "Done with calculation.\n";
    timer.print();
}
