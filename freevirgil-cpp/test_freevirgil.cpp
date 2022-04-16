/*
Unit and regression test for the freevirgil package.
*/

#include <iostream>
#include <cassert>
#include "spin_conf.h"
#include "hamiltonian.h"

void test_freevirgil_included()
{
	/*
	#include "spin_conf.h"
	assert(SPIN_CONF_H);
	#include "hamiltonian.h"	
	assert(HAMILTONIAN_H);
	*/
}

void test_ham_energy()
{
	// N = 2
        spin_conf spin(2);
	// J = -2, mu = 1.1
        hamiltonian ham(-2, 1.1);

	double E, M, HC, MS;
        ham.avg(spin, 1, E, M, HC, MS);
	
        // E ~= -3.99104425
        assert(-3.9910443 < E < -3.9910442);
        // M ~= -0.00298581
        assert(-0.0029859 < M < -0.0029858);
        // HC ~= 0.05269599
        assert(0.0526959 < HC < 0.0526960);
        // MS ~= 0.00611116
        assert(0.0061111 < MS < 0.0061112);
}
        
int main()
{
        //test_freevirgil_included();
        test_ham_energy();

	return 0;
}
