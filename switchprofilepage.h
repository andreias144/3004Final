#ifndef SWITCHPROFILEPAGE_H
#define SWITCHPROFILEPAGE_H

#include "AppManager.h"
#include <QWidget>
#include <QSettings>

namespace Ui {
class SwitchProfilePage;
}

class SwitchProfilePage : public QWidget
{
    Q_OBJECT

public:
    explicit SwitchProfilePage(AppManager* appManager, QWidget *parent = nullptr);
    ~SwitchProfilePage();

private:
    Ui::SwitchProfilePage *ui;
    AppManager* appManager;
    void loadProfiles();

signals:
    void backToMenu();
    void profileSwitched();

private slots:
    void doneButtonClicked();
    void switchButtonClicked();
    void profileSelectionChanged();

protected:
    void showEvent(QShowEvent *event) override;
};

#endif
