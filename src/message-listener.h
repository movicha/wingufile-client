#ifndef WINGUFILE_CLIENT_MESSAGE_LISTENER_H
#define WINGUFILE_CLIENT_MESSAGE_LISTENER_H

#include <QObject>

struct _CcnetClient;
struct _CcnetMqclientProc;
struct _CcnetMessage;

class QSocketNotifier;

/**
 * Handles ccnet message
 */
class MessageListener : QObject {
    Q_OBJECT
public:
    MessageListener();

    void connectDaemon();
    void handleMessage(_CcnetMessage *message);

private slots:
    void readConnfd();

private:
    Q_DISABLE_COPY(MessageListener)

    void startMqClient();

    _CcnetClient *async_client_;
    _CcnetMqclientProc *mqclient_proc_;

    QSocketNotifier *socket_notifier_;
};

#endif // WINGUFILE_CLIENT_MESSAGE_LISTENER_H
