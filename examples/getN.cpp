/*
testing the speed of the freevirgil package.
*/

#include <iostream>
#include <cassert>
#include "spin_conf.h"
#include "hamiltonian.h"

void test_ham_energy()
{
	int N = 20;
        spin_conf spin(N);
	// J = -2, mu = 1.1
        hamiltonian ham(-2, 1.1);

	double E = 0.0, M = 0.0, HC = 0.0, MS = 0.0;
        ham.avg(spin, 1, E, M, HC, MS);
	
	cout << "E = " << E << endl;
	
	cout << "M = " << M << endl;
	
	cout << "HC = " << HC << endl;
	
	cout << "MS = " << MS << endl;
}
        
int main()
{
        test_ham_energy();

	return 0;
}
