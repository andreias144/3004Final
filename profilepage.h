#ifndef PROFILEPAGE_H
#define PROFILEPAGE_H

#include <QWidget>
#include <QString>

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
    void saveProfileData(const QString& profileName, int age, double height, double weight);
    bool isProfileNameUnique(const QString& profileName);
    int getProfileCount();
};

#endif // PROFILEPAGE_H
