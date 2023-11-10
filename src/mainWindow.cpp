/*
 *
 *
 * 
 * 
 * 
 * 
 */

#include <fmt/core.h>
#include "mainWindow.h"

#include "imgui.h"

ADMainWindow::ADMainWindow() {
    isOpen = true;
    showOscilloscope = false;
}

ADMainWindow::~ADMainWindow() {

}

void ADMainWindow::update() {
    ImGui::Begin(PROGRAM_NAME.c_str());
    ImGui::End();
    showMenu();
}

void ADMainWindow::showMenu() {

    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("Menu")) {
            ImGui::MenuItem("Open", nullptr, nullptr);
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("View")) {
            ImGui::SeparatorText("Audio Viewers");
            ImGui::MenuItem("Oscilloscope", NULL, &showOscilloscope);
            ImGui::SeparatorText("Other Tools");
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
}