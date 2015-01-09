#include <iostream>
#include "signal.hpp"
#include "signal2d.hpp"
#include "signalprocessing.hpp"
#include "bmp.hpp"

int main(void)
{
	////////////////////////////////////////////////
	///	DEBUG
	////////////////////////////////////////////////

	// Signal signal(8);
	// for(int i = 0; i<signal.getSize(); ++i)
	// 	signal[i] = i;

	// Signal filtre(5);
	// filtre[2] = 1;
	// Signal cpy = signal;
	// tools::filtrage(cpy, filtre);
	// cpy.save("test.dat");
	

	//////////////////////////////////////////////
	/// LELECUM
	//////////////////////////////////////////////

	/*Signal signal;
	signal.load("./data/leleccum.txt");

	tools::haar::analyse(signal);
	signal.savepng("./data/leleccum/haaranalyse.png");
	tools::haar::synthese(signal);
	signal.savepng("./data/leleccum/haar.png");
	tools::biortho97::analyse(signal);
	signal.savepng("./data/leleccum/biortho97analyse.png");
	tools::biortho97::synthese(signal);
	signal.savepng("./data/leleccum/biortho97.png");*/

	/*
	Signal signalHaar = signal;
	Signal signalLift = signal;
	Signal signalBiortho = signal;
	Signal signalAMR = signal;
	tools::lifting::analyse(signalLift);
	tools::lifting::synthese(signalLift);
	tools::haar::analyse(signalHaar);
	tools::haar::synthese(signalHaar);
	tools::biortho97::analyse(signalBiortho);
	tools::biortho97::synthese(signalBiortho);
	tools::amr::analyse(signalBiortho, 1);
	tools::amr::synthese(signalBiortho, 1);
	signalLift.savepng("./data/test.png");
	signalLift.save("./data/test1.dat");
	signalBiortho.savepng("./data/test2.png");
	signalBiortho.save("./data/test2.dat");
	signalHaar.savepng("./data/test3.png");
	signalHaar.save("./data/test3.dat");
	signal.save("./data/test.dat");
	signal.savepng("./data/base.png");
	//signalHaar.savepng("./data/test2.png");
	std::cout << "Error: " << tools::significantError(signal, signal) << std::endl;
	std::cout << "Error Lift: " << tools::significantError(signal, signalLift) << std::endl;
	std::cout << "Error Haar: " << tools::significantError(signal, signalHaar) << std::endl;
	std::cout << "Error Biortho: " << tools::significantError(signal, signalBiortho) << std::endl;
	*/

	//////////////////////////////////////////////
	/// RAMPE
	//////////////////////////////////////////////
/*
	Signal rampe(256);
	for(int i = 0; i<rampe.getSize(); ++i)
		rampe[i] = i;

	tools::haar::analyse(rampe);
	rampe.savepng("./data/rampe/haaranalyse.png");
	tools::haar::synthese(rampe);
	rampe.savepng("./data/rampe/haar.png");
	tools::biortho97::analyse(rampe);
	rampe.savepng("./data/rampe/biortho97analyse.png");
	tools::biortho97::synthese(rampe);
	rampe.savepng("./data/rampe/biortho97.png");*/

	//////////////////////////////////////////////
	/// LENA SIGNAL
	//////////////////////////////////////////////
	Signal2D lena2D;
	lena2D.load("./data/lena.bmp");
	
	Signal lena512 = lena2D.getLine(255);
	//lena512.load("./data/lena.txt");
	Signal lena512origine = lena512;
	// tools::haar::analyse(lena512);
	// lena512.savepng("./data/lena512/haaranalyse.png");
	// tools::haar::synthese(lena512);
	// lena512.savepng("./data/lena512/haar.png");
	// tools::biortho97::analyse(lena512);
	// lena512.savepng("./data/lena512/biortho97analyse.png");
	// tools::biortho97::synthese(lena512);
	// lena512.savepng("./data/lena512/biortho97.png");
	// tools::lifting::analyse(lena512);
	// lena512.savepng("./data/lena512/liftinganalyse.png");
	// tools::lifting::synthese(lena512);
	// lena512.savepng("./data/lena512/lifting.png");

	/*
		Q : Tracez et commentez les courbes des coefficients.
		Décrivez les interêts du "lifting".
		R : Même resultat mais plus facile à réutiliser/implementer?
	*/

	// AMR
	try{

		/*Signal lena512_1 = lena512;
		tools::amr::analyse(lena512_1, 1);
		tools::minMaxAverage(lena512_1, 1);
		tools::amr::synthese(lena512_1, 1);

		Signal lena512_2 = lena512;
		tools::amr::analyse(lena512_2, 2);
		tools::minMaxAverage(lena512_2, 2);
		tools::amr::synthese(lena512_2, 2);

		Signal lena512_4 = lena512;
		tools::amr::analyse(lena512_4, 4);
		tools::minMaxAverage(lena512_4, 4);
		lena512_4.savepng("./data/lena512/liftinganalyse_4.png");
		tools::amr::synthese(lena512_4, 4);

		std::cout << tools::significantError(lena512_4, lena512origine) << std::endl;
	*/
		/*tools::biortho97::analyse(lena2D);

		lena2D.save("./data/lenaBmp/test.bmp");
		Signal2D tmp = lena2D.subSignal(0,0,256);*/
		tools::amr::analyse(lena2D, 3);
		lena2D.save("./data/lenaBmp/test.bmp");
		tools::amr::synthese(lena2D, 3);
		lena2D.save("./data/lenaBmp/test2.bmp");
	} catch(const std::string& s)
	{
		std::cerr << "EXCEPTION: " << s << std::endl;
	}



	/* 
		Q: Niveau maximal de décompositions pour un signal de taille p?
		R: log2(p)
	
		Q: Montrer de manière objective que le signal reconstruit est identique
		au signal d'origine.
		R: Calcul de l'erreur significative pour les deux signaux.

		Q: Si l'on réalise une amr de niveau j combien de sous bande obtient-on ?
		R: j + 1 avec j sous bande de détails et une sous bande d'approximation.

			A 		 D2			D1
		|--------|--------|----------------|	
	*/

	


	//////////////////////////////////////////////
	/// LENA BMP
	//////////////////////////////////////////////

	return 0;
}