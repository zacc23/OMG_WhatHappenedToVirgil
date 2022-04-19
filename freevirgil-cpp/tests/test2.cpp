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
	cout << SPIN_CONF_H << endl;
	//assert(SPIN_CONF_H);
	#include "hamiltonian.h"	
	cout << HAMILTONIAN_H << endl;
	//assert(HAMILTONIAN_H);
	*/
}

void test_ham_energy()
{
	// N = 2
        spin_conf spin(2);
	// J = -2, mu = 1.1
        hamiltonian ham(-2, 1.1);

	double E = 0.0, M = 0.0, HC = 0.0, MS = 0.0;
        ham.avg(spin, 1, E, M, HC, MS);
	
        // E ~= -3.99104425
	cout << E << endl;
        assert(E < -3.991 && E > -3.992);
        // M ~= -0.00298581
        assert(-0.0029 < M < -0.0030);
        // HC ~= 0.05269599
        assert(0.0526959 < HC < 0.0526960);
        // MS ~= 0.00611116
        assert(0.0061111 < MS < 0.0061112);
}
        
int main()
{
        test_freevirgil_included();
        test_ham_energy();

	return 0;
}
