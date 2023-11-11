/*
 *
 *
 * 
 * 
 * 
 * 
 */

#include <string>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#ifndef AD_MAIN_WINDOW_H
#define AD_MAIN_WINDOW_H

    class ADMainWindow {
        private:
            bool isOpen = true;
            ImGuiWindowFlags windowFlags;

            bool bShowAudioTimeline = true;
            bool bShowOscilloscope = true;
            bool bShowSpectrogram = true;
            bool bShowTopMenu = true;
            bool bShowVideo = true;
            bool bShowNNOutput = true;

        public:
            static inline std::string PROGRAM_NAME = "RoboÉireann audioDebugger";

            ADMainWindow();
            ~ADMainWindow();

            void update();
            void showMenu();
            void showOscilloscope();
            int parseSettings();
            
    };
#endif /* AD_MAIN_WINDOW_H */