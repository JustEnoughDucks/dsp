/**************************************************************************/
//Name:  freqAnalyze.c																										//
//Purpose:  Implement function to compare measured to expected frequency  //
//Author:  Ben Gerber																											//
//Revision:  1.0 13Dec2018	Initial creation															//
//Target:  Freescale K22f																									//
/**************************************************************************/

#include "MK22F51212.h"                				 	//Device header
#include "freqAnalyze.h"

/******************************************************************/
//						Function for Comparing Frequencies									//
/******************************************************************/

// FreqInfo must be redefined because linker doesn't allow multiple .c files 
// accesing same variable in header because of linker multi-definition`
float freqInfo2[88] = { 
27.500000, 
29.135240, 
30.870000, 
32.703200, 
34.647830, 
36.708100, 
41.203440, 
38.890870, 
43.653530, 
46.249300, 
48.999430, 
51.913090, 
55.000000, 
58.270480, 
61.740000, 
65.406400, 
69.295660, 
73.416200, 
82.406880, 
77.781740, 
87.307060, 
92.498600, 
97.998860, 
103.826180, 
110.000000, 
116.540960, 
123.480000, 
130.812800, 
138.591320, 
146.832400, 
164.813760, 
155.563480, 
174.614120, 
184.997200, 
195.997720, 
207.652360, 
220.000000, 
233.081920, 
246.960000, 
261.625600, 
277.182640, 
293.664800, 
329.627520, 
311.126960, 
349.228240, 
369.994400, 
391.995440, 
415.304720, 
440.000000, 
466.163840, 
493.920000, 
523.251200, 
554.365280, 
587.329600, 
659.255040, 
622.253920, 
698.456480, 
739.988800, 
783.990880, 
830.609440, 
880.000000, 
932.327680, 
987.840000, 
1046.502400, 
1108.730560, 
1174.659200, 
1318.510080, 
1244.507840, 
1396.912960, 
1479.977600, 
1567.981760, 
1661.218880, 
1760.000000, 
1864.655360, 
1975.680000, 
2093.004800, 
2217.461120, 
2349.318400, 
2637.020160, 
2489.015680, 
2793.825920, 
2959.955200, 
3135.963520, 
3322.437760, 
3520.000000, 
3729.310720, 
3951.360000, 
4186.009600 
 }; 

uint8_t getTunedFrequency(float f0)
{
	uint8_t fBaseIndex;
	
	for(fBaseIndex = 0; fBaseIndex < 88; fBaseIndex++)
	{
		if(f0 > freqInfo2[0] && f0 < freqInfo2[87])
		{
			if( f0 > freqInfo2[fBaseIndex] && f0 < freqInfo2[fBaseIndex + 1])
			{
				float compare = (freqInfo2[fBaseIndex + 1] + freqInfo2[fBaseIndex])/2 ;
				if(f0 < compare)
				{
					break;
				}else if(f0 > compare)
				{
					fBaseIndex++;
					break;
				}
			}
		}else if(f0 < freqInfo2[0])
		{
			fBaseIndex = 0;
			break;
		}else if(f0 > freqInfo2[87])
		{
			fBaseIndex = 87;
			break;
		}
	}
	
	
	
	return fBaseIndex;
}
