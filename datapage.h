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

const QColor belowNormalColour(240, 84, 70);
const QColor normalColour(255, 217, 46);
const QColor aboveNormalColour(158, 222, 93);

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

signals:
    void backToMenu();

private slots:
    void menuButtonClicked();
    void scanListItemClicked(const QModelIndex&);
};

#endif // DATAPAGE_H
