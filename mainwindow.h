#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void Convert();
    void lineEditClear();

    void on_comboBox_3_activated(int index);

private:
    Ui::MainWindow *ui;

    std::map<QString, double> lengthValues
    {
        {"millimeter", 1000},
        {"centimeter", 100},
        {"meter", 1},
        {"kilometer", 0.001}
    };

    std::map<QString, int> timeValues
    {
        {"second",1},
        {"minute", 60},
        {"hour", 3600},
        {"Day", 86400}
    };

    std::map<QString, double> weightValues
    {
        {"gram",1000},
        {"kilogram",1},
        {"hundredweight",0.01},
        {"ton",0.001}
    };
};
#endif // MAINWINDOW_H
