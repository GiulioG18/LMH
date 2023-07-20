
// ========================================================================
//		Application Main window 
// ========================================================================

#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_lmhqt.h"

class LMHQt : public QMainWindow
{
    Q_OBJECT

public:
    LMHQt(QWidget *parent = nullptr);
    ~LMHQt();

private:
    Ui::LMHQtClass ui;
};
