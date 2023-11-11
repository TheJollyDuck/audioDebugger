/*
 *
 *
 * 
 * 
 * 
 * 
 */

#include <cmath>
#include <fmt/core.h>
#include "mainWindow.h"

ADMainWindow::ADMainWindow() {
    windowFlags = 0;
    
    if (bShowTopMenu) {windowFlags |= ImGuiWindowFlags_MenuBar;}
}

ADMainWindow::~ADMainWindow() {

}

void ADMainWindow::update() {
    ImGui::Begin(PROGRAM_NAME.c_str(), &isOpen, windowFlags);
    showMenu();
    showOscilloscope();
    ImGui::End();   
}

void ADMainWindow::showMenu() {

    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("Menu")) {
            ImGui::MenuItem("Open Audio File", nullptr, nullptr);
            ImGui::MenuItem("Open Video File", nullptr, nullptr);
            ImGui::MenuItem("Open Open B-Human Log", nullptr, nullptr);
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("View")) {
            ImGui::SeparatorText("Audio Viewers");
            ImGui::MenuItem("Audio Timeline", NULL, &bShowAudioTimeline);
            ImGui::MenuItem("Oscilloscope", NULL, &bShowOscilloscope);
            ImGui::MenuItem("Spectrogram", NULL, &bShowSpectrogram);
            ImGui::SeparatorText("Other Tools");
            ImGui::MenuItem("NN Output", NULL, &bShowNNOutput);
            ImGui::MenuItem("Video", NULL, &bShowVideo);
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
}

void ADMainWindow::showOscilloscope() {

    if (bShowOscilloscope) {
        static bool animate = true;
        ImGui::Checkbox("Animate", &animate);

        static float arr[] = { 0.6f, 0.1f, 1.0f, 0.5f, 0.92f, 0.1f, 0.2f };
        ImGui::PlotLines("Frame Times", arr, IM_ARRAYSIZE(arr));
        ImGui::PlotHistogram("Histogram", arr, IM_ARRAYSIZE(arr), 0, NULL, 0.0f, 1.0f, ImVec2(0, 80.0f));

        // Fill an array of contiguous float values to plot
        // Tip: If your float aren't contiguous but part of a structure, you can pass a pointer to your first float
        // and the sizeof() of your structure in the "stride" parameter.
        static float values[90] = {};
        static int values_offset = 0;
        static double refresh_time = 0.0;
        if (!animate || refresh_time == 0.0)
            refresh_time = ImGui::GetTime();
        while (refresh_time < ImGui::GetTime()) // Create data at fixed 60 Hz rate for the demo
        {
            static float phase = 0.0f;
            values[values_offset] = cosf(phase);
            values_offset = (values_offset + 1) % IM_ARRAYSIZE(values);
            phase += 0.10f * values_offset;
            refresh_time += 1.0f / 60.0f;
        }

        // Plots can display overlay texts
        // (in this example, we will display an average value)
        {
            float average = 0.0f;
            for (int n = 0; n < IM_ARRAYSIZE(values); n++)
                average += values[n];
            average /= (float)IM_ARRAYSIZE(values);
            char overlay[32];
            sprintf(overlay, "avg %f", average);
            ImGui::PlotLines("Lines", values, IM_ARRAYSIZE(values), values_offset, overlay, -1.0f, 1.0f, ImVec2(0, 80.0f));
        }

        // Use functions to generate output
        // FIXME: This is actually VERY awkward because current plot API only pass in indices.
        // We probably want an API passing floats and user provide sample rate/count.
        struct Funcs
        {
            static float Sin(void*, int i) { return sinf(i * 0.1f); }
            static float Saw(void*, int i) { return (i & 1) ? 1.0f : -1.0f; }
        };
        static int func_type = 0, display_count = 70;
        ImGui::SeparatorText("Functions");
        ImGui::SetNextItemWidth(ImGui::GetFontSize() * 8);
        ImGui::Combo("func", &func_type, "Sin\0Saw\0");
        ImGui::SameLine();
        ImGui::SliderInt("Sample count", &display_count, 1, 400);
        float (*func)(void*, int) = (func_type == 0) ? Funcs::Sin : Funcs::Saw;
        ImGui::PlotLines("Lines", func, NULL, display_count, 0, NULL, -1.0f, 1.0f, ImVec2(0, 80));
        ImGui::PlotHistogram("Histogram", func, NULL, display_count, 0, NULL, -1.0f, 1.0f, ImVec2(0, 80));
    }
}