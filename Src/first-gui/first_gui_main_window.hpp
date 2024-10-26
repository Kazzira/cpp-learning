#ifndef FIRST_GUI_MAIN_WINDOW_HPP
#define FIRST_GUI_MAIN_WINDOW_HPP

#include "ui_first_gui_main_window.h"

class first_gui_main_window : public QMainWindow, private Ui::first_gui_main_window
{
    Q_OBJECT

public:
    explicit first_gui_main_window(QWidget *parent = nullptr);
};

#endif // FIRST_GUI_MAIN_WINDOW_HPP
