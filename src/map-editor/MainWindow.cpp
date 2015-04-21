#include "MainWindow.h"

MainWindow::MainWindow(QWidget * parent, Qt::WindowFlags flags)
:QMainWindow(parent, flags)
{
    m_glRender = new GLRenderWidget();
    this.setCentralWidget(m_glRender);
}

MainWindow::~MainWindow()
{
    delete m_glRender;
}
