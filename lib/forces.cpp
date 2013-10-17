/*
 * forces.cpp
 */

#include "forces.hpp"
#include "types.hpp"
using namespace types;

void LennardJones::update(State &s){

    size_t i,j,d, N = s.N;

    real_t r, rx, ry, rz, f;
    real_t pow6, pow12;
    for(i=0; i < N; ++i){
        for(j=i+1; j < N; ++j) {
            r = dist(i,j);
            if (r < rcut){

                pow6 = pow(sigma/r, 6.0);
                pow12 = pow(sigma/r, 12.0);

                s.ePot += 4.0*epsilon*(pow12 - pow6);

                f = -4.0*epsilon*(
                     -12.0*pow12 +6.0*pow6
                    ) /r;
                for(d=0; d<3; ++d){
                    s.f(i,d) += (s.x(i,d)-s.x(j,d))/r * f;
                    s.f(j,d) -= (s.x(i,d)-s.x(j,d))/r * f;
                }
            }
        }
    }
}

    
#endif