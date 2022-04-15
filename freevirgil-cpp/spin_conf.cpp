#include <cmath>
using namespace std;

class spin_conf {
    /*
    Class for generating spin configurations   
        of various dimensions
    */
    
    private:    

        int sites;
        int dim;
        int[] config;

    public:
        
        spin_conf(int);
        double M();
        double dec_conf(int);
        set_conf(int[]);
        
spin_conf::spin_conf(N=10) {
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
    this->config = [N];

double spin_conf::M() {
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
    for (int i = 0; i < self.sites; i++)
    {
        if (self.config[i] == 1)
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
    bool conf[self.sites];
 
    int i = 0;
    while (dec > 0) 
    {
        conf[i] = dec % 2;
        dec = dec / 2;
        i++;
    }

    for (int i = 0; i < len(conf); i++)
    {
        if (conf[i] == 0)
            conf[i] = -1;
    }
    
    // NOTE: can't be done in c++
    while (len(conf) < self.sites)
        conf = [-1] + conf;
        
    this->config = conf;
}

void spin_conf::set_conf(int[] conf):
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
    this->config = conf; 
