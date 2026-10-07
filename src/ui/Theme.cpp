#include "Theme.h"
#include "imgui.h"

namespace UI {

void ApplyModernTheme() {
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;

    // Redondeo y geometría
    style.WindowRounding = 8.0f;
    style.FrameRounding = 5.0f;
    style.PopupRounding = 6.0f;
    style.ScrollbarRounding = 6.0f;
    style.GrabRounding = 4.0f;
    style.TabRounding = 5.0f;
    style.WindowPadding = ImVec2(15.0f, 15.0f);
    style.ItemSpacing = ImVec2(10.0f, 8.0f);

    // Paleta de colores
    colors[ImGuiCol_Text]                  = ImVec4(0.92f, 0.93f, 0.95f, 1.00f);
    colors[ImGuiCol_TextDisabled]          = ImVec4(0.50f, 0.55f, 0.60f, 1.00f);
    colors[ImGuiCol_WindowBg]              = ImVec4(0.11f, 0.12f, 0.15f, 1.00f);
    colors[ImGuiCol_ChildBg]               = ImVec4(0.14f, 0.15f, 0.19f, 1.00f);
    colors[ImGuiCol_PopupBg]               = ImVec4(0.14f, 0.15f, 0.19f, 0.98f);
    colors[ImGuiCol_Border]                = ImVec4(0.23f, 0.25f, 0.31f, 0.50f);
    colors[ImGuiCol_FrameBg]               = ImVec4(0.18f, 0.20f, 0.25f, 1.00f);
    colors[ImGuiCol_FrameBgHovered]        = ImVec4(0.24f, 0.27f, 0.34f, 1.00f);
    colors[ImGuiCol_FrameBgActive]         = ImVec4(0.28f, 0.32f, 0.40f, 1.00f);
    colors[ImGuiCol_TitleBg]               = ImVec4(0.11f, 0.12f, 0.15f, 1.00f);
    colors[ImGuiCol_TitleBgActive]         = ImVec4(0.14f, 0.15f, 0.19f, 1.00f);
    colors[ImGuiCol_CheckMark]             = ImVec4(0.38f, 0.61f, 1.00f, 1.00f);
    colors[ImGuiCol_SliderGrab]            = ImVec4(0.38f, 0.61f, 1.00f, 1.00f);
    colors[ImGuiCol_SliderGrabActive]      = ImVec4(0.50f, 0.70f, 1.00f, 1.00f);
    colors[ImGuiCol_Button]                = ImVec4(0.20f, 0.23f, 0.29f, 1.00f);
    colors[ImGuiCol_ButtonHovered]         = ImVec4(0.38f, 0.61f, 1.00f, 1.00f);
    colors[ImGuiCol_ButtonActive]          = ImVec4(0.30f, 0.50f, 0.90f, 1.00f);
    colors[ImGuiCol_Header]                = ImVec4(0.20f, 0.23f, 0.29f, 1.00f);
    colors[ImGuiCol_HeaderHovered]         = ImVec4(0.28f, 0.32f, 0.40f, 1.00f);
    colors[ImGuiCol_HeaderActive]          = ImVec4(0.38f, 0.61f, 1.00f, 1.00f);
    colors[ImGuiCol_Separator]             = ImVec4(0.23f, 0.25f, 0.31f, 1.00f);
    colors[ImGuiCol_Tab]                   = ImVec4(0.14f, 0.15f, 0.19f, 1.00f);
    colors[ImGuiCol_TabHovered]            = ImVec4(0.38f, 0.61f, 1.00f, 0.80f);
    colors[ImGuiCol_TabActive]             = ImVec4(0.24f, 0.27f, 0.34f, 1.00f);
}

} // namespace UI