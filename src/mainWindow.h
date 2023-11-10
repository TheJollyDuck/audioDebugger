/*
 *
 *
 * 
 * 
 * 
 * 
 */

#include <string>

#ifndef AD_MAIN_WINDOW_H
#define AD_MAIN_WINDOW_H

    class ADMainWindow {
        private:
            bool isOpen;

            bool showOscilloscope;

        public:
            static inline std::string PROGRAM_NAME = "RoboÉireann audioDebugger";

            ADMainWindow();
            ~ADMainWindow();

            void update();
            void showMenu();
            int parseSettings();
            
    };
#endif /* AD_MAIN_WINDOW_H */