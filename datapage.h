#ifndef DATAPAGE_H
#define DATAPAGE_H

#include <QWidget>
#include "profile.h"
#include "diagnosis.h"
#include "defs.h"
#include <QStandardItemModel>
#include <QGraphicsPixmapItem>
#include <QAbstractItemView>
#include <QColor>

const QColor belowNormalColour(255, 228, 138);
const QColor normalColour(233, 240, 156);
const QColor aboveNormalColour(164, 237, 189);

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
    QStandardItemModel* scanListContent;
    Profile* profile;

signals:
    void backToMenu();

private slots:
    void menuButtonClicked();
    void scanListItemClicked(const QModelIndex&);
};

#endif // DATAPAGE_H
