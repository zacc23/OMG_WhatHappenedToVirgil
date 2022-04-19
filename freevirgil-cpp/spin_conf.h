#ifndef SPIN_CONF_H
#define SPIN_CONF_H

#include <cmath>
using namespace std;

class spin_conf {
    /*
    Class for generating spin configurations   
        of various dimensions
    */
    public:
        
    int sites;
	int dim;
	int config[];    
	spin_conf(int);
	double magnetization();
	void dec_conf(int);
	void set_conf(int[]);
};
        
spin_conf::spin_conf(int N=10) {
    /*
    Initialize configuration

    Parameters
    ----------
    N : int, default: 10
        Amount of sites
    
    Returns
    -------
    */
    this->sites = N;
    this->dim = pow(2, N);
    this->config[N];
}

double spin_conf::magnetization() {
    /*
    Magnetization of configuration

    Parameters
    ----------

    Returns
    -------
    M : float
        magnetization
    */
    int N_up = 0;
    int N_down = 0;

    for (int i = 0; i < this->sites; i++)
    {
        if (this->config[i] == 1)
            N_up += 1;
        else
            N_down += 1;
    }
    return N_up - N_down;
}

void spin_conf::dec_conf(int dec) {
    /*
    Convert decimal to binary (-1, 1)
    spin configuration
    
    Parameters
    ----------
    dec : int
        Decimal number to convert to
        binary (0, 1) -> (-1, 1)

    Returns
    -------
    */
    int conf[this->sites];
    // initialize to 0
    for (int i = 0; i < this->sites; i++)
    {
        conf[i] = 0;
    }
 
    // start at the end
    int i = this->sites - 1;
    while (dec > 0 && i >= 0) 
    {
        conf[i] = dec % 2;
        dec = dec / 2;
        i--;
    }

    // set initial values to -1
    for (int i = this->sites - 1; i >= 0; i--)
    {
        if (conf[i] == 0)
            conf[i] = -1;
    }
    
    for (int i = 0; i < this->sites; i++)
    {   
        this->config[i] = conf[i];
        cout << this->config[i] << " ";
    }
    cout << endl;
}

void spin_conf::set_conf(int conf[]) {
    /*
    Specify binary (-1, 1) 
    spin configuration
    
    Parameters
    ----------
    conf : int list
        Spin configuration list (-1, 1)

    Returns
    -------
    */
    for (int i = 0; i < this->sites; i++)
    {   
        this->config[i] = conf[i];
    }
}

#endif // SPIN_CONF_H
