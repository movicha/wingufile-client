#ifndef WINGUFILE_CLIENT_CONFIGURATOR_H
#define WINGUFILE_CLIENT_CONFIGURATOR_H

#include <QObject>
#include <QString>

/**
 * Handles ccnet/wingufile configuration initialize
 */
class Configurator : public QObject {
    Q_OBJECT

public:
    Configurator();
    void checkInit();

    const QString& ccnetDir() const { return ccnet_dir_; }
    const QString& wingufileDir() const { return wingufile_dir_; }
    const QString& worktreeDir() const { return worktree_; }

private:
    Q_DISABLE_COPY(Configurator)

    bool needInitConfig();
    void initConfig();
    void validateExistingConfig();
    int readSeafileIni(QString *content);

    void initCcnet();
    void initSeafile();

    QString ccnet_dir_;
    QString wingufile_dir_;
    QString worktree_;
};

#endif // WINGUFILE_CLIENT_CONFIGURATOR_H
