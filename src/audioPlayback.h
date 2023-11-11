/*
 *
 *
 * 
 * 
 * 
 * 
 */

#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
#include <string>

#ifndef AD_AUDIO_PB_H
#define AD_AUDIO_PB_H

    class ADAudioPlayback {
        private:
            ma_result result;
            ma_decoder decoder;
            ma_device_config deviceConfig;
            ma_device device;

        public:
            ADAudioPlayback();
            ADAudioPlayback(std::string);
            ~ADAudioPlayback();

            static void dataCallback(ma_device *, void *, const void *, ma_uint32);
            void playAudio();
    };
    
#endif /* AD_AUDIO_PB_H */