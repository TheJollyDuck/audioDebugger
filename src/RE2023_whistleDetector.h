/*
 *  @name: RE2023_whistleDetector.h
 *
 *  @author: Shauna Recto
 * 
 *  @description: This header file contains all the necessary member
 *     declarations and default initializations of the Whistle Detector class.
 * 
 *     As this is a RoboÉireann project, it currently uses a modified version
 *     of the whistle detector from the rematch codebase.
 */

#ifndef RE_2023_WD_H
#define RE_2023_WD_H

    class AD_RE2023_Whistle_Detector {
        private:
            float lowerConfidenceThresh;
            float upperConfidenceThresh;

        public:
            AD_RE2023_Whistle_Detector();
            ~AD_RE2023_Whistle_Detector();
    };

#endif /* RE_2023_WD_H */