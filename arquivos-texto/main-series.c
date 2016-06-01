#include "series.h"

int main() {
	BDSeries bd;
	
	bd = leBDSeries("series.in");
	
	imprimeSeries(bd);
	
	gravaBDSeries(bd, "series.out");
	destroiBDSeries(bd);


	return(0);
}





