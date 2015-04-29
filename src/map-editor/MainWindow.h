#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

#include "GLRenderWidget.h"

class MainWindow : public QMainWindow
{
	public:
		MainWindow(QWidget * parent = 0, Qt::WindowFlags flags = 0);
		~MainWindow();
	private:
		GLRenderWidget *m_glRender;
		Map *m_map;
};

#endif
