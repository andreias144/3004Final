#ifndef PROFILEPAGE_H
#define PROFILEPAGE_H

#include <QWidget>

namespace Ui {
class ProfilePage;
}

class ProfilePage : public QWidget
{
    Q_OBJECT

public:
    explicit ProfilePage(QWidget *parent = nullptr);
    ~ProfilePage();

private:
    Ui::ProfilePage *ui;

signals:
    void backToMenu();

private slots:
    void doneButtonClicked();
};

#endif // PROFILEPAGE_H
