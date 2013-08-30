#ifndef REPO_ITEM_H
#define REPO_ITEM_H

#include <QWidget>
#include "ui_repo-item.h"
#include "rpc/local-repo.h"

class RepoItem : public QWidget,
                 public Ui::RepoItem
{
    Q_OBJECT

public:
    RepoItem(const LocalRepo& repo, QWidget *parent=0);

    void refresh();

    const LocalRepo& repo() const { return repo_; }

private:
    LocalRepo repo_;
};


#endif // REPO_ITEM_H
