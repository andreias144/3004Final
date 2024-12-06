#ifndef DATAPAGE_H
#define DATAPAGE_H

#include <QWidget>
#include "profile.h"
#include "defs.h"
#include <QStandardItemModel>
#include <QGraphicsPixmapItem>
#include <QAbstractItemView>

namespace Ui {
class DataPage;
}

class DataPage : public QWidget
{
    Q_OBJECT

public:
    explicit DataPage(QWidget *parent = nullptr);
    ~DataPage();
    void loadForNewProfile(Profile*);
    void addScan(Scan*);

private:
    Ui::DataPage *ui;
    void setupOrganTable();
    QStandardItemModel* content;

signals:
    void backToMenu();

private slots:
    void menuButtonClicked();
};

#endif // DATAPAGE_H
