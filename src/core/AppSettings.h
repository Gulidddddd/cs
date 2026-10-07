#pragma once

struct AppSettings {
    // General
    char username[64] = "Usuario_Demo";
    int language_idx = 0;
    bool auto_update = true;
    bool launch_on_startup = false;

    // Gráficos
    int resolution_idx = 2; // 1920x1080
    int display_mode = 0;   // Ventana / Pantalla Completa
    bool vsync = true;
    int target_fps = 60;
    float brightness = 1.0f;
    bool anti_aliasing = true;

    // Audio
    float master_volume = 0.8f;
    float music_volume = 0.6f;
    float sfx_volume = 1.0f;
    bool mute_on_focus_loss = true;

    // Red
    char server_ip[32] = "127.0.0.1";
    int port = 8080;
    bool enable_proxy = false;
};