#pragma once

#include "core/AppSettings.h"

namespace UI {

class SettingsWindow {
public:
    SettingsWindow();
    void Render(bool* p_open);

    const AppSettings& GetSettings() const { return m_settings; }

private:
    AppSettings m_settings;
    AppSettings m_tempSettings;
    int m_activeTab = 0;
};

} // namespace UI