#ifndef DATAPAGE_H
#define DATAPAGE_H

#include <QWidget>

namespace Ui {
class DataPage;
}

class DataPage : public QWidget
{
    Q_OBJECT

public:
    explicit DataPage(QWidget *parent = nullptr);
    ~DataPage();

private:
    Ui::DataPage *ui;

signals:
    void backToMenu();

private slots:
    void menuButtonClicked();
};

#endif // DATAPAGE_H
