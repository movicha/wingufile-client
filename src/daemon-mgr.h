#ifndef WINGUFILE_CLIENT_DAEMON_MANAGER_H
#define WINGUFILE_CLIENT_DAEMON_MANAGER_H

#include <QObject>
#include <QProcess>

struct _CcnetClient;

class QTimer;

/**
 * Start/Monitor ccnet/wingufile daemon
 */
class DaemonManager : public QObject {
    Q_OBJECT

public:
    DaemonManager();
    void startCcnetDaemon();
    void stopAll();

signals:
    void daemonStarted();

private slots:
    void tryConnCcnet();
    void onCcnetDaemonStarted();
    void onCcnetDaemonExited();
    void onSeafDaemonStarted();
    void onSeafDaemonExited();

private:
    Q_DISABLE_COPY(DaemonManager)

    void startSeafileDaemon();

    QTimer *monitor_timer_;
    QTimer *conn_daemon_timer_;
    QProcess *ccnet_daemon_;
    QProcess *seaf_daemon_;
    _CcnetClient *sync_client_;
};

#endif // WINGUFILE_CLIENT_DAEMON_MANAGER_H
