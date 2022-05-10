#include <TCanvas.h>
#include <TFrame.h>
#include <TAxis.h>
#include <TGraph.h>
#include <TLegend.h>

#include <iostream>
#include "spin_conf.h"
#include "hamiltonian.h"
#include "montecarlo.h"

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
	// n_sweep=40000, n_burn=2000
	montecarlo mcarlo(40000, 2000);

	const int irange = 100;
		T[irange],
		E[irange],
		M[irange],
		EE[irange],
		MM[irange],
		EvT[irange],
		MvT[irange],
		MMvT[irange],
		HCvT[irange],
		MSvT[irange];

	for (int i = 0; i < irange; i++)
	{
		T[i] = 0.1 * (i + 1) + 1;

		mcarlo.metropolis(ham, spin, T[i],
			E, M, EE, MM); 

		EvT[i] = E[irange - 1];
		MvT[i] = M[irange - 1];
		EEvT[i] = EE[irange - 1];
		MMvT[i] = MM[irange - 1];

		HCvT[i] = (EEvT[i] - EvT[i]*EvT[i]) / (T[i]*T[i]);
		MSvT[i] = (MMvT[i] - MvT[i]*MvT[i]) / T[i];
		cout << EvT[i] << ' ' << MvT[i] << ' ' <<
			HCvT[i] << ' ' << MSvT[i];
	}

	TGraph *EvT = new TGraph(irange, T, EvT);
	TGraph *MvT = new TGraph(irange, T, MvT);
        TGraph *HCvT = new TGraph(irange, T, HCvT);
        TGraph *MSvT = new TGraph(irange, T, MSvT);
	TLegend *leg = new TLegend(0.75, 0.1, 0.9, 0.3);

	EvT->SetTitle("Approximated Quantities versus Temperature");
	EvT->GetXaxis()->SetTitle("Temperature");
        EvT->GetXaxis()->CenterTitle(true);
	EvT->GetXaxis()->SetRangeUser(0, 10);
        EvT->GetYaxis()->SetRangeUser(-20, 5);
	EvT->SetLineWidth(3);
	EvT->SetLineColor(1);
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

	//leg->SetHeader("The Legend Title");
	leg->AddEntry(EvT, "<E>", "l");
	leg->AddEntry(MvT, "<M>", "l");
	leg->AddEntry(HCvT, "HC", "l");
	leg->AddEntry(MSvT, "MS", "l");
	leg->Draw();

	c1->Update();
        c1->Print("plot.pdf");
        c1->Print("plot.png");
	
	return 0;
}
