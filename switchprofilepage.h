#ifndef SWITCHPROFILEPAGE_H
#define SWITCHPROFILEPAGE_H

#include <QWidget>

namespace Ui {
class SwitchProfilePage;
}

class SwitchProfilePage : public QWidget
{
    Q_OBJECT

public:
    explicit SwitchProfilePage(QWidget *parent = nullptr);
    ~SwitchProfilePage();

private:
    Ui::SwitchProfilePage *ui;

signals:
    void backToMenu();

private slots:
    void doneButtonClicked();
};

#endif // SWITCHPROFILEPAGE_H
