#ifndef MONTECARLO_H
#define MONTECARLO_H

#include <iostream>
#include <random>
#include <cmath>
#include "spin_conf.h"
using namespace std;

class montecarlo {
    /*
    Class for MonteCarlo
	*/
	public:
        int n_sweep; 
        int n_burn;

		montecarlo(int, int);
		spin_conf sweep(hamiltonian, spin_conf);
		void metropolis(hamiltonian, spin_conf, double,
    		double&, double&, double&, double&);
};

montecarlo::montecarlo(int n_sweep=1000, int n_burn=100) {
	/*
	Constructor

	Parameters
	----------
	n_sweep : int, optional
		Number of sweeps
	n_burn : int, optional
		Number to burn
	*/
	this->n_sweep = n_sweep;
	this->n_burn = n_burn;
}

spin_conf montecarlo::sweep(hamiltonian ham, spin_conf spin) {
	/*
	Sweep through all sites to 
	create a new configuration

	Parameters
	----------
	ham : :class:`hamiltonian`
		Ising Hamiltonian
	spin : :class:`spin_conf`
		Spin configuration
	T : int
		Temperature

	Returns
	-------
	spin : :class:`spin_conf`
		New spin configuration
	*/
	for (int i = 0; i < spin.sites; i++)
	{
		// all sites to the right and left
		int rside = (i+1) % spin.sites;
		int lside = (i+1) % spin.sites;

		if (spin.config[lside] == spin.config[rside])
		{
			if (spin.config[lside] == spin.config[i])
			{
				net_E = 4 * ham.J;
			}
			else
			{
				net_E = -4 * ham.J
			}
		}
	}

	# TODO: explain how this works
	double net_E += 2*ham.mu * (2*spin.config[i] - 1); 
	
	bool usable = true;
	if (net_E > 0)
	{
		// generate float between 0 and 1
		double rand = (double) rand() / RAND_MAX;
		if (rand > math.exp( -net_E/T ))
		{
			usable = false;
		}
	}

	if (usable)
	{
		if (spin.config[i] == -1)
		{
			spin.config[i] = 1;
		}
		else
		{
			spin.config[i] = -1;
		}
	}

	return spin;
}

void montecarlo::metropolis(hamiltonian ham, spin_conf spin, double T,
	double& Es, double& Ms, double& EEs, double& MMs)
{
 	/*	
	Metropolis sampling

	Parameters
	----------
	ham : :class:`hamiltonian`
		Ising Hamiltonian
	spin : :class:`spin_conf`
		Spin configuration
	T : float 
		Temperature

	Returns
	-------
	Es : float list
		 Energy of sample
	Ms : float list
		 Magnetization of sample
	EEs : float list
		  Average energy of sample      
	MMs : float list
		  Average magnetization of sample
	*/
	// samples
	double Es[this->n_sweep],
		   Ms[this->n_sweep],
		   EEs[this->n_sweep],
		   MMs[this->n_sweep];

	for (int site = 0; site < this->n_burn; site++)
	{
		this->sweep(ham, spin, T);
	}
		
	this->sweep(ham, spin, T);
	double Ei = ham.E(spin);
	double Mi = spin.M();

	Es[0] = Ei;
	Ms[0] = Mi;
	MMs[0] = Mi * Mi;
	EEs[0] = Ei * Ei;

	for (int s = 1; s < this->n_sweep; s++)
	{	
		self.sweep(ham, spin, T)
		Ei = ham.E(spin)
		Mi = spin.M()

		Es[s] = (Es[s - 1]*s + Ei) / (s + 1)
		EEs[s] = (EEs[s - 1]*s + Ei*Ei) / (s + 1)

		Ms[s] = (Ms[s - 1]*s + Mi) / (s + 1)
		MMs[s] = (MMs[s - 1]*s + Mi*Mi) / (s + 1)
	}

	return Es, Ms, EEs, MMs
}

#endif // MONTECARLO_H
