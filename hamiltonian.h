#ifndef HAMILTONIAN_H
#define HAMILTONIAN_H

#include <iostream>
#include <cmath>
#include "spin_conf.h"
using namespace std;

class hamiltonian {
    /*
    Class for Hamiltonian

    .. math::
        H = -J\\sum_{\\left<ij\\right>} \\sigma_i\\sigma_j + \\mu\\sum_i\\sigma_i
    */
    public:
        double J;
        double mu;

        hamiltonian(double, double);
        double energy(spin_conf);
        void avg(spin_conf, double, 
            double&, double&, double&, double&);
};

hamiltonian::hamiltonian(double J=-2.0, double mu=1.0) {
    /*
    Constructor

    Parameters
    ----------
    J : float, optional
        Coupling strength
    mu : float, optional
        Chemical potential
    */ 
    this->J = J;
    this->mu = mu;
}
        
double hamiltonian::energy(spin_conf spin) {
    /*
    Energy of configuration `spin`

    .. math::
            E = \\left<\\hat{H}\\right> 

    Parameters
    ----------
    spin : :class:`spin_conf`
        Spin configuration

    Returns
    -------
    energy : float
        Energy of configuration
    */
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < spin.sites - 1; i++)
    {
        sum1 += spin.config[i] * spin.config[i + 1];
        sum2 += spin.config[i];
        // Periodic boundary conditions
        if (i == spin.sites - 2)
        {
            sum1 += spin.config[i + 1] * spin.config[0];
            sum2 += spin.config[i + 1];
        }
    }
    return (-(this->J) * sum1) + (this->mu * sum2);      
}

void hamiltonian::avg(spin_conf spin, double T, 
    double& E, double& M, double& HC, double& MS)
{
    /*
    Exact average values

    Parameters
    ----------
    spin : :class:`spin_conf`
        Spin configuration
    T : float
        Temperature
    
    Returns 
    -------
    E : float
        Energy of configuration 
    M : float
        Magnetization of configuration
    HC : float
        Heat capacity
    MS : float
        Magnetic susceptability
    */     
     
    E = M = HC = MS = 0.0;
    double Z = 0.0,
           Zi = 0.0,
           Ei = 0.0,
           Mi = 0.0,
           EE = 0.0,
           MM = 0.0;
    
    for (int i=0; i < spin.dim; i++)
    {               
        // generate each possible configuration
        spin.dec_conf(i);
        
        Ei = this->energy(spin);
        Zi = exp( -Ei/T );
        E += Ei * Zi;
        EE += Ei * Ei * Zi;
        
        Mi = spin.magnetization();
        M += Mi * Zi;
        MM += Mi * Mi * Zi;
        Z += Zi;
    }
          
    E = E/Z;
    M = M/Z;
    EE = EE/Z;
    MM = MM/Z;

    HC = (EE - E*E) / (T*T);
    MS = (MM - M*M) / T;

	cout << E << ' ' << M << ' ' << EE	<< ' ' 
		<< MM << ' ' << HC << ' ' << MS << endl;
}

#endif // HAMILTONIAN_H
