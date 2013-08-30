#ifndef WINGUFILE_CLIENT_SETTINGS_MANAGER_H
#define WINGUFILE_CLIENT_SETTINGS_MANAGER_H

#include <QObject>

/**
 * Settings Manager handles wingufile client user settings & preferences
 */
class SettingsManager : QObject {
    Q_OBJECT

public:
    SettingsManager();

    void setAutoSync(bool);

    bool autoSync() { return auto_sync_; }

private slots:
    void onSetAutoSyncFinished(bool);

private:
    Q_DISABLE_COPY(SettingsManager)

    bool auto_sync_;
};

#endif // WINGUFILE_CLIENT_SETTINGS_MANAGER_H
