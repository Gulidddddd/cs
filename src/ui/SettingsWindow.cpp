#include "SettingsWindow.h"
#include "imgui.h"

namespace UI {

SettingsWindow::SettingsWindow() {
    m_tempSettings = m_settings;
}

void SettingsWindow::Render(bool* p_open) {
    if (!*p_open) return;

    ImGui::SetNextWindowSize(ImVec2(750, 500), ImGuiCond_FirstUseEver);
    ImGuiWindowFlags flags = ImGuiWindowFlags_NoCollapse;

    if (ImGui::Begin("Panel de Configuración", p_open, flags)) {

        ImGui::TextDisabled("Ajusta las preferencias globales de la aplicación.");
        ImGui::Separator();
        ImGui::Spacing();

        const char* categories[] = { " General", " Gráficos", " Audio", " Red y Conexión" };

        ImGui::Columns(2, "SettingsLayout", false);
        ImGui::SetColumnWidth(0, 180.0f);

        // Menú Lateral
        for (int i = 0; i < 4; i++) {
            bool is_selected = (m_activeTab == i);
            if (ImGui::Selectable(categories[i], is_selected, 0, ImVec2(0, 32.0f))) {
                m_activeTab = i;
            }
        }

        ImGui::NextColumn();

        // Contenido Principal
        ImGui::BeginChild("SettingsContent", ImVec2(0, -40), true);

        switch (m_activeTab) {
            case 0: // GENERAL
                ImGui::TextColored(ImVec4(0.38f, 0.61f, 1.00f, 1.00f), "Perfil y Preferencias Generales");
                ImGui::Separator();
                ImGui::Spacing();

                ImGui::InputText("Nombre de Usuario", m_tempSettings.username, IM_ARRAYSIZE(m_tempSettings.username));
                {
                    const char* languages[] = { "Español", "English", "Français", "Deutsch" };
                    ImGui::Combo("Idioma", &m_tempSettings.language_idx, languages, IM_ARRAYSIZE(languages));
                }
                ImGui::Spacing();
                ImGui::Checkbox("Actualizar automáticamente", &m_tempSettings.auto_update);
                ImGui::Checkbox("Iniciar con el sistema operativo", &m_tempSettings.launch_on_startup);
                break;

            case 1: // GRÁFICOS
                ImGui::TextColored(ImVec4(0.38f, 0.61f, 1.00f, 1.00f), "Pantalla y Rendimiento");
                ImGui::Separator();
                ImGui::Spacing();

                {
                    const char* resolutions[] = { "1280x720 (HD)", "1600x900", "1920x1080 (FHD)", "2560x1440 (2K)", "3840x2160 (4K)" };
                    ImGui::Combo("Resolución", &m_tempSettings.resolution_idx, resolutions, IM_ARRAYSIZE(resolutions));

                    const char* display_modes[] = { "Ventana", "Pantalla Completa", "Ventana sin Bordes" };
                    ImGui::Combo("Modo de Pantalla", &m_tempSettings.display_mode, display_modes, IM_ARRAYSIZE(display_modes));
                }

                ImGui::SliderFloat("Brillo", &m_tempSettings.brightness, 0.5f, 1.5f, "%.2f");
                ImGui::SliderInt("Límite de FPS", &m_tempSettings.target_fps, 30, 240);
                ImGui::Spacing();
                ImGui::Checkbox("Sincronización Vertical (V-Sync)", &m_tempSettings.vsync);
                ImGui::Checkbox("Anti-Aliasing (MSAA)", &m_tempSettings.anti_aliasing);
                break;

            case 2: // AUDIO
                ImGui::TextColored(ImVec4(0.38f, 0.61f, 1.00f, 1.00f), "Volumen y Salida de Audio");
                ImGui::Separator();
                ImGui::Spacing();

                ImGui::SliderFloat("Volumen General", &m_tempSettings.master_volume, 0.0f, 1.0f, "%.0f%%");
                ImGui::SliderFloat("Música", &m_tempSettings.music_volume, 0.0f, 1.0f, "%.0f%%");
                ImGui::SliderFloat("Efectos de Sonido (SFX)", &m_tempSettings.sfx_volume, 0.0f, 1.0f, "%.0f%%");
                ImGui::Spacing();
                ImGui::Checkbox("Silenciar al perder el foco de la ventana", &m_tempSettings.mute_on_focus_loss);
                break;

            case 3: // RED
                ImGui::TextColored(ImVec4(0.38f, 0.61f, 1.00f, 1.00f), "Conexión y Servidor");
                ImGui::Separator();
                ImGui::Spacing();

                ImGui::InputText("Dirección IP Servidor", m_tempSettings.server_ip, IM_ARRAYSIZE(m_tempSettings.server_ip));
                ImGui::InputInt("Puerto", &m_tempSettings.port);
                ImGui::Checkbox("Habilitar conexión vía Proxy", &m_tempSettings.enable_proxy);
                break;
        }

        ImGui::EndChild();

        // Botones de acción inferiores
        ImGui::Columns(1);
        ImGui::Separator();
        ImGui::Spacing();

        float button_width = 110.0f;
        ImGui::SetCursorPosX(ImGui::GetWindowWidth() - (button_width * 2 + 25.0f));

        if (ImGui::Button("Cancelar", ImVec2(button_width, 0))) {
            m_tempSettings = m_settings; // Descarta los cambios
        }

        ImGui::SameLine();

        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.20f, 0.50f, 0.85f, 1.00f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.30f, 0.60f, 0.95f, 1.00f));
        if (ImGui::Button("Guardar", ImVec2(button_width, 0))) {
            m_settings = m_tempSettings; // Aplica los cambios
        }
        ImGui::PopStyleColor(2);

        ImGui::End();
    }
}

} // namespace UI