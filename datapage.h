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
#include "organ.h"

const QColor belowNormalColour(101,91,217);
const QColor normalColour(107,222,118);
const QColor aboveNormalColour(243,85,73);

namespace Ui {
class DataPage;
}

class DataPage : public QWidget
{
    Q_OBJECT

public:
    explicit DataPage(QWidget *parent = nullptr);
    ~DataPage();
    void setupOrganTable(const vector<Organ>&);
    void loadForProfile(Profile*);
    void loadHeatmap(QString);

private:
    Ui::DataPage *ui;
    QStandardItemModel* organTableContent;
    QStandardItemModel* scanListContent;
    Profile* profile;
    void setupLegend();

signals:
    void backToMenu();
    void recommendations();

private slots:
    void menuButtonClicked();
    void recommendationsButtonClicked();
    void scanListItemClicked(const QModelIndex&);
};

#endif // DATAPAGE_H
