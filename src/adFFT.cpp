/*
 *
 *
 * 
 * 
 * 
 * 
 */

#include <fftw3.h>
#include "adFFT.h"

ADFFT::ADFFT() {

}

ADFFT::~ADFFT() {
    fftwf_destroy_plan(fft);
    fftwf_free(spectrum);
    fftwf_free(samples);
}

void ADFFT::update() {
    
}