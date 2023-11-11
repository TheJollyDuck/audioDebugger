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
#include "tempSettings.h"

ADMainWindow::ADMainWindow() {
    windowFlags = 0;
    
    if (bShowTopMenu) {windowFlags |= ImGuiWindowFlags_MenuBar;}
    windowFlags |= ImGuiWindowFlags_NoMove;

    const ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->Pos);
    ImGui::SetNextWindowSize(viewport->Size);
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
        if (ImGui::BeginMenu("File")) {
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

        /* Raw Audio Output */
        ImGui::BeginChild("Raw Audio Output", ImVec2(770, 450), ImGuiChildFlags_Border);
        ImGui::SeparatorText("Raw Audio Output");
        ImGui::EndChild();

        /* Downmixed Mono Audio Output */
        ImGui::SameLine();
        ImGui::BeginChild("Mono Audio Downmix", ImVec2(770, 450), ImGuiChildFlags_Border);
        ImGui::SeparatorText("Mono Audio Downmix");
        ImGui::EndChild();

        /* Spectrogram Output */
        ImGui::BeginChild("Spectrogram", ImVec2(1150, 450), ImGuiChildFlags_Border);
        ImGui::SeparatorText("Spectrogram");
        ImGui::EndChild();

        /* Configuration */
        ImGui::SameLine();
        ImGui::BeginChild("Configuration", ImVec2(390, 450), ImGuiChildFlags_Border);
        ImGui::SeparatorText("Configuration");
        ImGui::PushItemWidth(100.f);

        if (ImGui::TreeNode("Audio")) {
            ImGui::InputFloat("Mono Audio Gain", &tempConf_AudioGain);
            ImGui::InputInt("Sampling Rate (Hz)", &tempConf_SamplingRate);
            ImGui::TreePop();
        }

        if (ImGui::TreeNode("Spectrogram")) {
            ImGui::InputInt("FFT Size", &tempConf_FFTSize);
            ImGui::InputInt("FFT Step", &tempConf_FFTStep);
            ImGui::InputInt("Number of FFTs", &tempConf_NumFFTs);
            ImGui::TreePop();
        }

        if (ImGui::TreeNode("Whistle Detector")) {
            ImGui::InputInt("Detection Timeout (ms)", &tempConf_DetTimeoutMs);
            ImGui::InputFloat("Whistle Bias", &tempConf_WhistleBias);
            ImGui::InputFloat("Lower Whistle Confidence Threshold", &tempConf_WhistleConfidenceThresh);
            ImGui::InputFloat("Upper Whistle Confidence Threshold", &tempConf_UpperWhistleConfidenceThresh);
            ImGui::InputInt("Confidence Averaging Length", &tempConf_AveragingLen);
            ImGui::TreePop();
        }
        
        ImGui::EndChild();

        // static float arr[] = { 0.6f, 0.1f, 1.0f, 0.5f, 0.92f, 0.1f, 0.2f };
        // ImGui::PlotLines("Frame Times", arr, IM_ARRAYSIZE(arr));

        // // Fill an array of contiguous float values to plot
        // // Tip: If your float aren't contiguous but part of a structure, you can pass a pointer to your first float
        // // and the sizeof() of your structure in the "stride" parameter.
        // static float values[90] = {};
        // static int values_offset = 0;
        // static double refresh_time = 0.0;
        // if (!animate || refresh_time == 0.0)
        //     refresh_time = ImGui::GetTime();
        // while (refresh_time < ImGui::GetTime()) // Create data at fixed 60 Hz rate for the demo
        // {
        //     static float phase = 0.0f;
        //     values[values_offset] = cosf(phase);
        //     values_offset = (values_offset + 1) % IM_ARRAYSIZE(values);
        //     phase += 0.10f * values_offset;
        //     refresh_time += 1.0f / 60.0f;
        // }

        // // Plots can display overlay texts
        // // (in this example, we will display an average value)
        // {
        //     float average = 0.0f;
        //     for (int n = 0; n < IM_ARRAYSIZE(values); n++)
        //         average += values[n];
        //     average /= (float)IM_ARRAYSIZE(values);
        //     char overlay[32];
        //     sprintf(overlay, "avg %f", average);
        //     ImGui::PlotLines("Lines", values, IM_ARRAYSIZE(values), values_offset, overlay, -1.0f, 1.0f, ImVec2(0, 80.0f));
        // }

    }
}