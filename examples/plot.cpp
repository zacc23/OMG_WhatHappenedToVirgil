/*
graph program for the freevirgil package.
*/

#include <TCanvas.h>
#include <TFrame.h>
#include <TGraphSmooth.h>
#include <TAxis.h>

#include <iostream>
#include "spin_conf.h"
#include "hamiltonian.h"

int main()
{
	TCanvas *c1 = new TCanvas("c1", "Plot of Quantities versus Temperature", 
		200, 10, 700, 500);
	c1->SetGrid();
        c1->GetFrame()->SetBorderSize(12);

	// N = 10
        spin_conf spin(10);
        // J = -2, mu = 1.1
        hamiltonian ham(-2, 1.1);

	const int irange = 100;
        double T[irange],
		E[irange],
		M[irange], 
		HC[irange],
	 	MS[irange];

        for (int i = 0; i < irange; i++)
        {
		// start at .1, increment by .1 until end
                T[i] = 0.1 * (i + 1);
		//cout << T[i] << endl;
                ham.avg(spin, T[i], E[i], M[i], HC[i], MS[i]);
		//cout << T[i] << ' ' << E[i] << ' ' << M[i] << 
		//	' ' << HC[i] << ' ' << MS[i] << endl;
        }

	TGraph *EvT = new TGraph(irange, T, E);
	TGraph *MvT = new TGraph(irange, T, M);
        TGraph *HCvT = new TGraph(irange, T, HC);
        TGraph *MSvT = new TGraph(irange, T, MS);

	EvT->SetTitle("Quantities versus Temperature");
	EvT->GetXaxis()->SetTitle("Temperature");
        EvT->GetXaxis()->CenterTitle(true);
	EvT->SetLineWidth(3);
	EvT->SetLineColor(1);
	EvT->GetXaxis()->SetRangeUser(0, 10);
	EvT->GetYaxis()->SetRangeUser(-20, 5);
	EvT->Draw("AC");
	
	MvT->SetLineWidth(3);
        MvT->SetLineColor(2);
        MvT->Draw("CSame");

	HCvT->SetLineWidth(3);
        HCvT->SetLineColor(3);
        HCvT->Draw("CSame");

	MSvT->SetLineWidth(3);
        MSvT->SetLineColor(4);
        MSvT->Draw("CSame");

	c1->Update();
        c1->Print("plot.pdf");
        c1->Print("plot.png");
	
	return 0;
}
