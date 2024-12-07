#ifndef DATAPAGE_H
#define DATAPAGE_H

#include <QWidget>
#include "profile.h"
#include "defs.h"
#include <QStandardItemModel>
#include <QGraphicsPixmapItem>
#include <QAbstractItemView>
#include <QColor>

const QColor AboveAverage(127, 215, 240);
const QColor Average(157, 227, 143);
const QColor BelowAverage(252, 204, 28);

namespace Ui {
class DataPage;
}

class DataPage : public QWidget
{
    Q_OBJECT

public:
    explicit DataPage(QWidget *parent = nullptr);
    ~DataPage();
    void loadForProfile(Profile*);
    void loadHeatmap(QString scanDate);

private:
    Ui::DataPage *ui;
    void setupOrganTable();
    QStandardItemModel* organTableContent;
    Profile* profile;

signals:
    void backToMenu();

private slots:
    void menuButtonClicked();
};

#endif // DATAPAGE_H
